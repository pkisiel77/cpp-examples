# Projekt 11 - Parser plików CSV

## Cel projektu

Celem projektu jest przygotowanie aplikacji konsolowej do wczytywania,
przetwarzania i zapisywania plików CSV. Projekt ma pokazać pracę z plikami,
parsowanie tekstu, modelowanie danych tabelarycznych, filtrowanie, sortowanie
oraz obsługę błędów wejścia.

CSV powinien być traktowany jako format tekstowy z rekordami i kolumnami,
a nie tylko jako zwykłe dzielenie linii po przecinku. Warto uwzględnić
wartości ujęte w cudzysłowy oraz puste pola.

## Zakres funkcjonalny

Program powinien umożliwiać:

- wczytanie pliku CSV z dysku,
- rozpoznanie nagłówka kolumn,
- wyświetlenie danych w terminalu,
- wybór wybranych kolumn,
- filtrowanie rekordów po wartości w kolumnie,
- sortowanie rekordów po wskazanej kolumnie,
- zapis wyniku do nowego pliku CSV,
- wyświetlenie podstawowych informacji o pliku,
- obsługę pustych pól,
- obsługę błędnych ścieżek i niepoprawnych danych.

Przykładowe operacje:

```text
load students.csv
show
select name,grade
filter grade >= 4.0
sort name asc
save result.csv
```

## Wymagania techniczne

Projekt powinien:

- być napisany w C++17,
- mieć osobny moduł parsera CSV,
- mieć osobny model danych tabelarycznych,
- używać `std::vector` do przechowywania rekordów,
- używać `std::string` i strumieni plikowych,
- obsługiwać separator `,`,
- obsługiwać wartości w cudzysłowach,
- obsługiwać puste pola,
- używać algorytmów STL do sortowania i filtrowania,
- rozdzielać deklaracje i implementacje na pliki `.h` i `.cpp`,
- kompilować się z flagami `-Wall -Wextra -pedantic`.

## Proponowana struktura plików

```text
csv-parser/
  include/csv_parser/
    csv_parser.h
    csv_writer.h
    csv_table.h
    csv_record.h
    query.h
    menu.h
  src/
    csv_parser.cpp
    csv_writer.cpp
    csv_table.cpp
    query.cpp
    menu.cpp
    main.cpp
  tests/
    csv_parser_tests.cpp
  data/
    students.csv
    result.csv
  build/
```

Znaczenie elementów:

- `CsvParser` - zamiana pliku CSV na strukturę danych,
- `CsvWriter` - zapis danych do pliku CSV,
- `CsvTable` - tabela z nagłówkami i rekordami,
- `CsvRecord` - pojedynczy rekord,
- `Query` - wybieranie kolumn, filtrowanie i sortowanie,
- `Menu` - interfejs użytkownika w terminalu.

## Model danych

Tabela powinna mieć co najmniej:

- listę nazw kolumn,
- listę rekordów,
- informację o separatorze,
- metody wyszukiwania indeksu kolumny po nazwie.

Przykład:

```cpp
struct CsvRecord {
    std::vector<std::string> fields;
};

class CsvTable {
public:
    const std::vector<std::string>& headers() const;
    const std::vector<CsvRecord>& records() const;

    std::optional<std::size_t> columnIndex(const std::string& name) const;

private:
    std::vector<std::string> headers_;
    std::vector<CsvRecord> records_;
};
```

## Zasady parsowania CSV

Minimalna wersja parsera powinna obsługiwać:

- separator przecinka,
- koniec rekordu jako koniec linii,
- puste pola, np. `Jan,,Kowalski`,
- pola w cudzysłowach, np. `"Kowalski, Jan"`,
- podwójny cudzysłów wewnątrz pola, np. `"tekst ""w cudzysłowie"""`.

Nie trzeba od razu obsługiwać wszystkich wariantów CSV. Ważne jest jednak,
aby jasno opisać obsługiwany format i poprawnie zgłaszać błędy dla danych,
których program nie potrafi przetworzyć.

## Minimalny wariant zaliczeniowy

Minimalna wersja projektu powinna zawierać:

1. Menu konsolowe z opcjami:
   - wczytaj plik,
   - pokaż nagłówki,
   - pokaż dane,
   - wybierz kolumny,
   - filtruj rekordy,
   - sortuj rekordy,
   - zapisz wynik,
   - zakończ.
2. Wczytanie pliku z nagłówkiem.
3. Wyświetlenie danych w terminalu.
4. Filtrowanie po równości tekstowej, np. `city == Warsaw`.
5. Sortowanie rosnące po wybranej kolumnie.
6. Zapis przefiltrowanych danych do nowego pliku CSV.
7. Przykładowy plik wejściowy w katalogu `data`.
8. Instrukcję kompilacji i uruchomienia w `README.md` projektu.

## Rozszerzenia dla chętnych

Możliwe rozszerzenia:

- separator wybierany przez użytkownika,
- sortowanie malejące,
- filtrowanie liczbowe, np. `age > 18`,
- filtrowanie tekstowe typu `contains`,
- kilka filtrów połączonych operatorem `AND`,
- wykrywanie typu kolumny,
- paginacja wyników w terminalu,
- eksport tylko wybranych kolumn,
- testy automatyczne parsera,
- obsługa dużych plików bez wczytywania całości do pamięci.

## Kryteria oceny

Projekt jest zaliczony, jeśli:

- kompiluje się bez błędów i ostrzeżeń,
- poprawnie wczytuje przykładowy plik CSV,
- poprawnie rozpoznaje nagłówki,
- poprawnie obsługuje puste pola,
- poprawnie obsługuje pola w cudzysłowach,
- pozwala wybrać kolumny,
- filtruje rekordy po wartości,
- sortuje rekordy po kolumnie,
- zapisuje wynik do nowego pliku,
- zgłasza czytelne błędy dla niepoprawnych danych,
- zawiera instrukcję uruchomienia,
- zawiera testy albo opis ręcznych scenariuszy sprawdzenia.

## Scenariusze sprawdzenia

1. Wczytaj plik `students.csv` i wyświetl nagłówki.
2. Wyświetl pierwsze rekordy w terminalu.
3. Wybierz tylko kolumny `name` i `grade`.
4. Przefiltruj rekordy po warunku `city == Warsaw`.
5. Posortuj wynik po kolumnie `name`.
6. Zapisz wynik do pliku `result.csv`.
7. Wczytaj plik z polem `"Kowalski, Jan"` i sprawdź, czy przecinek nie dzieli
   pola na dwie kolumny.
8. Spróbuj wczytać nieistniejący plik i sprawdź komunikat błędu.
