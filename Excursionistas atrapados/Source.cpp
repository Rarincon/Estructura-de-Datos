
#include <iostream>
#include <math.h>
#include "bintree_eda.h"

using namespace std;


struct tSol {
	int equip;
	int pers;
};

template <class T>
tSol montana(bintree<T> const& arbol) {
	if (!arbol.empty()) {
		tSol izq = montana(arbol.left());
		tSol dch = montana(arbol.right());
		tSol sol = { 0,0 };
		if (arbol.root() != 0) {
			sol.pers = arbol.root();
			sol.equip = 1;
		}
		if (dch.pers != 0 && izq.pers != 0) {
			sol.equip = dch.equip + izq.equip;
			sol.pers = max(dch.pers, izq.pers) + arbol.root();
		}
		else if (dch.pers != 0) {
			sol.pers += dch.pers;
			sol.equip = dch.equip;
		}
		else if (izq.pers != 0) {
			sol.pers += izq.pers;
			sol.equip = izq.equip;
		}
		return sol;
	}
	else {
		return { 0 , 0 };
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {

	bintree <int> arbol = leerArbol(-1);
	
	
	tSol bin = montana(arbol);
	cout << bin.equip << " " << bin.pers << endl;
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