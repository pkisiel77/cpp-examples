#include <fstream>
#include <iostream>

int main()
{
    std::ofstream plik("dane.txt", std::ios::app);

    if (!plik)
    {
        std::cout << "Nie mozna otworzyc pliku do dopisania" << std::endl;
        return 1;
    }

    plik << "Dopisany wpis" << std::endl;

    std::cout << "Dopisano dane do pliku dane.txt" << std::endl;
    return 0;
}
