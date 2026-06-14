# Jak wybrać projekt

Ten dokument pomaga dobrać temat projektu do poziomu zaawansowania, czasu i
materiału, który student chce przećwiczyć. Najpierw wybierz stabilny wariant
minimum, a dopiero potem planuj rozszerzenia.

## 1. Wybierz poziom trudności

### Poziom podstawowy

Dla osób, które chcą przećwiczyć funkcje, pliki, proste klasy i menu konsolowe:

- [Projekt 01 - Logger](project-01-logger.md),
- [Projekt 08 - Kalkulator](project-08-kalkulator.md),
- [Projekt 11 - Parser plików CSV](project-11-parser-csv.md),
- [Gra kółko i krzyżyk](gra-kolko-krzyzyk.md).

### Poziom średni

Dla osób, które chcą użyć kilku klas, kontenerów STL i zapisu do pliku:

- [Projekt 02 - Kolejkowanie zamówień](project-02-kolejkowanie-zamowien.md),
- [Projekt 07 - Baza danych pojazdów](project-07-baza-pojazdow.md),
- [Projekt 10 - System zarządzania zadaniami](project-10-system-zadan.md),
- [Projekt 09 - Kalkulator macierzy](project-09-kalkulator-macierzy.md).

### Poziom rozszerzony

Dla osób, które chcą połączyć logikę gry, pętlę programu, stan obiektów i
więcej przypadków brzegowych:

- [Projekt 04 - Tetris](project-04-tetris.md),
- [Projekt 05 - Snake](project-05-snake.md),
- [Projekt 06 - Pac-Man](project-06-pacman.md).

## 2. Dopasuj projekt do materiału

| Chcesz przećwiczyć | Wybierz |
| --- | --- |
| Pliki tekstowe i walidację | Logger, Parser CSV, System zadań |
| Klasy i enkapsulację | Baza pojazdów, System zadań, Kalkulator macierzy |
| STL i kolejki | Kolejkowanie zamówień, System zadań |
| Algorytmy i parsowanie | Kalkulator, Parser CSV |
| Pętlę gry i stan planszy | Kółko i krzyżyk, Snake, Tetris, Pac-Man |
| Testy i strukturę projektu | Każdy projekt, szczególnie Logger albo Kalkulator |

## 3. Sprawdź realny zakres

Przed zatwierdzeniem tematu odpowiedz na pytania:

- Czy umiesz opisać wariant minimum w pięciu punktach?
- Czy projekt da się uruchomić w terminalu bez dodatkowych bibliotek?
- Czy jesteś w stanie przygotować pierwszą działającą wersję w ciągu jednych lub dwóch zajęć?
- Czy wiesz, jakie dane program będzie przechowywał?
- Czy potrafisz wymienić trzy scenariusze sprawdzenia?

Jeśli odpowiedź na kilka pytań brzmi `nie`, wybierz prostszy temat albo zmniejsz
zakres wariantu minimum.

## 4. Przygotuj pierwszy plan pracy

Dobry pierwszy plan ma małe kroki:

1. Utwórz strukturę katalogów projektu.
2. Dodaj minimalny `README.md` z komendą kompilacji.
3. Napisz najprostszy program, który się kompiluje.
4. Dodaj model danych albo pierwszą klasę.
5. Dodaj jedną funkcję z wariantu minimum.
6. Uruchom program i zapisz scenariusz sprawdzenia.
7. Dopiero potem dodawaj kolejne funkcje.

## 5. Nie zaczynaj od rozszerzeń

Rozszerzenia są oceniane dopiero wtedy, gdy wariant minimum działa stabilnie.
Najczęstszy błąd to rozpoczęcie od funkcji dodatkowych, zanim program potrafi
wykonać podstawowy przypadek użycia od początku do końca.

Przykład dobrej kolejności:

1. Kalkulator najpierw liczy `2 + 3`.
2. Potem obsługuje `+`, `-`, `*`, `/`.
3. Potem obsługuje błędy.
4. Dopiero później dodaje historię, funkcje matematyczne i eksport.

## 6. Przed oddaniem

Przed pokazem projektu przejdź przez:

- [checklistę projektu](checklista-projektu.md),
- scenariusze sprawdzenia z opisu wybranego projektu,
- własny `README.md` projektu.
