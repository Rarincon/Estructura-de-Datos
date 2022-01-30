

#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
using namespace std;
//#include "Pizarra.h"

// funcion que resuelve el problema
/*TipoSolucion resolver(TipoDatos datos) {


}*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	int p, s;
	// leer los datos de la entrada
	cin >> p>> s;
	if (p==0 && s==0)
		return false;
	else {
		queue<int> a;
		int i = 1;
		while (i < p + 1) {
			a.push(i);
			i++;
		}
		i = 0;
		while (a.size() > 1) {
			while (i < s) {
				a.push(a.front());
				a.pop();
				i++;
			}
			i = 0;
			a.pop();
		}
		cout<< a.front()<<endl;
		//a.pizarra(s);
		//a.print();

		//TipoSolucion sol = resolver(datos);
		return true;
	}
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


	while (resuelveCaso())
		;

	/*
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	*/
	return 0;
}