

# include "Header.h"
using namespace std;


bool resuelveCaso()
{
	int cant, h, m, s;
	cin >> cant;
	string p;
	//vector<Lista> v(cant);
	vector<Horas> v(cant);
	if (cant == 0)return false;
	else {
		for (int i = 0; i < cant; i++) {
			Horas ini;
			Horas fin;
			cin >> ini;
			cin >> fin;
			v[i] = ini + fin;
			cin.ignore(1);
			getline(cin, p);
			v[i].set_pelicula(p);
		}
		sort(v.begin(), v.end());
		//ordena(v, 0, cant-1);
		for (int i = 0; i < cant; i++){
			cout << v[i] << endl;
		}
		cout << "---" << endl;
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
	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
	/*
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
*/
	return 0;
}