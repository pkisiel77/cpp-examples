#include <iostream>

constexpr int maxUsers = 100;

void printBuildLocation() {
    std::cout << "Source file: " << __FILE__ << '\n';
    std::cout << "Line: " << __LINE__ << '\n';
}

int main() {
    std::cout << "Preprocessor example\n";
    std::cout << "Max users: " << maxUsers << '\n';

    printBuildLocation();

#ifdef DEBUG_MODE
    std::cout << "Debug mode: enabled\n";
#else
    std::cout << "Debug mode: disabled\n";
#endif

    return 0;
}
