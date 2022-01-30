

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

	T minimo(Link r) {
		T min = r->elem;
		if (r->left == nullptr && r->right == nullptr)
			return min;
		else {
			if (r->left != nullptr && r->right != nullptr) {
				T minL = minimo(r->left);
				T minR = minimo(r->right);
				if (minL < minR) {
					if (minL < min)
						return minL;
					else return min;
				}
				else if (minR < min)return minR;
				else return min;
			}
			else if (r->right != nullptr) {
				T minR = minimo(r->right);
				if (minR < min)return minR;
				else return min;
			}
			else {
				T minL = minimo(r->left);
				if (minL < min)return minL;
				else return min;
			}
		}
	}

public:
	void minimo()
	{
		cout<< minimo(this->raiz);
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