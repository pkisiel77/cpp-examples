# 05 - Move semantics

## Cel lekcji

Celem lekcji jest zrozumienie podstaw semantyki przenoszenia. Student powinien
umieć rozpoznać sytuację, w której obiekt jest kopiowany, oraz sytuację, w
której zasoby mogą zostać przeniesione.

## Wymagania wstępne

Przed rozpoczęciem lekcji warto znać:

- klasy i konstruktory,
- konstruktor kopiujący,
- `std::vector`,
- referencje,
- podstawy zarządzania zasobami.

## Problem kopiowania

Kopiowanie obiektu oznacza utworzenie drugiego, niezależnego obiektu z taką samą
zawartością.

```cpp
Report copy = original;
```

Dla małych obiektów koszt jest niewielki. Dla obiektów przechowujących duże
wektory, napisy albo uchwyty do zasobów kopiowanie może być kosztowne.

## Przenoszenie

Przenoszenie pozwala przejąć zasoby z obiektu tymczasowego albo obiektu, którego
już nie potrzebujemy.

```cpp
Report moved = std::move(original);
```

Po `std::move(original)` obiekt `original` nadal istnieje, ale jego stan jest
poprawny tylko w sensie technicznym. Nie należy zakładać, że zachował dawną
zawartość.

## `std::move`

`std::move` niczego samo nie przenosi. Ono tylko zamienia wyrażenie na takie,
które może zostać obsłużone przez konstruktor przenoszący albo operator
przenoszący.

Do `std::move` potrzebny jest nagłówek:

```cpp
#include <utility>
```

## Konstruktor przenoszący

Konstruktor przenoszący przyjmuje referencję rvalue:

```cpp
Report(Report&& other) noexcept;
```

W praktyce często nie trzeba pisać go ręcznie, bo typy z biblioteki standardowej
same dobrze obsługują przenoszenie. Własny konstruktor w przykładzie służy
pokazaniu, kiedy przeniesienie następuje.

## Kiedy używać przenoszenia

Przenoszenie jest przydatne, gdy:

- obiekt posiada duży zasób,
- obiekt tymczasowy ma trafić do kontenera,
- funkcja zwraca duży obiekt,
- nie potrzebujemy już starej zawartości obiektu.

Nie należy używać `std::move` mechanicznie. Jeśli obiekt ma być dalej używany z
oczekiwaną zawartością, przenoszenie będzie błędem projektowym.

## Kompletny przykład

Przykład znajduje się w pliku
[`examples/move_semantics.cpp`](examples/move_semantics.cpp).

Kompilacja:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic examples/move_semantics.cpp -o move_semantics
./move_semantics
```

## Zadania do wykonania

1. Skompiluj i uruchom przykład.
2. Usuń `std::move` i sprawdź, czy uruchamia się kopiowanie czy przenoszenie.
3. Dodaj operator przypisania przenoszącego.
4. Dodaj metodę `size`, która zwraca liczbę elementów raportu.
5. Po przeniesieniu obiektu wypisz jego rozmiar i porównaj z nowym obiektem.

## Kryteria zaliczenia

Student zalicza lekcję, jeśli potrafi:

- wyjaśnić różnicę między kopiowaniem i przenoszeniem,
- użyć `std::move`,
- wyjaśnić, że `std::move` samo nie przenosi danych,
- rozpoznać konstruktor przenoszący,
- zachować ostrożność przy używaniu obiektu po przeniesieniu,
- skompilować przykład w standardzie C++17.
