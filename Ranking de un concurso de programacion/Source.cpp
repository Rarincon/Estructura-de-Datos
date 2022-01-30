

#include <iostream>
#include <vector>
#include <ctype.h>
#include <map>
#include <unordered_map>
#include<unordered_set>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

using equipo = string;
using resueltos = int;
//using time = int;
using problema = string;

struct problem {
	bool AC=false;
	int fallos=0;
};

struct tabla {
	int time=0, resueltos=0;
	unordered_map<problema, problem> tabP;
};

struct EQUIP {
	string nombre;
	int time,resueltos;
	bool operator<(EQUIP const& a) {
		return resueltos > a.resueltos || (resueltos == a.resueltos && time < a.time) || (resueltos == a.resueltos && time == a.time && nombre < a.nombre);
	}
};

void resuelveCaso() {
	unordered_map<equipo, tabla> Equipos;
	string equipo, problema, result;
	int tiempo;
	while (cin>>equipo && equipo != "FIN") {
		cin >> problema >> tiempo >> result;
		auto& t = Equipos[equipo];
		auto& p = t.tabP[problema];
		if (!p.AC) {
			if (result == "AC") {
				p.AC = true;
				t.resueltos++;
				t.time += tiempo + (p.fallos * 20);
			}
			else
				p.fallos++;
		}
	}

	vector<EQUIP> resultados;
	for (auto const &it1 : Equipos) 
		resultados.push_back({ it1.first, it1.second.time, it1.second.resueltos });
	
	sort(resultados.begin(), resultados.end());
	for (auto const& it : resultados)
		cout << it.nombre << " " << it.resueltos << " " << it.time << endl;
	cout << "---" << endl;
}


int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	/*
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
*/
	int n,i=0;
	cin >> n;
	cin.ignore();
	while (i < n) {
		resuelveCaso();
		i++;
	}

	/*
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
*/
	return 0;
}