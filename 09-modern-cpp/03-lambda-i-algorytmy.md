# 03 - Lambdy i algorytmy

## Cel lekcji

Celem lekcji jest praktyczne użycie wyrażeń lambda z algorytmami STL. Student
powinien umieć napisać prostą lambdę, przekazać ją jako predykat oraz
zrozumieć, czym jest przechwytywanie zmiennych.

## Wymagania wstępne

Przed rozpoczęciem lekcji warto znać:

- `std::vector`,
- podstawowe algorytmy STL,
- funkcje,
- pętlę zakresową,
- podstawy `auto`.

## Krótka teoria

### Czym jest lambda

Lambda to krótka funkcja zapisana w miejscu użycia.

```cpp
auto isEven = [](int value) {
    return value % 2 == 0;
};
```

Elementy lambdy:

- `[]` - lista przechwytywania,
- `(int value)` - lista parametrów,
- `{ ... }` - ciało funkcji.

Lambdy są szczególnie wygodne z algorytmami STL, bo często potrzebujemy małego
warunku tylko w jednym miejscu.

## Przykład kodu: lambda jako predykat

Predykat to funkcja albo lambda zwracająca `bool`.

```cpp
auto isPositive = [](int value) {
    return value > 0;
};
```

Predykaty pasują do algorytmów takich jak:

- `std::find_if`,
- `std::count_if`,
- `std::copy_if`,
- `std::remove_if`,
- `std::sort`.

## Przykład kodu: sortowanie obiektów

Jeśli sortujemy obiekty lub struktury, trzeba podać kryterium:

```cpp
std::sort(orders.begin(), orders.end(),
          [](const Order& left, const Order& right) {
              return left.total > right.total;
          });
```

Lambda zwraca `true`, jeśli `left` ma znaleźć się przed `right`.

### Przechwytywanie zmiennych

Lambda może używać zmiennych z zewnętrznego zakresu.

Przechwycenie przez wartość:

```cpp
double minimumTotal = 100.0;

auto isLargeOrder = [minimumTotal](const Order& order) {
    return order.total >= minimumTotal;
};
```

Przechwycenie przez wartość oznacza, że lambda dostaje kopię zmiennej.

Przechwycenie przez referencję:

```cpp
int counter = 0;

auto countOrder = [&counter](const Order&) {
    ++counter;
};
```

Przechwytywanie przez referencję trzeba stosować ostrożnie, bo lambda pracuje na
oryginalnej zmiennej.

### Czytelność lambd

Lambda jest dobrym wyborem, gdy:

- warunek jest krótki,
- używamy go tylko w jednym miejscu,
- nazwa algorytmu jasno mówi, co się dzieje.

Jeśli warunek robi się długi, lepiej rozważyć osobną funkcję albo metodę.

## Przykład referencyjny

Przykład znajduje się w pliku
[`examples/lambda_algorithms.cpp`](examples/lambda_algorithms.cpp).

Kompilacja:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic examples/lambda_algorithms.cpp -o lambda_algorithms
./lambda_algorithms
```

## Zadania do wykonania

1. Skompiluj i uruchom przykład.
2. Zmień próg `minimumTotal` i sprawdź wynik filtrowania.
3. Dodaj sortowanie alfabetyczne według nazwy klienta.
4. Dodaj `std::count_if`, które policzy zamówienia opłacone.
5. Zastąp jedną lambdę osobną funkcją i porównaj czytelność obu wersji.

## Kryteria zaliczenia

Student zalicza lekcję, jeśli potrafi:

- napisać prostą lambdę,
- użyć lambdy jako predykatu,
- posortować obiekty według wskazanego pola,
- przechwycić zmienną przez wartość,
- wyjaśnić różnicę między przechwyceniem przez wartość i referencję,
- dobrać lambdę albo osobną funkcję w zależności od czytelności kodu.
