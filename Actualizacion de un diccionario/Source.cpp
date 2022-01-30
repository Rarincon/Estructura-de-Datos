#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

using cadena = string;
using numero = int;

/*
class clave_valor {
	string cad, num;
public:
	clave_valor(cadena const& c, numero const& v) : cad(c), num(v) {};
	clave_valor() {};
	string getCad()const { return cad; }
	string getNum()const { return num; }
};

using cv = clave_valor;*/

void resuelveCaso() {
	map<cadena, numero> dic,dic2;
	int* valor;
	string conj,conj2;
	getline(cin, conj);
	stringstream sconj(conj);
	string c;
	int v;
	while (sconj >> c >> v) {
		//dic[c] =v;
		valor = &dic[c];
		*valor = v;
	}
	getline(cin, conj2);
	stringstream sconj2(conj2);
	while (sconj2 >> c >> v) {
		//dic[c] =v;
		valor = &dic2[c];
		*valor = v;
	}
	vector<string>add, erase, change;
	
	auto it = dic.cbegin();
	auto it2 = dic2.cbegin();

	while (it != dic.cend()) {
		if (dic2.count((*it).first) == 0)
			erase.push_back((*it).first);
		it++;
	}
	while (it2 != dic2.cend()) {
		if (dic.count((*it2).first) == 1) {
			if (dic.at((*it2).first) != (*it2).second)
				change.push_back((*it2).first);
		}
		else
			add.push_back((*it2).first);
		it2++;
	}

	if (add.empty() && erase.empty() && change.empty()) 
		cout << "Sin cambios" << endl;
	else {
		if (!add.empty()) {
			cout << "+ ";
			for (int i = 0; i < add.size(); i++)
				cout << add.at(i) << " ";
			cout << endl;
		}
		if (!erase.empty()) {
			cout << "- ";
			for (int i = 0; i < erase.size(); i++)
				cout << erase.at(i)<<" ";
			cout << endl;
		}
		if (!change.empty()) {
			cout << "* ";
			for (int i = 0; i < change.size(); i++)
				cout << change.at(i)<<" ";
			cout << endl;
		}
	}
	cout << "---"<<endl;
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
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
		resuelveCaso();


	/*
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
*/
	return 0;
}