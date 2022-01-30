
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "bintree_eda.h"

struct sol {
	int contador;
	int maxPares;
};

sol caminoPares(const bintree<int>& arbol) {
	sol izq, der;

	if (arbol.empty()) {
		return { 0,0 };
	}
	izq = caminoPares(arbol.left());
	der = caminoPares(arbol.right());
	int raiz = arbol.root();

	if (der.maxPares > izq.maxPares) { //Llevamos la cuenta del maximo de numeros pares consecutivos en el maxPares de izq
		izq.maxPares = der.maxPares;
	}

	if (raiz % 2 == 1) { //Si es impar cortamos la secuencia de numeros pares consecutivos y reiniciamos
		izq.contador = 0;
	}

	else { //si es par seguimos contando
		int consecutivos = izq.contador + der.contador; //Para unir los consecutivos del lado izq y der
		consecutivos += 1;
		if (consecutivos > izq.maxPares) {
			izq.maxPares = consecutivos;
		}

		if (der.contador > izq.contador) { //Comprobamos si la rama de la derecha tiene mayor numero de pares consecutivos
			izq.contador = der.contador;
		}
		izq.contador++; //Le sumamos uno a la cuenta ya que hay que contar ese numero par siguiente
	}
	return izq;
}

void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	cout << caminoPares(arbol).maxPares << '\n';
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
	system("PAUSE");
#endif
	return 0;
}