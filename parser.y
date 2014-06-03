%{
#include "public.h"
#include <cstdio>
#include <cctype>
#include <string>
#include "scanner.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
#define YYSTYPE TreeNode *
#ifndef YYPARSER
#include "parser.hpp"
#endif
#define currentToken yytext

int yyerror(string);
static void tp(const string);
static int yylex();
string s,s1,s2,name;
int x;
TreeNode *id;
extern char* yytext;
extern FILE *yyin, *yyout;
extern int traceScan;
extern string idstr;
ProgramTreeNode *root;
int traceParse = TRUE;
ofstream parserOut("parserOut");
%}

%token AND  ARRAY  ASSIGN  BEGINP  CASE CHAR COLON COMMA CONST DIV DO SYS_CON PROCEDURE
%token DOT DOTDOT DOWNTO OR ELSE END EQUAL FOR FUNCTION GE GOTO GT ID
%token IF INTEGER LB LE LP LT MINUS MOD MUL NOT OF PLUS PROGRAM RB SYS_TYPE
%token READ REAL RECORD REPEAT RP SEMI STRING THEN TO TYPE UNEQUAL UNTIL VAR WHILE SYS_FUNCT SYS_PROC MINUST

%%
program : program_head  routine  DOT {
tp("pargram");
root = new ProgramTreeNode(((ProgramHeadTreeNode*)$1)->getName(), (RoutineTreeNode *)$2);
$$ = root;
;
}
;
program_head : PROGRAM  ID { name = currentToken; } SEMI {
  tp("program head");
  $$ = new ProgramHeadTreeNode(currentToken);
}
;
routine : routine_head  routine_body {
  tp("routine");
  $$ = new RoutineTreeNode($1, $2);
}
;
name_list : name_list  COMMA  ID  {
  tp("name list 1");
  $$ = $1;
  $$->insert(new TreeNode(currentToken));
}
|  ID {
   tp("name list 2");
   vector<TreeNode *> list;
   list.push_back(new TreeNode(currentToken));
   $$ = new ListTreeNode("name_list", list);
}
;
routine_head : label_part  const_part  type_part  var_part  routine_part {
   tp("routine head");
   $$ = new RoutineHeadTreeNode($2, $3, $4, $5);
}
;
label_part : {}
;
const_part : CONST  const_expr_list {
  tp("const part1");
  $$ = $2;
} |  {tp("const part 2"); $$ = new ListTreeNode("non const part");}
;
const_expr_list : const_expr_list  ID { name = currentToken; }
EQUAL  const_value  SEMI {
  tp("const expr list 1");
  $$ = $1;
  $$->insert(new ConstTreeNode(name, $5));
}
|  ID  {name = currentToken;}
EQUAL  const_value  SEMI {
  tp("const expr list 2");
  vector<TreeNode *> list;
  $$ = new ListTreeNode("const_value_list",list);
  $$->insert(new ConstTreeNode(name, $4));
}
;
const_value : INTEGER     {tp("const value 1");$$ = new NumberTreeNode<int>(atoi(currentToken), "INTEGER");}
              |  REAL     {tp("const value 2");$$ = new NumberTreeNode<double>(atof(currentToken), "REAL");}
              |  CHAR     {tp("const value 3");$$ = new NumberTreeNode<char>(currentToken[0], "CHAR");}
              |  STRING   {tp("const value 4");$$ = new NumberTreeNode<string>(currentToken, "STRING");}  
              |  SYS_CON  {tp("const value 5");$$ = new NumberTreeNode<string>(currentToken, "SYS_CON");}  
              ;
type_part : TYPE type_decl_list {
  tp("type part 1");
  $$ = $2;
} |  {tp("type part 2"); $$ = new ListTreeNode("non type part");}
;
type_decl_list : type_decl_list  type_definition 
{
  tp("type_decl_list 1");
  $$ = $1;
  $$->insert($2);
} 
|  type_definition {
  tp("type_decl_list 2");
  vector<TreeNode *> list;
  list.push_back($1);
  $$ = new ListTreeNode("type_decl_list",list);
}
;
type_definition : ID  {name = currentToken;}EQUAL  type_decl  SEMI {
  tp("type_definition");
  $$ = new CustomTypeTreeNode(name, $4);
}
;
type_decl : simple_type_decl  {tp("type_decl 1");$$ = $1;} 
          |  array_type_decl  {tp("type_decl 2");$$ = $1;} 
          |  record_type_decl {tp("type_decl 3");$$ = $1;} 
