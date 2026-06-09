#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Report {
public:
    Report(std::string title, std::vector<int> values)
        : title(std::move(title)), values(std::move(values)) {
        std::cout << "Construct report: " << this->title << '\n';
    }

    Report(const Report& other)
        : title(other.title), values(other.values) {
        std::cout << "Copy report: " << title << '\n';
    }

    Report(Report&& other) noexcept
        : title(std::move(other.title)), values(std::move(other.values)) {
        std::cout << "Move report: " << title << '\n';
    }

    Report& operator=(const Report& other) {
        if (this != &other) {
            title = other.title;
            values = other.values;
        }

        std::cout << "Copy assign report: " << title << '\n';
        return *this;
    }

    void printSummary() const {
        std::cout << title << " has " << values.size() << " values\n";
    }

private:
    std::string title;
    std::vector<int> values;
};

Report createReport() {
    return Report{"Monthly report", {10, 20, 30, 40}};
}

int main() {
    Report original{"Original report", {1, 2, 3}};
    Report copy = original;
    Report moved = std::move(original);
    Report generated = createReport();

    std::cout << "\nSummaries:\n";
    copy.printSummary();
    moved.printSummary();
    generated.printSummary();

    return 0;
}
