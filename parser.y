%{
#include "public.h"
#include <cstdio>
#include <cctype>
#include <string>
#include "scanner.h"
#include <cstdlib>
using namespace std;
#define YYSTYPE TreeNode *
#ifndef YYPARSER
#include "parser.hpp"
#endif
string s,s1,s2,name;
int x;
TreeNode *id;
int yyerror(string);
%}

%token AND  ARRAY  ASSIGN  BEGINP  CASE CHAR COLON COMMA CONST DIV DO SYS_CON PROCEDURE
%token DOT DOTDOT DOWNTO OR ELSE END EQUAL FOR FUNCTION GE GOTO GT ID
%token IF INTEGER LB LE LP LT MINUS MOD MUL NOT OF PLUS PROGRAM RB SYS_TYPE
%token READ REAL RECORD REPEAT RP SEMI STRING THEN TO TYPE UNEQUAL UNTIL VAR WHILE SYS_FUNCT SYS_PROC MINUST

%%
program : program_head  routine  DOT {
$$ = new ProgramTreeNode(((ProgramHeadTreeNode*)$1)->getName(), (RoutineTreeNode *)$2);
}
;
program_head : PROGRAM  ID {
  $$ = new ProgramHeadTreeNode(currentToken);
} SEMI 
;
routine : routine_head  routine_body {
  $$ = new RoutineTreeNode($1, $2);
}
;
name_list : name_list  COMMA  ID  {
  $$ = $1;
  $$->insert(new TreeNode(currentToken));
}
|  ID {
   vector<TreeNode *> list;
   list.push_back(new TreeNode(currentToken));
   $$ = new ListTreeNode("name_list", list);
}
;
routine_head : label_part  const_part  type_part  var_part  routine_part {
   $$ = new RoutineHeadTreeNode($2, $3, $4, $5);
}
;
label_part : {}
;
const_part : CONST  const_expr_list {
  $$ = $2;
} |  
;
const_expr_list : const_expr_list  ID {name = currentToken;}
EQUAL  const_value  SEMI {
  $$ = $1;
  $$->insert(new ConstTreeNode(name, $4));
}
|  ID  {name = currentToken;}
EQUAL  const_value  SEMI {
  vector<TreeNode *> list;
  $$ = new ListTreeNode("const_value_list",list);
  $$->insert(new ConstTreeNode(name, $3));
}
;
const_value : INTEGER     {$$ = new NumberTreeNode<int>(atoi(currentToken.c_str()));}
              |  REAL     {$$ = new NumberTreeNode<double>(atof(currentToken.c_str()));}
              |  CHAR     {$$ = new NumberTreeNode<char>(currentToken[0]);}
              |  STRING   {$$ = new NumberTreeNode<string>(currentToken);}  
              |  SYS_CON  {$$ = new NumberTreeNode<string>(currentToken);}  
              ;
type_part : TYPE type_decl_list {
  $$ = $2;
} |  
;
type_decl_list : type_decl_list  type_definition 
{
  $$ = $1;
  $$->insert($2);
} 
|  type_definition {
  vector<TreeNode *> list;
  list.push_back($1);
  $$ = new ListTreeNode("type_decl_list",list);
}
;
type_definition : ID  {name = currentToken;}EQUAL  type_decl  SEMI {
  $$ = new CustomTypeTreeNode(name, $3);
}
;
type_decl : simple_type_decl  {$$ = $1;} 
          |  array_type_decl  {$$ = $1;} 
          |  record_type_decl {$$ = $1;} 
;
array_type_decl : ARRAY  LB  simple_type_decl  RB  COLON  type_decl {
  $$ = new ArrayTypeTreeNode($3,$6);
}
;
record_type_decl : RECORD  field_decl_list  END {
  $$ = new RecordTypeTreeNode($2);
}
;
field_decl_list : field_decl_list  field_decl  {
  $$ = $1;
  $$->insert($2);
}
|  field_decl {
  vector<TreeNode *> list;
  list.push_back($1);
  $$ = new ListTreeNode("field_decl_list",list);
}
;
field_decl : name_list  COLON  type_decl  SEMI {
  $$ = new VariableTreeNode($1, $3);
}
;
simple_type_decl : SYS_TYPE {
                  $$ = new SysTypeTreeNode(currentToken);
                } 
                |  ID {
                  $$ = new CustomTypeTreeNode(currentToken);
                }
                |  LP  name_list  RP {
                  $$ = new EnumTypeTreeNode($2);
                }
                |  const_value  DOTDOT  const_value  {
                  $$ = new SubRangeTypeTreeNode($1,$3);
                }
                |  MINUS  const_value  DOTDOT  const_value {
                  NumberTreeNode<int>* n = (NumberTreeNode<int>*)$1;
                  n->set(-(int)(n->get()));
                  $$ = new SubRangeTypeTreeNode($1,$3);
                }
                |  MINUS  const_value  DOTDOT  MINUS  const_value {
                  NumberTreeNode<int>* n1 = (NumberTreeNode<int>*)$1;
                  NumberTreeNode<int>* n2 = (NumberTreeNode<int>*)$2;
                  n1->set(-(int)(n1->get()));
                  n2->set(-(int)(n2->get()));
                  $$ = new SubRangeTypeTreeNode($1,$3); 
                }
                |  ID {s1 = currentToken;} DOTDOT  ID {
                  s2 = currentToken;
                  $$ = new RecordElemTreeNode(s1, s2);
                }
