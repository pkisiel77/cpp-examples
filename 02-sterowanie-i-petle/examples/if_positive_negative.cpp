#include <iostream>

int main()
{
    int liczba;

    std::cout << "Podaj liczbe: ";
    std::cin >> liczba;

    if (liczba > 0)
    {
        std::cout << "Liczba jest dodatnia" << std::endl;
    }
    else if (liczba < 0)
    {
        std::cout << "Liczba jest ujemna" << std::endl;
    }
    else
    {
        std::cout << "Liczba jest rowna zero" << std::endl;
    }

    return 0;
}
