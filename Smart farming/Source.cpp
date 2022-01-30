

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <map>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>

using namespace std;

using sector = string;
using plaga = string;

class Granja {
private:
	unordered_map<sector, set<plaga>>A;//map<plaga, signed int>//list<sector>::iterator>> A; //Por si queremos eliminar todas las plagas de un sector
	unordered_map<plaga, list<sector>> P;
public:
	Granja() {};

	void alta(sector const& a) {
		auto it = A.find(a);
		if (it == A.end()) {
			A.insert({ a, {} });
		}
	}
	void datos(sector const& a, plaga const& p) {
		auto it = A.find(a);
		if (it == A.end())throw domain_error("Sector no existente");	
		
		auto it3 = it->second.find(p);
		if (it3 != it->second.end())throw domain_error("Plaga repetida");
		else 
			it->second.insert({ p,{} });
		auto it2 = P.find(p);
		if (it2 == P.end()){
			P.insert({ p, { a } });
			//auto it4 = it->second.find(p);
			//auto it5= P.find(p);
			//it4->second = it5->second.begin();
		}
		else {
			it2->second.push_back(a);
			//auto it4 = it->second.find(p);
			//it4->second = it2->second.begin();
		}
	}
	vector<sector> fumigar(plaga const& p) {
		auto it = P.find(p);
		if (it == P.end())throw domain_error("Plaga no existente");
		vector<sector> sol;
		for (auto a : it->second) {
			auto it2 = A.find(a);
			it2->second.erase(p);
			sol.push_back(it2->first);
		}
		//it->second.clear();
		P.erase(p);
		/*while(!it->second.empty()){
			sol.push_back(it->second.back());
			auto it2 = A.find(it->second.back());
			it2->second.erase(p);
			it->second.pop_back();
		}*/
		return sol;
	}
	vector<plaga> plagas(sector const& a) {
		auto it = A.find(a);
		if (it == A.end())throw domain_error("Sector no existente");
		vector<plaga>sol;
		for (auto a : it->second) {
			sol.push_back(a);
		}
		return sol;
	}
};



bool resuelveCaso() {
	Granja granja;
	string id,plag,comand;
	vector<string> a;
	cin >> comand;
	if (!cin)return false;
	while (comand != "FIN") {
		try {
			if (comand == "alta") {
				cin >> id;
				granja.alta(id);
			}
			else if (comand == "datos") {
				cin >> id >> plag;
				granja.datos(id, plag);
			}
			else if (comand == "fumigar") {
				cin >> plag;
				a = granja.fumigar(plag);
				cout << "Fumigar la plaga " << plag << " en los sectores : ";
				for (auto b : a)cout << b << " ";
				cout << endl;
			}
			else if (comand == "plagas") {
				cin >> id;
				a=granja.plagas(id);
				cout << "Plagas del sector " << id << " : ";
				for (auto b : a)cout << b << " ";
				cout << endl;
			}
		}
		catch (domain_error & e) {
			cout << "ERROR: "<<e.what()<<endl;
		}
		cin >> comand;
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