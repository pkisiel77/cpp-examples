# 09 - Ćwiczenie: kalkulator RPN

## Cel ćwiczenia

Celem ćwiczenia jest przygotowanie małego projektu wieloplikowego, który oblicza
wartość prostego wyrażenia matematycznego przez zamianę na odwrotną notację
polską.

Ćwiczenie jest pomostem między segmentem build/testy a większym projektem
[Projekt 08 - Kalkulator](../10-projekty/project-08-kalkulator.md). Tutaj
zakres jest mniejszy: najważniejsze są podział na moduły, testy i czytelny build.

## Wymagania wstępne

Przed wykonaniem ćwiczenia student powinien znać:

- podział programu na pliki `.h` i `.cpp`,
- strukturę katalogów `include`, `src`, `tests`, `build`,
- kompilację wielu plików jedną komendą,
- proste testy bez frameworka,
- podstawy pracy z `std::vector` i `std::string`.

## Opis zadania

Napisz program konsolowy, który:

- wczytuje jedno wyrażenie tekstowe,
- obsługuje liczby rzeczywiste,
- obsługuje operatory `+`, `-`, `*`, `/`,
- respektuje priorytet mnożenia i dzielenia,
- obsługuje nawiasy okrągłe,
- zamienia wyrażenie na odwrotną notację polską,
- oblicza wynik ze stosu,
- zgłasza czytelny błąd dla niepoprawnego wyrażenia.

Przykłady:

```text
2 + 2 * 2 = 6
(2 + 2) * 2 = 8
10 / 2 + 3 = 8
```

## Proponowana struktura plików

```text
rpn-calculator/
  include/rpn/
    token.h
    tokenizer.h
    rpn.h
    evaluator.h
  src/
    tokenizer.cpp
    rpn.cpp
    evaluator.cpp
    main.cpp
  tests/
    rpn_tests.cpp
  build/
    .gitignore
  build.sh
  README.md
```

## Wymagania techniczne

Projekt powinien:

- być napisany w C++17,
- mieć funkcję tokenizującą wyrażenie,
- mieć funkcję zamieniającą tokeny na odwrotną notację polską,
- mieć funkcję obliczającą wynik z odwrotnej notacji polskiej,
- używać `std::vector` do listy tokenów,
- używać `std::vector` albo `std::stack` jako stosu,
- obsługiwać dzielenie przez zero,
- mieć testy dla tokenizacji albo obliczeń,
- mieć skrypt `build.sh`, który buduje aplikację i testy,
- kompilować się z flagami `-Wall -Wextra -pedantic`.

Przykładowe funkcje:

```cpp
std::vector<Token> tokenize(const std::string& expression);
std::vector<Token> toReversePolishNotation(const std::vector<Token>& tokens);
double evaluateReversePolishNotation(const std::vector<Token>& tokens);
```

## Wariant podstawowy

Minimalna wersja ćwiczenia powinna zawierać:

1. Wczytanie jednego wyrażenia od użytkownika.
2. Obsługę operatorów `+`, `-`, `*`, `/`.
3. Obsługę nawiasów.
4. Poprawną kolejność wykonywania działań.
5. Zamianę wyrażenia na odwrotną notację polską.
6. Obliczenie wyniku ze stosu.
7. Komunikat dla dzielenia przez zero.
8. Komunikat dla błędnych nawiasów.
9. Testy dla co najmniej trzech poprawnych wyrażeń.
10. Instrukcję kompilacji i uruchomienia.

## Proponowany podział pracy

1. Utwórz strukturę katalogów projektu.
2. Dodaj `build.sh`, który kompiluje pusty program.
3. Zdefiniuj typ `Token`.
4. Napisz tokenizację liczb i operatorów.
5. Dodaj zamianę na odwrotną notację polską.
6. Dodaj obliczanie wyniku ze stosu.
7. Dodaj testy dla poprawnych wyrażeń.
8. Dodaj obsługę błędów i testy przypadków błędnych.

## Zadania dodatkowe

Po wykonaniu wariantu podstawowego możesz dodać:

- liczby ujemne,
- operator potęgowania,
- stałe `pi` i `e`,
- tryb wielu obliczeń w pętli,
- historię wyników,
- testy automatyczne tokenizacji i obliczeń,
- porównanie rozwiązania z parserem rekurencyjnym.

Funkcje matematyczne, historia i zapis do pliku są częścią większego projektu
[Projekt 08 - Kalkulator](../10-projekty/project-08-kalkulator.md), więc tutaj
nie są wymagane w wariancie podstawowym.

## Pytania kontrolne

1. Który moduł odpowiada za tokenizację, a który za obliczenie wyniku?
2. Dlaczego tokenizacja powinna być oddzielona od obliczania?
3. Jak test zwraca informację o błędzie do skryptu `build.sh`?
4. Jakie pliki powinny trafić do commita, a jakie powinny zostać w `build/`?

## Scenariusze sprawdzenia

1. Oblicz `2 + 2 * 2` i sprawdź, czy wynik to `6`.
2. Oblicz `(2 + 2) * 2` i sprawdź, czy wynik to `8`.
3. Oblicz `10 / 2 + 3` i sprawdź, czy wynik to `8`.
4. Spróbuj obliczyć `10 / 0` i sprawdź komunikat błędu.
5. Spróbuj obliczyć `(2 + 3` i sprawdź komunikat o nawiasach.
6. Spróbuj obliczyć `2 + * 3` i sprawdź komunikat o składni.

## Kryteria zaliczenia

Ćwiczenie jest zaliczone, jeśli:

- projekt kompiluje się bez błędów i ostrzeżeń,
- kod jest podzielony na pliki `.h` i `.cpp`,
- tokenizacja jest oddzielona od obliczania,
- program poprawnie liczy priorytety operatorów,
- program poprawnie obsługuje nawiasy,
- program wykrywa dzielenie przez zero,
- testy uruchamiają się z `build.sh`,
- `README.md` opisuje kompilację, testy i strukturę katalogów.

## Źródło

Ćwiczenie powstało na podstawie starszego zadania z
[zadań pomocniczych TNT](../10-projekty/tnt-tasks/calculator.md).
