#ifndef __SYMTAB_H_
#define __SYMTAB_H_
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class SymBucket;
class Symtab;	
typedef vector<SymBucket *> * SYMQUEUE;
typedef map<string, SYMQUEUE> SYMMAP;


class SymBucket {
	int 			lineNO;
	// the address of this type
	int 			location;
	int 			level;
	// type name
	const string 	type;
	// id name
	string 			name;
	// next bucket in the one hash entry
	SymBucket 		*next;
	// next bucket in complicated data structure
	SymBucket	    *nextItem;
	// the sub level symtab for funciton or procedure
	Symtab 			*nextSymtab;
	// currnt symtab
	Symtab 			*curSymtab;
public:
	SymBucket(const string _name, int _lineNO, const string _type, SymBucket *_next)
		:name(_name),lineNO(_lineNO), type(_type), next(_next)
		{}

	void setLocation(int l) {
		location = l;
	}
	int getLocation() {
		return location;
	}
	int getLineno() {
		return lineNO;
	}

	const string& getType() {
		return type;
	}

	SymBucket *getNext() {
		return next;
	}

	const string& getName() {
		return name;
	}
	void setSymtab(Symtab *symtab) {
		nextSymtab = symtab;
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
public:
	Symtab(const string _name, SymBucket *_pBucket = NULL)
		:symtabName(_name), pBucket(_pBucket){}

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

	void printSymtab() {

	}
	virtual ~Symtab() {}

};

#endif


