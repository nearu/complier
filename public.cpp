#include <typeinfo>
#include <queue>
#include <algorithm>
#include "code_generator.h"
#include "public.h"
#include "symtab.h"
#include <cmath>
#define FP 30
#define SP 29
ofstream ast("AST");
ofstream code("CODE");
ofstream sym("SYM");
ofstream error("ERROR");
LabelManager *labelManager;
RegManager *regManager;
int traceGenCode = TRUE;
int traceEmit = TRUE;
int isMain = TRUE;
extern Symtab* mainSymtab;

/////////////////////////////////////////////////////////////
// utils												   //
/////////////////////////////////////////////////////////////
void selectOP(SymBucket *bucket, int &reg, string &load, string &store, int &loc, int currentLevel = 0) {
	if (reg == -3) {
		reg = -1;
		loc = bucket->getOffsetReg();
		// 表明 reg中存放的是地址，array和record的情形
		load = "load_reg";
		store = "store_reg";
		return;
	} else {
		load = "load";
		store = "store";
	}

	if (reg == -1 && bucket != NULL) {
		if (bucket->getIsRef()) {
			cout <<  bucket->getName() << " : copy by referance" << endl;
			load += "_ref";
			store += "_ref";
		}
		loc = bucket->getLoc();
		cout << "in select " << bucket->getCurSymtab() <<endl;
		int level = bucket->getCurSymtab()->getLevel();
		if (level < currentLevel) {
			char ch[5] = {0,};
			sprintf(ch, "%d", currentLevel - level);
			load = load +  "-" + ch;
			store = store + "-" +  ch;
		}
	}

	cout << "out select" <<endl;
}

void traceGen(string msg) {
	if (traceGenCode)
		cout << msg << endl;
}


string intTostring(int x){
	char t[256];
    string s;
 
    sprintf(t, "%d", x);
    s = t;
    return s;
}

bool isTmpReg(int r) {
	return r >=8 && r <=15;
}

void autoFreeReg(int beFree, int* contrain) {
	if (isTmpReg(beFree)) {
		if (contrain != NULL && *contrain != beFree) {
			regManager->freeReg(beFree);
		}
	}
}



void printAST(TreeNode *root) {
	queue<TreeNode *> q;
	int curLevel = 0;
	int nextLevel = 0;
	q.push(root);
	curLevel = 1;
	while(!q.empty()) {
		TreeNode *t = q.front();
		q.pop();
		curLevel--;
		ast << " ";
		t->printSelf();
		ast << " ";
	
		vector<TreeNode *> children = t->getChildren();
		for(int i = 0; i < children.size(); i++) {
			nextLevel++;
			q.push(children[i]);
		}
		if (curLevel == 0) {
			ast << endl;
			curLevel = nextLevel;
			nextLevel = 0;
		}
	}
}

int getSize(const string& type) {
	int size;
	if (type == "integer") 
		size = 2;
	else if (type == "real") 
		size = 4;
	else if (type == "char")
		size = 1;
	else if (type == "string") 
		size = 256;
	return size;
}



////////////////////////////////////////////////////////////
// utils functions										  //
////////////////////////////////////////////////////////////
void childrenGenCode(vector<TreeNode*>& children, Symtab *symtab ,int *reg) {
	cout << children.size() << endl;
	for(int i = 0; i < children.size(); i++) {
		children[i]->genCode(symtab,reg);
	}
}

void childrenUpdateSymtab(vector<TreeNode*>& children, Symtab *symtab) {
	for(int i = 0; i < children.size(); i++) 
		children[i]->updateSymtab(symtab);
}



////////////////////////////////////////////////////////////
// update symtab functions								  //
////////////////////////////////////////////////////////////

void ProgramTreeNode::updateSymtab(Symtab *symtab) {
	env = symtab;
	routine->updateSymtab(symtab);	
}

void RoutineTreeNode::updateSymtab(Symtab* symtab) {
	env = symtab;
	head->updateSymtab(symtab);
}	

void RoutineHeadTreeNode::updateSymtab(Symtab *symtab) {
	env = symtab;
	childrenUpdateSymtab(children, symtab);
}

void ListTreeNode::updateSymtab(Symtab *symtab) {
	env = symtab;
	cout << typeName << " lu " << endl;
	childrenUpdateSymtab(list, symtab);	
}

