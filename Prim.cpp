#include "Prim.h"

/*
	* Método: Constructor->Prim
	* Descripción: Crea la clase Prim, sobre la cual se desarrollan los cálculos, y
	* lee el archivo de entrada para guardarlo en la matriz.
	* Parámetros:
	*	- entrada: Nombre del archivo que posee la matriz que se leerá.
	* Retorna: 
	*	- void
 */
Prim::Prim (string entrada) {
	// Se crea la MatrizCostos y se inicializa el costo final.
	this->costos = new MatrizCosto(entrada);
	//costos->readFile(entrada);
	this->costoFinal = 0;
}

/*
	* Método: Otros Metodos->print
	* Descripción: Muestra los valores que contiene el algoritmo Prim,
	* especificamente las aristas del árbol de coste mínimo y el costo final.
	* Parámetros:
	*	- void
	* Retorna:
	*	- void
 */
void Prim::print () {
	auto it = arista.begin();
	int i = 0;
	for (; it != arista.end() ; it++) {
		cout << "Arista " << i <<": (" << (*it)->i << "," << (*it)->j << ")" << "  Coste: " << (*it)->cost << endl;
		i += 1;
	}
	//Costo Final
	cout << endl << "Costo final: " << this->costoFinal << endl << endl << endl;
}

/*
	* Método: Otros Métodos->resolve
	* Descripción: Resuelve el algoritmo de Prim, buscando el árbol de coste mínimo
	* que se puede formar, uniendo todos los nodos, mediante un proceso iterativo,
	* en el cual se busca la arista mínima del árbol, hasta que se conecten todos
	* los nodos.
	* Parámetros:
	*	- void
	* Retorna:
	*	- void
 */
void Prim::resolve () {
	//Se ingresa el nodo inicial (ultimo)
	nodos.insert(this->costos->size-1);
	moverAAristasOut(this->costos->size-1);
	int nodosSize = nodos.size();
	while (nodosSize < this->costos->size) {
		buscarAristaMinima();
		nodosSize = nodos.size();
	}
}

/*
	* Método: Otros Métodos->moverAAristaOut
	* Descripción: Mueve Edges desde la matriz de costos (todas las existentes) a 
	* aristaOut (las que si se pueden alcanzar desde el árbol formado).
	* Parámetros:
	*	- nodo: el nodo nuevo que será ingresado.
	* Retorna:
	*	- void
 */
void Prim::moverAAristasOut (int nodo) {
	// Las aristas que tienen como destino al nodo ingresado
	for (int i = 0 ; i < nodo ; i++) {
		if (costos->matriz[i][nodo] != 0) {
			Edge* nuevaAristaDestino = new Edge(nodo,i,costos->matriz[i][nodo]);
			aristaOut.insert(nuevaAristaDestino);
			costos->matriz[i][nodo] = 0;
		}
	}

	// Las aristas que tienen como inicio al nodo ingresado
	for (int i = nodo ; i < costos->size ; i++) {
		if (costos->matriz[nodo][i] != 0) {
			Edge* nuevaAristaInicio = new Edge(i, nodo, costos->matriz[nodo][i]);
			aristaOut.insert(nuevaAristaInicio);
			costos->matriz[nodo][i] = 0;
		}
	}
}

/*
	* Método: Otros Métodos->buscarAristaMinima
	* Descripción: Encuentra la arista que tiene el menor valor dentro del arbol
	* Parámetros: Busca la arista de coste mínimo, debido a que el multiset está
	* ordenado por costo, la primera siempre será la de menor costo, pero puede que 
	* ya tenga ambos nodos entre sus aristas, por lo que se eliminan hasta encontrar
	* una que tenga solo un nodo ya almacenado.
	*	- void
	* Retorna:
	*	- void
 */
void Prim::buscarAristaMinima () {
	auto it = aristaOut.begin();

	//Agrega el nodo al vector
	if (contieneElNodo((*it)->i) && !contieneElNodo((*it)->j)) {
		insertarAristaYNodo((*it), (*it)->j);
		moverAAristasOut((*it)->j);
	} else if (contieneElNodo((*it)->j) && !contieneElNodo((*it)->i)) {
		insertarAristaYNodo((*it), (*it)->i);
		moverAAristasOut((*it)->i);
	}
	// 
	aristaOut.erase(it);
}

/*
	* Método: Otros Métodos->insertarAristaYNodo
	* Descripción: Inserta el nodo y arista ingresados
	* Parámetros:
	*	- nuevaArista: es la arista que que es ingresada en "arista" (árbol ya
	*	formado).
	*	- nodo: el nodo nuevo que se ingresa.
	* Retorna:
	*	- void
*/
void Prim::insertarAristaYNodo (Edge* nuevaArista, int nodo) {
	nodos.insert(nodo);
	arista.insert(nuevaArista);
	costoFinal += nuevaArista->cost;
}

/*
	* Método: Otros Métodos->contieneElNodo
	* Descripción: Verifica si un nodo ingresado se encuentra en el set de nodos.
	* Parámetros:
	*	- n: representa el nodo que se está buscando.
	* Retorna:
	*	- bool: true en caso de que lo contenga, false en caso contrario.
*/
bool Prim::contieneElNodo (int n) {
	if (nodos.find(n) != nodos.end()) {
		return true;
	}
	return false;
}
