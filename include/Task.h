#ifndef TASK_H
#define TASK_H

enum class Priority {LOW, MEDIUM, HIGH};

struct Task {
    int id;
    std::string title;
    std::string description;
    bool is_completed;
    Priority priority;

    static bool comparePriority(const Task& a, const Task& b) {
        return a.priority < b.priority;
    }
};

#endif
