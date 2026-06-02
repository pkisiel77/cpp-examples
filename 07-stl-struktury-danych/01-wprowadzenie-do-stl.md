# 01 - Wprowadzenie do STL

## Cel lekcji

Celem lekcji jest zrozumienie, czym jest STL, po co używamy kontenerów standardowych i jak wstępnie dobrać kontener do problemu.

## Wymagania wstępne

Student powinien znać:

- tablice i pętle z segmentu [03-funkcje-tablice-napisy](../03-funkcje-tablice-napisy/README.md),
- klasy i obiekty z segmentu [06-oop](../06-oop/README.md),
- podstawowe operacje wejścia i wyjścia.

## Czym jest STL

STL to część biblioteki standardowej C++, która dostarcza gotowe narzędzia do pracy z danymi.

W tym segmencie najważniejsze będą:

- kontenery, czyli gotowe struktury do przechowywania danych,
- iteracja po kontenerach,
- algorytmy, np. sortowanie i wyszukiwanie,
- dobór kontenera do problemu.

Zamiast samodzielnie pisać tablicę dynamiczną, kolejkę albo mapowanie klucz-wartość, zwykle lepiej użyć gotowego kontenera z biblioteki standardowej.

## Kontener

Kontener to obiekt przechowujący wiele elementów.

Przykład:

```cpp
std::vector<int> liczby = {10, 20, 30};
```

`std::vector<int>` przechowuje wiele liczb typu `int`.

Do użycia `std::vector` potrzebny jest nagłówek:

```cpp
#include <vector>
```

## Najważniejsze kontenery w tym segmencie

### `std::vector`

`std::vector` jest listą elementów w ciągłej pamięci.

Dobry wybór, gdy:

- potrzebujesz listy elementów,
- często dodajesz elementy na końcu,
- chcesz szybko dostać się do elementu po indeksie,
- nie znasz z góry liczby elementów.

### `std::map`

`std::map` przechowuje pary klucz-wartość.

Dobry wybór, gdy:

- wyszukujesz dane po unikalnym kluczu,
- chcesz powiązać nazwę z wartością,
- np. tytuł filmu z oceną albo identyfikator pracownika z wynagrodzeniem.

### `std::stack`

`std::stack` to stos. Działa według zasady: ostatni dodany element wychodzi pierwszy.

Dobry wybór, gdy:

- obsługujesz cofanie operacji,
- analizujesz nawiasy,
- potrzebujesz struktury LIFO.

### `std::queue`

`std::queue` to kolejka. Działa według zasady: pierwszy dodany element wychodzi pierwszy.

Dobry wybór, gdy:

- obsługujesz kolejkę zadań,
- modelujesz klientów w kolejce,
- przetwarzasz zgłoszenia w kolejności przyjścia.

### `std::list`

`std::list` to lista dwukierunkowa.

Dobry wybór, gdy:

- często wstawiasz lub usuwasz elementy ze środka,
- nie potrzebujesz szybkiego dostępu po indeksie.

W praktyce na początku częściej używa się `std::vector`, a `std::list` wybiera dopiero wtedy, gdy problem naprawdę tego wymaga.

## Przykład kilku kontenerów

Pełny przykład znajduje się w pliku [examples/stl_containers_overview.cpp](examples/stl_containers_overview.cpp).

Pokazuje on:

- `std::vector` jako listę liczb,
- `std::map` jako oceny filmów,
- `std::queue` jako kolejkę zadań,
- `std::stack` jako historię cofania.

## Dobór kontenera

Dobór kontenera zaczynamy od pytania: jak będę używać danych?

Jeśli chcesz przechowywać listę:

```cpp
std::vector<std::string> imiona;
```

Jeśli chcesz szukać po kluczu:

```cpp
std::map<std::string, double> ocenyFilmow;
```

Jeśli chcesz obsługiwać kolejkę:

```cpp
std::queue<std::string> zadania;
```

Jeśli chcesz zdejmować ostatnio dodany element:

```cpp
std::stack<std::string> historia;
```

Pełny przykład znajduje się w pliku [examples/choose_container.cpp](examples/choose_container.cpp).

## Pętla zakresowa

Po kontenerach często przechodzimy pętlą zakresową.

```cpp
for (const auto& liczba : liczby)
{
    std::cout << liczba << std::endl;
}
```

`const auto&` oznacza, że:

- typ elementu zostanie rozpoznany automatycznie,
- element nie będzie kopiowany,
- element nie zostanie zmieniony.

Na początku można też pisać typ jawnie.

```cpp
for (const int& liczba : liczby)
{
    std::cout << liczba << std::endl;
}
```

## Częste błędy

### Ręczne pisanie struktury, gdy istnieje kontener

Jeśli potrzebujesz listy elementów, zacznij od `std::vector`, a nie od ręcznej tablicy dynamicznej.

### Zły kontener do problemu

Jeśli często szukasz danych po nazwie, `std::vector` może wymagać przeglądania wszystkich elementów. `std::map` będzie bardziej naturalny.

### Kopiowanie dużych elementów w pętli

Mniej korzystnie:

```cpp
for (auto element : elementy)
{
}
```

Lepiej dla większych obiektów:

```cpp
for (const auto& element : elementy)
{
}
```

## Zadania

1. Wypisz trzy przykłady problemów, dla których dobrym wyborem będzie `std::vector`.
2. Wypisz trzy przykłady problemów, dla których dobrym wyborem będzie `std::map`.
3. Napisz program, który przechowuje imiona w `std::vector` i wypisuje je pętlą zakresową.
4. Napisz program, który przechowuje oceny filmów w `std::map`.
5. Napisz krótki komentarz w kodzie: czym różni się `std::stack` od `std::queue`.

## Kryteria zaliczenia

Program powinien:

- używać właściwych nagłówków,
- tworzyć co najmniej jeden kontener STL,
- dodawać elementy do kontenera,
- przechodzić po kontenerze pętlą,
- umieć uzasadnić wybór kontenera,
- kompilować się bez błędów.

## Pytania kontrolne

1. Czym jest kontener?
2. Kiedy warto użyć `std::vector`?
3. Kiedy warto użyć `std::map`?
4. Czym różni się `std::stack` od `std::queue`?
5. Po co używamy `const auto&` w pętli zakresowej?
