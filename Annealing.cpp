#include "Annealing.h"

Annealing::Annealing (MatrizCosto* matriz, int maxIter, vector<int> tour, double cost) {
	this->tour = tour;
	this->matrizCostos = matriz;
	int iter = 0;
	while (iter < maxIter) {
		vector<int> new_tour(two_opt_first(tour));
		double new_cost = tour_cost(new_tour);
		
		if (new_cost < cost) {
			tour = new_tour;
			cost = new_cost;
        } 
		iter++;
    }
	cout << "Tour 2-opt: ";
	for (int i = 0 ; i < 100 ; i++) {
		cout << tour[i] << " ";
	}
	cout << endl;


	vector<double> costs_annealing;
	vector<vector<int>> tours_annealing;
	vector<int> tour_menor;
	
	int iteraciones = 0;
	iter = 0;
	// TODO: Siempre iterar sobre el mejor
	for (int j = 0 ; j < 10 ; j++) {
		tours_annealing.clear();
		costs_annealing.clear();
		while (iter < 10) {
			// Cantidad de vertices que se cambian
			for (int i = 0 ; i < 5 ; i++) {
				vector<int> new_tour(annealing(tour));
				double new_cost = tour_cost(new_tour);	
				tour = new_tour;
				cost = new_cost;
			}

			while (iteraciones < maxIter) {
				vector<int> new_tour(two_opt_first(tour));
				double new_cost = tour_cost(new_tour);
				if (new_cost < cost) {
					tour = new_tour;
					cost = new_cost;
				}
				iteraciones++;
			}
			iter++;
			tours_annealing.push_back(tour);
			costs_annealing.push_back(cost);
		}
		
		double menor = costs_annealing[0];
		// TODO:
		tour_menor = tours_annealing[0];
		for (int it = 0 ; it < 10 ; it++) {
			if (menor > costs_annealing[it]) {
				menor = costs_annealing[it];
				tour_menor = tours_annealing[it];
			}
		}
		cost = menor;
		cout << "El mejor del lote = " << cost << endl;
	}
	
	
	cout << "Costo Annealing = " << cost << endl;
	cout << "Tour menor: ";
	for (auto it = tour.begin() ; it != tour.end() ; ++it) {
		cout << (*it) << " ";
	}
	cout << endl;	
}

//
vector<int> Annealing::annealing(vector<int> tour) {
    vector<int> new_tour(tour);
	int n = this->matrizCostos->getSize();

	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<> dis(0, n - 2);

	int i = dis(rng);
	uniform_int_distribution<> das(i + 1, n - 1);
	int j = das(rng);

	if (i >= j) {
		cout << endl << endl << "CAGASTE" << endl << endl;
	}

	int k = i+1;
	int l = j;
	while(k < l) {
		int temp = new_tour[k];
		new_tour[k] = new_tour[l];
		new_tour[l] = temp;
		k++;
		l--;
	}
	
    return(new_tour);
}


//
vector<int> Annealing::two_opt_first(vector<int> tour) {
    vector<int> new_tour(tour);
	double** c = this->matrizCostos->getMatriz();
	int n = this->matrizCostos->getSize();
    for(int i = 0 ; i < n - 1 ; i++) {
        for(int j = i + 1 ; j < n ; j++) {
            // iteramos sobre todos los pares de aristas (i,i+1) y (j,j+1)

            // se destruye la aristas: (i,i+1) (j,j+1)
            double current_cost = c[new_tour[i]][new_tour[i+1]] + c[new_tour[j]][new_tour[(j+1)%n]];
            // se crea la aristas: (i,j) (i+1,j+1)
            double new_cost = c[new_tour[i]][new_tour[j]] + c[new_tour[i+1]][new_tour[(j+1)%n]];
            
            if(new_cost < current_cost) {// va a bajar el costo total del tour
                // se destruye la aristas: (i,i+1) (j,j+1)
                // se crea la aristas: (i,j) (i+1,j+1)
                // --> se invierte el orden de los nodos entre i+1 y j
                int k = i+1;
                int l = j;
                while(k < l) {
                    int temp = new_tour[k];
                    new_tour[k] = new_tour[l];
                    new_tour[l] = temp;
                    k++;
                    l--;
                }
                // retornamos el primer menor tour que encontramos
                return(new_tour);
            }
        }
    }
    return(new_tour);
}

//
vector<int> Annealing::getTour () {
	return this->tour;
}

//
double Annealing::tour_cost(vector<int> tour) {
	double** c = this->matrizCostos->getMatriz();
	int n = this->matrizCostos->getSize();
    double cost = 0.0;
    for (int i = 0 ; i < n - 1 ; i++) {
        cost += c[tour[i]][tour[i+1]];
    }
    cost += c[tour[n-1]][tour[0]];
    return cost;
}



/*
	if (p >= 1) {
		int k = i+1;
		int l = j;
		while(k < l) {
			int temp = new_tour[k];
            new_tour[k] = new_tour[l];
			new_tour[l] = temp;
            k++;
            l--;
        }
		//cout << tour_cost(new_tour) << endl;

	} else {
		int randomInt = rand();
		double q = (double)randomInt / RAND_MAX;
		if (q < p) {
			int k = i+1;
			int l = j;
			while(k < l) {
				int temp = new_tour[k];
				new_tour[k] = new_tour[l];
				new_tour[l] = temp;
				k++;
				l--;
			}
		}
		//cout << tour_cost(new_tour) << endl;
		return(new_tour);
	}
	*/
