# Karta oceny projektu

Ten dokument można skopiować do projektu studenta albo użyć podczas odbioru.
Karta porządkuje ocenę, ale nie zastępuje rozmowy o kodzie i pokazu działania.

## Dane projektu

| Pole | Wartość |
| --- | --- |
| Student |  |
| Temat projektu |  |
| Wariant | minimum / rozszerzony |
| Data odbioru |  |
| Link albo ścieżka do repozytorium |  |

## Warunek wstępny

Przed przyznaniem punktów sprawdź:

- [ ] projekt kompiluje się z instrukcji,
- [ ] da się uruchomić program,
- [ ] student potrafi wskazać główne pliki,
- [ ] student potrafi pokazać podstawowy przypadek użycia.

Jeśli projekt nie kompiluje się albo nie uruchamia, najpierw opisz poprawkę.
Pełną punktację warto przyznać dopiero po działającym wariancie minimum.

## Punktacja

| Obszar | Maks. | Punkty | Notatka |
| --- | ---: | ---: | --- |
| Funkcjonalność minimum | 30 |  |  |
| Poprawność techniczna | 20 |  |  |
| Organizacja kodu | 20 |  |  |
| Testy lub scenariusze sprawdzenia | 15 |  |  |
| Dokumentacja | 10 |  |  |
| Rozszerzenia | 5 |  |  |
| Razem | 100 |  |  |

## Funkcjonalność minimum

Sprawdź, czy program realizuje wymagania z sekcji `Minimalny wariant
zaliczeniowy` wybranego projektu.

- [ ] podstawowy przepływ działania działa od początku do końca,
- [ ] menu albo sposób obsługi jest zrozumiały,
- [ ] program zapisuje albo przetwarza dane zgodnie z tematem,
- [ ] program obsługuje co najmniej jeden błąd użytkownika,
- [ ] brak funkcji z minimum nie jest maskowany rozszerzeniami.

## Poprawność techniczna

- [ ] projekt kompiluje się bez błędów,
- [ ] projekt kompiluje się z ostrzeżeniami włączonymi przez `-Wall -Wextra -pedantic`,
- [ ] repozytorium nie zawiera plików wynikowych,
- [ ] operacje na plikach sprawdzają błędy,
- [ ] program nie kończy się awaryjnie po typowych błędnych danych.

## Organizacja kodu

- [ ] kod jest podzielony na funkcje albo metody,
- [ ] większe odpowiedzialności są rozdzielone na klasy albo moduły,
- [ ] `main` nie zawiera całej logiki projektu,
- [ ] nazwy plików, funkcji i klas są czytelne,
- [ ] student potrafi uzasadnić strukturę projektu.

## Testy lub scenariusze sprawdzenia

- [ ] istnieje przypadek poprawny,
- [ ] istnieje przypadek błędnych danych,
- [ ] istnieje przypadek graniczny,
- [ ] student potrafi powtórzyć scenariusze podczas odbioru,
- [ ] oczekiwane wyniki są opisane.

## Dokumentacja

- [ ] `README.md` opisuje cel projektu,
- [ ] `README.md` zawiera kompilację i uruchomienie,
- [ ] dokumentacja oddziela wariant minimum od rozszerzeń,
- [ ] opisuje strukturę katalogów albo najważniejsze pliki,
- [ ] opisuje ograniczenia lub znane braki.

## Rozmowa techniczna

Podczas odbioru poproś studenta o krótkie wyjaśnienie:

- gdzie program wczytuje dane,
- gdzie program zapisuje dane,
- gdzie znajduje się najważniejsza logika,
- jak obsługiwany jest błąd użytkownika,
- co student zmieniłby w kolejnej wersji.

## Decyzja

| Wynik | Zaznacz |
| --- | --- |
| Projekt zaliczony | [ ] |
| Projekt zaliczony po drobnych poprawkach | [ ] |
| Projekt wymaga ponownego odbioru | [ ] |

## Poprawki

Jeśli projekt wymaga poprawy, wpisz konkretne zadania:

1.
2.
3.

Poprawka powinna być sprawdzalna. Zamiast pisać `popraw kod`, wpisz na przykład
`dodaj obsługę pustego pliku wejściowego` albo `opisz komendę uruchomienia w README`.

## Notatki z odbioru

Zapisz krótko, co działało dobrze i co wymaga dalszej pracy.
