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
            if(word[0] == '\0'){
                root->is_word = true;
                return;
            }
        
            int i = (int) word[0] - 'a';
            if(root->children[i] == nullptr) {
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

        bool _search(std::string prefix, std::string term, t_node * root){
            // same as print but everytime we find a word,
            // check if it's equal to the search term and return
            // accordingly.
            if(root->is_word){
                if(prefix == term){
                    return true;
                }
            }

            for(int i=0; i<26; ++i){
                if(root->children[i] != nullptr){
                    std::string new_prefix = prefix + (char) (97 + i);
                    return _search(new_prefix, term, root->children[i]);
                }
            }

            return false;
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
            return _search("", word, this->root);
        }

        void insert(std::string str){
            return _insert(str, this->root);
        } // wrapper insert

};

