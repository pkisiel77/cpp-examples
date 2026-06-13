# 05 - Napisy `std::string`

## Cel lekcji

Celem lekcji jest poznanie podstaw pracy z napisami w C++ przy pomocy typu `std::string`.

## Wymagania wstępne

Student powinien znać:

- wejście i wyjście z segmentu [01-podstawy](../01-podstawy/02-wejscie-wyjscie.md),
- pętle z segmentu [02-sterowanie-i-petle](../02-sterowanie-i-petle/README.md),
- funkcje z lekcji [01-funkcje-podstawy.md](01-funkcje-podstawy.md).

## Krótka teoria

### Typ `std::string`

`std::string` służy do przechowywania tekstu.

```cpp
#include <string>

std::string imie = "Ala";
```

Do wypisywania i wczytywania `std::string` używamy `std::cout`, `std::cin` oraz `std::getline`.

### `std::cin` i `std::getline`

`std::cin >> tekst` wczytuje tekst do pierwszej spacji.

```cpp
std::string imie;
std::cin >> imie;
```

`std::getline` wczytuje całą linię.

```cpp
std::string imieINazwisko;
std::getline(std::cin, imieINazwisko);
```

Pełny przykład znajduje się w pliku [examples/string_input.cpp](examples/string_input.cpp).

### Długość napisu

Długość napisu można sprawdzić metodą `.length()` albo `.size()`.

```cpp
std::string tekst = "program";

std::cout << tekst.length() << std::endl; // 7
std::cout << tekst.size() << std::endl;   // 7
```

W prostych programach można używać obu form.

### Indeksowanie znaków

Znaki w napisie są indeksowane od `0`, podobnie jak elementy tablicy.

```cpp
std::string tekst = "kot";

std::cout << tekst[0] << std::endl; // k
std::cout << tekst[1] << std::endl; // o
std::cout << tekst[2] << std::endl; // t
```

Dla napisu o długości `3` poprawne indeksy to `0`, `1`, `2`.

Pełny przykład znajduje się w pliku [examples/string_chars.cpp](examples/string_chars.cpp).

## Przykład kodu: iteracja po znakach

Możemy przechodzić po znakach napisu pętlą `for`.

```cpp
std::string tekst = "program";

for (int i = 0; i < tekst.length(); i++)
{
    std::cout << tekst[i] << std::endl;
}
```

Możemy też użyć pętli zakresowej:

```cpp
for (char znak : tekst)
{
    std::cout << znak << std::endl;
}
```

### Łączenie napisów

Napisy można łączyć operatorem `+`.

```cpp
std::string imie = "Ala";
std::string komunikat = "Czesc, " + imie + "!";
```

## Przykład kodu: proste sprawdzanie palindromu

Palindrom to tekst, który czytany od lewej i od prawej strony jest taki sam.

Przykłady:

- `kajak`,
- `oko`,
- `level`.

Funkcja sprawdzająca palindrom:

```cpp
bool czyPalindrom(std::string tekst)
{
    int left = 0;
    int right = tekst.length() - 1;

    while (left < right)
    {
        if (tekst[left] != tekst[right])
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}
```

Pełny przykład znajduje się w pliku [examples/string_palindrome.cpp](examples/string_palindrome.cpp).

## Uwaga o polskich znakach

Na tym etapie zakładamy, że tekst składa się z prostych znaków ASCII, np. `a-z`, `A-Z`, `0-9`.

Polskie znaki, takie jak `ą`, `ę`, `ł`, wymagają dodatkowej wiedzy o kodowaniu tekstu i nie są częścią tej lekcji.

## Zadania do wykonania

1. Napisz program, który wczytuje imię i wypisuje liczbę znaków.
2. Napisz program, który wczytuje całe imię i nazwisko przy pomocy `std::getline`.
3. Napisz program, który wypisuje każdy znak napisu w osobnej linii.
4. Napisz funkcję `pierwszyZnak`, która zwraca pierwszy znak napisu.
5. Napisz funkcję `czyPalindrom`, która sprawdza, czy napis jest palindromem.
6. Napisz program, który zlicza, ile razy litera `a` występuje w napisie.

## Ćwiczenia dodatkowe

1. Dodaj zliczanie spacji w napisie.
2. Zmień program tak, aby ignorował wielkość liter przy porównaniu.
3. Dodaj funkcję sprawdzającą, czy napis zaczyna się od podanego znaku.

## Kryteria zaliczenia

Program powinien:

- dołączać bibliotekę `string`,
- poprawnie używać `std::string`,
- rozróżniać `std::cin >> tekst` i `std::getline`,
- nie wychodzić poza zakres napisu,
- kompilować się bez błędów.

## Pytania kontrolne

1. Do czego służy `std::string`?
2. Czym różni się `std::cin >> tekst` od `std::getline`?
3. Od jakiego indeksu zaczynają się znaki w napisie?
4. Co zwraca metoda `.length()`?
5. Czym jest palindrom?
