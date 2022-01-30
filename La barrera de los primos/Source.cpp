

#include <iostream>
#include <math.h>
#include "bintree_eda.h"

using namespace std;

/*
struct tSol {
	bool enc;
	int num;
	int alt;
};

bool primo(int n) {
	if (n == 0 || n == 1 || n == 4) return false;
	for (int x = 2; x < n / 2; x++) {
		if (n % x == 0) return false;
	}
	return true;
}

// funcion que resuelve el problema
tSol resolver(const bintree<int>& arbol) {
	if (!arbol.empty() && !primo(arbol.root())) {
		queue<pair<int, bintree<int>>> pendientes;
		pendientes.push({ 1, arbol });
		while (!pendientes.empty()) {
			bintree<int> sig = pendientes.front().second;
			int alt = pendientes.front().first;
			pendientes.pop();
			if (sig.root() % 7 == 0)
				return { true, sig.root(), alt };
			if (!sig.left().empty() && !primo(sig.left().root()))
				pendientes.push({ alt + 1, sig.left() });
			if (!sig.right().empty() && !primo(sig.right().root()))
				pendientes.push({ alt + 1, sig.right() });
		}
		return { false, 0, 0 };
	}
	else
		return { false, 0, 0 };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<int> arbol = leerArbol(-1);

	//resolver el problema
	tSol sol = resolver(arbol);

	// escribir sol
	if (sol.enc)
		cout << sol.num << " " << sol.alt << endl;
	else
		cout << "NO HAY" << endl;
}*/

struct tSol {
	bool hay;
	int prim;
	int nivel;
};

template<class T>
tSol barrera(vector<bool> const& primo, bintree<T>const& arbol, int nivel) {
	if (!arbol.empty() &&!primo[arbol.root()]) {
		if (arbol.root() % 7 == 0) return { true, arbol.root(),nivel};

		int n = nivel+1;

		tSol izq = barrera(primo, arbol.left(), n);
		tSol dch = barrera(primo, arbol.right(), n);

		if (izq.hay && dch.hay) {
			if (izq.nivel == dch.nivel)return izq;
			else if (izq.nivel < dch.nivel)return izq;
			else return dch;
		}
		else if (izq.hay)return izq;
		else if (dch.hay)return dch;
		else return { false,-1,-1 };

	}
	else return{ false,-1, -1};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso(vector<bool> const &primo) {
	bintree <int> arbol = leerArbol(-1);
	int n = 1;

	tSol sol = barrera(primo, arbol,1);
	if (!sol.hay)cout << "NO HAY" << endl;
	else cout << sol.prim<<" "<< sol.nivel<< endl;
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
	std::vector<bool> primo(5000, true);
	primo[0] = primo[1] = false;
	for (int i = 2; i < sqrt(5000); i++) {
		if (primo[i])
			for (int j = i * i; j < 5000; j+=i)
				primo[j]=false;
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		resuelveCaso(primo);


	/*
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
*/
	return 0;
}