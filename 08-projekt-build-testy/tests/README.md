# Testy - 08 Projekt, build i testy

Ten katalog zawiera testy automatyczne do segmentu o organizacji projektu,
buildzie i testowaniu. Testy są pisane bez zewnętrznego frameworka, aby były
spójne z lekcją o prostych testach.

## Uruchomienie

Z katalogu głównego repozytorium:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic \
    08-projekt-build-testy/tests/test_split_project_calculator.cpp \
    08-projekt-build-testy/examples/split-project/calculator.cpp \
    -o /tmp/test_split_project_calculator

/tmp/test_split_project_calculator
```

Można też uruchomić pełny zestaw kontroli:

```sh
sh tools/check-examples.sh
```

## Zakres testu

- kompilacja testu razem z osobnym plikiem implementacji,
- testowanie funkcji zadeklarowanych w nagłówku,
- sprawdzenie dodawania, odejmowania i mnożenia,
- czytelny kod zakończenia programu dla skryptu build.
