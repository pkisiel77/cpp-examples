#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int points;
};

std::string resultForPoints(int points) {
    if (points >= 50) {
        return "passed";
    }

    return "failed";
}

void printReport(const std::vector<Student>& students) {
    for (const Student& student : students) {
        std::cout << student.name << ": "
                  << student.points << " points, "
                  << resultForPoints(student.points) << '\n';
    }
}

int main() {
    const std::vector<Student> students = {
        {"Anna", 82},
        {"Jan", 47},
        {"Maria", 64},
    };

    printReport(students);
    return 0;
}
