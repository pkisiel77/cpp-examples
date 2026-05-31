#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::ifstream plik("linie.txt");

    if (!plik)
    {
        std::cout << "Nie mozna otworzyc pliku linie.txt" << std::endl;
        return 1;
    }

    std::string linia;
    int numerLinii = 1;

    while (std::getline(plik, linia))
    {
        std::istringstream strumienLinii(linia);
        int liczba = 0;
        std::string reszta;

        if ((strumienLinii >> liczba) && !(strumienLinii >> reszta))
        {
            std::cout << "Linia " << numerLinii << ": " << liczba << std::endl;
        }
        else
        {
            std::cout << "Linia " << numerLinii << ": pominieto bledne dane" << std::endl;
        }

        numerLinii++;
    }

    return 0;
}
