#include "Header.h"

bool resuelveCaso() {
	int n,i=0;
	stack<aviones>pila;
	aviones av;
	cin >> n;
	if (!cin)return false;
	else {
		while (i < n) {
			cin >> av;
			while (!pila.empty() && av.get_ac() >= pila.top().get_ac())pila.pop();
			if (pila.empty())cout << "NO HAY" << endl;
			else cout << pila.top();
			pila.push(av);
			i++;
		}
		cout << "---" << endl;
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