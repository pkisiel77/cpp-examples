#include <iostream>

int main()
{
    int liczba;

    std::cout << "Podaj liczbe: ";
    std::cin >> liczba;

    if ((liczba >= -10 && liczba <= 13) || (liczba >= 25 && liczba <= 35))
    {
        std::cout << "Liczba nalezy do jednego z podanych przedzialow" << std::endl;
    }
    else
    {
        std::cout << "Liczba nie nalezy do podanych przedzialow" << std::endl;
    }

    return 0;
}
