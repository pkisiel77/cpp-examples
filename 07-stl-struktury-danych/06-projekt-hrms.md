# Projekt HRMS

## Cel lekcji

Celem projektu jest połączenie klas, kontenerów STL i algorytmów w jednym
programie. Zbudujemy prosty system do zarządzania pracownikami, działami oraz
wynagrodzeniami.

## Wymagania wstępne

Przed rozpoczęciem projektu warto znać:

- klasy i enkapsulację,
- [`std::vector`](02-vector.md),
- [algorytmy STL](03-algorytmy-stl.md),
- [`std::map`](04-map-i-slownik.md).

## Opis projektu

System HRMS przechowuje pracowników i pozwala:

- dodać pracownika wraz z wynagrodzeniem,
- wyświetlić pracowników wskazanego działu,
- zmienić wynagrodzenie pracownika,
- wyświetlić wszystkie wynagrodzenia,
- wyświetlić wynagrodzenia posortowane malejąco.

## Model pracownika

Klasa `Employee` opisuje jednego pracownika:

```cpp
class Employee {
private:
    std::string id;
    std::string name;
    std::string surname;
    std::string departmentId;
    std::string position;
};
```

Pola są prywatne. Pozostała część programu korzysta z publicznych metod
dostępowych, dzięki czemu klasa kontroluje sposób udostępniania danych.

## Dobór kontenerów

System używa trzech kontenerów:

```cpp
std::vector<Employee> employees;
std::map<std::string, std::vector<std::string>> departmentEmployees;
std::map<std::string, double> salaries;
```

- `employees` przechowuje pełne dane wszystkich pracowników,
- `departmentEmployees` przypisuje identyfikator działu do listy identyfikatorów
  pracowników,
- `salaries` przypisuje identyfikator pracownika do jego wynagrodzenia.

Taki podział pozwala ćwiczyć łączenie kilku struktur danych. W większym systemie
należałoby dodatkowo przeanalizować koszt wyszukiwania pracowników w wektorze.

## Dodawanie pracownika

Przed dodaniem pracownika system sprawdza, czy:

- identyfikator nie jest już używany,
- wynagrodzenie nie jest ujemne.

Po poprawnej walidacji dane trafiają do wszystkich właściwych kontenerów.
Ważne jest zachowanie ich spójności.

## Wyszukiwanie i zmiana wynagrodzenia

Do wyszukiwania wpisów w `std::map` używamy metody `find`:

```cpp
auto salaryIt = salaries.find(employeeId);

if (salaryIt != salaries.end()) {
    salaryIt->second = newSalary;
}
```

Metoda `find` pozwala odróżnić istniejący wpis od brakującego. Samo użycie
operatora `[]` utworzyłoby nowy wpis, gdyby klucza nie było w mapie.

## Sortowanie wynagrodzeń

Mapa porządkuje elementy według klucza, a nie według wynagrodzenia. Aby
wyświetlić pensje malejąco:

1. kopiujemy wpisy mapy do pomocniczego wektora,
2. sortujemy wektor funkcją `std::sort`,
3. wyświetlamy posortowane elementy.

```cpp
std::sort(sortedSalaries.begin(), sortedSalaries.end(),
          [](const auto& left, const auto& right) {
              return left.second > right.second;
          });
```

## Kompletny przykład

Kod kompletnego programu znajduje się w pliku
[`examples/hrms.cpp`](examples/hrms.cpp).

Kompilacja i uruchomienie:

```bash
c++ -std=c++17 examples/hrms.cpp -o hrms
./hrms
```

## Zadania rozszerzające

1. Dodaj metodę usuwającą pracownika ze wszystkich kontenerów.
2. Dodaj możliwość przeniesienia pracownika do innego działu.
3. Oblicz średnie wynagrodzenie w wybranym dziale.
4. Wyświetl pracowników posortowanych alfabetycznie.
5. Zapisz dane pracowników do pliku i odczytaj je po ponownym uruchomieniu.

## Kryteria ukończenia

Projekt jest ukończony, gdy:

- nie pozwala dodać dwóch pracowników z tym samym identyfikatorem,
- poprawnie wyświetla pracowników działu,
- pozwala zmienić istniejące wynagrodzenie,
- sortuje wynagrodzenia malejąco,
- kompiluje się bez błędów.

## Pytania kontrolne

1. Dlaczego dane jednego pracownika przechowujemy w klasie?
2. Dlaczego mapa działów przechowuje identyfikatory zamiast kopii pracowników?
3. Co się stanie, jeśli użyjemy `salaries[employeeId]` dla nieznanego klucza?
4. Dlaczego przed sortowaniem wynagrodzeń tworzymy wektor?
