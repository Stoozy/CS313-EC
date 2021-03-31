#pragma once
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

// simple map

struct t_node{
    // keep current nodes child nodes
    t_node * children[26];
    bool is_word;

    t_node(){
        // false by default
        this->is_word = false;
        for(int i=0; i<26; ++i)
            this->children[i] = nullptr;

    }
};

class tree {
    private:
        t_node * root;

        void _insert(std::string word, t_node * root){
            // reached end of word, 
            // mark root as word (base case)
            if(word[0] == '\0'){
                root->is_word = true;
                return;
            }
        
            // i represents the index of
            // the char from the word in 
            // the alphabet
            int i = (int) word[0] - 'a';
            if(root->children[i] == nullptr) {
                // children for the current 
                // character doesn't exit, 
                // create the children by 
                // initializing t_node
                t_node * np = new t_node();
                root->children[i] = np;

                word.erase(word.begin());
                _insert(word, np);
            }else{
                word.erase(word.begin());
                _insert(word, root->children[i]);
            }

        }

        void _print(std::string prefix, t_node  * root){
            // reached the end
            // of the word;
            // print it 
            if(root->is_word)
                cout << prefix << endl;

            // for every letter 
            // check if it has any subtree
            // if it does, that means the letter leads to a word, 
            // then add it to the prefix and call print recursively
            for(int i=0; i<26; ++i){
                if(root->children[i] != nullptr){
                    std::string new_prefix = prefix + (char) (97 + i);
                    _print(new_prefix, root->children[i]);
                }
            }

            return;
        }

        bool _search(std::string term, t_node * root){
            // iteratively check every char in the search term
            for(int i=0; i<term.length(); ++i){
                int n = term[i] - 'a';
                if(!root->children[n])
                    return false; // reached dead end
                root = root->children[n];
            }
            // if the word was found then 
            // root would be a valid node 
            // with is_word set to true
            return (root != nullptr && root->is_word);
        }

    public:
        tree(){
            this->root = new t_node();
        }

        void print(){
            // call with starter prefix
            return _print("", this->root);
        } //wrapper print

        bool search(std::string word){
            return _search(word, this->root);
        }

        void insert(std::string str){
            return _insert(str, this->root);
        } // wrapper insert

};

