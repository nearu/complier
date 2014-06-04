#ifndef __CODE_GENERATOR_H_
#define __CODE_GENERATOR_H_
#include <fstream>
#include <iostream>
#include <cctype>
#include <cstdio>
using namespace std;
extern ofstream code;
const string regTable[] = {
	"$zero",
	"$at",
	"$v0",
	"$v1",
	"$a0",
	"$a1",
	"$a2",
	"$a3",
	"$t0",
	"$t1",
	"$t2",
	"$t3",
	"$t4",
	"$t5",
	"$t6",
	"$t7",
	"$s0",
	"$s1",
	"$s2",
	"$s3",
	"$s4",
	"$s5",
	"$s6",
	"$s7",
	"$t8",
	"$t9",
	"$gp",
	"$sp",
	"$fp",
	"$ra"
};

class RegManager {
	 static const int BEGIN_TMP = 8;
	 static const int END_TMP   = 15;
	 int reg[32];
public:
	 int getTmpReg() {
		for(int i = BEGIN_TMP; i <= END_TMP; i++) {
			if (reg[i] == 0) {
				reg[i] = 1;
				return i;
			}
		}
		return -1;
	}

	void useReg(int i) {
	 	reg[i] = 1;
	}

	void freeReg(int i) {
		if (regTable[i][1] != 't') return;
		reg[i] = 0;
	}

};

class CodeGenerator {

public:
	// R-type instruments
	static void emitCodeR(const string op, int dst, int src_1, int src_2) {
		cout << "emit" << dst << src_1 << src_2 <<endl;
		string c;
		if (op == "=") {
			c = "add " + regTable[dst] + "," + regTable[src_1] + "," + regTable[src_2];
		} else if (op == "-") {
			c = "sub" + regTable[dst] + "," + regTable[src_1] + "," + regTable[src_2];
		} else if (op == "*") {
			c = "mul" + regTable[dst] + "," + regTable[src_1] + "," + regTable[src_2];
		} else if (op == "/") {
			c = "div" + regTable[dst] + "," + regTable[src_1] + "," + regTable[src_2];
		} else if (op == "%") {
			c = "rem" + regTable[dst] + "," + regTable[src_1] + "," + regTable[src_2];
		} else if (op == "&&") {
			c = "and" + regTable[dst] + "," + regTable[src_1] + "," + regTable[src_2];
		} else if (op == "||") {
			c = "or" + regTable[dst] + "," + regTable[src_1] + "," + regTable[src_2];
		} else if (op == ">=") {
			int tmp = regManager->getTmpReg();
            c = "slt" + regTable[tmp] + "," + regTable[src_1] + "," + regTable[src_2] + "\n";
            c = c + "beq" + regTable[tmp] + "," + regTable[0] + "greater than or equal";
            regManager->freeReg[tmp]; 
		} else if (op == ">") {
			int tmp = regManager->getTmpReg();
            c = "slt" + regTable[tmp] + "," + regTable[src_2] + "," + regTable[src_1] + "\n";
            c = c + "bne" + regTable[tmp] + "," + regTable[0] + "greater than";
            regManager->freeReg[tmp]; 
		} else if (op == "<=") {
			int tmp = regManager->getTmpReg();
            c = "slt" + regTable[tmp] + "," + regTable[src_2] + "," + regTable[src_1] + "\n";
            c = c + "beq" + regTable[tmp] + "," + regTable[0] + "less than or equal"
            regManager->freeReg[tmp]; 
		} else if (op == "<") {
			int tmp = regManager->getTmpReg();
            c = "slt" + regTable[tmp] + "," + regTable[src_1] + "," + regTable[src_2] + "\n";
            c = c + "bne" + regTable[tmp] + "," + regTable[0] + "less than";
            regManager->freeReg[tmp]; 
		} else if (op == "==") {
            c = "beq" + regTable[tmp] + "," + regTable[0] + "equal";
		} else if (op == "!=") {
			c = "bne" + regTable[tmp] + "," + regTable[0] + "not equal";
		}
		code << c << endl;
	}


	// lw sw instruments
	static void emitCodeM(const string op, int offset, int regAddr, int reg) {
		string c;
		char ch[16] = {0,};
		sprintf(ch,"%d",offset);
		c = op + regTable[reg] + "," + ch + "(" + regTable[regAddr]+"),"+regTable[reg];
		code << c << endl;
	}
};	

#endif