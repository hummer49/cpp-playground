/*
Linked List
Explanation:
    A linked list is a linear data structure where elements are not stored in contiguous memory locations. 
    Instead, each element (node) contains a data value and a pointer (or link) to the next node in the sequence.
    - Singly Linked List: Each node points to the next node.
    - Doubly Linked List: Each node points to both the next and previous nodes.   
    - Circular Linked List: The last node points back to the first node.

Requisites:
    - Nodes with data and pointer(s).
    - Operations: Insertion, deletion, traversal, searching.
*/
#include<iostream>

struct Data{
    int id;
    void print_data(){
        std::cout << "ID:\t" << id << std::endl;
    }
};

class Node{
    private:
        Data data;
        Node *next;
    public:
        Node(Data data):data(data),next(nullptr){}
        void set_data(Data data){
            this->data = data;
        }
        Data get_data(){
            return this->data;
        }
        void set_next(Node *next){
            this->next = next;
        }
        Node *get_next(){
            return this->next;
        }
};

class LinkedList{
    private:
        Node *head;
        unsigned int size;
    public:
        LinkedList():head(nullptr),size(0){}
        ~LinkedList(){
            Node *current = this->head;
            while(current != nullptr){
                Node *next = current->get_next();
                delete current;
                current = next;
            }
            this->head = nullptr;
        }
        
        void push_front(Node *node){
            // add node to front
            if(!head){
                node->set_next(nullptr);
            }else{
                node->set_next(this->head);
            }
            this->head = node;
            this->size++;
        }
        void push_back(Node *node){
            // add node to tail
            if(!head){
                this->push_front(node);
                return;
            }
            Node *aux = this->head;
            while(aux != nullptr){
                aux = aux->get_next();
            }
            aux->set_next(node);
            this->size++;
        }
        void insert_node(unsigned int pos, Node *node){
            // add node at position pos
            if(this->head == nullptr && pos > 0){
                std::cout << "Error. Empty list / Out of index" << std::endl;
                return;
            }
            if(pos == 0){
                this->push_front(node);
                return;
            }
            Node *prev = get_node(pos-1);
            if(prev !=nullptr){
                node->set_next(prev->get_next());
                prev->set_next(node);
            }
            this->size++;
        }

        void pop_front(){
            if(!this->head){
                std::cout << "Empty list" << std::endl;
                return;
            }
            if(this->head->get_next() == nullptr){
                this->head = nullptr;
                return;
            }
            this->head = this->head->get_next();
            this->size--;
        }
        void pop_back(){
            // remove last node
            if(!this->head){
                std::cout << "Empty list" << std::endl;
                return;
            }
            if(this->head->get_next() == nullptr){
                this->head = nullptr;
                return;
            }
            this->size--;
        }
        void remove_node(unsigned int pos){
            //remove node at position pos
            if(!this->head){
                std::cout << "Empty list" << std::endl;
                return;
            }
            if(pos > this->size - 1){
                std::cout << "Index out of range" << std::endl;
            }∆

            this->size--;
        }

        Node *get_head(){
            return this->head;
        }
        Node *get_tail(){
            // return last node

            return nullptr;
        }
        Node *get_node(unsigned int pos){
            // return node at position pos
            if(!this->head){
                std::cout << "Empty list" << std::endl;
                return nullptr;
            }
            unsigned int i;
            Node *aux = this->head;
            while(aux != nullptr && i < pos){
                aux = aux->get_next();
                i++;
            }
            if(aux == nullptr && i < pos){
                std::cout << "Error. Index out of range" << std::endl;
                return nullptr;
            }
            return aux;
        }

        unsigned int get_size(){
            return this->size;
        }

};


int main(){
    LinkedList list_0();


    return 0;
}
