#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

enum class TaskPriority {
    Low,
    Normal,
    High,
    Critical
};

enum class TaskStatus {
    New,
    InProgress,
    Done,
    Cancelled
};

struct Task {
    std::string id;
    std::string name;
    TaskPriority priority;
    TaskStatus status;
    std::string startTime;
    std::string functionName;
};

int priorityRank(TaskPriority priority) {
    switch (priority) {
        case TaskPriority::Low:
            return 1;
        case TaskPriority::Normal:
            return 2;
        case TaskPriority::High:
            return 3;
        case TaskPriority::Critical:
            return 4;
    }

    return 0;
}

std::string statusName(TaskStatus status) {
    switch (status) {
        case TaskStatus::New:
            return "New";
        case TaskStatus::InProgress:
            return "InProgress";
        case TaskStatus::Done:
            return "Done";
        case TaskStatus::Cancelled:
            return "Cancelled";
    }

    return "Unknown";
}

class TaskManager {
public:
    bool add(Task task) {
        if (find(task.id) != nullptr) {
            return false;
        }

        tasks_.push_back(std::move(task));
        return true;
    }

    bool changeStatus(const std::string& id, TaskStatus status) {
        Task* task = find(id);
        if (task == nullptr) {
            return false;
        }

        task->status = status;
        return true;
    }

    std::vector<Task> filterByStatus(TaskStatus status) const {
        std::vector<Task> result;
        for (const Task& task : tasks_) {
            if (task.status == status) {
                result.push_back(task);
            }
        }
        return result;
    }

    std::vector<Task> sortedByPriority() const {
        std::vector<Task> result = tasks_;
        std::sort(result.begin(), result.end(), [](const Task& left, const Task& right) {
            return priorityRank(left.priority) > priorityRank(right.priority);
        });
        return result;
    }

private:
    Task* find(const std::string& id) {
        auto it = std::find_if(tasks_.begin(), tasks_.end(), [&id](const Task& task) {
            return task.id == id;
        });
        return it == tasks_.end() ? nullptr : &(*it);
    }

    const Task* find(const std::string& id) const {
        auto it = std::find_if(tasks_.begin(), tasks_.end(), [&id](const Task& task) {
            return task.id == id;
        });
        return it == tasks_.end() ? nullptr : &(*it);
    }

    std::vector<Task> tasks_;
};

void printTasks(const std::vector<Task>& tasks) {
    for (const Task& task : tasks) {
        std::cout << task.id << " | " << task.name << " | " << statusName(task.status) << '\n';
    }
}

int main() {
    TaskManager manager;

    manager.add(Task{"T-1", "backup", TaskPriority::High, TaskStatus::New, "08:00", "backup_data"});
    manager.add(Task{"T-2", "raport", TaskPriority::Normal, TaskStatus::New, "09:30", "generate_report"});
    manager.add(Task{"T-3", "alarm", TaskPriority::Critical, TaskStatus::InProgress, "10:00", "send_alert"});

    if (!manager.add(Task{"T-1", "duplikat", TaskPriority::Low, TaskStatus::New, "11:00", "noop"})) {
        std::cout << "Odrzucono duplikat ID\n";
    }

    manager.changeStatus("T-2", TaskStatus::Done);

    std::cout << "Zadania posortowane po priorytecie:\n";
    printTasks(manager.sortedByPriority());

    std::cout << "\nZadania zakonczone:\n";
    printTasks(manager.filterByStatus(TaskStatus::Done));
}
