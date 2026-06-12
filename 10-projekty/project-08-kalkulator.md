# Projekt 08 - Kalkulator

## Cel projektu

Celem projektu jest przygotowanie kalkulatora działającego w terminalu.
Projekt ma pokazać parsowanie tekstu, obsługę błędów, priorytety operatorów,
nawiasy, funkcje matematyczne oraz podział programu na mniejsze moduły.

Minimalna wersja może działać jako zwykła aplikacja konsolowa. Określenie
"terminal graficzny" można potraktować jako czytelny interfejs tekstowy:
menu, historia obliczeń, wyróżnione komunikaty i uporządkowane wyniki.

## Zakres funkcjonalny

Kalkulator powinien umożliwiać:

- wpisanie działania jako jednego wyrażenia tekstowego,
- obliczenie wyniku,
- obsługę działań `+`, `-`, `*`, `/`,
- obsługę nawiasów okrągłych,
- poprawną kolejność wykonywania działań,
- obsługę liczb zmiennoprzecinkowych,
- obsługę funkcji trygonometrycznych,
- wyświetlenie historii obliczeń,
- zapis historii do pliku,
- obsługę błędnych wyrażeń.

Przykładowe wyrażenia:

```text
2 + 3 * 4
(2 + 3) * 4
sin(0)
cos(3.14159)
sqrt(16) + 2
```

## Wymagania techniczne

Projekt powinien:

- być napisany w C++17,
- rozdzielać logikę kalkulatora od interfejsu użytkownika,
- mieć osobny moduł tokenizacji wyrażenia,
- mieć osobny moduł parsowania albo obliczania wyrażenia,
- obsługiwać błędy bez przerywania programu,
- używać wyjątków albo typu wyniku do zgłaszania błędów,
- używać `std::vector` do przechowywania tokenów i historii,
- używać funkcji z `<cmath>` dla operacji matematycznych,
- rozdzielać deklaracje i implementacje na pliki `.h` i `.cpp`,
- kompilować się z flagami `-Wall -Wextra -pedantic`.

## Proponowana struktura plików

```text
calculator/
  include/calculator/
    token.h
    tokenizer.h
    parser.h
    calculator.h
    history.h
  src/
    tokenizer.cpp
    parser.cpp
    calculator.cpp
    history.cpp
    main.cpp
  tests/
    calculator_tests.cpp
  data/
    history.txt
  build/
```

Znaczenie elementów:

- `Token` - reprezentacja liczby, operatora, nawiasu albo funkcji,
- `Tokenizer` - zamiana tekstu wejściowego na listę tokenów,
- `Parser` - sprawdzanie składni i obliczanie wartości wyrażenia,
- `Calculator` - główna logika kalkulatora,
- `History` - historia wykonanych obliczeń.

## Obsługiwane operacje

Minimalny zestaw operacji:

- dodawanie: `a + b`,
- odejmowanie: `a - b`,
- mnożenie: `a * b`,
- dzielenie: `a / b`,
- nawiasy: `(a + b) * c`,
- liczby ujemne: `-5 + 2`.

Funkcje matematyczne:

- `sin(x)`,
- `cos(x)`,
- `tan(x)`,
- `sqrt(x)`,
- `abs(x)`,
- `pow(a, b)` jako rozszerzenie.

Na początku warto przyjąć, że funkcje trygonometryczne używają radianów.
Obsługa stopni może być rozszerzeniem projektu.

## Algorytm obliczania

Do obliczania wyrażeń można użyć jednego z dwóch podejść:

1. Algorytm Shunting Yard:
   - zamiana wyrażenia na odwrotną notację polską,
   - obliczenie wyniku ze stosu.
2. Parser rekurencyjny:
   - osobne funkcje dla wyrażeń, składników i czynników,
   - naturalna obsługa priorytetów operatorów.

Dla tego projektu rekomendowany jest parser rekurencyjny, ponieważ łatwiej
pokazać w kodzie kolejność działań i obsługę nawiasów.

## Minimalny wariant zaliczeniowy

Minimalna wersja projektu powinna zawierać:

1. Menu konsolowe z opcjami:
   - oblicz wyrażenie,
   - pokaż historię,
   - zapisz historię,
   - wyczyść historię,
   - zakończ.
2. Obsługę operatorów `+`, `-`, `*`, `/`.
3. Obsługę nawiasów.
4. Obsługę co najmniej trzech funkcji matematycznych.
5. Komunikaty dla błędów:
   - dzielenie przez zero,
   - brakujący nawias,
   - nieznany znak,
   - puste wyrażenie.
6. Testy ręczne albo automatyczne dla przykładowych wyrażeń.
7. Instrukcję kompilacji i uruchomienia w `README.md` projektu.

## Rozszerzenia dla chętnych

Możliwe rozszerzenia:

- zmienne, np. `x = 5`,
- stałe `pi` i `e`,
- tryb stopni i radianów,
- funkcja `pow(a, b)`,
- eksport historii do CSV,
- kolorowanie komunikatów w terminalu,
- testy automatyczne parsera,
- prosty tryb interaktywny REPL,
- obsługa skrótów poleceń, np. `:history`, `:clear`, `:quit`.

## Kryteria oceny

Projekt jest zaliczony, jeśli:

- kompiluje się bez błędów i ostrzeżeń,
- poprawnie obsługuje priorytety operatorów,
- poprawnie obsługuje nawiasy,
- poprawnie liczy funkcje matematyczne,
- wykrywa błędne wyrażenia,
- nie kończy programu po błędnym wejściu,
- przechowuje historię obliczeń,
- zapisuje historię do pliku,
- ma czytelne menu konsolowe,
- zawiera instrukcję uruchomienia,
- zawiera testy albo opis ręcznych scenariuszy sprawdzenia.

## Scenariusze sprawdzenia

1. Oblicz `2 + 3 * 4` i sprawdź, czy wynik to `14`.
2. Oblicz `(2 + 3) * 4` i sprawdź, czy wynik to `20`.
3. Oblicz `sin(0)` i sprawdź, czy wynik to `0`.
4. Spróbuj obliczyć `10 / 0` i sprawdź komunikat błędu.
5. Spróbuj obliczyć `(2 + 3` i sprawdź komunikat o nawiasie.
6. Wykonaj kilka obliczeń, pokaż historię i zapisz ją do pliku.
