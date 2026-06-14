# 07 - Ćwiczenie: minimum, maksimum i średnia

## Cel ćwiczenia

Celem ćwiczenia jest napisanie programu konsolowego, który wczytuje liczby
rzeczywiste od użytkownika, a następnie wyznacza wartość minimalną, wartość
maksymalną oraz średnią arytmetyczną.

Ćwiczenie utrwala pętle zależne od warunku, walidację danych wejściowych,
aktualizowanie wyniku częściowego i obsługę przypadku braku danych.

## Wymagania wstępne

Przed wykonaniem ćwiczenia student powinien znać:

- instrukcję `if`, `else if`, `else`,
- pętle `while` albo `do while`,
- typ `double`,
- podstawowe operacje wejścia i wyjścia,
- sprawdzanie poprawności danych wejściowych.

## Opis zadania

Napisz program, który:

- wczytuje kolejne liczby rzeczywiste,
- pozwala zakończyć wprowadzanie danych komendą tekstową,
- oblicza minimum,
- oblicza maksimum,
- oblicza średnią arytmetyczną,
- wyświetla liczbę poprawnie wczytanych wartości,
- obsługuje sytuację, gdy użytkownik nie poda żadnej liczby.

Zamiast obsługi klawisza `ESC` użyj rozwiązania przenośnego: użytkownik wpisuje
`q`, `koniec` albo pustą linię, aby zakończyć wprowadzanie danych.

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

## Wariant podstawowy

Minimalna wersja ćwiczenia powinna zawierać:

1. Wczytywanie wielu liczb od użytkownika.
2. Komendę kończącą wprowadzanie danych.
3. Obliczenie minimum.
4. Obliczenie maksimum.
5. Obliczenie średniej arytmetycznej.
6. Obsługę przypadku pustej listy danych.
7. Komunikat dla błędnej wartości wejściowej.
8. Krótką instrukcję kompilacji i uruchomienia.

## Proponowany podział pracy

1. Napisz pętlę, która czyta tekst do momentu wpisania `q`.
2. Dodaj licznik poprawnych wartości.
3. Dodaj sumę i obliczanie średniej.
4. Dodaj minimum i maksimum.
5. Dodaj komunikat dla pustej listy danych.
6. Dodaj obsługę błędnego tekstu, np. `abc`.

## Zadania dodatkowe

Po wykonaniu wariantu podstawowego możesz dodać:

- przechowywanie wszystkich liczb w `std::vector<double>`,
- sortowanie wprowadzonych liczb,
- obliczenie mediany,
- obliczenie sumy,
- obliczenie odchylenia standardowego,
- wczytanie liczb z pliku,
- zapis raportu do pliku,
- testy automatyczne funkcji liczącej statystyki.

## Pytania kontrolne

1. Dlaczego program nie może obliczyć średniej, gdy licznik wynosi `0`?
2. Kiedy należy ustawić pierwszą wartość minimum i maksimum?
3. Czym różni się błędna wartość wejściowa od komendy kończącej program?
4. Dlaczego w tym zadaniu pętla `while` jest wygodniejsza niż pętla `for`?

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

## Kryteria zaliczenia

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

## Źródło

Ćwiczenie powstało na podstawie starszego zadania z
[zadań pomocniczych TNT](../10-projekty/tnt-tasks/min-max-avg.md).
