# 01 - Adresy i wskaźniki

## Cel lekcji

Celem lekcji jest zrozumienie, czym jest adres zmiennej, czym jest wskaźnik i jak bezpiecznie odczytywać wartość wskazywaną przez wskaźnik.

## Wymagania wstępne

Student powinien znać:

- zmienne i typy danych z segmentu [01-podstawy](../01-podstawy/README.md),
- funkcje z segmentu [03-funkcje-tablice-napisy](../03-funkcje-tablice-napisy/README.md).

## Wartość i adres

Zmienna ma wartość oraz miejsce w pamięci.

```cpp
int liczba = 42;
```

Wartością zmiennej `liczba` jest `42`.

Adres zmiennej można pobrać operatorem `&`.

```cpp
std::cout << &liczba << std::endl;
```

Adres zwykle jest wypisywany jako liczba szesnastkowa. Konkretna wartość adresu może być inna przy każdym uruchomieniu programu.

Pełny przykład znajduje się w pliku [examples/address_of_variable.cpp](examples/address_of_variable.cpp).

## Czym jest wskaźnik

Wskaźnik to zmienna, która przechowuje adres innej zmiennej.

```cpp
int liczba = 42;
int* wskaznik = &liczba;
```

`wskaznik` przechowuje adres zmiennej `liczba`.

Zapis:

```cpp
int* wskaznik;
```

oznacza, że `wskaznik` może przechowywać adres zmiennej typu `int`.

## Deklarowanie wskaźników

Możliwe są różne style zapisu:

```cpp
int* p;
int *p;
```

W tym kursie stosujemy zapis:

```cpp
int* p;
```

Warto uważać przy deklarowaniu kilku zmiennych w jednej linii:

```cpp
int* p, liczba;
```

W tym przykładzie tylko `p` jest wskaźnikiem. `liczba` jest zwykłą zmienną typu `int`.

Dla czytelności lepiej pisać:

```cpp
int* p;
int liczba;
```

## Dereferencja

Operator `*` przed wskaźnikiem pozwala dostać się do wartości, na którą wskaźnik wskazuje.

```cpp
int liczba = 42;
int* wskaznik = &liczba;

std::cout << *wskaznik << std::endl; // 42
```

Można też zmienić wartość zmiennej przez wskaźnik:

```cpp
*wskaznik = 100;
std::cout << liczba << std::endl; // 100
```

Pełny przykład znajduje się w pliku [examples/pointer_dereference.cpp](examples/pointer_dereference.cpp).

## `nullptr`

Wskaźnik może nie wskazywać na żadną poprawną zmienną. W C++ używamy wtedy wartości `nullptr`.

```cpp
int* wskaznik = nullptr;
```

Przed dereferencją wskaźnika warto sprawdzić, czy nie jest pusty.

```cpp
if (wskaznik != nullptr)
{
    std::cout << *wskaznik << std::endl;
}
```

Nie wolno dereferencjonować `nullptr`.

```cpp
int* wskaznik = nullptr;
// std::cout << *wskaznik << std::endl; // błąd w czasie działania
```

Pełny przykład znajduje się w pliku [examples/nullptr_check.cpp](examples/nullptr_check.cpp).

## Wskaźnik i adres wskaźnika

Wskaźnik też jest zmienną, więc ma własny adres.

```cpp
int liczba = 42;
int* wskaznik = &liczba;

std::cout << "Wartosc liczby: " << liczba << std::endl;
std::cout << "Adres liczby: " << &liczba << std::endl;
std::cout << "Wartosc wskaznika: " << wskaznik << std::endl;
std::cout << "Adres wskaznika: " << &wskaznik << std::endl;
```

`wskaznik` przechowuje adres liczby, ale `&wskaznik` to adres samego wskaźnika.

## Częste błędy

### Błędny typ

Niepoprawnie:

```cpp
int liczba = 42;
int p = &liczba;
```

Poprawnie:

```cpp
int liczba = 42;
int* p = &liczba;
```

### Dereferencja pustego wskaźnika

Niepoprawnie:

```cpp
int* p = nullptr;
std::cout << *p << std::endl;
```

Poprawnie:

```cpp
int* p = nullptr;

if (p != nullptr)
{
    std::cout << *p << std::endl;
}
```

## Zadania

1. Utwórz zmienną typu `int`, wypisz jej wartość i adres.
2. Utwórz wskaźnik na zmienną typu `int` i wypisz wartość zmiennej przez wskaźnik.
3. Zmień wartość zmiennej przez wskaźnik.
4. Utwórz wskaźnik ustawiony na `nullptr` i sprawdź go instrukcją `if`.
5. Wypisz adres zmiennej, wartość wskaźnika oraz adres samego wskaźnika.

## Kryteria zaliczenia

Program powinien:

- poprawnie używać operatora `&`,
- poprawnie deklarować wskaźniki,
- używać operatora `*` tylko dla poprawnych wskaźników,
- sprawdzać `nullptr` przed dereferencją,
- kompilować się bez błędów.

## Pytania kontrolne

1. Co zwraca operator `&`?
2. Czym jest wskaźnik?
3. Co robi operator `*` przed wskaźnikiem?
4. Do czego służy `nullptr`?
5. Dlaczego nie wolno dereferencjonować pustego wskaźnika?
