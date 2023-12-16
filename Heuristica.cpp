#include "Heuristica.h"

/*
	* Método: Constructor->Heuristica
	* Descripción: Crea la clase Heuristica, que busca un tour con el menor costo
	* posible, basado en el tour obtenido por la heurística 2-opt.
	* Parámetros: 
	*	- matriz: una clase matriz que contiene los costos entre todos los vértices.
	*	- maxIter: cantidad de iteraciones que realizarán.
	*	- tour: el conjunto de vértices que contienen un camino valido para el
	*		problema de TSP.
	*	- cost: el costo del tour anterior.
	* Retorna: 
	*	- void
*/
Heuristica::Heuristica (MatrizCosto* matriz, int maxIter, vector<int> tour, double cost, double minimo) {
	this->tour = tour;
	this->matrizCostos = matriz;
	int size = this->tour.size();
	// Representa la iteración en que se encuentra el algoritmo
	int iter = 0;
	// Representa los costos y los tours mínimos encontrados
	vector<double> costs_annealing;
	vector<vector<int>> tours_annealing;
	// Aquí se calcula que tan aleatorio es la elección de los nodos
	// en cada iteración.
	double aleatoriedad = ((double)size)/(double)maxIter;
	double acumulador = round(aleatoriedad);
	while (iter < maxIter) {
		vector<int> new_tour(two_opt_first(tour));
		double new_cost = tour_cost(new_tour);

		// Se agrega el último tour encontrado a tours_annealing y su costo a costs_annealing.
		if (iter == maxIter - 1) {
			tour = new_tour;
			cost = new_cost;
			tours_annealing.push_back(new_tour);
			costs_annealing.push_back(new_cost);
			// Se muestra el costo y el GAP asociados a esta iteración.
       		cout << iter << ") Cost: " << cost << " | GAP: " << cost - minimo << endl;
		// En caso de que el costo encontrado con 2-opt sea menor, se cambia el tour y costo actual.
		} else if (new_cost < cost) {
			tour = new_tour;
			cost = new_cost;
       		cout << iter << ") Cost: " << cost << " | GAP: " << cost - minimo << endl;
		// Finalmente, en caso de que el costo no sea menor, se agrega el tour a tours_annealing 
		// y se realiza un cambio entre dos vértices al azar.
		} else {
			tours_annealing.push_back(tour);
			costs_annealing.push_back(cost);
			// Aquí el acumulador se redondea y pasa a ser un entero.
			int acumuladorRedondeado = static_cast<int>(round(acumulador));

			// Si el acumulador es un poco más pequeño que el número de nodos, entonces
			// se disminuye el acumulador.
			if (acumuladorRedondeado >= size - 2) {
				tour = vertices_aleatorios(new_tour, acumuladorRedondeado - 2);
			} else {
				tour = vertices_aleatorios(new_tour, acumuladorRedondeado);
			}
			cost = tour_cost(tour);
       		cout << iter << ") No improvement: " << cost << " | GAP: " << cost - minimo << endl;
		}
		iter++;
		acumulador = acumulador + aleatoriedad;
    }

	// Se busca el tour con el menor costo entre los que se almacenaron y se guarda como el tour mínimo final.
	int posicionMenor = buscar_menor_tour(costs_annealing);
	this->tour = tours_annealing[posicionMenor];
}

/*
	* Método: Otros Métodos->busca_menor_tour
	* Descripción: Entre todos los costos resultantes, encuentra el menor.
	* Parámetros: 
	*	- costs: vector que contiene todos los costos guardados.
	* Retorna: 
	*	- int: representa la posición en el vector.
*/
int Heuristica::buscar_menor_tour (vector<double> costs) {
	double menor = costs[0];
	int posicion = 0;
	int size = costs.size();
	for (int i = 1 ; i < size ; i++) {
		if (costs[i] < menor) {
			menor = costs[i];
			posicion = i;
		}
	}
	return posicion;
}

