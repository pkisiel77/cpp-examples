#include <iostream>
#include <vector>

int main()
{
    std::vector<int> liczby;

    for (int i = 1; i <= 5; i++)
    {
        liczby.push_back(i);
    }

    std::cout << "Elementy:" << std::endl;
    for (const auto& liczba : liczby)
    {
        std::cout << liczba << std::endl;
    }

    if (!liczby.empty())
    {
        std::cout << "Pierwszy: " << liczby.front() << std::endl;
        std::cout << "Ostatni: " << liczby.back() << std::endl;
    }

    if (!liczby.empty())
    {
        liczby.pop_back();
    }

    std::cout << "Rozmiar po pop_back: " << liczby.size() << std::endl;

    return 0;
}
