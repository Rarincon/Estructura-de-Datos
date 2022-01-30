

#include <iostream>
#include <string>
#include <math.h>
#include "bintree_eda.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////

//Aguaslimpias
struct tSol {
	int agua, cont;
};

template<class T>
tSol agua(bintree<T>const& arbol) {
	if (!arbol.empty()) {
		if (arbol.left().empty() && arbol.right().empty()) return { 1, 0};
		else {
			tSol dch, izq, sol = { 0,0 };
			izq = agua(arbol.left());
			dch = agua(arbol.right());
			if (izq.agua >= 3)sol.cont++;
			if (dch.agua >= 3)sol.cont++;
			sol.cont += izq.cont + dch.cont;
			sol.agua = dch.agua + izq.agua - arbol.root();
			if (sol.agua < 0)sol.agua = 0;
			return sol;
		}
	}
	else
		return { 0, 0};
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//Diametro

struct tSol5 {
	int max, alt;
};

template<class T>
tSol5 diametro(bintree<T>const& arbol, int alt) {
	if (!arbol.empty()) {
		tSol5 sol = { 0,alt }, dch,izq;
		izq = diametro(arbol.left(), alt + 1);
		dch = diametro(arbol.right(), alt + 1);
		sol.max = max(izq.alt + dch.alt + 1, max(izq.max, dch.max));
		sol.alt = max(izq.alt, dch.alt)+1;
		return sol;
	}
	else return {0, 0};
}

////////////////////////////////////////////////////////////////////////////////////////////////////

//Excursionistas atrapados
struct tSol6 {
	int cant, max;
};

tSol6 montania(bintree<int>const& arbol) {
	if (!arbol.empty()) {
		tSol6 sol = { 0,0 }, dch, izq;
		izq = montania(arbol.left());
		dch = montania(arbol.right());
		if (izq.cant == 0 && dch.cant == 0 && arbol.root() != 0)sol.cant++;
		else {
			if (izq.cant != 0 && dch.cant != 0)sol.cant += izq.cant + dch.cant;
			else if (izq.cant != 0)sol.cant = izq.cant;
			else sol.cant = dch.cant;
		}
		sol.max = max(izq.max, dch.max) + arbol.root();
		return sol;
	}
	else return { 0,0 };
}

////////////////////////////////////////////////////////////////////////////////////////////////////

//Caballeros y Damas
struct tSol3 {
	int salvo, caballeros;
};

tSol3 num_a_salvo(bintree<char>const& arbol, int M) {
	if (!arbol.empty()) {
		tSol3 sol = { 0, 0 }, dch, izq;
		int m = M;
		if (arbol.root() == 'M')m++;
		izq = num_a_salvo(arbol.left(), m);
		dch = num_a_salvo(arbol.right(), m);

		sol.caballeros += izq.caballeros + dch.caballeros;
		sol.salvo += izq.salvo + dch.salvo;
		if (arbol.root() == 'C')sol.caballeros++;
		else if (arbol.root() == 'D' && m <=sol.caballeros)sol.salvo++;
		return sol;
	}
	else
		return { 0, 0 };
}
/*int num_a_salvo(bintree<char>const& arbol, int M, int C) {
	if (!arbol.empty()) {
		int sol=0, dch, izq, c = C, m = M;
		if (arbol.root() == 'C')c++;
		else if (arbol.root() == 'M')m++;
		else if (arbol.root() == 'D' && M <= C)sol++;
		izq = num_a_salvo(arbol.left(), m, c);
		dch = num_a_salvo(arbol.right(), m, c);
		sol += izq + dch;
		return sol;
	}
	else
		return 0;
}*/

int num_a_salvo(bintree<char>const& mapa) {
	return num_a_salvo(mapa, 0).salvo;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

//Examen de la B
struct tSol4 {
	int pares,cont;
};

tSol4 num_neutros(bintree<int>const& arbol) {
	if (!arbol.empty()) {
		tSol4 dch, izq, sol = { 0,0 };
		izq = num_neutros(arbol.left());
		dch = num_neutros(arbol.right());
		if (izq.pares == dch.pares)sol.cont++;
		if (arbol.root() > 0)sol.pares++;
		sol.cont += dch.cont + izq.cont;
		sol.pares += dch.pares+izq.pares;
		return sol;
	}
	else return { 0,0 };
}

unsigned int numero_neutros(bintree<int>const& arbol) {
	return num_neutros(arbol).cont;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

//Examen de la B
struct tSol2 {
	int cont, pares;
};

tSol2 adivinos(bintree<int>const& arbol) {
	if (!arbol.empty()) {
		tSol2 dch, izq, sol = { 0,0 };
		izq = adivinos(arbol.left());
		dch = adivinos(arbol.right());
		int pares = dch.pares + izq.pares;
		if (arbol.root() == pares)sol.cont++;
		sol.cont += dch.cont + izq.cont;
		sol.pares += dch.pares + izq.pares;
		if (arbol.root() % 2 == 0)sol.pares++;
		return sol;
	}
	else return { 0,0 };

}

//4 2 2 -1 -1 2 -1 -1 1 -1 10 -1 -1
unsigned int num_adivinos(bintree<int>const& mapa) {
	return adivinos(mapa).cont;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

//Reconstruccion Arbol binario de busqueda
bintree<int> reconstruir(vector<int> const& preorden, int ini, int fin) {
	if (ini <= fin) {
		int raiz = preorden[ini];
		int top = ini + 1;
		while (top <= (preorden.size() - 1) && raiz > preorden[top]) top++;

		auto izq = reconstruir(preorden, ini + 1, top - 1);
		auto dch = reconstruir(preorden, top, fin);

		return { izq, raiz, dch };
	}
	else return {};
}

bintree<int> reconstruir2(vector<int> const& postorden, int ini, int fin) {
	if (ini <= fin) {
		int raiz = postorden[fin];
		int top = fin - 1;
		while (top <= (postorden.size() - 1) && raiz < postorden[top]) top--;

		auto dch = reconstruir2(postorden, top + 1, fin - 1);
		auto izq = reconstruir2(postorden, ini, top);

		return { izq, raiz, dch };
	}
	else return {};
}

////////////////////////////////////////////////////////////////////////////////////////////////////

//Reconstruccion arbol binario
bintree<int> reconstruir(vector<int>const& preorden, int& p, vector<int>const& inorden, int& i, int top) {
	if (p == preorden.size() || inorden[i] == top) return {};

	int r = preorden[p];
	p++;
	auto izq = reconstruir(preorden, p, inorden, i, r);
	i++;
	auto dch = reconstruir(preorden, p, inorden, i, top);
	return { izq, r, dch };
}

bintree<int> reconstruir2(vector<int>const& postorden, int& p, vector<int>const& inorden, int& i, int top) {
	if (p < 0 || inorden[i] == top) return {};

	int r = postorden[p];
	p--;
	auto dch = reconstruir2(postorden, p, inorden, i, r);
	i--;
	auto izq = reconstruir2(postorden, p, inorden, i, top);
	return { izq, r, dch };
}

////////////////////////////////////////////////////////////////////////////////////////////////////


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {

	bintree <int> arbol = leerArbol(-1);
	//bintree <char> arbol = leerArbol('.');
	//cout << agua(arbol).cont << endl;
	//cout << num_adivinos(arbol) << endl;
	//cout << num_a_salvo(arbol) << endl;
	//cout << diametro(arbol,0).max << endl;
	tSol6 a = montania(arbol);
	cout <<a.cant<<" "<<a.max << endl;
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
	for (int i = 0; i < n; i++)
		resuelveCaso();


	/*
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////

/*
bintree<int> lee_arbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return bintree<int>();
	case '[': {
		int raiz;
		in >> raiz;
		in >> c;
		return bintree<int>(raiz);
	}
	case '(': {
		bintree<int> iz = lee_arbol(in);
		int raiz;
		in >> raiz;
		bintree<int> dr = lee_arbol(in);
		in >> c;
		return bintree<int>(iz, raiz, dr);
	}
	default: return bintree<int>();
	}
}


int main() {
	bintree<int> arbol;
	while (cin.peek() != EOF) {
		bintree<int> a = lee_arbol(cin);
		cout << numero_neutros(a) << endl;
		string resto_linea;
		getline(cin, resto_linea);
	}
	return 0;
}*/