

#include <iostream>
#include"bintree_eda.h"

using namespace std;

template <class T>
int diametro(bintree<T> const& arbol, int& dim) {
	if (arbol.empty())
		return 0;
	else {
		int dimR = dim, dimL = dim;
		int DIMR = diametro(arbol.right(), dimR);
		int DIML = diametro(arbol.left(), dimL);
		int DIMMAX = max(DIMR, DIML);
		int dimmax = max(DIMMAX, dimR + dimL);
		dim = max(dimR, dimL)+1;
		return dimmax;
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	int dim = 0;
	if(!arbol.empty())
		dim=1+diametro(arbol, dim);
	cout << dim << endl;
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
	for(int i=0;i<n;i++)
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


/*
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
tSol struct {
	int alt, dim;
};


int diametro(bintree<char> const& arbol,int alt, int& dim) {        //       O(n^2)
	if (arbol.empty())return 0;
	else {
		int AD = alt, AI=alt;


		int DimI = dim;
		int DimD = dim;
		int Dch = diametro(arbol.right(),AD, DimD);
		int Izq = diametro(arbol.left(),AI, DimI);
		int Alt = max(AD,AI)+ 1;
		dim = max(DimD, DimI);
		if (Dch > Izq) {
			if (Dch > Alt)return Dch;
			else
				return dim;
		}
		else {
			if (Izq > Alt)return dim;
			else return dim;
		}
	}
}

int diametro(bintree<char> const& arbol) {        //       O(n^2)
	if (arbol.empty())
		return 0;
	else {
		if (arbol.left().empty() && arbol.right().empty())
			return 1;
		else {

			int maxAltura = altura(arbol.left()) + altura(arbol.right()) + 1;

			int ldiametro = diametro(arbol.left());
			int rdiametro = diametro(arbol.right());

			if (ldiametro > rdiametro) {
				if (ldiametro > maxAltura)return ldiametro;
				else return maxAltura;
			}
			else {
				if (rdiametro > maxAltura)return rdiametro;
				else return maxAltura;
			}
		}
	}
}*/