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

using pelicula = string;
using cantidad = int;
using actor = string;
using tiempo = int;


struct PELIS {
	int emsiones=0,pos;
	unordered_map<actor, tiempo> actors;
};

void resuelveCaso(int NPeliculas) {
	unordered_map<pelicula, PELIS> peliculas;
	map<actor, tiempo> actores;

	string P,AC;
	int A,T;

	for (int i = 0; i < NPeliculas; i++) {
		cin >> P >> A;
		auto& at= peliculas[P];
		for (int j = 0; j < A; j++) {
			cin >> AC >> T;
			actores[AC];
			auto& act = at.actors[AC];
			act = T;
		}
	}
	
	int CANT;
	cin >> CANT;
	for (int i = 1; i < CANT+1; i++) {
		cin >> P;
		auto &it = peliculas[P];
		it.emsiones++;
		it.pos = i;
		for (auto const& act1 : it.actors) {
			auto& act2 = actores[act1.first];
			act2 += act1.second;
		}
	}

	int TMAX = 0, EMAX = 0, pos=0;
	//vector<actor> AcPref;
	string PelFav;
	
	for (auto const& it : peliculas) {
		if (it.second.emsiones >= EMAX) {
			if (it.second.emsiones > EMAX) {
				pos = it.second.pos;
				PelFav = it.first;
			}
			else if(pos < it.second.pos){
				pos = it.second.pos;
				PelFav = it.first;
			}
			EMAX = it.second.emsiones;
		}
	}
	cout << EMAX << " " << PelFav << endl;
	for (auto const& it : actores) {
		if (it.second > TMAX)TMAX = it.second;
	}
	cout << TMAX << " ";
	for (auto const& it : actores) {
		if (it.second == TMAX)cout << it.first << " ";
	}
	cout << endl;
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
	while (n!=0) {
		resuelveCaso(n);
		cin>>n;
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