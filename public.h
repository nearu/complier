#ifndef _PUBLIC_H_
#define _PUBLIC_H_

#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
typedef int TokenType;
/*
* following variables are defined in main.c
*/
extern int lineno;
extern FILE *source;
extern FILE *listing;
extern string currentToken;
extern ofstream ast;
extern ofstream code;
extern ofstream sym;
class Symtab;
class SymBucket;


////////////////////////////////////////////////////////
// AST data structure								  //
////////////////////////////////////////////////////////
/*
* base class for all different kind of node within a AST
*/
class TreeNode {
private:
	const string treeName;
protected:
	Symtab *env;
	vector<TreeNode *> children;
	int lineNO;
public:
	TreeNode(const string _name):treeName(_name){}
	TreeNode():treeName(""){
		lineNO = lineno;
	}
	virtual ~TreeNode() {}
	virtual void printSelf() {
		ast << " TreeNode ";
	}
	virtual vector<TreeNode *> getChildren() {
		return children;
	}
	const string& getName() {
		return treeName;
	}
	virtual void insert(TreeNode* t) {}

	virtual void genCode() {
		code << "default genCode" << endl;
	}

	virtual void updateSymtab(Symtab *symtab) {
		sym << "default updateSymtab" << endl;
	}
	void setEnv(Symtab *e) {
		env = e;
	}
};


class StmtTreeNode : public TreeNode {
protected:
	int label;
public:
	virtual ~StmtTreeNode() {}
	void setLabel(int _label) {
		label = _label;
	}
	void printSelf() {
		ast << "StmtTreeNode";
	}
};

class IDTreeNode : public TreeNode {
public:
	virtual ~IDTreeNode() {}
	void printSelf() {
		ast << "IDTreeNode";
	}
	virtual const string getType() {}
};

/// expr node
class ExprTreeNode : public TreeNode {
public:
	virtual ~ExprTreeNode() {}
	void printSelf() {
		ast << "ExprTreeNode";
	}
};

/*
* base class for all kinds of type such as simple type, array type and record type
*/
class TypeTreeNode : public TreeNode {
public:
	virtual ~TypeTreeNode() {}
	void printSelf() {
		ast << "TypeTreeNode";
	}
	virtual SymBucket* genSymItem(const string typeName, Symtab *symtab){}
	virtual const string getType() {}
};

/*
* node contains a list of sub-nodes with same type
*/
class ListTreeNode : public TreeNode {
private:
	string typeName;
	vector<TreeNode *> list;
public:
	ListTreeNode( const string _name):typeName(_name) {
	}
	ListTreeNode( const string _name,  vector<TreeNode *>& _list)
	:typeName(_name),list(_list) {
	}
	//a.insert(a.end(), b.begin(), b.end());
	void append() {}
	void insert(TreeNode * newNode) {
		list.push_back(newNode);
	}
	TreeNode *get(int index) {
		return list[index];
	}
	int size() {
		return list.size();
	}
	vector<TreeNode *>& getList() {
		return list;
	}
	void printSelf() {
		ast << "a list of " << typeName<<":"<<list.size();	
	}
	vector<TreeNode *> getChildren() {
		return list;
	}

	void genCode();
	void updateSymtab(Symtab*);

};

//=====================================================================
/// struct node
/*
* node for routine head
*/
class RoutineHeadTreeNode : public TreeNode {
private:
	ListTreeNode * constPart;
	ListTreeNode * typePart;
	ListTreeNode * varPart;
	ListTreeNode * routinePart;
public:
	RoutineHeadTreeNode( TreeNode *_constPart,  TreeNode *_typePart, 
		 TreeNode *_varPart,  TreeNode *_routinePart)
		:constPart((ListTreeNode*)_constPart), typePart((ListTreeNode*)_typePart)
		, varPart((ListTreeNode*)_varPart),routinePart((ListTreeNode*)_routinePart)
		{
			children.push_back(constPart);
			children.push_back(typePart);
			children.push_back(varPart);
			children.push_back(routinePart);
		}
	void printSelf() {
		ast << "RoutineHead";
	}
	void updateSymtab(Symtab *);
	void genCode();
};
/*
* node for routine
*/
class RoutineTreeNode : public TreeNode {
private:
	RoutineHeadTreeNode *head;
	ListTreeNode *body;
public:
	RoutineTreeNode( TreeNode *_head,  TreeNode *_body)
					:head((RoutineHeadTreeNode*)_head), body((ListTreeNode *)_body) 
					{
						children.push_back(head);
						children.push_back(body);
					}
	void printSelf() {
		ast << "RoutineTreeNode";
	}					
	void genCode();
	void updateSymtab(Symtab*);

};

