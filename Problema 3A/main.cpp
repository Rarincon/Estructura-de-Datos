

#include <iostream>               
#include <fstream>               
#include <algorithm>
#include <unordered_map>
#include <vector>;
using namespace std;

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO

//El problema se resuelve con un diccionario sin orden (unordered_map), pues no nos interesa/sirve para nada que se ordene por juegos el mapa,
//ya que el objetivo es ver que dia se jugo un juego en especifico y para la solucion no interfiere el orden en el que se orden los juegos,
//por tanto no haria falta ordenarlo.
//En el diccionario utilizaremos como clave el juego, y como valor, un vector de enteros, en el que se van a ir insertando el numero del dia en el cual jugo dicho juego
//de forma que se sabra cuantas veces jugo dicho juego, y el dia exacto en el que jugo el juego, por primera, segunda, tercera... vez.

//El coste del ejercicio es de O(max(k,n)), siendo k el tamanyo de la tabla unordered_map, siendo n, el numero de palabras/juegos
//Explicaion:
//1. Es el coste de crear la tabla sin orden, pues su orden es de k ( tamanyo de la tabla ) , porque se trata de un diccionario sin orden
//2. El coste del bucle de lectura, pues aunque la busqueda e inserccion en el diccionario sea constante, se realiza n veces, tantas como palabras se intruduccan por consola.
//Tambien la inserccion en el vector es de coste constante.
//3. Ademas el bucle de salida tiene un coste constante bien sea porque la busqueda de un valor en una posicion determinada, y la obtencion del tamanyo de un vector tambien tiene un coste constante,
//sino que ademas de no recorrer todo el mapa, solo se realiza la funcion de busqueda en el diccionario, que tiene un coste constante.
//4. Los costes 1 y 2 se producen de forma secuencial , por lo que el coste final es el maximo de entre ellos dos.


using juego = string;

bool resuelveCaso() {
	int N;
	cin >> N;
	if (!cin)
		return false;
	string j;
	int dia;
	unordered_map<juego, vector<int>> abuelo;
	for (int i = 1; i < N + 1; i++) {
		cin >> j;
		auto& it = abuelo[j];
		it.push_back(i);
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> dia >> j;
		auto const& it = abuelo[j];
		if (it.size() < dia) cout << "NO JUEGA" << endl;
		else cout << it.at(dia-1)<<endl;
	}
	cout << "---" << endl;
	return true;
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
