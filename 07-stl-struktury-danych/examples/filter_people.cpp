#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

struct Osoba
{
    std::string imie;
    int wiek;
};

int main()
{
    std::vector<Osoba> osoby = {
        {"Anna", 24},
        {"Jan", 17},
        {"Ewa", 31},
        {"Adam", 15}
    };

    std::vector<Osoba> pelnoletni;

    std::copy_if(osoby.begin(), osoby.end(), std::back_inserter(pelnoletni), [](const Osoba& osoba)
    {
        return osoba.wiek >= 18;
    });

    std::sort(pelnoletni.begin(), pelnoletni.end(), [](const Osoba& a, const Osoba& b)
    {
        return a.imie < b.imie;
    });

    std::cout << "Pelnoletni:" << std::endl;
    for (const auto& osoba : pelnoletni)
    {
        std::cout << osoba.imie << ", wiek: " << osoba.wiek << std::endl;
    }

    osoby.erase(
        std::remove_if(osoby.begin(), osoby.end(), [](const Osoba& osoba)
        {
            return osoba.wiek < 18;
        }),
        osoby.end()
    );

    std::cout << "Liczba osob po usunieciu niepelnoletnich: " << osoby.size() << std::endl;

    return 0;
}
