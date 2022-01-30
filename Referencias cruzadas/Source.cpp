

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

using palabra = string;


void resuelveCaso(int n) {
	map<palabra, vector<int>> ref;
	string frase;
	int i = 1;
	cin.ignore();
	while (i <= n) {
		getline(cin, frase);
		stringstream sfrase(frase);
		string p;
		while (sfrase >> p)
			if (p.size() > 2) {
				for (char& p2 : p) p2 = tolower(p2);
				vector<int> & aux = ref[p];
				if (aux.empty() || aux.back() != i)
					aux.push_back(i);
			}
		i++;
	}

	for (auto it : ref) {
		cout<< it.first;
		for (auto v : it.second)
			cout << " " << v;
		cout << endl;
	}
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
	int n;
	cin >> n;
	while (n != 0) {
		resuelveCaso(n);
		cin >> n;
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