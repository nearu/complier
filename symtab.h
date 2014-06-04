#ifndef __SYMTAB_H_
#define __SYMTAB_H_
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include "code_generator.h"
using namespace std;

class SymBucket;
class Symtab;	

typedef vector<SymBucket *> * SYMQUEUE;
typedef map<string, SYMQUEUE> SYMMAP;
extern RegManager *regManager;

class SymBucket {
	int 			lineNO;
	// the address of this type, default -1
	int 			location;
	int 			size;
	// default -1
	int 			regNum;
	// type name
	const string 	type;
	// id name
	string 			name;

	// the sub level symtab for funciton or procedure
	Symtab 			*nextSymtab;
	// currnt symtab
	Symtab 			*curSymtab;

	void _print(ofstream &out) {
		if (location != -1)
			out << lineNO << " " << name << ":\t" << type << "\t at " << location;
		else if (regNum != -1)
			out << lineNO << " " << name << ":\t" << type << "\t at reg " << regNum;
		else 
			out << lineNO << " " << name << ":\t" << type;
	}

public:
	// next bucket in the one complicated datastructure
	SymBucket 		*next;
	SymBucket(const string _name, int _lineNO, const string _type, Symtab* _curSymtab)
		:name(_name),lineNO(_lineNO), type(_type), curSymtab(_curSymtab),nextSymtab(NULL),
		location(-1), next(this), regNum(-1)
		{}

/////////////////////////////////////////////////////
// set functions								   //
/////////////////////////////////////////////////////		
	void setLoc(int l) {
		location = l;
	}

	void setSize(int s) {
		size = s;
	}


	void setSymtab(Symtab *symtab) {
		nextSymtab = symtab;
	}

	void setRegNum(int rn) {
		regNum = rn;
	}

/////////////////////////////////////////////////////
// get functions								   //
/////////////////////////////////////////////////////	
	int getLoc() {
		return location;
	}

	int getLineno() {
		return lineNO;
	}

	const string& getType() {
		return type;
	}

	Symtab* getNextSymtab() {
		return nextSymtab;
	}

	const string& getName() {
		return name;
	}

	int getRegNum() {
		return regNum;
	}

	int getSize() {
		return size;
	}


	void printBucket(ofstream &out) {
		_print(out);
		SymBucket *tmp = next;
		while(tmp != this) {
			out << " .. ";
			tmp->_print(out);
			tmp = tmp->next;
		}
		out << endl;
	}
	~SymBucket() {

	}
};


class Symtab {
	const int BEGIN_REG_NUM;
	const int END_REG_NUM;
	// symtabName
	const string symtabName;
	// the parent symtab
	SymBucket *pBucket;
	// inner hash map for symtab
	SYMMAP symMap;
	// current offset in the stack
	int curLoc;
	// default reg num is -1
	int curRegNum;
public:
	Symtab(const string _name, SymBucket *_pBucket = NULL)
		:symtabName(_name), pBucket(_pBucket),curLoc(0),curRegNum(-1),
		BEGIN_REG_NUM(16), END_REG_NUM(23){}

	void insert(SymBucket* b) {
		SYMMAP::iterator iter;
		string name = b->getName();
		iter = symMap.find(name);
		if (iter != symMap.end()) {
			symMap[name]->push_back(b);
		} else {
			SYMQUEUE q = new vector<SymBucket*>();
			q->push_back(b);
			symMap[name] = q;
		}
	}

	SymBucket *find(string name) {
		SYMMAP::iterator iter;
		iter = symMap.find(name);
		cout << "ff" << endl;
		if (iter != symMap.end()) {
			SYMQUEUE q = symMap[name];
			for(int i = q->size()-1; i >= 0; i--) {
				cout << "fq" << endl;
				if ((*q)[i]->getName() == name) 
					return (*q)[i];
			}
		}
		return NULL;
	}

	void deleteSymBucket(string name) {

	}

	const string getSymtabName() {
		return symtabName;
	}

	const SymBucket * getParBucket() {
		return pBucket;
	}

	

	void setCurLoc(int loc) {
		curLoc = loc;
	}

	int getCurLoc() {
		return curLoc;
	}

	int  genLoc(int size) {
		int l = curLoc;
		curLoc += size;
		return l;
	}
	// if return num is -1, then this symbol has to be stored in the stack
	// otherwise, return a num 
	int genRegNum() {
		if (curRegNum == END_REG_NUM) return -1;
		if (curRegNum == -1) {
			curRegNum = BEGIN_REG_NUM;
		} else {
			curRegNum++;
		}
		regManager->useReg(curRegNum);
		return curRegNum;
	}

	int getCurReg() {
		return curRegNum;
	}

	int isRegSpill() {
		return curRegNum == END_REG_NUM;
	}
	void printSymtab(ofstream& out);
	virtual ~Symtab() {}

};

#endif


