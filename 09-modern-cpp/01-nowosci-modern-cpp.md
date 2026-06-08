# 01 - Nowości modern C++

## Cel lekcji

Celem lekcji jest uporządkowanie najważniejszych elementów współczesnego C++.
Student powinien rozpoznać konstrukcje wprowadzone od C++11 wzwyż i rozumieć,
które z nich poprawiają bezpieczeństwo, czytelność oraz organizację kodu.

## Wymagania wstępne

Przed rozpoczęciem lekcji warto znać:

- funkcje i klasy,
- kontenery STL,
- podstawową kompilację programu C++,
- rozdzielanie kodu na mniejsze fragmenty.

## Co oznacza modern C++

Modern C++ to styl pisania kodu korzystający z nowszych standardów języka,
szczególnie C++11, C++14, C++17 i nowszych. Nie chodzi tylko o nowe słowa
kluczowe. Ważniejsza jest zmiana stylu:

- mniej ręcznego zarządzania pamięcią,
- więcej typów i konstrukcji, które wyrażają intencję,
- krótszy i czytelniejszy kod,
- większe wykorzystanie biblioteki standardowej.

## Przykłady zmian

### Inicjalizacja klamrowa

```cpp
int value{10};
std::vector<int> numbers{1, 2, 3};
```

Klamry dają spójny zapis inicjalizacji dla prostych typów, obiektów i
kontenerów.

### `auto`

```cpp
auto count = numbers.size();
```

`auto` pozwala kompilatorowi wywnioskować typ. Należy go używać tam, gdzie typ
jest oczywisty z prawej strony przypisania albo bardzo długi.

### `nullptr`

```cpp
int* pointer = nullptr;
```

`nullptr` zastępuje starsze użycie `NULL` albo `0` jako pustego wskaźnika.

### Pętla zakresowa

```cpp
for (const auto& number : numbers) {
    std::cout << number << '\n';
}
```

Pętla zakresowa zmniejsza liczbę błędów z indeksami i dobrze pasuje do
kontenerów STL.

### `enum class`

```cpp
enum class Status {
    Active,
    Inactive
};
```

`enum class` ogranicza przypadkowe mieszanie wartości wyliczeniowych z liczbami
całkowitymi.

### Lambda

```cpp
auto isEven = [](int value) {
    return value % 2 == 0;
};
```

Lambda pozwala zdefiniować krótką funkcję w miejscu użycia. Jest szczególnie
przydatna z algorytmami STL.

### Structured bindings

```cpp
auto [name, score] = result;
```

Structured bindings z C++17 ułatwiają rozpakowanie par, krotek i prostych
struktur.

## Co zostanie omówione dalej

Ten segment rozwija wybrane tematy:

- `auto`, `nullptr` i inicjalizację,
- lambdy i algorytmy,
- `enum class`, `override` i aliasy typów,
- podstawy semantyki przenoszenia,
- przestrzenie nazw,
- moduły jako temat C++20,
- podstawy wielowątkowości.

## Kompletny przykład

Przykład znajduje się w pliku
[`examples/modern_cpp_overview.cpp`](examples/modern_cpp_overview.cpp).

Kompilacja:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic examples/modern_cpp_overview.cpp -o modern_cpp_overview
./modern_cpp_overview
```

## Zadania do wykonania

1. Skompiluj i uruchom przykład.
2. Dodaj do wektora kolejną osobę i sprawdź wynik sortowania.
3. Zmień lambdę filtrującą tak, aby wybierała osoby z wynikiem co najmniej `70`.
4. Dodaj nowe pole do struktury `Person` i wypisz je w raporcie.
5. Zastąp jeden jawny typ zmiennej przez `auto` tylko tam, gdzie nie pogarsza to
   czytelności.

## Kryteria zaliczenia

Student zalicza lekcję, jeśli potrafi:

- wyjaśnić ogólnie, czym jest modern C++,
- wskazać przykłady konstrukcji z C++11 i C++17,
- użyć inicjalizacji klamrowej,
- zastosować pętlę zakresową,
- rozpoznać lambdę,
- skompilować przykład w standardzie C++17.
