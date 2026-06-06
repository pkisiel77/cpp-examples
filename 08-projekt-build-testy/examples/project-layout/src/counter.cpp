#include "task_counter/counter.h"

void Counter::addTask() {
    ++openTasks;
}

void Counter::completeTask() {
    if (openTasks > 0) {
        --openTasks;
        ++completedTasks;
    }
}

int Counter::getOpenTasks() const {
    return openTasks;
}

int Counter::getCompletedTasks() const {
    return completedTasks;
}
