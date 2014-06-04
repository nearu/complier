#include "public.h"
#include "utils.h"
#include "scanner.h"
#include "parser.hpp"
#include "symtab.h"
#include "code_generator.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#define MAX_OPTION 10
using namespace std;

extern int traceScan;
extern int traceParse;
extern TreeNode *root;
Symtab *mainSymtab;
extern ofstream sym;
extern RegManager *regManager;
int main(int argc, char *argv[]) {
	// char option[MAX_OPTION];
	// int opNumber = 0;
	// if (argc == 0) {
	// 	cout << "no input file" << endl;
	// 	return 1;
	// }
	// for (int i = 0; i < argc; i++) {
	// 	if (argv[i][0] == '-') {
	// 		if (strlne(argv[i]) == 2) 
	// 			option[opNumber++] = argv[i][1];
	// 		else  {
	// 			cout << "error option : " <<　argv[i] <<　endl;
	// 			return 1;
	// 		}
	// 	} else {
	// 		if ((source = fopen(argv[i], "r") == NULL) {
	// 			cout << "error can not open file " << argv[i] << endl;
	// 			return 1;
	// 		}
	// 	}
	// }

	// listing = fopen("listing", "w+");
	// if (listing == NULL) {
	// 	cout << "error can not open file listing" << endl;
	// 	return 1;
	// }
  traceScan = TRUE;
  // cout << "begin parse" << endl;
  yyparse();
  // cout << "begin print AST" << endl;
  printAST(root);
  mainSymtab = new Symtab("mainSymtab");
  //root->genCode();
  regManager = new RegManager();
  root->updateSymtab(mainSymtab);
  mainSymtab->printSymtab(sym);
  root->genCode(mainSymtab);
  // cout << "begin print symtab" << endl;
  

  
  CodeGenerator::emitCodeR("+",11,9,10);
  CodeGenerator::emitCodeR("%",11,9,10);
  CodeGenerator::emitCodeR("<=",11,9,10);

  return 0;
	
	
	
}

















