"Simple Task Manager"
Overview:
Create a command-line task manager in C++ that allows users to add, remove, 
and list tasks. The program should store tasks in memory using a linked list or vector.

Basic Guidelines:
Define a Task Class

Attributes: ID, Description, Status (e.g., Pending, Completed).
Constructor for initialization.
Create a TaskManager Class

Use a vector<Task> or a linked list to store tasks.
Implement methods:
addTask(): Adds a new task.
removeTask(): Deletes a task by ID.
listTasks(): Displays all tasks.
markComplete(): Updates task status.
User Interface (CLI)

Display a menu with options (Add, Remove, List, Complete, Exit).
Use a loop to keep the program running until the user exits.
Handle invalid inputs gracefully.
Stretch Goals (Optional, if time allows)

Save tasks to a file and reload them on startup.
Implement a priority system (e.g., High, Medium, Low).
Allow searching for tasks by keywords.