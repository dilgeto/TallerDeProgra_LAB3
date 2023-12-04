#include "Two_opt.h"

Two_opt::Two_opt (MatrizCosto* matriz, int maxIter, vector<int> tour, double cost) {
	this->tour = tour;
	this->matrizCostos = matriz;
	int iter = 0;
	while (iter < maxIter) {
		vector<int> new_tour(two_opt_first(tour));
		double new_cost = tour_cost(new_tour);
		if (new_cost < cost) {
			tour = new_tour;
			cost = new_cost;
            		//cout << iter << ") Cost: " << cost << endl;
        	} else {
            		//cout << iter << ") No improvement: " << cost << endl;
        	}
        	iter++;
    	}
	cout << "Costo 2-opt = " << cost << endl;
}

vector<int> Two_opt::two_opt_first(vector<int> tour) {
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

vector<int> Two_opt::getTour () {
	return this->tour;
}

double Two_opt::tour_cost(vector<int> tour) {
	double** c = this->matrizCostos->getMatriz();
	int n = this->matrizCostos->getSize();
    double cost = 0.0;
    for (int i = 0 ; i < n - 1 ; i++) {
        cost += c[tour[i]][tour[i+1]];
    }
    cost += c[tour[n-1]][tour[0]];
    return cost;
}
