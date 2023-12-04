#include "Goloso.h"

Goloso::Goloso (MatrizCosto* matriz, int current_node) {
	this->matrizCostos = matriz;
	int n = this->matrizCostos->getSize();
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

int Goloso::smaller_cost_neighbour (int i, vector<bool> visited) {
    int min_cost = 4; // todos los costos estan entre 0 y sqrt(8)
    int min_cost_index = -1;
	int n = this->matrizCostos->getSize();
	double** c = matrizCostos->getMatriz();
    for (int j = 0; j < n ; j++) {
        if (i!=j && c[i][j] < min_cost && !visited[j]) {
            min_cost = c[i][j];
            min_cost_index = j;
        }
    }
    return min_cost_index;
}

double Goloso::tour_cost() {
	vector<int> tour = getTour();
	double** c = this->matrizCostos->getMatriz();
	int n = this->matrizCostos->getSize();
    double cost = 0.0;
    for (int i = 0 ; i < n - 1 ; i++) {
        cost += c[tour[i]][tour[i+1]];
    }
    cost += c[tour[n-1]][tour[0]];
    return cost;
}

vector<int> Goloso::getTour () {
	return this->tour;
}

void Goloso::print_tour () {
    for (int i = 0 ; i < this->matrizCostos->getSize() ; i++) {
        cout<< tour[i] << " ";
    }
    cout << endl;
}
