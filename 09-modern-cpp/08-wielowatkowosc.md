# 08 - Wielowątkowość

## Cel lekcji

Celem lekcji jest pierwsze, praktyczne użycie `std::thread`. Student powinien
umieć uruchomić funkcję w osobnym wątku, poczekać na zakończenie przez `join`
oraz rozumieć, dlaczego wspólne dane trzeba chronić.

## Wymagania wstępne

Przed rozpoczęciem lekcji warto znać:

- funkcje,
- lambdy,
- referencje,
- podstawy klas i obiektów,
- kompilację programu C++17.

## Czym jest wątek

Wątek to osobny tor wykonania w ramach jednego programu. Dzięki wątkom program
może wykonywać kilka zadań pozornie równolegle, a na procesorach wielordzeniowych
część pracy może faktycznie wykonywać się równolegle.

Do podstawowej obsługi wątków potrzebny jest nagłówek:

```cpp
#include <thread>
```

## Uruchomienie wątku

Najprostszy przykład:

```cpp
void work() {
    std::cout << "Working\n";
}

std::thread worker{work};
worker.join();
```

`join` oznacza: poczekaj, aż wątek zakończy pracę.

## Dlaczego `join` jest ważny

Jeśli utworzony wątek nie zostanie obsłużony przez `join` albo `detach`, program
zakończy się błędem w czasie działania. Na tym etapie używamy `join`, bo jest
łatwiejszy do zrozumienia i bezpieczniejszy.

## Wspólne dane

Jeśli kilka wątków modyfikuje tę samą zmienną, może dojść do wyścigu danych.
Wynik programu staje się wtedy nieprzewidywalny.

Do ochrony wspólnych danych używamy `std::mutex`:

```cpp
std::mutex mutex;
```

oraz `std::lock_guard`:

```cpp
{
    std::lock_guard<std::mutex> lock{mutex};
    sharedValue += 1;
}
```

`lock_guard` blokuje mutex przy utworzeniu i automatycznie odblokowuje go przy
wyjściu z zakresu.

## Przekazywanie danych do wątku

Do wątku można przekazać funkcję, lambdę albo obiekt funkcyjny.

```cpp
std::thread worker{[&counter]() {
    counter.add(10);
}};
```

Jeśli lambda przechwytuje referencje, trzeba pilnować, aby obiekty istniały tak
długo, jak działa wątek.

## Kompletny przykład

Przykład znajduje się w pliku
[`examples/thread_basics.cpp`](examples/thread_basics.cpp).

Kompilacja:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic examples/thread_basics.cpp -o thread_basics
./thread_basics
```

Na niektórych systemach Linux może być potrzebna flaga:

```sh
-pthread
```

## Zadania do wykonania

1. Skompiluj i uruchom przykład.
2. Zmień liczbę iteracji w każdym wątku.
3. Dodaj trzeci wątek pracujący na tym samym liczniku.
4. Usuń tymczasowo `lock_guard` i zaobserwuj, dlaczego wynik może być
   niepewny. Następnie przywróć ochronę.
5. Jako zadanie rozszerzające zaprojektuj szkic rozwiązania problemu pięciu
   filozofów z użyciem `std::thread` i `std::mutex`.

## Kryteria zaliczenia

Student zalicza lekcję, jeśli potrafi:

- utworzyć `std::thread`,
- wywołać `join`,
- wyjaśnić, czym jest wyścig danych,
- użyć `std::mutex`,
- użyć `std::lock_guard`,
- ostrożnie przekazać dane do lambdy uruchamianej w wątku.
