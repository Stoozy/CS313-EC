#include <iostream>
#include <random>

using std::cout;
using std::cin;
using std::endl;

void gen_graph(int N, int ** graph){
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            int r = rand() % 10;
            // let 0 represent nonexistent edges 
            // (roads in our case)
            if(i == j) graph[i][j] = 0;
            else if(i != j) graph[i][j] = r;
            if(i>j) graph[i][j] = graph[j][i];
        }
    }
}


void print_graph(int N, int ** graph){
    // simply print the 2d array
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cout <<  graph[i][j]  << " " ;
        }
        cout << endl;
    }
}

int get_cl(int v1, int v2, int cpl, int ** graph){
    if(graph[v1][v2] != 0)
        return cpl+graph[v1][v2];
    return cpl;
}

int longest_path(int v1, int v2, int cpl, int N, int ** graph){
    static int max;

    int cl = get_cl(v1, v2, cpl, graph);
    if(cl>max) max = cl;

    for(int c=v1+1; c<N; ++c){
        longest_path(c, v2, cpl+graph[v1][c], N, graph);
    }

    return max;
}

int main(){
    srand(time(0));
    int g_size;

    cout << "Enter number of nodes in the graph: ";
    cin >> g_size;

    int ** graph = new int *[g_size];

    // allocate rows
    for(int i=0; i<g_size; ++i)
        graph[i] = new int[g_size];

    gen_graph(g_size, graph);

    print_graph(g_size, graph);

    int lp = longest_path(0, g_size-1, 0, g_size, graph);

    cout << "Longest path: " << lp << endl;

    for(int i=0; i<g_size; ++i)
        delete[] graph[i]; // remove inner pointers
    delete [] graph; // remove outer pointers


    return 0;
}
