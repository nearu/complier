#include <queue>
#include "public.h"
#include "symtab.h"
ofstream ast("AST");
ofstream code("CODE");
ofstream sym("SYM");
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

void childrenGenCode(vector<TreeNode*>& children) {
	for(int i = 0; i < children.size(); i++) 
		children[i]->genCode(symtab);
}

void childrenUpdateSymtab(vector<TreeNode*>& children) {
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
	childrenUpdateSymtab(children);
}

void ListTreeNode::updateSymtab(Symtab *symtab) {
	childrenUpdateSymtab(children);	
}

void ConstTreeNode::updateSymtab(Symtab *symtab) {
	SymBucket b = new SymBucket(name, lineno, value->getType());
}

void NumberTreeNode::updateSymtab(Symtab *symtab) {

}


////////////////////////////////////////////////////////////
// gen code functions 									  //
////////////////////////////////////////////////////////////
void ProgramTreeNode::genCode() {
	routine->genCode();
}
void RoutineTreeNode::genCode() {
	body->genCode();
}

void ListTreeNode::genCode() {
	childrenGenCode(children);
}

void ConstTreeNode::genCode() {
	
}


