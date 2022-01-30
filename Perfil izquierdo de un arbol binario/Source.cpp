
#include <iostream>
#include <math.h>
#include "bintree_eda.h"
#include <string>

using namespace std;



template <class T>
void perfiles(bintree<T> const& arbol, vector<int> & v, int nivel) {
	if (!arbol.empty()) {
		if (nivel > v.size())
			v.push_back(arbol.root());
		perfiles(arbol.left(), v, nivel + 1);
		perfiles(arbol.right(), v, nivel + 1);
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
	
	bintree<int> arbol = leerArbol(-1);
	vector<int> v;
	perfiles(arbol, v, 1);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
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
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		resuelveCaso();


	/*
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
*/
	return 0;
}