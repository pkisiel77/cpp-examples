#include <iostream>

int main()
{
    int szukana = 7;
    bool znaleziono = false;

    for (int i = 1; i <= 10; i++)
    {
        if (i == szukana)
        {
            znaleziono = true;
            break;
        }
    }

    if (znaleziono)
    {
        std::cout << "Znaleziono liczbe " << szukana << std::endl;
    }
    else
    {
        std::cout << "Nie znaleziono liczby" << std::endl;
    }

    return 0;
}