void ConstTreeNode::updateSymtab(Symtab *symtab) {
	traceGen("cu");
	env = symtab;
	const string type = value->getType();
	SymBucket *b = new SymBucket(name, lineNO, "const-" + type, symtab);
	int size;

    if (type == "string") 
		size = ((NumberTreeNode<string>*)value)->get().length();
	else size = getSize(type);

	b->setSize(size);
	b->setLoc(symtab->genLoc(size));
	symtab->insert(b);

}
// in var part
void VariableTreeNode::updateSymtab(Symtab *symtab) {
	traceGen("vu: " + name);
	env = symtab;
	vector<TreeNode*>& list = nameList->getList();
	if (name != "") {
		list.push_back(new TreeNode(name));
	}
	for(int i = 0; i < list.size(); i++) {
		SymBucket *b = typeNode->genSymItem(list[i]->getName(), symtab);
		string type = b->getType();
		b->setCurSymtab(symtab);
		if ((type.find("integer") != string::npos || type.find("real") != string::npos 
			|| type.find("char")!=string::npos) && !symtab->isRegSpill()) {

			int reg = symtab->genRegNum();
			b->setLoc(symtab->genLoc(b->getSize()));
			b->setRegNum(reg);			
		} else {
			SymBucket *tmpBucket;
			// need to gencode to allocate memory in stack for these variables.
			if (type.find("record") != string::npos) {
				SymBucket *member = b->next;
				do {
					member->setLoc(env->genLoc(member->getSize()));
					member = member->last->next;
				} while(member != b);
			} else {
				//cout << "in vu" << b->getName() << " size is " << b->getSize() << endl;
				b->setLoc(symtab->genLoc(b->getSize()));
			}
		}
		if (getIsVar()) {
		 	b->setIsVar(1);
		}
		symtab->insert(b);
	}
}
//////// 对于传引用的方法，可以改成直接放具体的地址，而不是偏移
////////
void FunctionTreeNode::updateSymtab(Symtab *symtab) {
	env = symtab;
	// new a bucket for function
	SymBucket *bucket = new SymBucket(name, lineNO, !isProc ? "func" : "proc", symtab);
	bucket->setSize(0);
	Symtab *subSymtab = new Symtab(name+"-subSymtab");
	subSymtab->setLevel(symtab->getLevel() + 1);
	subSymtab->setParentBucket(bucket);
	bucket->setSubSymtab(subSymtab);
	args->updateSymtab(subSymtab);
	// copy args into the function bucket
	vector<SymBucket *> v;
	subSymtab->getSymBucketList(v);
	SymBucket *tmpBucket = bucket;
	subSymtab->setCurRegNum(symtab->getCurReg());
	subSymtab->setCurLoc(0);
	for (int  i = 0; i < v.size(); i++) {
		cout << name << " : " << v[i]->getName() << endl;
		if (!v[i]->getIsRef())
			v[i]->setLoc(subSymtab->genLoc(v[i]->getSize()));
		else v[i]->setLoc(subSymtab->genLoc(4));
		v[i]->setRegNum(-1);
		if (v[i]->getIsVar()) {
			v[i]->setIsRef(1);
		}
		// here we only need the first node of arguments' type
		SymBucket *newBucket = new SymBucket(v[i]);
		tmpBucket->next = newBucket;
		tmpBucket = newBucket;
	}
	// set subsymtab for this node
	body->updateSymtab(subSymtab);
	subTab = subSymtab;
	if (!isProc) {
		cout << "it is not proc!!!!!" << endl;
		SymBucket *returnTypeBucket = returnType->genSymItem("returnType", symtab);
		bucket->last = returnTypeBucket->last;
		bucket->last->next = bucket;
		tmpBucket->next = returnTypeBucket;
		symtab->insert(bucket);
		// insert return node
		SymBucket *returnNameBucket = new SymBucket(returnTypeBucket);
		returnNameBucket->setCurSymtab(subSymtab);
		returnNameBucket->setName(name);
		// set return reg num
		returnNameBucket->setRegNum(2);
		subSymtab->insert(returnNameBucket);
	} else {
		bucket->last = tmpBucket;		
		tmpBucket->next = bucket;
		symtab->insert(bucket);
	}
}

// in type part
void CustomTypeTreeNode::updateSymtab(Symtab *symtab) {
	env = symtab;
	SymBucket *b = type->genSymItem(name, symtab);
	b->setIsType(1);
	symtab->insert(b);
}
	

////////////////////////////////////////////////////////////
// gen code functions 									  //
////////////////////////////////////////////////////////////


SymBucket * ProgramTreeNode::genCode(Symtab *symtab, int *reg) {
	traceGen("pg");
	routine->genCode(env);
	return NULL;
}

