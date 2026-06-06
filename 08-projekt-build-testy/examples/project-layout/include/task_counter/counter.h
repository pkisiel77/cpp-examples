#ifndef TASK_COUNTER_COUNTER_H
#define TASK_COUNTER_COUNTER_H

class Counter {
public:
    void addTask();
    void completeTask();
    int getOpenTasks() const;
    int getCompletedTasks() const;

private:
    int openTasks = 0;
    int completedTasks = 0;
};

#endif
