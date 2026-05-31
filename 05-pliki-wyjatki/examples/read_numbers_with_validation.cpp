#include <fstream>
#include <iostream>

int main()
{
    std::ifstream plik("liczby.txt");

    if (!plik)
    {
        std::cout << "Nie mozna otworzyc pliku liczby.txt" << std::endl;
        return 1;
    }

    int liczba = 0;
    int suma = 0;

    while (plik >> liczba)
    {
        suma += liczba;
    }

    if (!plik.eof())
    {
        std::cout << "Plik zawiera dane, ktore nie sa liczbami" << std::endl;
        return 1;
    }

    std::cout << "Suma: " << suma << std::endl;
    return 0;
}
