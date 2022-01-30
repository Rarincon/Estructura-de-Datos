
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;


using capitulo = int;
struct tSol { int cont; };

class capitulos {
private:
	std::map < capitulo, signed int > tabla;
public:
	capitulos() {}
	void anade(capitulo const& a) { // O( log A)
		++tabla[a];
	}
	void borrar(capitulo const& a) { // O( log A)
		tabla.erase(a);
	}
	signed int cantidad(capitulo const& a) const { // O(log A)
		auto it = tabla.find(a);
		if (it == tabla.end())
			return 0;
		else
			return it->second;
	}
	bool count(capitulo const& a) const {
		if (cantidad(a) > 0)return false;
		else return true;
	}

	int operator[] (capitulo const & a) {
		return tabla[a];
	}
	/*bool count(capitulo const& a)const {
		auto it = tabla.find(a);
		if (tabla.find(a)) return true;
		else return false;
	}*/

	/*signed int repetidos() const { // O(A)
		int cont = 0;
		for (auto const& par : tabla) {
			if (par.second > 1) {
				cont++;
			}
		}
		return cont;
	}*/
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
	//capitulos cap;
	map<int, int> cap;
	int c, valor;
	int cont = 0,aux=1;
	cin >> c;
	for (int i =1; i <= c; i++) {
		cin >> valor;
		int & donde = cap[valor];
		if (donde >= aux)
			aux = donde + 1;
		cont = max(cont, i - aux + 1);
		cap[valor] = i;
		//cap.anade(valor);
	}
	cout << cont << endl;
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
	for(int i=0;i<n;i++)
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