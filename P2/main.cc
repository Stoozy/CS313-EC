#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>

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
            // let 0 represent nonexistent edges 
            // (roads in our case)
            if(i == j) city[i][j] = 0;
            else if(i != j) city[i][j] = r;
            // mirror along the diagonal
            // so that there is only one
            // edge connecting two vertices
            // (not a multigraph)
            if(i>j) city[i][j] = city[j][i];
        }
    }
}

void print_city(int N, int ** city){
    // simply print the 2d array
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cout <<  city[i][j]  << " " ;
        }
        cout << endl;

    }
}

void gen_map(int N, int ** map, int ** city_a, int ** city_b){
    for(int r=0; r<2*N; ++r){
        for(int c=0; c<2*N; ++c){
            if(r<N && c<N) map[r][c] = city_a[r][c];
            // copying city b by offsetting coords
            // by N (row 7 would be row 2 of city b, 
            // if N was 5)
            if(r>=N && c>=N) {
                map[r][c] = city_b[r-N][c-N];
            }
        }
    }
}

void add_roads(int N, int n_roads, int **map){
    std::vector<int> nrc;
    int total_roads = 0 ;
    
    // iterating map matrix
    for(int r=0; r<2*N; ++r){
        for(int c=0; c<2*N; ++c){
            if(r>=N && c<N) {
                map[r][c] = map[c][r];
            }
            if(r < N && c >= N) {
                // make sure to create only n_roads
                if(total_roads != n_roads ){
                    // check if road has already been added
                    // by checking if it's in the nrc vector
                    if(std::find(nrc.begin(), nrc.end(), r) == nrc.end() &&
                        std::find(nrc.begin(), nrc.end(), c) == nrc.end()){
 
                        // generate random weight for road
                        // and update nrc and total_roads accordingly
                        map[r][c] = (rand() % 9 ) +1;
                        nrc.push_back(r);
                        nrc.push_back(c);
                        ++total_roads;

                    }
                }
                
            }
        }
    }
}

int main(){
    srand(time(0));

    int N = 0, n_roads = 0;
    cout << "Enter number of nodes: " << endl;
    cin >> N;

    // adjacency matrix 
    // of two cities
    // 2d arrays are basically 
    // pointers to pointers
    int ** city_g = new int*[N];
    int ** city_h = new int*[N];
    int ** map = new int*[2*N];

    int i=0;
    // dynamically allocate N items
    // for each pointer of pointers
    for(; i<N; ++i){
        city_g[i] = new int[N];
        city_h[i] = new int[N];
    }

    // dynamically allocate N items
    // for each pointer of pointers
    for(i=0; i<2*N; ++i){
        map[i] = new int[2*N];
    }

    gen_city(N, city_g);
    cout << endl;
    gen_city(N, city_h);
    gen_map (N, map, city_g, city_h);

    cout << "City G Adjacency Matrix: " << endl;
    print_city(N, city_g);
    cout << endl;
    cout << "City H Adjacency Matrix: " << endl;

    print_city(N, city_h);
    cout << endl;

    cout << "Map M: " << endl;
    print_city(2*N, map);

    cout << "How many roads would you like?" << endl;
    cin >>  n_roads;

    add_roads(N, n_roads, map);

    cout << "Map M: " << endl;
    print_city(2*N, map);


    // deleting everything 
    for(i=0; i<N; ++i){
        delete[] city_g[i];
        delete[] city_h[i];
    }

    for(i=0; i<2*N; ++i) delete[] map[i];

    delete[] city_g;
    delete[] city_h;
    delete[] map;

    return 0;
}
