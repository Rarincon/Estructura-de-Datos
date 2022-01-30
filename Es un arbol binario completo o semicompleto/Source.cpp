
#include <iostream>
#include <math.h>
#include"bintree_eda.h"

using namespace std;


struct tSol {
	bool completo;
	bool semicompleto;
	int alt;
};

/*template <class T>
tSol completo(bintree<T> const& arbol, int nivel) {
	if (!arbol.empty()) {

	}
	else {

	}

}*/


template <class T>
tSol completo(bintree<T> const& arbol, int nivel) {
	if (!arbol.empty()) {
		//tSol act = { true,true, nivel };
		if (arbol.left().empty() && arbol.right().empty()) return{ true, true, nivel };
		else if (arbol.left().empty() && !arbol.right().empty()) { //Esto ya seria NADA
			return { false, falso, nivel };

			/*tSol dch = completo(arbol.right(), nivel + 1);
			if (dch.completo && dch.semicompleto) {
				if (dch.alt + 1 != nivel) return { false, false, nivel };
				else return { false,true,dch.alt };
			}
			else if (!dch.completo && dch.semicompleto) {
				if (dch.alt + 1 != nivel) return { false, false, nivel };
				else return{ false, true, dch.alt };
			}
			else {
				return { false, false, dch.alt };
			}*/
		}
		else if (!arbol.left().empty() && arbol.right().empty()) {
			tSol izq = completo(arbol.left(), nivel + 1);
			if (izq.completo && izq.semicompleto) {
				if (izq.alt + 1 != nivel) return { false, false, nivel };
				else return { false,true,izq.alt };
			}
			else if (!izq.completo && izq.semicompleto) {
				if (izq.alt + 1 != nivel) return { false, false, nivel };
				else return{ false, true, izq.alt };
			}
			else {
				return { false, false, izq.alt };
			}

		}
		else {
			tSol izq = completo(arbol.left(), nivel + 1);
			tSol dch = completo(arbol.right(), nivel + 1);
			if (izq.completo && dch.completo) {
				if(izq.alt==dch.alt) return { true,true, dch.alt };
				else if (/*izq.alt + 1 == dch.alt ||*/ dch.alt + 1 == izq.alt) {
					int alt = max(dch.alt, izq.alt);
					return{ false, true, alt };
				}
				else {
					int alt = max(dch.alt, izq.alt);
					return{ false, false, alt };
				}
			}
			else if(!izq.completo && !dch.completo &&  izq.semicompleto && dch.semicompleto) {
				int alt = max(dch.alt, izq.alt);
				return{ false,false, alt };
			}
			else if (izq.completo && dch.semicompleto && !dch.completo) {
				if (izq.alt == dch.alt + 1) return { false, true, dch.alt }; //|| dch.alt == izq.alt + 1) return { false, true, dch.alt };
				else return { false,false, dch.alt };
			}
			else if (dch.completo && izq.semicompleto && !izq.completo) {
				if (/*dch.alt == izq.alt + 1 || */izq.alt == dch.alt + 1) return { false, true, dch.alt };
				else return { false,false, izq.alt };
			}
			else {
				int alt = max(dch.alt, izq.alt);
				return { false, false, alt };
			}
		}
	}
	else return { false,false,nivel};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {

	bintree <char> arbol = leerArbol('.');
	tSol bin = completo(arbol,1);
	if (bin.completo)cout << "COMPLETO" << endl;
	else if (bin.semicompleto)cout << "SEMICOMPLETO" << endl;
	else cout << "NADA" << endl;
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