#pragma once
#include <iostream>

using std::cout;
using std::endl;

struct bt_node {
	int data;		
	bt_node * right;
	bt_node * left;

	bt_node(int x){
		this->data = x;
		this->right = nullptr;
		this->left = nullptr;
	}

	int value(){
		return this->data;
	}
};

class binary_tree{
	private:
		bt_node * root;

		void _insert(int x, bt_node * root){
            // empty root 
			if(root == nullptr){
				this->root = new bt_node(x);
			}

            // insert to the left if 
            // value is less than root
            if(x < root->value()){
                if(root->left == nullptr){
                    root->left = new bt_node(x); // left of root is empty, can insert
                    return;
                }else{
                    _insert(x, root->left); // left of root is not empty, insert to right subtree
                }
            }
            // insert to the right if 
            // value is greater than root
            if(x > root->value()){
                if(root->right == nullptr){
                    root->right = new bt_node(x); // right of root is empty, can insert
                    return;
                }else{
                    _insert(x, root->right); // right of root is not empty, insert to right subtree
                }
            }
		}  

        void _print( bt_node * root){
            if(root == nullptr) return;


            cout  << root->value() << " ";
            _print(root->left);
            _print(root->right);
        }
        
        bt_node * _search(int x, bt_node * root){
            if(root == nullptr ) return nullptr;
            if(root->value() == x) return root;

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
		binary_tree(){}

		binary_tree(int x){
			this->root = new bt_node(x);
			this->root->left = nullptr;
			this->root->right = nullptr;
				
		}

		void insert(int x){
			this->_insert(x, this->root);
		} // wrapper insert


        bt_node * search(int x){
            return this->_search(x, this->root);
        } // wrapper search

        void print(){
            this->_print( this->root);
        } // wrappper print


};