SymBucket * RoutineTreeNode::genCode(Symtab *symtab, int *reg) {
	traceGen("rg");
	env = symtab;
	vector<SymBucket *> bucketList;
	symtab->getSymBucketList(bucketList);
	int totalStackSize = 0;
	for (int i = 0; i < bucketList.size(); i++) {
		SymBucket *b = bucketList[i];
		cout << b->getName() << "'s size is "  << b->getSize() << endl;
		if (b->getRegNum() == -1) {
			totalStackSize += b->getSize();
		}
	}
	if (totalStackSize > 0) {
		CodeGenerator::emitCodeI("-", SP,SP,totalStackSize);
	}
	body->genCode(env);
	if (totalStackSize > 0) 
			CodeGenerator::emitCodeI("+", SP,SP,totalStackSize);
	if (!isMain) {
		CodeGenerator::emitCodeJ("jr", 31, 0, 0, "");
	}
	if (isMain) {
		isMain = FALSE;
	}
	head->genCode(env);
	return NULL;
}

SymBucket * ListTreeNode::genCode(Symtab *symtab, int *reg) {
	traceGen("lg");
	childrenGenCode(list, symtab ,reg);
	return 0;
}

SymBucket * ConstTreeNode::genCode(Symtab *symtab, int *reg) {
	traceGen("cg");
	if (reg != NULL) *reg = -1;
	env = symtab;
	SymBucket *b = env->find(name);
	SymBucket * returnBucket = new SymBucket(b);
	returnBucket->setCurSymtab(b->getCurSymtab());
	return returnBucket;
}

SymBucket * VariableTreeNode::genCode(Symtab *symtab, int *reg) {
	//traceGen("vg : " + name + " env" + symtab);
	cout << "vg : " <<  name <<  " env : " << symtab << endl;
	env = symtab;
	SymBucket *b = env->find(name);
	cout << "b = " << b << endl;
	if (b != NULL) {
		if (reg != NULL) *reg = b->getRegNum();
	} else {
		cout << lineNO << ": variable " << name << " is not defined" << endl;
	}
	SymBucket * returnBucket = new SymBucket(b);
	returnBucket->setCurSymtab(b->getCurSymtab());
	return returnBucket;
}

// const var parts will be processed later
SymBucket * RoutineHeadTreeNode::genCode(Symtab *symtab, int *reg) {
	routinePart->genCode(symtab);
	return 0;
}

SymBucket * CompoundStmtTreeNode::genCode(Symtab *symtab, int *reg) {
	stmtList->genCode(symtab);
	return NULL;
}

SymBucket * FunctionTreeNode::genCode(Symtab *symtab, int *reg) {
	traceGen("funtion gencode");
	string label = "&&&" + name + "&&&";
	//labelManager->addFuncLabel(label);
	CodeGenerator::addLabel(label);
	body->genCode(subTab);
	return NULL;
}

