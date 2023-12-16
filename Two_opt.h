#include <iostream>
#include <vector>
#include "MatrizCosto.h"

using namespace std;

/*
	* Clase Two_opt:
	* Esta clase se utiliza para resolver el problema del vendedor viajero (TSP)
	* utilizando la heurística de 2-opt.
	* Esta clase está representada por un tour, que vendría a ser la colección de 
	* tiendas que debe recorrer el vendedor, estas se recorren en el orden que
	* están colocadas en el vector. Además existe la matriz de costos, que 
	* tiene el costo entre cualquier par de tiendas.
 */
class Two_opt{
	public:
		// Atributos
		vector<int> tour;
		MatrizCosto* matrizCostos;

		// Métodos
		// Constructor
		Two_opt(MatrizCosto* matriz, int maxIter, vector<int> tour, double cost);

		// Otros Métodos
		vector<int> two_opt_first(vector<int> tour);
		double tour_cost(vector<int> tour);
		void print_tour();
};
