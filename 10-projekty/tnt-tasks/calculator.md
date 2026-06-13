# Ćwiczenie - Kalkulator i odwrotna notacja polska

## Cel ćwiczenia

Celem ćwiczenia jest napisanie programu konsolowego, który oblicza wartość
wyrażenia matematycznego złożonego z wielu liczb i operatorów. Ćwiczenie jest
krótszym wariantem głównego projektu
[Projekt 08 - Kalkulator](../project-08-kalkulator.md).

Ten wariant skupia się na:

- tokenizacji prostego wyrażenia,
- priorytetach operatorów,
- zamianie wyrażenia na odwrotną notację polską,
- obliczeniu wyniku ze stosu,
- obsłudze podstawowych błędów wejścia.

## Zakres funkcjonalny

Program powinien:

- wczytać wyrażenie tekstowe od użytkownika,
- obsługiwać liczby rzeczywiste,
- obsługiwać operatory `+`, `-`, `*`, `/`,
- respektować priorytet mnożenia i dzielenia,
- obsługiwać nawiasy okrągłe,
- zamienić wyrażenie na odwrotną notację polską,
- obliczyć wynik z odwrotnej notacji polskiej,
- wyświetlić wynik,
- zgłosić czytelny błąd dla niepoprawnego wyrażenia.

Przykłady:

```text
2 + 2 * 2 = 6
(2 + 2) * 2 = 8
10 / 2 + 3 = 8
```

## Wymagania techniczne

Program powinien:

- być napisany w C++17,
- mieć funkcję tokenizującą wyrażenie,
- mieć funkcję zamieniającą tokeny na odwrotną notację polską,
- mieć funkcję obliczającą wynik z odwrotnej notacji polskiej,
- używać `std::vector` do listy tokenów,
- używać `std::stack` albo `std::vector` jako stosu,
- obsługiwać dzielenie przez zero,
- kompilować się z flagami `-Wall -Wextra -pedantic`.

## Proponowany podział na funkcje

Przykładowe funkcje:

```cpp
std::vector<Token> tokenize(const std::string& expression);
std::vector<Token> toReversePolishNotation(const std::vector<Token>& tokens);
double evaluateReversePolishNotation(const std::vector<Token>& tokens);
```

Token może reprezentować:

- liczbę,
- operator,
- nawias otwierający,
- nawias zamykający.

## Minimalny wariant zaliczeniowy

Minimalna wersja ćwiczenia powinna zawierać:

1. Wczytanie jednego wyrażenia od użytkownika.
2. Obsługę operatorów `+`, `-`, `*`, `/`.
3. Obsługę nawiasów.
4. Poprawną kolejność wykonywania działań.
5. Zamianę wyrażenia na odwrotną notację polską.
6. Obliczenie wyniku ze stosu.
7. Komunikat dla dzielenia przez zero.
8. Komunikat dla błędnych nawiasów.
9. Krótką instrukcję kompilacji i uruchomienia.

## Rozszerzenia dla chętnych

Możliwe rozszerzenia:

- liczby ujemne,
- operator potęgowania,
- funkcje matematyczne, np. `sin`, `cos`, `sqrt`,
- stałe `pi` i `e`,
- tryb wielu obliczeń w pętli,
- historia wyników,
- testy automatyczne tokenizacji i obliczeń,
- porównanie rozwiązania z parserem rekurencyjnym.

## Kryteria oceny

Ćwiczenie jest zaliczone, jeśli:

- program kompiluje się bez błędów i ostrzeżeń,
- poprawnie liczy `2 + 2 * 2`,
- poprawnie liczy wyrażenia z nawiasami,
- poprawnie odrzuca błędne nawiasy,
- wykrywa dzielenie przez zero,
- kod jest podzielony na funkcje,
- tokenizacja jest oddzielona od obliczania,
- kod jest czytelnie sformatowany.

## Scenariusze sprawdzenia

1. Oblicz `2 + 2 * 2` i sprawdź, czy wynik to `6`.
2. Oblicz `(2 + 2) * 2` i sprawdź, czy wynik to `8`.
3. Oblicz `10 / 2 + 3` i sprawdź, czy wynik to `8`.
4. Spróbuj obliczyć `10 / 0` i sprawdź komunikat błędu.
5. Spróbuj obliczyć `(2 + 3` i sprawdź komunikat o nawiasach.
6. Spróbuj obliczyć `2 + * 3` i sprawdź komunikat o składni.

## Źródło pierwotne

Zadanie pochodziło ze starszego materiału egzaminacyjnego i zostało
uporządkowane jako krótszy wariant ćwiczeniowy głównego projektu kalkulatora.
