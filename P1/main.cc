#include <iostream>
#include <random>
#include <chrono>

using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;
using std::cout;
using std::endl;

#include "bt.h"
#include "tt.h"

int main(){
    srand(time(0));

    long long bt_avg = 0, tt_avg = 0;

    binary_tree bt = binary_tree(0);
    ternary_tree tt = ternary_tree(0);


    auto ct_begin = steady_clock::now();
    for(unsigned long long i=0; i<100000000; ++i){
        long val = rand()%100000000;
        bt.insert(val);
        tt.insert(val);
    }
    auto ct_end = steady_clock::now();
    cout << "Creating trees took " << duration_cast<milliseconds>(ct_end - ct_begin).count() << "ms long";


    for(unsigned long long i=0; i<10000000; ++i){
        int search = rand()%10000000;

        auto bt_begin = steady_clock::now();
        bt_node * bn = bt.search(search);
        if(bn != nullptr) // value was found 
            cout << bn->value() << endl;

        auto bt_end = steady_clock::now();
        bt_avg += duration_cast<milliseconds>(bt_end - bt_begin).count();


        auto tt_begin = steady_clock::now();
        tt_node * tn = tt.search(search);
        
        if(tn != nullptr) // value was found
            cout << tn->value() << endl;

        auto tt_end = steady_clock::now();
        tt_avg += duration_cast<milliseconds>(tt_end - tt_begin).count();
    }

    cout << "Binary Tree search time total: " << bt_avg << "ms" << endl;
    cout << "Ternary Tree search time total: " << tt_avg << "ms" << endl;

    return 0;
}
