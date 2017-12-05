#include <iostream>
#include <string>
#include <fstream>

#include "header.h"

using std::cout;
using std::ifstream;
using std::string;

void gem (ifstream& inputFile, double c, vector<vector<double>>& G) {

	string basura;
	tupla<int, int> eq1;
	tupla<int, int> eq2;
	int suma;
	int size = G.size();

	while (inputFile >> basura) {
		inputFile >> eq1.primero;
		inputFile >> eq1.segundo;
		inputFile >> eq2.primero;
		inputFile >> eq2.segundo;
		if (eq1.segundo == eq2.segundo) {
			//empate
			cout << "hay empate" << "\n";
		} else if (eq1.segundo > eq2.segundo) {
			//gano el 1
			G[eq2.primero-1][eq1.primero-1] += eq1.segundo - eq2.segundo;
		} else {
			//gano el 2
			G[eq1.primero-1][eq2.primero-1] += eq2.segundo - eq1.segundo;
		}
	}

	for (int i = 0; i < size; i++) {
		int sum = 0;
		for (int j = 0; j < size; j++) {
			sum += G[i][j];
		}
		if (sum>0) {
			for (int j = 0; j < size; j++) {
				G[i][j] = G[i][j] / sum;
			}
		}
	}

	//G = c * (H + a * u_traspuesta) + (1 - c) * e * v_traspuesta

	//a_i = 1 si la fila i es todo 0;
	//a_i = 0 sino
	vector<int> a(size,0);
	for (int i = 0; i < size; i++) {
		int j = 0;
		while (j<size && G[i][j] == 0) {
			j++;
		}
		if (j==size) {
			a[i] = 1;
		}
	}
	//e = (1 .. 1);
	//u_traspuesta = (1/n).e
	vector<double> u_traspuesta(size, 1.0/size);
	//a * u_taspuesta
	vector<vector<double>> au(size, vector<double>(size, 0));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			au[i][j] = a[i] * u_traspuesta[j];
		}
	}
	
	//(1 - c) * e = ( 1-c 1-c .... 1-c )
	//ce = (1 - c) * e
	vector<double> ce(size, 1-c);
	//v_traspuesta = vector de perzonalizacion
	//por ahora v_traspuesta = 1/n * e
	vector<double> v_traspuesta(size, 1.0/size);
	//ce * v_traspuesta
	vector<vector<double>> cev(size, vector<double>(size, 0));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cev[i][j] = ce[i] * v_traspuesta[j];
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			G[i][j] = ( G[i][j] + au[i][j] ) * c + cev[i][j];
		}
	}

	return;
}