# 04 - Bezpieczeństwo pamięci

## Cel lekcji

Celem lekcji jest poznanie podstawowych zasad bezpiecznej pracy ze wskaźnikami i referencjami.

## Wymagania wstępne

Student powinien znać:

- wskaźniki z lekcji [01-adresy-i-wskazniki.md](01-adresy-i-wskazniki.md),
- referencje z lekcji [02-referencje.md](02-referencje.md),
- przekazywanie argumentów z lekcji [03-przekazywanie-do-funkcji.md](03-przekazywanie-do-funkcji.md).

## Krótka teoria

### Zasada 1: inicjalizuj wskaźniki

Nie zostawiaj wskaźnika bez wartości początkowej.

Niepoprawnie:

```cpp
int* p;
```

Poprawnie:

```cpp
int* p = nullptr;
```

Jeżeli wskaźnik nie wskazuje jeszcze na poprawną zmienną, ustaw go na `nullptr`.

### Zasada 2: sprawdzaj `nullptr`

Przed dereferencją wskaźnika sprawdź, czy nie jest pusty.

```cpp
if (p != nullptr)
{
    std::cout << *p << std::endl;
}
```

Pełny przykład znajduje się w pliku [examples/safe_pointer_read.cpp](examples/safe_pointer_read.cpp).

### Zasada 3: nie zwracaj adresu zmiennej lokalnej

Zmienna lokalna przestaje istnieć po zakończeniu funkcji.

Niepoprawny pomysł:

```cpp
int* niepoprawnie()
{
    int lokalna = 10;
    return &lokalna;
}
```

Po wyjściu z funkcji `lokalna` już nie istnieje. Wskaźnik zwrócony z takiej funkcji wskazywałby na niepoprawne miejsce.

Bezpieczniej zwrócić wartość:

```cpp
int poprawnie()
{
    int lokalna = 10;
    return lokalna;
}
```

### Zasada 4: nie wychodź poza zakres tablicy

Dla tablicy:

```cpp
int tablica[3] = {1, 2, 3};
```

poprawne indeksy to `0`, `1`, `2`.

Ten kod jest błędny:

```cpp
tablica[3] = 10;
```

Podobny problem może wystąpić przy pracy ze wskaźnikiem na pierwszy element tablicy.

```cpp
int* p = tablica;
```

`p[0]`, `p[1]`, `p[2]` są poprawne. `p[3]` jest poza zakresem.

Pełny przykład bezpiecznego przejścia po tablicy znajduje się w pliku [examples/safe_array_pointer.cpp](examples/safe_array_pointer.cpp).

### Zasada 5: używaj referencji, gdy argument musi istnieć

Jeżeli funkcja wymaga poprawnej zmiennej, referencja jest często bezpieczniejsza i czytelniejsza niż wskaźnik.

```cpp
void zwieksz(int& liczba)
{
    liczba++;
}
```

Referencja nie może być `nullptr`, więc nie trzeba sprawdzać pustego argumentu.

Wskaźnik wybierz wtedy, gdy brak wartości jest dopuszczalny:

```cpp
void zwiekszJesliIstnieje(int* liczba)
{
    if (liczba != nullptr)
    {
        (*liczba)++;
    }
}
```

Pełny przykład znajduje się w pliku [examples/safe_optional_pointer.cpp](examples/safe_optional_pointer.cpp).

### Zasada 6: ograniczaj zakres zmiennych

Twórz zmienne możliwie blisko miejsca użycia.

```cpp
if (warunek)
{
    int wynik = 10;
    std::cout << wynik << std::endl;
}
```

Im mniejszy zakres zmiennej, tym mniejsze ryzyko przypadkowego użycia jej w złym miejscu.

## Dobre praktyki

- Ustawiaj pusty wskaźnik na `nullptr`.
- Sprawdzaj wskaźnik przed dereferencją.
- Nie zwracaj adresów zmiennych lokalnych.
- Nie wychodź poza zakres tablicy.
- Używaj referencji, gdy argument musi istnieć.
- Używaj `const` referencji, gdy funkcja ma tylko czytać większy obiekt.
- Pisz małe funkcje, które jasno pokazują, kto modyfikuje dane.

## Zadania do wykonania

1. Napisz funkcję `wypiszJesliIstnieje`, która przyjmuje `int*` i wypisuje wartość tylko wtedy, gdy wskaźnik nie jest `nullptr`.
2. Napisz funkcję `zwiekszJesliIstnieje`, która przyjmuje `int*` i zwiększa wartość tylko wtedy, gdy wskaźnik nie jest `nullptr`.
3. Napisz program, który bezpiecznie przechodzi po tablicy przez wskaźnik i jej rozmiar.
4. Napisz funkcję `zwieksz`, która przyjmuje `int&`. Porównaj ją z wersją wskaźnikową.
5. Znajdź w swoich wcześniejszych przykładach miejsca, w których można użyć `const` referencji.

## Ćwiczenia dodatkowe

1. Dodaj sprawdzanie wskaźnika przed każdym odczytem.
2. Zmień przykład tak, aby funkcja zwracała informację o błędzie.
3. Wypisz komunikat diagnostyczny, gdy dane wejściowe są niepoprawne.

## Kryteria zaliczenia

Program powinien:

- inicjalizować wskaźniki,
- sprawdzać `nullptr` przed dereferencją,
- nie zwracać adresów zmiennych lokalnych,
- nie wychodzić poza zakres tablic,
- kompilować się bez błędów.

## Pytania kontrolne

1. Dlaczego warto inicjalizować wskaźnik wartością `nullptr`?
2. Co może się stać przy dereferencji pustego wskaźnika?
3. Dlaczego nie wolno zwracać adresu zmiennej lokalnej?
4. Co oznacza wyjście poza zakres tablicy?
5. Kiedy referencja jest bezpieczniejsza niż wskaźnik?
