# 08 - Zadania

## Cel zestawu zadań

Ten plik zbiera zadania do segmentu [08 - Projekt, build i testy](README.md).
Zadania sprawdzają preprocesor, podział programu na pliki, strukturę katalogów,
kompilację, sprawdzanie składni, testy oraz podstawy CI/CD.

## Zasady wykonania

Każde zadanie powinno być zapisane w osobnym katalogu albo osobnym pliku `.cpp`,
jeśli zadanie jest krótkie. Program powinien kompilować się bez błędów.

Przykład kompilacji:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program
./program
```

Dla projektów wieloplikowych używaj katalogów `include`, `src`, `tests` i
`build`. Plików wynikowych nie dodawaj do commita.

## Wymagania jakościowe

W zadaniach z tego segmentu zwracaj uwagę na:

- kompilację z flagami `-std=c++17 -Wall -Wextra -pedantic`,
- oddzielenie deklaracji w `.h` od implementacji w `.cpp`,
- uruchamianie testów jako osobnego programu,
- build zapisujący artefakty do katalogu `build` albo `/tmp`,
- brak plików wynikowych, `.o` i tymczasowych katalogów w commicie.
- dokumentowanie komend build/test w `README.md` projektu.

## Poziom 1 - Preprocesor i nagłówki

### Zadanie 1. Własny nagłówek

Utwórz pliki:

- `greeting.h`,
- `greeting.cpp`,
- `main.cpp`.

W nagłówku zadeklaruj funkcję `printGreeting`, a w pliku `.cpp` dodaj jej
implementację.

Wymagania:

- `main.cpp` nie powinien znać szczegółów implementacji funkcji,
- kompilacja ma obejmować `main.cpp` i `greeting.cpp`,
- nagłówek nie powinien zawierać definicji funkcji, tylko deklarację.

### Zadanie 2. Guard

Dodaj do `greeting.h` klasyczny guard:

```cpp
#ifndef GREETING_H
#define GREETING_H

#endif
```

Dołącz nagłówek dwa razy w `main.cpp` i sprawdź, czy program nadal się
kompiluje.

W komentarzu zapisz, jaki problem rozwiązuje guard.

### Zadanie 3. Flaga debug

Dodaj fragment kodu, który wypisuje komunikat tylko wtedy, gdy program jest
kompilowany z flagą `DEBUG_MODE`.

Kompilacja:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic -DDEBUG_MODE main.cpp greeting.cpp -o app
```

Sprawdź program z flagą `DEBUG_MODE` i bez niej.

### Zadanie 4. Informacja diagnostyczna

Wypisz `__FILE__` oraz `__LINE__` w wybranej funkcji. Sprawdź, jak zmienia się
wynik po przeniesieniu instrukcji do innej linii.

Wynik powinien pomóc zrozumieć, z którego pliku i linii pochodzi komunikat.

## Poziom 2 - Podział na pliki

### Zadanie 5. Kalkulator

Utwórz moduł `calculator` z funkcjami:

- `add`,
- `subtract`,
- `multiply`,
- `divide`.

Podziel kod na pliki `calculator.h`, `calculator.cpp` i `main.cpp`.

Wymagania:

- `divide` ma obsługiwać dzielenie przez zero,
- nagłówek ma zawierać deklaracje wszystkich funkcji,
- `main.cpp` ma tylko demonstrować użycie modułu.

### Zadanie 6. Moduł tekstowy

Utwórz moduł `text_utils` z funkcjami:

- `toUpper`,
- `repeat`,
- `startsWith`.

Przygotuj osobny `main.cpp`, który demonstruje działanie funkcji.

Scenariusz sprawdzenia:

```text
toUpper("ala") -> "ALA"
repeat("ha", 3) -> "hahaha"
startsWith("program", "pro") -> true
```

### Zadanie 7. Błąd linkera

Celowo pomiń jeden plik `.cpp` w komendzie kompilacji. Zapisz w komentarzu, jaki
komunikat pokazał linker i jak go naprawić.

Po zapisaniu obserwacji przywróć poprawną komendę kompilacji.

### Zadanie 8. Interfejs i implementacja

Dla modułu `calculator` dopisz komentarz w nagłówku opisujący, co robi każda
funkcja. Implementację zostaw w pliku `.cpp`.

