# 01 - Preprocesor i `#include`

## Cel lekcji

Celem lekcji jest zrozumienie, co dzieje się z plikiem C++ przed właściwą
kompilacją. Student powinien umieć używać `#include`, prostych makr,
kompilacji warunkowej oraz zabezpieczeń przed wielokrotnym dołączeniem pliku
nagłówkowego.

## Wymagania wstępne

Przed rozpoczęciem lekcji warto znać:

- podstawową strukturę programu C++,
- funkcje,
- pliki nagłówkowe z biblioteki standardowej, np. `<iostream>`,
- kompilację pojedynczego pliku `.cpp`.

## Czym jest preprocesor

Preprocesor działa przed kompilatorem. Przetwarza dyrektywy zaczynające się od
znaku `#`, a dopiero wynik tego przetwarzania trafia do właściwej kompilacji.

Najczęściej spotykane dyrektywy to:

- `#include` - dołącza treść innego pliku,
- `#define` - definiuje makro,
- `#ifdef`, `#ifndef`, `#if` - włącza lub wyłącza fragmenty kodu,
- `#endif` - kończy blok kompilacji warunkowej.

## `#include`

Dyrektywa `#include` dołącza zawartość pliku do aktualnego pliku źródłowego.

```cpp
#include <iostream>
```

Nagłówki standardowe zapisujemy w nawiasach ostrych:

```cpp
#include <vector>
#include <string>
```

Własne nagłówki zapisujemy w cudzysłowie:

```cpp
#include "calculator.h"
```

## Makra i stałe kompilacyjne

Makro zdefiniowane przez `#define` jest podstawiane tekstowo przed kompilacją:

```cpp
#define MAX_USERS 100
```

W nowym kodzie C++ dla zwykłych stałych częściej używa się `const` albo
`constexpr`:

```cpp
constexpr int maxUsers = 100;
```

Makra nadal są przydatne do kompilacji warunkowej.

## Kompilacja warunkowa

Kompilacja warunkowa pozwala włączyć fragment kodu tylko wtedy, gdy dana flaga
jest zdefiniowana:

```cpp
#ifdef DEBUG_MODE
std::cout << "Debug information\n";
#endif
```

Flagę można zdefiniować w kodzie:

```cpp
#define DEBUG_MODE
```

albo podczas kompilacji:

```sh
c++ -std=c++17 -DDEBUG_MODE examples/preprocessor_info.cpp -o preprocessor_info
```

## Guardy w plikach nagłówkowych

Ten sam nagłówek może zostać dołączony kilka razy przez różne pliki. Guard
chroni przed wielokrotną definicją tych samych elementów.

Przykład:

```cpp
#ifndef CALCULATOR_H
#define CALCULATOR_H

int add(int a, int b);

#endif
```

Alternatywą jest:

```cpp
#pragma once
```

`#pragma once` jest proste i powszechnie obsługiwane, ale klasyczny guard
`#ifndef` / `#define` / `#endif` dobrze pokazuje mechanizm preprocesora.

## Nazwy predefiniowane

Preprocesor udostępnia specjalne nazwy, które pomagają w diagnostyce:

```cpp
__FILE__
__LINE__
__DATE__
__TIME__
```

Nie należy budować logiki programu na dacie kompilacji, ale takie wartości są
przydatne w prostych komunikatach diagnostycznych.

## Kompletny przykład

Przykład znajduje się w pliku
[`examples/preprocessor_info.cpp`](examples/preprocessor_info.cpp).

Kompilacja bez trybu debug:

```sh
c++ -std=c++17 examples/preprocessor_info.cpp -o preprocessor_info
./preprocessor_info
```

Kompilacja z trybem debug:

```sh
c++ -std=c++17 -DDEBUG_MODE examples/preprocessor_info.cpp -o preprocessor_info
./preprocessor_info
```

## Zadania do wykonania

1. Skompiluj przykład bez flagi `DEBUG_MODE` i z flagą `DEBUG_MODE`. Porównaj
   wynik działania programu.
2. Dodaj w przykładzie własną flagę `SHOW_BUILD_INFO`, która wyświetli
   `__DATE__` oraz `__TIME__`.
3. Utwórz plik `math_utils.h` z guardem i deklaracją funkcji `square`.
4. Utwórz plik `math_utils.cpp` z implementacją funkcji `square`.
5. Dołącz `math_utils.h` w `main.cpp` i użyj funkcji `square`.

## Kryteria zaliczenia

Student zalicza lekcję, jeśli potrafi:

- wyjaśnić, że preprocesor działa przed kompilatorem,
- odróżnić nagłówki standardowe od własnych,
- użyć `#include`,
- włączyć fragment kodu za pomocą `#ifdef`,
- zdefiniować flagę kompilacji przez `-D`,
- napisać prosty guard dla pliku nagłówkowego.
