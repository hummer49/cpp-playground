/*
Binary Search Tree (BST)


*/

#include<iostream>

class Node{
    private:
        Node *parent;
        Node *left;
        Node *right;
        int key;
    public:
        Node(int key):parent(nullptr),left(nullptr),right(nullptr),key(key){}
        void set_parent(Node *parent){
            this->parent = parent;
        }
        Node *get_parent() const {
            return this->parent ;
        }
        void set_left(Node *left){
            this->left = left;
        }
        Node *get_left() const {
            return this-> left;
        }
        void set_right(Node *right){
            this->right = right;
        }        
        Node *get_right() const {
            return this->right ;
        }
        int get_key() const {
            return key;
        }
    
};

class BST{
    private:
        Node *root;
        void destroy_BST(Node *node){
            if(node!=nullptr){
                destroy_BST(node->get_left());
                destroy_BST(node->get_right());
                delete node;
            }
        }
    public:
        BST():root(nullptr){}
        ~BST(){
            this->destroy_BST(this->root);
            this->root = nullptr;
        }
        
        void add_node(int key){
            Node *node = new Node(key);
            //chek if tree es empty
            if(!root){
                std::cout << "Tree is empty. Adding root node..." << std::endl;
                this->root = node;
                return;
            }
            // using an aux node, traverse the tree, and get parent node
            Node *aux = this->root;
            while(aux != nullptr){
                if(node->get_key() <= aux->get_key()){
                    // go left
                    if(aux->get_left() != nullptr){
                        aux = aux->get_left();
                    }else if(!aux->get_left()){
                        aux->set_left(node);
                        node->set_parent(aux);
                        break;
                    }
                }else if(node->get_key() > aux->get_key()){
                    // go right
                    if(aux->get_right() != nullptr){
                        aux = aux->get_right();
                    }else if(!aux->get_right()){
                        aux->set_right(node);
                        node->set_parent(aux);
                        break;
                    }
                }
            }
        }
};





int main(){


    return 0;
}
