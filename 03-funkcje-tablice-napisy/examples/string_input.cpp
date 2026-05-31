#include <iostream>
#include <string>

int main()
{
    std::string imieINazwisko;

    std::cout << "Podaj imie i nazwisko: ";
    std::getline(std::cin, imieINazwisko);

    std::cout << "Wczytano: " << imieINazwisko << std::endl;
    std::cout << "Liczba znakow: " << imieINazwisko.length() << std::endl;

    return 0;
}
