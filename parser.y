%{
#include "public.h"
#include <stdio.h>
#include <ctype.h>
#include <string>
#include "scanner.h"
using namespace std;
#define YYSTYPE TreeNode *
%}

%token AND  ARRAY  ASSIGN  BEGINP  CASE CHAR COLON COMMA CONST DIV DO SYS_CON PROCEDURE
%token DOT DOTDOT DOWNTO OR ELSE END EQUAL FOR FUNCTION GE GOTO GT ID
%token IF INTEGER LB LE LP LT MINUS MOD MUL NOT OF PLUS PROGRAM RB SYS_TYPE
%token READ REAL RECORD REPEAT RP SEMI STRING THEN TO TYPE UNEQUAL UNTIL VAR WHILE SYS_FUNCT SYS_PROC

%%
program : program_head  routine  DOT
program_head : PROGRAM  ID  SEMI
routine : routine_head  routine_body
name_list : name_list  COMMA  ID  |  ID
routine_head : label_part  const_part  type_part  var_part  routine_part
label_part : 
const_part : CONST  const_expr_list  |  
const_expr_list : const_expr_list  ID  EQUAL  const_value  SEMI
|  ID  EQUAL  const_value  SEMI
const_value : INTEGER  |  REAL  |  CHAR  |  STRING  |  SYS_CON
type_part : TYPE type_decl_list  |  
type_decl_list : type_decl_list  type_definition  |  type_definition
type_definition : ID  EQUAL  type_decl  SEMI
type_decl : simple_type_decl  |  array_type_decl  |  record_type_decl
array_type_decl : ARRAY  LB  simple_type_decl  RB  COLON  type_decl
record_type_decl : RECORD  field_decl_list  END
field_decl_list : field_decl_list  field_decl  |  field_decl
field_decl : name_list  COLON  type_decl  SEMI
simple_type_decl : SYS_TYPE  |  ID  |  LP  name_list  RP  
                |  const_value  DOTDOT  const_value  
                |  MINUS  const_value  DOTDOT  const_value
                |  MINUS  const_value  DOTDOT  MINUS  const_value
                |  ID  DOTDOT  ID
var_part : VAR  var_decl_list  |  
var_decl_list : var_decl_list  var_decl  |  var_decl
var_decl : name_list  COLON  type_decl  SEMI
routine_part : routine_part  function_decl  |  routine_part  procedure_decl
           |  function_decl  |  procedure_decl | 
function_decl : FUNCTION  ID  parameters  COLON  simple_type_decl SEMI routine SEMI
procedure_decl : PROCEDURE ID parameters  SEMI  routine  SEMI 
parameters : LP  para_decl_list  RP  |  
para_decl_list : para_decl_list  SEMI  para_type_list
para_type_list : var_para_list COLON  simple_type_decl  
|  val_para_list  COLON  simple_type_decl
var_para_list : VAR  name_list
val_para_list : name_list
routine_body : compound_stmt
stmt_list : stmt_list  stmt  SEMI  |  
stmt : INTEGER  COLON  non_label_stmt  |  non_label_stmt
non_label_stmt : assign_stmt | proc_stmt | compound_stmt | if_stmt | repeat_stmt | while_stmt | for_stmt | case_stmt | goto_stmt

assign_stmt : ID  ASSIGN  expression
           | ID LB expression RB ASSIGN expression
           | ID  DOT  ID  ASSIGN  expression
proc_stmt : ID
          |  ID  LP  args_list  RP
          |  SYS_PROC
          |  SYS_PROC  LP  args_list  RP
          |  READ  LP  factor  RP
compound_stmt : BEGINP  stmt_list  END
if_stmt : IF  expression  THEN  stmt  else_clause
else_clause : ELSE stmt |  
repeat_stmt : REPEAT  stmt_list  UNTIL  expression
while_stmt : WHILE  expression  DO stmt
for_stmt : FOR  ID  ASSIGN  expression  direction  expression  DO stmt
direction : TO | DOWNTO
case_stmt : CASE expression OF case_expr_list  END
case_expr_list : case_expr_list  case_expr  |  case_expr
case_expr : const_value  COLON  stmt  SEMI
          |  ID  COLON  stmt  SEMI
goto_stmt : GOTO  INTEGER
expression_list : expression_list  COMMA  expression  |  expression
expression : expression  GE  expr  |  expression  GT  expr  |  expression  LE  expr
          |  expression  LT  expr  |  expression  EQUAL  expr  
|  expression  UNEQUAL  expr  |  expr
expr : expr  PLUS  term  |  expr  MINUS  term  |  expr  OR  term  |  term
term : term  MUL  factor  |  term  DIV  factor 
|  term  MOD  factor  |  term  AND factor  |  factor
factor : ID  |  I%{
#include "public.h"
#include <stdio.h>
#include <ctype.h>
#include <string>
#include "scanner.h"
using namespace std;
#define YYSTYPE TreeNode *
%}

%token AND  ARRAY  ASSIGN  BEGINP  CASE CHAR COLON COMMA CONST DIV DO SYS_CON PROCEDURE
%token DOT DOTDOT DOWNTO OR ELSE END EQUAL FOR FUNCTION GE GOTO GT ID
%token IF INTEGER LB LE LP LT MINUS MOD MUL NOT OF PLUS PROGRAM RB SYS_TYPE
%token READ REAL RECORD REPEAT RP SEMI STRING THEN TO TYPE UNEQUAL UNTIL VAR WHILE SYS_FUNCT SYS_PROC