;
var_part : VAR  var_decl_list {
  $$ = $2;
} |  
;
var_decl_list : var_decl_list  var_decl {
  $$ = $1;
  $$->insert($2);
} |  var_decl {
  vector<TreeNode *> list;
  list.push_back($1);
  $$ = new ListTreeNode("var_decl_list",list);
}
;
var_decl : name_list  COLON  type_decl  SEMI {
  $$ = new VariableTreeNode($1, $3, 1);
}
;
routine_part : routine_part  function_decl  {
                $$ = $1;
                $$->insert($2);
              }
            |  routine_part  procedure_decl {
              $$ = $1;
              $$->insert($2);
              }
            |  function_decl  {
                vector<TreeNode *> list;
                list.push_back($1);
                $$ = new ListTreeNode("function_decl_list",list);
              }
            |  procedure_decl {
                vector<TreeNode *> list;
                list.push_back($1);
                $$ = new ListTreeNode("procedure_decl_list",list);
            }
            | 
;
function_decl : FUNCTION  ID {name = currentToken;} parameters  COLON  simple_type_decl SEMI routine SEMI {
  $$ = new FunctionTreeNode(name, $3, $5, $7);
}
;
procedure_decl : PROCEDURE ID {name = currentToken;}parameters  SEMI  routine  SEMI {
 $$ = new ProcedureTreeNode(name, $3, $5); 
}
;
parameters : LP  para_decl_list  RP  {
  $$ = $2; 
}
| 
; 
para_decl_list : para_decl_list  SEMI  para_type_list {
  $$ = $1;
  $$->insert($3);
}
| para_type_list {
  vector<TreeNode *> list;
  list.push_back($1);
  $$ = new ListTreeNode("para_type_list",list);
}
;
para_type_list : var_para_list COLON  simple_type_decl  {
  $$ = new VariableTreeNode($1, $3,1);
}
|  val_para_list  COLON  simple_type_decl {
 $$ = new VariableTreeNode($1, $3, 0); 
}
var_para_list : VAR  name_list {
  $$ = $2;
}
val_para_list : name_list {
  $$ = $1;
}
routine_body : compound_stmt {
  $$ = $1;
}



stmt_list : stmt_list  stmt  SEMI  {
    $$ = $1;
  	$$->insert($2);
}
    | {$$ = new ListTreeNode("stmt");}
;  
stmt : INTEGER  {x = atoi(currentToken.c_str());} COLON  non_label_stmt   {$$ = $3;((StmtTreeNode*)$$)->setLabel(x);}
  |  non_label_stmt         {$$ = $1;}
;
non_label_stmt :  assign_stmt       {$$ = $1;}
               | proc_stmt          {$$ = $1;}
               | compound_stmt      {$$ = $1;}
               | if_stmt            {$$ = $1;}
               | repeat_stmt        {$$ = $1;}
               | while_stmt         {$$ = $1;}
               | for_stmt           {$$ = $1;}
               | case_stmt          {$$ = $1;}
               | goto_stmt          {$$ = $1;}
               ;
assign_stmt : ID 	{name = currentToken;} ASSIGN  expression  {
                VariableTreeNode* x = new VariableTreeNode(name);
                $$ = new BinaryExprTreeNode("=",x,$3);
            }
            | ID	{s = currentToken;} LB expression RB ASSIGN expression {
                TreeNode* x = new ArrayElemTreeNode(s,$3);
                $$ = new BinaryExprTreeNode("=",x,$6);
            }
            | ID  {s1 = currentToken;} DOT  ID  {s2 = currentToken;} ASSIGN  expression	{
                TreeNode* x = new RecordElemTreeNode(s1,s2);
                $$ = new BinaryExprTreeNode("=",x,$5);
            }
            ;
proc_stmt :  ID                   {$$ = new CallExprTreeNode(currentToken);}
          |  ID                   {s = currentToken;}
          LP  args_list  RP       {$$ = new CallExprTreeNode(s,((ListTreeNode*)$3)->getList());}
          |  SYS_PROC             {$$ = new CallExprTreeNode(currentToken);}
          |  SYS_PROC             {s = currentToken;}
          LP  args_list  RP       {$$ = new CallExprTreeNode(s,((ListTreeNode*)$3)->getList());}
          |  READ                 {s = currentToken;}
          LP  factor  RP          {$$ = new CallExprTreeNode(s,((ListTreeNode*)$3)->getList());}
          ;

