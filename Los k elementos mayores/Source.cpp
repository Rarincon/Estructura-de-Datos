

#include "Header.h"

using namespace std;

template <class T>
void resuelve(T centinela) {
	int k;
	cin >> k;
	T elem;
	set<T> conj;
	cin >> elem;
	while (elem != centinela) {
		if (conj.size() < k)
			conj.insert(elem);
		else if (!conj.contains(elem) && conj.min() < elem) {
			conj.erase_min();
			conj.insert(elem);
		}
		cin >> elem;
	}
	conj.orden();
	conj.mostrar();
}

bool resuelveCaso() {
	char tipo;
	cin >> tipo;

	if (!cin)
		return false;

	if (tipo == 'N') { // el caso es de números
		resuelve(-1);
	}
	else { // el caso es de cadenas
		resuelve(string("FIN"));
	}
	return true;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif*/

	while (resuelveCaso());

	// restablecimiento de cin
/*#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif
*/
	return 0;
}