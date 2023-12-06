#include <iostream>
#include "MatrizCosto.h"
#include "Goloso.h"
#include "Two_opt.h"
#include "ACO.h"

int main () {
	MatrizCosto* matriz = new MatrizCosto("data.txt");
	Goloso golosino(matriz, 0);
	double costoGoloso = golosino.tour_cost();
	cout << "Costo Goloso = " << costoGoloso << endl;

	Two_opt dosOpt(matriz, 300, golosino.getTour(), costoGoloso);
	
	ACO hormiguitas(matriz);
	hormiguitas.generateAntPaths(300);
	hormiguitas.encontrarTour();
	cout << "Costo Hormigas = " << hormiguitas.tour_cost(hormiguitas.getTour()) << endl;
	hormiguitas.print();
	return 0;
}
