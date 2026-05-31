# 02 - Referencje

## Cel lekcji

Celem lekcji jest zrozumienie, czym jest referencja, jak różni się od wskaźnika i kiedy warto jej używać.

## Wymagania wstępne

Student powinien znać:

- zmienne i typy danych,
- funkcje,
- podstawy wskaźników z lekcji [01-adresy-i-wskazniki.md](01-adresy-i-wskazniki.md).

## Czym jest referencja

Referencja to inna nazwa dla istniejącej zmiennej.

```cpp
int liczba = 10;
int& ref = liczba;
```

`ref` nie jest osobną kopią wartości. `ref` odnosi się do tej samej zmiennej co `liczba`.

```cpp
ref = 20;
std::cout << liczba << std::endl; // 20
```

Pełny przykład znajduje się w pliku [examples/reference_alias.cpp](examples/reference_alias.cpp).

## Referencję trzeba zainicjalizować

Referencja musi od razu odnosić się do istniejącej zmiennej.

Poprawnie:

```cpp
int liczba = 10;
int& ref = liczba;
```

Niepoprawnie:

```cpp
int& ref; // błąd: referencja musi być zainicjalizowana
```

## Referencji nie przepinamy

Po utworzeniu referencja pozostaje aliasem tej samej zmiennej.

```cpp
int a = 1;
int b = 2;

int& ref = a;
ref = b;
```

Ostatnia linia nie sprawia, że `ref` zaczyna odnosić się do `b`. Ona przypisuje wartość `b` do `a`.

Po wykonaniu tego kodu:

```cpp
a == 2
b == 2
```

## Referencja a wskaźnik

| Cecha | Referencja | Wskaźnik |
| --- | --- | --- |
| Wymaga inicjalizacji | tak | nie |
| Może być `nullptr` | nie | tak |
| Dostęp do wartości | przez nazwę | przez `*` |
| Można przepiąć na inny obiekt | nie | tak |

Referencja jest wygodna, gdy funkcja ma pracować na istniejącej zmiennej i nie chcemy obsługiwać `nullptr`.

Wskaźnik jest potrzebny, gdy wartość może być pusta albo gdy chcemy jawnie pokazać pracę na adresach.

## Referencje w funkcjach

Referencje często służą do modyfikowania argumentów przekazanych do funkcji.

```cpp
void zwieksz(int& liczba)
{
    liczba++;
}
```

Wywołanie:

```cpp
int x = 5;
zwieksz(x);
std::cout << x << std::endl; // 6
```

Pełny przykład znajduje się w pliku [examples/reference_increment.cpp](examples/reference_increment.cpp).

## Zamiana wartości przez referencje

```cpp
void zamien(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
```

Ta funkcja modyfikuje oryginalne zmienne przekazane przy wywołaniu.

Pełny przykład znajduje się w pliku [examples/reference_swap.cpp](examples/reference_swap.cpp).

## `const` referencja

Jeżeli funkcja ma tylko odczytać argument i nie powinna go zmieniać, można użyć `const`.

```cpp
void wypisz(const std::string& tekst)
{
    std::cout << tekst << std::endl;
}
```

`const std::string&` oznacza: przyjmij istniejący napis bez kopiowania i nie pozwalaj funkcji go zmienić.

To jest szczególnie przydatne dla większych obiektów, takich jak `std::string`.

## Zadania

1. Utwórz zmienną `int` i referencję do niej. Zmień wartość przez referencję i wypisz oryginalną zmienną.
2. Napisz funkcję `zwieksz`, która przyjmuje `int&` i zwiększa wartość o `1`.
3. Napisz funkcję `wyzeruj`, która przyjmuje `int&` i ustawia wartość na `0`.
4. Napisz funkcję `zamien`, która przyjmuje dwie referencje do `int` i zamienia wartości miejscami.
5. Napisz funkcję `wypiszTekst`, która przyjmuje `const std::string&` i wypisuje tekst.

## Kryteria zaliczenia

Program powinien:

- poprawnie deklarować referencje,
- inicjalizować referencje przy deklaracji,
- używać referencji do modyfikowania argumentów funkcji,
- używać `const` referencji tam, gdzie funkcja nie powinna zmieniać argumentu,
- kompilować się bez błędów.

## Pytania kontrolne

1. Czym jest referencja?
2. Czy referencja może być niezainicjalizowana?
3. Czy referencję można przepiąć na inną zmienną?
4. Czym różni się referencja od wskaźnika?
5. Po co stosuje się `const std::string&`?
