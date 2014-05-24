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
};

class StmtTreeNode : public TreeNode {
public:
	virtual ~StmtTreeNode() {}
};

class IDTreeNode : public TreeNode {
public:
	virtual ~IDTreeNode() {}
};

/// expr node
class ExprTreeNode : public TreeNode {

public:
	virtual ~ExprTreeNode() {}
};

/*
* base class for all kinds of type such as simple type, array type and record type
*/
class TypeTreeNode : public TreeNode {
public:
	virtual ~TypeTreeNode() {}
};

/*
* node contains a list of sub-nodes with same type
*/
template <class T>
class ListTreeNode {
private:
	std::string typeName;
	std::vector<T *> list;
public:
	ListTreeNode( std::string& _name):typeName(_name) {}
	ListTreeNode( std::string& _name,  std::vector<T *>_list)
	:typeName(_name),list(_list) {}
	//a.insert(a.end(), b.begin(), b.end());
	void append() {}
	void insert(T * elem) {
		list.push_back(elem);
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
	CustomTypeTreeNode( std::string& _name,  TypeTreeNode* _type) 
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
	EnumTypeTreeNode( std::string &_name,  std::vector<std::string>& _elemList)
					:name(_name), elemList(_elemList)
					{}
};

/*
* node for array type
*/
class ArrayTypeTreeNode : public TypeTreeNode {
private:
	std::string name;
	SimpleTypeTreeNode *indexType;
	TypeTreeNode *elemType;
public:
	ArrayTypeTreeNode( std::string& _name,  SimpleTypeTreeNode *_indexType,
					 TypeTreeNode *_elemType):name(_name), indexType(_indexType),elemType(_elemType)
	{}
};

/*
* node for record type
*/
class RecordTypeTreeNode : public TypeTreeNode {
private:
	std::string name;
	std::vector<ListTreeNode *> elemList;
public:
	RecordTypeTreeNode( std::string& _name,  std::vector<ListTreeNode *>& _list)
						: name(_name), elemList(_list)
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
};

/*
*  node for  variables
*/
class ConstTreeNode : public IDTreeNode {
private:
	std::string name;
	IDTreeNode *value;
public:
	ConstTreeNode( std::string& _name,  IDTreeNode *_value)
				:name(_name),value(_value)
				{}
};
/*
* node for variables such as "fuck"
*/
class VariableTreeNode : public IDTreeNode {
private:
	std::string name;
	std::string type;
public:
	VariableTreeNode( std::string& _name,  std::string& _type):name(_name), type(_type) {}
	VariableTreeNode( std::string& _name):name(_name), type("") {}
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
	char op;
	TreeNode *oprand;
public:
	UnaryExprTreeNode(char _op,  TreeNode *_operand):op(_op),oprand(_operand)
	{}
};
/*
* node for binary operaotr such as '+'  '='
*/
class BinaryExprTreeNode : public ExprTreeNode {
private:
	char op;
	TreeNode * rhs, *lhs;
public:
	BinaryExprTreeNode(char _op,  TreeNode* r,  TreeNode* l)
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
	CompoundStmtTreeNode( ListTreeNode *list):stmtList(list){}

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