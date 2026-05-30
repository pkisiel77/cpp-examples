# 05 - Zadania

## Cel

Ten plik zbiera zadania do segmentu [01 - Podstawy C++](README.md). Zadania są ułożone od najprostszych do trudniejszych i korzystają z materiału z lekcji:

1. [01-pierwszy-program.md](01-pierwszy-program.md),
2. [02-wejscie-wyjscie.md](02-wejscie-wyjscie.md),
3. [03-typy-zmienne-operatory.md](03-typy-zmienne-operatory.md),
4. [04-formatowanie-wyjscia.md](04-formatowanie-wyjscia.md).

## Zasady wykonania

Każde zadanie powinno być zapisane w osobnym pliku `.cpp`. Program powinien kompilować się bez błędów i wypisywać wynik w czytelnej formie.

Przykład kompilacji:

```sh
c++ nazwa_pliku.cpp -o program
./program
```

## Poziom 1 - Pierwsze programy

### Zadanie 1. Powitanie

Napisz program, który wypisuje Twoje imię oraz nazwę grupy.

Przykładowy wynik:

```text
Imie: Jan
Grupa: 1A
```

### Zadanie 2. Trzy linie tekstu

Napisz program, który wypisuje trzy osobne linie:

- nazwę języka programowania,
- nazwę środowiska pracy,
- datę wykonania zadania.

### Zadanie 3. Komentarze

Napisz prosty program wypisujący dowolny tekst. Dodaj:

- jeden komentarz jednoliniowy,
- jeden komentarz wieloliniowy.

## Poziom 2 - Wejście i wyjście

### Zadanie 4. Dane użytkownika

Napisz program, który pyta użytkownika o imię i wiek, a następnie wypisuje zdanie:

```text
Czesc, Jan. Masz 20 lat.
```

### Zadanie 5. Imię i nazwisko

Napisz program, który wczytuje imię i nazwisko w jednej linii przy pomocy `std::getline`, a następnie wypisuje je na ekran.

### Zadanie 6. Argumenty programu

Napisz program, który wypisuje wszystkie argumenty przekazane przy uruchomieniu programu.

Przykład uruchomienia:

```sh
./program Ala ma kota
```

Przykładowy wynik:

```text
Liczba argumentow: 4
0: ./program
1: Ala
2: ma
3: kota
```

## Poziom 3 - Typy, zmienne i operatory

### Zadanie 7. Dwie liczby

Napisz program, który wczytuje dwie liczby całkowite i wypisuje:

- sumę,
- różnicę,
- iloczyn,
- wynik dzielenia całkowitego,
- resztę z dzielenia.

### Zadanie 8. Pole prostokąta

Napisz program, który oblicza pole prostokąta. Długości boków `a` i `b` użytkownik podaje z klawiatury. Użyj typu `double`.

Wynik wypisz z dokładnością do dwóch miejsc po przecinku.

### Zadanie 9. Pole i obwód koła

Napisz program, który wczytuje promień koła i oblicza:

- pole koła,
- obwód koła.

Przyjmij:

```cpp
const double PI = 3.141592653589793;
```

Wyniki wypisz z dokładnością do dwóch miejsc po przecinku.

### Zadanie 10. BMI

Napisz kalkulator BMI.

Użytkownik podaje:

- masę ciała w kilogramach,
- wzrost w metrach.

Wzór:

```cpp
BMI = masa / (wzrost * wzrost)
```

Program powinien wypisać wartość BMI z dokładnością do dwóch miejsc po przecinku.

### Zadanie 11. Pierwiastek i potęga

Napisz program, który wczytuje liczbę `x` typu `double`, a następnie wypisuje:

- pierwiastek kwadratowy z `x`,
- kwadrat liczby `x`,
- sześcian liczby `x`.

Użyj funkcji `std::sqrt` i `std::pow` z biblioteki `cmath`.

## Poziom 4 - Formatowanie wyjścia

### Zadanie 12. Liczba PI

Napisz program, który wypisuje liczbę PI:

- z dokładnością do dwóch miejsc po przecinku,
- z dokładnością do pięciu miejsc po przecinku,
- z dokładnością do dziesięciu miejsc po przecinku.

### Zadanie 13. Prosta tabela

Napisz program, który wypisuje tabelę produktów:

| Produkt | Liczba sztuk | Cena |
| --- | ---: | ---: |
| Zeszyt | 3 | 4.50 |
| Dlugoopis | 1 | 6.99 |
| Linijka | 2 | 2.25 |

Użyj `std::setw`, aby wyrównać kolumny.

### Zadanie 14. Numer z zerami

Napisz program, który przechowuje numer zamówienia jako liczbę całkowitą, na przykład `123`, i wypisuje go w formacie:

```text
00000123
```

Użyj `std::setw` i `std::setfill`.

## Poziom 5 - Zadania dodatkowe

### Zadanie 15. Palindrom tekstowy

Napisz program, który sprawdza, czy tekst przekazany jako argument programu jest palindromem.

Na tym etapie możesz założyć, że tekst:

- nie zawiera spacji,
- składa się z małych liter,
- nie zawiera polskich znaków.

Przykład:

```sh
./program kajak
```

Wynik:

```text
To jest palindrom.
```

### Zadanie 16. Liczby skojarzone

Dwie różne liczby całkowite `a` i `b` większe od `1` nazwiemy skojarzonymi, jeśli:

- suma wszystkich dodatnich dzielników `a` mniejszych od `a` jest równa `b + 1`,
- suma wszystkich dodatnich dzielników `b` mniejszych od `b` jest równa `a + 1`.

Napisz program, który sprawdza, czy dwie liczby podane przez użytkownika są skojarzone.

Przykład: liczby `140` i `195` są skojarzone.

## Zadania przeniesione na później

Niektóre stare zadania z materiałów źródłowych dotyczą tematów, które pojawią się później:

- tablice,
- struktury,
- stos,
- ONP,
- sortowanie,
- macierze.

Ich oryginalne wersje są zachowane w katalogu [archive](archive). Wrócą w segmentach o funkcjach, tablicach, STL i OOP.

## Kryteria zaliczenia segmentu

Student zalicza segment, jeśli potrafi samodzielnie:

- napisać program z funkcją `main`,
- skompilować i uruchomić program,
- użyć `std::cin`, `std::cout` i `std::getline`,
- dobrać typy `int`, `double`, `bool`, `char`, `std::string`,
- wykonać podstawowe obliczenia,
- użyć `std::setprecision`, `std::fixed`, `std::setw` i `std::setfill`,
- przygotować czytelny wynik w konsoli.
