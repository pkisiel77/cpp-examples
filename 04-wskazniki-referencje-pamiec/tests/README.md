# Testy - 04 Wskaźniki, referencje, pamięć

Ten katalog zawiera małe testy automatyczne do segmentu o wskaźnikach i
referencjach. Testy są pisane bez zewnętrznego frameworka, aby student mógł
łatwo prześledzić cały kod.

## Uruchomienie

Z katalogu głównego repozytorium:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic \
    04-wskazniki-referencje-pamiec/tests/test_wskazniki_referencje.cpp \
    -o /tmp/test_wskazniki_referencje

/tmp/test_wskazniki_referencje
```

Można też uruchomić pełny zestaw kontroli:

```sh
sh tools/check-examples.sh
```

## Zakres testu

- zamiana wartości przez referencje,
- bezpieczne odczytywanie wartości przez wskaźnik,
- obsługa `nullptr`,
- suma elementów tablicy przekazanej jako wskaźnik,
- zwracanie kilku wyników przez parametry referencyjne.
