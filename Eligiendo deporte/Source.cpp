
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

using deporte = string;
using persona = string;
using cantidad = int;


bool resuelveCaso() {
	unordered_map<deporte, unordered_set<persona>> deps;
	unordered_map<persona, deporte> pers;

	string person, sport;
	cin >> sport;
	if (!cin)return false;

	deps.insert({ sport, {} });

	while (cin>> person , person != "_FIN_") {
		if (isupper(person[0]) ){
			sport = person;
			deps.insert({ sport,{}});
		}
		else {
			if (pers.count(person) == 0) {
				pers[person]=sport;

				auto& c = deps[sport];
				c.insert(person);
			}
			else {
				auto& d = pers[person];
				if (d != sport) {
					auto& m = deps[d];
					m.erase(person);
				}
			}
		}
	}

	vector<pair<deporte, cantidad>> resum;
	for (auto it : deps) 
		resum.push_back({ it.first, it.second.size()});

	sort(resum.begin(), resum.end(), [](pair<deporte, cantidad> const& a, pair<deporte, cantidad> const& b) {
		return((a.second > b.second) || (a.second == b.second && a.first < b.first));
		});
	
	for (auto & it : resum)
		cout << it.first << ' ' << it.second << endl;
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
#endif
*/
	
	while(resuelveCaso());
	

	/*
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
*/
	return 0;
}