# Ćwiczenie - Szyfr GADERYPOLUKI

## Cel ćwiczenia

Celem ćwiczenia jest napisanie programu konsolowego, który szyfruje tekst
podany przez użytkownika za pomocą prostego szyfru podstawieniowego
GADERYPOLUKI.

Ćwiczenie utrwala:

- pracę z `std::string`,
- iterowanie po znakach napisu,
- tworzenie funkcji zwracającej wynik,
- instrukcje warunkowe,
- rozdzielenie logiki od wejścia i wyjścia programu.

## Opis szyfru

Szyfr GADERYPOLUKI używa par zamienników:

```text
GA DE RY PO LU KI
```

Zasady:

- `G` zamienia się na `A`,
- `A` zamienia się na `G`,
- `D` zamienia się na `E`,
- `E` zamienia się na `D`,
- i tak dalej dla pozostałych par,
- znaki, których nie ma w kluczu, pozostają bez zmian.

Przykład:

```text
PROGRAM -> OYPAYGM
```

## Zakres funkcjonalny

Program powinien:

- poprosić użytkownika o wpisanie tekstu,
- zaszyfrować tekst szyfrem GADERYPOLUKI,
- wyświetlić wynik,
- zachować bez zmian znaki spoza klucza,
- działać dla tekstu składającego się z wielu znaków.

## Wymagania techniczne

Program powinien:

- być napisany w C++17,
- zawierać funkcję `encryptGaderypoluki`,
- przyjmować tekst jako `std::string`,
- zwracać zaszyfrowany tekst jako `std::string`,
- nie modyfikować bezpośrednio tekstu wejściowego,
- używać czytelnych nazw zmiennych i funkcji,
- kompilować się z flagami `-Wall -Wextra -pedantic`.

Przykładowy nagłówek funkcji:

```cpp
std::string encryptGaderypoluki(const std::string& text);
```

## Minimalny wariant zaliczeniowy

Minimalna wersja ćwiczenia powinna zawierać:

1. Wczytanie tekstu od użytkownika.
2. Funkcję szyfrującą.
3. Obsługę wszystkich par z klucza `GA-DE-RY-PO-LU-KI`.
4. Pozostawianie bez zmian znaków spoza klucza.
5. Wyświetlenie tekstu zaszyfrowanego.
6. Krótką instrukcję kompilacji i uruchomienia.

## Rozszerzenia dla chętnych

Możliwe rozszerzenia:

- obsługa małych liter,
- zachowanie wielkości liter,
- odszyfrowywanie tekstu tą samą funkcją,
- testy automatyczne dla funkcji szyfrującej,
- wczytanie tekstu z pliku,
- zapis wyniku do pliku,
- wybór własnego klucza podstawieniowego.

## Kryteria oceny

Ćwiczenie jest zaliczone, jeśli:

- program kompiluje się bez błędów i ostrzeżeń,
- funkcja szyfrująca jest wydzielona z `main`,
- program poprawnie szyfruje słowo `PROGRAM` jako `OYPAYGM`,
- program poprawnie zamienia wszystkie pary z klucza,
- program zostawia bez zmian znaki spoza klucza,
- kod jest czytelnie sformatowany.

## Scenariusze sprawdzenia

1. Wpisz `PROGRAM` i sprawdź, czy wynik to `OYPAYGM`.
2. Wpisz `GADERYPOLUKI` i sprawdź, czy każda litera została zamieniona
   na swoją parę.
3. Wpisz tekst zawierający spacje i cyfry, np. `ALA 123`, i sprawdź, czy znaki
   spoza klucza pozostały bez zmian.
4. Wpisz pusty tekst i sprawdź, czy program nie kończy się błędem.

## Źródło pierwotne

Zadanie pochodziło ze starszego materiału egzaminacyjnego i zostało
uporządkowane do formatu ćwiczenia repozytorium.
