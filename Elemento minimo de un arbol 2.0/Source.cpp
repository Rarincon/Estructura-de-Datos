


#include <iostream>
#include <math.h>
#include"bintree_ext.h"



using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	char s;
	cin >> s;
	if (!cin)
		return false;
	else {
		if (s == 'N') {
			bintree_ext <int> arbol = leerArbol_ext(-1);
			arbol.minimo();
		}
		else {
			string c = "#";
			bintree_ext <string> arbol = leerArbol_ext(c);
			arbol.minimo();
		}
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