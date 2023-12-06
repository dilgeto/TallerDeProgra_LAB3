#include "Aleatorio.h"

Aleatorio::Aleatorio (MatrizCosto* matriz, int largo) {
	this->matriz = matriz;
	// Los candidatos
	for (int i = 0 ; i < largo ; i++) {
		candidatos.push_back(i);
	}
	srand(static_cast<unsigned int>(time(0)));
	// Elección aleatoria
	while (candidatos.size() > 1) {
		int aleatorio = rand() % largo;
		int elegido = candidatos[aleatorio];
		candidatos.erase(candidatos.begin() + aleatorio);
		tour.push_back(elegido);
	}
	tour.push_back(candidatos.front());

	//cout << tour.size() << endl;
}

MatrizCosto* Aleatorio::getMatriz () {
	return this->matriz;
}

vector<int> Aleatorio::getTour () {
	return this->tour;
}

double Aleatorio::tour_cost () {
	vector<int> tour = getTour();
	double** c = getMatriz()->getMatriz();
	int n = getMatriz()->getSize();
    double cost = 0.0;
    for (int i = 0 ; i < n - 1 ; i++) {
        cost += c[tour[i]][tour[i+1]];
    }
    cost += c[tour[n-1]][tour[0]];
    return cost;
}



