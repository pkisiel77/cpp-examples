# Gra kółko i krzyżyk

## Cel projektu

Celem projektu jest przygotowanie gry w kółko i krzyżyk na planszy `3x3`,
w której człowiek gra przeciwko komputerowi. Projekt ma pokazać modelowanie
planszy, sprawdzanie stanu gry, obsługę wejścia użytkownika oraz prostą
sztuczną inteligencję.

Najważniejsze wymaganie: komputer ma grać inteligentnie i nigdy nie przegrywać.
Dla klasycznej planszy `3x3` istnieje strategia gwarantująca komputerowi co
najmniej remis.

## Zakres funkcjonalny

Gra powinna umożliwiać:

- rozpoczęcie nowej gry,
- wybór znaku gracza, np. `X` albo `O`,
- wyświetlenie planszy w terminalu,
- wykonanie ruchu przez gracza,
- wykonanie ruchu przez komputer,
- odrzucenie ruchu na zajęte pole,
- sprawdzenie wygranej gracza,
- sprawdzenie wygranej komputera,
- wykrycie remisu,
- rozegranie kolejnej partii bez restartu programu.

Przykładowy widok planszy:

```text
  1 | 2 | 3
 ---+---+---
  4 | 5 | 6
 ---+---+---
  7 | 8 | 9
```

## Wymagania techniczne

Projekt powinien:

- być napisany w C++17,
- używać klasy do reprezentowania planszy,
- używać `enum class` do reprezentowania pól planszy,
- oddzielać logikę gry od interfejsu terminalowego,
- walidować dane wejściowe użytkownika,
- implementować strategię komputera, która nie przegrywa,
- rozdzielać deklaracje i implementacje na pliki `.h` i `.cpp`,
- kompilować się z flagami `-Wall -Wextra -pedantic`.

## Proponowana struktura plików

```text
tic-tac-toe/
  include/tic_tac_toe/
    board.h
    game.h
    player.h
    ai_player.h
    console_view.h
  src/
    board.cpp
    game.cpp
    ai_player.cpp
    console_view.cpp
    main.cpp
  tests/
    board_tests.cpp
    ai_player_tests.cpp
  build/
```

Znaczenie elementów:

- `Board` - plansza i operacje na polach,
- `Game` - przebieg partii i sprawdzanie stanu gry,
- `Player` - informacja o graczu i jego znaku,
- `AiPlayer` - wybór ruchu komputera,
- `ConsoleView` - wyświetlanie planszy i komunikatów.

## Model gry

Plansza powinna mieć dziewięć pól. Każde pole może być puste albo zajęte przez
jednego z graczy.

Przykład:

```cpp
enum class Cell {
    Empty,
    X,
    O
};

enum class GameState {
    InProgress,
    XWins,
    OWins,
    Draw
};

class Board {
public:
    bool makeMove(int position, Cell value);
    Cell at(int position) const;
    GameState state() const;

private:
    std::array<Cell, 9> cells_;
};
```

Pozycje mogą być numerowane od `1` do `9`, ponieważ jest to wygodne dla
użytkownika. Wewnątrz programu można je przeliczać na indeksy od `0` do `8`.

## Strategia komputera

Minimalna wersja strategii powinna:

1. Wygrać, jeśli komputer ma ruch kończący partię.
2. Zablokować wygraną gracza, jeśli gracz ma taki ruch.
3. Zająć środek, jeśli jest wolny.
4. Zająć róg, jeśli jest wolny.
5. Zająć dowolne wolne pole.

Wersja rekomendowana powinna użyć algorytmu minimax. Dla planszy `3x3` jest to
proste do policzenia, a komputer może grać optymalnie w każdej sytuacji.

## Minimalny wariant zaliczeniowy

Minimalna wersja projektu powinna zawierać:

1. Menu konsolowe z opcjami:
   - nowa gra,
   - zasady,
   - zakończ.
2. Planszę `3x3` wyświetlaną po każdym ruchu.
3. Walidację numeru pola.
4. Blokowanie ruchu na zajęte pole.
5. Sprawdzanie wszystkich linii wygranej:
   - trzy wiersze,
   - trzy kolumny,
   - dwie przekątne.
6. Wykrywanie remisu.
7. Komputer, który nie przegrywa.
8. Instrukcję kompilacji i uruchomienia w `README.md` projektu.

## Rozszerzenia dla chętnych

Możliwe rozszerzenia:

- poziomy trudności,
- gracz zaczyna albo komputer zaczyna,
- tryb dwóch graczy,
- licznik zwycięstw, porażek i remisów,
- zapis statystyk do pliku,
- testy automatyczne algorytmu komputera,
- kolorowe znaki w terminalu,
- większa plansza jako osobny wariant, np. `4x4`.

## Kryteria oceny

Projekt jest zaliczony, jeśli:

- kompiluje się bez błędów i ostrzeżeń,
- poprawnie wyświetla planszę,
- przyjmuje poprawne ruchy gracza,
- odrzuca niepoprawne ruchy gracza,
- poprawnie wykrywa wygraną,
- poprawnie wykrywa remis,
- komputer blokuje natychmiastową wygraną gracza,
- komputer wykorzystuje własną natychmiastową wygraną,
- komputer nigdy nie przegrywa przy poprawnej strategii,
- kod jest podzielony na moduły,
- zawiera instrukcję uruchomienia,
- zawiera testy albo opis ręcznych scenariuszy sprawdzenia.

## Scenariusze sprawdzenia

1. Rozpocznij grę i wykonaj ruch na wolne pole.
2. Spróbuj wykonać ruch na zajęte pole.
3. Ułóż sytuację, w której gracz ma dwa znaki w linii, i sprawdź, czy komputer
   blokuje trzeci znak.
4. Ułóż sytuację, w której komputer może wygrać jednym ruchem, i sprawdź, czy
   wybiera ruch wygrywający.
5. Rozegraj partię optymalnie po stronie gracza i sprawdź, czy wynik to remis.
6. Rozegraj kilka partii i sprawdź, czy program pozwala zacząć od nowa.
