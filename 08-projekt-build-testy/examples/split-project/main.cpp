#include <iostream>

#include "calculator.h"

int main() {
    const int left = 12;
    const int right = 4;

    std::cout << left << " + " << right << " = " << add(left, right) << '\n';
    std::cout << left << " - " << right << " = " << subtract(left, right) << '\n';
    std::cout << left << " * " << right << " = " << multiply(left, right) << '\n';

    return 0;
}
