#include <iostream>

int main()
{
    int wybor;

    do
    {
        std::cout << "1. Start" << std::endl;
        std::cout << "2. Pomoc" << std::endl;
        std::cout << "0. Wyjscie" << std::endl;
        std::cout << "Wybor: ";
        std::cin >> wybor;

        if (wybor == 1)
        {
            std::cout << "Start programu" << std::endl;
        }
        else if (wybor == 2)
        {
            std::cout << "Pomoc programu" << std::endl;
        }
        else if (wybor != 0)
        {
            std::cout << "Nieznana opcja" << std::endl;
        }
    }
    while (wybor != 0);

    std::cout << "Koniec programu" << std::endl;
    return 0;
}
