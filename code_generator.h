#ifndef __CODE_GENERATOR_H_
#define __CODE_GENERATOR_H_
#include <fstream>
#include <iostream>
#include <cctype>
#include <cstdio>
using namespace std;
extern ofstream code;
class RegManager;
class LabelManager;
extern RegManager *regManager;
extern LabelManager  *labelManager;
extern int traceEmit;
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
		cout << "reg is run out" << endl;
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

class LabelManager {

public:
	static int loop_number;
	static int func_number;
	static int case_number;
	static int goto_number;
	static int if_number;
	static int do_number;
	int getLoopLabel(){return loop_number;}
	void addLoopLabel(){loop_number++;} 
	int getRepeatLabel(){return do_number;}
	void addRepeatLabel(){do_number++;} 
	int getIfLabel(){return if_number;}
	void addIfLabel(){if_number++;} 
	int getgotoLabel(){return goto_number;}
	void addgotoLabel(){goto_number++;} 
	int getCaseLabel(){return case_number;}
	void addCaseLabel(){case_number++;}
	int getFuncLabel() {return func_number;}
	void addFuncLabel(string &label) {
		char labelNum[10] = {0,};
		sprintf(labelNum, "%d", func_number++);
		label = label + labelNum;	
	}

};



class CodeGenerator {

public:
	// R-type instruments
	// if the op is "~" then src_1 = 0 and src_2 is the right hand variable
	static void emitCodeR(const string op, int dst, int src_1, int src_2) {
		if (traceEmit) cout << "emit R : " << op << " " << dst << " " << src_1 << " " << src_2 <<endl;
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
            c = "slt " + regTable[dst] + "," + regTable[src_2] + "," + regTable[src_1];
		} else if (op == "<=") {
			int tmp = regManager->getTmpReg();
            c = "slt " + regTable[tmp] + "," + regTable[src_2] + "," + regTable[src_1] + "\n";
            c = c + "xori " + regTable[dst] + "," + regTable[tmp] + "," + "1";
            regManager->freeReg(tmp);
		} else if (op == "<") {
            c = "slt " + regTable[dst] + "," + regTable[src_1] + "," + regTable[src_2] ;
		} else if (op == "==") {
			c = "addi " + regTable[dst] + "," + regTable[0] + ",0" + "\n";
            c = c + "beq " + regTable[src_1] + "," + regTable[src_2] + ",4" +"\n";
            c = c + "addi " + regTable[dst] + "," + regTable[0] + ",-1" + "\n";
            c = c + "addi " + regTable[dst] + "," + regTable[dst] + ",1";
		} else if (op == "!=") {
			c = "addi " + regTable[dst] + "," + regTable[0] + ",0" + "\n";
            c = c + "bne " + regTable[src_1] + "," + regTable[src_2] + ",4" +"\n";
            c = c + "addi " + regTable[dst] + "," + regTable[0] + ",-1" + "\n";
            c = c + "addi " + regTable[dst] + "," + regTable[dst] + ",1";
		} else if (op == "~") {
			c = c + "xori " + regTable[dst] + ", " + regTable[src_2] + ", -1" ;
		}
		code << c << endl;
	}

	static void emitCodeI(const string op, int dst, int src, int imm)
	{
		if (traceEmit) cout << "emit I op = " << op << " dst = " << dst << " src = " << src <<endl;
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
			int tmp2 = regManager->getTmpReg();
			c = "addi " + regTable[tmp2] + "," + regTable[0] + "," + ch + "\n";
            c = c + "slt " + regTable[dst] + "," + regTable[tmp2] + "," + regTable[src]; 
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
            c = "slti " + regTable[dst] + "," + regTable[src] + "," + ch ;
            regManager->freeReg(tmp); 
		} else if (op == "==") {
			int tmp = regManager->getTmpReg();
			c = "addi " + regTable[dst] + "," + regTable[0] + ",0" + "\n";
			c = c + "addi " + regTable[tmp] + "," + regTable[0] + "," + ch + "\n";
            c = c + "beq " + regTable[src] + "," + regTable[tmp] + ",4" +"\n";
            c = c + "addi " + regTable[dst] + "," + regTable[0] + ",-1" + "\n";
            c = c + "addi " + regTable[dst] + "," + regTable[dst] + ",1";
            regManager->freeReg(tmp); 
		} else if (op == "!=") {
			int tmp = regManager->getTmpReg();
			c = "addi " + regTable[dst] + "," + regTable[0] + ",0" + "\n";
			c = c + "addi " + regTable[tmp] + "," + regTable[0] + "," + ch + "\n";
            c = c + "bne " + regTable[src] + "," + regTable[tmp] + ",4" +"\n";
            c = c + "addi " + regTable[dst] + "," + regTable[0] + ",-1" + "\n";
            c = c + "addi " + regTable[dst] + "," + regTable[dst] + ",1";
            regManager->freeReg(tmp); 
		}
		code << c << endl;
	}

	static void emitCodeJ(const string op, int reg1, int reg2, int imm, const string label){
		string c;
		if(op == "beq" || op == "bne"){
			if(reg2 > 31){
				char ch[16] = {0,};
				sprintf(ch,"%d",imm);
				int tmp = regManager->getTmpReg();
				c = "addi " + regTable[tmp] + "," + regTable[0] + "," + ch + "\n";
				c = c + op + " " + regTable[reg1] + "," + regTable[tmp] + "," + label;
				regManager->freeReg(tmp); 
			}
			else {
				c = op + " " + regTable[reg1] + "," + regTable[reg2] + "," + label;
			}
		}
		else if(op == "j") {
			c = op + " " + label;
		} else if (op == "jr") {
			c = op + " " + regTable[reg1];
		}
		code << c << endl;

	}

	static void addLabel(const string label){
		code << label << ":" << endl;
	}


	// lw sw instruments
	// reg is the src or dst reg
	// load_reg , store_reg means that offset is stored in the register numbered "offset"
	static void emitCodeM(int size, const string op, int offset, int regAddr, int reg) {
		if (traceEmit) cout << "emit M" << " size = " << size << " offset = " << offset <<  endl;
		string c;
		char loadInstr[][4] = {"", "lb", "lh", "","lw"};
		char storeInstr[][4] = {"", "sb", "sh", "","sw"};
		char ch[16] = {0,};
		string instr;
		string localOP = op;
		const int FP = 30;
		int tmpAC = regManager->getTmpReg();
		if (op.find("-") != string::npos) {
			int pos = op.find('-');
			int level = atoi(op.substr(pos+1, op.length()).c_str());
			CodeGenerator::emitCodeM(4, "load", 4, FP, tmpAC);
			for (int i = 1; i < level; i++) {
				CodeGenerator::emitCodeM(4, "load", 0, tmpAC, tmpAC);
			}
			regAddr = tmpAC;
			offset -= 4;
			localOP = op.substr(0,pos);
		}

		if (localOP == "load" || localOP == "load_reg") {
			instr = loadInstr[size];
		} else {
			instr = storeInstr[size];
		}
		if (localOP == "load" || localOP == "store") {
			sprintf(ch,"%d",offset);
			c = instr +  " "  + regTable[reg] + ", " + ch + "(" + regTable[regAddr]+")";
			code << c << endl;
		} else if (localOP == "load_reg" || localOP =="store_reg") {
			ch[0] = '\0';
			sprintf(ch, "0");
			string c1 = "add " + regTable[offset] + ", " + regTable[offset] + ", " + regTable[regAddr];
			c = instr + " " + regTable[reg] + ", " + ch + "(" + regTable[offset] + ")";
			regManager->freeReg(offset);
			code << c1 << endl << c << endl;
		}
		regManager->freeReg(tmpAC);
	}

	static void emitRet() {
		code << "ret" << endl;
	}

};	

#endif