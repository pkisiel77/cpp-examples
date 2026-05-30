#include <cmath>
#include <iostream>

int main()
{
    double liczba;

    std::cout << "Podaj liczbe: ";
    std::cin >> liczba;

    std::cout << "Pierwiastek: " << std::sqrt(liczba) << std::endl;
    std::cout << "Kwadrat: " << std::pow(liczba, 2.0) << std::endl;

    return 0;
}