;
array_type_decl : ARRAY  LB  simple_type_decl  RB  OF  type_decl {
  tp("array_type_decl");
  $$ = new ArrayTypeTreeNode($3,$6);
}
;
record_type_decl : RECORD  field_decl_list  END {
  tp("record_type_decl");
  $$ = new RecordTypeTreeNode($2);
}
;
field_decl_list : field_decl_list  field_decl  {
  tp("field_decl_list 1");
  $$ = $1;
  $$->insert($2);
}
|  field_decl {
  tp("field_decl_list 2");
  vector<TreeNode *> list;
  list.push_back($1);
  $$ = new ListTreeNode("field_decl_list",list);
}
;
field_decl : name_list  COLON  type_decl  SEMI {
  tp("field_decl");
  $$ = new VariableTreeNode($1, $3);
}
;
simple_type_decl : SYS_TYPE {                
                  tp("simple_type_decl 1");
                  $$ = new SysTypeTreeNode(currentToken);
                } 
                |  ID {
                  tp("simple_type_decl 2");                
                  $$ = new CustomTypeTreeNode(currentToken);
                }
                |  LP  name_list  RP {
                  tp("simple_type_decl 3");                
                  $$ = new EnumTypeTreeNode($2);
                }
                |  const_value  DOTDOT  const_value  {
                  tp("simple_type_decl 4");                
                  $$ = new SubRangeTypeTreeNode($1,$3);
                }
                |  MINUS  const_value  DOTDOT  const_value {
                  tp("simple_type_decl 5");                
                  NumberTreeNode<int>* n = (NumberTreeNode<int>*)$1;
                  n->set(-(int)(n->get()));
                  $$ = new SubRangeTypeTreeNode($1,$3);
                }
                |  MINUS  const_value  DOTDOT  MINUS  const_value {
                  tp("simple_type_decl 6");                
                  NumberTreeNode<int>* n1 = (NumberTreeNode<int>*)$1;
                  NumberTreeNode<int>* n2 = (NumberTreeNode<int>*)$2;
                  n1->set(-(int)(n1->get()));
                  n2->set(-(int)(n2->get()));
                  $$ = new SubRangeTypeTreeNode($1,$3); 
                }
                |  ID {s1 = currentToken;} DOTDOT  ID {
                  tp("simple_type_decl 7");                
                  s2 = currentToken;
                  $$ = new RecordElemTreeNode(s1, s2);
                }
;
var_part : VAR  var_decl_list {
  tp("var part 1");
  $$ = $2;
} |  {tp("var part 2");$$ = new ListTreeNode("non var part");}
;
var_decl_list : var_decl_list  var_decl {
  tp("var_decl_list 1");
  $$ = $1;
  $$->insert($2);
} |  var_decl {
  tp("var_decl_list 2");
  vector<TreeNode *> list;
  list.push_back($1);
  $$ = new ListTreeNode("var_decl_list",list);
}
;
var_decl : name_list  COLON  type_decl  SEMI {
  tp("var_decl");
  $$ = new VariableTreeNode($1, $3, 1);
}
;
routine_part : routine_part  function_decl  {
                tp("routine part 1");
                $$ = $1;
                $$->insert($2);
              }
            |  routine_part  procedure_decl {
              tp("routine part 2");
              $$ = $1;
              $$->insert($2);
              }
            |  function_decl  {
                tp("routine part 3");
                vector<TreeNode *> list;
                list.push_back($1);
                $$ = new ListTreeNode("function_decl_list",list);
              }
            |  procedure_decl {
                tp("routine part 4");            
                vector<TreeNode *> list;
                list.push_back($1);
                $$ = new ListTreeNode("procedure_decl_list",list);
            }
            | {tp("routine part 5");$$ = new ListTreeNode("non routine part");}
;
function_decl : FUNCTION  ID {name = currentToken;} parameters  COLON  simple_type_decl SEMI routine SEMI {
  tp("function decl");  
  $$ = new FunctionTreeNode(name, $4, $6, $8);
}
;
procedure_decl : PROCEDURE ID {name = currentToken;} parameters  SEMI  routine  SEMI {
  tp("procedure decl");
  $$ = new ProcedureTreeNode(name, $4, $6); 
}
;
parameters : LP  para_decl_list  RP  {
  tp("paramters 1");
  $$ = $2; 
}
| {tp("paramters 2");$$ = NULL;}
; 
para_decl_list : para_decl_list  SEMI  para_type_list {
  tp("para_decl_list 1");
  $$ = $1;
  $$->insert($3);
}
| para_type_list {
  tp("para_decl_list 2");
  vector<TreeNode *> list;
  list.push_back($1);
  $$ = new ListTreeNode("para_type_list",list);
}
;
para_type_list : var_para_list COLON  simple_type_decl  {
  tp("para_type_list 1");
  $$ = new VariableTreeNode($1, $3,1);
}
|  val_para_list  COLON  simple_type_decl {
  tp("para_type_list 2");
  $$ = new VariableTreeNode($1, $3, 0); 
}
| val_para_list {
  tp("para_type_list 3");
  $$ = new VariableTreeNode($1);  
}
;
var_para_list : VAR  name_list {
  tp("var_para_list");
  $$ = $2;
}
val_para_list : name_list {
  tp("val_para_list");
  $$ = $1;
}
routine_body : compound_stmt {
  tp("routine_body");
  $$ = $1;
}



