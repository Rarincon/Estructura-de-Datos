// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO
//El problema se resuelve recursivamente, comprobando si el arbol es vacio u hoja por tanto es zurdo, sino se comprueban sus hijos. Para ello hacen falta dos variables
//Una que nos diga si el hijo es zurdos y sus descendientes, y asi se realiza las dos comprobaciones de que  ambos hijos son zurdos y el en hijo izquierdo hay mas de la mitad
//de los descendientes del nodo en el que nos encontremos. Se devuelven los descendientes de ambos hijos +1(que es el nodo actual) y si es zurdo o no.

//Coste:
//T(n){ c0 si el arbol es vacio o una hoja, coste constante ya que solo se realizan comprobaciones
//	  { T(ni) + T(nd) + c1 pues se realizan dos llamadas recursicas, tanto para los nodos del lado izquierdo del arbol (ni) como los del lado derecho (nd) mas la constante de las operaciones a realizar

//Por tanto el coste del ejercicio en de O(n) siendo n el numero de nodos que tenga el arbol, pues se pasa una vez por cada uno de los nodos del arbol

#include <iostream>               
#include <fstream>               
#include <algorithm>
using namespace std;

#include "bintree_eda.h"


// Implementa aquí la función pedida. Puedes definir las funciones
// auxiliares que necesites
struct tSol {
	bool zurdo; //indica si es zurdo o no
	int alt; //numero de descendientes que tiene
};

tSol zurdo2(bintree<char>const& arbol) {
	if (!arbol.empty()) {
		if (arbol.left().empty() && arbol.right().empty())return{ true, 1 };
		else {
			tSol dch, izq;
			izq = zurdo2(arbol.left()); //llamada recursiva
			dch = zurdo2(arbol.right()); //llamada recursiva
			int desc = izq.alt + dch.alt;
			desc = desc / 2;
			if (izq.zurdo && dch.zurdo && izq.alt > desc) { // comprobacion de la mitad y de que los hijos sean zurdos
				return { true, izq.alt + dch.alt + 1 };
			}
			else return { false, izq.alt + dch.alt + 1 };
		}
	}
	else return { true,0 };
}

bool zurdo(bintree<char>const& arbol) {
	return zurdo2(arbol).zurdo;
}

void resuelveCaso() {
	auto arbol = leerArbol('.');
	if (zurdo(arbol))
		cout << "SI\n";
	else
		cout << "NO\n";
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	cin >> numCasos;

	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	// system("PAUSE");
#endif
	return 0;
}
