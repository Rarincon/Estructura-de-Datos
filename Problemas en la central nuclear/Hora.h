
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

class Hora {
private:
	int hora, min, seg;
public:
	Hora() {};
	Hora(int h, int m, int s) : hora(h), min(m), seg(s) {};
	int getH() const { return hora; }
	int getM() const { return min; }
	int getS() const { return seg; }

	bool operator<(const Hora& a)const;
	//bool operator== (Hora const& a) const;
};


inline bool Hora:: operator<(const Hora& a) const {
	if (hora < a.hora) return true;
	if (hora > a.hora) return false;
	if (min < a.min) return true;
	if (seg < a.seg) return true;
	if (seg > a.seg) return false;
	return false;
}
/*
inline bool Hora:: operator==(const Hora& a) const {
	if (dia == a.dia)return true;
	else return false;
}*/

inline std::ostream& operator << (std::ostream& out, Hora const& h) {
	if (h.getH() < 10)
		out << setfill('0') << setw(2) << h.getH() << ":";
	else
		out << h.getH() << ":";
	if (h.getM() < 10)
		out << setfill('0') << setw(2) << h.getM() << ":";
	else
		out << h.getM() << ":";
	if (h.getS() < 10)
		out << setfill('0') << setw(2) << h.getS();
	else
		out << h.getS();
	return out;
}

inline std::istream& operator >> (std::istream& in, Hora& hora) {
	int h(2), m(2), s(2);
	in >> h;
	cin.ignore(1);
	in >> m;
	cin.ignore(1);
	in >> s;
	hora = Hora(h, m, s);
	return in;
}