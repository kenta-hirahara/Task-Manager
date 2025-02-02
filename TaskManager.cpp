/*
 source file
   - includes header file, in this case TaskManager.h
   - contains e.g. definitions of member functions
 */

#include "TaskManager.h"
#include <iostream>
#include <fstream>
#include <algorithm>

/*
TaskManager::TaskManager() -> constructor
: nextId(1) -> initialization list of constructor. in this case, nextID is set to 1.
{} -> the content of constructor. In this case nothing.
 */
TaskManager::TaskManager() : nextId{1} {}

void TaskManager::addTask(const std::string& title, const std::string& description)
{
    tasks.push_back(std::make_unique<Task>(Task{nextId++, title, description, false}));
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
            << "\nCompleted: " << (task -> is_completed ? "Yes" : "No") << "\n\n";
        
    }
    
}
