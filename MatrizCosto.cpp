#include "MatrizCosto.h"

MatrizCosto::MatrizCosto (string filename) {
	ifstream file_obj(filename);
	int n = 0;
    file_obj>>n;
	setSize(n);
    matriz = new double*[n]; // memoria para todas las filas
    for(int i = 0 ; i < n ; i++) {
        matriz[i] = new double[n]; // inicializar a nullptr
        for(int j = 0 ; j < n ; j++) {
            matriz[i][j] = 0.0;
        }
    }
    while(!file_obj.eof()){
        int i,j;
        double cost;
        file_obj>>i>>j>>cost;
        matriz[i][j] = matriz[j][i] = cost;
    }
    file_obj.close();
}

int MatrizCosto::getSize () {
	return this->size;
}

double** MatrizCosto::getMatriz () {
	return this->matriz;
}

void MatrizCosto::setSize (int size) {
	this->size = size;
}

void MatrizCosto::setCosto (int i, int j, double costo) {
	this->matriz[i][j] = costo;
}

void MatrizCosto::printDatos () {
	cout << "n=" << size << endl;
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }
}
