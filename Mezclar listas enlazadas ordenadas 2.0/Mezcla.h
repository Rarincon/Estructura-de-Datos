

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "deque_eda.h"
template <class T>
class Mezcla : public deque<T> {
	using Nodo = typename deque<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(std::ostream& o = std::cout) const {
		Nodo* act = this->fantasma->sig;
		while (act != this->fantasma) {
			o << act->elem << " ";
			act = act->sig;
		}
		o << endl;
	}

	void mezcla(Mezcla<T>& s) {
		Nodo* act = this->fantasma->sig;
		Nodo* actS = s.fantasma->sig;
		Nodo* aux;
		if (this->empty()) {
			this->fantasma->sig = s.fantasma->sig;
			s.fantasma->sig->ant = this->fantasma;
			this->fantasma->ant = s.fantasma->ant;
			s.fantasma->ant->sig = this->fantasma;
		}
		else if (!s.empty()) {

			aux = act;

			while (act != this->fantasma && actS != s.fantasma) {
				if (act->elem == actS->elem) {
					s.fantasma->sig = actS->sig;
					actS->ant = s.fantasma;

					actS->sig = act->sig;
					act->sig->ant = actS;
					act->sig = actS;
					actS->ant = act;
					aux = act;
					act = act->sig;
					actS = s.fantasma->sig;
					this->nelems++;
				}
				else if (act->elem < actS->elem) {
					aux = act;
					act = act->sig;
					if (act == this->fantasma) {
						this->fantasma->ant = aux;
						aux->sig = this->fantasma;
					}
				}
				else {
					if (actS->elem < this->fantasma->sig->elem) {
						s.fantasma->sig = actS->sig;
						actS->sig->ant = s.fantasma;

						this->fantasma->sig = actS;
						actS->ant = this->fantasma;

						actS->sig = act;
						act->ant = actS;

						aux = actS;
						actS = s.fantasma->sig;
						this->nelems++;
					}
					else {
						s.fantasma->sig = actS->sig;
						actS->sig->ant = s.fantasma;

						aux->sig = actS;
						actS->ant = aux;

						actS->sig = act;
						act->ant = actS;

						actS = s.fantasma->sig;
						aux = aux->sig;
						this->nelems++;
					}
				}

			}
			if (actS != s.fantasma) {
				act = this->fantasma->ant;
				act->sig = actS;
				actS->ant = act;
				this->fantasma->ant = s.fantasma->ant;
				s.fantasma->ant->sig = this->fantasma;
			}
		}
		s.nelems = 0;
		s.fantasma->sig=s.fantasma->ant=s.fantasma;
	}
};