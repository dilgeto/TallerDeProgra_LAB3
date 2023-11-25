#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

/*
	* Clase MatrizCostos:
	* Esta clase es utilizada para guardar los datos del archivo de entrada
	* y para obtener las aristas adyacentes del árbol.
	* La MatrizCostos está representada por un arreglo de arreglos de enteros,
	* en el que las filas son el nodo de inicio y las columnas los nodos de
	* destino. Además se cuenta con la cantidad de nodos que tiene.
 */
class MatrizCostos {
	public:
		// Atributos
		int size;
		int **matriz;

		// Metodos
		// Constructor
		MatrizCostos(string matrizEntrada);

		// OtrosMetodos
		void readFile(string matrizEntrada);
		void print();
};
