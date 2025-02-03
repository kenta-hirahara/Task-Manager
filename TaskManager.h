#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <string>
#include <vector>
#include <memory>

struct Task {
    int id;
    std::string title;
    std::string description;
    bool is_completed;
};

class TaskManager
{
public:
    TaskManager();
    void addTask(const std::string& title, const std::string& description);
    void removeTask(int id);
    void updateTask(int id, const std::string& title, const std::string& description, bool is_completed);
    void listTasks() const; //const indicates that listTasks() is a "const member function".
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

private:
    std::vector<std::unique_ptr<Task>> tasks;
    int nextId;
    };
\
#endif
