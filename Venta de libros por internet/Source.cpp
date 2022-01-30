


#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include <map>
#include <list>

using namespace std;

struct top {
	string libro;
	int cant=0, comp=0;
	bool operator<(top const& a) {
		return cant > a.cant || (cant == a.cant && comp > a.comp);
	}
};


using libro = string;
struct lib {
	int cant = 0;
	int vendidos = 0;
};


class Libreria {
private:
	unordered_map<libro, pair<lib, list<libro>::iterator>> bib;
	map<int, list<libro>>topten;
	//list<top> topten;
public:
	Libreria() {};

	void nuevoLibro(libro const& a, int const& cant) {
		auto& it = bib[a];
		it.first.cant += cant;
		it.second = topten[0].end();
	}
	void comprar(libro const& a) {
		auto it = bib.find(a);
		if (it != bib.end()) {
			if (it->second.first.cant == 0)throw out_of_range("No hay ejemplares");
			else {
				if (it->second.second != topten[it->second.first.vendidos].end()) {
					topten[it->second.first.vendidos].erase(it->second.second);
				}
				it->second.first.vendidos++;
				it->second.first.cant--;
				topten[it->second.first.vendidos].push_front({ it->first });
				it->second.second = topten[it->second.first.vendidos].begin();
			}
		}
		else throw  invalid_argument("Libro no existente");
	}
	bool estaLibro(libro const& a){
		auto it = bib.find(a);
		if (it == bib.end())return false;
		else return true;
	}
	void elimLibro(libro const& a) {
		bib.erase(a);
	}
	int numEjemplares(libro const& a) {
		auto it = bib.find(a);
		if (it == bib.end())throw invalid_argument("Libro no existente");
		else return it->second.first.cant;
	}
	vector<libro> top10() {
		vector<libro> sol;
		int i = 0;
		auto it = topten.rbegin();
		while( it != topten.rend()) {
			for (auto it2 : it->second) {
				sol.push_back(it2);
				i++;
				if (i == 10)break;
			}
			if (i == 10)break;
			it++;
		}
		return sol;
	}
};


bool resuelveCaso() {
	Libreria lib;
	string libr, accion;
	int cant,n,i=0;
	bool ok;
	vector<libro> a;
	cin >> n;
	if (!cin)return false;
	while (i<n) {
		cin >> accion;
		try {
			if (accion == "nuevoLibro") {
				cin >> cant;
				cin.ignore();
				getline(cin,libr);
				lib.nuevoLibro(libr, cant);
			}
			else if (accion == "comprar") {
				cin.ignore();
				getline(cin, libr);
				lib.comprar(libr);
			}
			else if (accion == "estaLibro") {
				cin.ignore();
				getline(cin, libr);
				ok = lib.estaLibro(libr);
				if (!ok)cout << "No existe el libro " << libr << "  en el sistema" << endl;
				else cout << "El libro " << libr << " esta en el sistema" << endl;
			}
			else if (accion == "elimLibro") {
				cin.ignore();
				getline(cin, libr);
				lib.elimLibro(libr);
			}
			else if (accion == "numEjemplares") {
				cin.ignore();
				getline(cin, libr);
				cant = lib.numEjemplares(libr);
				cout << "Existen " << cant << " ejemplares del libro " << libr << endl;
			}
			else if (accion == "top10") {
				a = lib.top10();
				cout << "TOP10" << endl;
				for (auto const& b : a) {
					cout << "    " << b << endl;
				}
			}
		}
		catch (out_of_range & e) {
			cout << e.what() << endl;
		}
		catch (invalid_argument & e) {
			cout << e.what() << endl;
		}
		i++;
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