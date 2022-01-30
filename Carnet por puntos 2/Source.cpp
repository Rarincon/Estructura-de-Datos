

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <list>
#include <vector>
#include <iterator>

using namespace std;

using DNI = string;
using puntos = int;
const int MAX_PUNTOS = 15;

class DGT {
private:
	unordered_map<DNI, pair<puntos,list<DNI>::iterator>> tab;
	vector<list<DNI>> pts;
public:
	DGT(): pts(MAX_PUNTOS+1) {};

	void nuevo(DNI const& a) {
		auto it = tab.find(a);
		if (it == tab.end()) {
			pts[MAX_PUNTOS].push_front(a);
			tab.insert({ a,{MAX_PUNTOS,pts[MAX_PUNTOS].begin()} });
		}
		else
			throw domain_error("Conductor duplicado");
	}
	void quitar(DNI const& a, int const& puntos) {
		auto it = tab.find(a);
		if (it == tab.end())
			throw domain_error("Conductor inexistente");
		else {
			if (it->second.first != 0) {
				pts[it->second.first].erase(it->second.second);
				if (it->second.first < puntos)it->second.first = 0;
				else it->second.first -= puntos;
				pts[it->second.first].push_front(a);
				it->second.second = pts[it->second.first].begin();
			}
		}
	}
	void recuperar(DNI const& a, int const& puntos) {
		auto it = tab.find(a);
		if (it == tab.end())
			throw domain_error("Conductor inexistente");
		else {
			if (it->second.first != MAX_PUNTOS) {
				pts[it->second.first].erase(it->second.second);
				it->second.first += puntos;
				if (it->second.first > MAX_PUNTOS)it->second.first = MAX_PUNTOS;
				pts[it->second.first].push_front(a);
				it->second.second = pts[it->second.first].begin();
			}
		}
	}
	int consultar(DNI const& a)const {
		auto it = tab.find(a);
		if (it == tab.end())
			throw domain_error("Conductor inexistente");
		else
			return it->second.first;
	}
	int cuantos_con_puntos(int const& puntos) {
		if (puntos > 15 || puntos < 0)
			throw domain_error("Puntos no validos");
		return pts[puntos].size();
	}
	list<DNI> lista_por_puntos(int const& puntos) {
		if (puntos > 15 || puntos < 0)
			throw domain_error("Puntos no validos");
 		return pts[puntos];
	}
};


bool resuelveCaso() {
	DGT dgt;
	string p, dni;
	int puntos, ptos;
	cin >> p;
	if (!cin)return false;
	while (p != "FIN") {
		try {
			if (p == "nuevo") {
				cin >> dni;
				dgt.nuevo(dni);
			}
			else if (p == "cuantos_con_puntos") {
				cin >> puntos;
				ptos = dgt.cuantos_con_puntos(puntos);
				cout << "Con " << puntos << " puntos hay " << ptos << endl;
			}
			else if (p == "quitar") {
				cin >> dni >> puntos;
				dgt.quitar(dni, puntos);
			}
			else if (p == "consultar") {
				cin >> dni;
				ptos = dgt.consultar(dni);
				cout << "Puntos de " << dni << ": " << ptos << endl;
			}
			else if (p == "lista_por_puntos") {
				cin >> puntos;
				list<DNI> a = dgt.lista_por_puntos(puntos);
				cout <<"Tienen " << puntos << " puntos: ";
				while (!a.empty()) {
					cout << a.front() <<" ";
					a.pop_front(); 
				}
				cout << endl;
			}
			else if (p == "recuperar") {
				cin >> dni >> puntos;
				dgt.recuperar(dni, puntos);
			}
		}
		catch (domain_error & e) {
			cout << "ERROR: " << e.what() << endl;
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