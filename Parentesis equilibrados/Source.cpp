
#include <stack>
#include <iostream>
#include <string>

using namespace std;

bool esParen(char const& c) {
	if (c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}')
		return true;
	else
		return false;
}


bool evaluar(string const& expresion) { 
	stack<char> pila;
	char d;
	bool ok = true;
	for (char c : expresion) {
		if(ok) {
			if (esParen(c)){//!isalpha(c) && !isdigit(c) && !isspace(c) && c != '.') {
				if (c == '(' || c == '[' || c == '{')
					pila.push(c);
				else {
					if (pila.empty())
						ok = false;
					else {
						if (c == ')') {
							d = pila.top(); pila.pop();
							if (d != '(')ok = false;
						}
						else if (c == ']') {
							d = pila.top(); pila.pop();
							if (d != '[')ok = false;
						}
						else {
							d = pila.top(); pila.pop();
							if (d != '{')ok = false;
						}
					}
				}
			}
		}
	}
	if (!pila.empty())ok = false;
	return ok;
}

bool resuelveCaso() {
	string tipo;
	getline(cin, tipo);
	if (!cin) {
		return false;
	}
	else {
		if (evaluar(tipo))
			cout << "SI" << endl;
		else cout << "NO" << endl;
		return true;
	}


}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif*/

	while (resuelveCaso());

	// restablecimiento de cin
/*#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif
*/
	return 0;
}