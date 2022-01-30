

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>

using namespace std;

using cancion = string;
using artista = string;
using duracion = int;

/*
struct song {
	string artista;
	int duracion = 0;
	list<cancion>::iterator lst;
	list<cancion>::iterator reprod;
};


class iPud {
private:
	//unordered_map<cancion,pair<artista,duracion>> canciones;
	unordered_map<cancion,song> canciones;
	struct Plist {
		int total=0;
		list<cancion> lst;
		list<cancion> reprod;
	}pList;
public:
	iPud() {};

	void addSong(cancion const& c, artista const& a, duracion const & d) {
		auto it = canciones.find(a);
		if (it != canciones.end()) 
			throw domain_error("addSong");
		canciones.insert({ c, { a,d ,pList.lst.end(),pList.reprod.end()} });
	}
	void addToPlaylist(cancion const& c) {
		auto it = canciones.find(c);
		if (it == canciones.end())
			throw domain_error("addToPlaylist");
		auto f = pList.lst.end();
		if (it->second.lst == pList.lst.end()) {
			pList.total += it->second.duracion;
			pList.lst.push_front(c);
			it->second.lst = pList.lst.begin();
		}
	}
	cancion current() const{
		if (pList.lst.empty())throw domain_error("current");
		return pList.lst.back();
	}
	void play() {
		if(pList.lst.empty())throw domain_error("No hay canciones en la lista");
		auto it = canciones.find(pList.lst.back());
		if(it==canciones.end())throw domain_error("play"); //No deberia pasar nunca
		it->second.lst= pList.lst.end();
		if (it->second.reprod != pList.reprod.end())
			pList.reprod.erase(it->second.reprod);
		pList.reprod.push_front(pList.lst.back());
		pList.total -= it->second.duracion;
		pList.lst.pop_back();
		it->second.reprod = pList.reprod.begin();
	}
	int totalTime() const{
		return pList.total;
	}
	list<cancion> recent(int const& N) {
		if (pList.reprod.size() < N)return pList.reprod;
		else {
			if (pList.reprod.size() == 0)return {};
			list<cancion> aux;
			auto it = pList.reprod.begin();
			int cont = 0;
			while (cont < N) {
				aux.push_back(it->data());
				cont++;
				it++;
			}
			return aux;
		}
	}
	void deleteSong(cancion const& c) {
		auto it = canciones.find(c);
		if (it != canciones.end()) {
			if (it->second.lst != pList.lst.end()) {
				pList.total -= it->second.duracion;
				pList.lst.erase(it->second.lst);
			}
			if (it->second.reprod != pList.reprod.end()) {
				pList.reprod.erase(it->second.reprod);
			}
			canciones.erase(c);
		}
	}
};*/

struct song {
	string artista;
	int duracion = 0;
	list<cancion>::iterator lst;
	list<cancion>::iterator reprod;
};

struct pl {
	bool ok;
	cancion c;
};

class iPud {
private:
	unordered_map<cancion, song> tabla;
	int total = 0;
	list<cancion> lst;
	list<cancion> reprod;
public:
	iPud() {};

	void addSong(cancion const& c, artista const& a, duracion const& d) {
		//if (!tabla.insert({ c,{a,d,lst.end(),reprod.end()}}).second)
		auto it = tabla.find(c);
		if (it == tabla.end()) {
			tabla.insert({ c,{a,d,lst.end(),reprod.end()} });
		}
		else
			throw domain_error("addSong");
	}
	void addToPlaylist(cancion const& c) {
		auto it = tabla.find(c);
		if (it == tabla.end())throw domain_error("addToPlaylist");
		auto& it2 = it->second;
		if (it2.lst == lst.end()) {
			it2.lst = lst.insert(lst.end(), c);
			total += it->second.duracion;
			//lst.push_front(c);
			//it->second.lst = lst.begin();
		}
	}
	cancion current() const {
		if (lst.empty())throw domain_error("current");
		else lst.front();
	}
	pl play() {
		if (!lst.empty()) {
			cancion a = lst.front();
			lst.pop_front();
			auto it = tabla.find(a);
			auto& it2 = it->second;
			total -= it2.duracion;
			it2.lst = lst.end();
			if (it2.reprod != reprod.end()) {
				reprod.erase(it2.reprod);
			}
			reprod.push_front(a);
			it2.reprod = reprod.begin();
			return { true,a };
		}
		else return { false, "o" };
	}
	int totalTime() const {
		if (lst.empty())return 0;
		else
			return total;
	}
	list<cancion> recent(int const& N) {
		if (reprod.empty())return {};
		if (reprod.size() < N)return reprod;
		list<cancion> sol;
		auto it = reprod.begin();
		int i = 0;
		while (i < N) {
			sol.push_back(it->data());
			it++;
			i++;
		}
		return sol;
	}
	void deleteSong(cancion const& c) {
		auto it = tabla.find(c); 
		if (it != tabla.end()) {
			if (it->second.lst != lst.end()) {
				lst.erase(it->second.lst);
				total -= it->second.duracion;
			}
			if (it->second.reprod != reprod.end()) {
				reprod.erase(it->second.reprod);
			}
			tabla.erase(c);
		}
	}
};

bool resuelveCaso() {
	iPud mp3;
	string p, c, a;
	list<cancion> l;
	pl pla;
	int t,n;
	cin >> p;
	if (!cin)return false;
	while (p != "FIN") {
		try {
			if (p == "addSong") {
				cin >> c >> a >> t;
				mp3.addSong(c, a, t);
				
			}
			else if (p == "addToPlaylist") {
				cin >> c;
				mp3.addToPlaylist(c);

			}
			else if (p == "current") {
				mp3.current();
			}
			else if (p == "play") {
				pla=mp3.play();
				if (pla.ok)
					cout << "Sonando " << pla.c << endl;
				else cout << "No hay canciones en la lista" << endl;
			}
			else if (p == "totalTime") {
				t=mp3.totalTime();
				cout << "Tiempo total "<<t << endl;
				
			}
			else if (p == "recent") {
				cin >> n;
				l = mp3.recent(n);
				if (l.empty())cout << "No hay canciones recientes" << endl;
				else {
					cout << "Las " << n << " mas recientes" << endl;
					for (auto it : l)cout << "    " << it << endl;
				}
			}
			else if (p == "deleteSong") {
				cin >> c;
				mp3.deleteSong(c);
			}
		}
		catch (domain_error & e) {
			cout << "ERROR "<< e.what() << endl;
		}
		cin >> p;
	}
	cout << "---" << endl;
	return true;
}


int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}