%%
program : program_head  routine  DOT
program_head : PROGRAM  ID  SEMI
routine : routine_head  routine_body
name_list : name_list  COMMA  ID  |  ID
routine_head : label_part  const_part  type_part  var_part  routine_part
label_part : 
const_part : CONST  const_expr_list  |  
const_expr_list : const_expr_list  ID  EQUAL  const_value  SEMI
|  ID  EQUAL  const_value  SEMI
const_value : INTEGER  |  REAL  |  CHAR  |  STRING  |  SYS_CON
type_part : TYPE type_decl_list  |  
type_decl_list : type_decl_list  type_definition  |  type_definition
type_definition : ID  EQUAL  type_decl  SEMI
type_decl : simple_type_decl  |  array_type_decl  |  record_type_decl
array_type_decl : ARRAY  LB  simple_type_decl  RB  COLON  type_decl
record_type_decl : RECORD  field_decl_list  END
field_decl_list : field_decl_list  field_decl  |  field_decl
field_decl : name_list  COLON  type_decl  SEMI
simple_type_decl : SYS_TYPE  |  ID  |  LP  name_list  RP  
                |  const_value  DOTDOT  const_value  
                |  MINUS  const_value  DOTDOT  const_value
                |  MINUS  const_value  DOTDOT  MINUS  const_value
                |  ID  DOTDOT  ID
var_part : VAR  var_decl_list  |  
var_decl_list : var_decl_list  var_decl  |  var_decl
var_decl : name_list  COLON  type_decl  SEMI
routine_part : routine_part  function_decl  |  routine_part  procedure_decl
           |  function_decl  |  procedure_decl | 
function_decl : FUNCTION  ID  parameters  COLON  simple_type_decl SEMI routine SEMI
procedure_decl : PROCEDURE ID parameters  SEMI  routine  SEMI 
parameters : LP  para_decl_list  RP  |  
para_decl_list : para_decl_list  SEMI  para_type_list | para_type_list
para_type_list : var_para_list COLON  simple_type_decl  
|  val_para_list  COLON  simple_type_decl
var_para_list : VAR  name_list
val_para_list : name_list
routine_body : compound_stmt
stmt_list : stmt_list  stmt  SEMI  |  
stmt : INTEGER  COLON  non_label_stmt  |  non_label_stmt
non_label_stmt : assign_stmt {$$=$1;} 
              | proc_stmt {$$=$1;}
              | compound_stmt {$$=$1;}
              | if_stmt {$$=$1;}
              | repeat_stmt {$$=$1;}
              | while_stmt {$$=$1;}
              | for_stmt {$$=$1;}
              | case_stmt {$$=$1;}
              | goto_stmt {$$=$1;}

assign_stmt : ID  ASSIGN  expression 
           | ID LB expression RB ASSIGN expression
           | ID  DOT  ID  ASSIGN  expression
proc_stmt : ID
          |  ID  LP  args_list  RP
          |  SYS_PROC
          |  SYS_PROC  LP  args_list  RP
          |  READ  LP  factor  RP
compound_stmt : BEGINP  stmt_list  END  {$$ = new CompoundStmtTreeNode($2);}
if_stmt : IF  expression  THEN  stmt  else_clause {$$ = new IfStmtTreeNode($2,$4,$5);} 
else_clause : ELSE stmt |  {$$ = new StmtTreeNode($2);}
repeat_stmt : REPEAT  stmt_list  UNTIL  expression {$$ = new RepeatStmtTreeNode($2,$4);}
while_stmt : WHILE  expression  DO stmt {$$ = new WhileStmtTreeNode($4,$2);}
for_stmt : FOR  ID  ASSIGN  expression  direction  expression  DO stmt {$$ = new FotStmtTreeNode($4,$5,$6,$8);}
direction : TO | DOWNTO {$$ = $1;}
case_stmt : CASE expression OF case_expr_list  END {$$ = new SwitchStmtTreeNode($1,$2);}
case_expr_list : case_expr_list  case_expr  
              |  case_expr  {$$ = new  ListTreeNode("case",) } 
case_expr : const_value  COLON  stmt  SEMI  
          |  ID  COLON  stmt  SEMI {$$ = new CaseExprTreeNode($1,$3);}
goto_stmt : GOTO  INTEGER  {$$ = new GotoStmtTreeNode($2);}
expression : expression  GE  expr  |  expression  GT  expr  |  expression  LE  expr
          |  expression  LT  expr  |  expression  EQUAL  expr
          |  expression  UNEQUAL  expr  |  expr
expr : expr  PLUS  term  |  expr  MINUS  term  |  expr  OR  term  |  term
term : term  MUL  factor  |  term  DIV  factor 
|  term  MOD  factor  |  term  AND factor  |  factor
factor : ID  |  ID  LP  args_list  RP  |  SYS_FUNCT 
| SYS_FUNCT  LP  args_list  RP
|  const_value  |  LP  expression  RP
|  NOT  factor  |  MINUS  factor  |  ID  LB  expression  RB
|  ID  DOT  ID
args_list : args_list  COMMA  expression  |  expression

%%

main() 
{
  return yyparse();
}



int yyerror(char *s) {
  fprintf(stderr, "%s\n", s);
  return 0;
}D  LP  args_list  RP  |  SYS_FUNCT 
| SYS_FUNCT  LP  args_list  RP 
|  const_value  |  LP  expression  RP
|  NOT  factor  |  MINUS  factor  |  ID  LB  expression  RB
|  ID  DOT  ID
args_list : args_list  COMMA  expression  |  expression

%%

main() 
{
	return yyparse();
}



int yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
	return 0;
}