// expression will only return 
//
SymBucket * BinaryExprTreeNode::genCode(Symtab *symtab, int *reg) {
	traceGen("bg : " + op);
	env = symtab;
	int regR, regL;
	int locR = 0, locL = 0;
	// for arrayElem and recordElem
	SymBucket *returnBucket = NULL;
	SymBucket *bucketR, *bucketL;
	bucketR = rhs->genCode(env, &regR);
	bucketL = lhs->genCode(env, &regL);	
	string loadOPR, storeOPR;
	string loadOPL, storeOPL;
	cout << "regL : " << regL << " regR " << regR << endl;
	selectOP(bucketR, regR, loadOPR, storeOPR, locR, symtab->getLevel());
	selectOP(bucketL, regL, loadOPL, storeOPL, locL, symtab->getLevel());
	cout << "regL : " << regL << " regR " << regR << endl;
	if (regL == -1 && regR == -1) {		
		int tmpSrc_1 = regManager->getTmpReg();
		int tmpSrc_2 = regManager->getTmpReg();
		int tmpDst = regManager->getTmpReg();
		if (op == "=") {
			CodeGenerator::emitCodeM(bucketR->getSize(),loadOPR, locR, FP, tmpSrc_2);			
			CodeGenerator::emitCodeM(bucketL->getSize(),storeOPL, locL, FP, tmpSrc_2);
			if (reg != NULL) *reg = tmpSrc_2;
			returnBucket = new SymBucket(bucketL);
		} else {
			CodeGenerator::emitCodeM(bucketL->getSize(),loadOPL, locL, FP, tmpSrc_1);
			CodeGenerator::emitCodeM(bucketR->getSize(),loadOPR, locR, FP, tmpSrc_2);
			CodeGenerator::emitCodeR(op, tmpDst, tmpSrc_1, tmpSrc_2);
			if (reg != NULL) *reg = tmpDst;
		}
		regManager->freeReg(tmpSrc_1);
		regManager->freeReg(tmpSrc_2);
	} else if (regL > 0 && regR > 0) {
		cout << "L=" << regL << " R = " << regR <<endl;
		if (op == "=") {
			CodeGenerator::emitCodeR(op, regL, regR, 0);
			if (reg != NULL) *reg = regL;
			returnBucket = new SymBucket(bucketL);
		} else {
			int tmpReg = regManager->getTmpReg();
			CodeGenerator::emitCodeR(op, tmpReg, regR, regL);
			if (reg != NULL) *reg = tmpReg;
		}
		regManager->freeReg(regL);
		regManager->freeReg(regR);
	} else if (regL > 0 && regR == -1) {
		int tmpReg = regManager->getTmpReg();
		CodeGenerator::emitCodeM(bucketR->getSize(),loadOPR, locR, FP, tmpReg);
		if (op == "=") {
			CodeGenerator::emitCodeR(op, regL, tmpReg, 0);
			if (reg != NULL) *reg = regL;
			returnBucket = new SymBucket(bucketL);
		} else {
			int tmpDst = regManager->getTmpReg();
			CodeGenerator::emitCodeR(op, tmpDst, regL, tmpReg);
			if (reg != NULL) *reg = tmpDst;
		}
		regManager->freeReg(tmpReg);
	} else if (regL == -1 && regR > 0) {
		if (op == "=") {
			CodeGenerator::emitCodeM(bucketL->getSize(),storeOPL, locL, FP, regR);
			if (reg != NULL) *reg = regR;
			returnBucket = new SymBucket(bucketL);
		} else {
			int tmpSrc = regManager->getTmpReg();
			int tmpDst = regManager->getTmpReg();
			CodeGenerator::emitCodeM(bucketL->getSize(),loadOPL, locL, FP, tmpSrc);
			CodeGenerator::emitCodeR(op, tmpDst, tmpSrc, regR);
			regManager->freeReg(tmpSrc);
			if (reg != NULL) *reg = tmpDst;
		}
		regManager->freeReg(regR);
	} else if (regL == -2 || regR == -2) {
		int tmpDst = regManager->getTmpReg();
		int tmpSrc = regManager->getTmpReg();
		int immeR = -1, immeL = -1;
		NumberTreeNode<int> * immeNodeR = dynamic_cast<NumberTreeNode<int>*>(rhs);
		NumberTreeNode<int> * immeNodeL = dynamic_cast<NumberTreeNode<int>*>(lhs);
		if (immeNodeR != NULL) {
			immeR = immeNodeR->get();
		}
		if (immeNodeL != NULL) {
			immeL = immeNodeL->get();
		}
		cout << "immeR = " << immeR << " immeL = " << immeL << endl;
		if (regL == -2 && regR == -2) {
			CodeGenerator::emitCodeI(op, tmpDst, 0, immeR);
			CodeGenerator::emitCodeI(op, tmpDst, 0, immeL);
			if (reg != NULL) *reg = tmpDst;
		} else if (regL == -2 && regR > 0) {
			CodeGenerator::emitCodeI(op, tmpDst, regR, immeL);
			if (reg != NULL) *reg = tmpDst;
		} else if (regL == -2 && regR == -1) {
			CodeGenerator::emitCodeM(bucketR->getSize(),loadOPR, locR, FP, tmpSrc);
			CodeGenerator::emitCodeI(op, tmpDst, tmpSrc, immeL);
			if (reg != NULL) *reg = tmpDst;
		} else if (regL > 0 && regR == -2) {
			if (op == "=") {
				CodeGenerator::emitCodeI(op, regL, 0, immeR);
				if (reg != NULL) *reg = regL;
			} else {
				CodeGenerator::emitCodeI(op, tmpDst, regL, immeR);
				if (reg != NULL) *reg = tmpDst;
			}
		} else if (regL == -1 && regR == -2) {
			if (op == "=") {
				CodeGenerator::emitCodeI(op, tmpDst, 0, immeR);
				CodeGenerator::emitCodeM(bucketL->getSize(),storeOPL, locL, FP, tmpDst);
				if (reg != NULL) *reg = tmpDst;
			} else {
				CodeGenerator::emitCodeM(bucketL->getSize(),loadOPL, locL, FP, tmpSrc);
				CodeGenerator::emitCodeI(op, tmpDst, tmpSrc, immeR);
				if (reg != NULL) *reg = tmpDst;
			}
		}

		regManager->freeReg(tmpSrc);
	}
	if (bucketL != NULL) delete bucketL;
	if (bucketR != NULL) delete bucketR;
	autoFreeReg(regL, reg);
	autoFreeReg(regR, reg);
	return returnBucket;
}

