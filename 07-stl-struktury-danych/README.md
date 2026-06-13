# 07 - STL i struktury danych

Ten segment pokazuje standardowe kontenery C++ i ich praktyczne zastosowania. Materiał przechodzi od `std::vector` do kontenerów asocjacyjnych, adapterów takich jak `std::stack` i `std::queue`, podstaw algorytmów STL oraz większego zadania projektowego.

## Cele segmentu

Po zakończeniu segmentu student powinien umieć:

- dobrać kontener do prostego problemu,
- używać `std::vector` do przechowywania listy danych,
- przechodzić po kontenerach pętlą zakresową,
- dodawać, usuwać i wyszukiwać elementy w kontenerze,
- używać `std::map` do par klucz-wartość,
- używać `std::stack` i `std::queue`,
- zastosować podstawowe algorytmy STL, np. `std::sort` i `std::find_if`,
- połączyć kontenery z klasami w małym programie.

## Kolejność lekcji

1. [01-wprowadzenie-do-stl.md](01-wprowadzenie-do-stl.md) - po co są kontenery i kiedy ich używać.
2. [02-vector.md](02-vector.md) - `std::vector`, dodawanie, usuwanie, iteracja.
3. [03-algorytmy-stl.md](03-algorytmy-stl.md) - `std::sort`, `std::find_if`, predykaty i lambdy.
4. [04-map-i-slownik.md](04-map-i-slownik.md) - `std::map`, klucze, wartości i wyszukiwanie.
5. [05-stack-queue-list.md](05-stack-queue-list.md) - stos, kolejka i lista.
6. [06-projekt-hrms.md](06-projekt-hrms.md) - mini-projekt z kilkoma kontenerami.
7. [07-zadania.md](07-zadania.md) - zadania podstawowe i projektowe.

## Status porządkowania

Lekcje i zadania zostały uporządkowane do wspólnego formatu segmentów. Pierwotne materiały są zachowane w katalogu [archive](archive):

- [archive/kontenery-stl.md](archive/kontenery-stl.md)
- [archive/vector.md](archive/vector.md)
- [archive/vector-zadania.md](archive/vector-zadania.md)
- [archive/vector-part2.md](archive/vector-part2.md)
- [archive/map-zadania.md](archive/map-zadania.md)
- [archive/kolejka-linki.md](archive/kolejka-linki.md)
- [archive/console.md](archive/console.md)
- [archive/converter_v1.cpp](archive/converter_v1.cpp)
- [archive/egzamin-tablice.md](archive/egzamin-tablice.md)
- [archive/powtorzenie-zadania.md](archive/powtorzenie-zadania.md)
- [archive/powtorzenie-part2.md](archive/powtorzenie-part2.md)

## Przykłady kodu

Przykłady w katalogu [examples](examples) można kompilować osobno:

- [examples/stl_containers_overview.cpp](examples/stl_containers_overview.cpp) - przegląd kontenerów STL.
- [examples/choose_container.cpp](examples/choose_container.cpp) - dobór kontenera do problemu.
- [examples/vector_basics.cpp](examples/vector_basics.cpp) - podstawy `std::vector`.
- [examples/vector_records.cpp](examples/vector_records.cpp) - wektor rekordów.
- [examples/sort_numbers.cpp](examples/sort_numbers.cpp) - sortowanie liczb.
- [examples/filter_people.cpp](examples/filter_people.cpp) - filtrowanie danych.
- [examples/map_basics.cpp](examples/map_basics.cpp) - podstawy `std::map`.
- [examples/movie_library.cpp](examples/movie_library.cpp) - słownik filmów.
- [examples/stack_queue.cpp](examples/stack_queue.cpp) - stos i kolejka.
- [examples/list_operations.cpp](examples/list_operations.cpp) - operacje na liście.
- [examples/hrms.cpp](examples/hrms.cpp) - przykład projektu HRMS.

## Format lekcji

Każda docelowa lekcja powinna mieć taki układ:

1. Cel lekcji.
2. Wymagania wstępne.
3. Krótka teoria.
4. Przykład kodu.
5. Zadania do wykonania.
6. Kryteria zaliczenia.

## Katalogi pomocnicze

- `examples/` - kompilowalne przykłady `.cpp` dla tego segmentu.
- `archive/` - pierwotne wersje materiałów zachowane do wglądu.
