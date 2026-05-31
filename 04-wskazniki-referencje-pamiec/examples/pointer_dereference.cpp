#include <iostream>

int main()
{
    int liczba = 42;
    int* wskaznik = &liczba;

    std::cout << "Przez zmienna: " << liczba << std::endl;
    std::cout << "Przez wskaznik: " << *wskaznik << std::endl;

    *wskaznik = 100;

    std::cout << "Po zmianie: " << liczba << std::endl;
    return 0;
}
