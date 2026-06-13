# Projekt 04 - Tetris

## Cel projektu

Celem projektu jest przygotowanie gry Tetris działającej w terminalu. Projekt
ma pokazać reprezentację planszy, modelowanie klocków, obsługę kolizji,
pętlę gry, punktację oraz rozdzielenie logiki gry od wyświetlania.

Minimalna wersja może działać w terminalu tekstowym. Określenie "terminal
graficzny" można potraktować jako czytelny interfejs z ramką planszy,
kolorami ANSI albo prostymi znakami tekstowymi.

## Zakres funkcjonalny

Gra powinna umożliwiać:

- rozpoczęcie nowej gry,
- wyświetlenie planszy,
- generowanie kolejnych klocków,
- przesuwanie klocka w lewo i prawo,
- obracanie klocka,
- przyspieszenie opadania klocka,
- wykrywanie kolizji ze ścianami i innymi klockami,
- zatrzymanie klocka po dotknięciu dna albo bloków,
- usuwanie pełnych linii,
- naliczanie punktów,
- zakończenie gry po zapełnieniu górnej części planszy.

Przykładowy widok planszy:

```text
+----------+
|          |
|    []    |
|  [][][]  |
|          |
|[][][][][]|
+----------+
Wynik: 1200
```

## Wymagania techniczne

Projekt powinien:

- być napisany w C++17,
- używać klasy do reprezentowania planszy,
- używać klasy albo struktury do reprezentowania klocka,
- używać `enum class` do typów klocków,
- oddzielać logikę gry od interfejsu terminalowego,
- obsługiwać wejście użytkownika w pętli gry,
- walidować ruchy i obroty klocka przed ich wykonaniem,
- używać generatora liczb losowych z biblioteki standardowej,
- rozdzielać deklaracje i implementacje na pliki `.h` i `.cpp`,
- kompilować się z flagami `-Wall -Wextra -pedantic`.

## Proponowana struktura plików

```text
tetris/
  include/tetris/
    board.h
    tetromino.h
    game.h
    score.h
    console_view.h
    input.h
  src/
    board.cpp
    tetromino.cpp
    game.cpp
    score.cpp
    console_view.cpp
    input.cpp
    main.cpp
  tests/
    board_tests.cpp
    tetromino_tests.cpp
  build/
```

Znaczenie elementów:

- `Board` - plansza i zajęte pola,
- `Tetromino` - aktualny klocek i jego obroty,
- `Game` - pętla gry i reguły,
- `Score` - naliczanie punktów,
- `ConsoleView` - wyświetlanie planszy,
- `Input` - obsługa klawiszy albo komend gracza.

## Model gry

Plansza powinna mieć stały rozmiar, np. `10x20`. Każde pole może być puste
albo zajęte przez zatrzymany klocek.

Przykład:

```cpp
enum class TetrominoType {
    I,
    O,
    T,
    S,
    Z,
    J,
    L
};

struct Position {
    int row;
    int column;
};

class Board {
public:
    bool isInside(Position position) const;
    bool isOccupied(Position position) const;
    bool canPlace(const Tetromino& piece) const;
    int clearFullLines();

private:
    std::vector<std::vector<bool>> cells_;
};
```

Klocek można reprezentować jako zestaw czterech pozycji względem punktu
odniesienia. Obrót zmienia te pozycje, ale powinien być zaakceptowany tylko
wtedy, gdy nowy układ mieści się na planszy i nie nachodzi na zajęte pola.

## Pętla gry

Minimalna pętla gry powinna wykonywać powtarzalnie:

1. Wyświetlenie planszy.
2. Odczyt komendy gracza.
3. Próbę przesunięcia albo obrotu klocka.
4. Przesunięcie klocka o jeden wiersz w dół.
5. Zatrzymanie klocka, jeśli nie może opaść niżej.
6. Usunięcie pełnych linii.
7. Wygenerowanie nowego klocka.
8. Sprawdzenie warunku końca gry.

W prostej wersji można sterować komendami tekstowymi, np. `a`, `d`, `w`, `s`,
zamiast obsługiwać natychmiastowy odczyt klawiszy.

## Minimalny wariant zaliczeniowy

Minimalna wersja projektu powinna zawierać:

1. Menu konsolowe z opcjami:
   - nowa gra,
   - zasady,
   - zakończ.
2. Planszę o wymiarach co najmniej `10x20`.
3. Co najmniej cztery typy klocków.
4. Ruch w lewo, ruch w prawo i opadanie.
5. Obrót klocka.
6. Blokowanie ruchu poza planszę.
7. Blokowanie ruchu przez zajęte pola.
8. Usuwanie pełnej linii.
9. Punktację.
10. Warunek końca gry.
11. Instrukcję kompilacji i uruchomienia w `README.md` projektu.

## Rozszerzenia dla chętnych

Możliwe rozszerzenia:

- wszystkie siedem klasycznych klocków,
- podgląd następnego klocka,
- poziomy trudności,
- rosnąca prędkość opadania,
- zapis najlepszego wyniku do pliku,
- pauza,
- kolory ANSI,
- testy automatyczne kolizji i usuwania linii,
- tryb demonstracyjny z ustalonymi klockami,
- obsługa natychmiastowego odczytu klawiszy.

## Kryteria oceny

Projekt jest zaliczony, jeśli:

- kompiluje się bez błędów i ostrzeżeń,
- poprawnie wyświetla planszę,
- poprawnie generuje klocki,
- pozwala przesuwać i obracać klocek,
- nie pozwala wyjść klockiem poza planszę,
- nie pozwala przejść przez zajęte pola,
- zatrzymuje klocek po kolizji,
- usuwa pełne linie,
- nalicza punkty,
- kończy grę po zapełnieniu planszy,
- kod jest podzielony na moduły,
- zawiera instrukcję uruchomienia,
- zawiera testy albo opis ręcznych scenariuszy sprawdzenia.

## Scenariusze sprawdzenia

1. Uruchom nową grę i sprawdź, czy pojawia się plansza oraz pierwszy klocek.
2. Przesuń klocek w lewo i prawo.
3. Spróbuj przesunąć klocek poza lewą albo prawą ścianę.
4. Obróć klocek przy wolnej przestrzeni.
5. Spróbuj obrócić klocek przy ścianie albo zajętych polach.
6. Ułóż pełną linię i sprawdź, czy zostaje usunięta.
7. Doprowadź do zapełnienia górnej części planszy i sprawdź koniec gry.
