# 06 - Zadania

## Cel zestawu zadań

Ten plik zbiera zadania do segmentu [03 - Funkcje, tablice, napisy](README.md). Zadania sprawdzają umiejętność dzielenia programu na funkcje oraz pracy z tablicami i napisami.

## Zasady wykonania

Każde zadanie powinno być zapisane w osobnym pliku `.cpp`. Program powinien
kompilować się bez błędów i wypisywać wynik w czytelnej formie.

Przykład kompilacji:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic nazwa_pliku.cpp -o program
./program
```

Przed oddaniem zadania sprawdź:

- czy główna logika jest wydzielona do funkcji,
- czy funkcje mają czytelne nazwy i pojedynczą odpowiedzialność,
- czy tablice są przekazywane razem z rozmiarem,
- czy indeksy nie wychodzą poza zakres tablicy,
- czy program był sprawdzony dla danych typowych i granicznych.

## Poziom 1 - Funkcje

### Zadanie 1. Podstawowe działania

Napisz funkcje:

- `dodaj(int a, int b)`,
- `odejmij(int a, int b)`,
- `pomnoz(int a, int b)`,
- `podziel(double a, double b)`.

W funkcji `main` pokaż działanie każdej funkcji.

Wymagania:

- funkcje obliczające powinny zwracać wynik przez `return`,
- `main` powinien tylko przygotować dane, wywołać funkcje i wypisać wyniki,
- przy dzieleniu przez zero wypisz komunikat zamiast wykonywać działanie.

Scenariusz sprawdzenia:

```text
Dane: 10 i 5
Suma: 15
Roznica: 5
Iloczyn: 50
Iloraz: 2
```

### Zadanie 2. Kwadrat i sześcian

Napisz funkcje `kwadrat` i `szescian`, które przyjmują liczbę i zwracają odpowiednio drugą oraz trzecią potęgę tej liczby.

Sprawdź funkcje dla wartości `0`, `2` i `-3`.

### Zadanie 3. Parzystość

Napisz funkcję `czyParzysta`, która przyjmuje liczbę całkowitą i zwraca `true`, jeśli liczba jest parzysta.

W `main` wypisz wynik jako tekst `parzysta` albo `nieparzysta`, nie jako `0`
lub `1`.

### Zadanie 4. BMI

Napisz funkcję `obliczBmi`, która przyjmuje masę i wzrost, a następnie zwraca wartość BMI.

Rozbuduj program o funkcję `wypiszKategorieBmi`, która wypisuje opis wyniku.

Wymagania:

- `obliczBmi` nie powinna nic wypisywać,
- `wypiszKategorieBmi` powinna przyjmować gotową wartość BMI,
- wynik BMI wypisz z dokładnością do dwóch miejsc po przecinku.

### Zadanie 5. Maksimum

Napisz funkcję `maksimum`, która przyjmuje dwie liczby całkowite i zwraca większą z nich.

Sprawdź przypadki:

- pierwsza liczba większa,
- druga liczba większa,
- obie liczby równe.

## Poziom 2 - Tablice jednowymiarowe

### Zadanie 6. Wypisywanie tablicy

Utwórz tablicę pięciu liczb całkowitych i wypisz wszystkie elementy.

Wymagania:

- użyj pętli,
- nie wypisuj elementów ręcznie przez pięć osobnych instrukcji,
- wydziel funkcję `wypiszTablice`.

### Zadanie 7. Suma i średnia

Utwórz tablicę liczb całkowitych. Napisz funkcje:

- `sumaTablicy`,
- `sredniaTablicy`.

Funkcje powinny przyjmować tablicę i jej rozmiar.

Scenariusz sprawdzenia:

```text
Tablica: 2 4 6 8
Suma: 20
Srednia: 5
```

### Zadanie 8. Minimum i maksimum

Napisz funkcje `minimumTablicy` i `maksimumTablicy`, które znajdują najmniejszą oraz największą wartość w tablicy.

Sprawdź tablicę zawierającą liczby dodatnie, ujemne i zero.

### Zadanie 9. Odwrotna kolejność

Wczytaj od użytkownika pięć liczb do tablicy, a następnie wypisz je w odwrotnej kolejności.

Przykład:

```text
Dane:
1 2 3 4 5

Wynik:
5 4 3 2 1
```

### Zadanie 10. Liczby parzyste

Napisz funkcję, która zlicza, ile elementów tablicy jest parzystych.

Wymagania:

- funkcja powinna zwracać liczbę elementów parzystych,
- sprawdź przypadek, w którym tablica nie ma żadnej liczby parzystej.

## Poziom 3 - Tablice dwuwymiarowe

### Zadanie 11. Wypisywanie macierzy

Utwórz tablicę `3 x 3` liczb całkowitych i wypisz ją w formie tabeli.

Wymagania:

- użyj dwóch pętli,
- każdy wiersz macierzy wypisz w osobnej linii.

### Zadanie 12. Suma macierzy

Napisz program, który oblicza sumę wszystkich elementów tablicy `3 x 3`.

Scenariusz sprawdzenia:

```text
Macierz:
1 2 3
4 5 6
7 8 9

