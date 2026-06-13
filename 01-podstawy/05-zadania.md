# 05 - Zadania

## Cel zestawu zadań

Ten plik zbiera zadania do segmentu [01 - Podstawy C++](README.md). Zadania są ułożone od najprostszych do trudniejszych i korzystają z materiału z lekcji:

1. [01-pierwszy-program.md](01-pierwszy-program.md),
2. [02-wejscie-wyjscie.md](02-wejscie-wyjscie.md),
3. [03-typy-zmienne-operatory.md](03-typy-zmienne-operatory.md),
4. [04-formatowanie-wyjscia.md](04-formatowanie-wyjscia.md).

## Zasady wykonania

Każde zadanie powinno być zapisane w osobnym pliku `.cpp`. Program powinien
kompilować się bez błędów i wypisywać wynik w czytelnej formie.

Przykład kompilacji:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic nazwa_pliku.cpp -o program
./program
```

Przed oddaniem zadania sprawdź:

- czy plik ma rozszerzenie `.cpp`,
- czy program zawiera funkcję `main`,
- czy nazwy zmiennych opisują dane, które przechowują,
- czy program działa dla przykładowych danych z treści zadania,
- czy wynik jest wypisany w formie zrozumiałej dla użytkownika.

## Poziom 1 - Pierwsze programy

### Zadanie 1. Powitanie

Napisz program, który wypisuje Twoje imię oraz nazwę grupy.

Przykładowy wynik:

```text
Imie: Jan
Grupa: 1A
```

Wymagania:

- użyj `#include <iostream>`,
- wypisz każdą informację w osobnej linii,
- zakończ program przez `return 0;`.

### Zadanie 2. Trzy linie tekstu

Napisz program, który wypisuje trzy osobne linie:

- nazwę języka programowania,
- nazwę środowiska pracy,
- datę wykonania zadania.

Przykładowy wynik:

```text
Jezyk: C++
Srodowisko: Visual Studio Code
Data: 2026-06-13
```

### Zadanie 3. Komentarze

Napisz prosty program wypisujący dowolny tekst. Dodaj:

- jeden komentarz jednoliniowy,
- jeden komentarz wieloliniowy.

Komentarze powinny wyjaśniać cel programu albo znaczenie fragmentu kodu. Nie
dodawaj komentarza typu `wypisuje tekst` nad oczywistą instrukcją `std::cout`.

### Zadanie 4. Pierwsza wizytówka

Napisz program, który wypisuje prostą wizytówkę:

```text
====================
Jan Kowalski
Technik programista
====================
```

Wymagania:

- użyj kilku instrukcji `std::cout`,
- zadbaj o czytelne łamanie linii,
- nie wczytuj danych od użytkownika.

## Poziom 2 - Wejście i wyjście

### Zadanie 5. Dane użytkownika

Napisz program, który pyta użytkownika o imię i wiek, a następnie wypisuje zdanie:

```text
Czesc, Jan. Masz 20 lat.
```

Scenariusz sprawdzenia:

```text
Dane wejsciowe:
Jan
20

Oczekiwany fragment wyniku:
Czesc, Jan. Masz 20 lat.
```

### Zadanie 6. Imię i nazwisko

Napisz program, który wczytuje imię i nazwisko w jednej linii przy pomocy `std::getline`, a następnie wypisuje je na ekran.

Wskazówka: jeśli wcześniej używasz `std::cin >>`, przed `std::getline` może być
potrzebne oczyszczenie znaku końca linii. W tym zadaniu najlepiej użyć tylko
`std::getline`.

### Zadanie 7. Krótki formularz

Napisz program, który wczytuje:

- imię,
- miasto,
- nazwę szkoły.

Następnie wypisuje jedno podsumowanie:

```text
Jan mieszka w Gdansku i uczy sie w Technikum nr 1.
```

### Zadanie 8. Argumenty programu

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

### Zadanie 9. Dwie liczby

Napisz program, który wczytuje dwie liczby całkowite i wypisuje:

- sumę,
- różnicę,
- iloczyn,
- wynik dzielenia całkowitego,
- resztę z dzielenia.

Scenariusz sprawdzenia:

```text
Dane wejsciowe:
17
5

Oczekiwane wyniki:
Suma: 22
Roznica: 12
Iloczyn: 85
Dzielenie calkowite: 3
Reszta: 2
```

### Zadanie 10. Pole prostokąta

Napisz program, który oblicza pole prostokąta. Długości boków `a` i `b` użytkownik podaje z klawiatury. Użyj typu `double`.

Wynik wypisz z dokładnością do dwóch miejsc po przecinku.

### Zadanie 11. Pole i obwód koła

Napisz program, który wczytuje promień koła i oblicza:

- pole koła,
- obwód koła.

Przyjmij:

```cpp
const double PI = 3.141592653589793;
```

Wyniki wypisz z dokładnością do dwóch miejsc po przecinku.

### Zadanie 12. BMI

Napisz kalkulator BMI.

Użytkownik podaje:

- masę ciała w kilogramach,
- wzrost w metrach.

Wzór:

```cpp
BMI = masa / (wzrost * wzrost)
```

Program powinien wypisać wartość BMI z dokładnością do dwóch miejsc po przecinku.

