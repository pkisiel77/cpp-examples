# Testy - 02 Sterowanie i pętle

Ten katalog zawiera małe testy automatyczne do segmentu o instrukcjach
warunkowych i pętlach. Testy są pisane bez zewnętrznego frameworka, aby były
łatwe do uruchomienia i przeanalizowania przez studentów.

## Uruchomienie

Z katalogu głównego repozytorium:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic \
    02-sterowanie-i-petle/tests/test_sterowanie_petle.cpp \
    -o /tmp/test_sterowanie_petle

/tmp/test_sterowanie_petle
```

Można też uruchomić pełny zestaw kontroli:

```sh
sh tools/check-examples.sh
```

## Zakres testu

- warunki logiczne i przedziały,
- wybór opcji przez `switch`,
- sumowanie wartości w pętli `for`,
- zliczanie przez pętlę `while`,
- wyszukiwanie z użyciem `break`,
- pomijanie wartości z użyciem `continue`.
