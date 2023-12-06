#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <cstdlib>
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
		ACO(MatrizCosto* matrix);
		void generateAntPaths(int totalAnts);
		void eliminarNodo(int node);
		void addPheromones();
		void encontrarTour();
		void probability(int node);
		MatrizCosto* getCosts();
		double** getPheromones();
		vector<int> getTour();
		double tour_cost(vector<int> antTour);
		void print();
};
