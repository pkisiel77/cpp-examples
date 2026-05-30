#include <iostream>
#include <string>

int main()
{
    std::string imieINazwisko;

    std::cout << "Podaj imie i nazwisko: ";
    std::getline(std::cin, imieINazwisko);

    std::cout << "Uzytkownik: " << imieINazwisko << std::endl;
    return 0;
}
