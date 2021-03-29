#pragma once

struct tt_node{
    int data;
    tt_node * right;
    tt_node * down;
    tt_node * left;

    tt_node(int x){
        this->data = x;
        this->right = nullptr;
        this->down = nullptr;
        this->left = nullptr;
    }

    int value(){
        return this->data;
    }
};

class ternary_tree {
    private:
        tt_node * root;

        void _insert(int x, tt_node * root){
            // fill empty root
            if(root == nullptr) root = new tt_node(x);

            if(root->value() == x){
                // same value, create a new node down
                if(root->down == nullptr){
                    root->down = new tt_node(x); 
                    return;
                } 
                // if down already exists, 
                // do a recursive call
                // which would just create another
                // node down that one
                else _insert(x, root->down);
                return;
            }

            if(x < root->value()){
                // smaller value, insert left
                if(root->left == nullptr){
                    root->left = new tt_node(x); 
                    return;
                }
                else _insert(x, root->left);
                return;
            }else{
                // assume value is greater at this point
                // insert right
                if(root->right == nullptr){
                    root->right = new tt_node(x); 
                    return;
                }
                else _insert(x, root->right);
                return;
            }
            return;
        }


        void _print(tt_node * root){
            if(root == nullptr) return;

            cout << root->value() << " ";

            _print(root->left);
            _print(root->down);
            _print(root->right);
        }

        tt_node * _search(int x, tt_node * root){
            if(root == nullptr ) return nullptr;
            if(root->value() == x) return root;

            // no need to search down because 
            // it will always be the same value

            // search left subtree
            // if value is less than root
            if(x < root->value()  ) {
                if(root->left != nullptr)
                    return _search(x, root->left);
                else return nullptr;
            }else {

                // search right subtree
                // if value is greater than root
                if(root->right != nullptr)
                    return _search(x, root->right);
                else return nullptr;
            }

            return nullptr;

        }
    public:
        ternary_tree(int x){
            this->root = new tt_node(x);
        }

        void insert(int x){
            this->_insert(x, this->root);
        } // wrapper insert 

        void print(){
            this->_print(this->root);
        } // wrapper print

        tt_node * search(int x){
            return this->_search(x, this->root);
        } // wrapper search

};
