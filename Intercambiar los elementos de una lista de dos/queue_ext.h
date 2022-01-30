

#include "queue_eda.h"
#include<iostream>
using namespace std;

template <class T>
class Cambiar : public queue<T> {
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
		aux = this->prim;
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
	void intercambiar() {
		int camb = this->nelems / 2;
		int i = 0;
		Nodo* act;
		Nodo* seg;
		Nodo* aux;
		if (camb > 0) {
			act = this->prim;
			seg = act->sig;
			aux = act;
			while (i < camb) {
				if (i == 0) {
					this->prim = seg;
					act->sig = seg->sig;
					seg->sig = act;
				}
				else {
					aux->sig = seg;
					act->sig = seg->sig;
					seg->sig = act;
				}
				aux = act;
				act = act->sig;
				if (act != nullptr)
					seg = act->sig;
				i++;
			}
		}
		/*
		Nodo* act;
		Nodo* seg;
		T aux;
		if (this->prim != nullptr) {
			act = this->prim;
			seg = this->prim->sig;
			while (seg != nullptr && act != nullptr) {
				aux = act->elem;
				act->elem = seg->elem;
				seg->elem = aux;
				act = seg->sig;
				if(act!=nullptr)
					seg = act->sig;
			}
		}*/
	}
};