#include "Comparator.h"

/*
	* Método: Otros Métodos->operator
	* Descripción: Operador que permite ordenar los elementos de un multiset
	* para que sean ordenados de menor a mayor, basándose en el costo.
	* Parámetros:
	*	- a: primer nodo a comparar
	*	- b: segundo nodo a comparar
	* Retorna: 
	*	- bool: true si el costo de a es menor que el de b, false en 
	*		otro caso.
 */
bool Comparator::operator ()(const Edge* a, const Edge*b) const {
	return a->cost < b->cost;
}
