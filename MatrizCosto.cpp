#include "MatrizCosto.h"

/*
	* Método: Constructor->MatrizCosto
	* Descripción: Crea la clase MatrizCosto, sobre el cual se guardan los costos
	* de viajar entre dos vértices para cada par.
	* Parámetros: 
	*	- filename: nombre del archivo que se leerá.
	* Retorna: 
	*	- void
*/
MatrizCosto::MatrizCosto (string filename) {
	ifstream file_obj(filename);
	int n = 0;
    file_obj>>n;
	size = n;
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

/*
	* Método: Otros Métodos->printDatos
	* Descripción: Muestra los costos de cada par de vértices.
	* Parámetros: 
	*	- void
	* Retorna:
	*	- void
*/
void MatrizCosto::printDatos () {
	cout << "n=" << size << endl;
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }
}
