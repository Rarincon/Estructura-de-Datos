

#include <iostream>
#include <math.h>
#include"bintree_eda.h"

using namespace std;


struct tSol {
	bool bin;
	int max;
	int min;
};

//5 4 1 -1 -1 6 -1 -1 8 7 -1 -1 9 -1 -1  NO

//5 3 1 -1 -1 4 2 -1 -1 -1 8 7 -1 -1 9 -1 -1  NO

//5 4 1 -1 -1 -1 8 3 -1 -1 9 -1 -1  NO

//5 4 1 -1 -1 -1 8 7 -1 -1 9 2 -1 -1 -1 NO

//5 4 1 -1 -1 -1 8 3 -1 -1 9 2 -1 -1 -1  NO

template <class T>
tSol binario(bintree<T> const& arbol){
	if (!arbol.empty()) {
		if (arbol.right().empty() && arbol.left().empty()) {
			return { true , arbol.root(), arbol.root() };
		}
		else {
			bool minR = true, maxL=true;
			int MAX = arbol.root(), MIN= arbol.root();
			tSol dch = { true, 0, 0 };
			tSol izq = {true, 0, 0};
			if (!arbol.left().empty()) {
				izq = binario(arbol.left());
				maxL = arbol.root() > izq.min && arbol.root() > izq.max;
				MIN = min(izq.min, arbol.root());
			}
			if (!arbol.right().empty()) {
				dch = binario(arbol.right());
				//if (!arbol.right().left().empty())
					minR = arbol.root() < dch.max && arbol.root() < dch.min;
				//else
					//minR = arbol.root() < dch.max;
				MAX = max(dch.max, arbol.root());
			}
			if (!arbol.left().empty()) {
				MAX = max(MAX, izq.max);
			}
			if (!arbol.right().empty()) {
				MIN = min(MIN, dch.min);
			}


			bool bn = minR && maxL && izq.bin && dch.bin;
			return { bn, MAX, MIN };
		}
	}
	else {
		return { true ,0 , 0 };
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {

	bintree <int> arbol = leerArbol(-1);
	tSol bin = binario(arbol);
	if (bin.bin)cout << "SI" << endl;
	else cout << "NO" << endl;
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