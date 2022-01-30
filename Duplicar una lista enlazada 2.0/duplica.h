
#ifndef DEQUE_DUPLICA
#define DEQUE_DUPLICA

#include <iostream>
#include "Header.h"

using namespace std;

/*
template <typename T>
class dequed : public deque<T> {
	using Nodo = typename deque<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(ostream& o = cout) const {
		if (fantasma->sig != fantasma) {
			Nodo* act = fantasma->sig;
			while (act->sig != fantasma) {
				o << act->elem << " ";
				act = act->sig;
			}
			o << act->elem << endl;
		}
		else o << endl;
	}
	// duplicar los nodos de una lista enlazada simple
	void duplica() {
		if (fantasma->sig != fantasma) {
			Nodo* act = fantasma->sig;
			Nodo* aux = act->sig;
			while (act->sig != fantasma) {
				Nodo* nuevoNodo = new Nodo(act->elem, act, act->sig);
				aux->ant = nuevoNodo;
				act->sig = nuevoNodo;
				act = nuevoNodo->sig;
				this->nelems++;
			}
			/*
			Nodo* nuevoNodo = new Nodo(act->elem);
			act->sig = nuevoNodo;
			this->ult = nuevoNodo;
			this->nelems++;
		}
	}
};
*/
#endif


