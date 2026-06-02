#include <algorithm>
#include <iostream>
#include <vector>

void wypisz(const std::vector<int>& liczby)
{
    for (const auto& liczba : liczby)
    {
        std::cout << liczba << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> liczby = {32, 71, 12, 45, 26, 80, 53, 33};

    std::sort(liczby.begin(), liczby.end());
    std::cout << "Rosnaco: ";
    wypisz(liczby);

    std::sort(liczby.begin(), liczby.end(), [](int a, int b)
    {
        return a > b;
    });

    std::cout << "Malejaco: ";
    wypisz(liczby);

    auto wynik = std::find_if(liczby.begin(), liczby.end(), [](int liczba)
    {
        return liczba < 30;
    });

    if (wynik != liczby.end())
    {
        std::cout << "Pierwsza liczba mniejsza od 30: " << *wynik << std::endl;
    }

    return 0;
}
