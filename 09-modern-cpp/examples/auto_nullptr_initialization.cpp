#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int points;
};

const Student* findBestStudent(const std::vector<Student>& students) {
    const Student* bestStudent = nullptr;

    for (const auto& student : students) {
        if (bestStudent == nullptr || student.points > bestStudent->points) {
            bestStudent = &student;
        }
    }

    return bestStudent;
}

int main() {
    int passingPoints{50};
    std::vector<Student> students{
        {"Anna", 82},
        {"Jan", 47},
        {"Maria", 64},
    };

    std::cout << "Students:\n";
    for (const auto& student : students) {
        auto result = student.points >= passingPoints ? "passed" : "failed";
        std::cout << "  " << student.name << ": "
                  << student.points << " - " << result << '\n';
    }

    const Student* bestStudent = findBestStudent(students);
    if (bestStudent != nullptr) {
        std::cout << "Best student: " << bestStudent->name << '\n';
    }

    return 0;
}
