

# include "Header.h"
//# include <stdexcept>
using namespace std;

bool resuelveCaso()
{
	int tren, cant, h, m, s;
	cin >> tren >> cant;
	vector<Horas> v(tren);
	if (tren == 0 || cant == 0)return false;
	else {
	
		for (int i = 0; i < tren; i++) {
			cin >> v[i];
			/*
			cin >> h;
			cin.ignore(1);
			cin >> m;
			cin.ignore(1);
			cin >> s;
			Horas hora(h, m, s);
			v[i] = hora;*/
		}
		for (int i = 0; i < cant; i++) {
			try {
				Horas hora;
				cin >> hora;
				/*cin >> h;
				cin.ignore(1);
				cin >> m;
				cin.ignore(1);
				cin >> s;
				Horas hora(h, m, s);*/
				int pos = busqbin(hora, v, 0, tren);
				cout << v[pos];
			}
			catch (std::invalid_argument & ia) {
				std::cout << ia.what() << '\n';
			}
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
	while(resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
	/*
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
*/
	return 0;
}