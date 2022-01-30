

#include "queue_eda.h"
#include<iostream>
using namespace std;

template <class T>
class ListaDuplica : public queue<T> {
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
	void duplica() {
		if (this->prim != nullptr) {
			Nodo* act = this->prim;
			while (act != nullptr) {
				T elem = act->elem;
				Nodo* nuevo = new Nodo(elem);
				nuevo->sig = act->sig;
				act->sig = nuevo;
				act = nuevo->sig;
				this->nelems++;
			}
		}

	}
};
