

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>

using namespace std;

using alumno = string;
using profesor = string;
using points = int;

/*
struct sol {
	string nombre;
	bool operator<(sol const& a) { return nombre < a.nombre; }
};

class LARA{
private:
	unordered_map<alumno,pair<points,pair<profesor,list<alumno>::iterator>>> A;
	unordered_map<profesor, list<alumno>> P;
public:
	LARA() {};

	void alta(alumno const& a, profesor const& p) {
		auto it = A.find(a);
		if (it == A.end()) {
			auto& it2 = A[a];
			it2.first = 0;
			it2.second.first = p;
			P[p].push_back(a);
			it2.second.second = --P[p].end();
		}
		else {
			P[it->second.second.first].erase(it->second.second.second);
			P[p].push_back(a);
			it->second.second.first = p;
			it->second.second.second = --P[p].end();
		}
	}
	bool es_alumno(alumno const& a, profesor const& p) {
		return A[a].second.first == p;
	}
	int puntuacion(alumno const& a) {
		auto it= A.find(a);
		if (it == A.end())throw domain_error("El alumno " + a + " no esta matriculado");
		return it->second.first;
	}
	void actualizar(alumno const& a, int const& p) {
		auto it = A.find(a);
		if (it == A.end())throw domain_error("El alumno " + a + " no esta matriculado");
		it->second.first += p;
	}
	vector<sol> examen(profesor const& p, int const& N) {
		vector<sol> a;
		sol b;
		for (auto it : P[p]) {
			if (A[it].first >= N) {
				b.nombre = it.data();
				a.push_back(b);
			}
		}
		sort(a.begin(), a.end());
		return a;
	}
	void aprobar(alumno const& a) {
		auto it = A.find(a);
		if (it == A.end())throw domain_error("El alumno " + a + " no esta matriculado");
		P[it->second.second.first].erase(it->second.second.second);
		A.erase(a);
	}
};*/

class LARA {
private:
	unordered_map<alumno, pair<points, profesor>> A;
	unordered_map<profesor, set<alumno>> P;
public:
	LARA() {};

	void alta(alumno const& a, profesor const& p) {
		auto it = A.find(a);
		if (it == A.end()) {
			auto& it2 = A[a];
			it2.first = 0;
			it2.second= p;
			P[p].insert(a);
		}
		else {
			P[it->second.second].erase(it->first);
			P[p].insert(a);
			it->second.second = p;
		}
	}
	bool es_alumno(alumno const& a, profesor const& p) {
		return A[a].second == p;
	}
	int puntuacion(alumno const& a) {
		auto it = A.find(a);
		if (it == A.end())throw domain_error("El alumno " + a + " no esta matriculado");
		return it->second.first;
	}
	void actualizar(alumno const& a, int const& p) {
		auto it = A.find(a);
		if (it == A.end())throw domain_error("El alumno " + a + " no esta matriculado");
		it->second.first += p;
	}
	set<alumno> examen(profesor const& p, int const& N) {
		set<alumno> a;
		for (auto it : P[p]) {
			if (A[it].first >= N) {
				a.insert(it.data());
			}
		}
		return a;
	}
	void aprobar(alumno const& a) {
		auto it = A.find(a);
		if (it == A.end())throw domain_error("El alumno " + a + " no esta matriculado");
		P[it->second.second].erase(it->first);
		A.erase(a);
	}
};


bool resuelveCaso() {
	LARA autoesc;
	string p,al,prof;
	int punt;
	bool ok;
	set<alumno> a;
	cin >> p;
	if (!cin)return false;
	while (p != "FIN") {
		try {
			if (p == "alta") {
				cin >> al>>prof;
				autoesc.alta(al,prof);
			}
			else if (p == "es_alumno") {
				cin >> al >> prof;
				ok=autoesc.es_alumno(al, prof);
				if (ok)cout << al << " es alumno de " << prof<<endl;
				else cout << al << " no es alumno de " << prof << endl;
			}
			else if (p == "puntuacion") {
				cin >> al ;
				punt=autoesc.puntuacion(al);
				cout << "Puntuacion de " << al << ": " << punt << endl;
			}
			else if (p == "actualizar") {
				cin >> al >> punt;
				autoesc.actualizar(al, punt);
			}
			else if (p == "aprobar") {
				cin >> al;
				autoesc.aprobar(al);
			}
			else if (p == "examen") {
				cin >> prof >> punt;
				a = autoesc.examen(prof, punt);
				cout << "Alumnos de " << prof << " a examen:\n";
				for (auto it : a)cout << it << endl;
			}
		}
		catch (domain_error & e) {
			cout << "ERROR\n";
			//cout << e.what() << endl;
		}
		cin >> p;
	}
	cout << "---" << endl;
	return true;
}


int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


	while (resuelveCaso());

	
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}