# 03 - Typy, zmienne i operatory

## Cel lekcji

Celem lekcji jest zrozumienie, czym są typy danych, jak deklarować zmienne i jak wykonywać podstawowe operacje arytmetyczne w C++.

## Wymagania wstępne

Student powinien znać materiał z lekcji:

- [01-pierwszy-program.md](01-pierwszy-program.md),
- [02-wejscie-wyjscie.md](02-wejscie-wyjscie.md).

## Typ danych

Typ danych określa, jakiego rodzaju wartość może przechowywać zmienna.

Najczęściej używane typy na początku nauki:

| Typ | Przykład wartości | Zastosowanie |
| --- | --- | --- |
| `int` | `10`, `-4`, `0` | liczby całkowite |
| `double` | `3.14`, `-0.5` | liczby zmiennoprzecinkowe |
| `char` | `'A'` | pojedynczy znak |
| `bool` | `true`, `false` | wartość logiczna |
| `std::string` | `"Ala"` | tekst |

Typ `std::string` wymaga dołączenia biblioteki `string`:

```cpp
#include <string>
```

## Zmienna

Zmienna to nazwane miejsce w pamięci programu, w którym przechowujemy wartość.

```cpp
int wiek = 20;
double wzrost = 1.75;
std::string imie = "Ala";
```

Deklaracja zmiennej składa się z typu i nazwy:

```cpp
int liczba;
```

Inicjalizacja oznacza nadanie wartości początkowej:

```cpp
int liczba = 5;
```

## Nazwy zmiennych

Dobra nazwa zmiennej powinna opisywać jej znaczenie.

```cpp
int liczbaStudentow = 24;
double temperatura = 21.5;
bool czyZalogowany = false;
```

Unikamy nazw, które nic nie mówią:

```cpp
int x;
double a;
```

Krótkie nazwy są dopuszczalne w prostych wzorach matematycznych, ale w programach użytkowych lepiej stosować nazwy opisowe.

## Operatory arytmetyczne

Podstawowe operatory:

| Operator | Znaczenie | Przykład |
| --- | --- | --- |
| `+` | dodawanie | `a + b` |
| `-` | odejmowanie | `a - b` |
| `*` | mnożenie | `a * b` |
| `/` | dzielenie | `a / b` |
| `%` | reszta z dzielenia | `a % b` |

Operator `%` działa dla liczb całkowitych.

```cpp
int reszta = 10 % 3; // wynik: 1
```

## Dzielenie całkowite i zmiennoprzecinkowe

W C++ wynik dzielenia zależy od typów operandów.

```cpp
int a = 5;
int b = 2;
std::cout << a / b << std::endl; // wynik: 2
```

Ponieważ `a` i `b` są typu `int`, wynik też jest całkowity.

```cpp
double x = 5.0;
double y = 2.0;
std::cout << x / y << std::endl; // wynik: 2.5
```

Jeżeli potrzebujemy wyniku zmiennoprzecinkowego, co najmniej jedna wartość powinna być typu `double`.

## Konwersja typu

Czasem trzeba jawnie potraktować wartość jako inny typ.

```cpp
int a = 5;
int b = 2;

double wynik = static_cast<double>(a) / b;
std::cout << wynik << std::endl; // wynik: 2.5
```

`static_cast<double>(a)` tworzy wartość `a` potraktowaną jako `double`.

## Przykład: podstawowe typy

```cpp
#include <iostream>
#include <string>

int main()
{
    int wiek = 20;
    double wzrost = 1.75;
    char ocena = 'A';
    bool aktywny = true;
    std::string imie = "Ala";

    std::cout << "Imie: " << imie << std::endl;
    std::cout << "Wiek: " << wiek << std::endl;
    std::cout << "Wzrost: " << wzrost << std::endl;
    std::cout << "Ocena: " << ocena << std::endl;
    std::cout << "Aktywny: " << aktywny << std::endl;

    return 0;
}
```

Ten przykład znajduje się w pliku [examples/basic_types.cpp](examples/basic_types.cpp).

## Przykład: kalkulator sumy

```cpp
#include <iostream>

int main()
{
    int a;
    int b;

    std::cout << "Podaj pierwsza liczbe: ";
    std::cin >> a;

    std::cout << "Podaj druga liczbe: ";
    std::cin >> b;

    std::cout << "Suma: " << a + b << std::endl;
    return 0;
}
```

Ten przykład znajduje się w pliku [examples/sum_two_numbers.cpp](examples/sum_two_numbers.cpp).

## Biblioteka `cmath`

Do wybranych obliczeń matematycznych używamy biblioteki `cmath`.

```cpp
#include <cmath>
```

Przykładowe funkcje:

- `std::sqrt(x)` - pierwiastek kwadratowy,
- `std::pow(a, b)` - potęga `a` do `b`,
- `std::sin(x)` - sinus,
- `std::cos(x)` - cosinus.

Przykład:

```cpp
#include <cmath>
#include <iostream>

int main()
{
    double wynik = std::sqrt(25.0);
    std::cout << wynik << std::endl;
    return 0;
}
```

Ten przykład znajduje się w pliku [examples/math_functions.cpp](examples/math_functions.cpp).

## Zadania

1. Zadeklaruj zmienne: imię, wiek, wzrost i informację, czy student jest aktywny. Wypisz je na ekran.
2. Napisz program, który wczytuje dwie liczby całkowite i wypisuje ich sumę, różnicę oraz iloczyn.
3. Napisz program, który wczytuje dwie liczby typu `double` i wypisuje wynik dzielenia.
4. Napisz program, który wczytuje liczbę całkowitą i wypisuje resztę z dzielenia przez `2`.
5. Napisz program, który oblicza pole prostokąta na podstawie boków podanych przez użytkownika.
6. Napisz program, który oblicza pierwiastek z liczby podanej przez użytkownika.

## Kryteria zaliczenia

Program powinien:

- używać poprawnych typów danych,
- mieć czytelne nazwy zmiennych,
- kompilować się bez błędów,
- poprawnie wczytywać dane od użytkownika,
- wypisywać wynik z opisem,
- stosować `double`, gdy wynik może mieć część ułamkową.

## Pytania kontrolne

1. Czym różni się `int` od `double`?
2. Do czego służy typ `bool`?
3. Dlaczego `5 / 2` daje inny wynik niż `5.0 / 2.0`?
4. Kiedy można użyć operatora `%`?
5. Do czego służy `static_cast<double>`?
