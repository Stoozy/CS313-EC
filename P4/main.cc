#include "tt.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(){
    tree words_tree = tree();

    words_tree.insert("red");
    words_tree.insert("orange");
    words_tree.insert("yellow");
    words_tree.insert("green");
    words_tree.insert("blue");
    words_tree.insert("violet");

    cout << "list: " <<  endl;
    words_tree.print();
    cout << endl;

    std::string search_term;
    for(;;){
        cout << "Search:";
        cin >> search_term;
        if(words_tree.search(search_term))
            cout << search_term << " was found in the tree." << endl;
        else cout << search_term << " was not found in the tree." << endl;
    }
    return 0;
} 
