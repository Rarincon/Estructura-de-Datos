

#include <iostream>
#include <math.h>
#include "bintree_eda.h"
#include <string>
#include <sstream>

using namespace std;

bintree<int> reconstruir(vector<int>const& preorden, int & p, vector<int>const& inorden, int & i, int top) {
	if (p == preorden.size() || inorden[i] == top) return {};

	int r = preorden[p];
	p++;
	auto izq = reconstruir(preorden, p, inorden, i, r);
	i++;
	auto dch = reconstruir(preorden, p, inorden, i, top);
	return { izq, r, dch };
}

bintree<int> reconstruir2(vector<int>const& postorden, int& p, vector<int>const& inorden, int& i, int top) {
	if (p < 0  || inorden[i] == top) return {};

	int r = postorden[p];
	p--;
	auto dch = reconstruir2(postorden, p, inorden, i, r);
	i--;
	auto izq = reconstruir2(postorden, p, inorden, i, top);
	return { izq, r, dch };
}

/*
bintree<int> reconstruir(vector<int>const& preorden, int a, int b, vector<int>const& inorden, int c, int d) {
	
	
	if (a > b) return {};
	int r = preorden[a];
	int pr = c;
	while (inorden[pr] != r) pr++;
	int TamIzq = pr - c;
	auto iz = reconstruir(preorden, a + 1, a + TamIzq, inorden, c, pr - 1);
	auto dch = reconstruir(preorden, a + TamIzq + 1, b, inorden,pr + 1, d);

	return { iz, r, dch };
}*/


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	string pre, in;
	getline(cin, pre);
	getline(cin, in);
	if (!cin) return false;
	//int p = 0, i = 0;
	int p,i;

	int n;
	vector<int>preorden;
	vector<int>inorden;

	stringstream spre(pre);
	while (spre >> n) preorden.push_back(n);
	p = preorden.size()-1;
	stringstream sin(in);
	while (sin >> n) inorden.push_back(n);
	i = inorden.size() - 1;
	int k = preorden.size();
	//auto arbol = reconstruir(preorden,0, k-1, inorden,0, k-1);
	//auto arbol = reconstruir(preorden,p, inorden,i, -1);
	auto arbol = reconstruir2(preorden, p, inorden, i, -1);
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
	while (resuelveCaso());


	/*
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
*/
	return 0;
}