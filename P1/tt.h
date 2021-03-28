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
}

class ternary_tree {
    private:
        tt_node * root;
        void _insert(int x, tt_node * root){
        }
    public:
        ternary_tree(){}
        ternary_tree(int x){
            this->root = new tt_node(x);
        }

        void insert(){

        }
}
