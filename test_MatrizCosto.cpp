#include "MatrizCosto.h"

/*
	* Test para la clase MatrizCostos
	* En este archivo se prueban 3 matrices para demostrar que la clase y sus
	* métodos funcionan correctamente.
 */
int main () {
	/* Aqui se crean 3 objetos de prueba que leen cada uno el nombre de un archivo de entrada.
	 * Cuando se usa el constructor, lo que se hace es leer los archivos para determinar
	 * la cantidad de nodos que posee, y con ello el tamano de la matriz.
	 */
	MatrizCosto matrizPrueba1("matrizEntrada1.txt");
	/*	Cuando se realiza la funcion readFile, se lee cada elemento de la matriz
	 *	de entrada, y se guarda en la clase, finalmente mostrando la cantidad de nodos que
	 *	posee el archivo.
	 */
	
	// Se muestran las matrices resultantes
	cout << "Matriz de prueba 1:" << endl;
	matrizPrueba1.printDatos();
	cout << endl; 

	// Este esto se repite para las otras dos matrices de prueba.
	
	MatrizCosto matrizPrueba2("matrizEntrada2.txt");
	cout << "Matriz de prueba 2:" << endl;
	matrizPrueba2.printDatos();
	cout << endl; 
	
	MatrizCosto matrizPrueba3("matrizEntrada3.txt");
	cout << "Matriz de prueba 3:" << endl;
	matrizPrueba3.printDatos();
	cout << endl; 
	
	return 0;
}
