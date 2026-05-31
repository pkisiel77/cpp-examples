#include <iostream>

int main()
{
    int* wskaznik = nullptr;

    if (wskaznik != nullptr)
    {
        std::cout << *wskaznik << std::endl;
    }
    else
    {
        std::cout << "Wskaznik jest pusty" << std::endl;
    }

    int liczba = 7;
    wskaznik = &liczba;

    if (wskaznik != nullptr)
    {
        std::cout << "Wartosc: " << *wskaznik << std::endl;
    }

    return 0;
}
