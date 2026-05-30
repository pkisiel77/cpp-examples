#include <iostream>

int main()
{
    int liczba;
    int suma = 0;

    std::cout << "Podaj liczbe, 0 konczy program: ";
    std::cin >> liczba;

    while (liczba != 0)
    {
        suma += liczba;

        std::cout << "Podaj liczbe, 0 konczy program: ";
        std::cin >> liczba;
    }

    std::cout << "Suma: " << suma << std::endl;
    return 0;
}
