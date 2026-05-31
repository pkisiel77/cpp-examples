#include <iostream>

void wypiszJesliIstnieje(const int* liczba)
{
    if (liczba != nullptr)
    {
        std::cout << "Wartosc: " << *liczba << std::endl;
    }
    else
    {
        std::cout << "Brak wartosci" << std::endl;
    }
}

int main()
{
    int x = 42;
    int* pusty = nullptr;

    wypiszJesliIstnieje(&x);
    wypiszJesliIstnieje(pusty);

    return 0;
}
