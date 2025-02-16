#include "TaskManager.h"
#include <iostream>

enum class MenuOption {
    ADD_TASK = 1,
    REMOVE_TASK,
    UPDATE_TASK,
    LIST_TASKS,
    SAVE_TASKS,
    LOAD_TASKS,
    EXIT
};

int main() {
   TaskManager manager;

   int choice;
   while(true) {
       std::cout << "1. Add task" << std::endl;
       std::cout << "2. Remove task" << std::endl;
       std::cout << "3. Update task" << std::endl;
       std::cout << "4. List tasks" << std::endl;
       std::cout << "5. Save tasks" << std::endl;
       std::cout << "6. Load tasks" << std::endl;
       std::cin >> choice;

       MenuOption option = static_cast<MenuOption>(choice);

       switch (option) {
           case MenuOption::ADD_TASK: {
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
           case MenuOption::REMOVE_TASK: {
                       int id;
                       std::cout << "Enter task ID to remove: ";
                       std::cin >> id;
                       manager.removeTask(id);
                       break;
                   }
           case MenuOption::UPDATE_TASK: {
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
           case MenuOption::LIST_TASKS:
                manager.listTasks();
                break;
           case MenuOption::SAVE_TASKS:
                manager.saveToFile("tasks.txt");
                break;
           case MenuOption::LOAD_TASKS:
                manager.loadFromFile("tasks.txt");
                break;
           case MenuOption::EXIT:
                return 0;
            default:
                std::cerr << "Invalid choice." << std::endl;
        }
    }
}
