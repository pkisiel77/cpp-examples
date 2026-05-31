# 01 - Pliki tekstowe

## Cel lekcji

Celem lekcji jest poznanie podstaw zapisu, odczytu i dopisywania danych do pliku tekstowego w C++.

## Wymagania wstępne

Student powinien znać:

- zmienne i typy danych z segmentu [01-podstawy](../01-podstawy/README.md),
- instrukcje warunkowe i pętle z segmentu [02-sterowanie-i-petle](../02-sterowanie-i-petle/README.md),
- funkcje i napisy z segmentu [03-funkcje-tablice-napisy](../03-funkcje-tablice-napisy/README.md).

## Biblioteka `<fstream>`

Do pracy z plikami tekstowymi używamy nagłówka:

```cpp
#include <fstream>
```

Najczęściej używane klasy to:

- `std::ofstream` - zapis do pliku,
- `std::ifstream` - odczyt z pliku,
- `std::fstream` - odczyt i zapis w jednym strumieniu.

Na początku warto rozdzielać zapis i odczyt, bo kod jest wtedy prostszy do zrozumienia.

## Zapis do pliku

Plik można otworzyć do zapisu przy pomocy `std::ofstream`.

```cpp
std::ofstream plik("dane.txt");
plik << "Ala ma kota" << std::endl;
```

Jeśli plik `dane.txt` nie istnieje, zostanie utworzony. Jeśli istnieje, jego poprzednia zawartość zostanie nadpisana.

Pełny przykład znajduje się w pliku [examples/write_text_file.cpp](examples/write_text_file.cpp).

## Sprawdzanie otwarcia pliku

Operacja otwarcia pliku może się nie udać. Program powinien to sprawdzić przed zapisem albo odczytem.

```cpp
std::ofstream plik("dane.txt");

if (!plik)
{
    std::cout << "Nie mozna otworzyc pliku" << std::endl;
    return 1;
}
```

Warunek `!plik` oznacza, że strumień jest w stanie błędu.

## Dopisywanie do pliku

Domyślny zapis przez `std::ofstream` nadpisuje plik. Jeśli chcemy dopisać dane na końcu pliku, używamy trybu `std::ios::app`.

```cpp
std::ofstream plik("dane.txt", std::ios::app);
plik << "Nowy wpis" << std::endl;
```

Pełny przykład znajduje się w pliku [examples/append_text_file.cpp](examples/append_text_file.cpp).

## Odczyt z pliku

Plik można otworzyć do odczytu przy pomocy `std::ifstream`.

```cpp
std::ifstream plik("dane.txt");
std::string linia;

while (std::getline(plik, linia))
{
    std::cout << linia << std::endl;
}
```

`std::getline` czyta całą linię tekstu, razem ze spacjami wewnątrz linii.

Pełny przykład znajduje się w pliku [examples/read_text_file.cpp](examples/read_text_file.cpp).

## Odczyt liniami i odczyt słowami

Dla plików tekstowych są dwa częste sposoby odczytu.

Odczyt liniami:

```cpp
std::getline(plik, linia);
```

Ten sposób zachowuje spacje w linii.

Odczyt słowami:

```cpp
plik >> slowo;
```

Ten sposób pomija białe znaki i czyta kolejne słowa osobno.

W zadaniach z tekstem opisowym zwykle lepszy jest `std::getline`.

## Zamykanie pliku

Strumień plikowy zamyka plik automatycznie, gdy obiekt wychodzi poza zakres.

```cpp
{
    std::ofstream plik("dane.txt");
    plik << "tekst" << std::endl;
} // tutaj plik zostaje zamkniety
```

Można też wywołać `close()`, ale w prostych programach często nie jest to potrzebne.

## Częste błędy

### Brak sprawdzenia otwarcia pliku

Niepoprawnie:

```cpp
std::ifstream plik("brak.txt");
std::string linia;
std::getline(plik, linia);
```

Poprawnie:

```cpp
std::ifstream plik("brak.txt");

if (!plik)
{
    std::cout << "Nie mozna otworzyc pliku" << std::endl;
    return 1;
}
```

### Nadpisanie pliku zamiast dopisania

Niepoprawnie, jeśli chcemy zachować stare dane:

```cpp
std::ofstream plik("dane.txt");
```

Poprawnie:

```cpp
std::ofstream plik("dane.txt", std::ios::app);
```

### Użycie `>>` tam, gdzie potrzebna jest cała linia

Dla tekstu:

```text
Ala ma kota
```

operator `>>` wczyta najpierw tylko `Ala`. Funkcja `std::getline` wczyta całą linię.

## Zadania

1. Napisz program, który tworzy plik `dane.txt` i zapisuje do niego trzy linie tekstu.
2. Napisz program, który odczytuje plik `dane.txt` linia po linii i wypisuje jego zawartość.
3. Napisz program, który dopisuje nową linię na końcu pliku `dane.txt`.
4. Rozbuduj program odczytujący plik tak, aby wypisywał numer każdej linii.
5. Napisz program, który liczy, ile linii znajduje się w pliku tekstowym.

## Kryteria zaliczenia

Program powinien:

- używać `std::ofstream` do zapisu,
- używać `std::ifstream` do odczytu,
- sprawdzać, czy plik został poprawnie otwarty,
- używać `std::ios::app`, gdy dane mają być dopisane,
- czytać tekst liniami przy pomocy `std::getline`,
- kompilować się bez błędów.

## Pytania kontrolne

1. Czym różni się `std::ofstream` od `std::ifstream`?
2. Co stanie się z istniejącym plikiem po otwarciu go zwykłym `std::ofstream`?
3. Do czego służy `std::ios::app`?
4. Dlaczego warto sprawdzić `if (!plik)`?
5. Czym różni się `std::getline` od operatora `>>`?
