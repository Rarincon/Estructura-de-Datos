

#include <iostream>
#include<vector>
#include <map>
#include<string>

using namespace std;


using alumno = std::string;
using nota = int;
struct tSol{ string al; int mark; };

class ejercicios {
private:
	std::map < alumno, signed int > tabla;
public:
	ejercicios() {}
	void correcto(alumno const& a) { // O( log A)
		++tabla[a];
	}
	void incorrecto(alumno const& a) {
		--tabla[a];
	}
	void borrar(alumno const& a) { // O( log A)
		tabla.erase(a);
	}
	signed int cantidad(alumno const& a) const { // O(log A)
		auto it = tabla.find(a);
		if (it == tabla.end())
			return 0;
		else
			return it -> second;
	}
	std::vector < tSol > lista_negra() const { // O(A)
		std::vector < tSol > resultado;
		tSol sol;
		for (auto const& par : tabla) {
			if (par.second != 0) {
				sol.al = par.first; sol.mark = par.second;
				resultado.push_back(sol);
			}
		}
		return resultado;
	}
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso(int n) {
	ejercicios ej;
	string name, valor;
	for (int i = 0; i < n; i++) {
		cin.ignore();
		getline(cin, name);
		cin>> valor;
		if (valor == "CORRECTO")
			ej.correcto(name);
		else ej.incorrecto(name);
	}
	vector<tSol> v = ej.lista_negra();
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].al << ", " << v[i].mark << endl;
	}
	cout << "---" << endl;

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
	while (n != 0) {
		resuelveCaso(n);
		cin >> n;
	}


	/*
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
*/
	return 0;
}