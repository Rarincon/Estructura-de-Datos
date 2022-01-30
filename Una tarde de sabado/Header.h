
#ifndef HORAS
#define HORAS


#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

using namespace std;



class Horas {
private:
	int horas, min, seg;
	string pelicula;
public:
	Horas() {};
	Horas(int h, int m, int s) : horas(h), min(m), seg(s) {
		if (h < 0 || h >= 24) throw std::invalid_argument("ERROR");
		else if (m < 0 || m >= 60) throw std::invalid_argument("ERROR");
		else if (s < 0 || s >= 60) throw std::invalid_argument("ERROR");
	}

	string hora() {
		return to_string(this->horas) + ":" + to_string(this->min) + ":" + to_string(this->seg);
	}
	int get_hora() const { return horas; }
	int get_min() const { return min; }
	int get_seg() const { return seg; }
	string get_pel() const { return pelicula; }

	Horas& operator =(Horas const& other) { // operador de asignaci´on
		if (this != &other) {
			horas = other.horas; min = other.min; seg = other.seg; pelicula = other.pelicula;
		}
		return *this;
	}
	Horas& operator + (Horas const& other) {
		this->seg += other.get_seg();
		if (this->seg >= 60) {
			this->seg -= 60;
			this->min += other.get_min() + 1;
		}
		else
			this->min += other.get_min();
		if (this->min >= 60) {
			this->min -= 60;
			this->horas += other.get_hora() + 1;
		}
		else
			this->horas += other.get_hora();
		if(this->horas >= 24)
			throw std::invalid_argument("ERROR");
		return *this;
	
	}

	void set_pelicula(string p) {
		pelicula = p;
	}

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
		else if (seg > h.seg)return false;
		else if (pelicula < h.pelicula) return true;
		else
			return false;
	}
};


inline std::ostream& operator << (std::ostream& out, Horas const& h) {
	if (h.get_hora() < 10)
		out << setfill('0') << setw(2) << h.get_hora() << ":";
	else
		out << h.get_hora() << ":";
	if (h.get_min() < 10)
		out << setfill('0') << setw(2) << h.get_min() << ":";
	else
		out << h.get_min() << ":";
	if (h.get_seg() < 10)
		out << setfill('0') << setw(2) << h.get_seg();
	else
		out << h.get_seg();
	out <<" "<< h.get_pel();

	return out;
}

inline std::istream& operator >> (std::istream& in, Horas& hora) {
	int h, m, s;
	in >> h;
	cin.ignore(1);
	in >> m;
	cin.ignore(1);
	in >> s;
	hora = Horas(h, m, s);
	return in;
}

typedef struct {
	Horas hora;
	string pelicula;
}Lista;

inline void particion(vector<Horas>& v, int ini, int fin, int& p) {
	int i, j;
	//Lista aux;
	i = ini + 1;
	j = fin;
	while (i <= j) {
		if (v[ini]< v[i] && v[j] < v[ini]) {
			swap(v[i], v[j]);
			//aux = v[i];
			//v[i] = v[j];
			//v[j] = aux;
			i++;
			j--;

		}
		else{
			if (v[i] <= v[ini])
				i++;
			if (v[ini] <= v[j])
				j--;

			/*
			if (v[i].hora <= v[ini].hora) {
				if (v[i].hora == v[ini].hora) {
					if (v[i] < v[ini].pelicula)
						i++;
				}
				else
					i++;
			}
			if (v[ini].hora <= v[j].hora) {
				if (v[j].hora == v[ini].hora) {
					if (v[j].pelicula > v[ini].pelicula)
						j--;
				}
				else
					j--;
			}*/
		}
		
	}

	swap(v[ini], v[j]);
	p = j;
	/*
	p = j;
	aux = v[ini];
	v[ini] = v[p];
	v[p] = aux;*/
}

inline void ordena(vector<Horas>&v,int ini, int fin) {
	
	int p;
	if (ini <= fin) {
		particion(v, ini, fin, p);
		ordena(v, ini, p - 1);
		ordena(v, p + 1, fin);
	}
}


#endif

