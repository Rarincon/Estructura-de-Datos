
#ifndef ListRemover_h
#define ListRemover_h
#include<iostream>
#include"list_eda.h"

template <class T>
class ListRemover : public list<T> {
	using Nodo = typename list<T>::Nodo;
public:
	template<class Predicate>
	void remove_if(Predicate pred) {
		if (this->nelems != 0) {
			Nodo* z = this->fantasma->sig, * a;
			while (z != this->fantasma) {
				if (!pred(z->elem)) {
					if (z->ant == this->fantasma) {
						this->pop_front();
						z = this->fantasma->sig;
					}
					else if (z->sig == this->fantasma) {
						z->ant->sig = this->fantasma;
						this->fantasma->ant = z->ant;
						a = z->sig;
						delete z;//borrar
						z = a;
						this->nelems--;

					}
					else {
						z->ant->sig = z->sig;
						z->sig->ant = z->ant;
						a = z->sig;
						delete z;//borrar
						z = a;
						this->nelems--;
					}
				}
				else {
					z = z->sig;//avanzar
				}
			}
		}
	}
	void print(ListRemover<T>& l) {
		for (int i = 0; i < l.size(); i++) {
			T aux = l.front();
			std::cout << aux << "\n";
			l.push_back(aux);
			l.pop_front();
		}
	}

};
#endif