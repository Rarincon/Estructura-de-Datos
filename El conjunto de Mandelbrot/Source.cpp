

#include "Header.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    float r, i;
    int n;
    cin >> r >> i >> n;
    complejo<class T> c(r, i, n);
    complejo<class T> a(0, 0, 0);
    c.Mandelbrot(a, 0);
  
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

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    /*
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif*/

    return 0;
}