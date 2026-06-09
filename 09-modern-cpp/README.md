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

## Docelowa kolejność lekcji

1. [01-nowosci-modern-cpp.md](01-nowosci-modern-cpp.md) - najważniejsze elementy C++11 i nowszych standardów.
2. [02-auto-nullptr-inicjalizacja.md](02-auto-nullptr-inicjalizacja.md) - `auto`, `nullptr`, inicjalizacja klamrowa.
3. [03-lambda-i-algorytmy.md](03-lambda-i-algorytmy.md) - lambdy w praktycznym użyciu ze STL.
4. [04-enum-class-override-aliasy.md](04-enum-class-override-aliasy.md) - typy silniejsze semantycznie i czytelniejsze API.
5. [05-move-semantics.md](05-move-semantics.md) - podstawy referencji rvalue i przenoszenia.
6. `06-namespaces.md` - przestrzenie nazw i operator zakresu.
7. `07-moduly-i-podzial-kodu.md` - klasyczne pliki kontra moduły C++20.
8. `08-wielowatkowosc.md` - podstawy `std::thread`.
9. `09-zadania.md` - zadania podstawowe i projektowe.

## Obecne materiały źródłowe

Materiały w tym katalogu są w trakcie porządkowania. Aktualnie źródłem treści są:

- [modern-cpp.md](modern-cpp.md)
- [namespaces.md](namespaces.md)
- [moduly.md](moduly.md)
- [moduly-linki.md](moduly-linki.md)
- [modules-ex1-main.cpp](modules-ex1-main.cpp)
- [wielowatkowosc.md](wielowatkowosc.md)
- [main1.cpp](main1.cpp)
- [main2.cpp](main2.cpp)

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
- `archive/` - stare wersje plików po wchłonięciu ich treści do nowych lekcji.
