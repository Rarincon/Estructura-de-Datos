

#include "extension.h"
#include <fstream>
#include <iostream>
#include <queue>

using namespace std;
/*
int militar() {
	int n, cont = 0;
	bool ok = true;
	queue<int> cola;
	cin >> n;
	if (n == -1)return 0;
	while (n != 7) {
		cont++;
		cola.push(n);
		cin >> n;
	}
	cin >> n;
	while (!cola.empty() && n != -1) {
		if (cola.front() != n)ok = false;
		cola.pop();
		cin >> n;
	}
	if (n != -1 && cola.empty()) {
		ok = false;
		while (n != -1)
			cin >> n;
	}
	if (!ok || !cola.empty() || n!= -1)return -1;
	else return cont;
}*/

void resuelveCaso(){
	int n, pos;
	extension<int> q;
	cin >> n;
	while (n != 0) {
		q.push_back(n);
		cin >> n;
	}
	cin >> n >> pos;
	q.inserta(n, pos);
	q.mostrar();
	/*int sol;
	sol = militar();
	cout << sol << endl;*/

	/*
	extension<char> q;
	char n;
	cin >> n;
	while (n != '*') {
		q.push_back(n);
		cin >> n;
	}
	int i, c;
	cin >> i >> c;
	q.invierte(i, c);
	q.mostrar();*/

}

/*
bool resuelveCaso() {
	
	int n;
	queue<int> q;
	cin >> n;
	while ( n != -1) {
		q.push(n);
		cin >> n;
	}
	int i, c;
	//cin >> i >> c;
	//i=q.solveCase();
	i = q.militar();
	cout << i << endl;
	//q.mostrar();
	//q.invierte(i,c);
	
	//q.mostrar();
	return false;*/
	/*cin >> n;
	if (!cin)
		return false;
	else {
		while (n != 0) {
			q.push_back(n);
			cin >> n;
		}
		q.estremecer();
		q.print();
		return true;
	}*/
//}

int main() {
	/*
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif*/
	int n;
	cin >> n;
	int i = 0;
	while (i < n) {
		resuelveCaso();
		i++;
	}
	/*
	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif*/

	return 0;
}