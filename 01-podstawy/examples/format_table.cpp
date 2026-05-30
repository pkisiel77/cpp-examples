#include <iomanip>
#include <iostream>
#include <string>

int main()
{
    std::cout << std::left << std::setw(12) << "Produkt"
              << std::right << std::setw(8) << "Sztuk"
              << std::setw(10) << "Cena" << std::endl;

    std::cout << std::setfill('-') << std::setw(30) << "" << std::setfill(' ') << std::endl;

    std::cout << std::left << std::setw(12) << "Zeszyt"
              << std::right << std::setw(8) << 3
              << std::setw(10) << std::fixed << std::setprecision(2) << 4.50 << std::endl;

    std::cout << std::left << std::setw(12) << "Dlugoopis"
              << std::right << std::setw(8) << 1
              << std::setw(10) << std::fixed << std::setprecision(2) << 6.99 << std::endl;

    return 0;
}
