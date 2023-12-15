#include "Goloso.h"

/*
	* Test para la clase Goloso
	* En este código se prueba el funcionamiento de la clase Goloso.
 */
int main () {
	// Se leen archivos en las matrices
	MatrizCosto* matrizEjemplo1 = new MatrizCosto("");
	MatrizCosto* matrizEjemplo2 = new MatrizCosto("");
	MatrizCosto* matrizEjemplo3 = new MatrizCosto("");

	// Se resuelven los tours con goloso.
	Goloso ejemplo1(matrizEjemplo1, 0);
	Goloso ejemplo2(matrizEjemplo2, 0);
	Goloso ejemplo3(matrizEjemplo3, 0);

	// Se muestra los datos del ejemplo1
	cout << "Costo del tour del Ejemplo 1: " << ejemplo1.costo << endl;
	cout << "Tour Resultante Ejemplo 1:";
	ejemplo1.print_tour();

	// Se muestra los datos del ejemplo2
	cout << "Costo del tour del Ejemplo 2: " << ejemplo2.costo << endl;
	cout << "Tour Resultante Ejemplo 2:";
	ejemplo2.print_tour();
	
	// Se muestra los datos del ejemplo3
	cout << "Costo del tour del Ejemplo 3: " << ejemplo3.costo << endl;
	cout << "Tour Resultante Ejemplo 3:";
	ejemplo3.print_tour();
	
	return 0;
}
