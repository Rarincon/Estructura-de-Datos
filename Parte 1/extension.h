

#include "queue_eda.h"
#include "deque_eda.h"
#include "list_eda.h"
#include <iostream>
using namespace std;

template <class T>
class extensionQU : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
	//using Apuntado = typename list<T>::iterator;
public:
	int militar() {
		if (this->nelems == 0)
			return 0;
		int i = this->nelems - 1;
		Nodo* seg = this->prim;
		Nodo* prim = this->prim;
		while (seg->elem != 7 && seg != nullptr) {
			seg = seg->sig;
		}
		if (seg == nullptr)return -1;
		seg = seg->sig;
		if (seg == nullptr)return -1;
		while (prim->elem != 7 && seg != nullptr) {
			if (prim->elem != seg->elem)return -1;
			prim = prim->sig;
			seg = seg->sig;
		}
		if (prim->elem != 7 || seg != nullptr)return -1;
		else return i / 2;
	}
};

template <class T>
class extensionQ : public deque<T> {
	using Nodo = typename deque<T>::Nodo; // para poder usar Nodo aquí
	//using Apuntado = typename list<T>::Iterator;
public:
	int militar() {
		if (this->nelems == 0)
			return 0;
		int i = this->nelems-1;
		Nodo* seg=this->fantasma->sig;
		Nodo* prim = this->fantasma->sig;
		while (seg->elem != 7 && seg !=this->fantasma) {
			seg= seg->sig;
		}
		if (seg == this->fantasma)return -1;
		seg= seg->sig;
		if (seg == this->fantasma)return -1;
		while (prim->elem != 7 && seg != this->fantasma) {
			if (prim->elem != seg->elem)return -1;
			prim = prim->sig;
			seg = seg->sig;
		}
		if (prim->elem != 7 || seg != this->fantasma)return -1;
		else return i/2;
	}

	int solveCase() {
		int cont = 0;
		if (!this->empty()) {
			Nodo* act = this->fantasma->sig;
			Nodo* sig=act->sig;
			Nodo* aux=act->ant;
			while (sig != this->fantasma) {
				if (act->elem == sig->elem) {
					cont++;
					aux->sig = sig->sig;
					sig->sig->ant = aux;
					this->nelems -= 2;
					if (aux = this->fantasma) {
						if (this->nelems == 0)
							sig = this->fantasma;
						else {
							act = aux->sig;
							sig = act->sig;
						}
					}
					else {
						if(this->nelems == 0)
							sig = this->fantasma;
						else {
							aux = act;
							act = sig;
							sig = sig->sig;
						}
					}
				}
				else{
					aux = act;
					act = sig;
					sig = sig->sig;
				}
			}
		}
		return cont;
	}
};

template <class T>
class extension : public list<T> {
	using Nodo = typename list<T>::Nodo; // para poder usar Nodo aquí
	using Apuntado = typename list<T>::iterator;
public:

	//Mayo 2019
	void estremecer() {
		Nodo* act = this->fantasma->ant;
		Nodo* aux;
		int tam = this->size()-1;
		while (tam >= 0) {
			if (tam % 2 != 0) {
				aux = act->ant;
				act->ant->sig = act->sig;
				act->sig->ant = act->ant;
				act->sig = this->fantasma;
				this->fantasma->ant->sig = act;
				act->ant = this->fantasma->ant;
				this->fantasma->ant = act;
				act = aux;
			}
			else {
				act = act->ant;
			}
			tam--;
		}
	}

	void inserta(T elem, int pos) {
		auto it = this->begin();
		int i = 1;
		while (i < pos) {
			it++;
			i++;
		}
		this->insert(it, elem);
	}
	void mostrar(){
		auto it = this->begin();
		while (it != this->end()){
			cout << *it << " ";
			if(it != this->end())
				it++;
		}
		cout << endl;
	}

	//Junio 2018
	void invierte(int const& ini, int const& cant) {
		Nodo* act = this->fantasma->sig;
		Nodo* ult;
		Nodo* aux;
		Nodo* b;
		int i = 1;
		while (i < ini) {
			act = act->sig;
			i++;
		}
		if (ini+cant>this->size()+1) {
			ult = this->fantasma->ant;
			int n = this->size() - ini + 1;
			for (int j = 0; j < n / 2; j++) {
				if (act->sig == ult) {
					aux = act->ant;
					act->ant->sig = ult;
					ult->sig->ant = act;
					act->sig = ult->sig;
					act->ant = ult;
					ult->sig = act;
					ult->ant = aux;
				}
				else {
					act->ant->sig = ult;
					act->sig->ant = ult;
					ult->sig->ant = act;
					ult->ant->sig = act;
					b = ult->sig;
					ult->sig = act->sig;
					act->sig = b;
					b = ult->ant;
					ult->ant = act->ant;
					act->ant = b;
					//swap(ult->sig, act->sig);
					//swap(ult->ant, act->ant);
					aux = act;
					act = ult->sig;
					ult = aux->ant;
				}
			}
		}
		else {
			ult = act;
			int j = 1;
			while (j < cant) {
				ult = ult->sig;
				j++;
			}
			for (int p = 0; p < cant / 2; p++) {
				if (act->sig == ult) {
					aux = act->ant;
					act->ant->sig = ult;
					ult->sig->ant = act;
					act->sig = ult->sig;
					act->ant = ult;
					ult->sig = act;
					ult->ant = aux;
				}
				else {
					act->ant->sig = ult;
					act->sig->ant = ult;
					ult->sig->ant = act;
					ult->ant->sig = act;
					b = ult->sig;
					ult->sig = act->sig;
					act->sig = b;
					b = ult->ant;
					ult->ant = act->ant;
					act->ant = b;
					//swap(ult->sig, act->sig);
					//swap(ult->ant, act->ant);
					aux = act;
					act = ult->sig;
					ult = aux->ant;
				}
			}
		}
	}
};
