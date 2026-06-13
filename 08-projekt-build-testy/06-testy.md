# 06 - Proste testy

## Cel lekcji

Celem lekcji jest pokazanie, jak sprawdzać działanie funkcji i klas bez
frameworka testowego. Student powinien umieć napisać osobny program testujący,
uruchomić go po kompilacji i interpretować kod zakończenia programu.

## Wymagania wstępne

Przed rozpoczęciem lekcji warto znać:

- podział programu na pliki,
- strukturę katalogów `src`, `include` i `tests`,
- kompilację programu złożonego z kilku plików,
- podstawowe instrukcje warunkowe.

## Krótka teoria

### Po co pisać testy

Test to program, który sprawdza, czy kod zachowuje się zgodnie z oczekiwaniem.
Najprostszy test:

1. przygotowuje dane,
2. wywołuje funkcję lub metodę,
3. porównuje wynik z oczekiwaniem,
4. zwraca `0`, jeśli wszystko działa,
5. zwraca wartość różną od `0`, jeśli test wykrył błąd.

Dzięki temu test można uruchamiać ręcznie albo w skrypcie build.

## Przykład kodu: test jako osobny program

W przykładzie testy są w pliku:

```text
examples/project-layout/tests/counter_tests.cpp
```

Program testujący korzysta z tej samej klasy `Counter`, co aplikacja:

```cpp
#include "task_counter/counter.h"
```

Nie uruchamia `main.cpp` aplikacji. Ma własną funkcję `main`, która sprawdza
wybrane przypadki.

### Funkcja pomocnicza

Żeby testy były czytelniejsze, można napisać małą funkcję pomocniczą:

```cpp
bool expectEqual(const std::string& name, int actual, int expected) {
    if (actual != expected) {
        std::cout << name << " failed: expected "
                  << expected << ", got " << actual << '\n';
        return false;
    }

    return true;
}
```

Taka funkcja zmniejsza powtarzanie kodu i wypisuje konkretny powód błędu.

### Przypadki testowe

Dobry test sprawdza jeden scenariusz. Przykłady dla klasy `Counter`:

- dodanie zadania zwiększa liczbę otwartych zadań,
- zakończenie zadania zmniejsza liczbę otwartych zadań,
- zakończenie zadania zwiększa liczbę wykonanych zadań,
- próba zakończenia zadania przy pustej liście niczego nie psuje.

Nazwy funkcji testowych powinny opisywać zachowanie:

```cpp
bool testCompletingTask();
bool testCompletingWithoutOpenTasks();
```

### Kod zakończenia programu

Program powinien zwrócić:

- `0`, jeśli testy przeszły,
- `1` albo inną wartość różną od zera, jeśli testy nie przeszły.

Skrypty build i narzędzia CI wykorzystują ten kod, aby przerwać proces po
wykryciu błędu.

## Przykład komendy: kompilacja testów

Testy kompilujemy jako osobny program:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic \
  -I examples/project-layout/include \
  examples/project-layout/tests/counter_tests.cpp \
  examples/project-layout/src/counter.cpp \
  -o examples/project-layout/build/counter_tests
```

Uruchomienie:

```sh
./examples/project-layout/build/counter_tests
```

### Testy w skrypcie build

Skrypt `examples/project-layout/build.sh` kompiluje aplikację, kompiluje testy i
uruchamia testy. Jeśli testy zwrócą błąd, skrypt zakończy działanie z błędem.

Uruchomienie:

```sh
BUILD_DIR=/tmp/task-counter-build sh examples/project-layout/build.sh
```

## Zadania do wykonania

1. Uruchom testy z `examples/project-layout`.
2. Dodaj test sprawdzający, że po utworzeniu `Counter` ma `0` otwartych zadań.
3. Dodaj metodę `reset` do klasy `Counter`.
4. Dopisz test metody `reset`.
5. Celowo zmień implementację `completeTask` tak, aby test się nie powiódł.
   Przeczytaj komunikat błędu i przywróć poprawną implementację.

## Kryteria zaliczenia

Student zalicza lekcję, jeśli potrafi:

- napisać prosty test jako osobny program,
- przygotować dane wejściowe i sprawdzić wynik,
- wypisać czytelny komunikat błędu,
- zwrócić `0` dla sukcesu i `1` dla porażki,
- skompilować test razem z testowanym plikiem `.cpp`,
- uruchomić testy ze skryptu build.
