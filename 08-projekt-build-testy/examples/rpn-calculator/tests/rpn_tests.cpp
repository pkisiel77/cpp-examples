#include "rpn/calculator.h"

#include <cmath>
#include <iostream>
#include <string>

namespace {

bool expectNear(const std::string& expression, double expected) {
    const rpn::CalculationResult result = rpn::calculate(expression);
    if (!result.ok) {
        std::cerr << "Expected success for: " << expression << ", got: " << result.error << '\n';
        return false;
    }

    if (std::fabs(result.value - expected) > 0.0001) {
        std::cerr << "Expected " << expected << " for: " << expression << ", got: " << result.value << '\n';
        return false;
    }

    return true;
}

bool expectError(const std::string& expression) {
    const rpn::CalculationResult result = rpn::calculate(expression);
    if (result.ok) {
        std::cerr << "Expected error for: " << expression << ", got: " << result.value << '\n';
        return false;
    }

    return true;
}

}  // namespace

int main() {
    bool ok = true;

    ok = expectNear("2 + 2 * 2", 6.0) && ok;
    ok = expectNear("(2 + 2) * 2", 8.0) && ok;
    ok = expectNear("10 / 2 + 3", 8.0) && ok;
    ok = expectNear("-5 + 2", -3.0) && ok;
    ok = expectNear("2 * -3", -6.0) && ok;
    ok = expectNear("2 - -3", 5.0) && ok;
    ok = expectNear("(-2 + 5) * 3", 9.0) && ok;
    ok = expectError("10 / 0") && ok;
    ok = expectError("(2 + 3") && ok;
    ok = expectError("2 + * 3") && ok;
    ok = expectError("") && ok;
    ok = expectError("2 +") && ok;
    ok = expectError("2 & 3") && ok;

    if (!ok) {
        return 1;
    }

    std::cout << "Wszystkie testy kalkulatora RPN przeszly\n";
    return 0;
}