class ProgramHeadTreeNode : public TreeNode {
private:
	const string name;
public:
	ProgramHeadTreeNode(const string _name):name(_name){}

	const string& getName() {
		return name;
	}
	void printSelf() {
		ast << "ProgramHeadTreeNode";
	}
};

/*
* root of the AST, representing the whole program
*/
class ProgramTreeNode : public TreeNode {
private:
	const string name;
	RoutineTreeNode * routine;
public:
	ProgramTreeNode( const string _name,  TreeNode * _routine):name(_name), routine((RoutineTreeNode *)_routine)
	{
		children.push_back(routine);
	}
	void printSelf() {
		ast << "ProgramTreeNode";
	}
	void genCode();
	void updateSymtab(Symtab*);
};

//======
//===============================================================
///type node

/*
* node for user defined type
*/
class CustomTypeTreeNode : public TypeTreeNode {
private:
	const string name;
	TypeTreeNode *type;
public:
	
	///if type is null, then it means we need to check whether this 
	///type exists
	CustomTypeTreeNode( const string _name,  TreeNode* _type=NULL) 
						: name(_name),type((TypeTreeNode*)_type)
						{}
	void printSelf() {
		ast << "CustomTypeTreeNode:" << name;
	}
	void updateSymtab(Symtab *);
};

/*
* node for simple type such as sys type , subrange type, enum tpye
*/
class SimpleTypeTreeNode : public TypeTreeNode {
public:
	virtual ~SimpleTypeTreeNode() {}
};

class SysTypeTreeNode : public SimpleTypeTreeNode {
private:
	const string type;
public:
	SysTypeTreeNode( const string _name):type(_name){}
	void printSelf() {
		ast << "SysTypeTreeNode";
	}
	const string getType() {
		return type;
	}
	SymBucket *genSymItem(const string type, Symtab *symtab);
};

class SubRangeTypeTreeNode : public SimpleTypeTreeNode {
private:
	IDTreeNode *upperBound;
	IDTreeNode *lowerBound;
public:
	SubRangeTypeTreeNode( TreeNode *_u, TreeNode *_l)
						:upperBound((IDTreeNode*)_u), lowerBound((IDTreeNode*)_l)
						{}
	void printSelf() {
		ast << "SubRangeTypeTreeNode";
	}
	const string getType() {
		return "subrange";
	}
};

/*
* node for enum type
*/
class EnumTypeTreeNode : public SimpleTypeTreeNode {
private:
	const string name;
	ListTreeNode* elemList;
public:
	EnumTypeTreeNode(TreeNode* _elemList,const string _name="")
					:name(_name), elemList((ListTreeNode*)_elemList)
					{}
	void printSelf() {
		ast << "EnumTypeTreeNode";
	}					
	const string getType() {
		return "enum";
	}
};

/*
* node for array type
*/
class ArrayTypeTreeNode : public TypeTreeNode {
private:
	SimpleTypeTreeNode *indexType;
	TypeTreeNode *elemType;
public:
	ArrayTypeTreeNode(TreeNode *_indexType,
					 TreeNode *_elemType):indexType((SimpleTypeTreeNode*)_indexType),elemType((TypeTreeNode*)_elemType)
	{
		// children.push_back(indexType);
		// children.push_back(elemType);
	}
	void printSelf() {
		ast << "ArrayTypeTreeNode";
	}	
	const string getType() {
		return "array";
	}
};

/*
* node for record type
*/
class RecordTypeTreeNode : public TypeTreeNode {
private:
	ListTreeNode * elemList;
public:
	RecordTypeTreeNode( TreeNode *_list)
						:elemList((ListTreeNode*)_list)
						{
							// children.push_back(elemList);
						}
	void printSelf() {
		ast << "RecordTypeTreeNode";
	}	
	const string getType() {
		return "record";
	}						
};

//==============================================================
/// id node

/**
* node for differnet kinds of  values
*/
template <class T>
class NumberTreeNode : public IDTreeNode {
private:
	T value;
	const string type;
public:
	NumberTreeNode(T v, const string _type):value(v),type(_type) {}
	T get() {
		return value;
	}
	const string getType() {
		return type;
	}
	void set(T v) {
		value = v;
	}
	void printSelf() {
		ast << "NumberTreeNode";
	}	


};

/*
*  node for  variables
*/
class ConstTreeNode : public IDTreeNode {
private:
	const string name;
	IDTreeNode *value; // NumberTreeNode
public:
	ConstTreeNode( const string _name,  TreeNode *_value)
				:name(_name),value((IDTreeNode*)_value)
				{}
	void printSelf() {
		ast << "ConstTreeNode";
	}
	void genCode();
	void updateSymtab(Symtab* symtab);
};

