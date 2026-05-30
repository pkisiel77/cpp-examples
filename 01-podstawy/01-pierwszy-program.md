# 01 - Pierwszy program

## Cel lekcji

Celem lekcji jest zrozumienie, czym jest program w C++, gdzie zaczyna się jego wykonanie i jak uruchomić najprostszy kod w konsoli.

## Wymagania wstępne

Student powinien mieć przygotowane środowisko z segmentu [00-start](../00-start/README.md): edytor, kompilator i dostęp do terminala.

## Pojęcia

**Algorytm** to opis kolejnych kroków prowadzących do rozwiązania problemu.

**Program** to algorytm zapisany w języku programowania tak, aby komputer mógł go wykonać.

**Kod źródłowy** to tekst programu zapisany przez programistę, na przykład w pliku `.cpp`.

**Kompilator** tłumaczy kod źródłowy C++ na program wykonywalny.

## Funkcja `main`

W typowym programie konsolowym C++ wykonanie zaczyna się od funkcji `main`.

```cpp
int main()
{
    return 0;
}
```

Znaczenie elementów:

- `int` oznacza, że funkcja zwraca liczbę całkowitą,
- `main` to nazwa funkcji startowej programu,
- `{ ... }` wyznacza ciało funkcji,
- `return 0;` oznacza poprawne zakończenie programu.

## Pierwszy przykład

```cpp
#include <iostream>

int main()
{
    std::cout << "Witaj w C++!" << std::endl;
    return 0;
}
```

Program korzysta z biblioteki `iostream`, aby wypisać tekst na ekran.

- `#include <iostream>` dołącza obsługę wejścia i wyjścia.
- `std::cout` wypisuje dane na standardowe wyjście.
- `std::endl` kończy linię.
- Średnik `;` kończy instrukcję.

Ten sam przykład znajduje się w pliku [examples/hello.cpp](examples/hello.cpp).

## Kompilacja i uruchomienie

Dla kompilatora `g++`:

```sh
g++ examples/hello.cpp -o hello
./hello
```

Dla kompilatora `clang++`:

```sh
clang++ examples/hello.cpp -o hello
./hello
```

Oczekiwany wynik:

```text
Witaj w C++!
```

## Komentarze

Komentarze służą do opisywania kodu. Kompilator je pomija.

```cpp
// Komentarz jednoliniowy

/*
   Komentarz
   wieloliniowy
*/
```

Komentarzy używamy do wyjaśnienia decyzji albo trudniejszego fragmentu kodu. Nie trzeba komentować każdej oczywistej instrukcji.

## Zadania

1. Napisz program, który wypisze Twoje imię.
2. Napisz program, który wypisze nazwę kierunku lub grupy.
3. Zmień przykład tak, aby wypisywał trzy linie tekstu.
4. Dodaj do programu komentarz z krótkim opisem działania.
5. Skompiluj program i uruchom go z terminala.

## Kryteria zaliczenia

Program powinien:

- znajdować się w pliku `.cpp`,
- zawierać funkcję `main`,
- kompilować się bez błędów,
- wypisywać tekst w konsoli,
- kończyć się instrukcją `return 0;`.

## Pytania kontrolne

1. Od której funkcji zaczyna się wykonanie typowego programu C++?
2. Do czego służy `#include <iostream>`?
3. Czym różni się kod źródłowy od programu wykonywalnego?
4. Co oznacza `return 0;` w funkcji `main`?
