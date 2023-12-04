#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <ctime>

using namespace std;

int main() {
    ofstream file_obj("data.txt");
    ofstream file_obj2("points.txt");
    int n=100;
    default_random_engine generator;
    generator.seed(time(0) );
    uniform_real_distribution<double> distribution(-1.0,1.0);
    double x,y;
    vector<pair<double,double>> points;
    file_obj2<<n<<endl;
    for (int i = 0; i < n; i++) {
            x = distribution(generator);
            y = distribution(generator);
            points.push_back(make_pair(x,y));
            if (i!=n-1)
                file_obj2<<x<<" "<<y<<endl;
            else
                file_obj2<<x<<" "<<y;
    }
    file_obj2.close();
    file_obj<<n<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            double dx=(points[i].first-points[j].first);
            double dy=(points[i].second-points[j].second);
            double dist=sqrt(dx*dx+dy*dy);
            if (i!=n-2)
                file_obj<<i<<" "<<j<<" "<<dist<<endl;
            else
                file_obj<<i<<" "<<j<<" "<<dist;
        }
    }
    file_obj.close();
    return 0;
}
