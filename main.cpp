#include "public.h"
#include "utils.h"
#include "scanner.h"
#include <iostream>
#include <stdio.h>
#define MAX_OPTION 10
using namespace std;

int lineno = 0;
FILE *source;
FILE *listing;

int traceScan = TRUE;

int main(int argc, char *argv[]) {
	char option[MAX_OPTION];
	int opNumber = 0;
	if (argc == 0) {
		cout << "no input file" << endl;
		return 1;
	}
	for (int i = 0; i < argc; i++) {
		if (argv[i][0] == '-') {
			if (strlne(argv[i]) == 2) 
				option[opNumber++] = argv[i][1];
			else  {
				cout << "error option : " <<　argv[i] <<　endl;
				return 1;
			}
		} else {
			if ((source = fopen(argv[i], "r") == NULL) {
				cout << "error can not open file " << argv[i] << endl;
				return 1;
			}
		}
	}

	listing = fopen("listing", "w+");
	if (listing == NULL) {
		cout << "error can not open file listing" << endl;
		return 1;
	}
	
	
	
	
	
}

















