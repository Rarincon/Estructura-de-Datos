#include <iostream>
#include <math.h>
#include "bintree_eda.h"

using namespace std;


struct tSol {
	int agua, navegables;
};

template<class T>
tSol rios(bintree<T>const& arbol) {
	if (!arbol.empty()) {
		tSol sol = { 0,0 }, dch, izq;
		izq = rios(arbol.left());
		dch = rios(arbol.right());
		if (arbol.left().empty() && arbol.right().empty()) {
			return{ 1,0 };
		}
		else {
			sol.agua = izq.agua + dch.agua - arbol.root();
			if (sol.agua < 0)sol.agua = 0;
			if (sol.agua >= 3) {
				sol.navegables = 1;
			}
			sol.navegables += izq.navegables + dch.navegables;
		}
		return sol;
	}
	else
		return{ 0,0 };
}

template<class T>
tSol rioI(bintree<T>const& arbol) {
	if (!arbol.empty()) {
		tSol sol = { 0,0 }, dch, izq;
		izq = rios(arbol.left());
		dch = rios(arbol.right());
		if (arbol.left().empty() && arbol.right().empty()) {
			return{ 1,0 };
		}
		else {
			sol.agua = izq.agua + dch.agua - arbol.root();
			if (sol.agua < 0)sol.agua = 0;
			sol.navegables += izq.navegables + dch.navegables;
		}
		return sol;
	}
	else
		return{ 0,0 };
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {

	bintree <int> arbol = leerArbol(-1);
	tSol sol = rioI(arbol);
	//if (sol.navegables > 0 )//&& arbol.root() == 0 && sol.agua >= 3)
		cout << sol.navegables << endl;// -1 << endl;
	//else
		//cout << sol.navegables << endl;
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