#include <iostream>
#include <iomanip>
#include <random>

using std::cout;
using std::cin;
using std::setw;
using std::endl;

/*
 * Generates randomly weighted
 * roads for a specific city
 *
 */

void gen_city(int N, int ** city){
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            int r = rand() % 10;
            if(i == j) city[i][j] = -1;
            else if(i != j) city[i][j] = r;

            if(i>j) city[i][j] = city[j][i];
        }
    }
}

void print_city(int N, int ** city){
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(city[i][j] >= 0)
                cout <<  " " << city[i][j]  << " " ;
            else  cout <<  city[i][j]  << " " ;

        }
        cout << endl;

    }
}

int main(){
    srand(time(0));

    int N = 0;
    cout << "Enter number of nodes: " << endl;
    cin >> N;

    // adjacency matrix 
    // of two cities
    int ** city_g = new int*[N];
    int ** city_h = new int*[N];

    for(int i=0; i<N; ++i){
        city_g[i] = new int[N];
        city_h[i] = new int[N];
    }

    gen_city(N, city_g);
    cout << endl;
    gen_city(N, city_h);

    cout << "City G Adjacency Matrix: " << endl;
    print_city(N, city_g);
    cout << endl;
    cout << "City H Adjacency Matrix: " << endl;
    print_city(N, city_h);

    for(int i=0; i<N; ++i){
        delete[] city_g[i];
        delete[] city_h[i];
    }

    delete[] city_g;
    delete[] city_h;

    return 0;
}
