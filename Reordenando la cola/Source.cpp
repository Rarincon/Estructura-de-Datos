
#include <iostream>
#include <iomanip>
#include <fstream>

#include <stack>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	stack<float>p;
	stack<float>s;
	int c,i=0;
	float n;
	cin >> c;
	if (c==0)
		return false;
	else {
		while (i < c) {
			cin >> n;
			i++;
			if (n > 0)
				p.push(n);
			else
				s.push(n);
		}
		while (!s.empty()) {
			cout << s.top()<<" ";
			s.pop();
		}
		while (!p.empty()) {
			s.push(p.top());
			p.pop();
		}
		while (!s.empty()) {
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;
		return true;
		
		/*
		while (i < c) {
			cin >> n;
			if (p.empty())
				p.push(n);
			else {
				while (!p.empty() && n < p.top()) {
					s.push(p.top());
					p.pop();
				}
				p.push(n);
				while (!s.empty()) {
					p.push(s.top());
					s.pop();
				}
			}
			i++;
		}
		while (!p.empty()) {
			s.push(p.top());
			p.pop();
		}
		while (!s.empty()) {
			cout << s.top()<< " ";
			//p.push(s.top());
			s.pop();
		}
		cout << endl;
		return true;*/
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