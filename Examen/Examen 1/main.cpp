// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO

//La solucion del ejercicio consiste en ir enlzando los nodos de la lista principal con los nodos de la segunda lista, de forma que los elementos de
//la lista principal se queden con las posiciones pares, empezando el primero elemento con la posicion 0, posicicion par, que sera el primer elemento de 
//la lista principal. El segundo elemento de la nueva lista principal, sera el antiguo primer elemento de la otra lista, y tendra la primera posicion impar, y asi
//seguir de forma intercalada con el resto de elementos de la primera y segunda lista, de la forma, primera lista, segunda lista, primera lista, segunda lista...., y asi sucesivamente.
//Si la primera lista es vacio se colocara toda la segunda lista en esta, y si al ir recorriendo los elementos para colocarlos de forma intercalada 
//llegamos al final de la primera lista, se colocara los elementos restantes de la segunda lista a continucion del ultimo elemento de la primera lista.

//Coste:
//El coste del ejercico es N * M, siendo N el numero de elementos de la primera lista y M el numero de elementos de la segunda lista. Pues para entre mezclar las dos listas, 
//en el peor de los casos se recorren todos los nodos de ambas.


#include <iostream>                              
#include <fstream>               
#include <algorithm>
using namespace std;

#include "deque_eda.h"

class EntremezclarListas : public deque<int> {
	using Nodo = typename deque<int>::Nodo;
public:
	// imprime la lista
	void print(std::ostream& o = std::cout) const {
		Nodo* act=this->fantasma->sig;
		while (act != this->fantasma) { //Recorremos la lista mostrando por pantalla el valor de los nodos, de forma sucesiva.
			cout << act->elem << " ";
			act = act->sig;
		}
	}

	// modifica this para entremezclar sus elementos con los de other
	void entremezclar(EntremezclarListas& other) {
		Nodo* act1 = this->fantasma->sig; //Nodo para recorrer la primera lista
		Nodo* act2 = other.fantasma->sig; //Nodo para recorrer la segunda lista
		if (this->empty()) { //Pasamos todos los elementos de la segunda lista a la primera, si esta es vacia.
			this->fantasma->sig = other.fantasma->sig;
			other.fantasma->sig->ant = this->fantasma;
			this->fantasma->ant = other.fantasma->ant;
			other.fantasma->ant->sig = this->fantasma;
		}
		else if (!other.empty()) {
			while (act1 != this->fantasma && act2 != other.fantasma) {
				act2->ant->sig = act2->sig; //Conectamos el nodo fantasma de la segunda lista, con el segundo elemento de la segunda lista
				act2->sig->ant = act2->ant; //Conectamos el segundo elemento de la segunda lista, con el nodo fantasma de la segunda lista, de forma que el segundo elemento de la segunda lista pasa a ser el primero de la segunda lista
				other.nelems--;
				this->nelems++;
				act1->sig->ant = act2; //Enlazamos los punteros de los nodos, para poder insertar el nuevo nodo, el se la segunda lista, en la posicion querida
				act2->sig = act1->sig;
				act1->sig = act2;
				act2->ant = act1;
				act1 = act1->sig->sig; //Avanzamos el puntero del nodo de la primera lista, dos posiciones para adelante, pues la siguinte a la actual es el nuevo nodo introducido.
				act2 = other.fantasma->sig; //Colocamos el Nodo de la segunda lista en el nuevo primer elemento de la segunda lista
			}
			if (act2 != other.fantasma) { //Si la primera lista se ha recorrido hasta el final, pero la segunda no, se enlzan los nodos restantes de la segunda lista la final de la primera
				act1 = this->fantasma->ant;
				act1->sig = act2;
				act2->ant = act1;
				this->fantasma->ant = other.fantasma->ant;
				other.fantasma->ant->sig = this->fantasma;
				this->nelems += other.nelems;
			}		
		}
		other.nelems = 0;
		other.fantasma->sig = other.fantasma->ant = other.fantasma; //Se colocan los punteros de la segunda lista de fomar que no contenga ningun elemento.
		//Si se ha hecho correctamente el enlace de los punteros anteriores, esta instruccion se puede eliminar
	}
};


/////////////////////////////////////////////////////////
// de aquí hacia abajo NO se puede modificar nada

inline std::ostream& operator<<(std::ostream& o, EntremezclarListas const& a) {
	a.print(o);
	return o;
}

EntremezclarListas leerLista() {
	EntremezclarListas lista;
	int n, val;
	cin >> n; // tamaño
	while (n--) {
		cin >> val;
		lista.push_back(val);
	}
	return lista;
}

void resuelveCaso() {
	auto lista1 = leerLista();
	auto lista2 = leerLista();

	lista1.entremezclar(lista2);

	cout << lista1 << '\n';
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) {
		resuelveCaso();
	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	//  system("PAUSE");
#endif
	return 0;
}