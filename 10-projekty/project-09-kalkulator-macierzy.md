# Projekt 09 - Kalkulator macierzy

## Cel projektu

Celem projektu jest przygotowanie kalkulatora macierzy działającego w
terminalu. Projekt ma pokazać pracę z tablicami dwuwymiarowymi, klasami,
walidacją danych, przeciążaniem operatorów oraz obsługą błędów matematycznych.

Minimalna wersja może działać jako zwykła aplikacja konsolowa. Określenie
"terminal graficzny" można potraktować jako czytelny interfejs tekstowy:
tabele, menu, historia operacji i uporządkowane komunikaty.

## Zakres funkcjonalny

Kalkulator powinien umożliwiać:

- utworzenie macierzy o podanych wymiarach,
- ręczne wpisanie elementów macierzy,
- wyświetlenie macierzy w czytelnej formie,
- dodawanie macierzy,
- odejmowanie macierzy,
- mnożenie macierzy przez liczbę,
- mnożenie dwóch macierzy,
- transpozycję macierzy,
- obliczenie wyznacznika dla macierzy kwadratowej,
- zapis macierzy do pliku,
- odczyt macierzy z pliku,
- obsługę błędnych wymiarów i danych wejściowych.

Przykładowe operacje:

```text
A + B
A - B
2 * A
A * B
transpose(A)
det(A)
```

## Wymagania techniczne

Projekt powinien:

- być napisany w C++17,
- używać klasy `Matrix` do przechowywania danych macierzy,
- używać `std::vector<std::vector<double>>` albo jednowymiarowego
  `std::vector<double>` z przeliczaniem indeksów,
- walidować wymiary przed wykonaniem operacji,
- zgłaszać czytelne błędy dla niepoprawnych działań,
- rozdzielać logikę macierzy od interfejsu użytkownika,
- zapisywać i odczytywać macierze z pliku tekstowego,
- rozdzielać deklaracje i implementacje na pliki `.h` i `.cpp`,
- kompilować się z flagami `-Wall -Wextra -pedantic`.

## Proponowana struktura plików

```text
matrix-calculator/
  include/matrix_calculator/
    matrix.h
    matrix_io.h
    matrix_calculator.h
    menu.h
  src/
    matrix.cpp
    matrix_io.cpp
    matrix_calculator.cpp
    menu.cpp
    main.cpp
  tests/
    matrix_tests.cpp
  data/
    matrices.txt
  build/
```

Znaczenie elementów:

- `Matrix` - dane macierzy i podstawowe operacje matematyczne,
- `MatrixIo` - zapis i odczyt macierzy z pliku,
- `MatrixCalculator` - logika wyboru i wykonywania operacji,
- `Menu` - interfejs użytkownika w terminalu.

## Model danych

Macierz powinna mieć co najmniej:

- liczbę wierszy,
- liczbę kolumn,
- wartości elementów.

Przykład:

```cpp
class Matrix {
public:
    Matrix(std::size_t rows, std::size_t columns);

    std::size_t rows() const;
    std::size_t columns() const;

    double at(std::size_t row, std::size_t column) const;
    void set(std::size_t row, std::size_t column, double value);

private:
    std::size_t rows_;
    std::size_t columns_;
    std::vector<double> values_;
};
```

Jednowymiarowy wektor upraszcza przechowywanie danych i pozwala przeliczać
indeks według wzoru:

```text
index = row * columns + column
```

## Obsługiwane operacje

Minimalny zestaw operacji:

- dodawanie macierzy o tych samych wymiarach,
- odejmowanie macierzy o tych samych wymiarach,
- mnożenie macierzy przez skalar,
- mnożenie macierzy, gdy liczba kolumn pierwszej macierzy jest równa liczbie
  wierszy drugiej macierzy,
- transpozycja dowolnej macierzy,
- wyznacznik macierzy `2x2`.

Rozszerzona wersja może obsługiwać:

- wyznacznik macierzy `3x3`,
- wyznacznik metodą eliminacji Gaussa,
- macierz jednostkową,
- macierz odwrotną,
- potęgowanie macierzy kwadratowej.

## Minimalny wariant zaliczeniowy

Minimalna wersja projektu powinna zawierać:

1. Menu konsolowe z opcjami:
   - utwórz macierz,
   - wyświetl macierz,
   - dodaj macierze,
   - odejmij macierze,
   - pomnóż macierz przez liczbę,
   - pomnóż macierze,
   - transponuj macierz,
   - oblicz wyznacznik,
   - zapisz macierze,
   - wczytaj macierze,
   - zakończ.
2. Walidację wymiarów dla każdej operacji.
3. Obsługę liczb zmiennoprzecinkowych.
4. Co najmniej dwie przechowywane macierze, np. `A` i `B`.
5. Zapis i odczyt macierzy z pliku tekstowego.
6. Testy ręczne albo automatyczne dla podstawowych operacji.
7. Instrukcję kompilacji i uruchomienia w `README.md` projektu.

## Rozszerzenia dla chętnych

Możliwe rozszerzenia:

- dowolna liczba nazwanych macierzy,
- historia wykonanych operacji,
- import i eksport CSV,
- przeciążenie operatorów `+`, `-`, `*`,
- testy automatyczne klasy `Matrix`,
- generowanie macierzy losowej,
- wyznacznik dla większych macierzy,
- macierz odwrotna,
- rozwiązywanie układów równań liniowych,
- kolorowe formatowanie tabel w terminalu.

## Kryteria oceny

Projekt jest zaliczony, jeśli:

- kompiluje się bez błędów i ostrzeżeń,
- poprawnie tworzy i wyświetla macierze,
- poprawnie dodaje i odejmuje macierze,
- poprawnie mnoży macierz przez skalar,
- poprawnie mnoży dwie macierze,
- poprawnie transponuje macierz,
- sprawdza zgodność wymiarów przed operacjami,
- zgłasza czytelne komunikaty błędów,
- zapisuje i odczytuje macierze z pliku,
- używa klasy `Matrix`,
- zawiera instrukcję uruchomienia,
- zawiera testy albo opis ręcznych scenariuszy sprawdzenia.

## Scenariusze sprawdzenia

1. Utwórz macierz `A` o wymiarach `2x2` i wyświetl ją.
2. Utwórz macierz `B` o wymiarach `2x2`, dodaj `A + B` i sprawdź wynik.
3. Pomnóż macierz `A` przez liczbę `2`.
4. Pomnóż macierz `2x3` przez macierz `3x2`.
5. Spróbuj dodać macierze o różnych wymiarach i sprawdź komunikat błędu.
6. Oblicz wyznacznik macierzy `2x2`.
7. Zapisz macierze do pliku, uruchom program ponownie i wczytaj dane.
