# 07 - Ćwiczenie: szyfr GADERYPOLUKI

## Cel ćwiczenia

Celem ćwiczenia jest napisanie programu konsolowego, który szyfruje tekst
podany przez użytkownika za pomocą prostego szyfru podstawieniowego
GADERYPOLUKI.

Ćwiczenie utrwala pracę z `std::string`, iterowanie po znakach napisu,
tworzenie funkcji zwracającej wynik i rozdzielenie logiki od wejścia oraz
wyjścia programu.

## Wymagania wstępne

Przed wykonaniem ćwiczenia student powinien znać:

- deklarowanie i definiowanie funkcji,
- przekazywanie napisu do funkcji,
- zwracanie wartości przez `return`,
- pętlę przechodzącą po znakach napisu,
- instrukcje warunkowe.

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

## Opis zadania

Napisz program, który:

- prosi użytkownika o wpisanie tekstu,
- szyfruje tekst szyfrem GADERYPOLUKI,
- wyświetla wynik,
- zachowuje bez zmian znaki spoza klucza,
- działa dla tekstu składającego się z wielu znaków.

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

Kompilowalny punkt startowy znajduje się w
[examples/string_gaderypoluki.cpp](examples/string_gaderypoluki.cpp).

## Wariant podstawowy

Minimalna wersja ćwiczenia powinna zawierać:

1. Wczytanie tekstu od użytkownika.
2. Funkcję szyfrującą.
3. Obsługę wszystkich par z klucza `GA-DE-RY-PO-LU-KI`.
4. Pozostawianie bez zmian znaków spoza klucza.
5. Wyświetlenie tekstu zaszyfrowanego.
6. Krótką instrukcję kompilacji i uruchomienia.

## Proponowany podział pracy

1. Napisz funkcję, która zamienia pojedynczy znak.
2. Sprawdź zamianę dla pary `G` i `A`.
3. Dodaj pozostałe pary klucza.
4. Napisz funkcję, która przechodzi po całym napisie.
5. Dodaj wczytywanie tekstu przez `std::getline`.
6. Sprawdź tekst ze znakami spoza klucza.

## Zadania dodatkowe

Po wykonaniu wariantu podstawowego możesz dodać:

- obsługę małych liter,
- zachowanie wielkości liter,
- odszyfrowywanie tekstu tą samą funkcją,
- testy automatyczne dla funkcji szyfrującej,
- wczytanie tekstu z pliku,
- zapis wyniku do pliku,
- wybór własnego klucza podstawieniowego.

## Pytania kontrolne

1. Dlaczego funkcja szyfrująca powinna zwracać nowy napis zamiast wypisywać wynik?
2. Jak sprawdzić, czy znak nie występuje w kluczu?
3. Dlaczego `std::getline` jest lepsze niż `std::cin >> text`, jeśli tekst może zawierać spacje?
4. Czy ten sam algorytm może odszyfrować tekst? Uzasadnij odpowiedź.

## Scenariusze sprawdzenia

1. Wpisz `PROGRAM` i sprawdź, czy wynik to `OYPAYGM`.
2. Wpisz `GADERYPOLUKI` i sprawdź, czy każda litera została zamieniona na swoją parę.
3. Wpisz tekst zawierający spacje i cyfry, np. `ALA 123`, i sprawdź, czy znaki spoza klucza pozostały bez zmian.
4. Wpisz pusty tekst i sprawdź, czy program nie kończy się błędem.

## Kryteria zaliczenia

Ćwiczenie jest zaliczone, jeśli:

- program kompiluje się bez błędów i ostrzeżeń,
- funkcja szyfrująca jest wydzielona z `main`,
- program poprawnie szyfruje słowo `PROGRAM` jako `OYPAYGM`,
- program poprawnie zamienia wszystkie pary z klucza,
- program zostawia bez zmian znaki spoza klucza,
- kod jest czytelnie sformatowany.

## Źródło

Ćwiczenie powstało na podstawie starszego zadania z
[zadań pomocniczych TNT](../10-projekty/tnt-tasks/encryption-1.md).
