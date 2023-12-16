#ifndef MATRIZCOSTO_H
#define MATRIZCOSTO_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
	* Clase MatrizCosto:
	* Esta clase es utilizada para guardar los datos del archivo de entrada
	* y para obtener las aristas adyacentes del árbol.
	* La MatrizCosto está representada por un arreglo de arreglos de enteros,
	* en el que las filas son el nodo de inicio y las columnas los nodos de
	* destino. Además se cuenta con la cantidad de nodos que tiene.
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
