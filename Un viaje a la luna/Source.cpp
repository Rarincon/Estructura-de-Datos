

#include <iostream>
#include <fstream>
#include <vector>
#include"persona.h"
#include"extension.h"

// funcioon que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioon, y escribiendo la respuesta

bool  resuelveCaso() {
	// leer los datos de la entrada
	int numper, edadmax, edadmin;
	std::cin >> numper >> edadmin >> edadmax;
	if (!std::cin) { return false; }
	else if (numper == 0 && edadmin == 0 && edadmax == 0) {
		return false;
	}
	ListRemover<Persona> list;Persona read;
	for (int i = 0;i < numper;i++) {
		std::cin >> read;
		list.push_back(read);
	}
	list.remove_if([edadmin, edadmax](Persona per) {
		return(per.get_age() >= edadmin &&
			per.get_age() <= edadmax);
		});

	list.print(list);
	std::cout << "---\n";
	return true;

}
int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
  while(resuelveCaso());
	// Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}