Komentarz w nagłówku powinien opisywać zachowanie funkcji, a nie szczegóły jej
implementacji.

## Poziom 3 - Struktura projektu i build

### Zadanie 9. Projekt `notes`

Utwórz projekt w strukturze:

```text
notes/
  include/notes/
  src/
  tests/
  build/
```

Projekt powinien przechowywać liczbę notatek i umożliwiać dodanie nowej notatki.

Minimalne pliki:

```text
notes/include/notes/notes.h
notes/src/notes.cpp
notes/src/main.cpp
notes/tests/notes_tests.cpp
notes/build/.gitignore
```

### Zadanie 10. Kompilacja z `-I`

Skompiluj projekt `notes`, używając flagi `-I`. Program powinien korzystać z
nagłówka w katalogu `include/notes`.

Przykład komendy:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic \
    -I notes/include \
    notes/src/main.cpp notes/src/notes.cpp \
    -o notes/build/notes
```

### Zadanie 11. Pliki obiektowe

Zbuduj projekt `notes` w dwóch krokach:

1. utwórz pliki `.o`,
2. zlinkuj je w program.

Pliki `.o` zapisz w katalogu `build/`.

Wymagania:

- osobno skompiluj `notes.cpp`,
- osobno skompiluj `main.cpp`,
- linkowanie wykonaj jako ostatni krok.

### Zadanie 12. Skrypt build

Dodaj skrypt `build.sh`, który:

- tworzy katalog `build`,
- kompiluje aplikację,
- uruchamia aplikację testowo.

Skrypt powinien zaczynać się od:

```sh
#!/bin/sh
set -eu
```

### Zadanie 13. Ignorowanie artefaktów

Dodaj `.gitignore` w katalogu `build`, aby nie commitować programów wynikowych i
plików `.o`.

Przykładowa zawartość:

```text
*
!.gitignore
```

## Poziom 4 - Sprawdzanie składni i testy

### Zadanie 14. `-fsyntax-only`

Sprawdź składnię wybranego pliku `.cpp` bez tworzenia programu wynikowego.

Użyj:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic -fsyntax-only plik.cpp
```

W komentarzu zapisz różnicę między sprawdzeniem składni a pełnym buildem.

### Zadanie 15. Ostrzeżenie jako błąd

Dodaj do programu nieużywaną zmienną. Skompiluj program z `-Werror` i zapisz w
komentarzu, co się stało.

Po wykonaniu obserwacji usuń nieużywaną zmienną, aby projekt znowu się
kompilował.

### Zadanie 16. Pierwszy test

Do projektu `notes` dodaj `tests/notes_tests.cpp`. Test powinien sprawdzić, czy
nowy obiekt ma `0` notatek.

Test powinien zwrócić `0`, jeśli przechodzi, i `1`, jeśli wykryje błąd.

### Zadanie 17. Test dodawania

Dodaj test sprawdzający, czy dodanie jednej notatki zwiększa licznik do `1`.

Dodaj też test dodania dwóch notatek.

### Zadanie 18. Funkcja `expectEqual`

Dodaj funkcję pomocniczą `expectEqual`, która wypisuje oczekiwaną i otrzymaną
wartość, jeśli test nie przechodzi.

Funkcja powinna zwracać `bool`, aby można było składać kilka warunków testowych.

### Zadanie 19. Testy w buildzie

Rozbuduj `build.sh`, aby kompilował i uruchamiał testy. Skrypt powinien kończyć
się błędem, jeśli test nie przechodzi.

Wymagania:

- aplikacja i testy powinny być osobnymi programami wynikowymi,
- testy powinny uruchamiać się po kompilacji,
- jeśli test zwróci `1`, skrypt ma zakończyć się błędem.

## Poziom 5 - CI/CD i mini-projekt

### Zadanie 20. Lokalny odpowiednik CI

Przygotuj jedną komendę, która uruchamia cały build i testy projektu `notes`.
Zapisz ją w komentarzu w pliku `README.md` projektu.

Przykład:

```sh
sh build.sh
```

### Zadanie 21. Przykładowy workflow

Przygotuj plik `github-actions-cpp.yml`, który:

- pobiera repozytorium,
- pokazuje wersję kompilatora,
- uruchamia `build.sh`.

