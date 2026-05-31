#include <fstream>
#include <iostream>

int main()
{
    std::ifstream plik("brak_pliku.txt");

    if (!plik)
    {
        std::cout << "Nie mozna otworzyc pliku brak_pliku.txt" << std::endl;
        return 1;
    }

    std::cout << "Plik zostal otwarty" << std::endl;
    return 0;
}
