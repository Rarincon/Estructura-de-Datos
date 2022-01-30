
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
	void frontera(Link r) {
		if (r!=nullptr) {
			if (r->left==nullptr && r->right==nullptr)
				cout << r->elem << " ";
			else {
				if (r->left != nullptr)
					frontera(r->left);
				if (r->right != nullptr)
					frontera(r->right);
			}
		}
	}

public:
	void frontera()
	{
		frontera(this->raiz);
		cout << endl;
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