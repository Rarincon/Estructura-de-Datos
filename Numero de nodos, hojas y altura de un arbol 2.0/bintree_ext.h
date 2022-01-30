
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
	int altura(Link r) {
		if (r==nullptr) {
			return 0;
		}
		else {
			return max(altura(r->left), altura(r->right)) + 1;
		}
	}


	int nodos(Link r) {
		if (r==nullptr) {
			return 0;
		}
		else {
			return (nodos(r->left) + nodos(r->right) + 1);
		}
	}

	int hojas(Link r) {
		if (r==nullptr)
			return 0;
		else if (r->left== nullptr && r->right== nullptr)
			return 1;
		else
			return hojas(r->left) + hojas(r->right);

	}
public :
	void calcula()
	{
		int a = altura(this->raiz);
		int n = nodos(this->raiz);
		int h = hojas(this->raiz);

		cout << n << " " << h << " " << a << endl;
	}
};


template <typename T >
inline bintree_ext <T> leerArbol_ext(T vacio) {
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