/*
	* Método: Otros Métodos->vertices_aleatorios
	* Descripción: En base a un tour de entrada, se realiza un intercambio de nodos
	* aleatoriamente, dependiendo de la aleatoriedad con la que se trabaje.
	* Parámetros: 
	*	- tour: representa el conjunto de vértices que se va a modificar.
	*	- aleatoriedad: define desde que nodo se puede seleccionar, haciendo que
	*		mientras más iteraciones ocurran, menor va a ser el rango de nodos que
	*		se puede elegir.
	* Retorna: 
	*	- new_tour: el tour ingresado pero posterior a la permutación de un par de
	*		vértices.
*/
vector<int> Heuristica::vertices_aleatorios(vector<int> tour, int aleatoriedad) {
    vector<int> new_tour(tour);
	int n = this->matrizCostos->size;
	if (aleatoriedad == 0) aleatoriedad = 1;
	
	// Se define la fuente de números aleatorios
	random_device dev;
	// Se define un generador
	mt19937 rng(dev());
	// Se define los rangos del número generado para la variable i
	uniform_int_distribution<> disI(aleatoriedad, n - 2);

	int i = disI(rng);
	// Para que siempre sea un par de nodos válidos, j tiene que ser
	// mayor que i.
	uniform_int_distribution<> disJ(i + 1, n - 1);
	int j = disJ(rng);

	// Se realiza el cambio de aristas
	int k = i+1;
	int l = j;
	while(k < l) {
		int temp = new_tour[k];
		new_tour[k] = new_tour[l];
		new_tour[l] = temp;
		k++;
		l--;
	}
	// Se retorna el nuevo tour
    return(new_tour);
}

/*
	* Método: Otros Métodos->two_opt_first
	* Descripción: 
	* Parámetros: 
	*	- tour: el tour que se verá modificado.
	* Retorna: 
	*	- new_tour: el nuevo tour encontrado
*/
vector<int> Heuristica::two_opt_first(vector<int> tour) {
    vector<int> new_tour(tour);
	double** c = this->matrizCostos->matriz;
	int n = this->matrizCostos->size;
    for(int i = 0 ; i < n - 1 ; i++) {
        for(int j = i + 1 ; j < n ; j++) {
            // iteramos sobre todos los pares de aristas (i,i+1) y (j,j+1)

            // se destruye la aristas: (i,i+1) (j,j+1)
            double current_cost = c[new_tour[i]][new_tour[i+1]] + c[new_tour[j]][new_tour[(j+1)%n]];
            // se crea la aristas: (i,j) (i+1,j+1)
            double new_cost = c[new_tour[i]][new_tour[j]] + c[new_tour[i+1]][new_tour[(j+1)%n]];
            
            if(new_cost < current_cost) {// va a bajar el costo total del tour
                // se destruye la aristas: (i,i+1) (j,j+1)
                // se crea la aristas: (i,j) (i+1,j+1)
                // --> se invierte el orden de los nodos entre i+1 y j
                int k = i+1;
                int l = j;
                while(k < l) {
                    int temp = new_tour[k];
                    new_tour[k] = new_tour[l];
                    new_tour[l] = temp;
                    k++;
                    l--;
                }
                // retornamos el primer menor tour que encontramos
                return(new_tour);
            }
        }
    }
    return(new_tour);
}

/*
	* Método: Otros Métodos->tour_cost
	* Descripción: Calcula cuanto es el costo de recorrer todo el tour de
	* entrada y regresando al inicio.
	* Parámetros: 
	*	- tour: son todos los nodos (tiendas) en el orden que se recorren.
	* Retorna: 
	*	- cost: es el costo total que se obtiene al recorrer todo
	*		el tour.
*/
double Heuristica::tour_cost(vector<int> tour) {
	double** c = this->matrizCostos->matriz;
	int n = this->matrizCostos->size;
    double cost = 0.0;
    for (int i = 0 ; i < n - 1 ; i++) {
        cost += c[tour[i]][tour[i+1]];
    }
    cost += c[tour[n-1]][tour[0]];
    return cost;
}

/*
	* Método: Otros Métodos->print_tour
	* Descripción: Muestra el tour encontrado por el algoritmo, nodo por nodo.
	* Parámetros: 
	*	- void
	* Retorna:
	*	- void
*/
void Heuristica::print_tour () {
	cout << "Costo con Annealing = " << tour_cost(tour) << endl;
	cout << "Tour encontrado: ";
	for (auto it = tour.begin() ; it != tour.end() ; ++it) {
		cout << (*it) << " ";
	}
	cout << endl;
}
