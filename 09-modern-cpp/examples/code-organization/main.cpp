#include <iostream>
#include <vector>

#include "message.h"

int main() {
    const std::vector<app::messages::Message> messages{
        {"Anna", "Build finished"},
        {"Jan", "Tests passed"},
        {"Maria", "Release ready"},
    };

    for (const auto& message : messages) {
        std::cout << app::messages::formatMessage(message) << '\n';
    }

    return 0;
}
