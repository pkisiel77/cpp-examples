#include <iostream>

int main()
{
    int liczby[] = {1, 3, 6, 3, 4, 7, 8, 4, 3};
    int rozmiar = sizeof(liczby) / sizeof(liczby[0]);
    int suma = 0;

    for (int i = 0; i < rozmiar; i++)
    {
        suma += liczby[i];
    }

    double srednia = static_cast<double>(suma) / rozmiar;

    std::cout << "Suma: " << suma << std::endl;
    std::cout << "Srednia: " << srednia << std::endl;

    return 0;
}
