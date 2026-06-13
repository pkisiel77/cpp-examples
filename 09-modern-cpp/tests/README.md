# Testy - 09 Modern C++

Ten katalog zawiera małe testy automatyczne do segmentu modern C++. Testy są
pisane bez zewnętrznego frameworka, aby można je było kompilować tym samym
kompilatorem co przykłady lekcyjne.

## Uruchomienie

Z katalogu głównego repozytorium:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic \
    09-modern-cpp/tests/test_modern_cpp.cpp \
    -o /tmp/test_modern_cpp

/tmp/test_modern_cpp
```

Można też uruchomić pełny zestaw kontroli:

```sh
sh tools/check-examples.sh
```

## Zakres testu

- wyszukiwanie najlepszego elementu z użyciem pętli zakresowej i `nullptr`,
- użycie `enum class` i aliasów typów,
- filtrowanie oraz liczenie elementów z lambdami,
- przenoszenie danych przez konstruktor z `std::move`.
