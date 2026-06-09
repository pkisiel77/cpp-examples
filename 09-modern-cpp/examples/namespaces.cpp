#include <iostream>
#include <string>
#include <vector>

namespace app::math {
    int add(int left, int right) {
        return left + right;
    }
}

namespace app::reports {
    struct Report {
        std::string title;
        std::vector<int> values;
    };

    int sum(const Report& report) {
        int result{0};

        for (const auto value : report.values) {
            result += value;
        }

        return result;
    }

    void printSummary(const Report& report) {
        std::cout << report.title << ": "
                  << report.values.size() << " values, sum "
                  << sum(report) << '\n';
    }
}

namespace app::logs {
    void printSummary(const std::string& message) {
        std::cout << "Log: " << message << '\n';
    }
}

int main() {
    app::reports::Report report{"Sales", {10, 20, 30}};

    app::reports::printSummary(report);
    app::logs::printSummary("Report printed");

    using app::math::add;
    std::cout << "2 + 3 = " << add(2, 3) << '\n';

    return 0;
}