Suma: 45
```

### Zadanie 13. Sumy wierszy i kolumn

Napisz program, który wypisuje:

- sumę każdego wiersza,
- sumę każdej kolumny.

Wymagania:

- przygotuj osobną funkcję do sumy wiersza,
- przygotuj osobną funkcję do sumy kolumny,
- użyj stałych dla liczby wierszy i kolumn.

### Zadanie 14. Największy element

Napisz program, który znajduje największy element w tablicy dwuwymiarowej.

Sprawdź przypadek, w którym największa wartość znajduje się w ostatnim wierszu
i ostatniej kolumnie.

### Zadanie 15. Plansza 3 x 3

Utwórz pustą planszę `3 x 3` dla gry w kółko i krzyżyk. Wypełnij ją spacjami i wypisz na ekran.

Wymagania:

- wydziel funkcję `wypelnijPlansze`,
- wydziel funkcję `wypiszPlansze`,
- do przechowywania pól użyj tablicy znaków.

## Poziom 4 - Napisy

### Zadanie 16. Długość napisu

Napisz program, który wczytuje imię i wypisuje liczbę znaków.

Wymagania:

- użyj `std::string`,
- użyj metody `.size()` albo `.length()`,
- wczytaj tekst przez `std::getline`.

### Zadanie 17. Znaki napisu

Napisz program, który wypisuje każdy znak napisu w osobnej linii.

Przykład:

```text
Dane:
kot

Wynik:
k
o
t
```

### Zadanie 18. Pierwszy i ostatni znak

Napisz funkcje:

- `pierwszyZnak`,
- `ostatniZnak`.

Funkcje powinny przyjmować `std::string` i zwracać znak.

Wymagania:

- jeśli napis jest pusty, wypisz komunikat o błędzie w `main`,
- funkcji nie wywołuj dla pustego napisu.

### Zadanie 19. Liczenie litery

Napisz funkcję, która zlicza, ile razy litera `a` występuje w napisie.

Sprawdź napisy:

- `ala` - wynik `2`,
- `kot` - wynik `0`,
- pusty napis - wynik `0`.

### Zadanie 20. Palindrom

Napisz funkcję `czyPalindrom`, która sprawdza, czy napis jest palindromem.

Na tym etapie załóż, że tekst:

- nie zawiera spacji,
- nie zawiera polskich znaków,
- ma tylko małe litery.

Scenariusze sprawdzenia:

- `kajak` - palindrom,
- `anna` - palindrom,
- `program` - nie jest palindromem.

## Poziom 5 - Zadania dodatkowe

### Zadanie 21. Kółko i krzyżyk - plansza

Przygotuj program, który przechowuje planszę gry w kółko i krzyżyk jako tablicę `3 x 3` znaków.

Program powinien:

- wypisać pustą planszę,
- pozwolić wpisać znak `X` lub `O` w wybrane pole,
- wypisać planszę po zmianie.

Wymagania:

- sprawdź, czy wybrane pole mieści się w zakresie planszy,
- nie pozwól nadpisać zajętego pola,
- wydziel funkcję do sprawdzania poprawności ruchu.

### Zadanie 22. Najdłuższy wspólny podciąg

Napisz funkcję, która przyjmuje dwa napisy i zwraca długość ich najdłuższego wspólnego podciągu.

Przykład:

```text
input: "ABCD", "ACDF"
output: 2
```

To zadanie jest dodatkowe, ponieważ wymaga dynamicznego podejścia do problemu.

### Zadanie 23. Liczby skojarzone z funkcjami

Przepisz zadanie o liczbach skojarzonych tak, aby program był podzielony na funkcje:

- `sumaDzielnikow`,
- `czySkojarzone`,
- funkcja odpowiedzialna za wypisanie wyniku.

## Wariant minimum

Do zaliczenia segmentu wykonaj co najmniej:

1. Zadanie 1 albo 2.
2. Zadanie 4 albo 5.
3. Zadanie 7 albo 8.
4. Zadanie 11 albo 12.
5. Zadanie 16 albo 17.
6. Zadanie 20.
7. Mini-sprawdzian segmentu z końca pliku.

Zadania 21-23 są dodatkowe. Możesz je robić po wykonaniu wariantu minimum.

## Kryteria zaliczenia segmentu

Student zalicza segment, jeśli potrafi samodzielnie:

- napisać własną funkcję i wywołać ją z `main`,
- przekazać argumenty do funkcji,
- zwrócić wynik przez `return`,
- użyć tablicy jednowymiarowej,
- użyć tablicy dwuwymiarowej,
- przejść po tablicy pętlą,
- wykonać podstawowe operacje na `std::string`,
- podzielić większy program na mniejsze funkcje.

## Mini-sprawdzian segmentu

Napisz program analizujący listę ocen, który:

- przechowuje oceny w tablicy,
- ma osobne funkcje do obliczania średniej, minimum i maksimum,
- wypisuje wyniki w czytelnej formie,
- sprawdza, czy każda ocena mieści się w zakresie od `1` do `6`,
- kompiluje się z `-Wall -Wextra -pedantic`.

Wymagania szczegółowe:

- przygotuj funkcję `czyPoprawnaOcena`,
- przygotuj funkcje `sredniaOcen`, `minimumOcen`, `maksimumOcen`,
- nie licz średniej, jeśli w danych jest niepoprawna ocena,
- wypisz jasny komunikat dla błędnych danych.

Scenariusz sprawdzenia:

```text
Oceny:
5 4 3 6 2

Srednia: 4
Minimum: 2
Maksimum: 6
```

## Checklista oddania

Przed oddaniem rozwiązań sprawdź:

- [ ] Każde zadanie jest w osobnym pliku `.cpp`.
- [ ] Programy kompilują się z `-Wall -Wextra -pedantic`.
- [ ] Program jest podzielony na funkcje, a `main` nie zawiera całej logiki.
- [ ] Funkcje obliczeniowe zwracają wynik zamiast wypisywać go bezpośrednio.
- [ ] Tablice są przekazywane razem z rozmiarem.
- [ ] Program nie wychodzi poza zakres tablicy ani napisu.
- [ ] Przypadki pustego napisu i błędnych danych są obsłużone tam, gdzie mogą wystąpić.

## Archiwum

Oryginalne materiały źródłowe tego segmentu są zachowane w katalogu [archive](archive).
