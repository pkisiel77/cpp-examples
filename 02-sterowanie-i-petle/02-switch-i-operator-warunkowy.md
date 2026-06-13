# 02 - `switch` i operator warunkowy

## Cel lekcji

Celem lekcji jest poznanie dwóch dodatkowych sposobów zapisu decyzji w programie: instrukcji `switch` oraz operatora warunkowego `?:`.

## Wymagania wstępne

Student powinien znać materiał z lekcji [01-instrukcje-warunkowe.md](01-instrukcje-warunkowe.md): `if`, `else`, operatory porównania i operatory logiczne.

## Krótka teoria

### Instrukcja `switch`

Instrukcja `switch` pozwala wybrać jeden z wielu przypadków na podstawie wartości jednej zmiennej lub wyrażenia.

Najczęściej używamy jej, gdy porównujemy jedną wartość z kilkoma stałymi.

```cpp
switch (wybor)
{
    case 1:
        std::cout << "Wybrano 1" << std::endl;
        break;
    case 2:
        std::cout << "Wybrano 2" << std::endl;
        break;
    default:
        std::cout << "Nieznana opcja" << std::endl;
        break;
}
```

Znaczenie elementów:

- `switch (wybor)` sprawdza wartość zmiennej `wybor`,
- `case` oznacza konkretny przypadek,
- `break` kończy wykonywanie instrukcji `switch`,
- `default` obsługuje sytuację, gdy żaden `case` nie pasuje.

## Przykład kodu: proste menu

```cpp
#include <iostream>

int main()
{
    int wybor;

    std::cout << "1. Nowa gra\n";
    std::cout << "2. Wczytaj gre\n";
    std::cout << "3. Wyjscie\n";
    std::cout << "Wybor: ";
    std::cin >> wybor;

    switch (wybor)
    {
        case 1:
            std::cout << "Rozpoczynam nowa gre" << std::endl;
            break;
        case 2:
            std::cout << "Wczytuje gre" << std::endl;
            break;
        case 3:
            std::cout << "Koniec programu" << std::endl;
            break;
        default:
            std::cout << "Nieznana opcja" << std::endl;
            break;
    }

    return 0;
}
```

Ten przykład znajduje się w pliku [examples/switch_menu.cpp](examples/switch_menu.cpp).

### Dlaczego `break` jest ważny

Jeżeli pominiemy `break`, program przejdzie do kolejnego przypadku. Takie zachowanie nazywa się przejściem dalej przez przypadki.

```cpp
switch (wybor)
{
    case 1:
        std::cout << "Jeden" << std::endl;
    case 2:
        std::cout << "Dwa" << std::endl;
        break;
}
```

Dla `wybor == 1` program wypisze zarówno `Jeden`, jak i `Dwa`.

Czasem jest to celowe, ale na początku nauki zwykle oznacza błąd.

### Kiedy użyć `switch`, a kiedy `if`

`switch` jest dobrym wyborem, gdy:

- sprawdzamy jedną zmienną,
- porównujemy ją z konkretnymi wartościami,
- przypadków jest kilka.

`if` jest lepszy, gdy:

- warunek dotyczy przedziału, np. `x >= 10 && x <= 20`,
- warunek łączy kilka zmiennych,
- potrzebne są operatory logiczne,
- sprawdzamy wartości zmiennoprzecinkowe.

### Operator warunkowy `?:`

Operator warunkowy pozwala zapisać prostą decyzję w jednym wyrażeniu.

Składnia:

```cpp
warunek ? wartosc_gdy_prawda : wartosc_gdy_falsz
```

Przykład:

```cpp
int a = 10;
int b = 20;

int wieksza = (a > b) ? a : b;
```

Jeżeli `a > b`, zmienna `wieksza` otrzyma wartość `a`. W przeciwnym razie otrzyma wartość `b`.

## Przykład kodu: parzystość liczby

```cpp
#include <iostream>
#include <string>

int main()
{
    int liczba;

    std::cout << "Podaj liczbe: ";
    std::cin >> liczba;

    std::string wynik = (liczba % 2 == 0) ? "parzysta" : "nieparzysta";
    std::cout << "Liczba jest " << wynik << std::endl;

    return 0;
}
```

Ten przykład znajduje się w pliku [examples/ternary_even_odd.cpp](examples/ternary_even_odd.cpp).

## Zadania do wykonania

1. Napisz program z menu kalkulatora:
   - `1` - dodawanie,
   - `2` - odejmowanie,
   - `3` - mnożenie,
   - `4` - dzielenie.
2. Napisz program, który dla numeru dnia tygodnia od `1` do `7` wypisuje nazwę dnia.
3. Napisz program, który dla oceny od `1` do `6` wypisuje komunikat tekstowy, np. `bardzo dobry`.
4. Napisz program, który przy pomocy operatora `?:` wybiera większą z dwóch liczb.
5. Napisz program, który przy pomocy operatora `?:` wypisuje, czy użytkownik jest pełnoletni.

## Ćwiczenia dodatkowe

1. Dodaj do menu nową opcję i obsłuż ją w `switch`.
2. Zamień prosty `if else` na operator warunkowy tam, gdzie poprawia czytelność.
3. Dodaj przypadek `default` z czytelnym komunikatem o błędnym wyborze.

## Kryteria zaliczenia

Program powinien:

- poprawnie używać `switch`, `case`, `break` i `default`,
- używać `switch` tylko wtedy, gdy pasuje do problemu,
- stosować operator `?:` tylko do krótkich, czytelnych decyzji,
- kompilować się bez błędów,
- obsługiwać niepoprawny wybór użytkownika.

## Pytania kontrolne

1. Do czego służy `default` w instrukcji `switch`?
2. Co się stanie, gdy pominiemy `break`?
3. Kiedy `switch` jest czytelniejszy niż `if`?
4. Jak działa operator `?:`?
5. Dlaczego operatora `?:` nie należy nadużywać?
