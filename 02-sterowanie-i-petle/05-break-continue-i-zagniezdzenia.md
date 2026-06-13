# 05 - `break`, `continue` i pętle zagnieżdżone

## Cel lekcji

Celem lekcji jest poznanie sterowania wykonaniem pętli za pomocą `break` i `continue` oraz używania pętli zagnieżdżonych.

## Wymagania wstępne

Student powinien znać:

- [03-petla-for.md](03-petla-for.md),
- [04-petle-while-do-while.md](04-petle-while-do-while.md),
- instrukcje warunkowe z lekcji [01-instrukcje-warunkowe.md](01-instrukcje-warunkowe.md).

## Krótka teoria

### Instrukcja `break`

Instrukcja `break` natychmiast kończy najbliższą pętlę.

Przykład:

```cpp
for (int i = 1; i <= 10; i++)
{
    if (i == 5)
    {
        break;
    }

    std::cout << i << std::endl;
}
```

Wynik:

```text
1
2
3
4
```

Gdy `i` ma wartość `5`, pętla kończy działanie.

## Przykład kodu: szukanie liczby

```cpp
int szukana = 7;
bool znaleziono = false;

for (int i = 1; i <= 10; i++)
{
    if (i == szukana)
    {
        znaleziono = true;
        break;
    }
}
```

Pełny przykład znajduje się w pliku [examples/break_search.cpp](examples/break_search.cpp).

### Instrukcja `continue`

Instrukcja `continue` pomija resztę aktualnego obiegu pętli i przechodzi do następnego.

Przykład:

```cpp
for (int i = 1; i <= 10; i++)
{
    if (i % 2 == 0)
    {
        continue;
    }

    std::cout << i << std::endl;
}
```

Ten kod wypisze tylko liczby nieparzyste. Gdy liczba jest parzysta, `continue` pomija `std::cout`.

Pełny przykład znajduje się w pliku [examples/continue_skip_even.cpp](examples/continue_skip_even.cpp).

### Kiedy używać `break` i `continue`

`break` jest przydatny, gdy:

- znaleźliśmy szukany element,
- dalsze wykonywanie pętli nie ma sensu,
- użytkownik wybrał zakończenie działania.

`continue` jest przydatne, gdy:

- chcemy pominąć niektóre dane,
- dalsze instrukcje w aktualnym obiegu nie powinny się wykonać,
- chcemy uprościć warunki wewnątrz pętli.

Nie należy nadużywać `break` i `continue`. Jeśli pętla staje się trudna do czytania, warto uprościć warunki albo podzielić kod na funkcje.

### Pętle zagnieżdżone

Pętla zagnieżdżona to pętla umieszczona wewnątrz innej pętli.

```cpp
for (int i = 1; i <= 3; i++)
{
    for (int j = 1; j <= 3; j++)
    {
        std::cout << i << " " << j << std::endl;
    }
}
```

Dla każdej wartości `i` wewnętrzna pętla przechodzi przez wszystkie wartości `j`.

## Przykład kodu: tabliczka mnożenia

```cpp
for (int row = 1; row <= 10; row++)
{
    for (int col = 1; col <= 10; col++)
    {
        std::cout << row * col << '\t';
    }

    std::cout << std::endl;
}
```

Pełny przykład znajduje się w pliku [examples/nested_multiplication_table.cpp](examples/nested_multiplication_table.cpp).

### `break` w pętli zagnieżdżonej

`break` kończy tylko najbliższą pętlę.

```cpp
for (int i = 1; i <= 3; i++)
{
    for (int j = 1; j <= 3; j++)
    {
        if (j == 2)
        {
            break;
        }
    }
}
```

W tym przykładzie `break` kończy pętlę po `j`, ale pętla po `i` działa dalej.

## Zadania do wykonania

1. Napisz program, który sprawdza liczby od `1` do `100` i kończy pętlę, gdy znajdzie pierwszą liczbę podzielną przez `17`.
2. Napisz program, który wypisuje liczby od `1` do `50`, pomijając liczby podzielne przez `5`.
3. Napisz program, który wczytuje liczby od użytkownika i kończy działanie po wpisaniu liczby ujemnej.
4. Napisz program, który wypisuje tabliczkę mnożenia od `1` do `10`.
5. Napisz program, który wypisuje prostokąt z gwiazdek o wymiarach podanych przez użytkownika.
6. Napisz program, który wypisuje trójkąt z gwiazdek o wysokości podanej przez użytkownika.

## Ćwiczenia dodatkowe

1. Dodaj warunek, który używa `continue` do pomijania liczb ujemnych.
2. Zmień przykład z `break`, aby kończył wyszukiwanie po znalezieniu dwóch wyników.
3. Rozbuduj pętlę zagnieżdżoną o nagłówki wierszy i kolumn.

## Kryteria zaliczenia

Program powinien:

- poprawnie używać `break` do zakończenia pętli,
- poprawnie używać `continue` do pomijania obiegu pętli,
- stosować pętle zagnieżdżone tam, gdzie problem ma dwa wymiary,
- kompilować się bez błędów,
- wypisywać wynik w czytelnej formie.

## Pytania kontrolne

1. Co robi `break` w pętli?
2. Co robi `continue` w pętli?
3. Czy `break` kończy wszystkie pętle zagnieżdżone?
4. Kiedy warto użyć pętli zagnieżdżonej?
5. Dlaczego nie należy nadużywać `break` i `continue`?
