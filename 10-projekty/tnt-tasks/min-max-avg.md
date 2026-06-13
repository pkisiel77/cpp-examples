# Ćwiczenie - Minimum, maksimum i średnia

## Cel ćwiczenia

Celem ćwiczenia jest napisanie programu konsolowego, który wczytuje liczby
rzeczywiste od użytkownika, a następnie wyznacza wartość minimalną, wartość
maksymalną oraz średnią arytmetyczną.

Ćwiczenie utrwala:

- pętle zależne od warunku,
- walidację danych wejściowych,
- aktualizowanie wyniku częściowego,
- pracę z typem `double`,
- obsługę przypadku braku danych.

## Zakres funkcjonalny

Program powinien:

- wczytywać kolejne liczby rzeczywiste,
- pozwalać zakończyć wprowadzanie danych,
- obliczyć minimum,
- obliczyć maksimum,
- obliczyć średnią arytmetyczną,
- wyświetlić liczbę poprawnie wczytanych wartości,
- obsłużyć sytuację, gdy użytkownik nie poda żadnej liczby.

Zamiast wymagać obsługi klawisza `ESC`, można przyjąć prosty i przenośny
wariant: użytkownik wpisuje `koniec`, `q` albo pustą linię, aby zakończyć
wprowadzanie danych.

## Przykład działania

```text
Podaj liczbe albo q, aby zakonczyc: 10
Podaj liczbe albo q, aby zakonczyc: -2.5
Podaj liczbe albo q, aby zakonczyc: 4.5
Podaj liczbe albo q, aby zakonczyc: q

Liczba wartosci: 3
Minimum: -2.5
Maksimum: 10
Srednia: 4
```

## Wymagania techniczne

Program powinien:

- być napisany w C++17,
- używać pętli `while` albo `do while`,
- przechowywać sumę wartości w zmiennej typu `double`,
- przechowywać licznik poprawnych wartości,
- aktualizować minimum i maksimum po każdym poprawnym odczycie,
- wykrywać błędne dane wejściowe,
- nie dzielić przez zero, gdy nie podano żadnej liczby,
- kompilować się z flagami `-Wall -Wextra -pedantic`.

## Proponowany podział na funkcje

W prostej wersji można użyć jednej funkcji pomocniczej do parsowania tekstu:

```cpp
bool tryParseDouble(const std::string& text, double& value);
```

W wersji rozszerzonej można dodać strukturę wyniku:

```cpp
struct Statistics {
    double minimum;
    double maximum;
    double average;
    int count;
};
```

## Minimalny wariant zaliczeniowy

Minimalna wersja ćwiczenia powinna zawierać:

1. Wczytywanie wielu liczb od użytkownika.
2. Komendę kończącą wprowadzanie danych.
3. Obliczenie minimum.
4. Obliczenie maksimum.
5. Obliczenie średniej arytmetycznej.
6. Obsługę przypadku pustej listy danych.
7. Komunikat dla błędnej wartości wejściowej.
8. Krótką instrukcję kompilacji i uruchomienia.

## Rozszerzenia dla chętnych

Możliwe rozszerzenia:

- przechowywanie wszystkich liczb w `std::vector<double>`,
- sortowanie wprowadzonych liczb,
- obliczenie mediany,
- obliczenie sumy,
- obliczenie odchylenia standardowego,
- wczytanie liczb z pliku,
- zapis raportu do pliku,
- testy automatyczne funkcji liczącej statystyki.

## Kryteria oceny

Ćwiczenie jest zaliczone, jeśli:

- program kompiluje się bez błędów i ostrzeżeń,
- poprawnie liczy minimum,
- poprawnie liczy maksimum,
- poprawnie liczy średnią,
- poprawnie działa dla liczb ujemnych,
- poprawnie działa dla jednej liczby,
- nie wykonuje dzielenia przez zero,
- informuje użytkownika o błędnym wejściu,
- kod jest czytelnie sformatowany.

## Scenariusze sprawdzenia

1. Wpisz liczby `10`, `-2.5`, `4.5` i sprawdź wynik:
   - minimum: `-2.5`,
   - maksimum: `10`,
   - średnia: `4`.
2. Wpisz tylko jedną liczbę i sprawdź, czy minimum, maksimum i średnia są takie
   same.
3. Zakończ wprowadzanie bez podania liczby i sprawdź komunikat programu.
4. Wpisz błędną wartość, np. `abc`, i sprawdź, czy program prosi o kolejną
   wartość zamiast kończyć działanie.
5. Wpisz kilka liczb ujemnych i sprawdź poprawność minimum oraz maksimum.

## Źródło pierwotne

Zadanie pochodziło ze starszego materiału egzaminacyjnego i zostało
uporządkowane do formatu ćwiczenia repozytorium.
