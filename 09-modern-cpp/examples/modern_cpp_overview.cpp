#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

enum class Status {
    Active,
    Inactive
};

struct Person {
    std::string name;
    int score;
    Status status;
};

std::string statusToText(Status status) {
    if (status == Status::Active) {
        return "active";
    }

    return "inactive";
}

int main() {
    std::vector<Person> people{
        {"Anna", 82, Status::Active},
        {"Jan", 47, Status::Inactive},
        {"Maria", 64, Status::Active},
        {"Piotr", 91, Status::Active},
    };

    std::sort(people.begin(), people.end(), [](const Person& left, const Person& right) {
        return left.score > right.score;
    });

    auto isActive = [](const Person& person) {
        return person.status == Status::Active;
    };

    std::cout << "Active people sorted by score:\n";
    for (const auto& person : people) {
        if (isActive(person)) {
            std::pair<std::string, int> result{person.name, person.score};
            auto [name, score] = result;

            std::cout << "  " << name << ": " << score
                      << " (" << statusToText(person.status) << ")\n";
        }
    }

    const Person* selectedPerson = nullptr;
    if (!people.empty()) {
        selectedPerson = &people.front();
    }

    if (selectedPerson != nullptr) {
        std::cout << "Best result: " << selectedPerson->name << '\n';
    }

    return 0;
}
