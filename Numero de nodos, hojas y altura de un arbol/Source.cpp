

#include <iostream>
#include <math.h>
#include"bintree_eda.h"

using namespace std;


template <class T>
int altura(bintree<T> const& arbol) {
	if (arbol.empty()) {
		return 0;
	}
	else {
		return max(altura(arbol.left()), altura(arbol.right())) + 1;
	}
}


template <class T>
int nodos (bintree<T> const& arbol) {
	if (arbol.empty()) {
		return 0;
	}
	else {
		return (nodos(arbol.left()) + nodos(arbol.right()) + 1);
	}
}

template <class T>
int hojas(bintree<T> const& arbol) {
	if (arbol.empty()) 
		return 0;
	else if (arbol.left().empty() && arbol.right().empty())
		return 1;
	else 
		return hojas(arbol.left()) + hojas(arbol.right());
	
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {

	bintree <char > arbol = leerArbol('.');
	int a= altura(arbol);
	int n= nodos(arbol);
	int h = hojas(arbol);

	cout << n << " " << h << " " << a << endl;

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