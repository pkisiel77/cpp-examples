# 04 - `enum class`, `override` i aliasy

## Cel lekcji

Celem lekcji jest pokazanie konstrukcji, które pomagają pisać czytelniejsze i
bezpieczniejsze API: `enum class`, aliasy typów, `override`, `= default` oraz
`= delete`.

## Wymagania wstępne

Przed rozpoczęciem lekcji warto znać:

- klasy,
- dziedziczenie,
- metody wirtualne,
- podstawy typów wyliczeniowych,
- konstruktory.

## Krótka teoria

### `enum class`

Zwykły `enum` łatwo miesza się z liczbami całkowitymi. `enum class` tworzy
silniej oddzielony typ.

```cpp
enum class Priority {
    Low,
    Normal,
    High
};
```

Wartości używamy z nazwą typu:

```cpp
Priority priority = Priority::High;
```

Dzięki temu kod jest czytelniejszy i trudniej przypadkowo przekazać złą wartość.

### Aliasy typów

Alias pozwala nadać czytelną nazwę istniejącemu typowi:

```cpp
using UserId = std::string;
using MessageCount = int;
```

Alias nie tworzy nowego, odrębnego typu. Poprawia jednak czytelność intencji.

```cpp
void send(UserId userId);
```

Taki zapis jest bardziej opisowy niż samo `std::string`.

## Przykład kodu: `override`

`override` informuje kompilator, że metoda ma nadpisywać metodę wirtualną z
klasy bazowej.

```cpp
class EmailNotifier : public Notifier {
public:
    void send(const Message& message) const override;
};
```

Jeśli popełnimy literówkę w nazwie metody albo zmienimy typ parametru,
kompilator zgłosi błąd. Bez `override` łatwo przypadkowo utworzyć nową metodę
zamiast nadpisać istniejącą.

### `= default`

`= default` mówi, że chcemy domyślne zachowanie wygenerowane przez kompilator.

```cpp
class Message {
public:
    Message() = default;
};
```

Taki zapis jest przydatny, gdy chcemy jawnie pokazać intencję.

### `= delete`

`= delete` blokuje wybraną operację.

```cpp
class Notifier {
public:
    Notifier(const Notifier&) = delete;
    Notifier& operator=(const Notifier&) = delete;
};
```

Można tak zabronić kopiowania obiektu, jeśli kopiowanie nie ma sensu albo
mogłoby prowadzić do błędów.

## Przykład referencyjny

Przykład znajduje się w pliku
[`examples/strong_types_api.cpp`](examples/strong_types_api.cpp).

Kompilacja:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic examples/strong_types_api.cpp -o strong_types_api
./strong_types_api
```

## Zadania do wykonania

1. Skompiluj i uruchom przykład.
2. Dodaj wartość `Critical` do `Priority` i obsłuż ją w funkcji wypisującej.
3. Dodaj alias `Subject` dla `std::string`.
4. Dodaj klasę `SmsNotifier`, która dziedziczy po `Notifier`.
5. Celowo usuń `override`, zmień sygnaturę metody i sprawdź, jak zmienia się
   zachowanie kompilatora po ponownym dodaniu `override`.

## Kryteria zaliczenia

Student zalicza lekcję, jeśli potrafi:

- zdefiniować i użyć `enum class`,
- wyjaśnić przewagę `enum class` nad prostym `enum`,
- utworzyć alias typu przez `using`,
- użyć `override` przy metodzie wirtualnej,
- wyjaśnić sens `= default`,
- zablokować kopiowanie przez `= delete`.
