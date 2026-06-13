# 09 - Modern C++

Ten segment zbiera elementy współczesnego C++, które rozszerzają kurs
podstawowy. Materiał pokazuje najważniejsze konstrukcje C++11 i nowszych
standardów oraz tematy, które warto potraktować jako wprowadzenie do dalszej
nauki.

## Cele segmentu

Po zakończeniu segmentu student powinien umieć:

- rozpoznać wybrane elementy modern C++,
- używać `auto`, `nullptr`, inicjalizacji klamrowej i pętli zakresowej,
- stosować `enum class`, aliasy typów i `override`,
- używać prostych wyrażeń lambda,
- rozumieć podstawy semantyki przenoszenia,
- organizować nazwy za pomocą przestrzeni nazw,
- wyjaśnić, czym różni się moduł jako temat C++20 od klasycznego podziału na pliki,
- uruchomić prosty przykład z `std::thread`.

## Kolejność lekcji

1. [01-nowosci-modern-cpp.md](01-nowosci-modern-cpp.md) - najważniejsze elementy C++11 i nowszych standardów.
2. [02-auto-nullptr-inicjalizacja.md](02-auto-nullptr-inicjalizacja.md) - `auto`, `nullptr`, inicjalizacja klamrowa.
3. [03-lambda-i-algorytmy.md](03-lambda-i-algorytmy.md) - lambdy w praktycznym użyciu ze STL.
4. [04-enum-class-override-aliasy.md](04-enum-class-override-aliasy.md) - typy silniejsze semantycznie i czytelniejsze API.
5. [05-move-semantics.md](05-move-semantics.md) - podstawy referencji rvalue i przenoszenia.
6. [06-namespaces.md](06-namespaces.md) - przestrzenie nazw i operator zakresu.
7. [07-moduly-i-podzial-kodu.md](07-moduly-i-podzial-kodu.md) - klasyczne pliki kontra moduły C++20.
8. [08-wielowatkowosc.md](08-wielowatkowosc.md) - podstawy `std::thread`.
9. [09-zadania.md](09-zadania.md) - zadania podstawowe i projektowe.

## Status porządkowania

Lekcje i zadania zostały uporządkowane do wspólnego formatu segmentów. Pierwotne materiały są zachowane w katalogu [archive](archive):

- [archive/modern-cpp.md](archive/modern-cpp.md)
- [archive/namespaces.md](archive/namespaces.md)
- [archive/moduly.md](archive/moduly.md)
- [archive/moduly-linki.md](archive/moduly-linki.md)
- [archive/modules-ex1-main.cpp](archive/modules-ex1-main.cpp)
- [archive/wielowatkowosc.md](archive/wielowatkowosc.md)
- [archive/main1.cpp](archive/main1.cpp)
- [archive/main2.cpp](archive/main2.cpp)

## Przykłady kodu

Przykłady w katalogu [examples](examples) można kompilować osobno:

- [examples/modern_cpp_overview.cpp](examples/modern_cpp_overview.cpp) - przegląd wybranych elementów modern C++.
- [examples/auto_nullptr_initialization.cpp](examples/auto_nullptr_initialization.cpp) - `auto`, `nullptr` i inicjalizacja klamrowa.
- [examples/lambda_algorithms.cpp](examples/lambda_algorithms.cpp) - lambdy z algorytmami STL.
- [examples/strong_types_api.cpp](examples/strong_types_api.cpp) - `enum class`, aliasy i `override`.
- [examples/move_semantics.cpp](examples/move_semantics.cpp) - podstawy przenoszenia.
- [examples/namespaces.cpp](examples/namespaces.cpp) - przestrzenie nazw.
- [examples/code-organization](examples/code-organization) - podział kodu na moduł logiczny.
- [examples/thread_basics.cpp](examples/thread_basics.cpp) - podstawy `std::thread`.

## Testy

Katalog [tests](tests) zawiera prosty test wybranych elementów modern C++ bez
zewnętrznego frameworka. Test sprawdza pętlę zakresową z `auto`, `nullptr`,
`enum class`, aliasy typów, lambdy z algorytmami STL oraz przenoszenie danych.

## Format lekcji

Każda docelowa lekcja powinna mieć taki układ:

1. Cel lekcji.
2. Wymagania wstępne.
3. Krótka teoria.
4. Przykład kodu lub komend.
5. Zadania do wykonania.
6. Kryteria zaliczenia.

## Katalogi pomocnicze

- `examples/` - kompilowalne przykłady `.cpp` dla tego segmentu.
- `tests/` - proste testy automatyczne dla elementów modern C++.
- `archive/` - pierwotne wersje materiałów zachowane do wglądu.
