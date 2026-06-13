# 02 - `std::vector`

## Cel lekcji

Celem lekcji jest nauczenie się podstaw pracy z `std::vector`: tworzenia wektora, dodawania elementów, usuwania ostatniego elementu, odczytu po indeksie i iteracji.

## Wymagania wstępne

Student powinien znać:

- tablice z segmentu [03-funkcje-tablice-napisy](../03-funkcje-tablice-napisy/README.md),
- pętle z segmentu [02-sterowanie-i-petle](../02-sterowanie-i-petle/README.md),
- podstawy STL z lekcji [01-wprowadzenie-do-stl.md](01-wprowadzenie-do-stl.md).

## Krótka teoria

### Czym jest `std::vector`

`std::vector` to kontener przechowujący elementy w kolejności.

Można myśleć o nim jak o tablicy, która może zmieniać rozmiar.

```cpp
std::vector<int> liczby;
```

Do użycia `std::vector` potrzebny jest nagłówek:

```cpp
#include <vector>
```

## Przykład kodu: tworzenie wektora

Pusty wektor:

```cpp
std::vector<int> liczby;
```

Wektor z wartościami początkowymi:

```cpp
std::vector<int> liczby = {10, 20, 30};
```

Wektor o podanym rozmiarze:

```cpp
std::vector<int> liczby(5);
```

Taki wektor ma pięć elementów ustawionych na `0`.

## Przykład kodu: dodawanie elementów

Do dodania elementu na końcu używamy `push_back`.

```cpp
liczby.push_back(10);
liczby.push_back(20);
liczby.push_back(30);
```

Pełny przykład znajduje się w pliku [examples/vector_basics.cpp](examples/vector_basics.cpp).

### Rozmiar wektora

Liczbę elementów sprawdzamy metodą `size`.

```cpp
std::cout << liczby.size() << std::endl;
```

`size()` zwraca typ bez znaku. W prostych pętlach indeksowych można użyć:

```cpp
for (std::size_t i = 0; i < liczby.size(); i++)
{
    std::cout << liczby[i] << std::endl;
}
```

Do `std::size_t` zwykle wystarczy dołączony już nagłówek standardowy, ale w większych programach można też użyć:

```cpp
#include <cstddef>
```

### Dostęp po indeksie

Dostęp przez `[]`:

```cpp
std::cout << liczby[0] << std::endl;
```

Jest szybki, ale nie sprawdza zakresu.

Dostęp przez `at()`:

```cpp
std::cout << liczby.at(0) << std::endl;
```

`at()` sprawdza zakres i w razie błędu zgłasza wyjątek `std::out_of_range`.

Na początku warto używać `at()`, gdy indeks pochodzi od użytkownika albo z obliczeń.

### Pętla zakresowa

Najczytelniejszy sposób wypisania wszystkich elementów:

```cpp
for (const auto& liczba : liczby)
{
    std::cout << liczba << std::endl;
}
```

Jeśli elementy są małe, np. `int`, można też pisać:

```cpp
for (int liczba : liczby)
{
    std::cout << liczba << std::endl;
}
```

### Usuwanie ostatniego elementu

Ostatni element usuwamy metodą `pop_back`.

```cpp
liczby.pop_back();
```

Nie wolno wywoływać `pop_back()` na pustym wektorze.

```cpp
if (!liczby.empty())
{
    liczby.pop_back();
}
```

### `empty`, `front`, `back`

Przydatne metody:

- `empty()` - czy wektor jest pusty,
- `front()` - pierwszy element,
- `back()` - ostatni element.

```cpp
if (!liczby.empty())
{
    std::cout << liczby.front() << std::endl;
    std::cout << liczby.back() << std::endl;
}
```

## Przykład kodu: wektor struktur lub obiektów

Wektor może przechowywać nie tylko liczby, ale też struktury i obiekty.

```cpp
struct Kandydat
{
    std::string imie;
    int wiek;
};

std::vector<Kandydat> kandydaci;
```

Pełny przykład znajduje się w pliku [examples/vector_records.cpp](examples/vector_records.cpp).

### `resize`

Metoda `resize` zmienia rozmiar wektora.

```cpp
std::vector<int> liczby = {1, 2, 3};
liczby.resize(5);
```

Po powiększeniu nowe elementy będą miały wartość domyślną, np. `0` dla `int`.

```cpp
liczby.resize(6, 4);
```

Ten zapis powiększa wektor i wstawia `4` jako wartość nowych elementów.

## Typowe błędy

### Wyjście poza zakres

Niepoprawnie:

```cpp
std::vector<int> liczby = {1, 2, 3};
std::cout << liczby[10] << std::endl;
```

Poprawniej:

```cpp
if (indeks >= 0 && indeks < static_cast<int>(liczby.size()))
{
    std::cout << liczby[indeks] << std::endl;
}
```

### `pop_back` na pustym wektorze

Niepoprawnie:

```cpp
liczby.pop_back();
```

Poprawnie:

```cpp
if (!liczby.empty())
{
    liczby.pop_back();
}
```

### Kopiowanie dużych obiektów w pętli

Mniej korzystnie:

```cpp
for (auto kandydat : kandydaci)
{
}
```

Lepiej:

```cpp
for (const auto& kandydat : kandydaci)
{
}
```

## Zadania do wykonania

1. Utwórz wektor liczb całkowitych i dodaj do niego liczby od `1` do `10`.
2. Wypisz zawartość wektora pętlą zakresową.
3. Usuń ostatni element wektora, jeśli wektor nie jest pusty.
4. Wypisz pierwszy i ostatni element wektora.
5. Utwórz wektor struktur `Osoba` z polami `imie` i `wiek`. Wypisz wszystkie osoby.

## Kryteria zaliczenia

Program powinien:

- dołączać nagłówek `<vector>`,
- poprawnie tworzyć `std::vector`,
- dodawać elementy przez `push_back`,
- sprawdzać `empty()` przed `pop_back`, `front` i `back`,
- przechodzić po wektorze pętlą zakresową,
- kompilować się bez błędów.

## Pytania kontrolne

1. Czym `std::vector` różni się od zwykłej tablicy?
2. Do czego służy `push_back`?
3. Do czego służy `size`?
4. Czym różni się `liczby[0]` od `liczby.at(0)`?
5. Dlaczego warto sprawdzić `empty()` przed `pop_back()`?
