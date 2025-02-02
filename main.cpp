#include "TaskManager.h"
#include <iostream>

int main() {
   TaskManager manager;

   int choice;
   while(true) {
       std::cout << "1. Add task" << std::endl;
       std::cout << "2. Remove task" << std::endl;
       std::cout << "3. List task" << std::endl;
       std::cin >> choice;

       switch (choice) {
           case 1: {
                       std::string title, description;
                       std::cout << "Enter title: ";
                       std::cin.ignore();
                       std::getline(std::cin, title);
                       std::cout << "Enter description: ";
                       std::getline(std::cin, description);
                       manager.addTask(title, description);
                       break;
                   }
           case 2: {
                       int id;
                       std::cout << "Enter task ID to remove: ";
                       std::cin >> id;
                       manager.removeTask(id);
                       break;
                   }
           case 3: {
                       manager.listTasks();
                       break;
                   }
        }
    }
}
