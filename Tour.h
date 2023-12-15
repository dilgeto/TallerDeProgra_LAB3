#ifndef TOUR_H
#define TOUR_H
#include <iostream>
#include <vector>
#include "MatrizCosto.h"

using namespace std;

/*
	*  Clase Tour:
	*  Esta clse se utiliza para definir un tour, que corresponde a 
	*  un camino que recorre todos los nodos de un sistema, este
	*  tiene un costo asociado.
 */
class Tour {
	public:
		// Atributos
		vector<int> tour;
		double totalCost;

		// Métodos
		// Constructor
		Tour();

		// Otros Métodos
		double tour_cost(MatrizCosto* costos);
		void print_tour(MatrizCosto* costos);
};

#endif /* TOUR_H */
