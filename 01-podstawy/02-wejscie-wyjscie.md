# 02 - Wejście i wyjście

## Cel lekcji

Celem lekcji jest nauczenie podstawowej komunikacji programu z użytkownikiem: wypisywania tekstu na ekran, wczytywania danych z klawiatury i odczytywania argumentów programu.

## Wymagania wstępne

Student powinien rozumieć materiał z lekcji [01-pierwszy-program.md](01-pierwszy-program.md): funkcję `main`, dołączanie biblioteki `iostream`, kompilację i uruchamianie programu.

## Krótka teoria

### Strumień wyjściowy `std::cout`

Do wypisywania tekstu na ekran używamy `std::cout`.

```cpp
#include <iostream>

int main()
{
    std::cout << "Witaj!" << std::endl;
    return 0;
}
```

Operator `<<` przekazuje dane do strumienia wyjściowego.

Można wypisać kilka wartości w jednej instrukcji:

```cpp
std::cout << "Wynik: " << 42 << std::endl;
```

### `std::endl` i `\n`

`std::endl` kończy linię i opróżnia bufor wyjścia. W prostych programach jest wygodny, ale nie zawsze potrzebny.

Znak `\n` również przechodzi do nowej linii:

```cpp
std::cout << "Pierwsza linia\n";
std::cout << "Druga linia\n";
```

W zadaniach podstawowych można używać obu form. W większych programach często wybiera się `\n`, gdy nie trzeba wymuszać opróżnienia bufora.

### Strumień wejściowy `std::cin`

Do wczytywania danych z klawiatury używamy `std::cin`.

```cpp
#include <iostream>
#include <string>

int main()
{
    std::string imie;

    std::cout << "Podaj imie: ";
    std::cin >> imie;

    std::cout << "Czesc, " << imie << "!" << std::endl;
    return 0;
}
```

Operator `>>` pobiera dane ze strumienia wejściowego i zapisuje je do zmiennej.

Ten przykład znajduje się w pliku [examples/input_name.cpp](examples/input_name.cpp).

### Wczytywanie całej linii

`std::cin >> zmienna` czyta dane do pierwszej spacji. Jeżeli potrzebujemy wczytać cały tekst, na przykład imię i nazwisko, używamy `std::getline`.

```cpp
#include <iostream>
#include <string>

int main()
{
    std::string imieINazwisko;

    std::cout << "Podaj imie i nazwisko: ";
    std::getline(std::cin, imieINazwisko);

    std::cout << "Uzytkownik: " << imieINazwisko << std::endl;
    return 0;
}
```

Ten przykład znajduje się w pliku [examples/input_line.cpp](examples/input_line.cpp).

### Argumenty programu

Program może otrzymać dane już w chwili uruchomienia. Służą do tego argumenty funkcji `main`.

```cpp
int main(int argc, char* argv[])
{
    // argc - liczba argumentow
    // argv - tablica argumentow jako tekst
}
```

Przykład:

```cpp
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Liczba argumentow: " << argc << std::endl;

    for (int i = 0; i < argc; ++i)
    {
        std::cout << i << ": " << argv[i] << std::endl;
    }

    return 0;
}
```

Ten przykład znajduje się w pliku [examples/program_arguments.cpp](examples/program_arguments.cpp).

Uruchomienie:

```sh
c++ examples/program_arguments.cpp -o program_arguments
./program_arguments Ala ma kota
```

## Zadania do wykonania

1. Napisz program, który pyta użytkownika o imię i wypisuje powitanie.
2. Napisz program, który pyta użytkownika o imię oraz wiek i wypisuje oba dane w jednym zdaniu.
3. Napisz program, który wczytuje dwie liczby całkowite i wypisuje ich sumę.
4. Napisz program, który wczytuje imię i nazwisko w jednej linii przy pomocy `std::getline`.
5. Napisz program, który wypisuje wszystkie argumenty przekazane przy uruchomieniu.

## Kryteria zaliczenia

Program powinien:

- używać `std::cout` do komunikatów dla użytkownika,
- używać `std::cin` albo `std::getline` do wczytywania danych,
- deklarować zmienne o odpowiednich typach,
- kompilować się bez błędów,
- wypisywać wynik w czytelnej formie.

## Pytania kontrolne

1. Do czego służy `std::cout`?
2. Do czego służy `std::cin`?
3. Czym różni się `std::cin >> tekst` od `std::getline(std::cin, tekst)`?
4. Co oznacza parametr `argc`?
5. Co przechowuje `argv`?
