/*
Queue
Explanation:

    A queue is a linear data structure that follows the First-In-First-Out (FIFO) principle. Think of a line at a store.
Requisites:
    Operations: enqueue (add an element), dequeue (remove the front element), front (view the front element), isEmpty.

*/
#include<iostream>

class Item{
    private:
        Item *next;
        int id;
    public:
        Item(int id):id(id),next(nullptr){}
        void set_next(Item *next){
            this->next = next;
        }
        Item *get_next(){
            return this->next;
        }
        void print_item(){
            std::cout << "ID: " << this->id << std::endl;
        }
};

class Queue{
    private:
        Item *front;
        Item *rear;
    public:
        Queue():front(nullptr),rear(nullptr){}
        ~Queue(){
            //add destructor logic later
            Item *aux = this->front;
            while(aux != nullptr){
                Item *current = aux->get_next();
                delete aux;
                aux = current;
            }
            this->front = nullptr;
            this->rear = nullptr;
        }
        void enqueue(Item *new_item){
            if(this->isEmpty()){
                // if queue is empty
                this->front = new_item;
                new_item->set_next(nullptr);
                this->rear = this->front;
            }else{
                Item *aux = this->rear;
                aux->set_next(new_item);
                this->rear = new_item;
                this->rear->set_next(nullptr);
            }
        }
        void dequeue(){
            //remove front
            if(this->isEmpty()){
                std::cout << "Queue is empty" << std::endl;
                return;
            }
            Item *aux = this->front;
            this->front = this->front->get_next();
            delete aux;
            if(this->front == nullptr){
                this->rear = nullptr;
            }
        }
        void print_front(){
            if(this->isEmpty()){
                std::cout << "Queue is empty" << std::endl;
                return;
            }
            //print front
            std::cout << "FRONT: ";
            this->front->print_item();
            std::cout << std::endl;
        }
        bool isEmpty(){
            return this->front == nullptr;
        }

};



int main(){
    Queue q_0;
    for(int i = 0; i<10; i++){
        Item *item = new Item(i);
        q_0.enqueue(item);
        q_0.print_front();
        if(1){
            q_0.dequeue();
        }
    }

    return 0;
}