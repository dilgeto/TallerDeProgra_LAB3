#include <iostream>
#include <vector>
#include "MatrizCosto.h"

using namespace std;

/*
	* Clase
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
};