Nie musi być aktywowany w `.github/workflows`.

Workflow powinien używać `ubuntu-latest` i kroku `actions/checkout`.

### Zadanie 22. Analiza awarii

Celowo zepsuj jeden test i uruchom build. Zapisz w komentarzu:

- która komenda się nie powiodła,
- jaki był komunikat,
- jak naprawić problem.

Po analizie przywróć poprawny test.

### Zadanie 23. Mini-projekt `gradebook`

Przygotuj projekt `gradebook` w strukturze:

```text
gradebook/
  include/gradebook/
  src/
  tests/
  build/
```

Projekt powinien umożliwiać:

- dodanie oceny,
- policzenie średniej,
- sprawdzenie, czy wszystkie oceny są poprawne,
- uruchomienie testów przez `build.sh`.

Wymagania:

- logika ocen powinna być w osobnym module,
- `main.cpp` powinien tylko demonstrować użycie modułu,
- testy powinny sprawdzać pusty dziennik, poprawne oceny i błędne oceny.

### Zadanie 24. Dokumentacja builda

Dodaj do mini-projektu `README.md`, który zawiera:

- opis struktury katalogów,
- komendę kompilacji aplikacji,
- komendę kompilacji testów,
- komendę uruchamiającą cały build,
- informację, czego nie commitować.

Jeśli chcesz przećwiczyć większy projekt wieloplikowy przed projektem
zaliczeniowym, wykonaj
[09-cwiczenie-kalkulator-rpn.md](09-cwiczenie-kalkulator-rpn.md).

## Wariant minimum

Do zaliczenia segmentu wykonaj co najmniej:

1. Zadanie 1 albo 2.
2. Zadanie 5 albo 6.
3. Zadanie 9.
4. Zadanie 10 albo 11.
5. Zadanie 16 albo 17.
6. Zadanie 19 albo 20.
7. Mini-sprawdzian segmentu z końca pliku.

Zadania 21-24 są rozszerzone albo projektowe. Możesz je robić po wykonaniu
wariantu minimum.

## Mini-sprawdzian segmentu

Przygotuj mały projekt `counter-app` w strukturze:

```text
counter-app/
  include/counter/counter.h
  src/counter.cpp
  src/main.cpp
  tests/counter_tests.cpp
  build/.gitignore
  build.sh
  README.md
```

Projekt powinien:

- mieć klasę albo moduł licznika z operacjami `increment`, `reset`, `value`,
- kompilować aplikację i testy przez `build.sh`,
- uruchamiać testy automatycznie w `build.sh`,
- zapisywać artefakty w `build`,
- mieć `README.md` z komendą uruchomienia pełnego builda.

Scenariusz sprawdzenia:

```text
sh build.sh
All tests passed
```

## Kryteria zaliczenia segmentu

Student zalicza segment, jeśli potrafi samodzielnie:

- utworzyć nagłówek z guardem,
- rozdzielić program na deklaracje i implementacje,
- skompilować projekt z wieloma plikami `.cpp`,
- użyć katalogów `include`, `src`, `tests` i `build`,
- użyć flag `-I`, `-Wall`, `-Wextra`, `-pedantic`, `-fsyntax-only`,
- zbudować program przez pliki obiektowe,
- napisać prosty skrypt build,
- napisać test jako osobny program,
- sprawić, żeby test zwracał poprawny kod zakończenia,
- przygotować przykładowy workflow CI uruchamiający lokalny build.

## Checklista oddania

Przed oddaniem rozwiązań sprawdź:

- [ ] Projekt kompiluje się z `-Wall -Wextra -pedantic`.
- [ ] Deklaracje są w `.h`, a implementacje w `.cpp`.
- [ ] Komenda build zawiera wszystkie potrzebne pliki `.cpp`.
- [ ] Nagłówki mają guard albo `#pragma once`.
- [ ] Testy są osobnym programem i zwracają kod błędu przy niepowodzeniu.
- [ ] `build.sh` kończy się błędem, jeśli kompilacja albo test się nie powiedzie.
- [ ] Artefakty build, `.o` i programy wynikowe nie są commitowane.
- [ ] `README.md` projektu opisuje kompilację, testy i strukturę katalogów.

## Archiwum

Oryginalne materiały źródłowe tego segmentu są zachowane w katalogu [archive](archive).
