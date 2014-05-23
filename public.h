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
	std::vector<TreeNode *> list;
public:
	ListTreeNode(const std::string& _name):typeName(_name) {}
	//a.insert(a.end(), b.begin(), b.end());
	void append() {}
	void insert(TreeNode * newNode) {
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
class CustomTypeTreeNode : TypeTreeNode {
private:
	std::string name;
	TypeTreeNode *type;
public:
	CustomTypeTreeNode(const std::string& _name, const TypeTreeNode* _type) 
						: name(_name),type(_type)
						{}

};
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

//==============================================================
/// id node
/**
* node for differnet kinds of const values
*/
template <class T>
class NumberTreeNode : public TreeNode {
private:
	T value;
public:
	NumberTreeNode(T v):value(v) {}
};

/*
*  node for const variables
*/
class ConstTreeNode : public TreeNode {
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
class VariableTreeNode : public TreeNode {
private:
	std::string name;
	std::string type;
public:
	VariableTreeNode(const std::string& _name, const std::string& _type):name(_name), type(_type) {}
};


//===============================================
/// expr node
/*
* node for binary operaotr such as '+'  '='
*/
class BinaryExprTreeNode : public TreeNode {
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
class CallExprTreeNode : public TreeNode {
private:
	std::string name;
	std::vector<TreeNode *> args;
public:
	CallExprTreeNode(const std::string& _name, const std::vector<TreeNode *> _args )
						:name(_name), args(_args){}

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
class ProcedureTreeNode : public TreeNode {
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
/*
* if treceScan = TRUE, every token along with lineno will be 
* print in listing file
*/
int traceScan;
#endif