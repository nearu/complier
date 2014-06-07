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
extern LabelManager *labelManager;
int LabelManager::loop_number = 0;
int LabelManager::func_number = 0;
int LabelManager::case_number = 0;
int LabelManager::if_number = 0;
int LabelManager::do_number = 0;

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
  yyparse();
  printAST(root);
  mainSymtab = new Symtab("mainSymtab");
  regManager = new RegManager();
  labelManager = new LabelManager();


  root->updateSymtab(mainSymtab);
  cout << "======================updateSymtab end=========================" << endl;
  mainSymtab->printSymtab(sym);
  cout << "===========================begin gencode=======================" << endl;
  root->genCode(mainSymtab);
  // CodeGenerator::emitCodeM(4, "load_ref", 12, 30, 17);
  // CodeGenerator::emitCodeR("%",11,9,10);
  // CodeGenerator::emitCodeR("<=",11,9,10);
  // CodeGenerator::emitCodeR("==",11,9,10);
  // CodeGenerator::emitCodeI("%",11,9,10);
  // CodeGenerator::emitCodeI("<=",11,9,10);
  // CodeGenerator::emitCodeI("==",11,9,10);

  return 0;
	
	
	
}

















