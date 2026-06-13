#include <iostream>
#include <string>

int dodaj(int a, int b)
{
    return a + b;
}

int maksimum(int a, int b)
{
    if (a > b)
    {
        return a;
    }

    return b;
}

bool czyPalindrom(const std::string& tekst)
{
    for (std::size_t i = 0; i < tekst.size() / 2; ++i)
    {
        if (tekst[i] != tekst[tekst.size() - 1 - i])
        {
            return false;
        }
    }

    return true;
}

bool expectEqual(const std::string& nazwa, int wynik, int oczekiwane)
{
    if (wynik == oczekiwane)
    {
        return true;
    }

    std::cout << "FAIL " << nazwa << ": oczekiwano " << oczekiwane
              << ", otrzymano " << wynik << std::endl;
    return false;
}

bool expectEqual(const std::string& nazwa, bool wynik, bool oczekiwane)
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

    ok = expectEqual("dodaj liczby dodatnie", dodaj(2, 3), 5) && ok;
    ok = expectEqual("dodaj liczbe ujemna", dodaj(10, -4), 6) && ok;
    ok = expectEqual("maksimum pierwsza liczba", maksimum(9, 2), 9) && ok;
    ok = expectEqual("maksimum druga liczba", maksimum(3, 7), 7) && ok;
    ok = expectEqual("palindrom kajak", czyPalindrom("kajak"), true) && ok;
    ok = expectEqual("palindrom tekst zwykly", czyPalindrom("program"), false) && ok;

    if (!ok)
    {
        return 1;
    }

    std::cout << "Wszystkie testy przeszly" << std::endl;
    return 0;
}
