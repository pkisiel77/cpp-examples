#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

struct Student {
    std::string imie;
    int punkty;
};

const Student* znajdzNajlepszego(const std::vector<Student>& studenci) {
    const Student* najlepszy = nullptr;

    for (const auto& student : studenci) {
        if (najlepszy == nullptr || student.punkty > najlepszy->punkty) {
            najlepszy = &student;
        }
    }

    return najlepszy;
}

using IdUzytkownika = std::string;
using TrescWiadomosci = std::string;

enum class Priorytet {
    Niski,
    Normalny,
    Wysoki
};

struct Wiadomosc {
    IdUzytkownika idUzytkownika;
    TrescWiadomosci tresc;
    Priorytet priorytet{Priorytet::Normalny};
};

bool czyPilna(const Wiadomosc& wiadomosc) {
    return wiadomosc.priorytet == Priorytet::Wysoki;
}

std::vector<Wiadomosc> wybierzPilne(const std::vector<Wiadomosc>& wiadomosci) {
    std::vector<Wiadomosc> wynik;

    std::copy_if(wiadomosci.begin(), wiadomosci.end(), std::back_inserter(wynik),
                 [](const Wiadomosc& wiadomosc) {
                     return czyPilna(wiadomosc);
                 });

    return wynik;
}

class Raport {
public:
    Raport(std::string tytul, std::vector<int> wartosci)
        : tytul(std::move(tytul)), wartosci(std::move(wartosci)) {}

    const std::string& pobierzTytul() const {
        return tytul;
    }

    std::size_t liczbaWartosci() const {
        return wartosci.size();
    }

private:
    std::string tytul;
    std::vector<int> wartosci;
};

void sprawdz(bool warunek, const std::string& opis) {
    if (!warunek) {
        std::cerr << "Blad testu: " << opis << '\n';
        std::exit(1);
    }
}

int main() {
    const std::vector<Student> studenci{
        {"Anna", 82},
        {"Jan", 47},
        {"Maria", 91},
    };

    const Student* najlepszy = znajdzNajlepszego(studenci);
    sprawdz(najlepszy != nullptr, "znaleziono najlepszego studenta");
    sprawdz(najlepszy->imie == "Maria", "najlepszy student ma poprawne imie");
    sprawdz(najlepszy->punkty == 91, "najlepszy student ma poprawna liczbe punktow");
    sprawdz(znajdzNajlepszego({}) == nullptr, "pusty wektor zwraca nullptr");

    const std::vector<Wiadomosc> wiadomosci{
        {"u001", "Raport gotowy", Priorytet::Normalny},
        {"u002", "Awaria systemu", Priorytet::Wysoki},
        {"u003", "Newsletter", Priorytet::Niski},
        {"u004", "Backup nieudany", Priorytet::Wysoki},
    };

    const auto pilne = wybierzPilne(wiadomosci);
    sprawdz(pilne.size() == 2, "lambda filtruje pilne wiadomosci");
    sprawdz(pilne.at(0).idUzytkownika == "u002", "zachowana kolejnosc filtrowania");
    sprawdz(pilne.at(1).tresc == "Backup nieudany", "druga pilna wiadomosc jest poprawna");

    const auto liczbaNormalnych = std::count_if(
        wiadomosci.begin(), wiadomosci.end(),
        [](const Wiadomosc& wiadomosc) {
            return wiadomosc.priorytet == Priorytet::Normalny;
        });
    sprawdz(liczbaNormalnych == 1, "lambda liczy normalne wiadomosci");

    std::string tytul{"Raport miesieczny"};
    std::vector<int> wartosci{10, 20, 30};
    Raport raport{std::move(tytul), std::move(wartosci)};

    sprawdz(raport.pobierzTytul() == "Raport miesieczny", "raport przechowuje przeniesiony tytul");
    sprawdz(raport.liczbaWartosci() == 3, "raport przechowuje przeniesione wartosci");

    std::cout << "Wszystkie testy modern C++ przeszly\n";
    return 0;
}
