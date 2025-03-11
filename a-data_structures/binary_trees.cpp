/*

Binary Tree (Binary Search Tree)
Explanation:
    A binary tree is a hierarchical data structure where each node has at most two children (left and right).
    Binary Search Tree (BST): 
        A binary tree where the left subtree of a node contains only nodes with keys less than the node's key, 
        and the right subtree contains only nodes with keys greater than the node's key.   
Requisites:
    Nodes with data and pointers to left and right children.
    Operations: Insertion, deletion, searching, traversal (inorder, preorder, postorder).

*/
/*
Binary Search Tree (BST)


*/

#include<iostream>

int get_max(int a, int b){
    if(a>=b){
        return a;
    }else{
        return b;
    }
}

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
        int height;
        void destroy_BST(Node *node){
            if(node!=nullptr){
                destroy_BST(node->get_left());
                destroy_BST(node->get_right());
                delete node;
            }
        }
        int find_height(Node *root) {
  
            if (!root) {
                return -1;
            }
        
            int leftHeight = find_height(root->get_left());
            int rightHeight = find_height(root->get_right());
        
            return get_max(leftHeight, rightHeight) + 1;
        }
    public:
        BST():root(nullptr),height(-1){}
        ~BST(){
            this->destroy_BST(this->root);
            this->root = nullptr;
        }

        int get_height() const{
            return this->height;
        }
        
        void add_node(int key){
            Node *node = new Node(key);
            //chek if tree es empty
            if(!root){
                // std::cout << "Tree is empty. Adding root node..." << std::endl;
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
            this->height = this->find_height(this->root);
        }

        void search(int key){
            // check if empty
            if(!this->root){
                std::cout << "Tree is empty" << std::endl;
                return;
            }
            Node *aux = this->root;
            while(aux != nullptr){
                if(aux->get_key() == key){
                    std::cout << "Key was found" << std::endl;              // give more information, even 
                    return;
                }
                if(aux->get_key() < key){
                    // go right
                    aux = aux->get_right();
                }else if (aux->get_key() > key){
                    //go left
                    aux =aux->get_left();
                }
            }
            if(aux == nullptr){
                std::cout << "Key was not found" << std::endl;
                return;
            }

            std::cout << "IDK" << std::endl;
        }

        void print_tree(Node* node) const {
            if (node != nullptr) {
                print_tree(node->get_left());
                std::cout << node->get_key() << " ";
                print_tree(node->get_right());
            }
        }

        
        
        void print_tree() const {
            print_tree(root);
            std::cout << std::endl;
        }
};





int main(){
    BST *bst = new BST;

    bst->add_node(13);
    bst->add_node(12);
    bst->add_node(0);
    bst->add_node(22);
    bst->add_node(-1);
    std::cout << "HEIGHT:\t" <<bst->get_height() << std::endl;
    // bst->print_tree();


    return 0;
}
