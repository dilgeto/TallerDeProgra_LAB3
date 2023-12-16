#include <iostream>
#include <vector>
#include "MatrizCosto.h"

using namespace std;

/*
	* Clase Goloso:
	* Esta clase se usa para obtener un tour de costo mínimo utilizando el 
	* algoritmo Greedy (Goloso) para resolver el problema del vendedor
	* viajero (TSP). Funciona buscando desde la posición actual la arista
	* que tenga el menor costo hasta recorrer todos los nodos.
	* Esta clase está conformada por el tour encontrado, el cual tiene
	* todas las tiendas que se deben visitar en orden, el costo de este
	* tour y la matriz de costos que tiene lo que cuesta viajar entre
	* cualquier par de tiendas.
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
