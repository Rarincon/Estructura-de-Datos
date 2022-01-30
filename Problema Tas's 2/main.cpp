


#include <iostream>
#include <fstream>
#include <unordered_map>
#include <list>
#include <iterator>
#include <algorithm>
#include <map>



using namespace std;

using ecosistema = string; //nombre del ecosistema
using especie = string; //nombre del animal
using cantidad = int;

class Parque {
private:
	unordered_map<ecosistema, pair<map<especie, cantidad>, list<especie>>>parque;
	map<especie, cantidad> animales;

public:
	Parque() {};//es ela funion crea

	string an_ecosistema(ecosistema const& e) {
		auto it = parque.find(e);
		if (it != parque.end())return "EEcositemaDuplicado";
		parque[e].first.insert({});
		return "OK";
	}
	string an_ejemplares(ecosistema const& e, especie const& a, int const& cant) {
		auto it = parque.find(e);
		if (it == parque.end())return "EEcosistemaNoExiste";
		auto it2 = it->second.first.find(e);
		if (it2== it->second.first.end()) {
			it->second.first[a] += cant;
			it->second.second.push_front(a);
		}
		else {
			it2->second += cant;
		}
		animales[a]+=cant;
		return "OK";
	}
	list<especie> lista_especies_ecosistema(ecosistema const& e, int const& cant) {
		list<especie>aux;
		auto it = parque.find(e);
		if (it == parque.end())throw domain_error("EEcosistemaNoExiste");
		int i = 0;
		auto it2 = it->second.second.begin();
		while (i < cant && it2 != it->second.second.end()) {
			aux.push_back(it2->data());
			i++;
			it2++;
		}
		return aux;
	}
	int numero_ejemplares_en_ecosistema(ecosistema const& e, especie const& a) const{
		auto it = parque.find(e);
		if (it == parque.end())throw domain_error("EEcosistemaNoExiste");
		auto it2= it->second.first.find(a);
		if (it2 == it->second.first.end())return 0;
		else return it2->second;
	}
	list<especie> lista_especies_parque()const {
		list<especie> l;
		for (auto it : animales)l.push_back(it.first);
		return l;
	}
	int numero_ejemplares_en_parque(especie const& e) {
		auto it = animales.find(e);
		if (it == animales.end())return 0;
		else return it->second;
	}
};


void resuelveCaso() {
	Parque park;
	string p,e,a,sol;
	int n;
	list<especie> l;
	//cin >> p;
	//if (!cin)return false;
	while (cin>>p) {
		try {
			if (p == "crea") {

			}
			else if (p == "an_ecosistema") {
				cin>>e;
				sol=park.an_ecosistema(e);
				cout << "an_ecosistema "<<e<< " => " << sol << endl;
			}
			else if (p == "an_ejemplares") {
				cin >> e >> a >> n;
				sol=park.an_ejemplares(e,a,n);
				cout << "an_ejemplares " << e <<" "<<a<<" "<<n<<" => " << sol << endl;
			}
			else if (p == "lista_especies_ecosistema") {
				cin >> e >> n;
				l=park.lista_especies_ecosistema(e, n);
				cout << "lista_especies_ecosistema " << e << " " << n << " => ";
				for (auto it : l)cout << it << " ";
				cout << endl;
			}
			else if (p == "numero_ejemplares_en_ecosistema") {
				cin >> e >> a;
				n=park.numero_ejemplares_en_ecosistema(e, a);
				cout << "numero_ejemplares_en_ecosistema " << e << " " << a << " => " << n<<endl;
			}
			else if (p == "lista_especies_parque") {
				l = park.lista_especies_parque();
				cout << "lista_especies_parque => ";
				for (auto it : l)cout << it << " ";
				cout << endl;
			}
			else if (p == "numero_ejemplares_en_parque") {
				cin >> a;
				n = park.numero_ejemplares_en_parque(a);
				cout << "numero_ejemplares_en_parque " << a << " => " << n << endl;
			}
		}
		catch (domain_error & e) {
			cout << "ERROR: " << e.what() << endl;
		}
		//cin >> p;
	}
	//cout << "---" << endl;
}


int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


	resuelveCaso();

	
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}