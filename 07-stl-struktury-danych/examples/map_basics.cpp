#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<std::string, int> magazyn;

    magazyn["monitor"] = 5;
    magazyn["klawiatura"] = 12;
    magazyn["mysz"] = 20;

    magazyn["monitor"] = 4;

    std::cout << "Magazyn:" << std::endl;
    for (const auto& produkt : magazyn)
    {
        std::cout << produkt.first << ": " << produkt.second << std::endl;
    }

    auto wynik = magazyn.find("klawiatura");
    if (wynik != magazyn.end())
    {
        std::cout << "Znaleziono klawiature, sztuk: " << wynik->second << std::endl;
    }

    magazyn.erase("mysz");

    std::cout << "Po usunieciu myszy, liczba produktow: " << magazyn.size() << std::endl;

    return 0;
}
