#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

int resolver() {
	int raiz;
	cin >> raiz;
	if (raiz == 0) { // es un arbol vacio
		return 1;
	}
	else { // leer recursivamente los hijos
		int numNodos = 0;
		for (int i = 0; i < raiz; ++i)
			numNodos += resolver();
		return numNodos + 1;
	}
}


int altura() {
	int raiz;
	cin >> raiz;
	if (raiz == 0) {
		return 0;
	}

	else {
		int alt = 0;
		for (int i = 0; i < raiz; i++) {
			alt = max(alt, altura());
		}
		return alt + 1;
	}
}

void resuelveCaso() {
	cout << altura() + 1 << "\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta



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