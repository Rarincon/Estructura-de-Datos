

//
//  stack_eda.h
//
//  Implementaci�n del TAD pila con nodos enlazados
//  y punteros al primero y al �ltimo nodo
//
//  Estructuras de Datos y Algoritmos
//  Facultad de Inform�tica
//  Universidad Complutense de Madrid
//
//

#ifndef stack_eda_h
#define stack_eda_h

#include <stdexcept>  // std::domain_error

template <class T>
class stack {
protected:

	/*
	 Nodo que almacena internamente el elemento (de tipo T),
	 y un puntero al nodo siguiente, que puede ser nullptr si
	 el nodo es el �ltimo de la lista enlazada.
	 */
	struct Nodo {
		Nodo() : sig(nullptr) {}
		Nodo(T const& elem, Nodo* si = nullptr) : elem(elem), sig(si) {}
		T elem;
		Nodo* sig;
	};

	// punteros al primer y �ltimo elemento
	Nodo* prim;
	Nodo* ult;

	// n�mero de elementos en la pila
	int nelems;

public:

	// constructor: cola vac�a
	stack() : prim(nullptr), ult(nullptr), nelems(0) {}

	// destructor
	~stack() {
		libera();
	}

	// constructor por copia
	stack(stack<T> const& other) {
		copia(other);
	}

	// operador de asignaci�n
	stack<T>& operator=(stack<T> const& other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	// a�adir un elemento al final de la cola
	void push(T const& elem) {
		Nodo* nuevo = new Nodo(elem);

		if (ult != nullptr)
			ult->sig = nuevo;
		ult = nuevo;
		if (prim == nullptr) // la pila estaba vac�a
			prim = nuevo;
		++nelems;
	}

	// consultar el primero de la cola
	T const& top() const {
		if (empty())
			throw std::domain_error("la pila vacia no tiene primero");
		return prim+->elem;
	}

	// eliminar el primero de la cola
	void pop() {
		if (empty())
			throw std::domain_error("eliminando de una pila vacia");
		Nodo* a_borrar = prim;
		prim = prim->sig;
		if (prim == nullptr) // la pila se ha quedado vac�a
			ult = nullptr;
		delete a_borrar;
		--nelems;
	}

	// consultar si la pila est� vac�a
	bool empty() const {
		return nelems == 0;
	}

	// consultar el tama�o de la pila
	int size() const {
		return nelems;
	}

protected:

	void libera() {
		while (prim != nullptr) {
			Nodo* a_borrar = prim;
			prim = prim->sig;
			delete a_borrar;
		}
		ult = nullptr;
	}

	// this est� sin inicializar
	void copia(stack const& other) {
		if (other.empty()) {
			prim = ult = nullptr;
			nelems = 0;
		}
		else {
			Nodo* act = other.prim; // recorre la cola original
			Nodo* ant = new Nodo(act->elem); // �ltimo nodo copiado
			prim = ant;
			while (act->sig != nullptr) {
				act = act->sig;
				ant->sig = new Nodo(act->elem);
				ant = ant->sig;
			}
			ult = ant;
			nelems = other.nelems;
		}
	}
};

#endif 