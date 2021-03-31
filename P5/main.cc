#include "tt.h"
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main(){
    tree words_tree = tree();

    words_tree.insert("behind");
    words_tree.insert("mind");
    words_tree.insert("kind");
    words_tree.insert("blind");
    words_tree.insert("unwind");
    words_tree.insert("back");
    words_tree.insert("black");
    words_tree.insert("jack");
    words_tree.insert("track");

    cout << "Words list: " << endl;
    words_tree.print();
    cout << endl;

    vector<std::string> rhyming_words = words_tree.ends_with("ind");
    cout << "Words ending with \"ind\"" << endl;
    for(std::string word : rhyming_words){
        cout << word << endl;
    }

    int end = rhyming_words.size();

    rhyming_words.clear();

    cout << endl;

    rhyming_words = words_tree.ends_with("ack");
    cout << "Words ending with \"ack\"" << endl;

    for(int i=end; i<rhyming_words.size(); ++i){
        cout << rhyming_words[i] << endl;
    }
}
