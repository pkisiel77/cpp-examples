#include <iostream>

#include "task_counter/counter.h"

int main() {
    Counter counter;

    counter.addTask();
    counter.addTask();
    counter.completeTask();

    std::cout << "Open tasks: " << counter.getOpenTasks() << '\n';
    std::cout << "Completed tasks: " << counter.getCompletedTasks() << '\n';

    return 0;
}