SymBucket * WhileStmtTreeNode::genCode(Symtab *symtab, int *reg){
	SymBucket *bucketR, *bucketL;
	int regL, regR;
	int locL, LocR;
	string loadOPR, storeOPR;
	string loadOPL, storeOPL;
	int x;
	x=labelManager->getLoopLabel();
	char ch[16] = {0,};
	sprintf(ch,"%d",x);
	string loop = "loop";
	loop = loop + ch;
	string breakn = "break";
	breakn = breakn + ch;
	labelManager->addLoopLabel();
	CodeGenerator::addLabel(loop);
	bucketL = condition->genCode(symtab, &regL);
	selectOP(bucketL,regL,loadOPL,storeOPL,locL, symtab->getLevel());
	if(regL == -1){
		int tmp = regManager->getTmpReg();
		CodeGenerator::emitCodeM(bucketL->getSize(),loadOPL, locL, FP, tmp);
		CodeGenerator::emitCodeJ("beq",tmp,0,0,breakn);
		regManager->freeReg(tmp);
	}
	else {
		CodeGenerator::emitCodeJ("beq",regL,0,0,breakn);
	}
	body->genCode(symtab, &regR);
	CodeGenerator::emitCodeJ("j",0,0,0,loop);
	CodeGenerator::addLabel(breakn);
	//delete bucketL;
	//delete bucketR;
	return NULL;
}

SymBucket * ForStmtTreeNode::genCode(Symtab *symtab, int *reg){
	SymBucket *bucketR, *bucketL;
	int regL, regR ,regB;
	int locL, locR;
	string loadOPR, storeOPR;
	string loadOPL, storeOPL;
	int x;
	x=labelManager->getLoopLabel();
	char ch[16] = {0,};
	sprintf(ch,"%d",x);
	string loop = "loop";
	loop = loop + ch;
	string breakn = "break";
	breakn = breakn + ch;
	labelManager->addLoopLabel();
	bucketL = assignExpr->genCode(symtab, &regL);
	cout << "for reg L = " << regL << endl; 
	CodeGenerator::addLabel(loop);
	bucketR = dirExpr->genCode(symtab,&regR);
	selectOP(bucketR,regR,loadOPR,storeOPR,locR, symtab->getLevel());
	if(regR == -1){
		int tmp = regManager->getTmpReg();
		CodeGenerator::emitCodeM(bucketR->getSize(),loadOPR, locR, FP, tmp);
		CodeGenerator::emitCodeJ("bne",tmp,0,0,breakn);
		regManager->freeReg(tmp);
	}
	else {
		CodeGenerator::emitCodeJ("bne",regR,0,0,breakn);
	}
	body->genCode(symtab, &regB);
	if(regL == -1){
		int tmp = regManager->getTmpReg();
		CodeGenerator::emitCodeM(bucketR->getSize(),loadOPR, locR, FP, tmp);
		if(direction == "to") {
			CodeGenerator::emitCodeI("+",tmp,tmp,1);
		}
		else {
			CodeGenerator::emitCodeI("-",tmp,tmp,1);
		}
		CodeGenerator::emitCodeM(bucketR->getSize(),storeOPR, locR, FP, tmp);
		regManager->freeReg(tmp);
	}
	else {
		if(direction == "to") {
			CodeGenerator::emitCodeI("+",regL,regL,1);
		}
		else {
			CodeGenerator::emitCodeI("-",regL,regL,1);
		}
	}

	CodeGenerator::emitCodeJ("j",0,0,0,loop);
	CodeGenerator::addLabel(breakn);
	//delete bucketL;
	//delete bucketR;
	return NULL;
}

SymBucket * SwitchStmtTreeNode::genCode(Symtab *symtab, int *reg){
	SymBucket *bucketE, *bucketLD;
	int regE;	
	string loadOPE, storeOPE;
	int locE;
	bucketE = expr->genCode(symtab,&regE);
	selectOP(bucketE,regE,loadOPE,storeOPE,locE, symtab->getLevel());
	if(regE == -1){
		int tmp = regManager->getTmpReg();
		CodeGenerator::emitCodeM(bucketE ->getSize(),loadOPE, locE, FP, tmp);
		bucketLD = caseExprList->genCode(symtab,&tmp);
		regManager->freeReg(tmp);
	}
	else{
		bucketLD = caseExprList->genCode(symtab,&regE);
	}
	return NULL;
}

