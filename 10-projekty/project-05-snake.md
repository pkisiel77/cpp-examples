# Projekt 05 - Snake

## Cel projektu

Celem projektu jest przygotowanie gry Snake działającej w terminalu. Projekt
ma pokazać reprezentację planszy, modelowanie ruchu w czasie, obsługę kolizji,
generowanie losowych elementów, punktację oraz rozdzielenie logiki gry od
wyświetlania.

Minimalna wersja może działać w terminalu tekstowym. Określenie "terminal
graficzny" można potraktować jako czytelny interfejs z ramką planszy, znakami
ASCII i opcjonalnymi kolorami ANSI.

## Zakres funkcjonalny

Gra powinna umożliwiać:

- rozpoczęcie nowej gry,
- wyświetlenie planszy,
- sterowanie kierunkiem ruchu węża,
- automatyczny ruch węża w pętli gry,
- generowanie jedzenia w losowym wolnym polu,
- zwiększenie długości węża po zjedzeniu jedzenia,
- naliczanie punktów,
- wykrywanie kolizji ze ścianą,
- wykrywanie kolizji węża z samym sobą,
- zakończenie gry po kolizji,
- rozpoczęcie kolejnej gry bez restartu programu.

Przykładowy widok planszy:

```text
+------------+
|            |
|    @***    |
|       *    |
|   F   *    |
|            |
+------------+
Wynik: 40
```

## Wymagania techniczne

Projekt powinien:

- być napisany w C++17,
- używać klasy do reprezentowania planszy,
- używać klasy albo struktury do reprezentowania węża,
- używać `enum class` do kierunku ruchu,
- oddzielać logikę gry od interfejsu terminalowego,
- walidować zmianę kierunku, aby nie zawrócić bezpośrednio w siebie,
- używać generatora liczb losowych z biblioteki standardowej,
- rozdzielać deklaracje i implementacje na pliki `.h` i `.cpp`,
- kompilować się z flagami `-Wall -Wextra -pedantic`.

## Proponowana struktura plików

```text
snake/
  include/snake/
    board.h
    snake.h
    food.h
    game.h
    score.h
    console_view.h
    input.h
  src/
    board.cpp
    snake.cpp
    food.cpp
    game.cpp
    score.cpp
    console_view.cpp
    input.cpp
    main.cpp
  tests/
    snake_tests.cpp
    board_tests.cpp
  build/
```

Znaczenie elementów:

- `Board` - rozmiar planszy i sprawdzanie granic,
- `Snake` - pozycje segmentów węża i zmiana kierunku,
- `Food` - pozycja jedzenia,
- `Game` - pętla gry i reguły,
- `Score` - naliczanie punktów,
- `ConsoleView` - wyświetlanie planszy,
- `Input` - obsługa komend gracza.

## Model gry

Wąż może być reprezentowany jako lista pozycji. Pierwszy element listy to głowa,
a kolejne elementy to segmenty ciała.

Przykład:

```cpp
enum class Direction {
    Up,
    Down,
    Left,
    Right
};

struct Position {
    int row;
    int column;
};

class Snake {
public:
    Position head() const;
    void changeDirection(Direction direction);
    void move(bool grow);
    bool contains(Position position) const;

private:
    std::deque<Position> segments_;
    Direction direction_;
};
```

Do przechowywania segmentów dobrze pasuje `std::deque`, ponieważ w każdym kroku
dodajemy nową głowę i zwykle usuwamy ostatni segment ogona.

## Pętla gry

Minimalna pętla gry powinna wykonywać powtarzalnie:

1. Wyświetlenie planszy.
2. Odczyt komendy gracza.
3. Zmianę kierunku, jeśli jest poprawna.
4. Wyliczenie nowej pozycji głowy.
5. Sprawdzenie kolizji.
6. Sprawdzenie, czy wąż zjadł jedzenie.
7. Przesunięcie węża i ewentualne zwiększenie długości.
8. Wygenerowanie nowego jedzenia, jeśli poprzednie zostało zjedzone.
9. Aktualizację wyniku.

W prostej wersji można sterować komendami tekstowymi, np. `w`, `a`, `s`, `d`,
zamiast obsługiwać natychmiastowy odczyt klawiszy.

## Minimalny wariant zaliczeniowy

Minimalna wersja projektu powinna zawierać:

1. Menu konsolowe z opcjami:
   - nowa gra,
   - zasady,
   - zakończ.
2. Planszę o wymiarach co najmniej `20x10`.
3. Węża złożonego z co najmniej trzech segmentów.
4. Sterowanie w czterech kierunkach.
5. Blokadę bezpośredniego zawracania.
6. Losowe generowanie jedzenia.
7. Wzrost węża po zjedzeniu jedzenia.
8. Kolizję ze ścianą.
9. Kolizję z własnym ciałem.
10. Punktację.
11. Warunek końca gry.
12. Instrukcję kompilacji i uruchomienia w `README.md` projektu.

## Rozszerzenia dla chętnych

Możliwe rozszerzenia:

- rosnąca prędkość gry,
- zapis najlepszego wyniku do pliku,
- pauza,
- przeszkody na planszy,
- przechodzenie przez krawędzie planszy jako osobny tryb,
- kolory ANSI,
- poziomy trudności,
- testy automatyczne ruchu i kolizji,
- tryb demonstracyjny z ustalonymi pozycjami jedzenia,
- obsługa natychmiastowego odczytu klawiszy.

## Kryteria oceny

Projekt jest zaliczony, jeśli:

- kompiluje się bez błędów i ostrzeżeń,
- poprawnie wyświetla planszę,
- poprawnie przesuwa węża,
- poprawnie zmienia kierunek ruchu,
- blokuje bezpośrednie zawracanie,
- generuje jedzenie na wolnym polu,
- zwiększa długość węża po zjedzeniu jedzenia,
- nalicza punkty,
- wykrywa kolizję ze ścianą,
- wykrywa kolizję z własnym ciałem,
- kończy grę po kolizji,
- kod jest podzielony na moduły,
- zawiera instrukcję uruchomienia,
- zawiera testy albo opis ręcznych scenariuszy sprawdzenia.

## Scenariusze sprawdzenia

1. Uruchom nową grę i sprawdź, czy pojawia się plansza, wąż i jedzenie.
2. Zmień kierunek ruchu węża we wszystkich czterech kierunkach.
3. Spróbuj zawrócić bezpośrednio w przeciwną stronę.
4. Doprowadź węża do jedzenia i sprawdź wzrost długości oraz wynik.
5. Doprowadź węża do ściany i sprawdź koniec gry.
6. Doprowadź do kolizji z własnym ciałem i sprawdź koniec gry.
7. Rozpocznij nową grę po zakończeniu poprzedniej.
