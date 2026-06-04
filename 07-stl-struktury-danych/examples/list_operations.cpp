#include <algorithm>
#include <iostream>
#include <list>

int main()
{
    std::list<int> liczby = {7, 5, 16, 8};

    liczby.push_front(25);
    liczby.push_back(13);

    auto miejsce = std::find(liczby.begin(), liczby.end(), 16);
    if (miejsce != liczby.end())
    {
        liczby.insert(miejsce, 42);
    }

    liczby.remove(5);

    std::cout << "Lista:" << std::endl;
    for (const auto& liczba : liczby)
    {
        std::cout << liczba << std::endl;
    }

    return 0;
}
