

#ifndef POLINOMIO
#define POLINOMIO

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

typedef struct {
	int coef,lit;

}datos;

/*
template <typename T>
class polinomio {
public:
	set(); // constructor
	set(set <T> const& other); // constructor por copia
	set <T>& operator =(set <T> const& other); // operador de asignacion
	~set(); // destructor
	void insert(T e);
	bool contains(T e) const;
	void erase(T e);
	bool empty() const;
	size_t size() const;
private:
	size_t contador;
	size_t capacidad;
	T* datos; // sin repeticiones
	void amplia();
	void libera();
	void copia(set <T> const& other);
};
*/


class polinomio {
	int coef;
	int lit;
	

public:
	polinomio() {};
	polinomio(int c,int  l) : coef(c), lit(l) {};

	int get_coef() const { return coef; }
	int get_lit() const { return lit; }

};

inline void resultado(const vector<polinomio> p, int valor) {
	int r=0;
	for (int i = 0; i < p.size(); i++) {
		r += p[i].get_coef() * (pow(valor, p[i].get_lit()));
	}
	cout << r <<" ";
}


#endif