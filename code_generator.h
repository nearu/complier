#ifndef __CODE_GENERATOR_H_
#define __CODE_GENERATOR_H_
#include <fstream>
#include <iostream>
#include <cctype>
#include <cstdio>
using namespace std;
extern ofstream code;
class RegManager;
extern RegManager *regManager;
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
	"",
	"",
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
		cout << "free " << i << endl;
		if (regTable[i][1] != 't') return;
		reg[i] = 0;
	}

};

class CodeGenerator {

public:
	// R-type instruments
	static void emitCodeR(const string op, int dst, int src_1, int src_2) {
		cout << "emit R :" << op << dst << " " << src_1 << " " << src_2 <<endl;
		string c;
		if (op == "+" || op == "=") {
			c = "add " + regTable[dst] + "," + regTable[src_1] + "," + regTable[src_2];
		} else if (op == "-") {
			c = "sub " + regTable[dst] + "," + regTable[src_1] + "," + regTable[src_2];
		} else if (op == "*") {
			c = "mul " + regTable[dst] + "," + regTable[src_1] + "," + regTable[src_2];
		} else if (op == "/") {
			c = "div " + regTable[dst] + "," + regTable[src_1] + "," + regTable[src_2];
		} else if (op == "%") {
			c = "rem " + regTable[dst] + "," + regTable[src_1] + "," + regTable[src_2];
		} else if (op == "&&") {
			c = "and " + regTable[dst] + "," + regTable[src_1] + "," + regTable[src_2];
		} else if (op == "||") {
			c = "or " + regTable[dst] + "," + regTable[src_1] + "," + regTable[src_2];
		} else if (op == ">=") {
			int tmp = regManager->getTmpReg();
            c = "slt " + regTable[tmp] + "," + regTable[src_1] + "," + regTable[src_2] + "\n";
            c = c + "xori " + regTable[dst] + "," + regTable[tmp] + "," + "1";
            regManager->freeReg(tmp); 
		} else if (op == ">") {
			int tmp = regManager->getTmpReg();
            c = "slt " + regTable[tmp] + "," + regTable[src_2] + "," + regTable[src_1] + "\n";
            c = c + "xori " + regTable[dst] + "," + regTable[tmp] + "," + "0";
            regManager->freeReg(tmp); 
		} else if (op == "<=") {
			int tmp = regManager->getTmpReg();
            c = "slt " + regTable[tmp] + "," + regTable[src_2] + "," + regTable[src_1] + "\n";
            c = c + "xori " + regTable[dst] + "," + regTable[tmp] + "," + "1";
            regManager->freeReg(tmp);
		} else if (op == "<") {
			int tmp = regManager->getTmpReg();
            c = "slt " + regTable[tmp] + "," + regTable[src_1] + "," + regTable[src_2] + "\n";
            c = c + "xori " + regTable[dst] + "," + regTable[tmp] + "," + "0";
            regManager->freeReg(tmp); 
		} else if (op == "==") {
			c = "addi " + regTable[dst] + "," + regTable[0] + ",0" + "\n";
            c = c + "beq " + regTable[src_1] + "," + regTable[src_2] + ",equal" +"\n";
            c = c + "addi " + regTable[dst] + "," + regTable[0] + ",-1" + "\n";
            c = c + "equal:" + "addi " + regTable[dst] + "," + regTable[dst] + ",1";
		} else if (op == "!=") {
			c = "addi " + regTable[dst] + "," + regTable[0] + ",0" + "\n";
            c = c + "bne " + regTable[src_1] + "," + regTable[src_2] + ",notequal" +"\n";
            c = c + "addi " + regTable[dst] + "," + regTable[0] + ",-1" + "\n";
            c = c + "notequal:" + "addi " + regTable[dst] + "," + regTable[dst] + ",1";
		}
		code << c << endl;
	}

