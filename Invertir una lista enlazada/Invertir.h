

#include "Header.h"
#include<iostream>
using namespace std;

template <class T>
class Invertir : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(std::ostream& o = std::cout) const {
		Nodo* aux;
		aux = this->prim;
		while (aux != nullptr) {
			cout << aux->elem << " ";
			aux = aux->sig;
		}
		cout << endl;
	}

	void mostrar() {
		Nodo* aux;
		aux = this->ult;
		while (aux != nullptr) {
			cout << aux->elem << " ";
			aux = aux->sig;
		}
		cout << endl;
	}

	void invertir() {
		int i = this->nelems;
		Nodo* act;
		Nodo* seg;
		Nodo* aux;
		if (this->prim != nullptr) {
			act = this->prim;
			seg = this->prim->sig;
			while (seg != nullptr) {
				aux = seg->sig;
				seg->sig = act;
				act = seg;
				seg = aux;
			}
			this->prim->sig = nullptr;
		}
	}
};