#ifndef MATRIZCOSTO_H
#define MATRIZCOSTO_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class MatrizCosto {
	public:
		int size;
		double** matriz;

	//public:
		MatrizCosto(string filename);
		int getSize();
		double** getMatriz();
		void setSize(int size);
		void setCosto(int i, int j, double costo);
		void printDatos();
};
#endif /* MATRIZCOSTO_H */
