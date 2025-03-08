/*
author: hummer49
main.cpp
*/
#include<iostream>
#include<string>

// ===================================================================
// Functions

// ===================================================================
// Auxiliar data structures
enum Status{
    AVAILABLE = 0,
    OUT_OF_STOCK = 1, 
};
// ===================================================================
// Classes
class Product{
    private:
        unsigned int id;            // i'll rather use a string, but this will do it
        std::string name;
        unsigned int price;         // negative value for a price makes nos sense
        unsigned int quantity;      // similar case
    public:
        Product(unsigned int id, std::string name):
            id(id),
            name(name)
        {};

        void print_information(){
            std::cout <<"ID: " << this->id << std::endl;
            std::cout <<"NAME: " << this->name << std::endl;
            std::cout <<"PRICE: " << this->price << std::endl;
            std::cout <<"QUANTITY: " << this->quantity << std::endl;

        }
        void update_name(std::string new_name){
            this->name  = new_name;
        }
        void update_price(unsigned int new_price ){
            this->price = new_price;
        }
        void update_quantity(unsigned int new_quantity){
            this->quantity = new_quantity;
        }
};

class Inventory{
    private:
        std::string name;
        Product *head;
        Product *tail;
        unsigned int counter;           // to keep track of inventory size
    public:
        Inventory(std::string name):
            name(name),
            head(nullptr),
            tail(nullptr),
            counter(0)
        {
            std::cout << "New inventory created\t" << this-> name << std::endl;
        };

        void initialize_inventory(){
            Product *first = new Product(0,"Product_0");
            this->head = first;
            this->tail = first;
        } 


};

// ===================================================================
// Main Block
int main(){
    return 0;
}