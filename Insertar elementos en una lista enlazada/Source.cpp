

#include "mezcla.h"
#include <iostream>
using namespace std;

bool resuelveCaso() {
	int n, i, c, j;;
	Mezcla<int> q;
	Mezcla<int> d;
	cin >> n;
	if (!cin)
		return false;
	else {
		i = 0;
		while (i < n) {
			cin >> c;
			q.push(c);
			i++;
		}
		cin >> n;
		cin >> j;
		i = 0;
		while (i<n){
			cin >> c;
			d.push(c);
			i++;
		}
		q.mezcla(d, j);

		q.print();

		//d.print();
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