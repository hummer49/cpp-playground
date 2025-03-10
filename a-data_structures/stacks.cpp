/*
Stack
Explanation:
    A stack is a linear data structure that follows the Last-In-First-Out (LIFO) principle. Think of a stack of plates.
Requisites:
    Operations: push (add an element), pop (remove the top element), peek (view the top element), isEmpty.
*/
#include<iostream>
#include<vector>


class Item{
    private:
        Item *next;
        int id;                         //placeholder for actual data
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

class Stack{
    private:
        Item *top;
    public:
        Stack():top(nullptr){};
        ~Stack(){
            //add destructor logic later
            Item *aux = this->top;
            while(aux != nullptr){
                Item *current = aux->get_next();
                delete aux;
                aux = current;
            }
            this->top = nullptr;
        }
        void push(Item *item){
            item->set_next(this->top);
            this->top = item;
        }
        void pop(){
            if(!this->top){
                std::cout << "Empty stack" << std::endl;
                return;
            }
            Item *aux = this->top;
            this->top = this->top->get_next();
            delete aux;
        }
        void peek(){
            if(!this->top){
                std::cout << "Empty stack" << std::endl;
                return;
            }
            std::cout << "TOP:\t";
            this->top->print_item();
            std::cout << std::endl;
        }
        bool isEmpty(){
            return this->top == nullptr;
        }
};




int main(){
    Stack stack;
    for(int i;i<10;i++){
        Item *item = new Item(i);
        stack.push(item);
        std::cout << "Iteration " << i+1 << std::endl;
        stack.peek();
        std::cout << "=========" << std::endl;
    }
    std::cout << "\n\n\n" << std::endl;
    for(int i;i<15;i++){
        std::cout << "Iteration " << i+1 << std::endl;
        stack.peek();
        stack.pop();
        std::cout << "=========" << std::endl;
    }
    return 0;
}