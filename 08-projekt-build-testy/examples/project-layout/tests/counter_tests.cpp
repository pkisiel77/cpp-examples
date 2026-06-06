#include <iostream>

#include "task_counter/counter.h"

bool testCompletingTask() {
    Counter counter;

    counter.addTask();
    counter.addTask();
    counter.completeTask();

    return counter.getOpenTasks() == 1 && counter.getCompletedTasks() == 1;
}

bool testCompletingWithoutOpenTasks() {
    Counter counter;

    counter.completeTask();

    return counter.getOpenTasks() == 0 && counter.getCompletedTasks() == 0;
}

int main() {
    if (!testCompletingTask()) {
        std::cout << "testCompletingTask failed\n";
        return 1;
    }

    if (!testCompletingWithoutOpenTasks()) {
        std::cout << "testCompletingWithoutOpenTasks failed\n";
        return 1;
    }

    std::cout << "All tests passed\n";
    return 0;
}
