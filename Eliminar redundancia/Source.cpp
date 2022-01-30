

#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <vector>

//-1 4 5 -5 0 0 9 8 23 -100 4 8 5 1 -1 0 4 4 9 8

using namespace std;

using numero = signed int;
using cantidad = int;

struct NUM {
	int cantidad = 0, pos;
};

struct SOL {
	int num, cantidad, pos;
	bool operator < (SOL const& a) {
		return pos < a.pos;
	}
};

bool resuelveCaso() {
	int n,pos=1;
	signed int num;
	cin >> n;
	if (!cin)return false;
	map<numero, NUM> numeros;

	for (int i = 0; i < n; i++) {
		cin >> num;
		auto& valor = numeros[num];
		valor.cantidad++;
		if (valor.cantidad == 1) {
			valor.pos = pos;
			pos++;
		}
	}
	vector<SOL>sol;
	for (auto const& it : numeros) 
		sol.push_back({ it.first,it.second.cantidad, it.second.pos });
	
	sort(sol.begin(), sol.end());

	for (auto const& it : sol)
		cout << it.num << " " << it.cantidad << endl;
	cout << "---" << endl;
	return true;
}

/*
bool resuelveCaso() {
	int n;
	signed int num;
	cin >> n;
	if (!cin)return false;
	unordered_map<numero, cantidad> numeros;
	for (int i = 0; i < n; i++) {
		cin >> num;
		auto& valor = numeros[num];
		valor++;
	}
	for (auto const& it : numeros)
		cout << it.first << " " << it.second << endl;
	cout << "---" << endl;
	return true;
}*/


int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	/*
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
*/

	while (resuelveCaso());

	/*
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
*/
	return 0;
}