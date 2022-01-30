#include <iostream>
#include <math.h>
#include "bintree_eda.h"

using namespace std;

template<class T>
bool simetrico(bintree<T>const& dch, bintree<T>const& izq) {
	if (!dch.empty() && !izq.empty()) {
		bool ok = simetrico(dch.right(), izq.left());
		bool ok2 = simetrico(dch.left(), izq.right());
		return ok & ok2;
	}
	else if(dch.empty() && izq.empty()){
		return true;
	}
	else {
		return false;
	}
}

/*
struct tSol {
	int hojas;
	int dch;
	int izq;
	int alt;
};

template<class T>
tSol simetrico(bintree<T>const& arbol) {
	if (!arbol.empty()) {
		tSol sol={ 0,0,0,0 };
		if (arbol.left().empty() && arbol.right().empty()) {
			return { 1,0,0,0 };
		}
		else {
			if (!arbol.left().empty()) sol.izq += 1;
			if (!arbol.right().empty()) sol.dch += 1;
			tSol izq = simetrico(arbol.left());
			tSol dch = simetrico(arbol.right());

			sol.hojas += izq.hojas + dch.hojas;
			sol.dch += dch.dch+izq.dch;
			sol.izq += izq.izq + dch.izq;
			sol.alt += max(izq.alt, dch.alt)+1;

		}
		return sol;
	}
	else
		return { 0,0,0,0 };
}
*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {

	bintree <char> arbol = leerArbol('.');
	if (!arbol.empty()) {
		if (simetrico(arbol.right(), arbol.left()))
			cout << "SI" << endl;
		else cout << "NO" << endl;
		/*tSol dch = simetrico(arbol.right());
		tSol izq = simetrico(arbol.left());
	
		if (dch.hojas == izq.hojas && dch.dch == izq.izq && dch.izq == izq.dch && dch.alt==izq.alt) cout << "SI" << endl;
		else cout << "NO" << endl;*/
	}
	else cout<<"NO"<<endl;

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