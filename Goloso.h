#include <iostream>
#include <vector>
#include "MatrizCosto.h"

using namespace std;

class Goloso {
	private:
		double costo;
		MatrizCosto* matrizCostos;
		vector<int> tour;
	public:
		Goloso(MatrizCosto* matriz, int current_node);
		int smaller_cost_neighbour(int i, vector<bool> visited);
		double tour_cost();
		vector<int> getTour();
		void print_tour();
};
