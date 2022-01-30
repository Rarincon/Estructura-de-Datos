
#include <iostream>
#include <string>

class fecha {
private:
	int dia, hora, min;
public:
	fecha(int d, int h, int m) : dia(d), hora(h), min(m) {};
	int getH() { return hora; }
	int getM() { return min; }
	int getD() { return dia; }
	
	bool operator<(const fecha& a)const;
	bool operator== (fecha const& a) const;
};


inline bool fecha:: operator<(const fecha& a) const {
	if (dia < a.dia) return true;
	if (dia > a.dia) return false;
	if (hora < a.hora) return true;
	if (hora > a.hora) return false;
	if (min < a.min) return true;
	return false;
}

inline bool fecha:: operator==(const fecha& a) const {
	if (dia == a.dia)return true;
	else return false;
}