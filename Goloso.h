#include <iostream>
#include <vector>
#include "MatrizCosto.h"

using namespace std;

/*
	* Clase Goloso:
	* Esta clase se usa para obtener un tour de costo mínimo utilizando el 
	* algoritmo Greedy (Goloso). Funciona buscando desde la posición actual
	* la arista que tenga el menor costo hasta recorrer todos los nodos.
 */
class Goloso {
	public:
		// Atributos
		double costo;
		MatrizCosto* matrizCostos;
		vector<int> tour;

		// Métodos
		// Constructor
		Goloso(MatrizCosto* matriz, int current_node);

		// Otros Métodos
		int smaller_cost_neighbour(int i, vector<bool> visited);
		double tour_cost();
		void print_tour();
};
