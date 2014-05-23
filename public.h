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
#define MAX_CHILDREN 10;
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
	virtual ~treeNode() {}
	virtual void traverse() {};
};


/*
* node contains a list of sub-nodes with same type
*/
class ListTreeNode {
private:
	std::string typeName;
	std::vector<T *> list;
public:
	ListTreeNode(const std::string& _name):typeName(_name) {}
	ListTreeNode(const std::string& _name, const std::vector<TreeNode *>_list)
	:typeName(_name),list(_list) {}
	//a.insert(a.end(), b.begin(), b.end());
	void append() {}
	void insert(T * newNode) {
		list.push_back(newNode);
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
	RoutineHeadTreeNode(const ListTreeNode *_constPart, const ListTreeNode *_typePart, 
		const ListTreeNode *_varPart, const ListTreeNode *_routinePart)
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
	RoutineTreeNode(const RoutineHeadTreeNode *_head, const ListTreeNode *body)
					:head(_head), body(_body) 
					{}
};
/*
* root of the AST, representing the whole program
*/
class ProgramTreeNode : public TreeNode {
private:
	std::string name;
	RoutineTreeNode * routine;
public:
	ProgramTreeNode(const std::string& _name, const RoutineTreeNode * _routine):name(_name), routine(_routine)
	{}

};

//=====================================================================
///type node
/*
* base class for all kinds of type such as simple type, array type and record type
*/
class TypeTreeNode : public TreeNode {
public:
	virtual ~TypeTreeNode() {}
};
/*
* node for user defined type
*/
class CustomTypeTreeNode : TypeTreeNode {
private:
	std::string name;
	TypeTreeNode *type;
public:
	CustomTypeTreeNode(const std::string& _name, const TypeTreeNode* _type) 
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
	SysTypeTreeNode(const std::string& _name):name(_name){}
};

class SubRangeTypeTreeNode : public SimpleTypeTreeNode {
private:
	NumberTreeNode *upperBound;
	NumberTreeNode *lowerBound;
public:
	SubRangeTypeTreeNode(const NumberTreeNode *_u,const NumberTreeNode *_l)
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
	EnumTypeTreeNode(const std::string &_name, const std::vector<std::string>& _elemList)
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
	ArrayTypeTreeNode(const std::string& _name, const SimpleTypeTreeNode *_indexType,
					const TypeTreeNode *_elemType):name(_name), indexType(_indexType),elemType(_elemType)
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
	RecordTypeTreeNode(const std::string& _name, const std::vector<ListTreeNode *>& _list)
						: name(_name), list(_list)
						{}
};
//==============================================================
/// id node
/**
* node for differnet kinds of const values
*/
class IDTreeNode : public TreeNode {
public:
	virtual ~IDTreeNode() {}
};
template <class T>
class NumberTreeNode : public IDTreeNode {
private:
	T value;
public:
	NumberTreeNode(T v):value(v) {}
};

/*
*  node for const variables
*/
class ConstTreeNode : public IDTreeNode {
private:
	std::string name;
	NumberTreeNode *value;
public:
	ConstTreeNode(const std::string& _name, const NumberTreeNode *_value)
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
	VariableTreeNode(const std::string& _name, const std::string& _type):name(_name), type(_type) {}
};

class ArrayElemTreeNode : public IDTreeNode {
private:
	std::string name;
	ExprTreeNode *index;
public:
	ArrayElemTreeNode(const std::string& _name, const ExprTreeNode *_index)
					: name(_name), index(_index) 
					{}
};

class RecordElemTreeNode : public IDTreeNode {
private:
	std::string recordName;
	std::string elemName;
public:
	RecordElemTreeNode(const std::string& _rName, const std::string& _eName)
					:recordName(_rName), elemName(_eName)
					{}
};
//===============================================
/// expr node
class ExprTreeNode : public TreeNode {

public:
	virtual ~ExprTreeNode() {}
};

/*
* node for unary operator
*/
class UnaryExprTreeNode : public ExprTreeNode {
private:
	char op;
	TreeNode *oprand;
public:
	UnaryExprTreeNode(char _op, const TreeNode *_operand):op(_op),operand(_operand)
	{}
};
/*
* node for binary operaotr such as '+'  '='
*/
class BinaryExprTreeNode : public ExprTreeNode {
private:
	char op;
	TreeNode * rhs, lhs;
public:
	BinaryExprTreeNode(char _op, const TreeNode* r, const TreeNode* l)
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
	CallExprTreeNode(const std::string& _name, const std::vector<TreeNode *> _args )
						:name(_name), args(_args){}

};

class CaseExprTreeNode : public ExprTreeNode {
private:
	IDTreeNode *lable;
	StmtTreeNode *stmt;
public:
	CaseExprTreeNode(const IDTreeNode* _lable, const StmtTreeNode *_stmt)
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
	FuntionTreeNode(const std::string& _name, const std::vector<VariableTreeNode *> _args, 
		const std::string& _returnType, const std::vector<TreeNode *>& _body)
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
	ProcedureTreeNode(const std::string& _name, const std::vector<VariableTreeNode *> _args, 
		const std::vector<TreeNode *>& _body)
		:name(_name), args(_args), body(_body){}

};

//======================================================
///stmt node
class StmtTreeNode : public TreeNode {
public:
	virtual ~StmtTreeNode() {}
};

class CompoundStmtTreeNode : public StmtTreeNode {
private:
	ListTreeNode *stmtList;
public:
	CompoundStmtTreeNode(const ListTreeNode *list):stmtList(list){}

};

class IfStmtTreeNode : public StmtTreeNode {
private:
	ExprTreeNode *condition;
	CompoundStmtTreeNode *body;
	StmtTreeNode *elsePart;
public:
	IfStmtTreeNode(const ExprTreeNode *e, const CompoundStmtTreeNode *c)
				:condition(e), body(c){}
	IfStmtTreeNode(const ExprTreeNode *e, const CompoundStmtTreeNode *c,
		const StmtTreeNode *s)
				:condition(e), body(c),elsePart(s){}				

};

class RepeatStmtTreeNode : public StmtTreeNode {
private:
	CompoundStmtTreeNode *body;
	ExprTreeNode *condition;
public:
	RepeatStmtTreeNode(const CompoundStmtTreeNode *_body, ExprTreeNode *_cond) 
					: body(_body), condition(_cond)
					{}
};

class WhileStmtTreeNode : public StmtTreeNode {
private:
	StmtTreeNode *body;
	ExprTreeNode *condition;
public:
	WhileStmtTreeNode(const StmtTreeNode* _body, const ExprTreeNode *_cond)
					: body(_body),cond(_cond){}

};

class CaseStmtTreeNode : public StmtTreeNode {
private:
	TreeNode *expr;
	ListTreeNode *caseExprList;
public:
	CaseStmtTreeNode(const TreeNode *_expr, const ListTreeNode *_list)
				:expr(_expr), caseExprList(_list){}
};

class ForStmtTreeNode : public StmtTreeNode {
private:
	ExprTreeNode *assignExpr;
	std::string direction;
	TreeNode *dirExpr; // may be a variable
	StmtTreeNode *body;
public:
	ForStmtTreeNode(const ExprTreeNode * _aExpr, const std::string& _dire, 
		const TreeNode *_dExpr, const StmtTreeNode* _body)
		: assignExpr(_aExpr), direction(_dire), dirExpr(_dExpr), body(_body){}
};


class GotoStmtTreeNode : public StmtTreeNode {
private:
	int lable;
public:
	GotoStmtTreeNode(int _lable):label(_lable){}
};
/*
* if treceScan = TRUE, every token along with lineno will be 
* print in listing file
*/
int traceScan;
#endif