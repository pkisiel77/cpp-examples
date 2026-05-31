#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::ifstream plik("dane.txt");

    if (!plik)
    {
        std::cout << "Nie mozna otworzyc pliku do odczytu" << std::endl;
        return 1;
    }

    std::string linia;
    int numerLinii = 1;

    while (std::getline(plik, linia))
    {
        std::cout << numerLinii << ": " << linia << std::endl;
        numerLinii++;
    }

    return 0;
}
