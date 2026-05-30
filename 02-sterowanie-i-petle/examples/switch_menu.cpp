#include <iostream>

int main()
{
    int wybor;

    std::cout << "1. Nowa gra\n";
    std::cout << "2. Wczytaj gre\n";
    std::cout << "3. Wyjscie\n";
    std::cout << "Wybor: ";
    std::cin >> wybor;

    switch (wybor)
    {
        case 1:
            std::cout << "Rozpoczynam nowa gre" << std::endl;
            break;
        case 2:
            std::cout << "Wczytuje gre" << std::endl;
            break;
        case 3:
            std::cout << "Koniec programu" << std::endl;
            break;
        default:
            std::cout << "Nieznana opcja" << std::endl;
            break;
    }

    return 0;
}
