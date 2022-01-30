
// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO
/*
El ejercicio se resuelve con mapa sin orden, en el cual dentro tendra como clave un sector y como valor un pair, del  numero de plantas y otro mapa ordenado
por las plagas con el numero de plantas afectadas. Tambien hay que usar un set donde se guardaran aquellos sectores que tengan un plaga la cual afecte a un cuarto
o mas de las plantas del sector. La variable cont, es un parte extra para asi poder ordenar el set en el orden de entrada, pues voy a usar la funcion insert de este tipo
tanto para comprobar si ya esta en el set como para introducirlo en el caso de que no este.

Costes:
1. EL coste de la funcion de alta, tiene un coste constate, pues la creacion de un mapar sin orden tiene un coste constante al igual que todos sus metodos
2. El coste de datos, la operacion[] en el mapa con orden puede llegar a recorrer todo el arbol si no encuentra la clave en este, este tiene un coste de (log n), siendo n
el numero de claves que tiene el mapa. Ademas la operacion de insercion del set puede ser el caso peor de coste (log a) siendo a el numoro de elementos del set.
Por tanto el coste es el max(log n, log a).
3. El coste de fumigar es lineal respecto el numero de elementos que tenga el set, pues se recorre entero.
4. El coste es lineal respecto del numero de elementos que pose el mapa ordenado que se encuentra dentro del valor de una posicion determinada del unordered_map.
5. El coste de resuelve caso es de orden N en el peor de los casos, siendo N el tamaño de cualquiera de los dos vectores que recibe, pues tiene que recorrerlos enteros para
mostrar el resultado. Su coste sera en algun caso el mismo que el de algun metodo de la clase Farming.

El coste final del problema es el maximo del apartado 2, 3, y 4.
*/

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>
#include <set>


using namespace std;

using id = string;
using planta = int;
using plaga = string;

struct plag {
	string plaga;
	int plants;
};
struct fum {
	string pla, sec;
};

class Farming {
private:
	unordered_map<id, pair<planta,map<plaga,planta>>> sector;
	set<pair<int,pair<plaga,id>>> fumin;
	int cont = 0;
	//map<plaga,planta> plagas;
	//unordered_map<plaga, unordered_map<id, planta>> plagas;
	//unordered_map<id, planta> plagas;
public:
	Farming() {};

	void alta(id const& a, planta const& n) {
		auto& it = sector[a];
		it.first += n;
	}
	void datos(id const& a, plaga const& p, int const& n) {
		auto it = sector.find(a);
		if (it == sector.end())throw domain_error("Sector no existente");
		if (it->second.first < n)throw domain_error("Numero de plantas incorrecto");
		auto & it2= it->second.second[p];
		it2 += n;
		if (it2 > it->second.first)it2 = it->second.first;
		int cuarto = it->second.first / 4;
		if (it2 >= cuarto) {
			fumin.insert({ cont,{ p,a} });
			cont++;
		}
		//it2.a = fumin.end();
		/*auto &it2 = plagas[p];
		auto it3 = it2.find(a);
		if (it3 != it2.end()) {
			it3->second += n;
			if (it3->second > it->second.first)it3->second = it->second.first;
		}
		else {
			it2.insert({ a,n });
			it->second.second.insert(p);
		}*/
	}
	vector<fum> fumigar() {
		vector<fum> aux;	
		for (auto it : fumin) {
			aux.push_back({ it.second.first,it.second.second });
			sector[it.second.second].second[it.second.first] = 0;
		}
		cont = 0;
		fumin.clear();
		/*while (!fumin.empty()) {
		aux.push_back(fumin.);
		fumin.pop_back();
		}*/
		return aux;
	}
	vector<plag> plagas(id const& a) {
		auto it = sector.find(a);
		if (it == sector.end())throw domain_error("Sector no existente");
		vector<plag> aux;
		for (auto it2 : it->second.second)
			aux.push_back({ it2.first,it2.second });
		return aux;
	}
};


bool resuelveCaso() {
	Farming granja;
	string p,pl, id;
	vector<fum> f;
	vector<plag>v;
	int n;
	cin >> p;
	if (!cin)return false;
	while (p != "FIN") {
		try {
			if (p == "alta") {
				cin >> id >> n;
				granja.alta(id, n);
			}
			else if (p == "datos") {
				cin >> id >> pl >> n;
				granja.datos(id, pl, n);
			}
			else if (p == "fumigar") {
				f = granja.fumigar();
				for (int i = 0; i < f.size(); i++) {
					cout << "Fumigar la plaga " << f[i].pla << " del sector : " << f[i].sec << endl;
				}
			}
			else if (p == "plagas") {
				cin >> id;
				v = granja.plagas(id);
				cout << "Plagas del sector " << id << " : ";
				for (int i = 0; i < v.size(); i++) {
					cout << v[i].plaga << " " << v[i].plants << " ";
				}
				cout << endl;
			}
		}
		catch (domain_error & e) {
			cout <<"ERROR: "<< e.what() << endl;
		}
		cin >> p;
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