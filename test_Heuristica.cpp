#include "Heuristica.h"

/*
	* Test para la clase Heuristica
	* En este código se prueba el funcionamiento de la clase Heuristica.
 */
int main () {
	cout << endl << "Test para la clase Heuristica:" << endl << endl;
	// Se leen archivos en las matrices
	MatrizCosto* matrizEjemplo1 = new MatrizCosto("ejemploMatriz1.txt");
	MatrizCosto* matrizEjemplo2 = new MatrizCosto("ejemploMatriz2.txt");
		MatrizCosto* matrizEjemplo3 = new MatrizCosto("ejemploMatriz3.txt");

	// Se crea un tour para los ejemplos
	vector<int> tour_ejemplo;
	for (int i = 0 ; i < 10 ; i++) {
		tour_ejemplo.push_back(i);
	}

	// Se hará la suposición de que el mínimo posible en cualquiera de los tour
	// es 0.0001 por temas de conveniencia
	double minimo = 0.0001;

	// Se resuelven los tours con Heuristica.
	// Se utiliza 40000.0 como el costo actual por temas demostrativos
	// Se muestra los datos del ejemplo1
	Heuristica ejemplo1(matrizEjemplo1, 20, tour_ejemplo, 400000.0, minimo);
	cout << endl << "Costo del tour del Ejemplo 1: " << ejemplo1.tour_cost(ejemplo1.tour) << endl;
	cout << "Tour Resultante Ejemplo 1: ";
	ejemplo1.print_tour();
	cout << endl << endl;

	// Se muestra los datos del ejemplo2
	Heuristica ejemplo2(matrizEjemplo2, 20, tour_ejemplo, 400000.0, minimo);
	cout << endl << "Costo del tour del Ejemplo 2: " << ejemplo2.tour_cost(ejemplo2.tour) << endl;
	cout << "Tour Resultante Ejemplo 2: ";
	ejemplo2.print_tour();
	cout << endl << endl;
	
	// Se muestra los datos del ejemplo3
	Heuristica ejemplo3(matrizEjemplo3, 20, tour_ejemplo, 400000.0, minimo);
	cout << endl << "Costo del tour del Ejemplo 3: " << ejemplo3.tour_cost(ejemplo3.tour) << endl;
	cout << "Tour Resultante Ejemplo 3: ";
	ejemplo3.print_tour();
	cout << endl << endl;

	return 0;
}
