

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <map>
#include <list>
#include <string>
#include <vector>
#include <iomanip>
#include "fecha.h"

using namespace std;

using medico = string;
using paciente = string;
using dia = int;

class consultorio{
private:
	unordered_map < medico, map<fecha,paciente>> tab;

public:
	consultorio() {};
	void nuevoMedico(medico const& a) {
		 tab.insert({ a,{} });
	}
	void pideConsulta(paciente const& p, medico const& m, fecha const& f) {
		auto it = tab.find(m);
		if (it == tab.end()) {
			throw domain_error("Medico no existente");
		}
		else {
			auto it2 = it->second.insert({ f,p });
			if (!it2.second)throw domain_error("Fecha ocupada");
		}
	}
	paciente const & siguientePaciente(medico const& m) const {
		auto it = tab.find(m);
		if (it == tab.end())
			throw domain_error("Medico no existente");
		else if (it->second.empty())
			throw domain_error("No hay pacientes");
		else
			return it->second.begin()->second;
	}
	void atiendeConsulta(medico const& m) {
		auto it = tab.find(m);
		if (it == tab.end())
			throw domain_error("Medico no existente");
		else if (it->second.empty())
			throw domain_error("No hay pacientes");
		else
			it->second.erase(it->second.begin());
	}
	vector<pair<paciente, fecha>> listaPacientes(medico const& m, dia const& d) {
		auto it = tab.find(m);
		if (it == tab.end())
			throw domain_error("Medico no existente");
		else {
			vector<pair < paciente, fecha>> a;
			fecha f(d, 0, 0);
			
			auto it2 = it->second.begin();
			while (it2 != it->second.end()) {
				if (it2->first == f) {
					pair<paciente, fecha> b(it2->second, it2->first);
					a.push_back(b);
				}
				++it2;
			}
			return a;
		}
	}
};


bool resuelveCaso() {
	consultorio consulta;
	string p, doc, pac;
	int i,d,h,m;
	cin >> i;
	if (!cin)return false;
	while (i >0) {
		cin >> p;
		try {
			if (p == "nuevoMedico") {
				cin >> doc;
				consulta.nuevoMedico(doc);
			}
			else if (p == "pideConsulta") {
				cin >> pac>>doc>>d>>h;
				cin.ignore();
				cin >> m;
				fecha fec(d, h, m);
				consulta.pideConsulta(pac, doc, fec);
			}
			else if (p == "siguientePaciente") {
				cin >>doc;
				pac = consulta.siguientePaciente(doc);
				cout << "Siguiente paciente doctor " << doc << endl;
				cout << pac << endl;
			}
			else if (p == "atiendeConsulta") {
				cin >> doc;
				consulta.atiendeConsulta(doc);
			}
			else if (p == "listaPacientes") {
				cin >> doc>>d;
				vector<pair<paciente,fecha>> a = consulta.listaPacientes(doc, d);
				cout << "Doctor " << doc << " dia " << d << endl;
				for (auto it : a)cout << it.first << " " << setfill('0') << setw(2) << it.second.getH() << ":" << setfill('0') << setw(2) << it.second.getM() << endl;
			}
		}
		catch (domain_error & e) {
			cout << e.what() << endl;
		}
		i--;
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