Scenariusz sprawdzenia:

```text
Dane wejsciowe:
80
2

Oczekiwany wynik:
BMI: 20.00
```

### Zadanie 13. Pierwiastek i potęga

Napisz program, który wczytuje liczbę `x` typu `double`, a następnie wypisuje:

- pierwiastek kwadratowy z `x`,
- kwadrat liczby `x`,
- sześcian liczby `x`.

Użyj funkcji `std::sqrt` i `std::pow` z biblioteki `cmath`.

### Zadanie 14. Czas w sekundach

Napisz program, który wczytuje liczbę sekund jako liczbę całkowitą, a następnie
przelicza ją na godziny, minuty i sekundy.

Przykład:

```text
Dane wejsciowe:
3671

Oczekiwany wynik:
1 h 1 min 11 s
```

Wymagania:

- użyj dzielenia całkowitego,
- użyj operatora reszty z dzielenia `%`,
- nie używaj instrukcji warunkowych.

## Poziom 4 - Formatowanie wyjścia

### Zadanie 15. Liczba PI

Napisz program, który wypisuje liczbę PI:

- z dokładnością do dwóch miejsc po przecinku,
- z dokładnością do pięciu miejsc po przecinku,
- z dokładnością do dziesięciu miejsc po przecinku.

### Zadanie 16. Prosta tabela

Napisz program, który wypisuje tabelę produktów:

| Produkt | Liczba sztuk | Cena |
| --- | ---: | ---: |
| Zeszyt | 3 | 4.50 |
| Dlugoopis | 1 | 6.99 |
| Linijka | 2 | 2.25 |

Użyj `std::setw`, aby wyrównać kolumny.

Wymagania:

- użyj `std::left` dla nazw produktów,
- użyj `std::right` dla liczb,
- ceny wypisz z dokładnością do dwóch miejsc po przecinku.

### Zadanie 17. Numer z zerami

Napisz program, który przechowuje numer zamówienia jako liczbę całkowitą, na przykład `123`, i wypisuje go w formacie:

```text
00000123
```

Użyj `std::setw` i `std::setfill`.

### Zadanie 18. Paragon

Napisz program, który wczytuje:

- nazwę produktu,
- cenę jednostkową,
- liczbę sztuk.

Następnie wypisuje prosty paragon:

```text
Produkt          Cena    Ilosc    Wartosc
Zeszyt           4.50        3      13.50
```

Wymagania:

- użyj `std::setw`,
- wynik wartości oblicz jako `cena * liczbaSztuk`,
- ceny i wartość wypisz z dokładnością do dwóch miejsc po przecinku.

## Poziom 5 - Zadania dodatkowe

### Zadanie 19. Palindrom tekstowy

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

### Zadanie 20. Prosty kalkulator argumentów

Napisz program, który przyjmuje przez argumenty programu dwie liczby całkowite i
wypisuje ich sumę.

Przykład:

```sh
./program 12 8
```

Wynik:

```text
Suma: 20
```

Wskazówka: zamiana tekstu na liczbę wymaga funkcji takiej jak `std::stoi`.

### Zadanie 21. Liczby skojarzone

Dwie różne liczby całkowite `a` i `b` większe od `1` nazwiemy skojarzonymi, jeśli:

- suma wszystkich dodatnich dzielników `a` mniejszych od `a` jest równa `b + 1`,
- suma wszystkich dodatnich dzielników `b` mniejszych od `b` jest równa `a + 1`.

Napisz program, który sprawdza, czy dwie liczby podane przez użytkownika są skojarzone.

Przykład: liczby `140` i `195` są skojarzone.

## Wariant minimum

Do zaliczenia segmentu wykonaj co najmniej:

1. Zadanie 1 albo 2.
2. Zadanie 5 albo 6.
3. Zadanie 9.
4. Zadanie 10 albo 11.
5. Zadanie 15 albo 16.
6. Mini-sprawdzian segmentu z końca pliku.

Zadania z poziomu 5 są dodatkowe. Możesz je robić po wykonaniu wariantu minimum.

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

## Mini-sprawdzian segmentu

Przed przejściem dalej student powinien samodzielnie napisać mały program, który:

- pyta użytkownika o nazwę produktu, cenę i liczbę sztuk,
- oblicza wartość zamówienia,
- wypisuje wynik z dokładnością do dwóch miejsc po przecinku,
- używa czytelnych nazw zmiennych,
- kompiluje się z flagami `-Wall -Wextra -pedantic`.

Scenariusz sprawdzenia:

```text
Dane wejsciowe:
Zeszyt
4.5
3

Oczekiwany wynik:
Produkt: Zeszyt
Wartosc zamowienia: 13.50
```

## Checklista oddania

Przed oddaniem rozwiązań sprawdź:

- [ ] Każde zadanie jest w osobnym pliku `.cpp`.
- [ ] Każdy program kompiluje się z `-Wall -Wextra -pedantic`.
- [ ] Programy nie wymagają plików wynikowych zapisanych w repozytorium.
- [ ] Wyniki są opisane, a nie wypisane jako same liczby.
- [ ] W zadaniach z `double` wynik ma wymaganą liczbę miejsc po przecinku.
- [ ] W zadaniach z wejściem przetestowano dane z treści zadania.