/*
* node for variables such as "fuck", it represents three kinds
* of variable: only a name, a name with a type, a list of name with a type
* if this node's type is NULL, we need to determine it in the analysis pass
*/
/// copy by reference if ref = 1, else copy by value
/// if this node is not within a arg-list , then ref can be ignored
class VariableTreeNode : public IDTreeNode {
private:
	const string name;
	TypeTreeNode * typeNode;
	ListTreeNode *nameList;
	int ref;
public:
	VariableTreeNode( const string _name = "",  TreeNode* _type=NULL, int _ref = 0)
	:name(_name), typeNode((TypeTreeNode*)_type), nameList(NULL),ref(_ref)
	 {}
	VariableTreeNode(TreeNode *_list, TreeNode* _type=NULL, int _ref = 0)
	:name(""),typeNode((TypeTreeNode*)_type),ref(_ref),nameList((ListTreeNode*)_list)
	{}
	const string& getName() {
		return name;
	}
	const TypeTreeNode* getTreeNodeType() {
		return typeNode;
	}
	ListTreeNode *getNameList() {
		return nameList;
	}
	int getRef() {
		return ref;
	}
	void printSelf() {
		ast << "VariableTreeNode:";
		if (name != "") {
			ast << name;
		} else {
			vector<TreeNode *> list = nameList->getList();
			if (list.size() > 0) {
				for (int i = 0; i < list.size(); i++) 
					ast << list[i]->getName();
			}
		}

	}	
	void updateSymtab(Symtab*);
};

class ArrayElemTreeNode : public IDTreeNode {
private:
	const string name;
	ExprTreeNode *index;
public:
	ArrayElemTreeNode( const string _name,  TreeNode *_index)
					: name(_name), index((ExprTreeNode*)_index) 
					{}
	void printSelf() {
		ast << "ArrayElemTreeNode:" << name;
	}					
};

class RecordElemTreeNode : public IDTreeNode {
private:
	const string recordName;
	const string elemName;
public:
	RecordElemTreeNode( const string& _rName,  const string& _eName)
					:recordName(_rName), elemName(_eName)
					{}
	void printSelf() {
		ast << "RecordElemTreeNode:"<<recordName<<"."<<elemName;
	}						
};

//===============================================
//expr nodes
/*
* node for unary operator
*/
class UnaryExprTreeNode : public ExprTreeNode {
private:
	const string op;
	TreeNode *oprand;
public:
	UnaryExprTreeNode(const string _op,  TreeNode *_operand):op(_op),oprand(_operand)
	{
		children.push_back(oprand);
	}
	void printSelf() {
		ast << "UnaryExprTreeNode";
	}	
};
/*
* node for binary operaotr such as '+'  '='
*/
class BinaryExprTreeNode : public ExprTreeNode {
private:
	const string op;
	TreeNode * rhs, *lhs;
public:
	BinaryExprTreeNode(const string _op,  TreeNode* r,  TreeNode* l)
						:op(_op),rhs(r),lhs(l) 
	{
		children.push_back(rhs);
		children.push_back(lhs);
	}
	void printSelf() {
		ast << "BinaryExprTreeNode";
	}	
	
	void genCode();
};

/*
* node for function call
*/
class CallExprTreeNode : public ExprTreeNode {
private:
	const string name;
	vector<TreeNode *> args;
public:
	CallExprTreeNode( const string _name,  vector<TreeNode *> _args )
						:name(_name), args(_args){}
	CallExprTreeNode( const string _name)
						:name(_name){}
	void printSelf() {
		ast << "BinaryExprTreeNode";
	}
};

class CaseExprTreeNode : public ExprTreeNode {
private:
	IDTreeNode *label;
	StmtTreeNode *stmt;
public:
	CaseExprTreeNode( TreeNode* _label,  TreeNode *_stmt)
					: label((IDTreeNode*)_label), stmt((StmtTreeNode*)_stmt){}
	void printSelf() {
		ast << "CaseExprTreeNode";
	}					
};


//======================================================
///function and procedure node
/*
* node for function definition
*/
class FunctionTreeNode : public TreeNode {
private:
	const string name;
	ListTreeNode* args;
	SimpleTypeTreeNode* returnType;
	ListTreeNode* body;
public:
	FunctionTreeNode( const string _name,  TreeNode* _args, 
		 TreeNode* _returnType,  TreeNode* _body)
		:name(_name), args((ListTreeNode*)_args), returnType((SimpleTypeTreeNode*)_returnType), body((ListTreeNode*)_body)
		{
			children.push_back(args);
			children.push_back(body);
		}
	void printSelf() {
		ast << "FunctionTreeNode";
	}		

};

