
// COMENTARIO SOBRE LA SOLUCIÓN
/*
Para resolver este problema hacen faltan varios elementos, un mapa (sin orden, ya que no es necesario), y dentro de este una clave que indique el nombre de un paciente, 
y como valor, un pair que indique la gravedad del paciente y un iterador a la lista de espera para poder eliminarlo de forma constante si cambia su gravedad.
Tambien hace falta un vector de tamaño 3, en el cual en cada una de sus posiciones tendra la lista de pacientes con dicha gravedad, esta ordenada de forma que el mas prioritario
se encuentre al final de la lista.
Y por ultimo un set, que permite guardar los pacientes que se han mejorado (entiendo que estando unicamente en epera, sin realizar la funcion de siguiente), y de esta forma ya se encuantran 
ordenados alfabeticamente y no habra repetuciones ya si las hay, no se insertan.

Cuando se inserta un nuevo paciente se añade al mapa y a la lista de espera en funcion de su gravedad, una vez mejora puede ser eliminado del mapa pues ya se ha curado o puede cambiarse
de lista en funcion de su nueva gravedad. Cuando un paciente pasa a siguiente, se cura y desaparece del mapa por si hay qye ingresarlo de nuevo (eso supongo yo), y si se recupera esperando
se le elimina del mapa pero se le añade a la "lista" de pacientes recuperados mientras esperaban.
*/

// NO OLVIDES PONER EL COSTE JUSTIFICADO DE CADA OPERACIÓN JUNTO A ELLA
/*
El coste de este ejercicio se divide en cada una de las funciones del TAD urgencias
1. La creacion de un mapa sin orden tiene un coste constante, ademas de la creacion de un vector de un tamaño determinado, al igual que el set
2. Las operaciones de busqueda e insercion en el caso peor tiene un coste de log(n) siendo n el numero de elementos que tenga el mapa, sino tiene coste constante de igual forma
que la insercion de nuevos elementos en una lista.
3. La busqueda de gravedad() tambien tiene coste constante pues realiza funciones de busqueda en un mapa, en el caso peor seria log(n), siendo n el numoro de elementos/pacientes que tiene el mapa.
4. El el metodo siguinte() se busca el ultimo pacinet de la lista con la gravedad mas alta, comprobando que dicha lista tenga algun paciente, y de ser asi lo elimina de la lista y del mapa, que esos dos
metodos tienen coste constante. Pero recorrer el vector en el caso peor tiene coste de O(3) que es el numero de elementos que tiene. Ademas las funciones de empty tambien tiene coste cosntante
5. El metodo mejora() usa funciones de busqueda y de eliminacion que tienen un coste constante, pues la eliminacion en la lista se realiza a traves de un iterador, de esta forma no hace falta recorrerla
6. El metodo de recuperados() tiene un coste constante pues solo hay que devolver el set, que hemos tenido actualizado todo el rato
El coste final es el maximo de los apartados
*/


#ifndef URGENCIAS
#define URGENCIAS

#include <iostream>          
#include <string>
#include <stdexcept>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <iterator>
#include <set>
#include <list>
using namespace std;

using paciente = string;
using gravedad = int;

class urgencias {
	unordered_map<paciente, pair< gravedad, list<paciente>::iterator>> pac;
	vector<list<paciente>> espera;
	set<paciente> recupera;
public:
	urgencias(): espera(3) {};

	void nuevo_paciente(paciente const& p, gravedad const& g) {
		if (g < 1 || g>3) throw	domain_error("Gravedad incorrecta");
		auto it = pac.find(p);
		if (it == pac.end()) {
			espera[g - 1].push_front(p);
			pac.insert({ p,{g, espera[g - 1].begin()} });
		}
		else throw domain_error("Paciente repetido");
	}
	int gravedad_actual(paciente const& p) {
		auto it = pac.find(p);
		if (it == pac.end()) throw domain_error("Paciente inexistente");
		else return it->second.first;
	}
	paciente siguiente(){
		paciente e;
		if (espera[0].empty() && espera[1].empty() && espera[2].empty())throw domain_error("No hay pacientes");
		for (int i = 2; i >= 0; i--) {
			auto & it = espera[i];
			if (!it.empty()) {
				pac.erase(it.back()); //Aclarar que una vez recuperados se elimina de la tabla de pacientes, pues ya no lo es,  esto puede permite volver a ingresarlo si es necesario
				e=it.back();
				it.pop_back();
				//recupera.insert(e); //No esta muy bn especificado, pero segun los casos de prueba no se les añade
				return e;
			}
		}
	}
	void mejora(paciente const& p){
		auto it = pac.find(p);
		if (it == pac.end()) throw domain_error("Paciente inexistente");
		espera[it->second.first - 1].erase(it->second.second);
		it->second.first--;
		if (it->second.first == 0) {
			recupera.insert(it->first);
			pac.erase(it->first); //Aclarar que una vez recuperados se elimina de la tabla de pacientes, pues ya no lo es, esto puede permite volver a ingresarlo si es necesario
		}
		else {
			espera[it->second.first - 1].push_back(it->first);
			it->second.second = --espera[it->second.first - 1].end();
		}
		
	}
	set<paciente> recuperados() {
		return recupera;
	}
};


#endif
