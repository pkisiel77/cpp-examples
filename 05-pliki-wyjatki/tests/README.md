# Testy segmentu 05

Ten katalog pokazuje, jak testować walidację danych bez zależności od realnych
plików. Zamiast otwierać plik w teście, testujemy małe funkcje odpowiedzialne za:

- parsowanie linii tekstu,
- sprawdzanie zakresu,
- rozpoznawanie pustych albo błędnych danych.

## Uruchomienie

```sh
c++ -std=c++17 -Wall -Wextra -pedantic tests/test_walidacja.cpp -o /tmp/test_walidacja
/tmp/test_walidacja
```

Ten test jest też uruchamiany przez główny skrypt:

```sh
sh ../../tools/check-examples.sh
```

## Wskazówka

Programy pracujące na plikach łatwiej testować, jeśli logika walidacji jest w
osobnych funkcjach. Funkcja, która dostaje `std::string` i zwraca wynik, jest
łatwiejsza do sprawdzenia niż funkcja, która od razu otwiera plik i wypisuje
komunikaty.