SymBucket * CaseExprTreeNode::genCode(Symtab *symtab, int *reg){

	SymBucket *bucketID;
	int regID,regE;
	int locID;
	string loadOPID, storeOPID;
	string s;
	int x;
	
	regE = *reg;

	bucketID = label->genCode(symtab,&regID);
	
	selectOP(bucketID,regID,loadOPID,storeOPID,locID, symtab->getLevel());
	if(regID == -1){
		int tmp = regManager->getTmpReg();
		CodeGenerator::emitCodeM(bucketID ->getSize(),loadOPID, locID, FP, tmp);
		x = labelManager->getCaseLabel();
		s = "nextcase" + intTostring(x);
		CodeGenerator::emitCodeJ("bne",tmp,regE,0,s); 
		labelManager->addCaseLabel();
		regManager->freeReg(tmp);
	}
	else if (regID > 0){
		x = labelManager->getCaseLabel();
		s = "nextcase" + intTostring(x);
		CodeGenerator::emitCodeJ("bne",regID,regE,0,s); 
		labelManager->addCaseLabel();
	}
	else {
		x = labelManager->getCaseLabel();
		s = "nextcase" + intTostring(x);
		CodeGenerator::emitCodeJ("bne", regE, 32, ((NumberTreeNode<int> *)label)->get(),s);
		labelManager->addCaseLabel();
	}
	
	stmt->genCode(symtab);
	CodeGenerator::addLabel(s);
}

SymBucket * ArrayElemTreeNode::genCode(Symtab *symtab, int *reg) {
	env = symtab;
	SymBucket *type = env->find(name);
	SymBucket *elemType = type->next->last->next;
	SymBucket *returnBucket = new SymBucket("arrayElem", lineNO,  elemType->getType(), symtab );
	int elemSize = elemType->getSize();
	int exprReg;
	// the stack offset of the index
	int indexLoc; 
	string loadOP, storeOP;
	SymBucket *indexBucket = index->genCode(symtab, &exprReg);
	selectOP(indexBucket, exprReg, loadOP, storeOP, indexLoc, symtab->getLevel());
	if (exprReg == -2) {
		int offset = 0;
		NumberTreeNode<int> * immeNode = dynamic_cast<NumberTreeNode<int>*>(index);
		if (immeNode != NULL) {
			offset = type->getLoc() + elemSize * (immeNode->get());
		} else {
			cout << "fuck==================array index has to be integer!!!1" << endl;
		}
		returnBucket->setLoc(offset);
		if (reg != NULL) *reg = -1;
	} else if (exprReg == -1) { // stack
		int tmpSrc_1 = regManager->getTmpReg();
		int tmpSrc_2 = regManager->getTmpReg();
		int tmpDst   = regManager->getTmpReg();
		CodeGenerator::emitCodeM(indexBucket->getSize(), "load", indexLoc, FP,tmpSrc_1);
		CodeGenerator::emitCodeI("+", tmpSrc_2, 0, elemSize);
		CodeGenerator::emitCodeR("*", tmpDst, tmpSrc_1, tmpSrc_2);
		if (reg != NULL) *reg = -3;
		returnBucket->setOffsetReg(tmpDst);
		regManager->freeReg(tmpSrc_1);
		regManager->freeReg(tmpSrc_2);
	} else if (exprReg > 0) {	// reg
		int tmpDst = regManager->getTmpReg();
		int tmpSrc = regManager->getTmpReg();
		CodeGenerator::emitCodeI("+", tmpSrc, 0, elemSize);
		CodeGenerator::emitCodeR("*", tmpDst, tmpSrc, exprReg);
		if (reg != NULL) *reg = -3;
		returnBucket->setOffsetReg(tmpDst);
		regManager->freeReg(tmpSrc);
	}
	returnBucket->setSize(elemSize);
	autoFreeReg(exprReg, reg);
	return returnBucket;
}

SymBucket * RecordElemTreeNode::genCode(Symtab *symtab, int *reg) {
	env = symtab;
	SymBucket *returnBucket = new SymBucket("recordElem", lineNO, "",symtab);
	SymBucket *bucket = env->find(recordName);
	SymBucket *member = bucket->next;
	do {
		if (member->getName() == elemName) {
			returnBucket->setLoc(member->getLoc());
			returnBucket->setSize(member->getSize());
			break;
		}
		member = member->last->next;
	} while (member != bucket);
	if (reg != NULL) *reg = -1;
	if (member == bucket) cout << lineNO << " : undefined record member :" << elemName << " in "  << recordName << endl;
	return returnBucket;
}

