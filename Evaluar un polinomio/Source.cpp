
#include "Header.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    int f, s, i, n;
    cin >> f;
    if (!std::cin)
        return false;
    else {
        vector<polinomio> p;
        cin >> s;
        while ((f != 0) || (s != 0)) {
            polinomio j(f, s);
            p.push_back(j);
            cin >> f >> s;;
        }
        cin >> i;
        while (i > 0) {
            cin >> n;
            resultado(p, n);
            i--;
        }
        cout << endl;
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

    /*
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif*/

    return 0;
}