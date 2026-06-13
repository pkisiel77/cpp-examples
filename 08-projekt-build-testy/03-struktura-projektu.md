# 03 - Struktura projektu

## Cel lekcji

Celem lekcji jest uporządkowanie małego projektu C++ w katalogach. Student
powinien rozumieć, gdzie trzymać publiczne nagłówki, implementacje, testy oraz
pliki wynikowe budowania.

## Wymagania wstępne

Przed rozpoczęciem lekcji warto znać:

- podział programu na pliki `.h` i `.cpp`,
- kompilację programu złożonego z kilku plików,
- podstawową rolę plików nagłówkowych.

## Krótka teoria

### Dlaczego struktura katalogów ma znaczenie

Gdy projekt ma kilka plików, płaski katalog szybko staje się nieczytelny.
Ustalona struktura pomaga:

- znaleźć interfejs modułu,
- oddzielić kod aplikacji od testów,
- nie mieszać kodu źródłowego z plikami wynikowymi,
- łatwiej przejść później do CMake albo innego narzędzia build.

## Przykład struktury projektu

Na tym etapie wystarczy taki układ:

```text
project-name/
  include/
    project_name/
      public_header.h
  src/
    main.cpp
    implementation.cpp
  tests/
    test_something.cpp
  build/
```

Znaczenie katalogów:

- `include/` - nagłówki używane przez inne części projektu,
- `src/` - implementacja programu,
- `tests/` - programy testujące,
- `build/` - pliki wygenerowane podczas kompilacji.

### Katalog `include`

W `include` trzymamy nagłówki publiczne. Dobrą praktyką jest dodanie katalogu z
nazwą projektu:

```text
include/task_counter/counter.h
```

Dzięki temu w kodzie można pisać:

```cpp
#include "task_counter/counter.h"
```

Taki zapis zmniejsza ryzyko konfliktu nazw z innymi projektami.

### Katalog `src`

W `src` trzymamy pliki `.cpp` z implementacją:

```text
src/counter.cpp
src/main.cpp
```

Plik `main.cpp` jest punktem startowym aplikacji. Pozostałe pliki `.cpp`
zawierają funkcje i klasy używane przez aplikację.

### Katalog `tests`

W `tests` można umieścić osobne programy testujące. Na tym etapie nie trzeba
jeszcze używać frameworka testowego.

Przykład:

```text
tests/counter_tests.cpp
```

Taki plik może kompilować się jako osobny program i zwracać `0`, jeśli testy
przechodzą.

### Katalog `build`

`build` służy na pliki wynikowe:

- programy wykonywalne,
- pliki obiektowe,
- pliki wygenerowane przez narzędzia build.

Zwykle nie commitujemy zawartości `build/`. W repozytorium można zostawić pusty
plik `.gitkeep`, jeśli chcemy pokazać, że katalog ma istnieć.

## Przykład referencyjny

Przykład znajduje się w katalogu
[`examples/project-layout`](examples/project-layout).

Struktura:

```text
examples/project-layout/
  include/task_counter/counter.h
  src/counter.cpp
  src/main.cpp
  tests/counter_tests.cpp
  build/.gitkeep
```

Kompilacja aplikacji:

```sh
c++ -std=c++17 \
  -I examples/project-layout/include \
  examples/project-layout/src/main.cpp \
  examples/project-layout/src/counter.cpp \
  -o examples/project-layout/build/task_counter_app
```

Uruchomienie aplikacji:

```sh
./examples/project-layout/build/task_counter_app
```

Kompilacja testów:

```sh
c++ -std=c++17 \
  -I examples/project-layout/include \
  examples/project-layout/tests/counter_tests.cpp \
  examples/project-layout/src/counter.cpp \
  -o examples/project-layout/build/counter_tests
```

Uruchomienie testów:

```sh
./examples/project-layout/build/counter_tests
```

## Przykład komendy: flaga `-I`

Flaga `-I` mówi kompilatorowi, gdzie szukać własnych nagłówków:

```sh
-I examples/project-layout/include
```

Bez tej flagi kompilator może nie znaleźć pliku:

```cpp
#include "task_counter/counter.h"
```

## Zadania do wykonania

1. Skompiluj i uruchom aplikację z `examples/project-layout`.
2. Skompiluj i uruchom testy.
3. Dodaj do klasy `Counter` metodę `reset`.
4. Dopisz test sprawdzający metodę `reset`.
5. Dodaj drugi moduł `report`, który tworzy tekstowy opis stanu licznika.

## Kryteria zaliczenia

Student zalicza lekcję, jeśli potrafi:

- wyjaśnić rolę katalogów `include`, `src`, `tests` i `build`,
- użyć flagi `-I`,
- skompilować aplikację z kodem w kilku katalogach,
- skompilować osobny program testujący,
- nie umieszczać plików wynikowych w kodzie źródłowym.