SymBucket * UnaryExprTreeNode::genCode(Symtab *symtab, int *reg) {
	env = symtab;
	SymBucket *returnBucket = new SymBucket("unaryExpr", lineNO, "", symtab);
	int operandReg;
	string loadOP, storeOP;
	int operandLoc;
	SymBucket *operandBucket = operand->genCode(symtab, &operandReg);
	selectOP(operandBucket, operandReg, loadOP, storeOP, operandLoc, symtab->getLevel());
	cout << "in unaryExpr reg = " << operandReg  << " with op = " << op << endl;
	int tmpDst;
	tmpDst = regManager->getTmpReg();
	if (operandReg > 0) {
		CodeGenerator::emitCodeR(op, tmpDst, 0, operandReg);
		if (reg != NULL) *reg = tmpDst;
	} else if (operandReg == -1) {
		CodeGenerator::emitCodeM(operandBucket->getSize(), loadOP, operandBucket->getLoc(),FP,tmpDst);
		CodeGenerator::emitCodeR(op,tmpDst,0,tmpDst);
		if (reg != NULL) *reg = tmpDst;
	} else if (operandReg == -2) {
		NumberTreeNode<int> * immeNode = dynamic_cast<NumberTreeNode<int>*>(operand);
		if (immeNode != NULL) {
			int imme = ((NumberTreeNode<int>*)operand)->get();
			cout << "in unaryExpr imme = " << imme << endl;
			if (op == "-") 
				imme = -imme;
			else if (op == "~") 
				imme = ~imme;
			CodeGenerator::emitCodeI("=", tmpDst, 0, imme);
			if (reg != NULL) *reg = tmpDst;
		} else {
			cout << "==================float has not be support" << endl;
		}
	}
	if (operandBucket != NULL) delete operandBucket;
	autoFreeReg(operandReg, reg);
	return returnBucket;
}
// we do not support passing a var type argment of one function 
// to another function's var type argument
SymBucket * CallExprTreeNode::genCode(Symtab *symtab, int *reg) {
	cout << "in call" <<endl;
	env = symtab;
	SymBucket *returnBucket = new SymBucket("call_" + name, lineNO, "call" , symtab);
	cout << name << endl;
	SymBucket *funcBucket = env->find(name);
	cout << funcBucket << endl;
	vector<SymBucket *> argsTypeList;
	SymBucket *member = funcBucket->next;
	do {
		argsTypeList.push_back(funcBucket->getNextSymtab()->find(member->getName()));
		member = member->last->next;
	} while (member != funcBucket);
	// save the environment, such as save ra, v0, fp, and set access link
	CodeGenerator::emitCodeI("-", SP,SP,16);
	CodeGenerator::emitCodeM(4, "store", 16, SP, 31);
	CodeGenerator::emitCodeM(4, "store", 12,  SP, 2);
	CodeGenerator::emitCodeM(4, "store", 8,  SP, FP);
	int tmp = regManager->getTmpReg();
	CodeGenerator::emitCodeI("+", tmp, FP, 4);
	CodeGenerator::emitCodeM(4, "store", 4,  SP, tmp);
	CodeGenerator::emitCodeI("+", FP, SP, 0);
	CodeGenerator::emitCodeI("-", tmp, tmp, 4);
	int tmpDst;
	for (int i = 0; i < args.size(); i++) {
		tmpDst = regManager->getTmpReg();
		SymBucket *argType = argsTypeList[i];
		int argReg, argLoc;
		string loadOP, storeOP;
		SymBucket *argBucket = args[i]->genCode(symtab, &argReg);
		int isElem = argReg == -3;
		selectOP(argBucket, argReg, loadOP, storeOP, argLoc, symtab->getLevel());
		if (argReg == -1) {
			if (argType->getIsRef()) {
				if (isElem) {
					CodeGenerator::emitCodeM(4, "load", 0, argReg, tmpDst);
				} else {
					CodeGenerator::emitCodeI("+", tmpDst, 0, argLoc); // what if it is a reg stores addr !!!!
				}
				CodeGenerator::emitCodeR("+", tmpDst, tmp, tmpDst);   // addr = old fp + offset
				CodeGenerator::emitCodeM(4, "store", argType->getLoc(), FP, tmpDst);
			} else {
				CodeGenerator::emitCodeM(argBucket->getSize(), loadOP, argLoc, FP, tmpDst);
				CodeGenerator::emitCodeM(argType->getSize(), "store", argType->getLoc(), FP, tmpDst);
			}
		} else if (argReg == -2) {
			// imme can be passed to a ref argment
			NumberTreeNode<int> * immeNode = dynamic_cast<NumberTreeNode<int>*>(args[i]);
			if (immeNode != NULL) {
				int imme = immeNode->get();
				CodeGenerator::emitCodeI("+", tmpDst, 0, imme);
				CodeGenerator::emitCodeM(argType->getSize(), "store", argType->getLoc(), FP, tmpDst);
			} else {
				cout << "float is not supported!!!!!!" << endl;
			} 
		} else if (argReg > 0) { // depreted
			if (argType->getIsRef()) {
				cout << "immediate expression result can not be copy by reference" << endl;
				// CodeGenerator::emitCodeM(4, "store", argType->getLoc(), FP, -argReg);
			} else {
				CodeGenerator::emitCodeM(argType->getSize(), "store", argType->getLoc(), FP, argReg);
			}
		}
		regManager->freeReg(tmpDst);
	}
	regManager->freeReg(tmp);
	CodeGenerator::emitCodeJ("jal", 0,0,0,"&&&"+name+"&&&");
	if (!isProc) {
		tmp = regManager->getTmpReg();
		CodeGenerator::emitCodeR("+",tmp, 2, 0);
		if (reg != NULL) *reg = tmp;
	} else {
		if (reg != NULL) *reg = -4;
	}
	CodeGenerator::emitCodeM(4, "load", 16, SP, 31); 	// ra
	CodeGenerator::emitCodeM(4, "load", 12, SP, 2);		// v0	
	CodeGenerator::emitCodeM(4, "load", 8, SP, FP);		
	CodeGenerator::emitCodeI("+", SP,SP,16);
	cout << "out call" <<endl;
	return returnBucket;
}

