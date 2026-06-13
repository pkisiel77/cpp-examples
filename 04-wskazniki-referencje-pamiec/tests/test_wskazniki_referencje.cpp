#include <cstdlib>
#include <iostream>
#include <string>

void zamienPrzezReferencje(int& pierwsza, int& druga) {
    const int tymczasowa = pierwsza;
    pierwsza = druga;
    druga = tymczasowa;
}

bool odczytajJesliIstnieje(const int* liczba, int& wynik) {
    if (liczba == nullptr) {
        return false;
    }

    wynik = *liczba;
    return true;
}

int sumaTablicy(const int* liczby, int rozmiar) {
    if (liczby == nullptr || rozmiar <= 0) {
        return 0;
    }

    int suma = 0;
    for (int i = 0; i < rozmiar; ++i) {
        suma += *(liczby + i);
    }

    return suma;
}

void znajdzMinMax(const int* liczby, int rozmiar, int& minimum, int& maksimum) {
    if (liczby == nullptr || rozmiar <= 0) {
        minimum = 0;
        maksimum = 0;
        return;
    }

    minimum = *liczby;
    maksimum = *liczby;

    for (int i = 1; i < rozmiar; ++i) {
        if (*(liczby + i) < minimum) {
            minimum = *(liczby + i);
        }
        if (*(liczby + i) > maksimum) {
            maksimum = *(liczby + i);
        }
    }
}

void sprawdz(bool warunek, const std::string& opis) {
    if (!warunek) {
        std::cerr << "Blad testu: " << opis << '\n';
        std::exit(1);
    }
}

int main() {
    int a = 10;
    int b = 20;
    zamienPrzezReferencje(a, b);
    sprawdz(a == 20, "pierwsza wartosc zostala zamieniona przez referencje");
    sprawdz(b == 10, "druga wartosc zostala zamieniona przez referencje");

    int wynik = 0;
    const int liczba = 42;
    sprawdz(odczytajJesliIstnieje(&liczba, wynik), "odczytano istniejaca wartosc");
    sprawdz(wynik == 42, "wskaznik zostal poprawnie zdereferencjonowany");

    wynik = -1;
    sprawdz(!odczytajJesliIstnieje(nullptr, wynik), "nullptr nie jest dereferencjonowany");
    sprawdz(wynik == -1, "wynik nie zmienia sie przy nullptr");

    const int liczby[] = {4, -2, 9, 1};
    sprawdz(sumaTablicy(liczby, 4) == 12, "suma tablicy przez wskaznik");
    sprawdz(sumaTablicy(nullptr, 4) == 0, "pusta tablica daje zero");
    sprawdz(sumaTablicy(liczby, 0) == 0, "zerowy rozmiar daje zero");

    int minimum = 0;
    int maksimum = 0;
    znajdzMinMax(liczby, 4, minimum, maksimum);
    sprawdz(minimum == -2, "minimum zwrocone przez referencje");
    sprawdz(maksimum == 9, "maksimum zwrocone przez referencje");

    znajdzMinMax(nullptr, 4, minimum, maksimum);
    sprawdz(minimum == 0, "minimum resetowane dla nullptr");
    sprawdz(maksimum == 0, "maksimum resetowane dla nullptr");

    std::cout << "Wszystkie testy wskaznikow i referencji przeszly\n";
    return 0;
}
