# 02 - Podział programu na pliki

## Cel lekcji

Celem lekcji jest rozdzielenie programu C++ na kilka plików. Student powinien
rozumieć różnicę między deklaracją a definicją oraz wiedzieć, dlaczego pliki
nagłówkowe nie powinny zawierać przypadkowych implementacji.

## Wymagania wstępne

Przed rozpoczęciem lekcji warto znać:

- funkcje,
- podstawy kompilacji programu C++,
- dyrektywę `#include`,
- guardy z lekcji [01-preprocesor-i-include.md](01-preprocesor-i-include.md).

## Problem jednego pliku

Małe programy można pisać w jednym pliku `main.cpp`. Gdy kod rośnie, taki plik
staje się trudny do czytania i testowania.

Podział na pliki pozwala:

- oddzielić interfejs od implementacji,
- łatwiej znaleźć odpowiedzialność danego fragmentu kodu,
- ponownie używać funkcji w różnych miejscach programu,
- kompilować większe projekty w bardziej uporządkowany sposób.

## Deklaracja i definicja

Deklaracja mówi kompilatorowi, że dana funkcja istnieje:

```cpp
int add(int a, int b);
```

Definicja zawiera właściwe ciało funkcji:

```cpp
int add(int a, int b) {
    return a + b;
}
```

Deklaracja najczęściej trafia do pliku `.h`, a definicja do pliku `.cpp`.

## Typowy podział

Prosty program może mieć trzy pliki:

```text
calculator.h
calculator.cpp
main.cpp
```

Rola plików:

- `calculator.h` - deklaracje funkcji widoczne dla innych plików,
- `calculator.cpp` - implementacje funkcji,
- `main.cpp` - punkt startowy programu.

## Plik nagłówkowy

Plik `calculator.h` opisuje interfejs:

```cpp
#ifndef CALCULATOR_H
#define CALCULATOR_H

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);

#endif
```

Nagłówek powinien być możliwie mały i czytelny. Osoba korzystająca z modułu
powinna widzieć, co może wywołać, bez czytania szczegółów implementacji.

## Plik implementacji

Plik `calculator.cpp` zawiera definicje funkcji:

```cpp
#include "calculator.h"

int add(int a, int b) {
    return a + b;
}
```

Dołączenie własnego nagłówka w pliku implementacji pomaga sprawdzić, czy
deklaracje i definicje są ze sobą zgodne.

## Plik `main.cpp`

Plik `main.cpp` korzysta z interfejsu:

```cpp
#include <iostream>

#include "calculator.h"

int main() {
    std::cout << add(2, 3) << '\n';
    return 0;
}
```

`main.cpp` nie musi znać szczegółów implementacji funkcji `add`. Wystarczy mu
deklaracja z nagłówka.

## Kompilacja wielu plików

Kompilator musi dostać wszystkie pliki `.cpp`, które zawierają potrzebne
implementacje:

```sh
c++ -std=c++17 main.cpp calculator.cpp -o calculator_app
```

Jeśli podamy tylko `main.cpp`, kompilator zobaczy deklarację funkcji, ale linker
nie znajdzie jej definicji.

## Kompletny przykład

Przykład znajduje się w katalogu
[`examples/split-project`](examples/split-project).

Kompilacja:

```sh
c++ -std=c++17 \
  examples/split-project/main.cpp \
  examples/split-project/calculator.cpp \
  -o split_project
./split_project
```

## Najczęstsze błędy

### Brak pliku `.cpp` w kompilacji

Objawem jest błąd linkera podobny do:

```text
undefined reference to `add(int, int)'
```

Rozwiązanie: dopisz do komendy kompilacji plik `.cpp` z implementacją.

### Implementacja funkcji w nagłówku

W prostych przykładach może działać, ale w większym projekcie łatwo prowadzi do
wielokrotnych definicji. Na tym etapie trzymaj implementacje zwykłych funkcji w
plikach `.cpp`.

### Brak guarda

Nagłówek bez guarda może zostać dołączony więcej niż raz i spowodować błędy
kompilacji.

## Zadania do wykonania

1. Skompiluj i uruchom przykład `examples/split-project`.
2. Dodaj do `calculator.h` deklarację funkcji `divide`.
3. Dodaj implementację `divide` w `calculator.cpp`. Dla dzielenia przez zero
   zwróć `0` i wypisz komunikat w `main.cpp`.
4. Dodaj drugi moduł `text_utils.h` oraz `text_utils.cpp` z funkcją
   `repeat(std::string text, int count)`.
5. Skompiluj program z trzema plikami `.cpp`.

## Kryteria zaliczenia

Student zalicza lekcję, jeśli potrafi:

- wskazać różnicę między deklaracją i definicją,
- utworzyć plik `.h` z guardem,
- utworzyć plik `.cpp` z implementacją,
- dołączyć własny nagłówek w `main.cpp`,
- skompilować program złożony z kilku plików źródłowych,
- rozpoznać błąd linkera wynikający z pominięcia pliku `.cpp`.