stmt_list : stmt_list  stmt  SEMI  {
    tp("stmt list 1");
    $$ = $1;
  	$$->insert($2);
}
    | {tp("stmt list 2");$$ = new ListTreeNode("stmt");}
;  
stmt : INTEGER  {x = atoi(currentToken);} COLON  
       non_label_stmt   {tp("stmt 1");$$ = $3;((StmtTreeNode*)$$)->setLabel(x);}
  |  non_label_stmt         {tp("stmt 2");$$ = $1;}
;
non_label_stmt :  assign_stmt       {tp("non_label_stmt 1");$$ = $1;}
               | proc_stmt          {tp("non_label_stmt 2");$$ = $1;}
               | compound_stmt      {tp("non_label_stmt 3");$$ = $1;}
               | if_stmt            {tp("non_label_stmt 4");$$ = $1;}
               | repeat_stmt        {tp("non_label_stmt 5");$$ = $1;}
               | while_stmt         {tp("non_label_stmt 6");$$ = $1;}
               | for_stmt           {tp("non_label_stmt 7");$$ = $1;}
               | case_stmt          {tp("non_label_stmt 8");$$ = $1;}
               | goto_stmt          {tp("non_label_stmt 9");$$ = $1;}
               ;
assign_stmt : ID 	{s = idstr;} ASSIGN  expression  {
                tp("assign stmt 1");
                cout << "name = " << idstr;
                VariableTreeNode* x = new VariableTreeNode(s);
                $$ = new BinaryExprTreeNode("=",x,$4);
            }
            | ID	{s = idstr;} LB expression RB ASSIGN expression {
                tp("assign stmt 2");
                TreeNode* x = new ArrayElemTreeNode(s,$4);
                $$ = new BinaryExprTreeNode("=",x,$7);
            }
            | ID  {s1 = idstr;} DOT  ID  {s2 = idstr;} ASSIGN  expression	{
                tp("assign stmt 3");
                TreeNode* x = new RecordElemTreeNode(s1,s2);
                $$ = new BinaryExprTreeNode("=",x,$7);
            }
            ;
proc_stmt :  ID                   {tp("proc_stmt 1");$$ = new CallExprTreeNode(currentToken);}
          |  ID                   {s = currentToken;}
          LP  args_list  RP       {//cout << $1 << "," << $2 << ","<< $3 << "," << $4 << $5;
          tp("proc_stmt 2");$$ = new CallExprTreeNode(s,((ListTreeNode*)$4)->getList());}
          |  SYS_PROC             {tp("proc_stmt 3");$$ = new CallExprTreeNode(currentToken);}
          |  SYS_PROC             {s = currentToken;}
          LP  args_list  RP       {tp("proc_stmt 4");$$ = new CallExprTreeNode(s,((ListTreeNode*)$4)->getList());}
          |  READ                 {s = currentToken;}
          LP  factor  RP          {tp("proc_stmt 5");$$ = new CallExprTreeNode(s,((ListTreeNode*)$4)->getList());}
          ;

compound_stmt : BEGINP  stmt_list  END {
    tp("compound stmt");
    $$ = new CompoundStmtTreeNode($2);
}
;
if_stmt : IF  expression  THEN  stmt  else_clause {
    tp("if stmt");
    $$ = new IfStmtTreeNode($2,$4,$5);
}
;
else_clause : ELSE stmt     {tp("else clause 1");$$ = $2;}
            |               {tp("else clause 2");$$ = NULL;}
            ;
repeat_stmt : REPEAT  stmt_list  UNTIL  expression {
    tp("repeat stmt");
    $$ = new RepeatStmtTreeNode($2,$4);
}
;
while_stmt : WHILE  expression  DO stmt {
    tp("while stmt");
    $$ = new WhileStmtTreeNode($4,$2);
}
;
for_stmt : FOR  ID {name = currentToken;} ASSIGN  expression  direction  expression  DO stmt {
    tp("for stmt");
    VariableTreeNode * v = new VariableTreeNode(name);
    BinaryExprTreeNode *be = new BinaryExprTreeNode(":=",v,$5);
    $$ = new ForStmtTreeNode(be,$6->getName(),$7,$9);
}
;
direction : TO         {$$ = new TreeNode("to");}
          | DOWNTO     {$$ = new TreeNode("downto");}
