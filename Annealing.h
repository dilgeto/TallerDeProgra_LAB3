#include <iostream>
#include <vector>
#include <random>
#include "MatrizCosto.h"

using namespace std;

/*
	* Clase
 */
class Annealing {
	public:
		// Atributos
		vector<int> tour;
		MatrizCosto* matrizCostos;

		// Métodos
		// Constructor
		Annealing(MatrizCosto* matriz, int maxIter, vector<int> tour, double cost);

		// Otros Métodos
		vector<int> two_opt_first(vector<int> tour);
		vector<int> vertices_aleatorios(vector<int> tour);
		int buscar_menor_tour(vector<double> costs);
		double tour_cost(vector<int> tour);
};
