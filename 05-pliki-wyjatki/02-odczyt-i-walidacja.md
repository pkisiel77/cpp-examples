# 02 - Odczyt i walidacja

## Cel lekcji

Celem lekcji jest nauczenie się sprawdzania, czy odczyt z pliku lub wejścia użytkownika rzeczywiście się udał oraz czy wczytane dane mają oczekiwaną postać.

## Wymagania wstępne

Student powinien znać:

- instrukcje warunkowe z segmentu [02-sterowanie-i-petle](../02-sterowanie-i-petle/README.md),
- pętle z segmentu [02-sterowanie-i-petle](../02-sterowanie-i-petle/README.md),
- funkcje z segmentu [03-funkcje-tablice-napisy](../03-funkcje-tablice-napisy/README.md),
- podstawowy zapis i odczyt plików z lekcji [01-pliki-tekstowe.md](01-pliki-tekstowe.md).

## Krótka teoria

### Czym jest walidacja

Walidacja to sprawdzenie, czy dane spełniają wymagania programu.

Przykłady wymagań:

- liczba musi być większa od `0`,
- wiek musi być w sensownym zakresie,
- linia w pliku nie może być pusta,
- plik musi istnieć,
- w pliku powinny znajdować się liczby, a nie dowolny tekst.

Program nie powinien zakładać, że dane zawsze są poprawne.

## Przykład kodu: sprawdzanie otwarcia pliku

Przed odczytem trzeba sprawdzić, czy plik został poprawnie otwarty.

```cpp
std::ifstream plik("liczby.txt");

if (!plik)
{
    std::cout << "Nie mozna otworzyc pliku" << std::endl;
    return 1;
}
```

Pełny przykład znajduje się w pliku [examples/missing_file_check.cpp](examples/missing_file_check.cpp).

## Przykład kodu: sprawdzanie odczytu liczby

Operator `>>` zwraca strumień. Strumień można sprawdzić w warunku.

```cpp
int liczba = 0;

if (std::cin >> liczba)
{
    std::cout << "Wczytano: " << liczba << std::endl;
}
else
{
    std::cout << "To nie jest poprawna liczba" << std::endl;
}
```

Ten sam mechanizm działa dla plików.

```cpp
std::ifstream plik("liczby.txt");
int liczba = 0;

while (plik >> liczba)
{
    std::cout << liczba << std::endl;
}
```

Pełny przykład znajduje się w pliku [examples/read_numbers_with_validation.cpp](examples/read_numbers_with_validation.cpp).

### Walidacja zakresu

Poprawny typ danych nie zawsze oznacza poprawną wartość.

```cpp
if (wiek < 0 || wiek > 130)
{
    std::cout << "Niepoprawny wiek" << std::endl;
}
```

Najpierw sprawdzamy, czy odczyt się udał. Dopiero potem sprawdzamy sens wartości.

```cpp
int wiek = 0;

if (!(std::cin >> wiek))
{
    std::cout << "Wiek musi byc liczba" << std::endl;
}
else if (wiek < 0 || wiek > 130)
{
    std::cout << "Wiek poza zakresem" << std::endl;
}
else
{
    std::cout << "Wiek poprawny" << std::endl;
}
```

## Przykład kodu: odczyt linii i parsowanie

Jeśli plik może zawierać błędne linie, wygodnie jest czytać go liniami, a potem analizować każdą linię osobno.

```cpp
std::string linia;

while (std::getline(plik, linia))
{
    std::istringstream strumienLinii(linia);
    int liczba = 0;

    if (strumienLinii >> liczba)
    {
        std::cout << "Liczba: " << liczba << std::endl;
    }
    else
    {
        std::cout << "Pominieto bledna linie" << std::endl;
    }
}
```

Do `std::istringstream` potrzebny jest nagłówek:

```cpp
#include <sstream>
```

Pełny przykład znajduje się w pliku [examples/validate_lines.cpp](examples/validate_lines.cpp).

### Stan strumienia

Strumień może być w różnych stanach:

- poprawny odczyt,
- koniec pliku,
- błąd formatu danych,
- błąd otwarcia lub odczytu.

Na tym etapie najważniejsze są dwa wzorce:

```cpp
if (!plik)
{
    // plik nie zostal otwarty albo strumien jest w stanie bledu
}
```

oraz:

```cpp
while (plik >> liczba)
{
    // wykonuje sie tylko dla poprawnie odczytanych liczb
}
```

## Typowe błędy

### Użycie wartości po nieudanym odczycie

Niepoprawnie:

```cpp
int liczba;
std::cin >> liczba;
std::cout << liczba << std::endl;
```

Jeśli użytkownik wpisze tekst zamiast liczby, program będzie pracował na niepoprawnych danych.

Poprawnie:

```cpp
int liczba = 0;

if (std::cin >> liczba)
{
    std::cout << liczba << std::endl;
}
else
{
    std::cout << "Niepoprawne dane" << std::endl;
}
```

### Sprawdzenie zakresu przed sprawdzeniem typu

Najpierw sprawdzamy, czy udało się odczytać liczbę. Dopiero później sprawdzamy jej zakres.

### Przerywanie programu przy pierwszej błędnej linii

W wielu zadaniach lepiej pominąć błędną linię, wypisać ostrzeżenie i kontynuować odczyt kolejnych danych.

## Zadania do wykonania

1. Napisz program, który wczytuje liczbę z klawiatury i sprawdza, czy odczyt się udał.
2. Rozbuduj program tak, aby sprawdzał, czy liczba należy do zakresu od `1` do `100`.
3. Napisz program, który odczytuje liczby z pliku `liczby.txt` i wypisuje ich sumę.
4. Rozbuduj program z zadania 3 tak, aby obsługiwał brak pliku.
5. Napisz program, który czyta plik linia po linii i wypisuje tylko te linie, które zawierają poprawne liczby całkowite.

## Kryteria zaliczenia

Program powinien:

- sprawdzać, czy plik został otwarty,
- sprawdzać wynik operacji odczytu,
- nie używać danych po nieudanym odczycie,
- rozdzielać sprawdzenie typu danych od sprawdzenia zakresu,
- jasno informować użytkownika o błędnych danych,
- kompilować się bez błędów.

## Pytania kontrolne

1. Co oznacza warunek `if (!plik)`?
2. Dlaczego nie wolno zakładać, że odczyt liczby zawsze się uda?
3. Czym różni się błąd formatu danych od wartości spoza zakresu?
4. Po co czytać plik liniami przed parsowaniem danych?
5. Kiedy lepiej pominąć błędną linię, a kiedy zakończyć program?
