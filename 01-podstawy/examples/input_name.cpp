#include <iostream>
#include <string>

int main()
{
    std::string imie;

    std::cout << "Podaj imie: ";
    std::cin >> imie;

    std::cout << "Czesc, " << imie << "!" << std::endl;
    return 0;
}
