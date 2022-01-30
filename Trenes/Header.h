
#ifndef HORAS
#define  HORAS

#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

class Horas {
private:
	int horas, min, seg;
public:
	Horas() {};
	Horas(int h, int m, int s): horas(h), min(m), seg(s) {
		if (h < 0 || h >= 24) throw std::invalid_argument("ERROR");
		else if (m < 0 || m >= 60) throw std::invalid_argument("ERROR");
		else if (s < 0 || s >= 60) throw std::invalid_argument("ERROR");
	}
	Horas& operator =(Horas const& other) { // operador de asignaci´on
		if (this != &other) {
			horas = other.horas; min = other.min; seg = other.seg;
		}
		return *this;
	}
	string hora() {
		return to_string(this->horas) + ":" + to_string(this->min) + ":" + to_string(this->seg);
	}
	int get_hora() const { return horas; }
	int get_min() const { return min; }
	int get_seg() const { return seg; }

	bool operator == (Horas const& hora) const {
		return horas == hora.horas && min == hora.min && seg == hora.seg;
	}
	bool operator <= (Horas const& h) const {
		return *this < h || *this == h;
	}
	bool operator < (Horas const& h) const {
		if (horas < h.horas)return true;
		else if (horas > h.horas)return false;
		else if (min < h.min)return true;
		else if (min > h.min)return false;
		else if (seg < h.seg)return true;
		else return false;
	}
};


inline std::ostream& operator << (std::ostream& out, Horas const& h) {
	if (h.get_hora() < 10)
		out << setfill('0')<<setw(2) << h.get_hora() << ":";
	else
		out << h.get_hora() << ":";
	if (h.get_min() < 10)
		out << setfill('0') << setw(2) << h.get_min() << ":";
	else
		out << h.get_min() << ":";
	if(h.get_seg()<10)
		out << setfill('0') << setw(2) << h.get_seg() << '\n';
	else
		out << h.get_seg() << '\n';
	
	return out;
}

inline std::istream& operator >> (std::istream& in, Horas& hora) {
	int h(2), m(2), s(2);
	in >> h;
	cin.ignore(1);
	in >> m;
	cin.ignore(1);
	in >> s;
	hora = Horas(h, m, s);
	return in;
}


inline int busqbin(const Horas h, const vector<Horas>v, int ini, int fin) {
	int pos;
	int m = (ini + fin) / 2;
	if (m >= v.size())throw std::invalid_argument("NO");
	if (ini == fin+1 )pos = ini;
	else {
		
		if (h <= v[m])
			pos=busqbin(h, v, ini, m-1);
		else {
			pos = busqbin(h, v, m + 1, fin);
		}
	}
	return pos;
}
#endif