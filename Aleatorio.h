#include <iostream>
#include <vector>
#include <ctime>
#include "MatrizCosto.h"

using namespace std;

class Aleatorio {
	private:
		vector<int> tour;
		MatrizCosto* matriz;
		vector<int> candidatos;
	public:
		Aleatorio(MatrizCosto* matriz, int largo);
		MatrizCosto* getMatriz();
		vector<int> getTour();
		double tour_cost();
};
