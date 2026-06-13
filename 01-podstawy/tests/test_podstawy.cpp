#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

int dodaj(int a, int b) {
    return a + b;
}

double poleProstokata(double szerokosc, double wysokosc) {
    return szerokosc * wysokosc;
}

double obliczBmi(double masaKg, double wzrostM) {
    return masaKg / (wzrostM * wzrostM);
}

std::string opiszWynik(int punkty) {
    if (punkty >= 50) {
        return "zaliczone";
    }

    return "do poprawy";
}

std::string sformatujKwote(double kwota) {
    std::ostringstream out;
    out << std::fixed << std::setprecision(2) << kwota;
    return out.str();
}

void sprawdz(bool warunek, const std::string& opis) {
    if (!warunek) {
        std::cerr << "Blad testu: " << opis << '\n';
        std::exit(1);
    }
}

void sprawdzBlisko(double aktualna, double oczekiwana, double tolerancja, const std::string& opis) {
    const double roznica = aktualna > oczekiwana
        ? aktualna - oczekiwana
        : oczekiwana - aktualna;

    if (roznica > tolerancja) {
        std::cerr << "Blad testu: " << opis
                  << ", oczekiwano " << oczekiwana
                  << ", otrzymano " << aktualna << '\n';
        std::exit(1);
    }
}

int main() {
    sprawdz(dodaj(2, 3) == 5, "dodawanie liczb dodatnich");
    sprawdz(dodaj(-4, 9) == 5, "dodawanie liczby ujemnej i dodatniej");
    sprawdz(dodaj(0, 0) == 0, "dodawanie zer");

    sprawdzBlisko(poleProstokata(4.0, 2.5), 10.0, 0.0001, "pole prostokata");
    sprawdzBlisko(poleProstokata(0.0, 8.0), 0.0, 0.0001, "zerowa szerokosc daje pole zero");

    sprawdzBlisko(obliczBmi(80.0, 2.0), 20.0, 0.0001, "obliczenie BMI");
    sprawdzBlisko(obliczBmi(72.0, 1.8), 22.2222, 0.0001, "BMI dla liczby zmiennoprzecinkowej");

    sprawdz(opiszWynik(50) == "zaliczone", "prog zaliczenia");
    sprawdz(opiszWynik(80) == "zaliczone", "wynik powyzej progu");
    sprawdz(opiszWynik(49) == "do poprawy", "wynik ponizej progu");

    sprawdz(sformatujKwote(12.0) == "12.00", "formatowanie pelnej kwoty");
    sprawdz(sformatujKwote(3.456) == "3.46", "zaokraglenie do dwoch miejsc");

    const int liczbaCalkowita = dodaj(10, 5);
    const double liczbaZmiennoprzecinkowa = poleProstokata(3.0, 1.5);
    sprawdz(liczbaCalkowita == 15, "wynik calkowity z funkcji int");
    sprawdzBlisko(liczbaZmiennoprzecinkowa, 4.5, 0.0001, "wynik double z funkcji double");

    std::cout << "Wszystkie testy podstaw C++ przeszly\n";
    return 0;
}
