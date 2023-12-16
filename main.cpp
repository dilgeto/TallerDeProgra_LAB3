#include <iostream>
#include <chrono>
#include "MatrizCosto.h"
#include "Goloso.h"
#include "Two_opt.h"
#include "Annealing.h"
#include "Prim.h"

using namespace std;
using namespace std::chrono;
/*
	* Este código intenta encontrar una aproximación al óptimo para el 
	* problema del vendedor viajero (TSP). Mediante el uso de un 
	* heurística basada en 2-opt.
 */
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
				// Resolucion de Prim
				Prim mst(entrada);
				mst.resolve();
				double minimo = mst.costoFinal;
				
				// Se genera la matriz
				MatrizCosto* matriz = new MatrizCosto(entrada);
				
				// Se encuentra un tour por Goloso.
				Goloso goloso(matriz, 0);
				double costoGoloso = goloso.tour_cost();

				// Se encuentra un tour por 2-opt.
				Two_opt dosOpt(matriz, iteraciones, goloso.tour, costoGoloso);
				
				// Inicio del tiempo
				auto start = high_resolution_clock::now();
				// Se encuentra un tour con la heurística.
				Annealing annealing(matriz, iteraciones, dosOpt.tour, dosOpt.tour_cost(dosOpt.tour), minimo);
				// Término del tiempo
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				// Se muestran todos los resultados
				cout << endl << "Tiempo empleado en la heuristica: ";
				cout << duration.count() << " milisegundos." << endl << endl;
				cout << "Costo Minimo por MST = " << minimo << endl;
				cout << "Costo Goloso = " << costoGoloso << endl;
				cout << "Costo 2-opt = " << dosOpt.tour_cost(dosOpt.tour) << endl;
				annealing.print_tour();
				// Comparaciones de GAP
				cout << endl << "El GAP final con la solucion encontrada es: " << annealing.tour_cost(annealing.tour) - minimo << endl;
				cout << endl << endl;

			}
		}
	}
	return 0;
}
