
#include "queue_ext.h"


bool resuelveCaso() {
	int n,l;
	Cambiar<int> q;
	cin >> n;
	if (n==0)
		return false;
	else {
		while (n != 0) {
			cin >> l;
			q.push(l);
			n--;
		}
		q.intercambiar();
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