#include "Goloso.h"

/*
	* Método: Constructor->Goloso
	* Descripción: Crear la clase Goloso, en esta clase se desarrollan los
	* cálculos para intentar obtener el tour mínimo en base a una matriz
	* de costos.
	* Parámetros: 
	*	- matriz:
	*	- current_node:
	* Retorna: 
	*	-void
*/
Goloso::Goloso (MatrizCosto* matriz, int current_node) {
	this->matrizCostos = matriz;
	int n = this->matrizCostos->size;
	vector<int> tour;
    vector<bool> visited(n, false); // es el numero de nodos, todos los elementos se inicializan con false
    tour.push_back(current_node);
    visited[current_node] = true;
    for (int i = 0 ; i < n ; i++) {
        int next_node = smaller_cost_neighbour(current_node, visited);
        if (next_node!= -1) {
            tour.push_back(next_node);
            visited[next_node] = true;
            current_node = next_node;
        }
    }
    this->tour = tour;
}

/*
	* Método: Otros Métodos->smaller_cost_neighbour
	* Descripción: 
	* Parámetros: 
	*	- i: 
	*	- visited: 
	* Retorna: 
	*	- min_cost_index:
*/
int Goloso::smaller_cost_neighbour (int i, vector<bool> visited) {
    int min_cost = 4; // todos los costos estan entre 0 y sqrt(8)
    int min_cost_index = -1;
	int n = this->matrizCostos->size;
	double** c = matrizCostos->matriz;
    for (int j = 0; j < n ; j++) {
        if (i!=j && c[i][j] < min_cost && !visited[j]) {
            min_cost = c[i][j];
            min_cost_index = j;
        }
    }
    return min_cost_index;
}

/*
	* Método: Otros Métodos->tour_cost
	* Descripción: 
	* Parámetros: 
	* Retorna: 
*/
double Goloso::tour_cost () {
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
void Goloso::print_tour () {
    for (int i = 0 ; i < this->matrizCostos->size ; i++) {
        cout<< tour[i] << " ";
    }
    cout << endl;
}
