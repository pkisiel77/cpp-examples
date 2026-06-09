# 06 - Przestrzenie nazw

## Cel lekcji

Celem lekcji jest zrozumienie, jak przestrzenie nazw pomagają organizować kod i
unikać konfliktów nazw. Student powinien umieć zdefiniować własną przestrzeń
nazw, użyć operatora zakresu `::` oraz świadomie korzystać z deklaracji `using`.

## Wymagania wstępne

Przed rozpoczęciem lekcji warto znać:

- funkcje,
- klasy albo struktury,
- podział programu na moduły tematyczne,
- podstawowe użycie `std::`.

## Po co są przestrzenie nazw

W większym programie różne części kodu mogą używać tych samych nazw funkcji,
typów albo stałych. Przestrzeń nazw grupuje powiązane elementy i zmniejsza
ryzyko konfliktu.

```cpp
namespace math {
    int add(int a, int b);
}
```

Funkcję wywołujemy przez operator zakresu:

```cpp
int result = math::add(2, 3);
```

## Operator `::`

Operator `::` wskazuje, z której przestrzeni nazw pochodzi element.

```cpp
std::cout << "Text\n";
```

W tym przykładzie `cout` pochodzi z przestrzeni nazw `std`.

Własny przykład:

```cpp
reporting::printSummary();
```

Taki zapis jest dłuższy, ale bardzo czytelny.

## Zagnieżdżone przestrzenie nazw

W C++17 można zapisać zagnieżdżoną przestrzeń nazw krótko:

```cpp
namespace app::reports {
    void print();
}
```

To odpowiada starszemu zapisowi:

```cpp
namespace app {
namespace reports {
    void print();
}
}
```

## `using`

Deklaracja `using` pozwala skrócić nazwę wybranego elementu:

```cpp
using app::reports::print;

print();
```

To jest zwykle bezpieczniejsze niż:

```cpp
using namespace app::reports;
```

Szerokie `using namespace` może wprowadzić wiele nazw naraz i utrudnić
rozpoznanie, skąd pochodzi dana funkcja.

## `using namespace std`

W krótkich przykładach edukacyjnych czasem spotyka się:

```cpp
using namespace std;
```

W materiałach tego kursu preferujemy zapis z `std::`, ponieważ uczy on, skąd
pochodzą elementy biblioteki standardowej i zmniejsza ryzyko konfliktu nazw.

## Kompletny przykład

Przykład znajduje się w pliku
[`examples/namespaces.cpp`](examples/namespaces.cpp).

Kompilacja:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic examples/namespaces.cpp -o namespaces
./namespaces
```

## Zadania do wykonania

1. Skompiluj i uruchom przykład.
2. Dodaj przestrzeń nazw `app::users` z funkcją `printUser`.
3. Dodaj funkcję `format` w dwóch różnych przestrzeniach nazw i wywołaj obie
   przez operator `::`.
4. Zastąp jedno długie wywołanie deklaracją `using`.
5. Usuń `std::` z jednego miejsca i sprawdź, jaki błąd zgłosi kompilator.

## Kryteria zaliczenia

Student zalicza lekcję, jeśli potrafi:

- zdefiniować własną przestrzeń nazw,
- wywołać funkcję przez operator `::`,
- użyć zagnieżdżonej przestrzeni nazw,
- wyjaśnić, do czego służy `std::`,
- użyć deklaracji `using` dla pojedynczej nazwy,
- wyjaśnić ryzyko szerokiego `using namespace`.
