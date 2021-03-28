#include "bt.h"
#include <iostream>
#include <random>

using std::cout;
using std::endl;

int main(){
    srand(time(nullptr));

    binary_tree bt = binary_tree(0);

    for(int i=0; i<200; ++i){
        int val = rand()%500; 
        bt.insert(val);
    }

    bt.print();

    int search = rand()%500;
    bt_node * n = bt.search(search);

    if(n != nullptr)
        cout << "Found node with value " << n->value();
    else cout << "Could not find " << search  << " in tree." << endl;

    return 0;
}
