#include <iostream>
#include <vector>
#include "MatrizCosto.h"

using namespace std;

class Two_opt{
	private:
		vector<int> tour;
		MatrizCosto* matrizCostos;
	public:
		Two_opt(MatrizCosto* matriz, int maxIter, vector<int> tour, double cost);
		vector<int> two_opt_first(vector<int> tour);
		vector<int> getTour();
		double tour_cost(vector<int> tour);
};