compound_stmt : BEGINP  stmt_list  END {
    $$ = new CompoundStmtTreeNode($2);
}
;
if_stmt : IF  expression  THEN  stmt  else_clause {
    $$ = new IfStmtTreeNode($2,$4,$5);
}
;
else_clause : ELSE stmt     {$$ = $2;}
            |               {$$ = NULL;}
            ;
repeat_stmt : REPEAT  stmt_list  UNTIL  expression {
    $$ = new RepeatStmtTreeNode($2,$4);
}
;
while_stmt : WHILE  expression  DO stmt {
    $$ = new WhileStmtTreeNode($4,$2);
}
;
for_stmt : FOR  ID  ASSIGN  expression  direction  expression  DO stmt {
    $$ = new ForStmtTreeNode($4,$5->getName(),$6,$8);
}
;
direction : TO         {$$ = new TreeNode("to");}
          | DOWNTO     {$$ = new TreeNode("downto");}
;
case_stmt : CASE expression OF case_expr_list  END {
    $$ = new SwitchStmtTreeNode($2,$4);
}
;
case_expr_list : case_expr_list  case_expr          {$$ = $1; $$->insert($2);}
               |  case_expr                         {$$ = new ListTreeNode("case"); $$->insert($1);}
;
case_expr : const_value  COLON  stmt  SEMI          {$$ = new CaseExprTreeNode($1,$3);}
          |  ID                                     {id = new VariableTreeNode(currentToken);}
          COLON  stmt  SEMI                         {$$ = new CaseExprTreeNode(id,$3);}
;
goto_stmt : GOTO  INTEGER {
    $$ = new GotoStmtTreeNode(currentToken);
}
;
expression :  expression  GE  expr      {$$ = new BinaryExprTreeNode(">=",$1,$3);}
           |  expression  GT  expr      {$$ = new BinaryExprTreeNode(">",$1,$3);}
           |  expression  LE  expr      {$$ = new BinaryExprTreeNode("<=",$1,$3);}
           |  expression  LT  expr      {$$ = new BinaryExprTreeNode("<",$1,$3);}
           |  expression  EQUAL  expr   {$$ = new BinaryExprTreeNode("==",$1,$3);}
           |  expression  UNEQUAL  expr {$$ = new BinaryExprTreeNode("!=",$1,$3);}
           |  expr                      {$$ = $1;}
;
expr :  expr  PLUS  term        {$$ = new BinaryExprTreeNode("+",$1,$3);}
     |  expr  MINUS  term       {$$ = new BinaryExprTreeNode("-",$1,$3);}
     |  expr  OR  term          {$$ = new BinaryExprTreeNode("||",$1,$3);}
     |  term                    {$$ = $1;}
;
term :  term  MUL  factor           {$$ = new BinaryExprTreeNode("*",$1,$3);}
     |  term  DIV  factor           {$$ = new BinaryExprTreeNode("/",$1,$3);}
     |  term  MOD  factor           {$$ = new BinaryExprTreeNode("%",$1,$3);}
     |  term  AND factor            {$$ = new BinaryExprTreeNode("&&",$1,$3);}
     |  factor                      {$$ = $1;}
;
factor : ID                         {$$ = new CallExprTreeNode(currentToken);}
       |  ID                        {s = currentToken;}
       LP  args_list  RP            {$$ = new CallExprTreeNode(s,((ListTreeNode*)$3)->getList());}
       |  SYS_FUNCT                 {$$ = new CallExprTreeNode(currentToken);}
       |  SYS_FUNCT                 {s = currentToken;}
       LP  args_list  RP            {$$ = new CallExprTreeNode(s,((ListTreeNode*)$3)->getList());}
       |  const_value               {$$ = $1;}
       |  LP  expression  RP        {$$ = $2;}
       |  NOT  factor               {$$ = new UnaryExprTreeNode("~",$2);}
       |  MINUS  factor             {$$ = new UnaryExprTreeNode("-",$2);}
       |  ID                        {s = currentToken;}
       LB  expression  RB           {$$ = new ArrayElemTreeNode(s,$3);}
       |  ID                        {s1 = currentToken;}
       DOT  ID                      {s2 = currentToken; $$ = new RecordElemTreeNode(s1,s2);}
;
args_list : args_list  COMMA  expression  {
    $$ = $1;
    $$->insert($3);
}
          |  expression                   {$$ = new ListTreeNode("expr"); $$->insert($1);}
;


%%

main() 
{
	return yyparse();
}



int yyerror(string s) {
	fprintf(stderr, "%s\n", s.c_str());
	return 0;
}

