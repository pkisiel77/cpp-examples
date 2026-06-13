# 03 - Tablice jednowymiarowe

## Cel lekcji

Celem lekcji jest poznanie tablic jednowymiarowych: deklaracji, inicjalizacji, indeksowania i iteracji po elementach.

## Wymagania wstępne

Student powinien znać:

- pętlę `for` z segmentu [02-sterowanie-i-petle](../02-sterowanie-i-petle/README.md),
- funkcje z lekcji [01-funkcje-podstawy.md](01-funkcje-podstawy.md),
- parametry i zmienne lokalne z lekcji [02-parametry-i-zakres.md](02-parametry-i-zakres.md).

## Krótka teoria

### Czym jest tablica

Tablica przechowuje wiele wartości tego samego typu pod jedną nazwą.

Przykład:

```cpp
int liczby[5] = {10, 20, 30, 40, 50};
```

Ta tablica:

- ma nazwę `liczby`,
- przechowuje wartości typu `int`,
- ma `5` elementów.

### Indeksy

Elementy tablicy numerujemy od `0`.

```cpp
int liczby[5] = {10, 20, 30, 40, 50};

std::cout << liczby[0] << std::endl; // 10
std::cout << liczby[4] << std::endl; // 50
```

Dla tablicy o rozmiarze `5` poprawne indeksy to:

```text
0, 1, 2, 3, 4
```

Indeks `5` jest już poza zakresem.

### Deklaracja i inicjalizacja

Tablicę można zadeklarować bez wartości początkowych:

```cpp
int wyniki[3];

wyniki[0] = 12;
wyniki[1] = 15;
wyniki[2] = 18;
```

Można też podać wartości od razu:

```cpp
int wyniki[3] = {12, 15, 18};
```

Jeżeli podajemy wartości przy inicjalizacji, kompilator może sam określić rozmiar:

```cpp
int wyniki[] = {12, 15, 18};
```

## Przykład kodu: iteracja po tablicy

Do przechodzenia po elementach tablicy najczęściej używamy pętli `for`.

```cpp
int liczby[] = {1, 3, 6, 3, 4, 7, 8, 4, 3};
int rozmiar = sizeof(liczby) / sizeof(liczby[0]);

for (int i = 0; i < rozmiar; i++)
{
    std::cout << liczby[i] << std::endl;
}
```

Pełny przykład znajduje się w pliku [examples/array_print.cpp](examples/array_print.cpp).

### Rozmiar tablicy

Dla tablic statycznych w tym samym zakresie można obliczyć liczbę elementów:

```cpp
int rozmiar = sizeof(liczby) / sizeof(liczby[0]);
```

`sizeof(liczby)` zwraca rozmiar całej tablicy w bajtach, a `sizeof(liczby[0])` rozmiar jednego elementu.

## Przykład kodu: suma i średnia

Tablice często przetwarzamy w pętli.

```cpp
int suma = 0;

for (int i = 0; i < rozmiar; i++)
{
    suma += liczby[i];
}

double srednia = static_cast<double>(suma) / rozmiar;
```

Pełny przykład znajduje się w pliku [examples/array_average.cpp](examples/array_average.cpp).

## Przykład kodu: minimum i maksimum

Typowy algorytm:

1. Przyjmij pierwszy element jako aktualne minimum i maksimum.
2. Przejdź po pozostałych elementach.
3. Aktualizuj minimum i maksimum, gdy znajdziesz mniejszą lub większą wartość.

```cpp
int minimum = liczby[0];
int maksimum = liczby[0];

for (int i = 1; i < rozmiar; i++)
{
    if (liczby[i] < minimum)
    {
        minimum = liczby[i];
    }

    if (liczby[i] > maksimum)
    {
        maksimum = liczby[i];
    }
}
```

Pełny przykład znajduje się w pliku [examples/array_min_max.cpp](examples/array_min_max.cpp).

## Typowy błąd: wyjście poza zakres tablicy

Dla tablicy:

```cpp
int liczby[3] = {1, 2, 3};
```

poprawne indeksy to `0`, `1`, `2`.

Kod:

```cpp
liczby[3] = 10;
```

jest błędny, bo zapisuje poza tablicą. Taki błąd może prowadzić do nieprzewidywalnego działania programu.

## Zadania do wykonania

1. Utwórz tablicę pięciu liczb całkowitych i wypisz wszystkie elementy.
2. Utwórz tablicę liczb i oblicz sumę jej elementów.
3. Utwórz tablicę liczb i oblicz średnią arytmetyczną.
4. Utwórz tablicę liczb i znajdź najmniejszą oraz największą wartość.
5. Wczytaj od użytkownika pięć liczb do tablicy, a następnie wypisz je w odwrotnej kolejności.
6. Policz, ile elementów tablicy jest parzystych.

## Ćwiczenia dodatkowe

1. Dodaj funkcję liczącą sumę elementów tablicy.
2. Dodaj funkcję zliczającą elementy większe od podanej wartości.
3. Zmień przykład tak, aby rozmiar tablicy był stałą nazwaną.

## Kryteria zaliczenia

Program powinien:

- poprawnie deklarować tablicę,
- używać indeksów od `0` do `rozmiar - 1`,
- iterować po tablicy pętlą,
- nie wychodzić poza zakres tablicy,
- kompilować się bez błędów.

## Pytania kontrolne

1. Od jakiego indeksu zaczyna się tablica w C++?
2. Jakie są poprawne indeksy dla tablicy `int x[4]`?
3. Do czego służy `sizeof(tablica) / sizeof(tablica[0])`?
4. Dlaczego wyjście poza zakres tablicy jest błędem?
5. Kiedy warto użyć tablicy zamiast kilku osobnych zmiennych?
