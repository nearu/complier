#include "symtab.h"
#include <fstream>
using namespace std;

//// type name begin with '0' means it is only a reference
void Symtab::printSymtab(ofstream &out) {
	for(SYMMAP::iterator iter = symMap.begin();iter != symMap.end(); iter++) {
		SYMQUEUE q = iter->second;
		for(int i = 0; i < q->size(); i++) {
			SymBucket *b = (*q)[i];

			b->printBucket(out);
			Symtab * s = b->getNextSymtab();
			if (s != NULL) {
				out << "============begin "<<b->getName() << "'s symtab==================" << endl;
				s->printSymtab(out);
				out << "============end "<<b->getName() << "'s symtab==================" << endl;
			}
		}
	}
}