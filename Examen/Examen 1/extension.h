
#include "deque_eda.h"
#include "queue_eda.h"
#include <iostream>

using namespace std;

/*
template<class T>
class extension : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void mostrar() {
		Nodo* a=this->prim;
		while (a != nullptr) {
			cout << a->elem << " ";
			a = a->sig;
		}
		cout << endl;
	}
	void mezcla(extension<T>&a) {
		Nodo* act1= this->prim;
		Nodo* aux = this->prim;
		Nodo* act2= a.prim;
		if (this->empty()) {
			this->prim = a.prim;
		}
		else if (!a.empty()) {
			while (act1 != nullptr && act2 != nullptr) {
				if (act1->elem == act2->elem) {
					a.prim = act2->sig;
					act2->sig = act1->sig;
					act1->sig = act2;
					this->nelems++;
					a.nelems--;
					aux = act1;
					act1 = act2;
					act2 = a.prim;
					if (this->ult == aux)
						this->ult = act1;
				}
				else if (act1->elem < act2->elem) {
					aux = act1;
					act1 = act1->sig;
				}
				else {
					if (this->prim->elem > act2->elem) {
						a.prim = act2->sig;
						a.nelems--;
						this->nelems++;
						act2->sig = this->prim;
						this->prim = act2;
						aux = act2;
						act1 = aux->sig;
						act2 = a.prim;
					}
					else {
						a.prim = act2->sig;
						a.nelems--;
						this->nelems++;
						act2->sig = act1;
						aux->sig = act2;
						aux = aux->sig;
						act2 = a.prim;
					}
				}
			}
			if (act2 != nullptr) {
				act1 = this->ult;
				act1->sig = act2;
				this->ult = a.ult;
				this->nelems += a.nelems;
			}
		}
		a.nelems = 0;
		a.prim = a.ult = nullptr;
	}

	void invierte(){
		if (this->nelems > 1) {
			Nodo* act = this->prim;
			Nodo* aux = this->ult;
			this->prim = aux;
			this->ult = act;
			Nodo* sig = act->sig;
			aux = nullptr;
			while (act != this->prim) {
				act->sig = aux;
				aux = act;
				act = sig;
				sig = sig->sig;
			}
			act->sig = aux;
		}
	}

	void inserta(extension<T>& a, int const& p) {
		Nodo* act;
		Nodo* aux;
		if (this->empty()) {
			this->prim = a.prim;
			this->ult = a.ult;
			this->nelems = a.nelems;
		}
		else {
			if (p == 0) {
				act = this->prim;
				this->prim = a.prim;
				a.ult->sig = act;
				this->nelems += a.nelems;
			}
			else {
				act = this->prim;
				int i = 1;
				while (i < p) {
					act = act->sig;
					i++;
				}
				aux = act->sig;
				if (aux == nullptr) {
					this->ult = a.ult;
					act->sig = a.prim;
				}
				else {
					act->sig = a.prim;
					a.ult->sig = aux;
				}
				this->nelems += a.nelems;
			}
		}
		a.prim = a.ult = nullptr;
		a.nelems = 0;
	}
};*/


template<class T>
class extension : public deque<T> {
	using Nodo = typename deque<T>::Nodo;
public:
	void mostrar() {
		Nodo* a = this->fantasma->sig;
		while (a != this->fantasma) {
			cout << a->elem << " ";
			a = a->sig;
		}
		cout << endl;
	}
	void mezcla(extension<T>& a) {
		Nodo* act1 = this->fantasma->sig;
		Nodo* act2 = a.fantasma->sig;
		if (this->empty()) {
			this->fantasma->sig = a.fantasma->sig;
			a.fantasma->sig->ant = this->fantasma;
			this->fantasma->ant = a.fantasma->ant;
			a.fantasma->ant->sig = this->fantasma;
		}
		else if (!a.empty()) {
			while (act1 != this->fantasma && act2 != a.fantasma) {
				if (act1->elem == act2->elem) {
					act2->ant->sig = act2->sig;
					act2->sig->ant = act2->ant;
					a.nelems--;
					act1->sig->ant = act2;
					act2->sig = act1->sig;
					act2->ant = act1;
					act1->sig = act2;
					act1 = act2;
					act2 = a.fantasma->sig;
					this->nelems++;
				}
				else if (act1->elem < act2->elem) {
					act1 = act1->sig;
				}
				else {
					act2->ant->sig = act2->sig;
					act2->sig->ant = act2->ant;
					a.nelems--;
					act1->ant->sig = act2;
					act2->ant = act1->ant;
					act1->ant = act2;
					act2->sig = act1;
					this->nelems++;
					act2 = a.fantasma->sig;
				}
			}
			if (act2 != a.fantasma) {
				act1 = this->fantasma->ant;
				act1->sig = act2;
				act2->ant = act1;
				this->fantasma->ant = a.fantasma->ant;
				a.fantasma->ant->sig = this->fantasma;
				this->nelems += a.nelems;
			}
		}
		a.nelems = 0;
		a.fantasma->sig = a.fantasma->ant = a.fantasma;
	}

	void invierte() {
		Nodo* act = this->fantasma->sig;
		Nodo* aux;
		while (act != this->fantasma) {
			aux = act->sig;
			act->sig = act->ant;
			act->ant = aux;
			act = aux;
		}
		act = this->fantasma;
		aux = act->sig;
		act->sig = act->ant;
		act->ant = aux;
	}

	void inserta(extension<T>& a, int const& p) {
		Nodo* act = this->fantasma->sig;
		if (this->empty()) {
			this->fantasma->sig = a.fantasma->sig;
			a.fantasma->sig->ant = this->fantasma;
			this->fantasma->ant = a.fantasma->ant;
			a.fantasma->ant->sig = this->fantasma;
			this->nelems = a.nelems;
		}
		else {
			if (p == 0) {
				this->fantasma->sig->ant = a.fantasma->ant;
				a.fantasma->ant->sig = this->fantasma->sig;
				a.fantasma->sig->ant = this->fantasma;
				this->fantasma->sig = a.fantasma->sig;
			}
			else {
				int i = 1;
				while (i < p) {
					act = act->sig;
					i++;
				}
				a.fantasma->ant->sig = act->sig;
				act->sig->ant = a.fantasma->ant;
				act->sig = a.fantasma->sig;
				a.fantasma->sig->ant = act;
			}
			this->nelems += a.nelems;
		}
		a.fantasma->sig = a.fantasma->ant = a.fantasma;
		a.nelems = 0;
	}
};