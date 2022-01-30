

#include "deque_eda.h"
#include<iostream>

using namespace std;

template <class T>
class Mezcla : public deque<T> {
	using Nodo = typename deque<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(ostream& o = cout) const {
		if (this->fantasma->sig
			!= this->fantasma) {
			Nodo* act = this->fantasma->sig;
			while (act->sig != this->fantasma) {
				o << act->elem << " ";
				act = act->sig;
			}
			o << act->elem << endl;
		}
		else o << endl;
	}

	void mezcla(Mezcla<T>& d, int n) {
		Nodo* aux;
		Nodo* auxFD;
		Nodo* auxID;
		Nodo* act;
		int i = 0;
		if (n == 0) {
			aux = d.fantasma->ant;
			aux->sig = this->fantasma->sig;
			this->fantasma->sig = d.fantasma->sig;

		}
		else {
			act = this->fantasma->sig;
			auxFD = d.fantasma->ant;
			while (i < n - 1) {
				act = act->sig;
				i++;
			}
			aux = act->sig;
			auxFD->sig = aux;
			aux->ant = auxFD;
			auxID = d.fantasma->sig;
			act->sig = d.fantasma->sig;
			auxID->ant = act;
		}
		d.fantasma->sig = d.fantasma->ant = d.fantasma;
	}

};