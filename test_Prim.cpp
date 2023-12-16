#include "Prim.h"

/*
	* Test para la clase Prim
	* En este archivo se prueban 2 matrices pequeñas para demostrar la funcionalidad
	* de la clase Prim.
 */
int main () {
	// Se crean los objetos
	Prim ejemplo1("ejemploMatriz1.txt");
	Prim ejemplo2("ejemploMatriz2.txt");

	// Se muestra la matriz del primer ejemplo
	cout << "Matriz del primer ejemplo:" << endl;
	ejemplo1.costos->printDatos();
	cout << endl;

	// Se resuelva y se imprime el primer ejemplo
	ejemplo1.resolve();
	ejemplo1.print();

	// Se muestra la matriz del segundo ejemplo
	cout << "Matriz del segundo ejemplo:" << endl;
	ejemplo2.costos->printDatos();
	cout << endl;

	// Se resuelva y se imprime el segundo ejemplo
	ejemplo2.resolve();
	ejemplo2.print();

	return 0;
}
