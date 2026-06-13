#include <iostream>
#include <sstream>
#include <string>

enum class WynikWalidacji
{
    Poprawny,
    PustaLinia,
    NieLiczba,
    PozaZakresem
};

WynikWalidacji wczytajLiczbeZLinii(const std::string& linia, int min, int max, int& wynik)
{
    if (linia.empty())
    {
        return WynikWalidacji::PustaLinia;
    }

    std::istringstream strumien(linia);
    int wartosc = 0;
    char dodatkowyZnak = '\0';

    if (!(strumien >> wartosc))
    {
        return WynikWalidacji::NieLiczba;
    }

    if (strumien >> dodatkowyZnak)
    {
        return WynikWalidacji::NieLiczba;
    }

    if (wartosc < min || wartosc > max)
    {
        return WynikWalidacji::PozaZakresem;
    }

    wynik = wartosc;
    return WynikWalidacji::Poprawny;
}

bool expectStatus(const std::string& nazwa, WynikWalidacji wynik, WynikWalidacji oczekiwany)
{
    if (wynik == oczekiwany)
    {
        return true;
    }

    std::cout << "FAIL " << nazwa << std::endl;
    return false;
}

bool expectInt(const std::string& nazwa, int wynik, int oczekiwany)
{
    if (wynik == oczekiwany)
    {
        return true;
    }

    std::cout << "FAIL " << nazwa << ": oczekiwano " << oczekiwany
              << ", otrzymano " << wynik << std::endl;
    return false;
}

int main()
{
    bool ok = true;
    int wynik = 0;

    ok = expectStatus("poprawna liczba", wczytajLiczbeZLinii("42", 0, 100, wynik), WynikWalidacji::Poprawny) && ok;
    ok = expectInt("wartosc poprawnej liczby", wynik, 42) && ok;
    ok = expectStatus("pusta linia", wczytajLiczbeZLinii("", 0, 100, wynik), WynikWalidacji::PustaLinia) && ok;
    ok = expectStatus("tekst zamiast liczby", wczytajLiczbeZLinii("abc", 0, 100, wynik), WynikWalidacji::NieLiczba) && ok;
    ok = expectStatus("liczba z dopiskiem", wczytajLiczbeZLinii("12abc", 0, 100, wynik), WynikWalidacji::NieLiczba) && ok;
    ok = expectStatus("wartosc za mala", wczytajLiczbeZLinii("-1", 0, 100, wynik), WynikWalidacji::PozaZakresem) && ok;
    ok = expectStatus("wartosc za duza", wczytajLiczbeZLinii("101", 0, 100, wynik), WynikWalidacji::PozaZakresem) && ok;

    if (!ok)
    {
        return 1;
    }

    std::cout << "Wszystkie testy walidacji przeszly" << std::endl;
    return 0;
}
