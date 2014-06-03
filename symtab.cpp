#include "symtab.h"
#include <fstream>
using namespace std;


void Symtab::printSymtab(ofstream &out) {
	for(SYMMAP::iterator iter = symMap.begin();iter != symMap.end(); iter++) {
		SYMQUEUE q = iter->second;
		for(int i = 0; i < q->size(); i++) {
			(*q)[i]->printBucket(out);
			Symtab * s = (*q)[i]->getNextSymtab();
			if (s != NULL) {
				out << "============begin "<<(*q)[i]->getName() << "'s symtab==================";
				s->printSymtab(out);
				out << "============end "<<(*q)[i]->getName() << "'s symtab==================";
			}
		}
	}
}