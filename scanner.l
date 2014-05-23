%{
#include "public.h"
#include "scanner.h"
#include "utils.h"
#include <cstdio>
#include <iostream>

using namespace std;

%}

digit [0-9]
number {digit}+
integer [1-9]{digit}*
real [1-9]{digit}*[.]{digit}+
string \'[^']*\'
letter [a-zA-Z]
char \'[.]\'
id ({letter}|_)+({letter}|_|{digit})+
newline \n
whitespace [ \t]+
name ({letter}|_)+({letter}|_|{digit})+
systype ("integer" | "real" | "string" | "char")
%%
systype {return SYS_TYPE;}
"and" { return AND;}
"array" { return ARRAY;}
":=" { return ASSIGN;}
"begin" { return BEGINP;}
"case" { return CASE;}
{char} { return CHAR;}
":" { return COLON;}
"," { return COMMA;}
"const" { return CONST;}
"/" { return DIV;}
"do" { return DO;}
"." { return DOT;}
".." { return DOTDOT;}
"downto" { return DOWNTO;}
"or" { return OR;}
"else" { return ELSE;}
"end" { return END;}
"=" { return EQUAL;}
"for" { return FOR;}
"function" { return FUNCTION;}
">=" { return GE;}
"goto" { return GOTO;}
">" { return GT;}
"if" { return IF;}
{integer} { return INTEGER;}
"[" { return LB;}
"<=" { return LE;}
"(" { return LP;}
"<" { return LT;}
"-" { return MINUS;}
"mod" { return MOD;}
"*" { return MUL;}
"not" { return NOT;}
"of" { return OF;}
"+" { return PLUS;}
"program" { return PROGRAM;}
"]" { return RB;}
"read" { return READ;}
{real} { return REAL;}
"record" { return RECORD;}
"repeat" { return REPEAT;}
")" { return RP;}
";" { return SEMI;}
{string} { return STRING;}
"then" { return THEN;}
"to" { return TO;}
"type" { return TYPE;}
"!=" { return UNEQUAL;}
"until" { return UNTIL;}
"var" { return VAR;}
"while" { return WHILE;}
{newline} {lineno++;}
{whitespace} {}
{id} { return ID;}

%%



int getToken(void) {
	static int firstIn = TRUE;
	int curToken;
	if (firstIn) {
		firstIn = FALSE;
		source = fopen("test.p","r");
		listing = fopen("listing","w+");
		yyin = source;
		yyout = listing;
		lineno++;
	}
	curToken = yylex();
	//yylval = yytext;
	if (traceScan) {
		fprintf(listing, "\t%d %s\n", lineno, yytext);
	}	
	return curToken;
}

int yywrap()
{
	return 1;
}
main() {
	lineno = 0;
	traceScan = TRUE;
	cout << "begin yylex" << endl;
	while(getToken() != 0);
	cout << "end" << endl;
}












