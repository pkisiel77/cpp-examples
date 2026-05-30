#include <iostream>

int main()
{
    int liczby[] = {12, -4, 9, 27, 0, 15};
    int rozmiar = sizeof(liczby) / sizeof(liczby[0]);

    int minimum = liczby[0];
    int maksimum = liczby[0];

    for (int i = 1; i < rozmiar; i++)
    {
        if (liczby[i] < minimum)
        {
            minimum = liczby[i];
        }

        if (liczby[i] > maksimum)
        {
            maksimum = liczby[i];
        }
    }

    std::cout << "Minimum: " << minimum << std::endl;
    std::cout << "Maksimum: " << maksimum << std::endl;

    return 0;
}
