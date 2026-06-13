# 01 - Instrukcje warunkowe

## Cel lekcji

Celem lekcji jest nauczenie zapisu decyzji w programie przy pomocy instrukcji `if`, `else if` i `else`.

## Wymagania wstępne

Student powinien znać podstawy z segmentu [01-podstawy](../01-podstawy/README.md): zmienne, typy danych, operatory arytmetyczne oraz wejście i wyjście.

## Krótka teoria

### Po co są instrukcje warunkowe

Instrukcja warunkowa pozwala wykonać fragment kodu tylko wtedy, gdy spełniony jest określony warunek.

Przykład:

```cpp
if (liczba > 0)
{
    std::cout << "Liczba jest dodatnia" << std::endl;
}
```

Kod w nawiasach klamrowych wykona się tylko wtedy, gdy `liczba > 0`.

### Operatory porównania

| Operator | Znaczenie |
| --- | --- |
| `==` | równe |
| `!=` | różne |
| `<` | mniejsze |
| `>` | większe |
| `<=` | mniejsze lub równe |
| `>=` | większe lub równe |

Uwaga: `==` porównuje wartości, a `=` przypisuje wartość.

```cpp
if (a == 5) // porównanie
{
    std::cout << "a jest rowne 5" << std::endl;
}

a = 5; // przypisanie
```

## Przykład kodu: `if` i `else`

```cpp
#include <iostream>

int main()
{
    int liczba;

    std::cout << "Podaj liczbe: ";
    std::cin >> liczba;

    if (liczba >= 0)
    {
        std::cout << "Liczba jest nieujemna" << std::endl;
    }
    else
    {
        std::cout << "Liczba jest ujemna" << std::endl;
    }

    return 0;
}
```

Ten przykład znajduje się w pliku [examples/if_positive_negative.cpp](examples/if_positive_negative.cpp).

### `else if`

Jeżeli mamy więcej niż dwa przypadki, używamy `else if`.

```cpp
if (liczba > 0)
{
    std::cout << "Liczba jest dodatnia" << std::endl;
}
else if (liczba < 0)
{
    std::cout << "Liczba jest ujemna" << std::endl;
}
else
{
    std::cout << "Liczba jest rowna zero" << std::endl;
}
```

Warunki są sprawdzane od góry do dołu. Wykonuje się pierwszy pasujący blok.

### Operatory logiczne

Warunki można łączyć operatorami logicznymi.

| Operator | Znaczenie | Przykład |
| --- | --- | --- |
| `&&` | i | `wiek >= 18 && wiek < 65` |
| `||` | lub | `liczba < -10 || liczba > 10` |
| `!` | negacja | `!czyAktywny` |

Przykład:

```cpp
if (liczba >= -10 && liczba <= 13)
{
    std::cout << "Liczba jest w przedziale <-10, 13>" << std::endl;
}
```

Pełny przykład znajduje się w pliku [examples/range_check.cpp](examples/range_check.cpp).

## Typowy błąd: średnik po `if`

Nie stawiamy średnika bezpośrednio po warunku `if`.

Niepoprawny kod:

```cpp
if (a == 1);
{
    std::cout << a << std::endl;
}
```

Ten kod się skompiluje, ale blok w nawiasach klamrowych wykona się zawsze. Średnik kończy pustą instrukcję warunkową.

Poprawny kod:

```cpp
if (a == 1)
{
    std::cout << a << std::endl;
}
```

## Zadania do wykonania

1. Napisz program, który sprawdza, czy liczba jest dodatnia, ujemna czy równa zero.
2. Napisz program, który sprawdza, czy liczba jest parzysta.
3. Napisz program, który sprawdza, czy trzy liczby są podane w kolejności rosnącej.
4. Napisz program, który sprawdza, czy liczba należy do przedziału `<-10, 13>`.
5. Napisz program, który sprawdza, czy liczba należy do jednego z przedziałów: `<-10, 13>` albo `<25, 35>`.

## Kryteria zaliczenia

Program powinien:

- używać `if`, `else if` albo `else` tam, gdzie jest to uzasadnione,
- stosować poprawne operatory porównania,
- stosować operatory logiczne dla warunków złożonych,
- kompilować się bez błędów,
- wypisywać czytelną informację dla użytkownika.

## Pytania kontrolne

1. Czym różni się `=` od `==`?
2. Kiedy używamy `else if`?
3. Co oznacza operator `&&`?
4. Co oznacza operator `||`?
5. Dlaczego średnik po `if (warunek);` jest błędem logicznym?
