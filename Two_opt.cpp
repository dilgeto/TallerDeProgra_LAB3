#include "Two_opt.h"

/*
	* Método: Constructor->Two_opt
	* Descripción: Algoritmo que busca un tour que tenga el menor costo posible,
	* realizando cambios en los nodos y guardándolos en caso de que el tour
	* resultante sea menor que el tour actual.
	* Parámetros:
	*	- matriz: representa el costo de viajar entre cualquier par de nodos.
	*	- maxIter: la cantidad máxima de iteraciones que realiza el algoritmo.
	*	- tour: representa el orden en que se recorren los nodos.
	*	- cost: el costo total de un tour de entrada.
	* Retorna: 
	*	- void
*/
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
       	}
       	iter++;
   	}
	this->tour = tour;
}

/*
	* Método: Otros Métodos->two_opt_first
	* Descripción: sobre un tour de entrada, se busca de forma iterativa 2
	* nodos que al intercambiarlos resulte en un costo total menor,
	* Parámetros: 
	*	- tour: representa el tour en el que se buscan los nodos.
	* Retorna: 
	*	- new_tour: es el tour en el que se realizó el intercambio de nodos,
	*		si es menor se retorna el tour, en caso contrario, se retorna
	*		el tour de entrada.
*/
vector<int> Two_opt::two_opt_first(vector<int> tour) {
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
	* Descripción: Calcula cuanto es el costo de recorrer todo el tour de
	* entrada y regresando al inicio.
	* Parámetros: 
	*	- tour: son todos los nodos (tiendas) en el orden que se recorren.
	* Retorna: 
	*	- cost: es el costo total que se obtiene al recorrer todo
	*		el tour.
*/
double Two_opt::tour_cost(vector<int> tour) {
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
	* Método: Otros Métodos->print_tour
	* Descripción: 
	* Parámetros: 
	* Retorna: 
*/
void Two_opt::print_tour () {
    for (int i = 0 ; i < this->matrizCostos->size ; i++) {
        cout<< tour[i] << " ";
    }
    cout << endl;
}
