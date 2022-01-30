
#include <iostream>
#include <math.h>
#include"bintree_eda.h"
#include <vector>

using namespace std;

template <class T>
void frontera(bintree<T> const& arbol) {
	if (!arbol.empty()) {
		if (arbol.left().empty() && arbol.right().empty())
			cout << arbol.root()<<" ";
		else {
			if (!arbol.left().empty())
				frontera(arbol.left());
			if (!arbol.right().empty())
				frontera(arbol.right());

		}	
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {

	bintree <int> arbol = leerArbol(-1);
	frontera(arbol);
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
	for (int i = 0; i < n; i++)
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