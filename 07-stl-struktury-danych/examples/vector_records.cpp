#include <iostream>
#include <string>
#include <vector>

struct Kandydat
{
    std::string imie;
    std::string nazwisko;
    int wiek;
};

int main()
{
    std::vector<Kandydat> kandydaci;

    kandydaci.push_back({"Anna", "Nowak", 24});
    kandydaci.push_back({"Jan", "Kowalski", 30});
    kandydaci.push_back({"Ewa", "Zielinska", 27});

    std::cout << "Kandydaci:" << std::endl;

    for (const auto& kandydat : kandydaci)
    {
        std::cout << kandydat.imie << " "
                  << kandydat.nazwisko << ", wiek: "
                  << kandydat.wiek << std::endl;
    }

    std::cout << "Liczba kandydatow: " << kandydaci.size() << std::endl;

    return 0;
}
