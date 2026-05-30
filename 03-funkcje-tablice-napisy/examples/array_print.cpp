#include <iostream>

int main()
{
    int liczby[] = {1, 3, 6, 3, 4, 7, 8, 4, 3};
    int rozmiar = sizeof(liczby) / sizeof(liczby[0]);

    for (int i = 0; i < rozmiar; i++)
    {
        std::cout << liczby[i] << std::endl;
    }

    return 0;
}
