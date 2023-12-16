#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include "MatrizCosto.h"

using namespace std;

/*
	* Clase Annealing:
	* Esta clase es usada para resolver el problema del vendedor viajero (TSP) 
	* utilizando una versión modificada de la heurística de Annealing, basándose
	* en la heurística 2-opt. Funciona de la misma forma que 2-opt, pero cuando
	* no se logra encontrar un tour de menor costo, se realiza una permutación 
	* aleatoria de los nodos, esto se repite hasta completar todas las iteraciones,
	* solo que cada vez que se avanza en las iteraciones, se empieza a disminuir
	* el rango en que se realizan las permutaciones.
	* Esta clase está conformada por el tour encuentrado, el cual se va
	* actualizando conforme se avanza en el algoritmo y la matriz de costos
	* que contiene el costo de viajar entre cualquier par de nodos.
 */
class Annealing {
	public:
		// Atributos
		vector<int> tour;
		MatrizCosto* matrizCostos;

		// Métodos
		// Constructor
		Annealing(MatrizCosto* matriz, int maxIter, vector<int> tour, double cost, double minimo);

		// Otros Métodos
		vector<int> two_opt_first(vector<int> tour);
		vector<int> vertices_aleatorios(vector<int> tour, int aleatoriedad);
		int buscar_menor_tour(vector<double> costs);
		double tour_cost(vector<int> tour);
		void print_tour();
};
