

#include <iostream>
#include <string>
#include <math.h>
#include "bintree_eda.h"

using namespace std;

struct tSol3 {
	int salvo, caballeros;
};

tSol3 num_a_salvo(bintree<char>const& arbol, int M) {
	if (!arbol.empty()) {
		tSol3 sol = { 0, 0 }, dch, izq;
		int m = M;
		if (arbol.root() == 'M')m++;
		izq = num_a_salvo(arbol.left(), m);
		dch = num_a_salvo(arbol.right(), m);

		sol.caballeros += izq.caballeros + dch.caballeros;
		sol.salvo += izq.salvo + dch.salvo;
		if (arbol.root() == 'C')sol.caballeros++;
		else if (arbol.root() == 'D' && m <= sol.caballeros)sol.salvo++;
		return sol;
	}
	else
		return { 0, 0 };
}


int num_a_salvo(bintree<char>const& mapa) {
	return num_a_salvo(mapa, 0).salvo;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {

	//bintree <int> arbol = leerArbol(-1);
	bintree <char> arbol = leerArbol('.');
	//cout << agua(arbol).cont << endl;
	//cout << num_adivinos(arbol) << endl;
	cout << num_a_salvo(arbol) << endl;
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
#endif*/

	return 0;
}