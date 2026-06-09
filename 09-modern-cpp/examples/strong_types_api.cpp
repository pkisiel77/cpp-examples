#include <iostream>
#include <string>
#include <vector>

using UserId = std::string;
using MessageText = std::string;

enum class Priority {
    Low,
    Normal,
    High
};

struct Message {
    UserId userId;
    MessageText text;
    Priority priority{Priority::Normal};
};

std::string priorityToText(Priority priority) {
    switch (priority) {
        case Priority::Low:
            return "low";
        case Priority::Normal:
            return "normal";
        case Priority::High:
            return "high";
    }

    return "unknown";
}

class Notifier {
public:
    Notifier() = default;
    Notifier(const Notifier&) = delete;
    Notifier& operator=(const Notifier&) = delete;
    virtual ~Notifier() = default;

    virtual void send(const Message& message) const = 0;
};

class ConsoleNotifier : public Notifier {
public:
    void send(const Message& message) const override {
        std::cout << "[" << priorityToText(message.priority) << "] "
                  << "user=" << message.userId
                  << ", text=" << message.text << '\n';
    }
};

int main() {
    const std::vector<Message> messages{
        {"u001", "Welcome", Priority::Normal},
        {"u002", "Password changed", Priority::High},
        {"u003", "Newsletter", Priority::Low},
    };

    ConsoleNotifier notifier;
    for (const auto& message : messages) {
        notifier.send(message);
    }

    return 0;
}
