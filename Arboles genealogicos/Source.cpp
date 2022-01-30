#include <iostream>
#include <math.h>
#include "bintree_eda.h"

using namespace std;


struct tSol {
	bool ok;
	int num;
};

template<class T>
tSol genealogico(bintree<T>const& arbol) {
	if (!arbol.empty()) {
		tSol sol = { true,1 }, dch, izq;		
		if (!arbol.left().empty() && !arbol.right().empty()) {
			if (arbol.root() - arbol.left().root() >= 18 && arbol.left().root() - arbol.right().root() >= 2) {
				izq = genealogico(arbol.left());
				dch = genealogico(arbol.right());
				sol.ok = sol.ok & dch.ok & izq.ok;
				sol.num += max(dch.num, izq.num);		
			}
			else
				return { false,0 };
		}
		else if (arbol.left().empty() && !arbol.right().empty())
			return { false,1 };
		else if (!arbol.left().empty() && arbol.right().empty()) {
			if (arbol.root() - arbol.left().root() >= 18) {
				izq = genealogico(arbol.left());
				sol.ok = sol.ok & izq.ok;
				sol.num += izq.num;
			}
			else
				return { false,0 };
		}	
		return sol;
	}
	else 
		return{ true,0 };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {

	bintree <int> arbol = leerArbol(-1);
	tSol sol = genealogico(arbol);
	if (sol.ok)cout << "SI" << " " << sol.num << endl;
	else cout << "NO" << endl;
	/*
	if (!arbol.empty()) {
		tSol dch = simetrico(arbol.right());
		tSol izq = simetrico(arbol.left());

		if (dch.hojas == izq.hojas && dch.dch == izq.izq && dch.izq == izq.dch && dch.alt == izq.alt) cout << "SI" << endl;
		else cout << "NO" << endl;
	}
	else cout << "NO" << endl;*/

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