/*
* node for procedure definition
*/
class ProcedureTreeNode :  public TreeNode {
private:
	const string name;
	ListTreeNode * args;
	ListTreeNode * body;
public:
	ProcedureTreeNode( const string _name,  TreeNode *  _args, 
		 TreeNode *  _body)
		:name(_name), args((ListTreeNode*)_args), body((ListTreeNode*)_body)
		{
			children.push_back(args);
			children.push_back(body);
		}
	void printSelf() {
		ast << "ProcedureTreeNode";
	}		

};



//======================================================
///stmt node


class CompoundStmtTreeNode : public StmtTreeNode {
private:
	ListTreeNode *stmtList;
public:
	CompoundStmtTreeNode( TreeNode *list)
						:stmtList((ListTreeNode*)list)
	{
		children.push_back(stmtList);
	}
	void printSelf() {
		ast << "CompoundStmtTreeNode";
	}	

};

class IfStmtTreeNode : public StmtTreeNode {
private:
	ExprTreeNode *condition;
	CompoundStmtTreeNode *body;
	StmtTreeNode *elsePart;
	void addChildren() {
		children.push_back(condition);
		children.push_back(body);
		children.push_back(elsePart);
	}
public:
	IfStmtTreeNode( TreeNode *e,  TreeNode *c)
				:condition((ExprTreeNode*)e), body((CompoundStmtTreeNode*)c)
	{
		addChildren();
	}
	IfStmtTreeNode( TreeNode *e,  TreeNode *c,
		 TreeNode *s)
				:condition((ExprTreeNode*)e), body((CompoundStmtTreeNode*)c),elsePart((StmtTreeNode*)s){
					addChildren();
				}	
	void printSelf() {
		ast << "IfStmtTreeNode";
	}							

};

class RepeatStmtTreeNode : public StmtTreeNode {
private:
	CompoundStmtTreeNode *body;
	ExprTreeNode *condition;
public:
	RepeatStmtTreeNode( TreeNode *_body, TreeNode *_cond) 
					: body((CompoundStmtTreeNode*)_body), condition((ExprTreeNode*)_cond)
	{
		children.push_back(condition);
		children.push_back(body);
	}
	void printSelf() {
		ast << "RepeatStmtTreeNode";
	}	
};

class WhileStmtTreeNode : public StmtTreeNode {
private:
	StmtTreeNode *body;
	ExprTreeNode *condition;
public:
	WhileStmtTreeNode( TreeNode* _body,  TreeNode *_cond)
					: body((StmtTreeNode*)_body),condition((ExprTreeNode*)_cond)
	{
		children.push_back(condition);
		children.push_back(body);
	}
	void printSelf() {
		ast << "WhileStmtTreeNode";
	}	

};

/*
* switch stmt
*/
class SwitchStmtTreeNode : public StmtTreeNode {
private:
	TreeNode *expr;
	ListTreeNode *caseExprList;
public:
	SwitchStmtTreeNode( TreeNode *_expr,  TreeNode *_list)
				:expr(_expr), caseExprList((ListTreeNode*)_list)
	{
		children.push_back(expr);
		children.push_back(caseExprList);
	}
	void printSelf() {
		ast << "SwitchStmtTreeNode";
	}	
};

class ForStmtTreeNode : public StmtTreeNode {
private:
	ExprTreeNode *assignExpr;
	const string direction;
	TreeNode *dirExpr; // may be a variable
	StmtTreeNode *body;
public:
	ForStmtTreeNode( TreeNode * _aExpr, const string _dire, 
		 TreeNode *_dExpr,  TreeNode* _body)
		: assignExpr((ExprTreeNode*)_aExpr), direction(_dire), dirExpr(_dExpr), body((StmtTreeNode*)_body)
		{
			children.push_back(assignExpr);
			children.push_back(dirExpr);
			children.push_back(body);
		}
	void printSelf() {
		ast << "ForStmtTreeNode";
	}		
};


class GotoStmtTreeNode : public StmtTreeNode {
private:
	const string label;
public:
	GotoStmtTreeNode(const string _label):label(_label){}
	void printSelf() {
		ast << "GotoStmtTreeNode";
	}	
};
/*
* if treceScan = TRUE, every token along with lineno will be 
* print in listing file
*/
extern int traceScan;

void printAST(TreeNode *root);
#endif