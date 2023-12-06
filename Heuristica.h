#include <iostream>
#include <vector>
#include "MatrizCosto.h"

using namespace std;

class Heuristica {
	private:
		vector<int> tour;
		MatrizCosto* matrizCostos;
	public:
		Heuristica(MatrizCosto* matriz, int maxIter, vector<int> tour, double cost);
		vector<int> heuristica_first(vector<int> tour);
		vector<int> getTour();
		double tour_cost(vector<int> tour);
};
