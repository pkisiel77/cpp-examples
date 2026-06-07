#include <iostream>
#include <string>

#include "task_counter/counter.h"

bool expectEqual(const std::string& name, int actual, int expected) {
    if (actual != expected) {
        std::cout << name << " failed: expected "
                  << expected << ", got " << actual << '\n';
        return false;
    }

    return true;
}

bool testInitialState() {
    Counter counter;

    return expectEqual("initial open tasks", counter.getOpenTasks(), 0)
           && expectEqual("initial completed tasks", counter.getCompletedTasks(), 0);
}

bool testCompletingTask() {
    Counter counter;

    counter.addTask();
    counter.addTask();
    counter.completeTask();

    return expectEqual("open tasks after complete", counter.getOpenTasks(), 1)
           && expectEqual("completed tasks after complete", counter.getCompletedTasks(), 1);
}

bool testCompletingWithoutOpenTasks() {
    Counter counter;

    counter.completeTask();

    return expectEqual("open tasks after empty complete", counter.getOpenTasks(), 0)
           && expectEqual("completed tasks after empty complete", counter.getCompletedTasks(), 0);
}

int main() {
    if (!testInitialState()) {
        return 1;
    }

    if (!testCompletingTask()) {
        return 1;
    }

    if (!testCompletingWithoutOpenTasks()) {
        return 1;
    }

    std::cout << "All tests passed\n";
    return 0;
}
