#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

bool czyWDozwolonymPrzedziale(int liczba) {
    return (liczba >= -10 && liczba <= 13) || (liczba >= 25 && liczba <= 35);
}

std::string opiszOcene(int ocena) {
    switch (ocena) {
        case 1:
            return "niedostateczny";
        case 2:
            return "dopuszczajacy";
        case 3:
            return "dostateczny";
        case 4:
            return "dobry";
        case 5:
            return "bardzo dobry";
        case 6:
            return "celujacy";
        default:
            return "nieznana";
    }
}

int sumaOdJedenDo(int koniec) {
    int suma = 0;

    for (int i = 1; i <= koniec; ++i) {
        suma += i;
    }

    return suma;
}

int policzCyfry(int liczba) {
    if (liczba == 0) {
        return 1;
    }

    if (liczba < 0) {
        liczba = -liczba;
    }

    int licznik = 0;
    while (liczba > 0) {
        liczba /= 10;
        ++licznik;
    }

    return licznik;
}

int znajdzPierwszyPodzielnyPrzez(const std::vector<int>& liczby, int dzielnik) {
    if (dzielnik == 0) {
        return -1;
    }

    int znaleziony = -1;
    for (int liczba : liczby) {
        if (liczba % dzielnik == 0) {
            znaleziony = liczba;
            break;
        }
    }

    return znaleziony;
}

int sumaNieparzystych(const std::vector<int>& liczby) {
    int suma = 0;

    for (int liczba : liczby) {
        if (liczba % 2 == 0) {
            continue;
        }
        suma += liczba;
    }

    return suma;
}

void sprawdz(bool warunek, const std::string& opis) {
    if (!warunek) {
        std::cerr << "Blad testu: " << opis << '\n';
        std::exit(1);
    }
}

int main() {
    sprawdz(czyWDozwolonymPrzedziale(-10), "dolna granica pierwszego przedzialu");
    sprawdz(czyWDozwolonymPrzedziale(13), "gorna granica pierwszego przedzialu");
    sprawdz(czyWDozwolonymPrzedziale(25), "dolna granica drugiego przedzialu");
    sprawdz(czyWDozwolonymPrzedziale(35), "gorna granica drugiego przedzialu");
    sprawdz(!czyWDozwolonymPrzedziale(14), "liczba poza przedzialami");

    sprawdz(opiszOcene(1) == "niedostateczny", "switch obsluguje ocene 1");
    sprawdz(opiszOcene(5) == "bardzo dobry", "switch obsluguje ocene 5");
    sprawdz(opiszOcene(9) == "nieznana", "switch ma galaz default");

    sprawdz(sumaOdJedenDo(5) == 15, "for sumuje liczby od 1 do 5");
    sprawdz(sumaOdJedenDo(100) == 5050, "for sumuje liczby od 1 do 100");
    sprawdz(sumaOdJedenDo(0) == 0, "for nie wykonuje sie dla konca 0");

    sprawdz(policzCyfry(0) == 1, "while liczy zero jako jedna cyfre");
    sprawdz(policzCyfry(7) == 1, "while liczy jedna cyfre");
    sprawdz(policzCyfry(12345) == 5, "while liczy wiele cyfr");
    sprawdz(policzCyfry(-902) == 3, "while obsluguje liczbe ujemna");

    const std::vector<int> liczby{5, 7, 10, 12, 15};
    sprawdz(znajdzPierwszyPodzielnyPrzez(liczby, 2) == 10, "break zatrzymuje wyszukiwanie");
    sprawdz(znajdzPierwszyPodzielnyPrzez(liczby, 11) == -1, "brak podzielnej liczby");
    sprawdz(znajdzPierwszyPodzielnyPrzez(liczby, 0) == -1, "dzielenie przez zero jest odrzucone");

    sprawdz(sumaNieparzystych(liczby) == 27, "continue pomija liczby parzyste");
    sprawdz(sumaNieparzystych({2, 4, 6}) == 0, "same parzyste daja zero");

    std::cout << "Wszystkie testy sterowania i petli przeszly\n";
    return 0;
}
