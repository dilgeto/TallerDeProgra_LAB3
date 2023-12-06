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
	
	ACO hormiguitas(matriz, golosino.getTour());
	hormiguitas.generateAntPaths(300);
	hormiguitas.print();
	return 0;
}
