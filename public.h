#ifndef _PUBLIC_H_
#define _PUBLIC_H_
#ifndef YYPARSER
#include "parser.hpp"
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif
#include <string>
#include <vector>
using namespace std;
typedef int TokenType;
/*
* following variables are defined in main.c
*/
int lineno;
FILE *source;
FILE *listing;

/*
* base class for all different kind of node within a AST
*/
class TreeNode {
public:
	virtual ~TreeNode() {}
	virtual void traverse() {};
	virtual void printSelf() {
		cout << " TreeNode ";
	}
};

class StmtTreeNode : public TreeNode {
protected:
	int lable;
public:
	virtual ~StmtTreeNode() {}
	void setLable(int _lable) {
		lable = _lable;
	}
	void printSelf() {
		cout << "StmtTreeNode";
	}
};

class IDTreeNode : public TreeNode {
public:
	virtual ~IDTreeNode() {}
	void printSelf() {
		cout << "IDTreeNode";
	}
};

/// expr node
class ExprTreeNode : public TreeNode {
public:
	virtual ~ExprTreeNode() {}
	void printSelf() {
		cout << "ExprTreeNode";
	}
};

/*
* base class for all kinds of type such as simple type, array type and record type
*/
class TypeTreeNode : public TreeNode {
public:
	virtual ~TypeTreeNode() {}
	void printSelf() {
		cout << "TypeTreeNode";
	}
};

/*
* node contains a list of sub-nodes with same type
*/
class ListTreeNode : public TreeNode{
private:
	std::string typeName;
	std::vector<TreeNode *> list;
public:
	ListTreeNode( std::string& _name):typeName(_name) {}
	ListTreeNode( std::string& _name,  std::vector<TreeNode *>& _list)
	:typeName(_name),list(_list) {}
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
		cout << "a list of " << typeName;
	}
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
	RoutineHeadTreeNode( ListTreeNode *_constPart,  ListTreeNode *_typePart, 
		 ListTreeNode *_varPart,  ListTreeNode *_routinePart)
		:constPart(_constPart), typePart(_typePart), varPart(_varPart),routinePart(_routinePart)
		{}
	void printSelf {
		cout << "RoutineHead : " <<
	}
};
/*
* node for routine
*/
class RoutineTreeNode : public TreeNode {
private:
	RoutineHeadTreeNode *head;
	ListTreeNode *body;
public:
	RoutineTreeNode( RoutineHeadTreeNode *_head,  ListTreeNode *_body)
					:head(_head), body(_body) 
					{}
};

class ProgramHeadTreeNode : public TreeNode {
private:
	std::string name;
public:
	ProgramHeadTreeNode(std::string _name):name(_name){}
};

/*
* root of the AST, representing the whole program
*/
class ProgramTreeNode : public TreeNode {
private:
	std::string name;
	RoutineTreeNode * routine;
public:
	ProgramTreeNode( std::string& _name,  RoutineTreeNode * _routine):name(_name), routine(_routine)
	{}

};

//======
//===============================================================
///type node

/*
* node for user defined type
*/
class CustomTypeTreeNode : TypeTreeNode {
private:
	std::string name;
	TypeTreeNode *type;
public:
	
	///if type is null, then it means we need to check whether this 
	///type exists
	CustomTypeTreeNode( std::string& _name,  TypeTreeNode* _type=NULL) 
						: name(_name),type(_type)
						{}

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
	std::string name;
public:
	SysTypeTreeNode( std::string& _name):name(_name){}
};

class SubRangeTypeTreeNode : public SimpleTypeTreeNode {
private:
	IDTreeNode *upperBound;
	IDTreeNode *lowerBound;
public:
	SubRangeTypeTreeNode( IDTreeNode *_u, IDTreeNode *_l)
						:upperBound(_u), lowerBound(_l)
						{}
};

/*
* node for enum type
*/
class EnumTypeTreeNode : public SimpleTypeTreeNode {
private:
	std::string name;
	std::vector<std::string> elemList;
public:
	EnumTypeTreeNode(std::vector<std::string>& _elemList,std::string &_name = "")
					:name(_name), elemList(_elemList)
					{}

};

/*
* node for array type
*/
class ArrayTypeTreeNode : public TypeTreeNode {
private:
	SimpleTypeTreeNode *indexType;
	TypeTreeNode *elemType;
public:
	ArrayTypeTreeNode(SimpleTypeTreeNode *_indexType,
					 TypeTreeNode *_elemType):indexType(_indexType),elemType(_elemType)
	{}
};

/*
* node for record type
*/
class RecordTypeTreeNode : public TypeTreeNode {
private:
	ListTreeNode * elemList;
public:
	RecordTypeTreeNode( ListTreeNode *_list)
						:elemList(_list)
						{}
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
public:
	NumberTreeNode(T v):value(v) {}
	T get() {
		return value;
	}
	void set(T v) {
		value = v;
	}
};

/*
*  node for  variables
*/
class ConstTreeNode : public IDTreeNode {
private:
	std::string name;
	IDTreeNode *value; // NumberTreeNode
public:
	ConstTreeNode( std::string& _name,  IDTreeNode *_value)
				:name(_name),value(_value)
				{}


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
	std::string name;
	TypeTreeNode * type;
	ListTreeNode *nameList;
	int ref;
public:
	VariableTreeNode( std::string& _name="",  TypeTreeNode* _type=NULL, int _ref = 0)
	:name(_name), type(_type), nameList(NULL),ref(_ref)
	 {}
	VariableTreeNode(ListTreeNode *_list, TypeTreeNode* _type=NULL, int _ref)
	:name(""),type(_type),ref(_ref)
	{}
	const string& getName() {
		return name;
	}
	const string getType() {
		return type;
	}
	ListTreeNode *getNameList() {
		return nameList;
	}
	int getRef() {
		return ref;
	}
};

