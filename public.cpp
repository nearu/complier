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
void childrenGenCode(vector<TreeNode*>& children) {
	for(int i = 0; i < children.size(); i++) 
		children[i]->genCode();
}

void childrenUpdateSymtab(vector<TreeNode*>& children, Symtab *symtab) {
	for(int i = 0; i < children.size(); i++) 
		children[i]->updateSymtab(symtab);
}



////////////////////////////////////////////////////////////
// update symtab functions								  //
////////////////////////////////////////////////////////////

void ProgramTreeNode::updateSymtab(Symtab *symtab) {
	routine->updateSymtab(symtab);	
}

void RoutineTreeNode::updateSymtab(Symtab* symtab) {
	head->updateSymtab(symtab);
}	

void RoutineHeadTreeNode::updateSymtab(Symtab *symtab) {
	childrenUpdateSymtab(children, symtab);
}

void ListTreeNode::updateSymtab(Symtab *symtab) {
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
	cout << "vu" <<endl;
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


SymBucket * ProgramTreeNode::genCode(int *reg) {
	routine->genCode();
	return NULL;
}

SymBucket * RoutineTreeNode::genCode(int *reg) {
	body->genCode();
	return NULL;
}

SymBucket * ListTreeNode::genCode(int *reg) {
	childrenGenCode(children);
	return 0;
}

SymBucket * ConstTreeNode::genCode(int *reg) {
	*reg = -1;
	return env->find(name);
}

SymBucket * VariableTreeNode::genCode(int *reg) {
	SymBucket *b = env->find(name);
	if (b != NULL) {
		int reg = b->getRegNum();
	} else {
		cout << lineNO << "variable " << name << " is not defined" << endl;
	}
	return b;
}

// const var parts will be processed later
SymBucket * RoutineHeadTreeNode::genCode(int *reg) {

	return 0;
}

SymBucket * BinaryExprTreeNode::genCode(int *reg) {
	int regR, regL;
	int locR, locL;
	SymBucket *bucketR, *bucketL;
	bucketR = rhs->genCode(&regR);
	bucketL = lhs->genCode(&regL);
	if (regL == -1 && regR == -1) {
		locL = bucketL->getLoc();
		locR = bucketR->getLoc();
	} else if (regL != -1 && regR != -1) {
		CodeGenerator::emitCodeR(op, regL, regR, 0);
	} else if (regL != -1 && regR == -1) {

	} else if (regL == -1 && regR != -1) {

	}
	
	return 0;
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