# Projekt 07 - Baza danych pojazdów

## Cel projektu

Celem projektu jest przygotowanie konsolowej aplikacji do zarządzania bazą
pojazdów. Projekt ma pokazać modelowanie danych za pomocą klas, operacje CRUD,
wyszukiwanie, walidację danych oraz zapis i odczyt bazy z pliku.

Minimalna wersja nie wymaga prawdziwej bazy danych. Wystarczy zapis do pliku
tekstowego, np. CSV. Baza SQL albo NoSQL może być rozszerzeniem projektu.

## Zakres funkcjonalny

System powinien umożliwiać:

- dodanie pojazdu,
- edycję danych pojazdu,
- usunięcie pojazdu,
- wyświetlenie danych pojedynczego pojazdu,
- wyświetlenie listy wszystkich pojazdów,
- wyszukiwanie po numerze rejestracyjnym,
- filtrowanie po typie pojazdu albo marce,
- zapis bazy do pliku,
- odczyt bazy z pliku przy starcie programu,
- obsługę błędnych danych wejściowych.

## Wymagania techniczne

Projekt powinien:

- być napisany w C++17,
- używać klas do modelowania pojazdu i bazy pojazdów,
- używać `std::vector` do przechowywania pojazdów,
- używać `std::map` albo `std::unordered_map` jako indeksu po numerze
  rejestracyjnym,
- używać `enum class` dla typu pojazdu,
- zapisywać dane do pliku tekstowego, np. CSV,
- rozdzielać deklaracje i implementacje na pliki `.h` i `.cpp`,
- kompilować się z flagami `-Wall -Wextra -pedantic`.

## Proponowana struktura plików

```text
vehicle-database/
  include/vehicle_database/
    vehicle.h
    vehicle_type.h
    vehicle_database.h
    vehicle_storage.h
  src/
    vehicle.cpp
    vehicle_database.cpp
    vehicle_storage.cpp
    main.cpp
  tests/
    vehicle_database_tests.cpp
  data/
    vehicles.csv
  build/
```

Znaczenie elementów:

- `Vehicle` - dane pojedynczego pojazdu,
- `VehicleType` - typ pojazdu,
- `VehicleDatabase` - operacje dodawania, edycji, usuwania i wyszukiwania,
- `VehicleStorage` - zapis i odczyt z pliku.

## Model danych

Pojazd powinien mieć co najmniej:

- `registrationNumber`,
- `brand`,
- `model`,
- `productionYear`,
- `type`,
- `ownerName`.

Przykład:

```cpp
enum class VehicleType {
    Car,
    Motorcycle,
    Truck,
    Bus
};

struct Vehicle {
    std::string registrationNumber;
    std::string brand;
    std::string model;
    int productionYear;
    VehicleType type;
    std::string ownerName;
};
```

## Minimalny wariant zaliczeniowy

Minimalna wersja projektu powinna zawierać:

1. Menu konsolowe z opcjami:
   - dodaj pojazd,
   - edytuj pojazd,
   - usuń pojazd,
   - wyszukaj pojazd,
   - wyświetl wszystkie pojazdy,
   - zapisz dane,
   - wczytaj dane,
   - zakończ.
2. Walidację unikalnego numeru rejestracyjnego.
3. Walidację roku produkcji.
4. Zapis i odczyt danych z pliku CSV.
5. Przykładowy plik z danymi.
6. Instrukcję kompilacji i uruchomienia w `README.md` projektu.

## Rozszerzenia dla chętnych

Możliwe rozszerzenia:

- filtrowanie po właścicielu,
- sortowanie po marce, roczniku albo typie,
- historia zmian danych pojazdu,
- eksport raportu do pliku tekstowego,
- zapis do SQLite,
- import danych z innego pliku CSV,
- testy automatyczne dla `VehicleDatabase`,
- obsługa przeglądów technicznych i dat ubezpieczenia.

## Kryteria oceny

Projekt jest zaliczony, jeśli:

- kompiluje się bez błędów i ostrzeżeń,
- poprawnie dodaje pojazdy,
- odrzuca duplikaty numeru rejestracyjnego,
- umożliwia edycję i usuwanie pojazdów,
- wyszukuje pojazd po numerze rejestracyjnym,
- zapisuje i odczytuje dane z pliku,
- używa klas i kontenerów STL,
- ma czytelne menu konsolowe,
- zawiera instrukcję uruchomienia,
- zawiera testy albo opis ręcznych scenariuszy sprawdzenia.

## Scenariusze sprawdzenia

1. Dodaj trzy pojazdy i wyświetl całą bazę.
2. Spróbuj dodać drugi pojazd z tym samym numerem rejestracyjnym.
3. Edytuj właściciela wybranego pojazdu i sprawdź wynik wyszukiwania.
4. Usuń pojazd i sprawdź, czy nie pojawia się na liście.
5. Zapisz bazę do pliku, uruchom program ponownie i wczytaj dane.
