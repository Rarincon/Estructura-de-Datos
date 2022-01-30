

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "bintree_eda.h"
template <class T>
class bintree_ext : public bintree<T> {
	using Link = typename bintree <T >::Link;
public:
	bintree_ext() : bintree <T >() {}
	bintree_ext(bintree_ext <T > const& l, T const& e, bintree_ext <T > const& r) : bintree <T >(l, e, r) {}

private:
	int diametro(Link r, int& dim) {
		if (r==nullptr)
			return 0;
		else {
			int dimR = dim, dimL = dim;
			int DIMR = diametro(r->right, dimR);
			int DIML = diametro(r->left, dimL);
			int DIMMAX = max(DIMR, DIML);
			int dimmax = max(DIMMAX, dimR + dimL);
			dim = max(dimR, dimL) + 1;
			return dimmax;
		}
	}

public:

	void diametro() {
		int dim = 0;
		if (!this->empty())
			dim = 1 + diametro(this->raiz, dim);
		cout << dim << endl;

	}
};


template <typename T >
inline bintree_ext <T > leerArbol_ext(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un arbol vacio
		return {};
	}
	else { // leer recursivamente los hijos
		bintree_ext <T > iz = leerArbol_ext(vacio);
		bintree_ext <T > dr = leerArbol_ext(vacio);
		return { iz , raiz , dr };
	}
}