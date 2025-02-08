/*
 *  This header file declares the interface of the TaskManager class.
 *  Other files (main.cpp and TaskManager.cpp) include this file to access the class definition.
 *  acts as a contract for how TaskManager class behaves.
 */

#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <string>
#include <vector>
#include <memory>
#include "Task.h"

class TaskManager
{
public:
    TaskManager();
    void addTask(const std::string& title, const std::string& description, int priority);
    void removeTask(int id);
    void updateTask(int id, const std::string& title, const std::string& description, bool is_completed);
    void listTasks() const; //const indicates that listTasks() is a "const member function".
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

private:
    std::vector<std::unique_ptr<Task>> tasks;
    int nextId;
    };

#endif
