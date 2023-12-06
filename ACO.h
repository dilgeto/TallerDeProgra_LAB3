#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <ctime>
#include "MatrizCosto.h"
#include "Edge.h"
#include "Comparator.h"

using namespace std;

class ACO {
	private:
		vector<int> tour;
		MatrizCosto* costs;
		double** pheromones;
		vector<vector<int>> antPaths;
	public:
		ACO(MatrizCosto* matrix, vector<int> tour);
		void generateAntPaths(int totalAnts);
		void addPheromones();
		double probability();
		MatrizCosto* getCosts();
		double** getPheromones();
		vector<int> getTour();
		double tour_cost(vector<int> antTour);
		void print();
};
