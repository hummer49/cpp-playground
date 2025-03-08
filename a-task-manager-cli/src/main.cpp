/*
author: hymmer49
main.cpp

*/
// ================================================================================
// Include
#include<iostream>
#include<string>
#include<limits>
#include<memory>
// ================================================================================
// declarations
int getYesNoInput(const std::string& prompt);
// ================================================================================
// Enum
enum Status{
    PENDING,
    COMPLETED
};
// ================================================================================
// Classes
class Task{
    private:
        int id;
        std::string name;
        std::string description;
        Status status;
        Task *prev;
        Task *next;
    public:
        Task(int id, Task *prev, Task *next) : 
        id(id),
        prev(prev),
        next(next)
        {}
        ~Task(){}

        Task *get_next(){
            return this->next;
        }
        void set_next(Task *next){
            this->next = next;
        }
        Task *get_prev(){
            return this->prev;
        }
        void set_prev(Task *prev){
            this->prev = prev;
        }
        
        int get_id(){
            return this->id;
        }

        void create_task(){
            std::cout << "New task" << std::endl;
            std::cout << "Enter task name:\t";
            std::getline(std::cin >> std::ws, this->name);
            std::cout << "\nEnter task description:\t";
            std::getline(std::cin >> std::ws, this->description);
            std::cout << std::endl;
            this->status = Status::PENDING;


        }
        void read_task(){
            std::cout << "Name: " << this->name << std::endl;
            std::cout << "Description: " << this->description << std::endl;
        }
        void update_task(){
            if (getYesNoInput("Change name? 1 yes - 0 no") == 1) {
                std::cout << "Enter new name: ";
                std::getline(std::cin >> std::ws, this->name);
            }
        
            if (getYesNoInput("Change description? 1 yes - 0 no") == 1) {
                std::cout << "Enter new description: ";
                std::getline(std::cin >> std::ws, this->description);
            }
        }

        void delete_task(){
            std::cout << "This is not right" << std::endl;
        }
};
class TaskManager{
    private:
        Task *head;
        Task *tail;
        int last_id;

    public:
        TaskManager():
            head(nullptr),
            tail(nullptr),
            last_id(0)
        {}
        
        void initialize(){
            Task *head = new Task(last_id, nullptr, nullptr);
            head->create_task();
            this->tail = head;
            this->last_id++;
        }
        void add_task(){
            Task *new_task = new Task(last_id, this->tail->get_prev(), nullptr);
            new_task->create_task();
            if(this->tail){
                this->tail->set_next(new_task);
            }
            this->last_id++;
        }

        void remove_task(int id){
            //check if list is empty
            if(!this->head){
                std::cout << "List is empty" << std::endl;
                return;
            }
            Task *aux = this->head;
            Task *prev = nullptr;

            while(aux != nullptr && aux->get_id()!=id){
                prev = aux;
                aux = aux->get_next();
            }

            if (aux->get_prev() == nullptr) {
                // remove head
                this->head = aux->get_next();
                if (this->head) {
                    this->head->set_prev(nullptr);
                } else {
                    this->tail = nullptr; // List is now empty
                }
            } else if (aux->get_next() == nullptr) {
                //remove tail
                this->tail = prev;
                this->tail->set_next(nullptr);
            } else {
                //remove from middle
                prev->set_next(aux->get_next());
                aux->get_next()->set_prev(prev);
            }
            delete aux; // Deallocate memory

        }

        void update_task(int id){
            //check if list is empty
            if(!this->head){
                std::cout << "List is empty" << std::endl;
                return;
            }
            Task *aux = this->head;

            while(aux != nullptr && aux->get_id()!=id){
                aux = aux->get_next();
            }
            aux->update_task();
        }

        void print_list(){
             //check if list is empty
             if(!this->head){
                std::cout << "List is empty" << std::endl;
                return;
            }
            Task *aux = this->head;
            while(aux != nullptr){
                aux->read_task();
                aux = aux->get_next();
            }
        }
        }

};

// ================================================================================
// Functions

int getYesNoInput(const std::string& prompt) {
    short int aux = 2;
    do {
        std::cout << prompt << std::endl;
        std::cin >> aux;
        if (std::cin.fail() || aux < 0 || aux > 1) {
            std::cout << "Invalid input. Please enter 1 for yes or 0 for no." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            return aux;
        }
    } while (true);
}
// ================================================================================
// main
int main(){
    return 0;
}
// ================================================================================