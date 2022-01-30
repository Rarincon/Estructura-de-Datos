// Solucion al problema smartFarming 2
// Solucion de Isabel Pita

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <map>

using namespace std;

class agricultura30 {
private:
	using tsector = std::string;
	using tplaga = std::string;
	// El primer elemento del par es el numero de plantas del sector
	// El map mantiene el número de plantas notificadas y no tratadas de esa plaga
	std::unordered_map < tsector, std::pair<int, std::map<tplaga, int>>> tabla_sector;
	std::vector<std::pair<tsector, tplaga>> cola_fumigar;

public:
	agricultura30() {}

	// Alta de un sector con un numero de plantas
	void alta(tsector const& id, int n) {
		auto par = tabla_sector.insert({ id,{n,std::map<tplaga, int>()} });
		if (!par.second) { // Ya estaba dado de alta, se modifica el número de plantas
			tabla_sector[id].first += n;
		}
	}

	// Se recibe una notificacion del robot
	void datos(tsector const& id, tplaga const& p, int n) {
		if (tabla_sector.count(id) == 0) throw std::domain_error("Sector no existente");
		if (tabla_sector[id].first < n) throw std::domain_error("Numero de plantas incorrecto");
		// Comprueba si hay bastantes plantas afectadas para fumigar. Comprueba que no este ya añadida al vector
		if (tabla_sector[id].second[p] < tabla_sector[id].first / 4.0 && n >= tabla_sector[id].first / 4.0)
			cola_fumigar.push_back({ id,p });
		// La añade a la tabla
		tabla_sector[id].second[p] = n;
	}

	// Obtiene los sectores y plagas a fumigar
	std::vector<std::pair<tsector, tplaga>> fumigar() {
		std::vector<std::pair<tsector, tplaga>> v;
		for (auto afumigar : cola_fumigar) {
			// Se inicializa el numero de plantas afectadas por la plaga
			tabla_sector[afumigar.first].second[afumigar.second] = 0;
			// Se añade a la salida
			v.push_back(afumigar);
		}
		cola_fumigar.clear();
		return v;
	}

	// Plagas de un sector
	std::vector<std::pair<tplaga, int>> plagas(tsector const& id) {
		std::vector<std::pair<tplaga, int>> v;
		for (auto s : tabla_sector[id].second)
			v.push_back(s);
		return v;
	}
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioon, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::string op;
	agricultura30 a30;
	std::cin >> op;
	if (!std::cin)
		return false;
	std::string id; std::string plaga; int n;
	while (op != "FIN") {
		try {
			if (op == "alta") {
				std::cin >> id >> n;
				a30.alta(id, n);
			}
			else if (op == "datos") {
				std::cin >> id >> plaga >> n; // numero de plagas
				a30.datos(id, plaga, n);
			}
			else if (op == "fumigar") {
				std::vector<std::pair<std::string, std::string>> v = a30.fumigar();
				for (auto const& s : v) {
					std::cout << "Fumigar la plaga " << s.second << " del sector :";
					std::cout << ' ' << s.first << '\n';
				}
			}
			else if (op == "plagas") {
				std::cin >> id;
				std::vector<std::pair<std::string, int>> v = a30.plagas(id);
				std::cout << "Plagas del sector " << id << " :";
				for (auto const& s : v)
					std::cout << ' ' << s.first << ' ' << s.second;
				std::cout << '\n';
			}
		}
		catch (std::domain_error & d) {
			std::cout << "ERROR: " << d.what() << '\n';
		}
		std::cin >> op;
	}
	std::cout << "---" << '\n';

	return true;

}

int main() {

	while (resuelveCaso()) {} //Resolvemos todos los casos

	return 0;
}

