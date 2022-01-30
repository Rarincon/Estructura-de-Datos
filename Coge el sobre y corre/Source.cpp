//Cola doble
//Bucle de los k primeros
//K=3
// 3 8 5 4 2 1


#include <iostream>
#include <deque>
#include<algorithm>


using namespace std;

bool resuelveCaso() {
	int s, k,n;
	deque<int> d;
	cin >> s >> k;
	if (s == 0 && k == 0) return false;
	else {
		for (int i = 0; i < k; i++) {
			cin >> n;
			d.push_back(n);
		}
		int i= s - k + 1;
		
		
		while (i > 0) {

			if(d.front()>)
			
			cout << d.front();
			i--;
		}
		
		while (i < d.size()) {
			if (d.front() > i)


			i++;
		}


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