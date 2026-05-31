#include <fstream>
#include <iostream>

int main()
{
    std::ofstream plik("dane.txt");

    if (!plik)
    {
        std::cout << "Nie mozna otworzyc pliku do zapisu" << std::endl;
        return 1;
    }

    plik << "Pierwsza linia" << std::endl;
    plik << "Druga linia" << std::endl;
    plik << "Trzecia linia" << std::endl;

    std::cout << "Zapisano dane do pliku dane.txt" << std::endl;
    return 0;
}
