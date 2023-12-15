#ifndef MATRIZCOSTO_H
#define MATRIZCOSTO_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
	* Clase
 */
class MatrizCosto {
	public:
		// Atributos
		int size;
		double** matriz;

		// Métodos
		// Constructor
		MatrizCosto(string filename);
		
		// Otros Métodos
		void printDatos();
};
#endif /* MATRIZCOSTO_H */