;
case_stmt : CASE expression OF case_expr_list  END {
    tp("case stmt");
    $$ = new SwitchStmtTreeNode($2,$4);
}
;
case_expr_list : case_expr_list  case_expr          {tp("case expr list 1");$$ = $1; $$->insert($2);}
               |  case_expr                         {tp("case expr list 2");$$ = new ListTreeNode("case"); $$->insert($1);}
;
case_expr : const_value  COLON  stmt  SEMI          {tp("case expr 1");$$ = new CaseExprTreeNode($1,$3);}
          |  ID                                     {id = new VariableTreeNode(currentToken);}
          COLON  stmt  SEMI                         {tp("case expr 2");$$ = new CaseExprTreeNode(id,$4);}
;
goto_stmt : GOTO  INTEGER {
    tp("got stmt");
    $$ = new GotoStmtTreeNode(currentToken);
}
;
expression :  expression  GE  expr      {tp("expression 1");$$ = new BinaryExprTreeNode(">=",$1,$3);}
           |  expression  GT  expr      {tp("expressoin 2");$$ = new BinaryExprTreeNode(">",$1,$3);}
           |  expression  LE  expr      {tp("expression 3");$$ = new BinaryExprTreeNode("<=",$1,$3);}
           |  expression  LT  expr      {tp("expression 4");$$ = new BinaryExprTreeNode("<",$1,$3);}
           |  expression  EQUAL  expr   {tp("expression 5");$$ = new BinaryExprTreeNode("==",$1,$3);}
           |  expression  UNEQUAL  expr {tp("expression 6");$$ = new BinaryExprTreeNode("!=",$1,$3);}
           |  expr                      {tp("expression 7");$$ = $1;}
;
expr :  expr  PLUS  term        {tp("expr 1");$$ = new BinaryExprTreeNode("+",$1,$3);}
     |  expr  MINUS  term       {tp("expr 2");$$ = new BinaryExprTreeNode("-",$1,$3);}
     |  expr  OR  term          {tp("expr 3");$$ = new BinaryExprTreeNode("||",$1,$3);}
     |  term                    {tp("expr 4");$$ = $1;}
;
term :  term  MUL  factor           {tp("term 1");$$ = new BinaryExprTreeNode("*",$1,$3);}
     |  term  DIV  factor           {tp("term 2");$$ = new BinaryExprTreeNode("/",$1,$3);}
     |  term  MOD  factor           {tp("term 3");$$ = new BinaryExprTreeNode("%",$1,$3);}
     |  term  AND factor            {tp("term 4");$$ = new BinaryExprTreeNode("&&",$1,$3);}
     |  factor                      {tp("term 5");$$ = $1;}
;
factor : ID                         {tp("factor 1");$$ = new VariableTreeNode(currentToken);}
       |  ID                        {s = currentToken;}
       LP  args_list  RP            {tp("factor 2");$$ = new CallExprTreeNode(s,((ListTreeNode*)$4)->getList());}
       |  SYS_FUNCT                 {tp("factor 3");$$ = new CallExprTreeNode(currentToken);}
       |  SYS_FUNCT                 {s = currentToken;}
       LP  args_list  RP            {tp("factor 4");$$ = new CallExprTreeNode(s,((ListTreeNode*)$4)->getList());}
       |  const_value               {tp("factor 5");$$ = $1;}
       |  LP  expression  RP        {tp("factor 6");$$ = $2;}
       |  NOT  factor               {tp("factor 7");$$ = new UnaryExprTreeNode("~",$2);}
       |  MINUS  factor             {tp("factor 8");$$ = new UnaryExprTreeNode("-",$2);}
       |  ID                        {s = currentToken;}
       LB  expression  RB           {tp("factor 9");$$ = new ArrayElemTreeNode(s,$4);}
       |  ID                        {s1 = currentToken;}
       DOT  ID                      {tp("factor 10");s2 = currentToken; $$ = new RecordElemTreeNode(s1,s2);}
;
args_list : args_list  COMMA  expression  {
    tp("args_list 1");
    $$ = $1;
    $$->insert($3);
}
|  expression                   {tp("args_list 2"); $$ = new ListTreeNode("args_list");  $$->insert($1);}
;


%%
static int yylex() {
  return getToken();
}

static void tp(const string msg) {
  if(traceParse) {parserOut << lineno << " " << msg  << endl;}
}
//main() 
//{
//  traceScan = TRUE;
//  yyparse();
//  printAST(root);
//  return 0;
//}



int yyerror(string s) {
	fprintf(stderr, "%s\n", s.c_str());
	return 0;
}

