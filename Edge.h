#ifndef EDGE_H
#define EDGE_H
#include <iostream>

using namespace std;

/* 
	* Clase Edge:
	* Esta clase es usada para representar las aristas en el árbol,
	* presentando un nodo de inicio, otro de destino y el costo.
	* Clase que está representada por 3 enteros, siendo "i" el nodo
	* de inicio, "j" el nodo de destino y "cost" el costo asociado.
 */
class Edge {
	public:
		// Atributos
		int i;
		int j;
		int cost;

		// Metodos
		// Constructor
		Edge(int i, int j, int cost);
};

#endif /* EDGE_H */
