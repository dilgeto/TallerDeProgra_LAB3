#include "Annealing.h"

/*
	* Método: Constructor->Annealing
	* Descripción: Crea la clase Annealing, que busca un tour con el menor costo
	* posible.
	* Parámetros: 
	*	- matriz: una clase matriz que contiene los costos entre todos los vértices.
	*	- maxIter: cantidad de iteraciones que realizarán.
	*	- tour: el conjunto de vértices que contienen un camino valido para el
	*		problema de TSP.
	*	- cost: el costo del tour anterior.
	* Retorna: 
	*	- void
*/
Annealing::Annealing (MatrizCosto* matriz, int maxIter, vector<int> tour, double cost) {
	this->tour = tour;
	this->matrizCostos = matriz;
	int iter = 0;
	vector<double> costs_annealing;
	vector<vector<int>> tours_annealing;
	
	while (iter < maxIter) {
		vector<int> new_tour(two_opt_first(tour));
		double new_cost = tour_cost(new_tour);
		
		 if (iter == maxIter - 1) {
			 tour = new_tour;
			 cost = new_cost;
			 tours_annealing.push_back(new_tour);
			 costs_annealing.push_back(new_cost);
		} else if (new_cost < cost) {
			tour = new_tour;
			cost = new_cost;
       		cout << iter << ") Cost: " << cost << endl;
		} else {
       		cout << iter << ") No improvement: " << cost << "    " << new_cost << endl;
			tours_annealing.push_back(tour);
			costs_annealing.push_back(cost);
			tour = vertices_aleatorios(new_tour);
			cost = tour_cost(tour);
		}
		iter++;
    }
	
	int posicionMenor = buscar_menor_tour(costs_annealing);
	tour = tours_annealing[posicionMenor];
	cost = costs_annealing[posicionMenor];
	//cout << "Cost 2-opt = " << cost << endl;

	int iteraciones = 0;
	iter = 0;
	for (int j = 0 ; j < 10 ; j++) {
		while (iter < 10) {
			// Cantidad de vertices que se cambian
			for (int i = 0 ; i < 2 ; i++) {
				vector<int> new_tour(vertices_aleatorios(tour));
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

		posicionMenor = buscar_menor_tour(costs_annealing);
		tour = tours_annealing[posicionMenor];
		cost = costs_annealing[posicionMenor];
	}
	
	cout << "Costo con aleatoriedad = " << cost << endl;
	cout << "Tour encontrado: ";
	for (auto it = tour.begin() ; it != tour.end() ; ++it) {
		cout << (*it) << " ";
	}
	cout << endl;
}

/*
	* Método: Otros Métodos->busca_menor_tour
	* Descripción: Entre todos los costos resultantes, encuentra el menor.
	* Parámetros: 
	*	- costs: vector que contiene todos los costos guardados.
	* Retorna: 
	*	- int: representa la posición en el vector.
*/
int Annealing::buscar_menor_tour (vector<double> costs) {
	double menor = costs[0];
	int posicion = 0;
	int size = costs.size();
	for (int i = 1 ; i < size ; i++) {
		if (costs[i] < menor) {
			menor = costs[i];
			posicion = i;
		}
	}
	return posicion;
}

/*
	* Método: Otros Métodos->vertices_aleatorios
	* Descripción: 
	* Parámetros: 
	*	- tour: representa el conjunto de vértices que se va a modificar.
	* Retorna: 
	*	- new_tour: el tour ingresado pero posterior a la permutación de un par de
	*		vértices.
*/
vector<int> Annealing::vertices_aleatorios(vector<int> tour) {
    vector<int> new_tour(tour);
	int n = this->matrizCostos->size;

	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<> disI(1, n - 2);

	int i = disI(rng);
	uniform_int_distribution<> disJ(i + 1, n - 1);
	int j = disJ(rng);

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

/*
	* Método: Otros Métodos->two_opt_first
	* Descripción: 
	* Parámetros: 
	*	- tour: el tour que se verá modificado.
	* Retorna: 
	*	- new_tour: el nuevo tour encontrado
*/
vector<int> Annealing::two_opt_first(vector<int> tour) {
    vector<int> new_tour(tour);
	double** c = this->matrizCostos->matriz;
	int n = this->matrizCostos->size;
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

/*
	* Método: Otros Métodos->tour_cost
	* Descripción: Encuentra el costo total del tour ingresado.
	* Parámetros: 
	*	- tour: el conjunto de vértices que conforman un tour.
	* Retorna: 
	*	- cost: el costo final
*/
double Annealing::tour_cost(vector<int> tour) {
	double** c = this->matrizCostos->matriz;
	int n = this->matrizCostos->size;
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



/*
	* Método: 
	* Descripción: 
	* Parámetros: 
	* Retorna: 
*/
