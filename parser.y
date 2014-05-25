%{
#include "public.h"
#include <cstdio>
#include <cctype>
#include <string>
#include "scanner.h"
#include <cstdlib>
using namespace std;
#define YYSTYPE TreeNode *
%}

%token AND  ARRAY  ASSIGN  BEGINP  CASE CHAR COLON COMMA CONST DIV DO SYS_CON PROCEDURE
%token DOT DOTDOT DOWNTO OR ELSE END EQUAL FOR FUNCTION GE GOTO GT ID
%token IF INTEGER LB LE LP LT MINUS MOD MUL NOT OF PLUS PROGRAM RB SYS_TYPE
%token READ REAL RECORD REPEAT RP SEMI STRING THEN TO TYPE UNEQUAL UNTIL VAR WHILE SYS_FUNCT SYS_PROC MINUST

%%
program : program_head  routine  DOT {
$$ = new ProgramTreeNode($1, $2);
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
  $$.insert(new VariableTreeNode(currentToken));
}
|  ID {
   vector<TreeNode *> list;
   list.push_back(new VariableTreeNode(currentToken));
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
const_expr_list : const_expr_list  ID {string name = currentToken;}
EQUAL  const_value  SEMI {
  $$ = $1;
  $$.insert(new ConstTreeNode(name,$4));
}
|  ID  {string name = currentToken;}
EQUAL  const_value  SEMI {
  vector<TreeNode *> list;
  $$ = new ListTreeNode(list);
  $$.insert(new ConstTreeNode(name, $3));
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
type_decl_list : type_decl_list  type_definition {
  $$ = $1;
  $$.insert($2);
} 
|  type_definition {
  vector<TreeNode *> list;
  list.push_back($1);
  $$ = new ListTreeNode(list);
}
;
type_definition : ID  {string name = currentToken;}EQUAL  type_decl  SEMI {
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
  $$.insert($2);
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
                  $1.set(-(int)$1.get());
                  $$ = new SubRangeTypeTreeNode($1,$3);
                }
                |  MINUS  const_value  DOTDOT  MINUS  const_value {
                  $1.set(-(int)$1.get());
                  $2.set(-(int)$2.get());
                  $$ = new SubRangeTypeTreeNode($1,$3); 
                }
                |  ID {string recordName = currentToken;} DOTDOT  ID {
                  string elemName = currentToken;
                  $$ = new RecordElemTreeNode(recordName, elemName);
                }
;
var_part : VAR  var_decl_list {
  $$ = $2;
} |  
;
var_decl_list : var_decl_list  var_decl {
  $$ = $1;
  $$.insert($2);
} |  var_decl {
  vector<TreeNode *> list;
  list.push_back($1);
  $$ = new ListTreeNode(list);
}
;
var_decl : name_list  COLON  type_decl  SEMI {
  $$ = new VariableTreeNode($1, $3, 1);
}
;
routine_part : routine_part  function_decl  {
                $$ = $1;
                $$.insert($2);
              }
            |  routine_part  procedure_decl {
              $$ = $1;
              $$.insert($2);
              }
            |  function_decl  {
                vector<TreeNode *> list;
                $$ = new ListTreeNode(list.push_back($1));
              }
            |  procedure_decl {
                vector<TreeNode *> list;
                $$ = new ListTreeNode(list.push_back($1));
            }
            | 
;
function_decl : FUNCTION  ID {string funcName = currentToken;} parameters  COLON  simple_type_decl SEMI routine SEMI {
  $$ = new FunctionTreeNode(funcName, $3, $5, $7);
}
;
procedure_decl : PROCEDURE ID {string procName = currentToken;}parameters  SEMI  routine  SEMI {
 $$ = new ProcedureTreeNode(funcName, $3, $5); 
}
;
parameters : LP  para_decl_list  RP  {
  $$ = $2; 
}
| 
; 
para_decl_list : para_decl_list  SEMI  para_type_list {
  $$ = $1;
  $$.insert($3);
}
| para_type_list {
  vector<TreeNode *> list;
  $$ = new ListTreeNode(list.push_back($1));
}
;
para_type_list : var_para_list COLON  simple_type_decl  {
  $$ = new Variable($1, $3,1);
}
|  val_para_list  COLON  simple_type_decl {
 $$ = new Variable($1, $3, 0); 
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
  if($1 == NULL)
    $$ = new ListTreeNode("stmt");
  else
    $$ = $1;
  $$->list.insert($2);
}
    | {}
    ;  
stmt : INTEGER  COLON  non_label_stmt   {$$ = $3;}
  |  non_label_stmt         {$$ = $1;}
  ;
non_label_stmt : assign_stmt  {$$ = $1;}
        | proc_stmt   {$$ = $1;}
        | compound_stmt {$$ = $1;}
        | if_stmt   {$$ = $1;}
        | repeat_stmt {$$ = $1;}
        | while_stmt  {$$ = $1;}
        | for_stmt    {$$ = $1;}
        | case_stmt   {$$ = $1;}
        | goto_stmt   {$$ = $1;}
        ;

assign_stmt : ID  ASSIGN  expression  
           | ID LB expression RB ASSIGN expression
           | ID  DOT  ID  ASSIGN  expression
           ;
proc_stmt : ID
          |  ID  LP  args_list  RP
          |  SYS_PROC
          |  SYS_PROC  LP  args_list  RP
          |  READ  LP  factor  RP
          ;
compound_stmt : BEGINP  stmt_list  END {
  $$ = new CompoundStmtTreeNode($2);
}
;
if_stmt : IF  expression  THEN  stmt  else_clause {
  $$ = new IfStmtTreeNode($2,$4,$5)
}
;
else_clause : ELSE stmt   {$$ = $2;}
      |         {$$ = NULL;}
      ;
repeat_stmt : REPEAT  stmt_list  UNTIL  expression {
  $$ = new RepeatStmtTreeNode($2,$4);
}
;
while_stmt : WHILE  expression  DO stmt {
  $$ = new WhileStmtTreeNode($2,$4);
}
;
for_stmt : FOR  ID  ASSIGN  expression  direction  expression  DO stmt{
  $$ = new ForStmtTreeNode($4,$5,$6,$8);
}
;
direction : TO    {$$ = $1;}
    | DOWNTO  {$$ = $1;}
    ;
case_stmt : CASE expression OF case_expr_list  END {
  $4 = new ListTreeNode("case");
  $$ = new SwitchStmtTreeNode($2,$4);
}
;
case_expr_list : case_expr_list  case_expr  {$$.list.push_back($2);}
        |  case_expr        {$$.list.push_back($2);}
        ;
case_expr : const_value  COLON  stmt  SEMI  { $$ = new CaseExprTreeNode($1,$3);}
          |  ID  COLON  stmt  SEMI  {$$ = new CaseExprTreeNode($1,$3);}
          ;
goto_stmt : GOTO  INTEGER {
  $$ = new GotoStmtTreeNode($2);
}
;
expression : expression  GE  expr       {$$ = new BinaryExprTreeNodw('GE',$1,$3);}
      |  expression  GT  expr     {$$ = new BinaryExprTreeNodw('GT',$1,$3);}
      |  expression  LE  expr     {$$ = new BinaryExprTreeNodw('LE',$1,$3);}
            |  expression  LT  expr       {$$ = new BinaryExprTreeNodw('LT',$1,$3);}
            |  expression  EQUAL  expr    {$$ = new BinaryExprTreeNodw('EQUAL',$1,$3);}
      |  expression  UNEQUAL  expr    {$$ = new BinaryExprTreeNodw('UNENQUAL',$1,$3);}
      |  expr             {$$ = $1;}
      ;
expr : expr  PLUS  term     {$$ = new BinaryExprTreeNodw('+',$1,$3);}
  |  expr  MINUS  term      {$$ = new BinaryExprTreeNodw('-',$1,$3);}
  |  expr  OR  term       {$$ = new BinaryExprTreeNodw('|',$1,$3);}
  |  term           {$$ = $1;}
  ;
term : term  MUL  factor      {$$ = new BinaryExprTreeNodw('*',$1,$3);}
  |  term  DIV  factor    {$$ = new BinaryExprTreeNodw('/',$1,$3);}
  |  term  MOD  factor      {$$ = new BinaryExprTreeNodw('%',$1,$3);}
  |  term  AND factor     {$$ = new BinaryExprTreeNodw('&',$1,$3);}
  |  factor         {$$ = $1;}
  ;
factor : ID                 {$$ = $1;}
    |  ID  LP  args_list  RP
    |  SYS_FUNCT 
    | SYS_FUNCT  LP  args_list  RP
    |  const_value            {$$ = $1;}
    |  LP  expression  RP         {$$ = $2;}
    |  NOT  factor            {$$ = ~$1;}
    |  MINUS  factor            {$$ = -$1;}
    |  ID  LB  expression  RB
    |  ID  DOT  ID
    ;
args_list : args_list  COMMA  expression  {
  if($$==NULL)
    $$ = new ListTreeNode("expr");
  $$->list.insert($3);
}
    |  expression {$$->list.insert($3);}
    ;


%%

main() 
{
	return yyparse();
}



int yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
	return 0;
}