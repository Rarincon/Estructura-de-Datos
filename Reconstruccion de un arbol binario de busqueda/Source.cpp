
#include <iostream>
#include <math.h>
#include"bintree_eda.h"
#include<string>
#include <vector>
#include<sstream>

using namespace std;

bintree<int> reconstruir(vector<int> const& preorden, int ini, int fin) {
	if (ini <= fin) {
		int raiz = preorden[ini];
		int top = ini+1;
		while (top<=(preorden.size() - 1) && raiz > preorden[top]) top++;

		auto izq = reconstruir(preorden, ini + 1, top - 1);
		auto dch = reconstruir(preorden, top, fin);

		return { izq, raiz, dch };
	}
	else return {};
}

bintree<int> reconstruir2(vector<int> const& postorden, int ini, int fin) {
	if (ini <= fin) {
		int raiz = postorden[fin];
		int top = fin - 1;
		while (top <= (postorden.size() - 1) && raiz < postorden[top]) top--;

		auto dch = reconstruir2(postorden, top + 1 , fin - 1);
		auto izq = reconstruir2(postorden, ini, top);

		return { izq, raiz, dch };
	}
	else return {};
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	string pre;
	getline(cin, pre);
	if (!cin) return false;

	int n;
	vector<int>preorden;
	stringstream spre(pre);
	while (spre >> n) preorden.push_back(n);
	int k = preorden.size() - 1;
	//auto arbol = reconstruir(preorden, 0, k);
	auto arbol = reconstruir2(preorden, 0,k);

	//auto postorden = arbol.postorder();
	auto pretorden = arbol.preorder();
	bool prim = true;
	for (int x : pretorden) {
		if (!prim)cout << " ";
		else prim = false;
		cout << x;
	}
	cout << endl;
	return true;
}


int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	/*
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
*/
	
	while(resuelveCaso());


	/*
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
*/
	return 0;
}