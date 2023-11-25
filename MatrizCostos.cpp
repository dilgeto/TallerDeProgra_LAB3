#include "MatrizCostos.h"

/*
	* Método: Constructor->MatrizCostos
	* Descripción: Crea una matriz del tamaño de la cantidad de líneas 
	* que tenga el archivo.
	* Parámetros: 
	*	- matrizEntrada: Nombre de la matriz del archivo de entrada.
	* Retorna:
	*	- void
 */
MatrizCostos::MatrizCostos (string matrizEntrada) {
	ifstream file(matrizEntrada);
	string line;
	int size = 0;
	while (getline(file, line)) {
		size += 1;
	}
	file.close();

	this->size = size;
	this->matriz = new int*[size];
	for (int i = 0 ; i < size ; i++) {
		this->matriz[i] = new int[size];
	}
}

/*	Agrega los valores desde el archivo de entrada a la clase MatrizCostos
 */

/*
	* Método: Otros Métodos->readFile
	* Descripción: Agrega los valores desde el archivo de entrada a la 
	* clase MatrizCostos e indica la cantidad de nodos que tiene.
	* Parámetros:
	*	- matrizEntrda: el nombre del archivo que contiene la matriz.
	* Retorna:
	*	- void
 */
void MatrizCostos::readFile(string matrizEntrada) {
	ifstream file(matrizEntrada);
	string line, value;
	int countI = 0, countJ = 0;

	while (getline(file, line)) {
		stringstream charStream;
		charStream << line;
		stringstream part(line);
		while (getline(part, value, ' ')) {
			matriz[countI][countJ] = stoi(value);
			countJ += 1;
		}
		countJ = 0;
		countI += 1;
	}

	file.close();
	cout << "Cantidad de nodos: " << countI << endl << endl;
}

/*
	* Método: Otros Métodos->print
	* Descripción: Imprime por terminal la matriz almacenada.
	* Parámetros:
	*	- void
	* Retorna:
	*	- void
 */
void MatrizCostos::print() {
	for (int i = 0 ; i < this->size ; i++) {
		for (int j = 0 ; j < this->size ; j++) {
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
}
