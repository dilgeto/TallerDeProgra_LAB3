#include <iostream>
#include <vector>
#include <random>
#include "MatrizCosto.h"

using namespace std;

class Annealing {
	private:
		vector<int> tour;
		MatrizCosto* matrizCostos;
	public:
		Annealing(MatrizCosto* matriz, int maxIter, vector<int> tour, double cost);
		vector<int> two_opt_first(vector<int> tour);
		vector<int> annealing(vector<int> tour);
		vector<int> getTour();
		double tour_cost(vector<int> tour);
};
