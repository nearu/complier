#include <fstream>
#include <map>
#include <string>
using namespace std;
class SymBucket {
	int lineNO;
	int memoryLoc;
	const string type;
	string name;
	SymBucket *next;
public:
	SymBucket(const string _name, int _lineNO, const string _type, SymBucket *_next, int _memoryLoc = 0)
		:name(_name),lineNO(_lineNO), type(_type), next(_next), memoryLoc(_memoryLoc) 
		{}
	int getLineno() {
		return lineNO;
	}

	const string& getType() {
		return type;
	}

	SymBucket *getNext() {
		return next;
	}

	int getMemoryLoc() {
		return memoryLoc;
	}

	const string& getName() {
		return name;
	}
};


class Symtab {
	const string symtaName;
	map<string, queue< SymBucket *> *> symMap;
public:
	Symtab(const string _name):symtaName(_name){}
	void insert(SymBucket* b) {
		map<string, queue<SymBucket *>*>::iterator iter;
		string name = b->getName();
		iter = symMap.find(name);
		if (iter != symMap.end()) {
			symMap[name]->push_back(b);
		} else {
			queue<SymBucket *>* q = new queue<SymBucket*>();
			q->push_back(b);
			symMap[name] = q;
		}
	}

	virtual ~Symtab() {}

};

