#include <typeinfo>
#include <queue>
#include "code_generator.h"
#include "public.h"
#include "symtab.h"

ofstream ast("AST");
ofstream code("CODE");
ofstream sym("SYM");
ofstream error("ERROR");
RegManager *regManager;
extern Symtab* mainSymtab;

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
		size = 4;
	else if (type == "real") 
		size = 8;
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
		if (!(type == "array" || type == "string" || type == "record") && !symtab->isRegSpill()) {
			int reg = symtab->genRegNum();
			b->setRegNum(reg);			
		} else {
			b->setLoc(symtab->genLoc(b->getSize()));
		}
		symtab->insert(b);
	}
}

void CustomTypeTreeNode::updateSymtab(Symtab *symtab) {
	env = symtab;
	SymBucket *b = new SymBucket(name, lineNO, "custom-" +type->getType(), symtab);
	b->next = type->genSymItem(name, symtab);
	b->next->next = b;
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


SymBucket * BinaryExprTreeNode::genCode(Symtab *symtab, int *reg) {
	cout << "bg : " << op << endl;
	env = symtab;
	int regR, regL;
	int locR, locL;
	SymBucket *returnBucket;
	SymBucket *bucketR, *bucketL;
	bucketR = rhs->genCode(env, &regR);
	bucketL = lhs->genCode(env, &regL);
	cout << "regL : " << regL << " regR " << regR << endl;
	if (regL == -1 && regR == -1) {
		locL = bucketL->getLoc();
		locR = bucketR->getLoc();
		int tmpSrc_1 = regManager->getTmpReg();
		int tmpSrc_2 = regManager->getTmpReg();
		int tmpDst = regManager->getTmpReg();
		if (op == "=") {
			CodeGenerator::emitCodeM("lw", locR, 29, tmpSrc_2);			
			CodeGenerator::emitCodeM("sw", locL, 29, tmpSrc_2);
			if (reg != NULL) *reg = tmpSrc_2;
			returnBucket = bucketL;
		} else {
			CodeGenerator::emitCodeM("lw", locL, 29, tmpSrc_1);
			CodeGenerator::emitCodeM("lw", locR, 29, tmpSrc_2);
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
		locR = bucketR->getLoc();
		int tmpReg = regManager->getTmpReg();
		CodeGenerator::emitCodeM("lw", locR, 29, tmpReg);
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
		locL = bucketL->getLoc();
		if (op == "=") {
			CodeGenerator::emitCodeM("sw", locL, 29, regR);
			if (reg != NULL) *reg = regR;
			returnBucket = bucketL;
		} else {
			int tmpSrc = regManager->getTmpReg();
			int tmpDst = regManager->getTmpReg();
			CodeGenerator::emitCodeM("lw", locL, 29, tmpSrc);
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
			locR = bucketR->getLoc();
			CodeGenerator::emitCodeM("lw", locR, 29, tmpSrc);
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
			locL = bucketL->getLoc();
			if (op == "=") {
				CodeGenerator::emitCodeI(op, tmpDst, 0, ((NumberTreeNode<int> *)rhs)->get());
				CodeGenerator::emitCodeM("sw", locL, 29, tmpDst);
				if (reg != NULL) *reg = tmpDst;
			} else {
				CodeGenerator::emitCodeM("lw", locL, 29, tmpSrc);
				CodeGenerator::emitCodeI(op, tmpDst, tmpSrc, ((NumberTreeNode<int> *)rhs)->get());
				if (reg != NULL) *reg = tmpDst;
			}
		}
		regManager->freeReg(tmpSrc);
	}
	return returnBucket;
}

////////////////////////////////////////////////////////////
// type gen symtab bucket functions						  //
////////////////////////////////////////////////////////////

// type name is the l-side of type-definition, and type is the r-side
SymBucket* SysTypeTreeNode::genSymItem(const string typeName, Symtab *symtab) {
	cout << "type name :"  << typeName << endl;
	SymBucket *b = new SymBucket(typeName, lineNO, type, symtab);
	int size = getSize(type);
	b->setSize(size);
	return b;
}


SymBucket* 