class ArrayElemTreeNode : public IDTreeNode {
private:
	std::string name;
	ExprTreeNode *index;
public:
	ArrayElemTreeNode( std::string& _name,  ExprTreeNode *_index)
					: name(_name), index(_index) 
					{}
};

class RecordElemTreeNode : public IDTreeNode {
private:
	std::string recordName;
	std::string elemName;
public:
	RecordElemTreeNode( std::string& _rName,  std::string& _eName)
					:recordName(_rName), elemName(_eName)
					{}
};

//===============================================
//type nodes
/*
* node for unary operator
*/
class UnaryExprTreeNode : public ExprTreeNode {
private:
	std::string op;
	TreeNode *oprand;
public:
	UnaryExprTreeNode(std::string& _op,  TreeNode *_operand):op(_op),oprand(_operand)
	{}
};
/*
* node for binary operaotr such as '+'  '='
*/
class BinaryExprTreeNode : public ExprTreeNode {
private:
	std::string op;
	TreeNode * rhs, *lhs;
public:
	BinaryExprTreeNode(std::string& _op,  TreeNode* r,  TreeNode* l)
						:op(_op),rhs(r),lhs(l) {}

};

/*
* node for function call
*/
class CallExprTreeNode : public ExprTreeNode {
private:
	std::string name;
	std::vector<TreeNode *> args;
public:
	CallExprTreeNode( std::string& _name,  std::vector<TreeNode *> _args )
						:name(_name), args(_args){}
	CallExprTreeNode( std::string& _name)
						:name(_name){}

};

class CaseExprTreeNode : public ExprTreeNode {
private:
	IDTreeNode *lable;
	StmtTreeNode *stmt;
public:
	CaseExprTreeNode( IDTreeNode* _lable,  StmtTreeNode *_stmt)
					: lable(_lable), stmt(_stmt){}
};
//======================================================
///function and procedure node
/*
* node for function definition
*/
class FuntionTreeNode : public TreeNode {
private:
	std::string name;
	std::vector<VariableTreeNode *> args;
	std::string returnType;
	std::vector<TreeNode*> body;
public:
	FuntionTreeNode( std::string& _name,  std::vector<VariableTreeNode *> _args, 
		 std::string& _returnType,  std::vector<TreeNode *>& _body)
		:name(_name), args(_args), returnType(_returnType), body(_body){}

};

/*
* node for procedure definition
*/
class ProcedureTreeNode :  public TreeNode {
private:
	std::string name;
	std::vector<VariableTreeNode *> args;
	std::vector<TreeNode*> body;
public:
	ProcedureTreeNode( std::string& _name,  std::vector<VariableTreeNode *> _args, 
		 std::vector<TreeNode *>& _body)
		:name(_name), args(_args), body(_body){}

};

//======================================================
///stmt node


class CompoundStmtTreeNode : public StmtTreeNode {
private:
	ListTreeNode *stmtList;
public:
	CompoundStmtTreeNode( ListTreeNode *list)
						:stmtList(list){}

};

class IfStmtTreeNode : public StmtTreeNode {
private:
	ExprTreeNode *condition;
	CompoundStmtTreeNode *body;
	StmtTreeNode *elsePart;
public:
	IfStmtTreeNode( ExprTreeNode *e,  CompoundStmtTreeNode *c)
				:condition(e), body(c){}
	IfStmtTreeNode( ExprTreeNode *e,  CompoundStmtTreeNode *c,
		 StmtTreeNode *s)
				:condition(e), body(c),elsePart(s){}				

};

class RepeatStmtTreeNode : public StmtTreeNode {
private:
	CompoundStmtTreeNode *body;
	ExprTreeNode *condition;
public:
	RepeatStmtTreeNode( CompoundStmtTreeNode *_body, ExprTreeNode *_cond) 
					: body(_body), condition(_cond)
					{}
};

class WhileStmtTreeNode : public StmtTreeNode {
private:
	StmtTreeNode *body;
	ExprTreeNode *condition;
public:
	WhileStmtTreeNode( StmtTreeNode* _body,  ExprTreeNode *_cond)
					: body(_body),condition(_cond){}

};

/*
* switch stmt
*/
class SwitchStmtTreeNode : public StmtTreeNode {
private:
	TreeNode *expr;
	ListTreeNode *caseExprList;
public:
	SwitchStmtTreeNode( TreeNode *_expr,  ListTreeNode *_list)
				:expr(_expr), caseExprList(_list){}
};

class ForStmtTreeNode : public StmtTreeNode {
private:
	ExprTreeNode *assignExpr;
	std::string direction;
	TreeNode *dirExpr; // may be a variable
	StmtTreeNode *body;
public:
	ForStmtTreeNode( ExprTreeNode * _aExpr,  std::string& _dire, 
		 TreeNode *_dExpr,  StmtTreeNode* _body)
		: assignExpr(_aExpr), direction(_dire), dirExpr(_dExpr), body(_body){}
};


class GotoStmtTreeNode : public StmtTreeNode {
private:
	int lable;
public:
	GotoStmtTreeNode(int _lable):lable(_lable){}
};
/*
* if treceScan = TRUE, every token along with lineno will be 
* print in listing file
*/
int traceScan;
#endif