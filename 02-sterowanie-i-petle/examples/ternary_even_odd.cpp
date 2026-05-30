#include <iostream>
#include <string>

int main()
{
    int liczba;

    std::cout << "Podaj liczbe: ";
    std::cin >> liczba;

    std::string wynik = (liczba % 2 == 0) ? "parzysta" : "nieparzysta";
    std::cout << "Liczba jest " << wynik << std::endl;

    return 0;
}
