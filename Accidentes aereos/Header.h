
#ifndef Aviones
#define Aviones


#include <stack>
#include <iostream>
using namespace std;


class aviones {
	string fecha;
	int num;

public:
	aviones() {};
	aviones(string f, int a) : fecha(f), num(a) {};

	int get_ac() const { return this->num; }
	string get_f()const { return fecha; }

};

inline std::ostream& operator << (std::ostream& out, aviones const& a) {
	out << a.get_f() << endl;
	return out;
}

inline std::istream& operator >> (std::istream& in, aviones& a) {
	string f;
	int n;
	in >> f >> n;
	a = aviones(f, n);
	return in;
}
#endif // !Aviones