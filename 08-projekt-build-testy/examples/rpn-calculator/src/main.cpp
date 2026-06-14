#include "rpn/calculator.h"

#include <iostream>
#include <string>

int main() {
    std::cout << "Podaj wyrazenie: ";

    std::string expression;
    std::getline(std::cin, expression);

    const rpn::CalculationResult result = rpn::calculate(expression);
    if (!result.ok) {
        std::cout << "Blad: " << result.error << '\n';
        return 1;
    }

    std::cout << "Wynik: " << result.value << '\n';
    return 0;
}
