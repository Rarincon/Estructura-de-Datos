

#include <iostream>
#include <math.h>
#include"bintree_eda.h"
#include <vector>
#include<algorithm>

using namespace std;

template <class T>
T minimo(bintree<T> const& arbol) {
	T min = arbol.root();
	if (arbol.left().empty() && arbol.right().empty())
		return min;
	else {
		if (!arbol.left().empty() && !arbol.right().empty()) {
			T minL = minimo(arbol.left());
			T minR = minimo(arbol.right());
			if (minL < minR) {
				if (minL < min)
					return minL;
				else return min;
			}
			else if (minR < min)return minR;
			else return min;
		}
		else if (!arbol.right().empty()) {
			T minR= minimo(arbol.right());
			if (minR < min)return minR;
			else return min;
		}
		else {
			T minL = minimo(arbol.left());
			if (minL < min)return minL;
			else return min;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	char s;
	cin >> s;
	if (!cin)
		return false;
	else {
		if (s == 'N') {
			bintree <int> arbol = leerArbol(-1);
			cout << minimo(arbol);
		}
		else {
			string c="#";
			bintree <string> arbol = leerArbol(c);
			cout <<minimo(arbol);
		}
		cout << endl;
		return true;
	}
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