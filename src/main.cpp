#include "TaskManager.h"
#include "Task.h"
#include <iostream>

int main() {
   TaskManager manager;

   int choice;
   while(true) {
       std::cout << "1. Add task" << std::endl;
       std::cout << "2. Remove task" << std::endl;
       std::cout << "3. Update task" << std::endl;
       std::cout << "4. List task" << std::endl;
       std::cout << "5. Sort task by priority" << std::endl;
       std::cin >> choice;

       switch (choice) {
           case 1: {
                       std::string title, description, priority;
                       std::cout << "Enter title: ";
                       std::cin.ignore();
                       std::getline(std::cin, title);
                       std::cout << "Enter description: ";
                       std::getline(std::cin, description);
                       std::cout << "Enter priority: ";
                       std::getline(std::cin, priority);
                       manager.addTask(title, description, std::stoi(priority));
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
                int id;
                std::string title, description;
                bool is_completed;
                std::cout << "Enter task ID to update: ";
                std::cin >> id;
                std::cin.ignore();
                std::cout << "Enter new title: ";
                std::getline(std::cin, title);
                std::cout << "Enter new description: ";
                std::getline(std::cin, description);
                std::cout << "Is completed? (1 for yes, 0 for no): ";
                std::cin >> is_completed;
                manager.updateTask(id, title, description, is_completed);
                break;
            }
            case 4:
                manager.listTasks();
                break;
            case 5:
                manager.saveToFile("tasks.txt");
                break;
            case 6:
                manager.loadFromFile("tasks.txt");
                break;
            case 0:
                return 0;
            default:
                std::cerr << "Invalid choice.\n";
        }
    }
}
