#include "header.h"

void indeg (list<tupla<int, int>>& tuplas, vector<tupla<int,int>>& nodos) {
	
	for (list<tupla<int, int>>::iterator it = tuplas.begin(); it != tuplas.end(); it++) {
		nodos[(*it).segundo - 1].segundo += 1;
	}
	return;
}