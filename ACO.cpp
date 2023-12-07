#include "ACO.h"

// TODO: A veces se queda pegado en los 99
// TODO: Desvanecimineto de feromonas
// TODO: Usar 2-opt aleatorio para llegar soluciones buenas distintas.

//
ACO::ACO (MatrizCosto* matrix) {
	this->costs = matrix;
	pheromones = new double*[matrix->getSize()];
	for (int i = 0 ; i < matrix->getSize() ; i++) {
		pheromones[i] = new double[matrix->getSize()];
		for (int j = 0 ; j < matrix->getSize() ; j++) {
			pheromones[i][j] = 0.0;
		}
	}
	this->size = 0;
}

// Genera una cantidad determinada de tour aleatorios, uno por cada hormiga
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
		antPaths.push_back(antTour);

		double phTour = tour_cost(antTour);
		for (int j = 0 ; j < size - 1 ; j++) {
			pheromones[antTour[j]][antTour[j+1]] += 1.0/phTour;
		}
		pheromones[antTour[size-1]][antTour[0]] += 1.0/phTour;

		antTour.clear();
	}
}

//
void ACO::encontrarTour () {
	tour.push_back(0);
	while (tour.size() < getCosts()->getSize()) {
		probability(tour.back());
		//cout << size << endl;
	}
}

//
void ACO::eliminarNodo (int node) {
	for (int x = 0 ; x < node ; x++) {
		costs->matriz[x][node] = 0.0;
	}

	for (int x = node ; x < costs->getSize() ; x++) {
		costs->matriz[node][x] = 0.0;
	}
}

//
void ACO::probability (int node) {
	double alpha = 1.0;
	double beta = 1.0;
	multiset<Edge*, Comparator> probabilities;
	double denominador = 0.0;
	double tau_etaD;
	double tau_etaN;
	double probabilidad;
	Edge* alternativa;

	// Se obtiene el denominador
	for (int x = 0 ; x < node ; x++) {
		tau_etaD = pow(costs->getMatriz()[x][node], alpha) * pow(pheromones[x][node], beta);
		denominador += tau_etaD;
	}

	for (int x = node ; x < costs->getSize() ; x++) {
		tau_etaD = pow(costs->getMatriz()[node][x], alpha) * pow(pheromones[node][x], beta);
		denominador += tau_etaD;
	}

	//cout << "Denominador = " << denominador << endl << endl;

	// Se obtienen las probabilidades ya listas
	for (int x = 0 ; x < node ; x++) {
		tau_etaN = pow(costs->getMatriz()[x][node], alpha) * pow(pheromones[x][node], beta);
		probabilidad = tau_etaN / denominador;
		alternativa = new Edge(x, node, probabilidad);
		probabilities.insert(alternativa);

	}

	for (int x = node ; x < costs->getSize() ; x++) {
		tau_etaN = pow(costs->getMatriz()[node][x], alpha) * pow(pheromones[node][x], beta);
		//cout << costs->getMatriz()[node][x] << "    " << pheromones[node][x] << endl;
		probabilidad = tau_etaN / denominador;
		alternativa = new Edge(node, x, probabilidad);
		probabilities.insert(alternativa);
	}

	// Se calculan las probabilidades acumuladas
	multiset<Edge*, Comparator> acumProbabilities;
	double acum = 0.0;
	for (auto it = probabilities.begin() ; it != probabilities.end() ; ++it) {
		acum = acum + (*it)->probability;
		Edge* acumulado = new Edge((*it)->i, (*it)->j, acum);
		acumProbabilities.insert(acumulado);
	}
	
	for (auto it = probabilities.begin() ; it != probabilities.end() ; ++it) {
		//cout << (*it)->probability << endl;
	}

	// Elegir un numero aleatorio entre 0 y 1
	srand(static_cast<unsigned int>(time(0)));
	// Generate a random integer between 0 and RAND_MAX
    int randomInt = rand();

    // Map the random integer to a double between 0 and 1
	// TODO: Entender porque no da valores distintos en cada iteracion
    double aleatorio = (double)randomInt / RAND_MAX;

	// Se escoge un camino en base a la probabilidad acumulada
	// TODO: Hacer con binary search
	for (auto it = acumProbabilities.begin() ; it != acumProbabilities.end() ; ++it) {
		if (aleatorio <= (*it)->probability) {
			if ((*it)->i == node) {
				tour.push_back((*it)->j);
			} else {
				tour.push_back((*it)->i);
			}
			size++;
			break;
		}
	}
	eliminarNodo(node);
	//cout << "Nodo numero: " << tour.size() << endl;
}

//
MatrizCosto* ACO::getCosts () {
	return this->costs;
}

//
double** ACO::getPheromones () {
	return this->pheromones;
}

//
vector<int> ACO::getTour () {
	return this->tour;
}

//
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

//
void ACO::print () {
	for (auto it = tour.begin() ; it != tour.end() ; ++it) {
		cout << (*it) << " ";
	}
	cout << endl;
}
