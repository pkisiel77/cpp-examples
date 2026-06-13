# 03 - Funkcje, tablice, napisy

Ten segment uczy dzielenia programu na funkcje oraz pracy z prostymi kolekcjami danych: tablicami i napisami.

## Cele segmentu

Po zakończeniu segmentu student powinien umieć:

- deklarować i definiować własne funkcje,
- przekazywać argumenty do funkcji,
- zwracać wynik z funkcji,
- rozumieć różnicę między deklaracją a definicją funkcji,
- używać tablic jednowymiarowych i dwuwymiarowych,
- iterować po elementach tablicy,
- wykonywać podstawowe operacje na `std::string`,
- dzielić większe zadanie na mniejsze części.

## Docelowa kolejność lekcji

1. [01-funkcje-podstawy.md](01-funkcje-podstawy.md) - deklaracja, definicja, wywołanie, wartość zwracana.
2. [02-parametry-i-zakres.md](02-parametry-i-zakres.md) - parametry funkcji, zmienne lokalne, proste przypadki przekazywania danych.
3. [03-tablice.md](03-tablice.md) - tablice jednowymiarowe, indeksy, pętle.
4. [04-tablice-dwuwymiarowe.md](04-tablice-dwuwymiarowe.md) - macierze i proste operacje na siatkach danych.
5. [05-napisy.md](05-napisy.md) - `std::string`, długość, znaki, proste przetwarzanie tekstu.
6. [06-zadania.md](06-zadania.md) - zadania podstawowe i dodatkowe.

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

Katalog [examples](examples) zawiera krótkie programy pokazujące funkcje,
parametry, tablice jedno- i dwuwymiarowe oraz podstawowe operacje na napisach.
Przykłady są kompilowalne i mogą być punktem startowym do zadań.

## Testy

Katalog [tests](tests) zawiera prosty przykład testu automatycznego bez
zewnętrznego frameworka. Test pokazuje, jak sprawdzać funkcje zwracające wynik
i jak zwracać kod błędu, gdy przypadek testowy nie przechodzi.

## Katalogi pomocnicze

- `examples/` - kompilowalne przykłady `.cpp` dla tego segmentu.
- `tests/` - proste testy automatyczne dla funkcji.
- `archive/` - stare wersje plików po wchłonięciu ich treści do nowych lekcji.
