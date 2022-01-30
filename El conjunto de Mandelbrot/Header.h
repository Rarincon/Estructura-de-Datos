
#ifndef COMPLEJO
#define  COMPLEJO

#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>


using namespace std;

template <typename T >
class complejo {
	float real,ima;
	int num;

public:
	complejo() {};
	complejo(float uno, float dos, int cant) : real(uno), ima(dos), num(cant) {};
	void Mandelbrot(complejo e, int cont);

	int get_num() const { return num; }
	int get_real() const { return real; }
	int get_ima() const { return ima; }

	void set_real(float r) { real = r; }
	void set_ima(float i) { ima = i; }

	complejo& operator + (complejo const& other) {
		real = other.real + real;
		ima = other.ima + ima;
		return *this;
	}

	complejo& operator * (complejo const& other) {
		float r, i;
		r= (real * other.real) - (ima*other.ima);
		i = (real * other.ima) + (other.real * ima);
		real = r;
		ima = i;
		return *this;
	}
};

template <typename T>
void complejo<T>::Mandelbrot(complejo e, int cont) {
	if (cont < num) {
		if (cont == 0)
			Mandelbrot(e, cont + 1);
		else {
			e = e * e;
			e = e + *this;

			float m = (e.get_real() * e.get_real()) + (e.get_ima() * e.get_ima());
			m = sqrt(m);
			if (m <= 2)
				Mandelbrot(e, cont + 1);
			else
				cout << "NO" << endl;
		}

	}
	else {
		float m = (e.get_real() * e.get_real()) + (e.get_ima() * e.get_ima());
		m = sqrt(m);
		if (m <= 2)
			cout << "SI" << endl;
		else
			cout << "NO" << endl;
	}
}

#endif