# 04 - Tablice dwuwymiarowe

## Cel lekcji

Celem lekcji jest poznanie tablic dwuwymiarowych, czyli struktur przydatnych do reprezentowania tabel, macierzy i plansz.

## Wymagania wstępne

Student powinien znać:

- tablice jednowymiarowe z lekcji [03-tablice.md](03-tablice.md),
- pętle zagnieżdżone z segmentu [02-sterowanie-i-petle](../02-sterowanie-i-petle/05-break-continue-i-zagniezdzenia.md).

## Krótka teoria

### Czym jest tablica dwuwymiarowa

Tablica dwuwymiarowa przechowuje dane w układzie wierszy i kolumn.

Przykład:

```cpp
int macierz[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

Ta tablica ma:

- `2` wiersze,
- `3` kolumny,
- `6` elementów.

### Indeksy

Do elementu tablicy dwuwymiarowej odwołujemy się przez dwa indeksy:

```cpp
macierz[wiersz][kolumna]
```

Przykład:

```cpp
std::cout << macierz[0][0] << std::endl; // 1
std::cout << macierz[1][2] << std::endl; // 6
```

Indeksy, tak jak w tablicach jednowymiarowych, zaczynają się od `0`.

### Deklaracja

Składnia:

```cpp
typ nazwa[liczba_wierszy][liczba_kolumn];
```

Przykład:

```cpp
int plansza[3][3];
```

Taka tablica może reprezentować planszę 3 x 3, np. do gry w kółko i krzyżyk.

## Przykład kodu: iteracja po tablicy dwuwymiarowej

Do przechodzenia po wszystkich elementach używamy pętli zagnieżdżonych.

```cpp
for (int row = 0; row < rows; row++)
{
    for (int col = 0; col < cols; col++)
    {
        std::cout << macierz[row][col] << " ";
    }

    std::cout << std::endl;
}
```

Zewnętrzna pętla przechodzi po wierszach, a wewnętrzna po kolumnach.

Pełny przykład znajduje się w pliku [examples/matrix_print.cpp](examples/matrix_print.cpp).

## Przykład kodu: suma wszystkich elementów

```cpp
int suma = 0;

for (int row = 0; row < rows; row++)
{
    for (int col = 0; col < cols; col++)
    {
        suma += macierz[row][col];
    }
}
```

Pełny przykład znajduje się w pliku [examples/matrix_sum.cpp](examples/matrix_sum.cpp).

## Przykład kodu: suma wierszy

Możemy też przetwarzać każdy wiersz osobno.

```cpp
for (int row = 0; row < rows; row++)
{
    int sumaWiersza = 0;

    for (int col = 0; col < cols; col++)
    {
        sumaWiersza += macierz[row][col];
    }

    std::cout << "Suma wiersza " << row << ": " << sumaWiersza << std::endl;
}
```

Pełny przykład znajduje się w pliku [examples/matrix_row_sums.cpp](examples/matrix_row_sums.cpp).

### Tablica dwuwymiarowa jako plansza

Tablica dwuwymiarowa dobrze nadaje się do reprezentowania plansz.

```cpp
char plansza[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};
```

Przykładowe użycie:

```cpp
plansza[0][0] = 'X';
plansza[1][1] = 'O';
```

To dobry punkt startowy do projektu gry w kółko i krzyżyk.

## Typowe błędy

### Zamiana wiersza z kolumną

Jeżeli przyjmujemy zapis `macierz[row][col]`, pierwszy indeks oznacza wiersz, a drugi kolumnę.

### Wyjście poza zakres

Dla tablicy:

```cpp
int macierz[2][3];
```

poprawne indeksy to:

- wiersze: `0`, `1`,
- kolumny: `0`, `1`, `2`.

`macierz[2][0]` i `macierz[0][3]` są poza zakresem.

## Zadania do wykonania

1. Utwórz tablicę `3 x 3` liczb całkowitych i wypisz ją w formie tabeli.
2. Oblicz sumę wszystkich elementów tablicy `3 x 3`.
3. Oblicz sumę każdego wiersza osobno.
4. Oblicz sumę każdej kolumny osobno.
5. Znajdź największy element w tablicy dwuwymiarowej.
6. Utwórz pustą planszę `3 x 3` dla gry w kółko i krzyżyk i wypisz ją na ekran.

## Kryteria zaliczenia

Program powinien:

- poprawnie deklarować tablicę dwuwymiarową,
- używać pierwszego indeksu jako wiersza,
- używać drugiego indeksu jako kolumny,
- iterować po tablicy pętlami zagnieżdżonymi,
- nie wychodzić poza zakres tablicy,
- kompilować się bez błędów.

## Pytania kontrolne

1. Co oznaczają dwa indeksy w zapisie `tablica[row][col]`?
2. Jakie są poprawne indeksy dla tablicy `int x[2][3]`?
3. Dlaczego do tablicy dwuwymiarowej zwykle używamy dwóch pętli?
4. Jak można reprezentować planszę gry za pomocą tablicy dwuwymiarowej?
5. Czym różni się suma wszystkich elementów od sumy pojedynczego wiersza?
