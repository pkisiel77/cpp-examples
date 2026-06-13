#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <string>
#include <vector>

std::vector<int> posortujRosnaco(std::vector<int> liczby)
{
    std::sort(liczby.begin(), liczby.end());
    return liczby;
}

std::vector<int> wybierzWiekszeOd(const std::vector<int>& liczby, int prog)
{
    std::vector<int> wynik;
    std::copy_if(liczby.begin(), liczby.end(), std::back_inserter(wynik),
                 [prog](int liczba) {
                     return liczba > prog;
                 });
    return wynik;
}

double znajdzOcene(const std::map<std::string, double>& oceny, const std::string& tytul)
{
    auto wynik = oceny.find(tytul);
    if (wynik == oceny.end())
    {
        return 0.0;
    }

    return wynik->second;
}

std::vector<std::string> obsluzKolejke(std::queue<std::string> zadania)
{
    std::vector<std::string> wykonane;

    while (!zadania.empty())
    {
        wykonane.push_back(zadania.front());
        zadania.pop();
    }

    return wykonane;
}

bool expectVector(const std::string& nazwa, const std::vector<int>& wynik, const std::vector<int>& oczekiwane)
{
    if (wynik == oczekiwane)
    {
        return true;
    }

    std::cout << "FAIL " << nazwa << std::endl;
    return false;
}

bool expectVectorString(const std::string& nazwa, const std::vector<std::string>& wynik, const std::vector<std::string>& oczekiwane)
{
    if (wynik == oczekiwane)
    {
        return true;
    }

    std::cout << "FAIL " << nazwa << std::endl;
    return false;
}

bool expectDouble(const std::string& nazwa, double wynik, double oczekiwane)
{
    if (wynik == oczekiwane)
    {
        return true;
    }

    std::cout << "FAIL " << nazwa << ": oczekiwano " << oczekiwane
              << ", otrzymano " << wynik << std::endl;
    return false;
}

int main()
{
    bool ok = true;

    ok = expectVector("sortowanie rosnace", posortujRosnaco({5, 1, 4, 2}), {1, 2, 4, 5}) && ok;
    ok = expectVector("filtrowanie wiekszych", wybierzWiekszeOd({1, 7, 3, 9, 2}, 3), {7, 9}) && ok;

    std::map<std::string, double> oceny{{"Matrix", 4.8}, {"Incepcja", 4.6}};
    ok = expectDouble("istniejacy klucz mapy", znajdzOcene(oceny, "Matrix"), 4.8) && ok;
    ok = expectDouble("brakujacy klucz mapy", znajdzOcene(oceny, "Nieznany"), 0.0) && ok;

    std::queue<std::string> kolejka;
    kolejka.push("pierwsze");
    kolejka.push("drugie");
    kolejka.push("trzecie");
    ok = expectVectorString("kolejnosc FIFO", obsluzKolejke(kolejka), {"pierwsze", "drugie", "trzecie"}) && ok;

    if (!ok)
    {
        return 1;
    }

    std::cout << "Wszystkie testy STL przeszly" << std::endl;
    return 0;
}