	static void emitCodeI(const string op, int dst, int src, int imm)
	{
		cout << "emit I :" << op << dst << " " << src <<endl;
		string c;
		char ch[16] = {0,};
		sprintf(ch,"%d",imm);
		if (op == "+" || op == "=") {
			c = "addi " + regTable[dst] + "," + regTable[src] + "," + ch;
		} else if (op == "-") {
			c = "addi " + regTable[dst] + "," + regTable[src] + "," + "-" + ch;
		} else if (op == "*") {
			int tmp = regManager->getTmpReg();
			c = "addi " + regTable[tmp] + "," + regTable[0] + "," + ch + "\n";
			c = c + "mul " + regTable[dst] + "," + regTable[src] + "," + regTable[tmp];
			regManager->freeReg(tmp);
		} else if (op == "/") {
			int tmp = regManager->getTmpReg();
			c = "addi " + regTable[tmp] + "," + regTable[0] + "," + ch + "\n";
			c = c + "div " + regTable[dst] + "," + regTable[src] + "," + regTable[tmp];
			regManager->freeReg(tmp);
		} else if (op == "%") {
			int tmp = regManager->getTmpReg();
			c = "addi " + regTable[tmp] + "," + regTable[0] + "," + ch + "\n";
			c = c + "rem " + regTable[dst] + "," + regTable[src] + "," + regTable[tmp];
			regManager->freeReg(tmp);
		} else if (op == "&&") {
			c = "andi " + regTable[dst] + "," + regTable[src] + "," + ch;
		} else if (op == "||") {
			c = "ori " + regTable[dst] + "," + regTable[src] + "," + ch;
		} else if (op == ">=") {
			int tmp = regManager->getTmpReg();
            c = "slti " + regTable[tmp] + "," + regTable[src] + "," + ch + "\n";
            c = c + "xori " + regTable[dst] + "," + regTable[tmp] + "," + "1";
            regManager->freeReg(tmp); 
		} else if (op == ">") {
			int tmp = regManager->getTmpReg();
			int tmp2 = regManager->getTmpReg();
			c = "addi " + regTable[tmp2] + "," + regTable[0] + "," + ch + "\n";
            c = c + "slt " + regTable[tmp] + "," + regTable[tmp2] + "," + regTable[src] + "\n";
            c = c + "xori " + regTable[dst] + "," + regTable[tmp] + "," + "0";
            regManager->freeReg(tmp); 
            regManager->freeReg(tmp2);
		} else if (op == "<=") {
			int tmp = regManager->getTmpReg();
			int tmp2 = regManager->getTmpReg();
			c = "addi " + regTable[tmp2] + "," + regTable[0] + "," + ch + "\n";
            c = c + "slt " + regTable[tmp] + "," + regTable[tmp2] + "," + regTable[src] + "\n";
            c = c + "xori " + regTable[dst] + "," + regTable[tmp] + "," + "1";
            regManager->freeReg(tmp);
            regManager->freeReg(tmp2);
		} else if (op == "<") {
			int tmp = regManager->getTmpReg();
            c = "slt " + regTable[tmp] + "," + regTable[src] + "," + ch + "\n";
            c = c + "xori " + regTable[dst] + "," + regTable[tmp] + "," + "0";
            regManager->freeReg(tmp); 
		} else if (op == "==") {
			int tmp = regManager->getTmpReg();
			c = "addi " + regTable[dst] + "," + regTable[0] + ",0" + "\n";
			c = c + "addi " + regTable[tmp] + "," + regTable[0] + "," + ch + "\n";
            c = c + "beq " + regTable[src] + "," + regTable[tmp] + ",equal" +"\n";
            c = c + "addi " + regTable[dst] + "," + regTable[0] + ",-1" + "\n";
            c = c + "equal:" + "addi " + regTable[dst] + "," + regTable[dst] + ",1";
            regManager->freeReg(tmp); 
		} else if (op == "!=") {
			int tmp = regManager->getTmpReg();
			c = "addi " + regTable[dst] + "," + regTable[0] + ",0" + "\n";
			c = c + "addi " + regTable[tmp] + "," + regTable[0] + "," + ch + "\n";
            c = c + "bne " + regTable[src] + "," + regTable[tmp] + ",notequal" +"\n";
            c = c + "addi " + regTable[dst] + "," + regTable[0] + ",-1" + "\n";
            c = c + "notequal:" + "addi " + regTable[dst] + "," + regTable[dst] + ",1";
            regManager->freeReg(tmp); 
		}
		code << c << endl;
	}


	// lw sw instruments
	static void emitCodeM(const string op, int offset, int regAddr, int reg) {
		string c;
		char ch[16] = {0,};
		sprintf(ch,"%d",offset);
		c = op +  " "  + regTable[reg] + ", " + ch + "(" + regTable[regAddr]+")";
		code << c << endl;
	}

};	

#endif