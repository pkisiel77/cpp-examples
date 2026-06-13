# 02 - `auto`, `nullptr` i inicjalizacja

## Cel lekcji

Celem lekcji jest praktyczne użycie trzech częstych elementów modern C++:
`auto`, `nullptr` oraz inicjalizacji klamrowej. Student powinien rozumieć, kiedy
te konstrukcje poprawiają czytelność i bezpieczeństwo kodu.

## Wymagania wstępne

Przed rozpoczęciem lekcji warto znać:

- typy podstawowe,
- wskaźniki,
- struktury,
- `std::vector`,
- pętlę zakresową.

## Krótka teoria

### `auto`

`auto` pozwala kompilatorowi wywnioskować typ zmiennej z wartości po prawej
stronie przypisania.

```cpp
auto age = 20;
auto name = std::string{"Anna"};
```

`auto` jest przydatne, gdy typ jest oczywisty albo długi:

```cpp
auto it = students.begin();
```

Nie należy używać `auto`, jeśli ukrycie typu utrudnia zrozumienie kodu:

```cpp
auto value = loadData();
```

Jeśli nazwa funkcji nie mówi jasno, co zwraca, jawny typ może być lepszy.

### `auto` i referencje

W pętli po większych obiektach często używamy referencji:

```cpp
for (const auto& student : students) {
    std::cout << student.name << '\n';
}
```

`const auto&` oznacza:

- nie kopiuj elementu,
- nie pozwalaj go zmienić,
- dobierz typ automatycznie.

## Przykład kodu: `nullptr`

`nullptr` oznacza pusty wskaźnik:

```cpp
int* pointer = nullptr;
```

W modern C++ używamy `nullptr` zamiast `NULL` albo `0`, ponieważ `nullptr` ma
specjalny typ i lepiej wyraża intencję.

Przykład:

```cpp
Student* selected = nullptr;
```

Taki zapis jasno mówi, że wskaźnik na razie nie wskazuje na żaden obiekt.

### Sprawdzanie wskaźnika

Przed użyciem wskaźnika trzeba sprawdzić, czy nie jest pusty:

```cpp
if (selected != nullptr) {
    std::cout << selected->name << '\n';
}
```

W prostych programach edukacyjnych wskaźniki nadal są użyteczne do pokazania
mechaniki języka. W kodzie produkcyjnym często lepiej wybrać referencje albo
inteligentne wskaźniki.

## Przykład kodu: inicjalizacja klamrowa

Klamry pozwalają inicjalizować różne typy w spójny sposób:

```cpp
int points{80};
std::string name{"Anna"};
std::vector<int> values{1, 2, 3};
```

Dla struktur zapis jest czytelny:

```cpp
Student student{"Anna", 82};
```

Klamry pomagają ograniczyć część przypadkowych konwersji zawężających, np.
przypisanie liczby zmiennoprzecinkowej do `int`.

## Przykład referencyjny

Przykład znajduje się w pliku
[`examples/auto_nullptr_initialization.cpp`](examples/auto_nullptr_initialization.cpp).

Kompilacja:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic examples/auto_nullptr_initialization.cpp -o auto_nullptr_initialization
./auto_nullptr_initialization
```

## Zadania do wykonania

1. Skompiluj i uruchom przykład.
2. Dodaj kolejnego studenta do wektora.
3. Zmień warunek wyboru najlepszego studenta na wynik co najmniej `90`.
4. Zamień jedną zmienną z jawnym typem na `auto`, jeśli nie pogorszy to
   czytelności.
5. Dodaj przykład wskaźnika ustawionego na `nullptr` i sprawdzenie przed użyciem.

## Kryteria zaliczenia

Student zalicza lekcję, jeśli potrafi:

- użyć `auto` w prostym i czytelnym miejscu,
- wyjaśnić, kiedy `auto` może pogorszyć czytelność,
- użyć `const auto&` w pętli zakresowej,
- użyć `nullptr` jako pustego wskaźnika,
- sprawdzić wskaźnik przed dereferencją,
- zastosować inicjalizację klamrową dla typu prostego, struktury i wektora.
