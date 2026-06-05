# 08 - Projekt, build i testy

Ten segment pokazuje, jak przejść od pojedynczego pliku `.cpp` do małego
projektu C++ z podziałem na pliki, prostym buildem, sprawdzaniem składni,
testami i podstawową automatyzacją.

## Cele segmentu

Po zakończeniu segmentu student powinien umieć:

- rozdzielić program na pliki nagłówkowe i źródłowe,
- wyjaśnić rolę preprocesora i dyrektywy `#include`,
- stosować proste zabezpieczenia przed wielokrotnym dołączeniem nagłówka,
- przygotować minimalną strukturę projektu,
- skompilować projekt złożony z kilku plików,
- sprawdzić składnię bez budowania programu,
- uruchomić proste testy funkcji,
- opisać podstawową ideę CI/CD.

## Docelowa kolejność lekcji

1. `01-preprocesor-i-include.md` - preprocesor, `#include`, `#define`, guardy.
2. `02-podzial-na-pliki.md` - pliki `.h` i `.cpp`, interfejs i implementacja.
3. `03-struktura-projektu.md` - katalogi `include`, `src`, `tests`, `build`.
4. `04-kompilacja-i-build.md` - kompilacja wielu plików i prosty build.
5. `05-sprawdzanie-skladni.md` - `-fsyntax-only`, ostrzeżenia i podstawowa analiza.
6. `06-testy.md` - proste testy bez frameworka i organizacja przypadków testowych.
7. `07-ci-cd.md` - czym jest automatyzacja testów i budowania.
8. `08-zadania.md` - zadania podstawowe i projektowe.

## Obecne materiały źródłowe

Materiały w tym katalogu są w trakcie porządkowania. Aktualnie źródłem treści są:

- [preprocesor.md](preprocesor.md)
- [organizacja-projektu.md](organizacja-projektu.md)
- [structure.md](structure.md)
- [check-cpp-syntax.md](check-cpp-syntax.md)
- [testy-ci-cd.md](testy-ci-cd.md)
- [sqlite-macos.md](sqlite-macos.md)

## Format lekcji

Każda docelowa lekcja powinna mieć taki układ:

1. Cel lekcji.
2. Wymagania wstępne.
3. Krótka teoria.
4. Przykład kodu lub komend.
5. Zadania do wykonania.
6. Kryteria zaliczenia.

## Katalogi pomocnicze

- `examples/` - kompilowalne przykłady i małe projekty dla tego segmentu.
- `archive/` - stare wersje plików po wchłonięciu ich treści do nowych lekcji.
