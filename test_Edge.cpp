#include <set>
#include <string>
#include "Edge.h"

/*
	* Test para la clase Edge
	* En este código se pueden probar las funcionalidad de la clase Edge.
 */
int main () {
	// El multiset que contendrá las aristas
	multiset<Edge*> s;
	char opcion;
	string i;
	string j;
	string cost;
	string nodo;

	// Aquí se despliega un menú en el cual se puede elegir como trabajar con
	// la clase, permitiendo agregar una nueva arista, mostrar las aristas, buscar
	// aristas en base a los nodos y salir.
	while (true) {
		cout << "Elija una alternativa:" << endl;
		cout << "1. Agregar una arista" << endl;
		cout << "2. Mostrar aristas" << endl;
		cout << "3. Buscar que aristas contienen cierto nodo" << endl;
		cout << "4. Salir del test" << endl;
		cout << "Ingrese su decision: ";
		cin >> opcion;
		cout << endl;
		switch (opcion) {
			case '1':
				// Creacion de aristas (Edges)
				cout << "Ingrese el valor de i: ";
				cin >> i;
				cout << "Ingrese el valor de j: ";
				cin >> j;
				cout << "Ingrese el valor de cost: ";
				cin >> cost;
				cout << endl;
				// Se inserta el Edge en un multiset
				s.insert(new Edge(stoi(i),stoi(j),stoi(cost)));
				break;
			case '2':
				cout << "Aristas ingresadas:" << endl;
				for (auto it = s.begin() ; it != s.end() ; ++it) {
					cout << "(" << (*it)->i << "," << (*it)->j << ") Costo = ";
					cout << (*it)->cost << endl;
				}
				cout << endl;
				break;
			case '3':
				// Verificamos cuales son los Edges que contienen un nodo ingresado.
				cout << "Ingrese el nodo que se desea buscar: ";
				cin >> nodo;
				cout << endl;
				cout << "Contienen el nodo " << nodo << ":" << endl;
				for (auto it = s.begin() ; it != s.end() ; ++it) {
					if ((*it)->i == stoi(nodo) || (*it)->j == stoi(nodo)) {
						cout << "(" << (*it)->i << "," << (*it)->j;
						cout << ") Costo = " << (*it)->cost << endl;
					}
				}
				cout << endl;
				break;
			case '4':
				return 0;
				break;
		}
	}
}
