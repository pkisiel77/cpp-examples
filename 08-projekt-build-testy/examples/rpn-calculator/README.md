# Przykład - kalkulator RPN

Ten katalog pokazuje minimalny projekt wieloplikowy do ćwiczenia
[kalkulator RPN](../../09-cwiczenie-kalkulator-rpn.md).

## Struktura

```text
rpn-calculator/
  include/rpn/calculator.h
  src/calculator.cpp
  src/main.cpp
  tests/rpn_tests.cpp
  build.sh
```

## Build i testy

```sh
sh build.sh
```

Skrypt kompiluje aplikację, kompiluje testy i uruchamia testy automatyczne.

## Zakres przykładu

Przykład obsługuje:

- liczby rzeczywiste,
- liczby ujemne,
- operatory `+`, `-`, `*`, `/`,
- nawiasy,
- priorytet operatorów,
- dzielenie przez zero jako błąd,
- błędy składni, np. brak argumentu albo nieznany znak.

To jest punkt startowy, a nie pełny projekt zaliczeniowy.
