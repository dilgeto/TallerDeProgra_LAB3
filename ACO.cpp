#include "ACO.h"

ACO::ACO (MatrizCosto* matrix, vector<int> tour) {
	this->costs = matrix;
	pheromones = new double*[matrix->getSize()];
	for (int i = 0 ; i < matrix->getSize() ; i++) {
		pheromones[i] = new double[matrix->getSize()];
		for (int j = 0 ; j < matrix->getSize() ; j++) {
			pheromones[i][j] = 0.0;
		}
	}
	//double vaporization = 0.8;
}

// TODO: Entender como funciona el condicional de esta parte????
double calculatePheromone (int i, int j, double cost) {
	if (1==1) {
		return 1/cost;
	} else {
		return 0.0;
	}
}

void ACO::generateAntPaths (int totalAnts) {
	int size = getCosts()->getSize();
	// Los candidatos
	vector<int> ant;
	vector<int> antTour;
	for (int i = 0 ; i < size ; i++) {
		ant.push_back(i);
	}
	
	srand(static_cast<unsigned int>(time(0)));

	// Elección aleatoria
	for (int i = 0 ; i < totalAnts ; i++) {
		vector<int> antAux = ant;
		while (antAux.size() > 1) {
			int aleatorio = rand() % size;
			int elegido = antAux[aleatorio];
			antAux.erase(antAux.begin() + aleatorio);
			antTour.push_back(elegido);
		}
		antTour.push_back(antAux.front());
		//cout << "owo" << endl;
		antPaths.push_back(antTour);

		double phTour = tour_cost(antTour);
		for (int j = 0 ; j < size - 1 ; j++) {
			pheromones[antTour[j]][antTour[j+1]] += 1.0/phTour;
		}
		pheromones[antTour[size-1]][antTour[0]] += 1.0/phTour;

		antTour.clear();
	}
}

/*
void ACO::addPheromones () {
	for (auto it = antPaths.begin() ; it != antPaths.end() ; ++it) {
		double phTour = tour_cost((*it));
	}
}
*/

void ACO::probability (int node) {
	double alpha = 1.0;
	double beta = 1.0;
	multiset<Edge*, Comparator> probabilities;

	for (int probs = 0 ; probs < costs->getSize() ; probs++) {
		double tau = pow(pheromones[i][j], alpha);
		double eta = pow(costs->matriz[i][j], beta);
		double numerador, denominador = 0.0;
		numerador = tau * eta;
		for (int x = 0 ; x < node ; x++) {
			double tauD_etaD = pow(costs->getMatriz[x][nodo], alpha) * pow(pheromones[x][nodo], beta);
			denominador += tauD_etaD;
		}
	
		for (int x = node ; x < costs->getSize() ; x++) {
			double tauD_etaD = pow(costs->getMatriz[nodo][x], alpha) * pow(pheromones[nodo][x], beta);
			denominador += tauD_etaD;
		}
	}
}

MatrizCosto* ACO::getCosts () {
	return this->costs;
}

double** ACO::getPheromones () {
	return this->pheromones;
}

vector<int> ACO::getTour () {
	return this->tour;
}

double ACO::tour_cost (vector<int> antTour) {
	double** c = getCosts()->getMatriz();
	int n = getCosts()->getSize();
    double cost = 0.0;
    for (int i = 0 ; i < n - 1 ; i++) {
        cost += c[antTour[i]][antTour[i+1]];
    }
    cost += c[antTour[n-1]][antTour[0]];
    return cost;
}

void ACO::print () {
	/*
	int ant = 1;
	for (auto itRow = antPaths.begin() ; itRow != antPaths.end() ; ++itRow) {
		cout << "Ant " << ant << ": " << tour_cost((*itRow));
		cout << endl;
		ant++;
	}
	*/
	for (int i = 0 ; i < getCosts()->getSize() ; i++) {
		for (int j = 0 ; j < getCosts()->getSize() ; j++) {
			cout << pheromones[i][j] << " ";
		}
		cout << endl;
	}
}





