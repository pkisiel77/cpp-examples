# 06 - Zadania

## Cel zestawu zadań

Ten plik zbiera zadania do segmentu [03 - Funkcje, tablice, napisy](README.md). Zadania sprawdzają umiejętność dzielenia programu na funkcje oraz pracy z tablicami i napisami.

## Zasady wykonania

Każde zadanie powinno być zapisane w osobnym pliku `.cpp`. Program powinien kompilować się bez błędów i wypisywać wynik w czytelnej formie.

Przykład kompilacji:

```sh
c++ nazwa_pliku.cpp -o program
./program
```

## Poziom 1 - Funkcje

### Zadanie 1. Podstawowe działania

Napisz funkcje:

- `dodaj(int a, int b)`,
- `odejmij(int a, int b)`,
- `pomnoz(int a, int b)`,
- `podziel(double a, double b)`.

W funkcji `main` pokaż działanie każdej funkcji.

### Zadanie 2. Kwadrat i sześcian

Napisz funkcje `kwadrat` i `szescian`, które przyjmują liczbę i zwracają odpowiednio drugą oraz trzecią potęgę tej liczby.

### Zadanie 3. Parzystość

Napisz funkcję `czyParzysta`, która przyjmuje liczbę całkowitą i zwraca `true`, jeśli liczba jest parzysta.

### Zadanie 4. BMI

Napisz funkcję `obliczBmi`, która przyjmuje masę i wzrost, a następnie zwraca wartość BMI.

Rozbuduj program o funkcję `wypiszKategorieBmi`, która wypisuje opis wyniku.

### Zadanie 5. Maksimum

Napisz funkcję `maksimum`, która przyjmuje dwie liczby całkowite i zwraca większą z nich.

## Poziom 2 - Tablice jednowymiarowe

### Zadanie 6. Wypisywanie tablicy

Utwórz tablicę pięciu liczb całkowitych i wypisz wszystkie elementy.

### Zadanie 7. Suma i średnia

Utwórz tablicę liczb całkowitych. Napisz funkcje:

- `sumaTablicy`,
- `sredniaTablicy`.

Funkcje powinny przyjmować tablicę i jej rozmiar.

### Zadanie 8. Minimum i maksimum

Napisz funkcje `minimumTablicy` i `maksimumTablicy`, które znajdują najmniejszą oraz największą wartość w tablicy.

### Zadanie 9. Odwrotna kolejność

Wczytaj od użytkownika pięć liczb do tablicy, a następnie wypisz je w odwrotnej kolejności.

### Zadanie 10. Liczby parzyste

Napisz funkcję, która zlicza, ile elementów tablicy jest parzystych.

## Poziom 3 - Tablice dwuwymiarowe

### Zadanie 11. Wypisywanie macierzy

Utwórz tablicę `3 x 3` liczb całkowitych i wypisz ją w formie tabeli.

### Zadanie 12. Suma macierzy

Napisz program, który oblicza sumę wszystkich elementów tablicy `3 x 3`.

### Zadanie 13. Sumy wierszy i kolumn

Napisz program, który wypisuje:

- sumę każdego wiersza,
- sumę każdej kolumny.

### Zadanie 14. Największy element

Napisz program, który znajduje największy element w tablicy dwuwymiarowej.

### Zadanie 15. Plansza 3 x 3

Utwórz pustą planszę `3 x 3` dla gry w kółko i krzyżyk. Wypełnij ją spacjami i wypisz na ekran.

## Poziom 4 - Napisy

### Zadanie 16. Długość napisu

Napisz program, który wczytuje imię i wypisuje liczbę znaków.

### Zadanie 17. Znaki napisu

Napisz program, który wypisuje każdy znak napisu w osobnej linii.

### Zadanie 18. Pierwszy i ostatni znak

Napisz funkcje:

- `pierwszyZnak`,
- `ostatniZnak`.

Funkcje powinny przyjmować `std::string` i zwracać znak.

### Zadanie 19. Liczenie litery

Napisz funkcję, która zlicza, ile razy litera `a` występuje w napisie.

### Zadanie 20. Palindrom

Napisz funkcję `czyPalindrom`, która sprawdza, czy napis jest palindromem.

Na tym etapie załóż, że tekst:

- nie zawiera spacji,
- nie zawiera polskich znaków,
- ma tylko małe litery.

## Poziom 5 - Zadania dodatkowe

### Zadanie 21. Kółko i krzyżyk - plansza

Przygotuj program, który przechowuje planszę gry w kółko i krzyżyk jako tablicę `3 x 3` znaków.

Program powinien:

- wypisać pustą planszę,
- pozwolić wpisać znak `X` lub `O` w wybrane pole,
- wypisać planszę po zmianie.

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

## Archiwum

Oryginalne materiały źródłowe tego segmentu są zachowane w katalogu [archive](archive).
