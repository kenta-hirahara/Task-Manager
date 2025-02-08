/*
 source file
   - includes header file, in this case TaskManager.h
   - contains e.g. definitions of member functions
 */

#include "TaskManager.h"
#include "Task.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "magic_enum.hpp"

/*
TaskManager::TaskManager() -> constructor
: nextId(1) -> initialization list of constructor. in this case, nextID is set to 1.
{} -> the content of constructor. In this case nothing.
 */
TaskManager::TaskManager() : nextId{1} {}

void TaskManager::addTask(const std::string& title, const std::string& description, const int priority_int)
{
    tasks.push_back(std::make_unique<Task>(Task{nextId++, title, description, false, static_cast<Priority>(priority_int)}));
    std::cout << "Task added successfully." << std::endl;
}

void TaskManager::removeTask(int id)
{
    auto it = std::remove_if(tasks.begin(), tasks.end(), 
            [id](const std::unique_ptr<Task>& task){return task->id == id;});
    if (it != tasks.end()){
        tasks.erase(it, tasks.end());
        std::cout << "Task removed successfully" << std::endl;
    } else {
        std::cerr << "Task not found" << std::endl;
    }
}

void TaskManager::updateTask(int id, const std::string& title, const std::string& description, bool is_completed) {
    for (const auto& task : tasks) {
        if (task->id == id) {
            task->title = title;
            task->description = description;
            task->is_completed = is_completed;
            std::cout << "Task updated successfully.\n";
            return;
        }
    }
    std::cerr << "Task not found.\n";
}

void TaskManager::listTasks() const
{
    if (tasks.empty()) {
        std::cout << "No tasks" << std::endl;
        return;
    }
    for (const auto& task : tasks) {
        std::cout << std::endl;
        std::cout << "ID: " << task -> id << "\nTitle: " << task -> title
            << "\nDescription: " << task -> description
            << "\nCompleted: " << (task -> is_completed ? "Yes" : "No") 
            << "\nPriority: " << magic_enum::enum_name(task -> priority) << "\n\n";
    }
}

void TaskManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error upon saving to file" << std::endl;
        return;
    } 
    for (const auto& task: tasks) {
        file << task -> id << "|" << task -> title << "|" << task -> description  << "|" << task -> is_completed << std::endl;  
    }
    std::cout << "Saved to file." << std::endl;
}

void TaskManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error upon loading from file" << std::endl;
        return;
    } 
    tasks.clear();
    std::string line;
    while (std::getline(file, line)) {
        int id;
        std::string title, description;
        bool is_completed;
        std::istringstream iss(line);
        iss >> id >> std::ws;
        std::getline(iss, title, '|');
        std::getline(iss, description, '|');
        iss >> is_completed;
        tasks.push_back(std::make_unique<Task>(Task{id, title, description, is_completed}));
    }
    std::cout << "Tasks loaded from file.\n";
}
