#include <iostream>
#include <string>
#include <set>
#include "Comparator.h"
#include "MatrizCosto.h"

using namespace std;

/*
	* Clase Prim:
	* Esta clase es usada para resolver el problema de Minimum Spanning Tree,
	* basándose en el algoritmo de Prim, 
	* Prim está respresentado por una matriz con las aristas de entrada, 3 
	* multisets, el primero representa los nodos que ya fueron visitados,
	* el segundo representa las aristas que ya fueron completadas y el 
	* tercero un multiset ordenado por el valor del costo, en el cual
	* se almacenan las aristas que son adyacentes a los nodos ya visitados.
	* Además de un entero que representa el costo final cuando se encuentra
	* el árbol mínimo.
 */
class Prim {
	public:
		// Atributos
		double costoFinal;
		MatrizCosto *costos;
		multiset<int> nodos;
		multiset<Edge*> arista;
		multiset<Edge*, Comparator> aristaOut;

		// Metodos
		// Constructor
		Prim(string entrada);
		
		// Otros metodos
		void resolve();
		void print();
		void buscarAristaMinima();
		bool contieneElNodo(int n);
		void moverAAristasOut(int nodo);
		void insertarAristaYNodo(Edge* nuevaArista, int nodo);
};
