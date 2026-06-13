# 03 - Przekazywanie danych do funkcji

## Cel lekcji

Celem lekcji jest porównanie trzech sposobów przekazywania danych do funkcji: przez wartość, przez wskaźnik i przez referencję.

## Wymagania wstępne

Student powinien znać:

- funkcje z segmentu [03-funkcje-tablice-napisy](../03-funkcje-tablice-napisy/README.md),
- wskaźniki z lekcji [01-adresy-i-wskazniki.md](01-adresy-i-wskazniki.md),
- referencje z lekcji [02-referencje.md](02-referencje.md).

## Krótka teoria

### Przekazywanie przez wartość

Przy przekazywaniu przez wartość funkcja dostaje kopię argumentu.

```cpp
void ustawNaZero(int liczba)
{
    liczba = 0;
}
```

Wywołanie:

```cpp
int x = 5;
ustawNaZero(x);
std::cout << x << std::endl; // 5
```

Oryginalna zmienna `x` nie zmienia się, bo funkcja modyfikuje tylko kopię.

Pełny przykład znajduje się w pliku [examples/pass_by_value_no_change.cpp](examples/pass_by_value_no_change.cpp).

### Przekazywanie przez wskaźnik

Funkcja może otrzymać adres zmiennej. Wtedy może zmienić oryginalną wartość.

```cpp
void ustawNaZero(int* liczba)
{
    if (liczba != nullptr)
    {
        *liczba = 0;
    }
}
```

Wywołanie:

```cpp
int x = 5;
ustawNaZero(&x);
std::cout << x << std::endl; // 0
```

W tej wersji funkcja przyjmuje wskaźnik, więc trzeba przekazać adres zmiennej operatorem `&`.

### Przekazywanie przez referencję

Funkcja może otrzymać referencję do zmiennej. Wtedy pracuje bezpośrednio na oryginalnej zmiennej.

```cpp
void ustawNaZero(int& liczba)
{
    liczba = 0;
}
```

Wywołanie:

```cpp
int x = 5;
ustawNaZero(x);
std::cout << x << std::endl; // 0
```

Dla użytkownika funkcji wywołanie wygląda prościej niż przy wskaźniku, bo nie trzeba pisać `&x`.

## Przykład kodu: zamiana wartości przez wskaźniki

```cpp
void zamien(int* a, int* b)
{
    if (a == nullptr || b == nullptr)
    {
        return;
    }

    int temp = *a;
    *a = *b;
    *b = temp;
}
```

Pełny przykład znajduje się w pliku [examples/swap_by_pointer.cpp](examples/swap_by_pointer.cpp).

## Przykład kodu: zamiana wartości przez referencje

```cpp
void zamien(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
```

Pełny przykład znajduje się w pliku [examples/swap_by_reference.cpp](examples/swap_by_reference.cpp).

## Przykład kodu: zwracanie więcej niż jednego wyniku

Funkcja może zwrócić tylko jedną wartość przez `return`, ale dodatkowe wyniki można przekazać przez referencje lub wskaźniki.

Przykład przez referencje:

```cpp
void sumaIIloczyn(int a, int b, int& suma, int& iloczyn)
{
    suma = a + b;
    iloczyn = a * b;
}
```

Wywołanie:

```cpp
int suma;
int iloczyn;

sumaIIloczyn(3, 4, suma, iloczyn);
```

Pełny przykład znajduje się w pliku [examples/multiple_results_reference.cpp](examples/multiple_results_reference.cpp).

### Kiedy używać którego sposobu

| Sposób | Kiedy używać |
| --- | --- |
| przez wartość | gdy funkcja nie ma zmieniać argumentu |
| przez wskaźnik | gdy argument może być pusty albo chcemy jawnie pracować na adresie |
| przez referencję | gdy funkcja ma zmienić argument i argument musi istnieć |
| przez `const` referencję | gdy chcemy uniknąć kopii, ale nie zmieniać argumentu |

## Zadania do wykonania

1. Napisz funkcję `ustawNaZero` w trzech wersjach: przez wartość, przez wskaźnik i przez referencję. Porównaj wyniki.
2. Napisz funkcję, która zamienia miejscami dwie liczby przekazane przez wskaźniki.
3. Napisz funkcję, która zamienia miejscami dwie liczby przekazane przez referencje.
4. Napisz funkcję, która przyjmuje dwie liczby i zwraca przez referencje ich sumę oraz iloczyn.
5. Napisz funkcję, która przyjmuje wskaźnik na `int` i zwiększa wartość tylko wtedy, gdy wskaźnik nie jest `nullptr`.

## Kryteria zaliczenia

Program powinien:

- rozróżniać przekazywanie przez wartość, wskaźnik i referencję,
- sprawdzać wskaźnik przed dereferencją,
- używać referencji do argumentów, które muszą istnieć,
- kompilować się bez błędów,
- jasno pokazywać, które funkcje zmieniają oryginalne zmienne.

## Pytania kontrolne

1. Dlaczego funkcja przyjmująca argument przez wartość nie zmienia oryginalnej zmiennej?
2. Po co przy wywołaniu funkcji wskaźnikowej używamy `&x`?
3. Dlaczego wskaźnik trzeba sprawdzić przed dereferencją?
4. Kiedy referencja jest wygodniejsza od wskaźnika?
5. Jak można zwrócić z funkcji więcej niż jeden wynik?
