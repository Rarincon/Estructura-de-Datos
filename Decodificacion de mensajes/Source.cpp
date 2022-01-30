

#include <iostream>
#include <iomanip>
#include <fstream>

#include <stdio.h>
#include <ctype.h>

#include <stack>
#include <deque>
#include <string>

using namespace std;

bool isVowel(char ch) {
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch=='A' || ch=='E' || ch=='I'|| ch=='O' ||ch=='U')
			return true;
	else return false;
}

bool resuelveCaso() {
	string f;
	stack<char> p;
	deque<char>s;
	string frase;
	int uno = 0;
	getline(cin, f);
	if (!cin)return false;
	else {
		if (f.size() % 2 == 0) {
			for (int i = f.size(); i > 0; i--) {
				if (uno % 2 == 0)
					s.push_back(f.at(i - 1));
				else
					s.push_front(f.at(i - 1));
				uno++;
			}
		}
		else {
			for (int i = f.size(); i > 0; i--) {
				if (uno % 2 == 0)
					s.push_front(f.at(i - 1));
				else
					s.push_back(f.at(i - 1));
				uno++;
			}
		}
		while (!s.empty()) {
			if (!isVowel(s.front()))
				p.push(s.front());
			else {
				while (!p.empty()) {
					frase.push_back(p.top());
					p.pop();
				}
				frase.push_back(s.front());
			}
			s.pop_front();
		}
		while (!p.empty()) {
			frase.push_back(p.top());
			p.pop();
		}

		cout << frase<<endl;
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

/*
// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	string f;
	stack<char> p;
	deque<char> s;
	deque<char> frase;
	//cin.get(f);
	getline(cin, f);
	if (!cin)
		return false;
	int uno = 1;
	for (int i = f.size()-1; i >= 0; i--) {
		if (uno == 0) {
			p.push(f[i]);
			uno = 1;
		}
		else {
			s.push_back(f[i]);
			uno = 0;
		}
	}
	
	char u, d;
	if (p.size() == s.size()) {
		if (p.size() >= 2) {
			u = p.top();
			p.pop();
			d = p.top();
			p.pop();

			while (!p.empty()) {
				if (isVowel(u)) {
					frase.push_back(u);
					swap(u, d);
					d = p.top();
					p.pop();
				}
				else if (!isVowel(u) && isVowel(d)) {
					frase.push_back(u);
					swap(u, d);
					d = p.top();
					p.pop();

				}
				else {
					swap(u, d);
					frase.push_back(u);
					swap(u, d);
					d = p.top();
					p.pop();
				}
			}
			if (isVowel(u)) {
				frase.push_back(u);
				frase.push_back(d);
			}
			else if (!isVowel(u) && isVowel(d)) {
				frase.push_back(u);
				frase.push_back(d);
			}
			else {
				frase.push_back(d);
				frase.push_back(u);
			}
		}
		if (s.size() >= 2) {
			u = s.front();
			s.pop_front();
			d = s.front();
			s.pop_front();


			while (!s.empty()) {
				if (isVowel(u)) {
					frase.push_back(u);
					swap(u, d);
					d = s.front();
					s.pop_front();
				}
				else if (!isVowel(u) && isVowel(d)) {
					frase.push_back(u);
					swap(u, d);
					d = s.front();
					s.pop_front();

				}
				else {
					swap(u, d);
					frase.push_back(u);
					swap(u, d);
					d = s.front();
					s.pop_front();
				}
			}
			if (isVowel(u)) {
				frase.push_back(u);
				frase.push_back(d);
			}
			else if (!isVowel(u) && isVowel(d)) {
				frase.push_back(u);
				frase.push_back(d);
			}
			else {
				frase.push_back(d);
				frase.push_back(u);
			}
		}
	}
	else {
		if (p.size() >= 2) {
			u = p.top();
			p.pop();
			d = p.top();
			p.pop();

			while (!p.empty()) {
				if (isVowel(u)) {
					frase.push_front(u);
					swap(u, d);
					d = p.top();
					p.pop();
				}
				else if (!isVowel(u) && isVowel(d)) {
					frase.push_front(u);
					swap(u, d);
					d = p.top();
					p.pop();

				}
				else {
					swap(u, d);
					frase.push_front(u);
					swap(u, d);
					d = p.top();
					p.pop();
				}
			}
			if (isVowel(u)) {
				frase.push_front(u);
				frase.push_front(d);
			}
			else if (!isVowel(u) && isVowel(d)) {
				frase.push_front(u);
				frase.push_front(d);
			}
			else {
				frase.push_front(d);
				frase.push_front(u);
				
			}
		}
		if (s.size() >= 2) {
			u = s.front();
			s.pop_front();
			d = s.front();
			s.pop_front();


			while (!s.empty()) {
				if (isVowel(u)) {
					frase.push_front(u);
					swap(u, d);
					d = s.front();
					s.pop_front();
				}
				else if (!isVowel(u) && isVowel(d)) {
					frase.push_front(u);
					swap(u, d);
					d = s.front();
					s.pop_front();

				}
				else {
					if (!isVowel(s.front())) {
						frase.push_front(s.front());
						s.pop_front();
					}
					else {
						swap(u, d);
						frase.push_front(u);
						swap(u, d);
						d = s.front();
						s.pop_front();
					}
				}
			}
			if (isVowel(u)) {
				frase.push_front(u);
				frase.push_front(d);
			}
			else if (!isVowel(u) && isVowel(d)) {
				frase.push_front(u);
				frase.push_front(d);
			}
			else {
				frase.push_front(d);
				frase.push_front(u);
				
				
			}
		}

	}
	int tam = frase.size();
	for (int i = 0; i < tam; i++) {
		cout << frase.front();
		frase.pop_front();
	}
	cout << endl;
	return true;
	
}
*/