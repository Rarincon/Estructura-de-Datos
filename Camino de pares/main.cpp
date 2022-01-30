

#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>

using namespace std;

#include "bintree_eda.h"

struct tSol{
	int camino;
	bool par;
	int max;
};

//8 4 2 -1 -1 6 -1 8 -1 -1 6 4 -1 2 -1 -1 -1 ->7

//10 8 4 2 -1 -1 6 -1 8 -1 -1 6 4 -1 2 -1 -1 -1 4 -1 -1 ->7

//10 7 4 2 -1 -1 6 -1 8 -1 -1 6 4 -1 2 -1 -1 -1 4 -1 -1 ->4

//8 4 2 -1 -1 6 -1 8 -1 -1 6 4 -1 2 -1 -1 -1

/*
3
2 4 5 2 - 1 - 1 - 1 6 - 1 - 1 8 - 1 1 - 1 - 1
1 4 5 - 1 2 - 1 - 1 - 1 6 - 1 - 1
3 4 2 - 1 - 1 6 - 1 8 - 1 - 1 5 4 - 1 2 - 1 - 1 - 1*/


tSol caminoPares(bintree<int> arbol) {
	if (!arbol.empty()) {
		tSol sol = { 0,false, 0 };
		if (arbol.root() % 2 == 0) {
			sol = { 1,true ,1 };
		}
		tSol contI = caminoPares(arbol.left());
		tSol contD = caminoPares(arbol.right());
		if (sol.par) {
			int s = sol.camino;
			int D = 0, I = 0;
			if (contI.par && contD.par) {
				int m = max(contI.max, contD.max) + 1;
				sol.max = m;
			}
			else {
				int M = max(contI.camino, contD.camino) + 1;
				sol.max = M;
			}
			if (contI.par) {
				s += contI.max;
				
			}
			if (contD.par) {
				s += contD.max;
			}
			/*int MAXI = max(contI.camino, contD.camino);
			if (s > MAXI) {
				sol.camino = s;
			}*/
			int MAXI = max(contI.camino, contD.camino);
			if (s > MAXI) {
				int MAX = max(contI.max, contD.max);
				if (s < MAX) sol.camino = MAX;
				else sol.camino = s;
			}
			else {
				int m = max(contI.camino, contD.camino);
				sol.camino = m;
			}
			
			//int M = max(contI.max, contD.max)+1;
			//sol.max = M;
			
			//if (sol.max >= sol.camino)sol.camino = sol.max;
			return sol;
			
			/*int D = 0, I = 0;
			int s = sol.camino;
			int cD=s, cI=s;
			if (contI.par) {
				cI += contI.max;
				s += contI.camino;
				I = sol.camino;
			}
			if (contD.par) {
				cD += contD.max;
				D = sol.camino + contD.camino;
				s+= contD.camino;
			}


			int M = max(I, D);
			sol.max += M;
			return sol;*/
		}
		else {
			int m = max(contD.camino, contI.camino);
			return { 0,false, m };
		}
	}
	else return { 0,false,0 };
}

/*
tSol caminoPares(bintree<int> arbol) {
	if (!arbol.empty()) {
		tSol sol = { 0,false, 0 };
		if (arbol.root() % 2 == 0) {
			sol = { 1,true ,1};
		}
		tSol contI = caminoPares(arbol.left());
		tSol contD = caminoPares(arbol.right());
		if (sol.par){
			int D=0, I=0;
			if (contI.par) {
				sol.camino += contI.camino;
				I = sol.camino;
			}
			if (contD.par) {
				D = sol.camino + contD.camino - contI.camino;
				sol.camino += contD.camino;
			}
			int M = max(I, D);
			sol.max += M;
			return sol;
		}
		else {
			int m = max(contD.camino, contI.camino);
			return { 0,false, m };
		}
	}
	else return { 0,false,0 };
}*/

void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	tSol sol = caminoPares(arbol);
	if(sol.camino>sol.max)cout << sol.camino << endl;
	else
		cout << sol.max << endl;
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif*/

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}
/*
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/
	return 0;
}
