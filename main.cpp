#include <iostream>
#include "MatrizCosto.h"
#include "Goloso.h"
#include "Two_opt.h"
#include "Annealing.h"
#include "Prim.h"

int main () {
	while (true) {
		string entrada;
		cout << "Si desea finalizar la ejecucion del programa, ingrese 'exit'";
		cout << endl;
		cout << "Ingrese el nombre del archivo: ";
		cin >> entrada;
		cout << endl;
		ifstream file(entrada);


		// En caso de que el archivo no exista, se cierra y se termina la ejecucion
		if (entrada == "exit") {
			return 0;
		} else if (!file.is_open()) {
			cout << "El archivo ingresado no existe." << endl << endl;
			file.close();
		} else {
			int iteraciones;
			cout << "Ingrese la cantidad de iteraciones: ";
			cin >> iteraciones;
			cout << endl;
			if (iteraciones < 0) {
				cout << "El numero de iteraciones debe ser mayor que 0." << endl << endl;
			} else {
				Prim mst(entrada);
				mst.resolve();
				double minimo = mst.costoFinal;
				cout << "Costo Minimo por MST = " << minimo << endl;
				
				MatrizCosto* matriz = new MatrizCosto(entrada);
				Goloso golosino(matriz, 0);
				double costoGoloso = golosino.tour_cost();
				cout << "Costo Goloso = " << costoGoloso << endl;
				Two_opt dosOpt(matriz, iteraciones, golosino.tour, costoGoloso);
				cout << "Costo 2-opt = " << dosOpt.tour_cost(dosOpt.tour) << endl;
			
				Annealing annealing(matriz, iteraciones, dosOpt.tour, dosOpt.tour_cost(dosOpt.tour), minimo);
				annealing.print_tour();
				cout << endl << endl;

				// Comparaciones de GAP
			}
		}
	}
	return 0;
}
