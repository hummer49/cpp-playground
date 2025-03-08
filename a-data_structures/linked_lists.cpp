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
            
        }
        void remove_node(unsigned int pos){
            //remove node at position pos
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

    return 0;
}





/*
#include<iostream>

class Node{
    private:
        Node *next;
        int id;
        int data;                   // placeholder for actual data
    public:
        Node(Node* next,int id,int data):
            next(next),
            id(id),
            data(data)
        {} // default constructor
        ~Node(){}
        void print_data(){
            std::cout << "ID:\t" << this->id << std::endl;
            std::cout << "DATA:\t" << this->data << std::endl;
        }
        void update_date(int new_data){
            this->data = new_data;
        }
        void set_next(Node *next){
            this->next = next;
        }
        Node *get_next(){
            return this->next;
        }
};

class D_Node : public Node{
    private:
        D_Node *prev;
    public:
        D_Node(D_Node *prev, Node* next, int id, int data):
            prev(prev),
            Node(next, id,data)
        {}
        void set_prev(D_Node *prev){
            this->prev = prev;
        }
        D_Node *get_prev(){
            return this->prev;
        }
};

class linked_list{
    private:
        Node *head;
        Node *tail;
    public:
        linked_list(): head(nullptr){}
        void initialize(int id, int data){
            Node *head = new Node(nullptr, id, data);
            this->head = head;
            this->tail = head;
        }
        // - Operations: Insertion, deletion, traversal, searching.
        void insert_at(unsigned int pos, int id, int data){
            if(!this->head){
                //empty list
                initialize(id, data);
            }

        }
        Node *search_by_position(unsigned int pos){
            Node *aux_0 = this->head;
            Node *aux_1;
            
        }

};


int main(){

    return 0;
}

*/