////////////////////////////////////////////////////////////
// type gen symtab bucket functions						  //
////////////////////////////////////////////////////////////

// they only set size , the caller will bother setting loc

// type name is the l-side of type-definition, and type is the r-side
SymBucket* SysTypeTreeNode::genSymItem(const string typeName, Symtab *symtab) {
	traceGen("type name :"  + typeName);
	cout << " env : " << symtab << endl;
	SymBucket *b = new SymBucket(typeName, lineNO, type, symtab);
	int size = getSize(type);
	b->setSize(size);
	return b;
}



// array need to consider about index type of sub range ,
SymBucket *ArrayTypeTreeNode::genSymItem(const string typeName, Symtab *symtab) {
	traceGen("array node");
	SymBucket *array = new SymBucket(typeName, lineNO, "array", symtab);
	SymBucket *indexBucket = indexType->genSymItem("index", symtab);
	SymBucket *typeBucket = elemType->genSymItem("array", symtab);
	int len;
	if (indexBucket->getType() == "subrange") {
		int u, l;
		l = atoi(indexBucket->next->getType().c_str());
		u = atoi(indexBucket->last->getType().c_str());
		len = u - l;
	}
	else {
		len = pow(2,indexBucket->getSize()*8);
	}
	int size = len * typeBucket->getSize();
	array->setSize(size);
	array->next = indexBucket;
	indexBucket->last->next = typeBucket;
	typeBucket->last->next = array;
	array->last = typeBucket->last;
	return array;
}


SymBucket *SubRangeTypeTreeNode::genSymItem(const string typeName, Symtab *symtab) {
	char cu[16] = {0,};
	char cl[16] = {0,};
	int u = ((NumberTreeNode<int>*)upperBound)->get();
	int l = ((NumberTreeNode<int>*)lowerBound)->get();
	sprintf(cu,"%d",u);
	sprintf(cl,"%d",l);
	SymBucket *head  = new SymBucket(typeName, lineNO, "subrange", symtab);
	SymBucket *begin = new SymBucket("subrange", lineNO, cl, symtab);
	SymBucket *end 	 = new SymBucket("subrange", lineNO, cu, symtab);
	head->setSize(getSize("integer"));
	begin->setSize(getSize("integer"));
	end->setSize(getSize("integer"));
	head->next = begin;
	begin->next = end;
	end->next = head;
	head->last = end;
	return head;
}

SymBucket *RecordTypeTreeNode::genSymItem(const string typeName, Symtab *symtab) {
	SymBucket *rb = new SymBucket(typeName, lineNO, "record",symtab);
	rb->setSize(0);
	// 每个都是variableTreeNode
	vector<TreeNode*>& list = elemList->getList();
	for (int i = 0; i < list.size(); i++) {
		VariableTreeNode* v = (VariableTreeNode *)list[i];
		
		vector<TreeNode*>& nameList = v->getNameList()->getList();
		if (v->getName() != "") 
			nameList.push_back(new TreeNode(v->getName()));
		for (int j = 0; j < nameList.size();j++) {
			SymBucket *vb = v->getTypeNode()->genSymItem(nameList[j]->getName(), symtab);
			rb->setSize(rb->getSize() + vb->getSize());
			if (rb->next == rb) {
				rb->next = vb;
				vb->last->next = rb;
				rb->last = vb->last;
			} else {
				SymBucket *tmp = rb->next;
				rb->next = vb;
				vb->last->next = tmp;
			}
		}
	}
	return rb;
}

// make use of last to point to previous defined symbuckets in current symtab
SymBucket *CustomTypeTreeNode::genSymItem(const string typeName, Symtab *symtab) {
	// the predefined custom type in symtab
	SymBucket *typeBucket = symtab->find(name);
	SymBucket* b = typeBucket->deepCopyBucket();
	b->setCurSymtab(symtab);
	b->setName(typeName);
	// cout << " xxxxx " << b->getSize() << endl;
	return b;
}

