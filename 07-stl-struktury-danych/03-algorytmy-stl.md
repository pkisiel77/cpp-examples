# 03 - Algorytmy STL

## Cel lekcji

Celem lekcji jest poznanie podstawowych algorytmów STL: `std::sort`, `std::find_if`, `std::copy_if` i `std::remove_if`, oraz zrozumienie prostych predykatów i lambd.

## Wymagania wstępne

Student powinien znać:

- podstawy STL z lekcji [01-wprowadzenie-do-stl.md](01-wprowadzenie-do-stl.md),
- `std::vector` z lekcji [02-vector.md](02-vector.md),
- funkcje z segmentu [03-funkcje-tablice-napisy](../03-funkcje-tablice-napisy/README.md).

## Krótka teoria

### Nagłówek `<algorithm>`

Do wielu algorytmów STL potrzebny jest nagłówek:

```cpp
#include <algorithm>
```

Algorytmy działają na zakresie elementów. Zakres zwykle zapisujemy przez `begin()` i `end()`.

```cpp
std::sort(liczby.begin(), liczby.end());
```

## Przykład kodu: `std::sort`

`std::sort` sortuje elementy w kontenerze.

```cpp
std::vector<int> liczby = {5, 1, 4, 2, 3};
std::sort(liczby.begin(), liczby.end());
```

Po sortowaniu wektor będzie miał wartości:

```text
1 2 3 4 5
```

Pełny przykład znajduje się w pliku [examples/sort_numbers.cpp](examples/sort_numbers.cpp).

### Sortowanie malejące

Do sortowania malejącego można przekazać predykat.

```cpp
std::sort(liczby.begin(), liczby.end(), [](int a, int b)
{
    return a > b;
});
```

Predykat mówi, który element powinien być wcześniej.

### Lambda

Lambda to krótka funkcja zapisana w miejscu użycia.

```cpp
[](int a, int b)
{
    return a > b;
}
```

W tym przykładzie lambda przyjmuje dwie liczby i zwraca `true`, jeśli pierwsza ma być przed drugą.

## Przykład kodu: `std::find_if`

`std::find_if` szuka pierwszego elementu spełniającego warunek.

```cpp
auto wynik = std::find_if(liczby.begin(), liczby.end(), [](int liczba)
{
    return liczba > 10;
});
```

Po wywołaniu trzeba sprawdzić, czy coś znaleziono.

```cpp
if (wynik != liczby.end())
{
    std::cout << "Znaleziono: " << *wynik << std::endl;
}
```

## Przykład kodu: `std::copy_if`

`std::copy_if` kopiuje do nowego kontenera tylko elementy spełniające warunek.

```cpp
std::vector<int> dodatnie;

std::copy_if(liczby.begin(), liczby.end(), std::back_inserter(dodatnie), [](int liczba)
{
    return liczba > 0;
});
```

Do `std::back_inserter` potrzebny jest nagłówek:

```cpp
#include <iterator>
```

### `std::remove_if` i `erase`

`std::remove_if` samo nie zmniejsza rozmiaru wektora. Przesuwa elementy, które mają zostać zachowane.

Dla `std::vector` używamy wzorca erase-remove:

```cpp
liczby.erase(
    std::remove_if(liczby.begin(), liczby.end(), [](int liczba)
    {
        return liczba < 0;
    }),
    liczby.end()
);
```

Ten kod usuwa liczby ujemne.

Pełny przykład znajduje się w pliku [examples/filter_people.cpp](examples/filter_people.cpp).

### Predykat

Predykat to funkcja albo lambda zwracająca `bool`.

Przykłady predykatów:

```cpp
[](int liczba) { return liczba > 0; }
[](const Osoba& osoba) { return osoba.wiek >= 18; }
[](const Produkt& produkt) { return produkt.cena < 100; }
```

Predykaty są używane w algorytmach takich jak `find_if`, `copy_if` i `remove_if`.

## Typowe błędy

### Brak sprawdzenia wyniku `find_if`

Niepoprawnie:

```cpp
auto wynik = std::find_if(liczby.begin(), liczby.end(), warunek);
std::cout << *wynik << std::endl;
```

Poprawnie:

```cpp
if (wynik != liczby.end())
{
    std::cout << *wynik << std::endl;
}
```

### Samo `remove_if` bez `erase`

`remove_if` nie usuwa fizycznie elementów z wektora. Do usunięcia potrzebne jest `erase`.

### Sortowanie obiektów bez kryterium

Jeśli sortujesz obiekty własnej klasy lub struktury, musisz powiedzieć, według czego sortować.

```cpp
std::sort(osoby.begin(), osoby.end(), [](const Osoba& a, const Osoba& b)
{
    return a.wiek < b.wiek;
});
```

## Zadania do wykonania

1. Utwórz wektor liczb i posortuj go rosnąco.
2. Posortuj ten sam wektor malejąco przy pomocy lambdy.
3. Znajdź pierwszą liczbę większą od `50` przy pomocy `std::find_if`.
4. Skopiuj do nowego wektora tylko liczby parzyste przy pomocy `std::copy_if`.
5. Usuń z wektora wszystkie liczby ujemne przy pomocy wzorca erase-remove.

## Kryteria zaliczenia

Program powinien:

- dołączać nagłówek `<algorithm>`,
- używać `begin()` i `end()`,
- poprawnie używać `std::sort`,
- sprawdzać wynik `std::find_if`,
- używać lambdy jako predykatu,
- poprawnie stosować `remove_if` razem z `erase`,
- kompilować się bez błędów.

## Pytania kontrolne

1. Do czego służy `std::sort`?
2. Czym jest predykat?
3. Co zwraca `std::find_if`, gdy nic nie znajdzie?
4. Dlaczego `remove_if` trzeba połączyć z `erase`?
5. Po co używamy lambd w algorytmach STL?
