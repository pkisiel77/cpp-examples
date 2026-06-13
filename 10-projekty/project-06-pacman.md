# Projekt 06 - Pac-Man

## Cel projektu

Celem projektu jest przygotowanie uproszczonej gry Pac-Man działającej w
terminalu. Projekt ma pokazać reprezentację labiryntu, ruch postaci,
zbieranie punktów, obsługę przeciwników, kolizje, punktację oraz rozdzielenie
logiki gry od wyświetlania.

Minimalna wersja może działać w terminalu tekstowym. Określenie "terminal
graficzny" można potraktować jako czytelny interfejs z labiryntem złożonym ze
znaków ASCII i opcjonalnymi kolorami ANSI.

## Zakres funkcjonalny

Gra powinna umożliwiać:

- rozpoczęcie nowej gry,
- wyświetlenie labiryntu,
- sterowanie graczem w czterech kierunkach,
- blokowanie przejścia przez ściany,
- zbieranie punktów z planszy,
- naliczanie wyniku,
- poruszanie przeciwników,
- wykrywanie kolizji z przeciwnikiem,
- wykrywanie wygranej po zebraniu wszystkich punktów,
- wykrywanie przegranej po utracie życia,
- rozpoczęcie kolejnej gry bez restartu programu.

Przykładowy widok labiryntu:

```text
###############
#P....#......G#
#.##.#.####...#
#....#........#
###############
Wynik: 80  Zycia: 3
```

## Wymagania techniczne

Projekt powinien:

- być napisany w C++17,
- używać klasy do reprezentowania labiryntu,
- używać klasy albo struktury do reprezentowania postaci,
- używać `enum class` do typów pól planszy,
- oddzielać logikę gry od interfejsu terminalowego,
- walidować ruchy przed ich wykonaniem,
- mieć prostą strategię ruchu przeciwników,
- rozdzielać deklaracje i implementacje na pliki `.h` i `.cpp`,
- kompilować się z flagami `-Wall -Wextra -pedantic`.

## Proponowana struktura plików

```text
pacman/
  include/pacman/
    maze.h
    character.h
    player.h
    ghost.h
    game.h
    score.h
    console_view.h
    input.h
  src/
    maze.cpp
    character.cpp
    player.cpp
    ghost.cpp
    game.cpp
    score.cpp
    console_view.cpp
    input.cpp
    main.cpp
  tests/
    maze_tests.cpp
    game_tests.cpp
  data/
    level-01.txt
  build/
```

Znaczenie elementów:

- `Maze` - labirynt, ściany, punkty i puste pola,
- `Character` - wspólne dane postaci na planszy,
- `Player` - gracz sterowany z klawiatury,
- `Ghost` - przeciwnik poruszany przez program,
- `Game` - pętla gry i reguły,
- `Score` - naliczanie punktów,
- `ConsoleView` - wyświetlanie labiryntu,
- `Input` - obsługa komend gracza.

## Model gry

Labirynt może być wczytywany z pliku tekstowego albo zdefiniowany w kodzie.
Każdy znak oznacza inny typ pola.

Przykładowe znaczenie znaków:

- `#` - ściana,
- `.` - punkt do zebrania,
- `P` - pozycja startowa gracza,
- `G` - pozycja startowa przeciwnika,
- spacja - puste pole.

Przykład:

```cpp
enum class Tile {
    Wall,
    Empty,
    Dot
};

struct Position {
    int row;
    int column;
};

class Maze {
public:
    bool isInside(Position position) const;
    bool isWall(Position position) const;
    bool hasDot(Position position) const;
    void collectDot(Position position);
    int remainingDots() const;

private:
    std::vector<std::vector<Tile>> tiles_;
};
```

## Ruch przeciwników

Minimalna wersja może używać prostego ruchu przeciwników:

1. Przeciwnik próbuje iść w obecnym kierunku.
2. Jeśli trafia na ścianę, wybiera losowy dostępny kierunek.
3. Jeśli wejdzie na pole gracza, gracz traci życie albo gra się kończy.

Wersja rozszerzona może dodać prostą pogoń za graczem, np. wybór ruchu, który
zmniejsza odległość Manhattan od gracza.

## Pętla gry

Minimalna pętla gry powinna wykonywać powtarzalnie:

1. Wyświetlenie labiryntu.
2. Odczyt komendy gracza.
3. Próbę ruchu gracza.
4. Zebranie punktu, jeśli gracz wszedł na pole z punktem.
5. Ruch przeciwników.
6. Sprawdzenie kolizji z przeciwnikiem.
7. Sprawdzenie warunku wygranej.
8. Aktualizację wyniku i liczby żyć.

W prostej wersji można sterować komendami tekstowymi, np. `w`, `a`, `s`, `d`,
zamiast obsługiwać natychmiastowy odczyt klawiszy.

## Minimalny wariant zaliczeniowy

Minimalna wersja projektu powinna zawierać:

1. Menu konsolowe z opcjami:
   - nowa gra,
   - zasady,
   - zakończ.
2. Labirynt o wymiarach co najmniej `15x8`.
3. Gracza poruszającego się w czterech kierunkach.
4. Blokowanie ruchu przez ściany.
5. Punkty do zebrania.
6. Co najmniej jednego przeciwnika.
7. Prosty ruch przeciwnika.
8. Kolizję z przeciwnikiem.
9. Punktację.
10. Warunek wygranej po zebraniu wszystkich punktów.
11. Warunek przegranej po kolizji albo utracie żyć.
12. Instrukcję kompilacji i uruchomienia w `README.md` projektu.

## Rozszerzenia dla chętnych

Możliwe rozszerzenia:

- kilka poziomów wczytywanych z plików,
- kilku przeciwników,
- różne strategie przeciwników,
- życia gracza,
- bonusowe punkty,
- czasowa możliwość zjadania przeciwników,
- zapis najlepszego wyniku do pliku,
- kolory ANSI,
- testy automatyczne ruchu i kolizji,
- prosty edytor poziomów w pliku tekstowym.

## Kryteria oceny

Projekt jest zaliczony, jeśli:

- kompiluje się bez błędów i ostrzeżeń,
- poprawnie wyświetla labirynt,
- poprawnie porusza graczem,
- blokuje przechodzenie przez ściany,
- poprawnie zbiera punkty,
- nalicza wynik,
- porusza przeciwnikiem,
- wykrywa kolizję z przeciwnikiem,
- wykrywa wygraną po zebraniu punktów,
- wykrywa przegraną,
- kod jest podzielony na moduły,
- zawiera instrukcję uruchomienia,
- zawiera testy albo opis ręcznych scenariuszy sprawdzenia.

## Scenariusze sprawdzenia

1. Uruchom nową grę i sprawdź, czy pojawia się labirynt, gracz i przeciwnik.
2. Spróbuj przejść graczem przez ścianę.
3. Przejdź przez kilka pól z punktami i sprawdź wynik.
4. Doprowadź do kolizji z przeciwnikiem i sprawdź przegraną albo utratę życia.
5. Zbierz wszystkie punkty i sprawdź warunek wygranej.
6. Rozpocznij nową grę po zakończeniu poprzedniej.
