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

## Poziom 1 - Preprocesor i nagłówki

### Zadanie 1. Własny nagłówek

Utwórz pliki:

- `greeting.h`,
- `greeting.cpp`,
- `main.cpp`.

W nagłówku zadeklaruj funkcję `printGreeting`, a w pliku `.cpp` dodaj jej
implementację.

### Zadanie 2. Guard

Dodaj do `greeting.h` klasyczny guard:

```cpp
#ifndef GREETING_H
#define GREETING_H

#endif
```

Dołącz nagłówek dwa razy w `main.cpp` i sprawdź, czy program nadal się
kompiluje.

### Zadanie 3. Flaga debug

Dodaj fragment kodu, który wypisuje komunikat tylko wtedy, gdy program jest
kompilowany z flagą `DEBUG_MODE`.

Kompilacja:

```sh
c++ -std=c++17 -DDEBUG_MODE main.cpp greeting.cpp -o app
```

### Zadanie 4. Informacja diagnostyczna

Wypisz `__FILE__` oraz `__LINE__` w wybranej funkcji. Sprawdź, jak zmienia się
wynik po przeniesieniu instrukcji do innej linii.

## Poziom 2 - Podział na pliki

### Zadanie 5. Kalkulator

Utwórz moduł `calculator` z funkcjami:

- `add`,
- `subtract`,
- `multiply`,
- `divide`.

Podziel kod na pliki `calculator.h`, `calculator.cpp` i `main.cpp`.

### Zadanie 6. Moduł tekstowy

Utwórz moduł `text_utils` z funkcjami:

- `toUpper`,
- `repeat`,
- `startsWith`.

Przygotuj osobny `main.cpp`, który demonstruje działanie funkcji.

### Zadanie 7. Błąd linkera

Celowo pomiń jeden plik `.cpp` w komendzie kompilacji. Zapisz w komentarzu, jaki
komunikat pokazał linker i jak go naprawić.

### Zadanie 8. Interfejs i implementacja

Dla modułu `calculator` dopisz komentarz w nagłówku opisujący, co robi każda
funkcja. Implementację zostaw w pliku `.cpp`.

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

### Zadanie 10. Kompilacja z `-I`

Skompiluj projekt `notes`, używając flagi `-I`. Program powinien korzystać z
nagłówka w katalogu `include/notes`.

### Zadanie 11. Pliki obiektowe

Zbuduj projekt `notes` w dwóch krokach:

1. utwórz pliki `.o`,
2. zlinkuj je w program.

Pliki `.o` zapisz w katalogu `build/`.

### Zadanie 12. Skrypt build

Dodaj skrypt `build.sh`, który:

- tworzy katalog `build`,
- kompiluje aplikację,
- uruchamia aplikację testowo.

### Zadanie 13. Ignorowanie artefaktów

Dodaj `.gitignore` w katalogu `build`, aby nie commitować programów wynikowych i
plików `.o`.

## Poziom 4 - Sprawdzanie składni i testy

### Zadanie 14. `-fsyntax-only`

Sprawdź składnię wybranego pliku `.cpp` bez tworzenia programu wynikowego.

Użyj:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic -fsyntax-only plik.cpp
```

### Zadanie 15. Ostrzeżenie jako błąd

Dodaj do programu nieużywaną zmienną. Skompiluj program z `-Werror` i zapisz w
komentarzu, co się stało.

### Zadanie 16. Pierwszy test

Do projektu `notes` dodaj `tests/notes_tests.cpp`. Test powinien sprawdzić, czy
nowy obiekt ma `0` notatek.

### Zadanie 17. Test dodawania

Dodaj test sprawdzający, czy dodanie jednej notatki zwiększa licznik do `1`.

### Zadanie 18. Funkcja `expectEqual`

Dodaj funkcję pomocniczą `expectEqual`, która wypisuje oczekiwaną i otrzymaną
wartość, jeśli test nie przechodzi.

### Zadanie 19. Testy w buildzie

Rozbuduj `build.sh`, aby kompilował i uruchamiał testy. Skrypt powinien kończyć
się błędem, jeśli test nie przechodzi.

## Poziom 5 - CI/CD i mini-projekt

### Zadanie 20. Lokalny odpowiednik CI

Przygotuj jedną komendę, która uruchamia cały build i testy projektu `notes`.
Zapisz ją w komentarzu w pliku `README.md` projektu.

### Zadanie 21. Przykładowy workflow

Przygotuj plik `github-actions-cpp.yml`, który:

- pobiera repozytorium,
- pokazuje wersję kompilatora,
- uruchamia `build.sh`.

Nie musi być aktywowany w `.github/workflows`.

### Zadanie 22. Analiza awarii

Celowo zepsuj jeden test i uruchom build. Zapisz w komentarzu:

- która komenda się nie powiodła,
- jaki był komunikat,
- jak naprawić problem.

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

### Zadanie 24. Dokumentacja builda

Dodaj do mini-projektu `README.md`, który zawiera:

- opis struktury katalogów,
- komendę kompilacji aplikacji,
- komendę kompilacji testów,
- komendę uruchamiającą cały build,
- informację, czego nie commitować.

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

## Archiwum

Oryginalne materiały źródłowe tego segmentu są zachowane w katalogu [archive](archive).
