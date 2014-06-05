#include <typeinfo>
#include <queue>
#include "code_generator.h"
#include "public.h"
#include "symtab.h"
#include <cmath>

ofstream ast("AST");
ofstream code("CODE");
ofstream sym("SYM");
ofstream error("ERROR");
LabelManager *labelManager;
RegManager *regManager;

extern Symtab* mainSymtab;

/////////////////////////////////////////////////////////////
// utils												   //
/////////////////////////////////////////////////////////////
void selectOP(SymBucket *bucket, int &reg, string &load, string &store, int &loc) {
	if (reg == -3) {
		reg = -1;
		loc = bucket->getOffsetReg();
		load = "load_reg";
		store = "store_reg";
		return;
	} else {
		load = "load";
		store = "store";
	}

	if (reg == -1) {
		loc = bucket->getLoc();
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
void childrenGenCode(vector<TreeNode*>& children, Symtab *symtab) {
	cout << children.size() << endl;
	for(int i = 0; i < children.size(); i++) 
		children[i]->genCode(symtab);
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
	cout << "cu" << endl;
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
	cout << "vu:" << name << " " << symtab << endl;
	env = symtab;
	vector<TreeNode*>& list = nameList->getList();
	if (name != "") {
		list.push_back(new TreeNode(name));
	}
	for(int i = 0; i < list.size(); i++) {
		SymBucket *b = typeNode->genSymItem(list[i]->getName(), symtab);
		string type = b->getType();
		if ((type.find("integer") != string::npos || type.find("real") != string::npos 
			|| type.find("char")!=string::npos) && !symtab->isRegSpill()) {

			int reg = symtab->genRegNum();
			b->setRegNum(reg);			
		} else {
			// need to gencode to allocate memory in stack for these variables.
			if (type.find("record") != string::npos) {
				SymBucket *member = b->next;
				do {
					member->setLoc(member->getSize());
					member = member->last->next;
				} while(member != b);
			}
			b->setLoc(symtab->genLoc(b->getSize()));
		}
		symtab->insert(b);
	}
}
// in type part
void CustomTypeTreeNode::updateSymtab(Symtab *symtab) {
	env = symtab;
	SymBucket *b = new SymBucket(name, lineNO, "custom-" +type->getType(), symtab);
	b->next = type->genSymItem(name, symtab);
	b->next->last->next = b;
	b->setSize(b->next->getSize());
	symtab->insert(b);
}
	

////////////////////////////////////////////////////////////
// gen code functions 									  //
////////////////////////////////////////////////////////////


SymBucket * ProgramTreeNode::genCode(Symtab *symtab, int *reg) {
	cout << "pg" << endl;
	routine->genCode(env);
	return NULL;
}

SymBucket * RoutineTreeNode::genCode(Symtab *symtab, int *reg) {
	cout << "rg" << endl;
	body->genCode(env);
	return NULL;
}

SymBucket * ListTreeNode::genCode(Symtab *symtab, int *reg) {
	cout << "lg" << endl;
	childrenGenCode(list, symtab);
	return 0;
}

SymBucket * ConstTreeNode::genCode(Symtab *symtab, int *reg) {
	cout << "cg" << endl;
	if (reg != NULL) *reg = -1;
	env = symtab;
	return env->find(name);
}

SymBucket * VariableTreeNode::genCode(Symtab *symtab, int *reg) {
	cout << "vg : "<< endl;
	env = symtab;
	SymBucket *b = env->find(name);
	if (b != NULL) {
		if (reg != NULL) *reg = b->getRegNum();
	} else {
		cout << lineNO << "variable " << name << " is not defined" << endl;
	}
	return b;
}

// const var parts will be processed later
SymBucket * RoutineHeadTreeNode::genCode(Symtab *symtab, int *reg) {
	return 0;
}

SymBucket * CompoundStmtTreeNode::genCode(Symtab *symtab, int *reg) {
	stmtList->genCode(symtab);
	return NULL;
}


// expression will only return 
//
SymBucket * BinaryExprTreeNode::genCode(Symtab *symtab, int *reg) {
	cout << "bg : " << op << endl;
	env = symtab;
	int regR, regL;
	int locR = 0, locL = 0;
	// for arrayElem and recordElem
	SymBucket *returnBucket;
	SymBucket *bucketR, *bucketL;
	bucketR = rhs->genCode(env, &regR);
	bucketL = lhs->genCode(env, &regL);
	cout << "regL : " << regL << " regR " << regR << endl;
	string loadOPR, storeOPR;
	string loadOPL, storeOPL;
	selectOP(bucketR, regR, loadOPR, storeOPR, locR);
	selectOP(bucketL, regL, loadOPL, storeOPL, locL);
	if (regL == -1 && regR == -1) {		
		int tmpSrc_1 = regManager->getTmpReg();
		int tmpSrc_2 = regManager->getTmpReg();
		int tmpDst = regManager->getTmpReg();
		if (op == "=") {
			CodeGenerator::emitCodeM(bucketR->getSize(),loadOPR, locR, 29, tmpSrc_2);			
			CodeGenerator::emitCodeM(bucketL->getSize(),storeOPL, locL, 29, tmpSrc_2);
			if (reg != NULL) *reg = tmpSrc_2;
			returnBucket = bucketL;
		} else {
			CodeGenerator::emitCodeM(bucketL->getSize(),loadOPL, locL, 29, tmpSrc_1);
			CodeGenerator::emitCodeM(bucketR->getSize(),loadOPR, locR, 29, tmpSrc_2);
			CodeGenerator::emitCodeR(op, tmpDst, tmpSrc_1, tmpSrc_2);
			if (reg != NULL) *reg = tmpDst;
			returnBucket = NULL;
		}
		regManager->freeReg(tmpSrc_1);
		regManager->freeReg(tmpSrc_2);
	} else if (regL > 0 && regR > 0) {
		cout << "L=" << regL << " R = " << regR <<endl;
		if (op == "=") {
			CodeGenerator::emitCodeR(op, regL, regR, 0);
			if (reg != NULL) *reg = regL;
			returnBucket = bucketL;
		} else {
			int tmpReg = regManager->getTmpReg();
			CodeGenerator::emitCodeR(op, tmpReg, regR, regL);
			if (reg != NULL) *reg = tmpReg;
			returnBucket = NULL;
		}
		regManager->freeReg(regL);
		regManager->freeReg(regR);
	} else if (regL > 0 && regR == -1) {
		int tmpReg = regManager->getTmpReg();
		CodeGenerator::emitCodeM(bucketR->getSize(),loadOPR, locR, 29, tmpReg);
		if (op == "=") {
			CodeGenerator::emitCodeR(op, regL, tmpReg, 0);
			if (reg != NULL) *reg = regL;
			returnBucket = bucketL;
		} else {
			int tmpDst = regManager->getTmpReg();
			CodeGenerator::emitCodeR(op, tmpDst, regL, tmpReg);
			if (reg != NULL) *reg = tmpDst;
			returnBucket = NULL;
		}
		regManager->freeReg(tmpReg);
	} else if (regL == -1 && regR > 0) {
		if (op == "=") {
			CodeGenerator::emitCodeM(bucketL->getSize(),storeOPL, locL, 29, regR);
			if (reg != NULL) *reg = regR;
			returnBucket = bucketL;
		} else {
			int tmpSrc = regManager->getTmpReg();
			int tmpDst = regManager->getTmpReg();
			CodeGenerator::emitCodeM(bucketL->getSize(),loadOPL, locL, 29, tmpSrc);
			CodeGenerator::emitCodeR(op, tmpDst, tmpSrc, regR);
			regManager->freeReg(tmpSrc);
			if (reg != NULL) *reg = tmpDst;
			returnBucket = NULL;
		}
		regManager->freeReg(regR);
	} else if (regL == -2 || regR == -2) {
		int tmpDst = regManager->getTmpReg();
		int tmpSrc = regManager->getTmpReg();
		if (regL == -2 && regR == -2) {
			CodeGenerator::emitCodeI(op, tmpDst, 0, ((NumberTreeNode<int> *)rhs)->get());
			CodeGenerator::emitCodeI(op, tmpDst, 0, ((NumberTreeNode<int> *)lhs)->get());
			if (reg != NULL) *reg = tmpDst;
			returnBucket = NULL;
		} else if (regL == -2 && regR > 0) {
			CodeGenerator::emitCodeI(op, tmpDst, regR, ((NumberTreeNode<int> *)lhs)->get());
			if (reg != NULL) *reg = tmpDst;
			returnBucket = NULL;
		} else if (regL == -2 && regR == -1) {
			CodeGenerator::emitCodeM(bucketR->getSize(),loadOPR, locR, 29, tmpSrc);
			CodeGenerator::emitCodeI(op, tmpDst, tmpSrc, ((NumberTreeNode<int> *)lhs)->get());
			if (reg != NULL) *reg = tmpDst;
		} else if (regL > 0 && regR == -2) {
			if (op == "=") {
				CodeGenerator::emitCodeI(op, regL, 0, ((NumberTreeNode<int> *)rhs)->get());
				if (reg != NULL) *reg = regL;
			} else {
				CodeGenerator::emitCodeI(op, tmpDst, regL, ((NumberTreeNode<int> *)rhs)->get());
				if (reg != NULL) *reg = tmpDst;
			}
			returnBucket = NULL;
		} else if (regL == -1 && regR == -2) {
			if (op == "=") {
				CodeGenerator::emitCodeI(op, tmpDst, 0, ((NumberTreeNode<int> *)rhs)->get());
				CodeGenerator::emitCodeM(bucketL->getSize(),storeOPL, locL, 29, tmpDst);
				if (reg != NULL) *reg = tmpDst;
			} else {
				CodeGenerator::emitCodeM(bucketL->getSize(),loadOPL, locL, 29, tmpSrc);
				CodeGenerator::emitCodeI(op, tmpDst, tmpSrc, ((NumberTreeNode<int> *)rhs)->get());
				if (reg != NULL) *reg = tmpDst;
			}
		}
		regManager->freeReg(tmpSrc);
	}
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
	bucketL = condition->genCode(symtab, &regL);
	CodeGenerator::addLabel(loop);
	selectOP(bucketL,regL,loadOPL,storeOPL,locL);
	if(regL == -1){
		int tmp = regManager->getTmpReg();
		CodeGenerator::emitCodeM(bucketL->getSize(),loadOPL, locL, 29, tmp);
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
	bucketR = dirExpr->genCode(symtab,&regR);
	CodeGenerator::addLabel(loop);
	selectOP(bucketR,regR,loadOPR,storeOPR,locR);
	if(regR == -1){
		int tmp = regManager->getTmpReg();
		CodeGenerator::emitCodeM(bucketR->getSize(),loadOPR, locR, 29, tmp);
		CodeGenerator::emitCodeJ("beq",tmp,0,0,breakn);
		regManager->freeReg(tmp);
	}
	else {
		CodeGenerator::emitCodeJ("beq",regR,0,0,breakn);
	}
	body->genCode(symtab, &regB);
	if(regL == -1){
		int tmp = regManager->getTmpReg();
		CodeGenerator::emitCodeM(bucketR->getSize(),loadOPR, locR, 29, tmp);
		if(direction == "to") {
			CodeGenerator::emitCodeI("+",tmp,tmp,1);
		}
		else {
			CodeGenerator::emitCodeI("-",tmp,tmp,1);
		}
		CodeGenerator::emitCodeM(bucketR->getSize(),storeOPR, locR, 29, tmp);
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
	selectOP(indexBucket, exprReg, loadOP, storeOP, indexLoc);
	if (exprReg == -2) {
		int offset = type->getLoc() + elemSize * ((NumberTreeNode<int>*)index)->get();
		returnBucket->setLoc(offset);
		if (reg != NULL) *reg = -1;
	} else if (exprReg == -1) { // stack
		int tmpSrc_1 = regManager->getTmpReg();
		int tmpSrc_2 = regManager->getTmpReg();
		int tmpDst   = regManager->getTmpReg();
		CodeGenerator::emitCodeM(indexBucket->getSize(), "load", indexLoc, 29,tmpSrc_1);
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
	return returnBucket;
}

SymBucket * RecordElemTreeNode::genCode(Symtab *symtab, int *reg) {
	env = symtab;
	SymBucket *returnBucket = new SymBucket("recordElem", lineNO, "",symtab);
	SymBucket *bucket = env->find(recordName);
	string type = bucket->getType();
	if (type.find("custom") != string::npos) {
		bucket = bucket->next;
	}
	SymBucket *member = bucket->next;
	do {
		if (member->getName() == elemName) {
			returnBucket->setLoc(member->getLoc());
			returnBucket->setSize(member->getSize());
		}
		member = member->last->next;
	} while (member != bucket);

}

////////////////////////////////////////////////////////////
// type gen symtab bucket functions						  //
////////////////////////////////////////////////////////////

// they only set size , the caller will bother setting loc

// type name is the l-side of type-definition, and type is the r-side
SymBucket* SysTypeTreeNode::genSymItem(const string typeName, Symtab *symtab) {
	cout << "type name :"  << typeName << endl;
	SymBucket *b = new SymBucket(typeName, lineNO, type, symtab);
	int size = getSize(type);
	b->setSize(size);
	return b;
}


// array need to consider about index type of sub range ,
SymBucket *ArrayTypeTreeNode::genSymItem(const string typeName, Symtab *symtab) {
	cout << "array node" << endl;
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
	else 
		len = pow(2,indexBucket->getSize()*8);
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
		SymBucket *typeBucket = v->getTypeNode()->genSymItem(v->getName(), symtab);
		vector<TreeNode*>& nameList = v->getNameList()->getList();
		if (v->getName() != "") 
			nameList.push_back(new TreeNode(v->getName()));
		for (int j = 0; j < nameList.size();j++) {
			SymBucket *vb = new SymBucket(nameList[j]->getName(), lineNO, typeBucket->getType(),symtab);
			vb->next = typeBucket;
			vb->last = typeBucket->last;
			typeBucket->next = vb;
			vb->setSize(typeBucket->getSize());
			rb->setSize(rb->getSize() + vb->getSize());
			if (rb->next == rb) {
				rb->next = vb;
				typeBucket->last->next = rb;
				rb->last = typeBucket->last;
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
	SymBucket *b = new SymBucket(typeName, lineNO, "ref-" + typeBucket->getName() + "-" + typeBucket->getType() , symtab);
	b->ref = typeBucket;
	b->setSize(typeBucket->getSize());
	return b;
}

