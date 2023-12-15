#include "Tour.h"

/*
	* Método: Otros Métodos->tour_cost
	* Descripción: 
	* Parámetros: 
	* Retorna: 
*/
Tour::Tour () {}

/*
	* Método: Otros Métodos->tour_cost
	* Descripción: 
	* Parámetros: 
	* Retorna: 
*/
double Tour::tour_cost (MatrizCosto* costos) {
	double** c = costos->matriz;
	int n = costos->size;
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
void Tour::print_tour (MatrizCosto* costos) {
    for (int i = 0 ; i < costos->size ; i++) {
        cout<< tour[i] << " ";
    }
    cout << endl;
}
