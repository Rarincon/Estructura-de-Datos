


#include <iostream>
#include<vector>
#include <map>
#include<string>
#include "Hora.h"

using namespace std;

using aviso =string;
struct sol {
	bool ok=false;
	Hora h;
};

class Central {
private:
	map < aviso, vector<Hora>> tabla;
public:
	Central() {}
	void alta(aviso const& a, Hora const& h) {
		auto it= tabla.find(a);
		if (it == tabla.end())tabla.insert({ a, { h } });
		else it->second.push_back(h);
		
	}
	sol comprobar(aviso const& a,int const& pos) {
		auto it = tabla.find(a);
		if (it == tabla.end())return { false, Hora(0,0,0) };
		else if(it->second.size()<pos)return { false, Hora(0,0,0) };
		else {
			return { true,it->second.at(pos - 1) };
		}
	}
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	Central central;
	string aviso;
	sol sl;
	Hora h;
	int N, M, time;
	cin >> N;
	if (!cin)return false;
	cin >> M;
	for (int i = 0; i < N; i++) {
		cin >> aviso>>h;
		central.alta(aviso, h);
	}
	for (int i = 0; i < M; i++) {
		cin >> aviso >> time;
		sl=central.comprobar(aviso, time);
		if (!sl.ok)cout << "-- ";
		else cout << sl.h<<" ";
	}
	cout << endl;
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