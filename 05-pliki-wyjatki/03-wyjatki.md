# 03 - Wyjątki

## Cel lekcji

Celem lekcji jest zrozumienie podstaw mechanizmu wyjątków w C++: `try`, `throw` i `catch`, oraz rozpoznanie sytuacji, w których wyjątek jest sensownym sposobem zgłoszenia błędu.

## Wymagania wstępne

Student powinien znać:

- funkcje z segmentu [03-funkcje-tablice-napisy](../03-funkcje-tablice-napisy/README.md),
- podstawy odczytu i walidacji z lekcji [02-odczyt-i-walidacja.md](02-odczyt-i-walidacja.md),
- podstawowe komunikaty o błędach zwracane przez program.

## Po co są wyjątki

Wyjątek służy do zgłoszenia sytuacji błędnej, której funkcja nie chce albo nie potrafi obsłużyć lokalnie.

Przykład:

- funkcja ma obliczyć wynik,
- wykrywa niepoprawne dane,
- przerywa normalne wykonanie przez `throw`,
- kod wyżej obsługuje problem w bloku `catch`.

Wyjątki nie zastępują zwykłych instrukcji `if`. Dla prostych walidacji, które można obsłużyć od razu, zwykły warunek często jest czytelniejszy.

## `try`, `throw`, `catch`

Podstawowy schemat wygląda tak:

```cpp
try
{
    throw std::runtime_error("Opis bledu");
}
catch (const std::runtime_error& blad)
{
    std::cout << blad.what() << std::endl;
}
```

Do `std::runtime_error` potrzebny jest nagłówek:

```cpp
#include <stdexcept>
```

Pełny przykład znajduje się w pliku [examples/basic_exception.cpp](examples/basic_exception.cpp).

## Rzucanie wyjątku z funkcji

Najczęściej wyjątek jest zgłaszany w funkcji, która wykrywa błąd.

```cpp
double podziel(double a, double b)
{
    if (b == 0)
    {
        throw std::invalid_argument("Dzielenie przez zero");
    }

    return a / b;
}
```

Kod wywołujący funkcję decyduje, jak zareagować.

```cpp
try
{
    std::cout << podziel(10, 0) << std::endl;
}
catch (const std::invalid_argument& blad)
{
    std::cout << blad.what() << std::endl;
}
```

Pełny przykład znajduje się w pliku [examples/function_exception.cpp](examples/function_exception.cpp).

## Łapanie wyjątków standardowych

Wiele elementów biblioteki standardowej zgłasza wyjątki. Przykładem jest metoda `at()` w `std::vector`, która sprawdza zakres indeksu.

```cpp
std::vector<int> liczby = {10, 20, 30};
std::cout << liczby.at(10) << std::endl;
```

Ten kod zgłosi wyjątek `std::out_of_range`.

Można go obsłużyć jako konkretny typ:

```cpp
catch (const std::out_of_range& blad)
{
    std::cout << "Indeks poza zakresem" << std::endl;
}
```

albo szerzej jako `std::exception`:

```cpp
catch (const std::exception& blad)
{
    std::cout << blad.what() << std::endl;
}
```

Pełny przykład znajduje się w pliku [examples/standard_exception.cpp](examples/standard_exception.cpp).

## Kolejność bloków `catch`

Najpierw zapisujemy bardziej szczegółowe typy wyjątków, a później ogólniejsze.

```cpp
catch (const std::out_of_range& blad)
{
    // konkretny blad zakresu
}
catch (const std::exception& blad)
{
    // inne standardowe wyjatki
}
```

Jeśli `std::exception` byłoby pierwsze, złapałoby też wyjątki bardziej szczegółowe.

## `catch (...)`

Zapis:

```cpp
catch (...)
{
    std::cout << "Nieznany blad" << std::endl;
}
```

łapie każdy wyjątek. Używamy go ostrożnie, bo nie daje informacji o typie błędu. W prostych programach lepiej łapać konkretne typy albo `std::exception`.

## Kiedy używać wyjątków

Wyjątek ma sens, gdy:

- funkcja wykrywa błąd, ale nie powinna sama pytać użytkownika o poprawkę,
- błąd uniemożliwia normalne wykonanie operacji,
- chcemy oddzielić logikę obliczeń od obsługi błędów,
- błąd powinien zostać obsłużony wyżej w programie.

Zwykły `if` jest często lepszy, gdy:

- błąd można obsłużyć od razu,
- sprawdzamy prosty warunek wejściowy,
- niepoprawna wartość jest normalnym elementem działania programu.

## Częste błędy

### Łapanie wyjątku przez wartość

Mniej zalecane:

```cpp
catch (std::exception blad)
{
    std::cout << blad.what() << std::endl;
}
```

Lepiej:

```cpp
catch (const std::exception& blad)
{
    std::cout << blad.what() << std::endl;
}
```

Łapanie przez referencję unika kopiowania i zachowuje właściwy typ wyjątku.

### Puste `catch`

Niepoprawnie:

```cpp
catch (const std::exception&)
{
}
```

Jeśli błąd jest ignorowany bez komunikatu, program może zachowywać się niezrozumiale.

### Używanie wyjątków do zwykłego sterowania programem

Wyjątki nie powinny zastępować pętli, `if` ani menu. Służą do obsługi sytuacji błędnych.

## Zadania

1. Napisz funkcję `podziel`, która rzuca `std::invalid_argument`, gdy drugi argument jest równy `0`.
2. Obsłuż wyjątek z zadania 1 w funkcji `main` i wypisz czytelny komunikat.
3. Napisz funkcję `sprawdzWiek`, która rzuca wyjątek, jeśli wiek jest mniejszy od `0` albo większy od `130`.
4. Przygotuj przykład z `std::vector` i metodą `at()`, który obsługuje indeks spoza zakresu.
5. Napisz program, który próbuje otworzyć plik i rzuca wyjątek, jeśli plik nie istnieje.

## Kryteria zaliczenia

Program powinien:

- używać bloku `try`,
- zgłaszać błąd przez `throw`,
- obsługiwać błąd przez `catch`,
- łapać wyjątki standardowe przez `const` referencję,
- wypisywać czytelny komunikat błędu,
- używać wyjątków tylko dla sytuacji błędnych,
- kompilować się bez błędów.

## Pytania kontrolne

1. Co robi instrukcja `throw`?
2. Po co stosujemy blok `try`?
3. Co robi blok `catch`?
4. Dlaczego zwykle łapiemy wyjątki jako `const std::exception&`?
5. Kiedy zwykły `if` jest lepszy niż wyjątek?
