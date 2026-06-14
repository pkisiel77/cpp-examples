# 02 - Sterowanie i pętle

Ten segment uczy sterowania przepływem programu: podejmowania decyzji, powtarzania instrukcji i zapisu prostych algorytmów.

## Cele segmentu

Po zakończeniu segmentu student powinien umieć:

- używać instrukcji `if`, `else if` i `else`,
- używać instrukcji `switch`,
- rozumieć operatory porównania i operatory logiczne,
- używać operatora warunkowego `?:`,
- pisać pętle `for`, `while` i `do while`,
- dobrać rodzaj pętli do problemu,
- używać `break` i `continue` w prostych przypadkach,
- rozwiązywać zadania wymagające warunków i powtórzeń.

## Docelowa kolejność lekcji

1. [01-instrukcje-warunkowe.md](01-instrukcje-warunkowe.md) - `if`, `else`, porównania, operatory logiczne.
2. [02-switch-i-operator-warunkowy.md](02-switch-i-operator-warunkowy.md) - `switch` oraz `?:`.
3. [03-petla-for.md](03-petla-for.md) - klasyczna pętla `for` i typowe schematy iteracji.
4. [04-petle-while-do-while.md](04-petle-while-do-while.md) - pętle zależne od warunku.
5. [05-break-continue-i-zagniezdzenia.md](05-break-continue-i-zagniezdzenia.md) - sterowanie wewnątrz pętli i pętle zagnieżdżone.
6. [06-zadania.md](06-zadania.md) - zadania podstawowe i dodatkowe.
7. [07-cwiczenie-min-max-srednia.md](07-cwiczenie-min-max-srednia.md) - większe ćwiczenie z pętli, walidacji i wyniku częściowego.

## Status porządkowania

Lekcje i zadania w tym segmencie są uporządkowane w docelowym formacie.
Materiały źródłowe zostały przeniesione do [archive](archive) po wchłonięciu
ich treści do lekcji i zadań.

## Format lekcji

Każda docelowa lekcja powinna mieć taki układ:

1. Cel lekcji.
2. Wymagania wstępne.
3. Krótka teoria.
4. Przykład kodu.
5. Zadania do wykonania.
6. Kryteria zaliczenia.

## Przykłady kodu

Katalog [examples](examples) zawiera krótkie programy pokazujące instrukcje
warunkowe, `switch`, pętle oraz użycie `break` i `continue`. Przykłady są
kompilowalne i mogą być punktem startowym do zadań.

Do większego ćwiczenia z minimum, maksimum i średnią przydatny jest przykład
[examples/while_min_max_average.cpp](examples/while_min_max_average.cpp).

## Testy

Katalog [tests](tests) zawiera prosty test bez zewnętrznego frameworka. Test
sprawdza warunki logiczne, `switch`, sumowanie w pętli `for`, pracę pętli
`while`, przerwanie pętli przez `break` oraz pomijanie elementów przez
`continue`.

## Katalogi pomocnicze

- `examples/` - kompilowalne przykłady `.cpp` dla tego segmentu.
- `tests/` - proste testy automatyczne dla sterowania przepływem programu.
- `archive/` - stare wersje plików po wchłonięciu ich treści do nowych lekcji.
