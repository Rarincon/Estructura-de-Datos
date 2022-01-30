
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

	void mezcla(Mezcla<T>& s) {
		Nodo* act = this->prim;
		Nodo* actS = s.prim;
		Nodo* aux;
		if (this->empty()) {
			this->prim = s.prim;
		}
		else if (!s.empty()) {
			/*if (act->elem >= actS->elem) {
				s.prim = actS->sig;
				this->prim = actS;
				actS->sig = act;
				actS = s.prim;
				this->nelems++;
			}*/

			aux = act;

			while (act != nullptr && actS != nullptr) {
				if (act->elem == actS->elem) {
					s.prim = actS->sig;
					actS->sig = act->sig;
					act->sig = actS;
					aux = act;
					act = act->sig;
					actS = s.prim;
					this->nelems++;
				}
				else if (act->elem < actS->elem) {
					aux = act;
					act = act->sig;
					if (act == nullptr)
						this->ult = aux;
				}
				else {
					if (actS->elem < this->prim->elem) {
						s.prim = actS->sig;
						this->prim = actS;
						actS->sig = act;
						aux = actS;
						actS = s.prim;
						this->nelems++;
					}
					else {
						s.prim = actS->sig;
						aux->sig = actS;
						actS->sig = act;
						actS = s.prim;
						aux = aux->sig;
						this->nelems++;
					}
				}

			}
			if (actS != nullptr) {
				act = this->ult;
				act->sig = actS;
				this->ult = s.ult;
			}
			
			
			/*if (act->elem >= actS->elem) {
				s.prim = actS->sig;
				this->prim = actS;
				actS->sig = act;
				this->nelems++;
			}
			actS = s.prim;
			aux = act;
			//aux = nullptr;
			while (act != nullptr && actS != nullptr) {
				if (act->elem == actS->elem) {
					aux = act->sig;
					s.prim = actS->sig;
					actS->sig = aux;
					act->sig = actS;
					act = act->sig;
					//this->prim = actS;
					//actS->sig = act;
					this->nelems++;
					actS = s.prim;
					//actS = actS->sig;
				}
				else if (act->elem < actS->elem) {
					aux = act;
					act = act->sig;
				}
				else {
					s.prim = actS->sig;
					actS->sig = act;
					aux->sig = actS;
					aux = actS;
					aux = aux->sig; //Aqui hay un error
					actS = s.prim;
					this->nelems++;
				}
				//}
			}
			if (actS != nullptr) {
				act = this->ult;
				act->sig = actS;
				this->ult = s.ult;
			}
			*/
		}
		s.nelems = 0;
		s.prim = nullptr;
	}
};