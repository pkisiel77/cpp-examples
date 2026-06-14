# 10 - Projekty

Ten segment zbiera większe zadania projektowe i tematy zaliczeniowe. Projekty
mają połączyć materiał z wcześniejszych segmentów: podstawy języka, STL, klasy,
pliki, testy, organizację kodu i prostą dokumentację.

## Cele segmentu

Po zakończeniu segmentu student powinien umieć:

- wybrać temat projektu i doprecyzować wymagania,
- podzielić rozwiązanie na mniejsze moduły,
- dobrać kontenery i klasy do problemu,
- przygotować kompilowalny projekt wieloplikowy,
- dodać podstawowe testy albo scenariusze sprawdzenia,
- przygotować krótką dokumentację użytkową i techniczną,
- opisać ograniczenia oraz możliwe rozszerzenia projektu.

## Kategorie projektów

Jeśli nie wiesz, który temat wybrać, zacznij od
[przewodnika wyboru projektu](jak-wybrac-projekt.md). Dokument pomaga dobrać
projekt do poziomu trudności, czasu i materiału, który chcesz przećwiczyć.

### Narzędzia konsolowe

- [Projekt 01 - Logger](project-01-logger.md)
- [Projekt 08 - Kalkulator](project-08-kalkulator.md)
- [Projekt 09 - Kalkulator macierzy](project-09-kalkulator-macierzy.md)
- [Projekt 11 - Parser plików CSV](project-11-parser-csv.md)

### Systemy i aplikacje użytkowe

- [Projekt 02 - Kolejkowanie zamówień](project-02-kolejkowanie-zamowien.md)
- [Projekt 07 - Baza danych pojazdów](project-07-baza-pojazdow.md)
- [Projekt 10 - System zarządzania zadaniami](project-10-system-zadan.md)
- [Projekt 12 - Symulator bankomatu](project-12-symulator-bankomatu.md)

### Gry

- [Gra kółko i krzyżyk](gra-kolko-krzyzyk.md)
- [Projekt 04 - Tetris](project-04-tetris.md)
- [Projekt 05 - Snake](project-05-snake.md)
- [Projekt 06 - Pac-Man](project-06-pacman.md)

## Status porządkowania

Opisy w docelowym formacie:

- `gra-kolko-krzyzyk.md`,
- `project-01-logger.md`,
- `project-02-kolejkowanie-zamowien.md`,
- `project-04-tetris.md`,
- `project-05-snake.md`,
- `project-06-pacman.md`,
- `project-07-baza-pojazdow.md`,
- `project-08-kalkulator.md`,
- `project-09-kalkulator-macierzy.md`,
- `project-10-system-zadan.md`,
- `project-11-parser-csv.md`,
- `project-12-symulator-bankomatu.md`.

Uporządkowane materiały pomocnicze:

- `tnt-tasks/`.

## Dodatkowe zadania źródłowe

Katalog [tnt-tasks](tnt-tasks) zawiera uporządkowane zadania pomocnicze, które
można wykorzystać jako ćwiczenia, warianty projektów albo źródła do dalszego
przenoszenia do wcześniejszych segmentów.

## Docelowy format opisu projektu

Każdy docelowy opis projektu powinien mieć taki układ:

1. Cel projektu.
2. Zakres funkcjonalny.
3. Wymagania techniczne.
4. Proponowana struktura plików.
5. Model danych albo model domeny, jeśli projekt tego wymaga.
6. Minimalny wariant zaliczeniowy.
7. Rozszerzenia dla chętnych.
8. Kryteria oceny.
9. Scenariusze sprawdzenia.

W opisach projektów nie usuwamy pierwotnego sensu zadania, tylko doprecyzowujemy
go tak, aby student wiedział, co jest wersją minimalną, co jest rozszerzeniem
i jak sprawdzić poprawność rozwiązania.

## Wymagania dla rozwiązania

Projekt powinien zawierać:

- `README.md` z instrukcją kompilacji i uruchomienia,
- kod źródłowy podzielony na pliki,
- przykładowe dane wejściowe, jeśli są potrzebne,
- krótki opis decyzji projektowych,
- testy albo opis ręcznych scenariuszy sprawdzenia.

Przed oddaniem pracy student powinien przejść przez
[checklistę projektu](checklista-projektu.md). Checklista zbiera wymagania
techniczne, dokumentacyjne i demonstracyjne w jednym miejscu.

W trakcie pracy warto korzystać też z
[planu pracy nad projektem](plan-pracy-nad-projektem.md), który rozbija projekt
na małe etapy: start, model danych, wariant minimum, testy, dokumentację i pokaz.
Do odbioru i wpisania punktacji służy
[karta oceny projektu](karta-oceny-projektu.md).

## Wariant minimum i rozszerzenie

Każdy projekt należy oddawać w jednym z dwóch wariantów:

- wariant minimum - spełnia sekcję `Minimalny wariant zaliczeniowy`, kompiluje się i obsługuje podstawowe przypadki użycia,
- wariant rozszerzony - spełnia wariant minimum oraz co najmniej dwa punkty z sekcji `Rozszerzenia dla chętnych`.

Wariant rozszerzony nie zwalnia z jakości kodu. Najpierw musi działać stabilna wersja minimalna, dopiero później warto dodawać funkcje dodatkowe.

## Rubryka oceny projektu

Proponowana punktacja dla każdego projektu:

| Obszar | Punkty | Co jest oceniane |
| --- | ---: | --- |
| Funkcjonalność minimum | 30 | Działają wszystkie wymagania z wariantu minimalnego. |
| Poprawność techniczna | 20 | Projekt kompiluje się z `-Wall -Wextra -pedantic`, nie wymaga plików wynikowych w repozytorium i obsługuje błędne dane. |
| Organizacja kodu | 20 | Kod jest podzielony na funkcje, klasy i pliki zgodnie z problemem. Nazwy są czytelne. |
| Testy lub scenariusze sprawdzenia | 15 | Autor potrafi pokazać przypadki poprawne, graniczne i błędne. |
| Dokumentacja | 10 | `README.md` wyjaśnia kompilację, uruchomienie, strukturę projektu i ograniczenia. |
| Rozszerzenia | 5 | Projekt zawiera sensowne funkcje dodatkowe bez psucia wersji minimalnej. |

Ocena projektu powinna zaczynać się od uruchomienia wariantu minimalnego. Jeśli wariant minimalny nie działa, rozszerzenia nie powinny podnosić oceny ponad podstawowy próg zaliczenia.

## Kryteria zaliczenia segmentu

Student zalicza segment, jeśli potrafi samodzielnie:

- uruchomić projekt z instrukcji,
- wyjaśnić strukturę plików,
- wskazać główne klasy i funkcje,
- pokazać działające podstawowe przypadki użycia,
- obsłużyć błędne dane wejściowe,
- opisać, co można dodać w kolejnej wersji.

## Katalogi pomocnicze

- [jak-wybrac-projekt.md](jak-wybrac-projekt.md) - przewodnik wyboru tematu i pierwszego planu pracy.
- [plan-pracy-nad-projektem.md](plan-pracy-nad-projektem.md) - harmonogram pracy od pierwszej wersji do pokazu.
- [checklista-projektu.md](checklista-projektu.md) - lista kontroli przed oddaniem i pokazem projektu.
- [karta-oceny-projektu.md](karta-oceny-projektu.md) - karta odbioru, punktacji i poprawek.
- `tnt-tasks/` - starsze zadania źródłowe do dalszego uporządkowania.
- `archive/` - stare wersje plików po wchłonięciu ich treści do nowych opisów.
