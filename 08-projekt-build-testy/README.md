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

## Kolejność lekcji

1. [01-preprocesor-i-include.md](01-preprocesor-i-include.md) - preprocesor, `#include`, `#define`, guardy.
2. [02-podzial-na-pliki.md](02-podzial-na-pliki.md) - pliki `.h` i `.cpp`, interfejs i implementacja.
3. [03-struktura-projektu.md](03-struktura-projektu.md) - katalogi `include`, `src`, `tests`, `build`.
4. [04-kompilacja-i-build.md](04-kompilacja-i-build.md) - kompilacja wielu plików i prosty build.
5. [05-sprawdzanie-skladni.md](05-sprawdzanie-skladni.md) - `-fsyntax-only`, ostrzeżenia i podstawowa analiza.
6. [06-testy.md](06-testy.md) - proste testy bez frameworka i organizacja przypadków testowych.
7. [07-ci-cd.md](07-ci-cd.md) - czym jest automatyzacja testów i budowania.
8. [08-zadania.md](08-zadania.md) - zadania podstawowe i projektowe.

## Status porządkowania

Lekcje i zadania zostały uporządkowane do wspólnego formatu segmentów. Pierwotne materiały są zachowane w katalogu [archive](archive):

- [archive/preprocesor.md](archive/preprocesor.md)
- [archive/organizacja-projektu.md](archive/organizacja-projektu.md)
- [archive/structure.md](archive/structure.md)
- [archive/check-cpp-syntax.md](archive/check-cpp-syntax.md)
- [archive/testy-ci-cd.md](archive/testy-ci-cd.md)
- [archive/sqlite-macos.md](archive/sqlite-macos.md)

## Przykłady kodu i konfiguracji

Przykłady w katalogu [examples](examples) można uruchamiać osobno:

- [examples/preprocessor_info.cpp](examples/preprocessor_info.cpp) - preprocesor i nazwy predefiniowane.
- [examples/split-project](examples/split-project) - podział programu na `.h` i `.cpp`.
- [examples/project-layout](examples/project-layout) - struktura projektu, build i testy.
- [examples/syntax-check/student_report.cpp](examples/syntax-check/student_report.cpp) - plik do sprawdzania składni.
- [examples/ci-cd/github-actions-cpp.yml](examples/ci-cd/github-actions-cpp.yml) - przykładowy workflow CI.

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
- `archive/` - pierwotne wersje materiałów zachowane do wglądu.
