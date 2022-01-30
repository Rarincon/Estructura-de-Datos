

#include <iostream>
#include <fstream>
using namespace std;

#include "deque_eda.h"

class EngordarLista : public deque<int> {
	using Nodo = deque<int>::Nodo;
public:
	// imprime la lista enlazada

	void print(std::ostream& o = std::cout) const {
		if (this->fantasma->sig != this->fantasma) {
			Nodo* aux = this->fantasma->sig;
			while (aux != this->fantasma) {
				o << aux->elem << " ";
				aux = aux->sig;
			}

		}

	}

	// introduce los elementos de other (una lista enlazada)
	// en la lista representada por this alternativamente al principio y al final
	void engordar(EngordarLista& other) {
		// tu código aquí
		int i = 0;
		while (!other.empty()) {
			if (i == 0) {
				this->push_front(other.front());
				i = 1;
			}
			else {
				this->push_back(other.front());
				i = 0;
			}
			other.pop_front();
		}
		
		/*
		//Otra forma usando los nodos

		Nodo* aux;
		Nodo* aux_2;
		int i = 0;
		while (other.nelems > 0) {
			if (i % 2 == 0) {
				aux = other.fantasma->sig;
				aux_2 = aux->sig;
				this->fantasma->sig->ant = other.fantasma->sig;
				aux->sig = this->fantasma->sig;
				this->fantasma->sig = other.fantasma->sig;
				aux->ant = this->fantasma;
				other.fantasma->sig = aux_2;
				aux_2->ant = other.fantasma;

			}
			else {
				aux = other.fantasma->sig;
				aux_2 = aux->sig;
				this->fantasma->ant->sig = other.fantasma->sig;
				aux->ant = this->fantasma->ant;
				this->fantasma->ant = other.fantasma->sig;
				aux->sig = this->fantasma;
				other.fantasma->sig = aux_2;
				aux_2->ant = other.fantasma;
			}

			i++;
			other.nelems--;
			this->nelems++;
		}
		other.fantasma->sig = other.fantasma->ant = other.fantasma;
		*/
	}
};


inline std::ostream& operator<<(std::ostream& o, EngordarLista const& lista) {
	lista.print(o);
	return o;
}

EngordarLista leerLista() {
	EngordarLista lista;
	int n, val;
	std::cin >> n; // tamaño
	while (n--) {
		std::cin >> val;
		lista.push_back(val);
	}
	return lista;
}


void resuelveCaso() {
	auto lista1 = leerLista();
	auto lista2 = leerLista();
	lista1.engordar(lista2);
	std::cout << lista1 << '\n';
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
	/*
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	*/

	int casos;
	cin >> casos;
	while (casos--) {
		resuelveCaso();
	}
	/*
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/
	return 0;
}
