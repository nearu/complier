#ifndef __SYMTAB_H_
#define __SYMTAB_H_
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class SymBucket;
class Symtab;	
typedef vector<SymBucket *> * SYMQUEUE;
typedef map<string, SYMQUEUE> SYMMAP;


class SymBucket {
	int 			lineNO;
	// the address of this type
	int 			location;
	int 			size;
	int 			regNum;
	// type name
	const string 	type;
	// id name
	string 			name;

	// the sub level symtab for funciton or procedure
	Symtab 			*nextSymtab;
	// currnt symtab
	Symtab 			*curSymtab;

public:
	// next bucket in the one complicated datastructure
	SymBucket 		*next;
	SymBucket(const string _name, int _lineNO, const string _type, Symtab* _curSymtab)
		:name(_name),lineNO(_lineNO), type(_type), curSymtab(_curSymtab),nextSymtab(NULL),
		location(0), next(this), regNum(0)
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

	int getSize() {
		return size;
	}
	void printBucket(ofstream &out) {
		out << lineNO << " " << name << ":\t" << type << "\t at " << location;
		SymBucket *tmp = next;
		while(tmp != this) {
			out << " .. ";
			out << tmp->getLineno() <<  "\t " << tmp->getName() << " :\t" << tmp->getType() << "\t at " << tmp->getLoc();
			tmp = tmp->next;
		}
		out << endl;

	}
	~SymBucket() {

	}
};


class Symtab {
	// symtabName
	const string symtabName;
	// the parent symtab
	SymBucket *pBucket;
	// inner hash map for symtab
	SYMMAP symMap;
	// current offset in the stack
	int curLoc;
	int curRegNum;
public:
	Symtab(const string _name, SymBucket *_pBucket = NULL)
		:symtabName(_name), pBucket(_pBucket),curLoc(0){}

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
		if (iter != symMap.end()) {
			SYMQUEUE q = symMap[name];
			for(int i = q->size()-1; i >= 0; i--) {
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

	int genRegNum() {
		
	}
	void printSymtab(ofstream& out);
	virtual ~Symtab() {}

};

#endif


