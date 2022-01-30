
#ifndef Persona_h
#define Persona_h
#include<iostream>
#include <fstream>
#include<string>

class Persona {
	int age;
	std::string name;
public:
	Persona() {};//contructor vacio
	Persona(int a, std::string n) :age(a), name(n) {};
	//metodos que devuelven los datos
	int get_age()const { return age; }
	std::string get_name() const { return name; }

};

//metodo que lee
inline std::istream& operator>>(std::istream& in, Persona& per) {
	int aux;
	std::string z;
	char espacio;
	in >> aux;
	in.ignore();//para ajustar la salida al borde
	std::getline(in, z);
	per = Persona(aux, z);
	return in;
}
//metodo que escribe
inline std::ostream& operator<<(std::ostream& out, Persona const& per) {
	out << per.get_name();
	return out;
}
#endif