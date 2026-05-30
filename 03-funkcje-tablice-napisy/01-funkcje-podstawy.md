# 01 - Funkcje: podstawy

## Cel lekcji

Celem lekcji jest zrozumienie, czym jest funkcja, jak ją zadeklarować, zdefiniować i wywołać w programie C++.

## Wymagania wstępne

Student powinien znać:

- podstawową strukturę programu z funkcją `main`,
- typy danych i zmienne,
- instrukcje warunkowe oraz pętle z wcześniejszych segmentów.

## Po co są funkcje

Funkcja to nazwany blok kodu, który wykonuje określone zadanie.

Funkcje pomagają:

- dzielić program na mniejsze części,
- unikać powtarzania kodu,
- nadawać nazwę konkretnemu działaniu,
- łatwiej testować i poprawiać program.

Przykład myślenia funkcjami:

```text
program BMI:
1. wczytaj dane
2. oblicz BMI
3. wypisz wynik
```

Krok `oblicz BMI` może być osobną funkcją.

## Definicja funkcji

Definicja funkcji zawiera nagłówek oraz ciało funkcji.

```cpp
typ_zwracany nazwa_funkcji(lista_parametrow)
{
    // instrukcje
}
```

Przykład:

```cpp
int dodaj(int a, int b)
{
    return a + b;
}
```

Znaczenie elementów:

- `int` przed nazwą funkcji oznacza typ zwracanej wartości,
- `dodaj` to nazwa funkcji,
- `int a, int b` to parametry,
- `return a + b;` zwraca wynik działania funkcji.

## Wywołanie funkcji

Funkcję wywołujemy przez podanie jej nazwy i argumentów.

```cpp
int wynik = dodaj(2, 3);
```

Wartość `2` trafia do parametru `a`, a wartość `3` trafia do parametru `b`.

Pełny przykład znajduje się w pliku [examples/function_add.cpp](examples/function_add.cpp).

## Funkcja bez wartości zwracanej

Jeżeli funkcja nie zwraca wyniku, używamy typu `void`.

```cpp
void wypiszPowitanie()
{
    std::cout << "Witaj!" << std::endl;
}
```

Wywołanie:

```cpp
wypiszPowitanie();
```

Pełny przykład znajduje się w pliku [examples/function_void.cpp](examples/function_void.cpp).

## Deklaracja funkcji

Deklaracja informuje kompilator, że funkcja istnieje. Deklaracja kończy się średnikiem.

```cpp
int dodaj(int a, int b);
```

Można też pominąć nazwy parametrów:

```cpp
int dodaj(int, int);
```

Deklaracja jest potrzebna, gdy funkcja jest zdefiniowana po funkcji `main`.

```cpp
#include <iostream>

int dodaj(int a, int b); // deklaracja

int main()
{
    std::cout << dodaj(2, 3) << std::endl;
    return 0;
}

int dodaj(int a, int b) // definicja
{
    return a + b;
}
```

## Deklaracja a definicja

**Deklaracja** mówi, jak funkcja wygląda z zewnątrz:

```cpp
int dodaj(int a, int b);
```

**Definicja** zawiera kod funkcji:

```cpp
int dodaj(int a, int b)
{
    return a + b;
}
```

Funkcja może mieć wiele deklaracji, ale powinna mieć jedną definicję w programie.

## Nazwy funkcji

Dobra nazwa funkcji powinna mówić, co funkcja robi.

Dobre przykłady:

- `dodaj`,
- `obliczBmi`,
- `czyParzysta`,
- `wypiszMenu`.

Słabe przykłady:

- `f`,
- `x`,
- `test`,
- `licz`.

## Zadania

1. Napisz funkcję `dodaj`, która przyjmuje dwie liczby całkowite i zwraca ich sumę.
2. Napisz funkcję `kwadrat`, która przyjmuje liczbę całkowitą i zwraca jej kwadrat.
3. Napisz funkcję `wypiszPowitanie`, która nic nie zwraca i wypisuje tekst powitania.
4. Napisz funkcję `czyParzysta`, która przyjmuje liczbę całkowitą i zwraca `true`, jeśli liczba jest parzysta.
5. Napisz program, który korzysta z co najmniej trzech własnych funkcji.

## Kryteria zaliczenia

Program powinien:

- zawierać co najmniej jedną własną funkcję poza `main`,
- poprawnie deklarować i definiować funkcje,
- używać `return` w funkcjach zwracających wartość,
- używać `void` dla funkcji, które nie zwracają wyniku,
- kompilować się bez błędów.

## Pytania kontrolne

1. Czym jest funkcja?
2. Czym różni się deklaracja funkcji od definicji?
3. Do czego służy `return`?
4. Co oznacza typ zwracany `void`?
5. Dlaczego warto dzielić program na funkcje?
