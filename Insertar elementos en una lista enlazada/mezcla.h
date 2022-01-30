
#include "queue_eda.h"
#include<iostream>
//#include<queue>
using namespace std;

template <class T>
class Mezcla : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(std::ostream& o = std::cout) const {
		Nodo *aux;
		aux = this->prim;
		while (aux != nullptr) {
			cout << aux->elem << " ";
			aux = aux->sig;
		}
		cout << endl;
	}

	void mezcla(Mezcla<T>& d, int n){
		if (n == 0) {
			d.ult->sig = this->prim;
			this->prim = d.prim;	
		}
		else {

			Nodo* act = this->prim;
			Nodo* aux_finD = d.ult;
			Nodo* aux = d.prim;
			int size = d.size();
			int i = 0;
			while (i < n - 1) {
				act = act->sig;
				i++;
			}
			Nodo* aux_sig = act->sig;
			aux_finD->sig = aux_sig;
			act->sig = aux;
		}
		d.prim = nullptr;
		d.ult = nullptr;
	}

};
