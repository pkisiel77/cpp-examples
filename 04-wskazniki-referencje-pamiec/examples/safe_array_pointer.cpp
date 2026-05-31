#include <iostream>

void wypiszTablice(const int* tablica, int rozmiar)
{
    if (tablica == nullptr || rozmiar <= 0)
    {
        return;
    }

    for (int i = 0; i < rozmiar; i++)
    {
        std::cout << tablica[i] << std::endl;
    }
}

int main()
{
    int liczby[] = {1, 2, 3, 4, 5};
    int rozmiar = sizeof(liczby) / sizeof(liczby[0]);

    wypiszTablice(liczby, rozmiar);

    return 0;
}
