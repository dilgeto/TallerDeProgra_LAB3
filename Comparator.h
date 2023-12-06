#ifndef COMPARATOR_H
#define COMPARATOR_H
#include <iostream>
#include <set>
#include "Edge.h"

using namespace std;

/*
	* Clase Comparator:
	* Esta clase es usada para comparar las aristas que se insertan en los
	* multiset, para que estñen ordenados por el valor de su costo.
	* El comparador solamente tiene el método que permite ordenar las 
	* aristas por su coste, de menor a mayor.
*/
class Comparator {
	public:
		//Methods
		bool operator ()(const Edge* a, const Edge*b) const;
		//Atributes
};

#endif /* COMPARATOR_H */
