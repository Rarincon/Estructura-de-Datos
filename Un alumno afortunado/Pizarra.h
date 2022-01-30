

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "queue_eda.h"
template <class T>
class Mezcla : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(std::ostream& o = std::cout) const {
		Nodo* act = this->prim;
		while (act != nullptr) {
			o << act->elem << " ";
			act = act->sig;
		}
		o << endl;
	}

	void pizarra(int n) {
		Nodo* aux;
		int i = 0;
		while (this->size() > 1) {
			if (i == n) {
				this->pop();
				i = 0;
			}
			else {
				aux = this->prim;
				this->prim = aux->sig;
				this->ult->sig = aux;
				this->ult = aux;
				aux->sig = nullptr;
				i++;

				/*
				int m = this->prim->elem;
				this->pop();
				this->push(m);
				i++;
				*/
			}

		}


	}
};