# Testy - 01 Podstawy C++

Ten katalog zawiera małe testy automatyczne do pierwszego segmentu kursu. Testy
nie używają zewnętrznego frameworka, dzięki czemu student może łatwo zobaczyć,
jak działa prosta kontrola wyniku programu.

## Uruchomienie

Z katalogu głównego repozytorium:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic \
    01-podstawy/tests/test_podstawy.cpp \
    -o /tmp/test_podstawy

/tmp/test_podstawy
```

Można też uruchomić pełny zestaw kontroli:

```sh
sh tools/check-examples.sh
```

## Zakres testu

- proste działania arytmetyczne,
- obliczanie pola prostokąta i BMI,
- klasyfikacja wyniku tekstem,
- formatowanie liczby z ustaloną precyzją,
- podstawowe rozumienie typów wyników.
