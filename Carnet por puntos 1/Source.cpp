

#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

using DNI = string;
using puntos = int;


class DGT {
private:
	unordered_map<DNI, puntos> tab;
	unordered_map<puntos, int> pts;
	//int pts[16];
public:
	DGT() {
		//for (int i = 0; i < 16; i++) pts[i] = 0;
	};
	void nuevo(DNI const& a) {
		auto it = tab.find(a);
		if (it == tab.end()) {
			tab[a] = 15; 
			pts[15]++;
		}
		else
			throw domain_error("Conductor duplicado");
	}
	void quitar(DNI const& a, int const& puntos) {
		auto it = tab.find(a);
		if (it == tab.end())
			throw domain_error("Conductor inexistente");
		else {
			pts[it->second]--;
			if (it->second < puntos)it->second = 0;
			else it->second -= puntos;
			pts[it->second]++;
		}
	}
	int consultar(DNI const& a)const {
		auto it = tab.find(a);
		if (it == tab.end())
			throw domain_error("Conductor inexistente");
		else
			return it->second;
	}
	int  cuantos_con_puntos(int const& puntos){
		if (puntos > 15 || puntos < 0)
			throw domain_error("Puntos no validos");
		auto const& it = pts[puntos];
		return it;
		/*auto it = tab.cbegin();
		int cant = 0;
		while (it != tab.cend()) {
			if (it->second == puntos)
				cant++;
			it++;
		}
		return cant;*/
	}
};


bool resuelveCaso() {
	DGT dgt;
	string p,dni;
	int puntos,ptos;
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
				cout << "Con " << puntos << " puntos hay " << ptos<<endl;
			}
			else if (p == "quitar") {
				cin >> dni >> puntos;
				dgt.quitar(dni, puntos);
			}
			else if(p=="consultar"){
				cin >> dni;
				ptos = dgt.consultar(dni);
				cout << "Puntos de " << dni << ": " << ptos <<endl;
			}
		}
		catch(domain_error & e){
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
	/*
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif*/


	while (resuelveCaso());

	/*
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/

	return 0;
}