
#include "Invertir.h"



bool resuelveCaso() {
	int n;
	Invertir<int> q;
	cin >> n;
	if (!cin)
		return false;
	else {
		while (n != 0) {
			q.push(n);
			cin >> n;
		}
		q.invertir();
		q.mostrar();
		return true;
	}
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