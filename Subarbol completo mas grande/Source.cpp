

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "bintree_eda.h"

using namespace std;

struct tSol {
	int max;
	int rel;
};

// funcion que resuelve el problema
tSol resolver(const bintree<char>& arbol) {
	if (arbol.empty())
		return { 0, 0 };
	else {
		int rel, m;
		tSol left = resolver(arbol.left()), right = resolver(arbol.right());
		if (left.rel == right.rel) {
			rel = left.rel + 1;
			m = max(left.max, right.max);
			if (rel > m)
				return { rel, rel };
			else
				return { m, rel };
		}
		else
			return { max(left.max, right.max), min(left.rel, right.rel) + 1 };
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<char> arbol = leerArbol('.');

	//resolver el problema
	tSol sol = resolver(arbol);

	// escribir sol
	cout << sol.max << endl;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	/*
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif */


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	/*
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/

	return 0;
}