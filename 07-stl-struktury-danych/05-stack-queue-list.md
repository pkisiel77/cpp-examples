# 05 - `std::stack`, `std::queue`, `std::list`

## Cel lekcji

Celem lekcji jest poznanie trzech struktur danych z biblioteki standardowej: stosu, kolejki i listy dwukierunkowej. Student powinien rozumieć różnicę między LIFO i FIFO oraz wiedzieć, kiedy `std::list` jest lepszym wyborem niż `std::vector`.

## Wymagania wstępne

Student powinien znać:

- podstawy STL z lekcji [01-wprowadzenie-do-stl.md](01-wprowadzenie-do-stl.md),
- `std::vector` z lekcji [02-vector.md](02-vector.md),
- algorytmy STL z lekcji [03-algorytmy-stl.md](03-algorytmy-stl.md).

## `std::stack`

`std::stack` to stos. Działa według zasady LIFO:

```text
last in, first out
```

Ostatni dodany element jest zdejmowany jako pierwszy.

Do użycia stosu potrzebny jest nagłówek:

```cpp
#include <stack>
```

Podstawowe operacje:

- `push` - dodaje element,
- `top` - zwraca element na szczycie,
- `pop` - usuwa element ze szczytu,
- `empty` - sprawdza, czy stos jest pusty,
- `size` - zwraca liczbę elementów.

Przykład:

```cpp
std::stack<std::string> historia;
historia.push("Dodano rekord");
historia.push("Zmieniono rekord");

std::cout << historia.top() << std::endl;
historia.pop();
```

Pełny przykład znajduje się w pliku [examples/stack_queue.cpp](examples/stack_queue.cpp).

## `std::queue`

`std::queue` to kolejka. Działa według zasady FIFO:

```text
first in, first out
```

Pierwszy dodany element jest obsługiwany jako pierwszy.

Do użycia kolejki potrzebny jest nagłówek:

```cpp
#include <queue>
```

Podstawowe operacje:

- `push` - dodaje element na koniec,
- `front` - zwraca pierwszy element,
- `back` - zwraca ostatni element,
- `pop` - usuwa pierwszy element,
- `empty` - sprawdza, czy kolejka jest pusta,
- `size` - zwraca liczbę elementów.

Przykład:

```cpp
std::queue<std::string> zgloszenia;
zgloszenia.push("Zgloszenie 1");
zgloszenia.push("Zgloszenie 2");

std::cout << zgloszenia.front() << std::endl;
zgloszenia.pop();
```

## LIFO kontra FIFO

Stos:

```text
dodaj: A, B, C
zdejmij: C, B, A
```

Kolejka:

```text
dodaj: A, B, C
obsłuż: A, B, C
```

Stos pasuje do historii cofania, a kolejka do obsługi zgłoszeń.

## `std::list`

`std::list` to lista dwukierunkowa.

Do użycia listy potrzebny jest nagłówek:

```cpp
#include <list>
```

Przydatne operacje:

- `push_front` - dodaje element na początek,
- `push_back` - dodaje element na koniec,
- `insert` - wstawia element w wybrane miejsce,
- `erase` - usuwa element,
- `remove` - usuwa elementy o podanej wartości.

Przykład:

```cpp
std::list<int> liczby = {7, 5, 16, 8};
liczby.push_front(25);
liczby.push_back(13);
```

Pełny przykład znajduje się w pliku [examples/list_operations.cpp](examples/list_operations.cpp).

## Kiedy używać `std::list`

`std::list` ma sens, gdy:

- często wstawiasz elementy w środku kolekcji,
- często usuwasz elementy ze środka,
- nie potrzebujesz dostępu po indeksie.

`std::vector` jest zwykle lepszy, gdy:

- często przechodzisz po wszystkich elementach,
- potrzebujesz dostępu po indeksie,
- dodajesz głównie na końcu.

Na początku wybieraj `std::vector`, dopóki problem wyraźnie nie pasuje do listy.

## Częste błędy

### `top`, `front` albo `back` na pustym kontenerze

Niepoprawnie:

```cpp
std::stack<int> stos;
std::cout << stos.top() << std::endl;
```

Poprawnie:

```cpp
if (!stos.empty())
{
    std::cout << stos.top() << std::endl;
}
```

### Oczekiwanie dostępu po indeksie w `std::list`

`std::list` nie obsługuje wygodnego dostępu:

```cpp
// lista[0] // tak nie dziala
```

Jeśli potrzebujesz indeksów, zwykle wybierz `std::vector`.

### Mylenie `pop` ze zwracaniem wartości

`pop()` usuwa element, ale go nie zwraca.

Najpierw odczytaj element przez `top()` albo `front()`, potem wywołaj `pop()`.

## Zadania

1. Utwórz `std::stack<std::string>` jako historię operacji. Dodaj trzy operacje i zdejmij je w kolejności cofania.
2. Utwórz `std::queue<std::string>` jako kolejkę zgłoszeń. Dodaj trzy zgłoszenia i obsłuż je w kolejności przyjścia.
3. Utwórz `std::list<int>`, dodaj elementy na początek i koniec, a następnie wypisz listę.
4. Wstaw wartość `42` przed pierwszą wartością `16` w liście.
5. Napisz komentarz w kodzie, kiedy wybrałbyś `std::list`, a kiedy `std::vector`.

## Kryteria zaliczenia

Program powinien:

- używać nagłówków `<stack>`, `<queue>` albo `<list>`,
- sprawdzać `empty()` przed odczytem ze stosu lub kolejki,
- poprawnie odróżniać LIFO od FIFO,
- przechodzić po `std::list` pętlą zakresową,
- umieć uzasadnić wybór struktury danych,
- kompilować się bez błędów.

## Pytania kontrolne

1. Co oznacza LIFO?
2. Co oznacza FIFO?
3. Czym różni się `top()` od `front()`?
4. Dlaczego `pop()` nie zwraca usuwanego elementu?
5. Kiedy `std::list` może być lepsza niż `std::vector`?
