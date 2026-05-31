#include <fstream>
#include <iostream>
#include <limits>
#include <string>

const char* NAZWA_PLIKU = "dane.txt";

void ignorujReszteLinii()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void pokazMenu()
{
    std::cout << std::endl;
    std::cout << "1. Dodaj wpis" << std::endl;
    std::cout << "2. Wyswietl wpisy" << std::endl;
    std::cout << "3. Usun wszystkie wpisy" << std::endl;
    std::cout << "0. Wyjdz" << std::endl;
    std::cout << "Wybor: ";
}

int wczytajWybor()
{
    int wybor = -1;

    if (!(std::cin >> wybor))
    {
        std::cin.clear();
        ignorujReszteLinii();
        return -1;
    }

    ignorujReszteLinii();
    return wybor;
}

void dodajWpis()
{
    std::cout << "Podaj wpis: ";

    std::string wpis;
    std::getline(std::cin, wpis);

    if (wpis.empty())
    {
        std::cout << "Pusty wpis nie zostal zapisany" << std::endl;
        return;
    }

    std::ofstream plik(NAZWA_PLIKU, std::ios::app);

    if (!plik)
    {
        std::cout << "Nie mozna otworzyc pliku do zapisu" << std::endl;
        return;
    }

    plik << wpis << std::endl;
    std::cout << "Dodano wpis" << std::endl;
}

void wyswietlWpisy()
{
    std::ifstream plik(NAZWA_PLIKU);

    if (!plik)
    {
        std::cout << "Brak pliku z wpisami" << std::endl;
        return;
    }

    std::string linia;
    int numer = 1;

    while (std::getline(plik, linia))
    {
        std::cout << numer << ". " << linia << std::endl;
        numer++;
    }

    if (numer == 1)
    {
        std::cout << "Brak wpisow" << std::endl;
    }
}

void usunWpisy()
{
    std::ofstream plik(NAZWA_PLIKU);

    if (!plik)
    {
        std::cout << "Nie mozna otworzyc pliku do czyszczenia" << std::endl;
        return;
    }

    std::cout << "Usunieto wszystkie wpisy" << std::endl;
}

int main()
{
    int wybor = -1;

    do
    {
        pokazMenu();
        wybor = wczytajWybor();

        switch (wybor)
        {
            case 1:
                dodajWpis();
                break;
            case 2:
                wyswietlWpisy();
                break;
            case 3:
                usunWpisy();
                break;
            case 0:
                std::cout << "Koniec programu" << std::endl;
                break;
            default:
                std::cout << "Niepoprawny wybor" << std::endl;
                break;
        }
    }
    while (wybor != 0);

    return 0;
}
