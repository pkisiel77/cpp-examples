#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

int main()
{
    std::vector<int> liczby = {10, 20, 30};
    std::map<std::string, double> ocenyFilmow;
    std::queue<std::string> zadania;
    std::stack<std::string> historia;

    ocenyFilmow["Matrix"] = 5.0;
    ocenyFilmow["Incepcja"] = 4.8;

    zadania.push("Wczytaj dane");
    zadania.push("Przetworz dane");

    historia.push("Dodano rekord");
    historia.push("Zmieniono rekord");

    std::cout << "Liczby:" << std::endl;
    for (const auto& liczba : liczby)
    {
        std::cout << liczba << std::endl;
    }

    std::cout << "Ocena Matrix: " << ocenyFilmow["Matrix"] << std::endl;
    std::cout << "Pierwsze zadanie: " << zadania.front() << std::endl;
    std::cout << "Ostatnia operacja: " << historia.top() << std::endl;

    return 0;
}
