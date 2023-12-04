#include <iostream>
#include "MatrizCosto.h"
#include "Goloso.h"
#include "Two_opt.h"
#include "Heuristica.h"

int main () {
	MatrizCosto* matriz = new MatrizCosto("data.txt");
	Goloso golosino(matriz, 0);
	double costoGoloso = golosino.tour_cost();
	cout << "Costo Goloso = " << costoGoloso << endl;

	Two_opt dosOpt(matriz, 300, golosino.getTour(), costoGoloso);
	
	double costoHeuristica = 8.2;
	cout << "Costo Heuristica = " << costoHeuristica << endl;
	return 0;
}
