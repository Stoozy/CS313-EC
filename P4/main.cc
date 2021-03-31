#include "tt.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(){
    tree words_tree = tree();
    words_tree.insert("red");
    words_tree.insert("green");
    words_tree.insert("blue");

    cout << "list: " <<  endl;
    words_tree.print();

    std::string search_term;
    while(1){
        cout << "Search:";
        cin >> search_term;
        if(words_tree.search(search_term)){
            cout << search_term << " was found in the tree." << endl;
        }else{
            cout << search_term << " was not found in the tree." << endl;
        }
    }

    return 0;
}
