# 04 - Formatowanie wyjścia

## Cel lekcji

Celem lekcji jest nauczenie podstawowego formatowania tekstu i liczb wypisywanych w konsoli.

## Wymagania wstępne

Student powinien znać materiał z lekcji:

- [01-pierwszy-program.md](01-pierwszy-program.md),
- [02-wejscie-wyjscie.md](02-wejscie-wyjscie.md),
- [03-typy-zmienne-operatory.md](03-typy-zmienne-operatory.md).

## Krótka teoria

### Biblioteka `iomanip`

Do formatowania wyjścia używamy biblioteki `iomanip`.

```cpp
#include <iomanip>
```

Pozwala ona między innymi ustawiać:

- liczbę cyfr wypisywanych dla wartości zmiennoprzecinkowych,
- stałą liczbę miejsc po przecinku,
- szerokość pola tekstowego,
- znak wypełnienia.

### `std::setprecision`

`std::setprecision` ustawia precyzję wypisywania liczb zmiennoprzecinkowych.

```cpp
#include <iomanip>
#include <iostream>

int main()
{
    double pi = 3.1415926535;

    std::cout << std::setprecision(4) << pi << std::endl;
    std::cout << std::setprecision(8) << pi << std::endl;

    return 0;
}
```

Bez `std::fixed` precyzja oznacza liczbę istotnych cyfr.

### `std::fixed`

`std::fixed` zmienia sposób wypisywania liczb zmiennoprzecinkowych. Po jego użyciu `std::setprecision` oznacza liczbę miejsc po przecinku.

```cpp
std::cout << std::fixed << std::setprecision(2) << 3.14159 << std::endl;
```

Wynik:

```text
3.14
```

Przykład znajduje się w pliku [examples/format_precision.cpp](examples/format_precision.cpp).

### `std::setw`

`std::setw` ustawia szerokość pola dla kolejnej wypisywanej wartości.

```cpp
std::cout << std::setw(10) << 77 << std::endl;
```

Jeżeli wartość jest krótsza niż podana szerokość, zostanie wyrównana spacjami.

Ważne: `std::setw` działa tylko na następną wartość wypisywaną do strumienia.

### `std::setfill`

`std::setfill` ustawia znak wypełnienia używany razem z `std::setw`.

```cpp
std::cout << std::setfill('*') << std::setw(10) << 15 << std::endl;
```

Przykładowy wynik:

```text
********15
```

## Przykład kodu: prosta tabela

```cpp
#include <iomanip>
#include <iostream>
#include <string>

int main()
{
    std::cout << std::left;
    std::cout << std::setw(12) << "Produkt"
              << std::right << std::setw(8) << "Cena" << std::endl;

    std::cout << std::left;
    std::cout << std::setw(12) << "Zeszyt"
              << std::right << std::setw(8) << 4.50 << std::endl;

    return 0;
}
```

Pełny przykład znajduje się w pliku [examples/format_table.cpp](examples/format_table.cpp).

## Zadania do wykonania

1. Napisz program, który wypisuje liczbę `3.1415926535` z dokładnością do dwóch miejsc po przecinku.
2. Napisz program, który wypisuje wynik dzielenia dwóch liczb typu `double` z dokładnością do trzech miejsc po przecinku.
3. Napisz program, który wypisuje trzy liczby całkowite w polach o szerokości `8`.
4. Napisz program, który wypisuje numer faktury w formacie podobnym do `00000123`.
5. Napisz program, który wypisuje prostą tabelę: nazwa produktu, liczba sztuk, cena.

## Checklist dla studenta

Przed zaliczeniem lekcji sprawdź, czy potrafisz:

- użyć `std::fixed`,
- ustawić precyzję przez `std::setprecision`,
- wyrównać kolumny przez `std::setw`,
- przygotować prostą tabelę tekstową,
- dobrać format wyniku do danych liczbowych.

## Kryteria zaliczenia

Program powinien:

- dołączać bibliotekę `iomanip`,
- używać `std::setprecision` dla liczb zmiennoprzecinkowych,
- używać `std::fixed`, gdy potrzebna jest stała liczba miejsc po przecinku,
- używać `std::setw` do wyrównania kolumn,
- wypisywać wynik w czytelnej formie.

## Pytania kontrolne

1. Do czego służy `std::setprecision`?
2. Co zmienia `std::fixed`?
3. Czy `std::setw` działa na wszystkie kolejne wartości, czy tylko na następną?
4. Do czego służy `std::setfill`?
5. Dlaczego formatowanie wyjścia jest ważne w programach konsolowych?
