/*
Se implementa el algoritmo de busqueda local con 2-opt para TSP
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int n=0;
double **c=nullptr; // matriz de costos c[i][j] = costo de ir de i a j

void load_data(string filename){
    ifstream file_obj(filename);
    file_obj>>n;
    c=new double*[n]; // memoria para todas las filas
    for(int i=0;i<n;i++) {
        c[i]=new double[n]; // inicializar a nullptr
        for(int j=0;j<n;j++) {
            c[i][j]=0.0;
        }
    }
    while(!file_obj.eof()){
        int i,j;
        double cost;
        file_obj>>i>>j>>cost;
        c[i][j]=c[j][i]=cost;
    }
    file_obj.close();
}

void print_data(){
    cout<<"n="<<n<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<c[i][j]<<" ";
        cout<<endl;
    }
}

int smaller_cost_neighbour(int i, vector<bool> visited) {
    int min_cost = 4; // todos los costos estan entre 0 y sqrt(8)
    int min_cost_index = -1;
    for (int j = 0; j < n; j++) {
        if (i!=j && c[i][j] < min_cost && !visited[j]) {
            min_cost = c[i][j];
            min_cost_index = j;
        }
    }
    return min_cost_index;
}

// consideremos que un tour es un vector de enteros con los numeros de los nodos
// en el orden en que se visitan
vector<int> make_greedy_tour(int current_node) {
    vector<int> tour;
    vector<bool> visited(n,false); // es el numero de nodos, todos los elementos se inicializan con false
    tour.push_back(current_node);
    visited[current_node] = true;
    for (int i = 0; i < n; i++) {
        int next_node = smaller_cost_neighbour(current_node, visited);
        if (next_node!= -1) {
            tour.push_back(next_node);
            //cout << "next_node: " << next_node << endl;
            visited[next_node] = true;
            current_node = next_node;
        }
    }
    return tour;
}

void print_tour(vector<int> tour) {
    for (int i = 0; i < n; i++) {
        cout<<tour[i]<<" ";
    }
    cout<<endl;
}

double tour_cost(vector<int> tour) {
    double cost = 0.0;
    for (int i = 0; i < n-1; i++) {
        cost += c[tour[i]][tour[i+1]];
    }
    cost += c[tour[n-1]][tour[0]];
    return cost;
}

vector<int> two_opt_first(vector<int> tour) {
    vector<int> new_tour(tour);

    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
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

int main() {
    load_data("data.txt");
//    print_data();

    vector<int> tour(make_greedy_tour(0));
    print_tour(tour);
    double cost = tour_cost(tour);
    cout<<"Cost: "<<cost<<endl;

    int maxIter=300;
    int iter=0;
    while (iter<maxIter) {
        vector<int> new_tour(two_opt_first(tour));
        double new_cost = tour_cost(new_tour);
        if (new_cost < cost) {
            tour = new_tour;
            cost = new_cost;
            cout<<iter<<") Cost: "<<cost<<endl;
        } else {
            cout<<iter<<") No improvement: "<<cost<<endl;
        }
        iter++;
    }

    return 0;
}
