#include "extension.h"
#include <fstream>
#include <iostream>


using namespace std;

bool resuelveCaso() {
	extension<int> a;
	extension<int>b;
	int n,c,P,i=0;
	cin >> c;
	if (!cin)return false;
	while (i < c) {
		cin >> n;
		a.push_back(n);
		i++;		
	}
	i = 0;
	cin >> c >> P;
	while (i < c) {
		cin >> n;
		b.push_back(n);
		i++;
	}
	a.inserta(b,P);
	a.mostrar();
	return true;
}

/*
bool resuelveCaso() {
	extension<int> a;
	int n;
	cin >> n;
	if (!cin)return false;
	while (n != 0) {
		a.push_back(n);
		cin >> n;
	}
	a.invierte();
	a.mostrar();
	return true;
}*/
/*
void resuelveCaso() {
	extension<int> a;
	extension<int> b;
	int n;
	cin >> n;
	while (n != 0) {
		a.push_back(n);
		cin >> n;
	}
	cin >> n;
	while (n != 0) {
		b.push_back(n);
		cin >> n;
	}
	a.mezcla(b);
	a.mostrar();
}*/

int main() {
	/*
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif*/
	/*int n;
	cin >> n;
	int i = 0;
	while (i < n) {
		resuelveCaso();
		i++;
	}*/
	while (resuelveCaso());
	/*
	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif*/

	return 0;
}