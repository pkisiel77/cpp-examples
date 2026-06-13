# C++ examples

Repozytorium jest uporządkowane jako kurs C++ podzielony na segmenty nauki. Każdy segment ma własny katalog i `README.md` z proponowaną kolejnością pracy.

## Ścieżka nauki

1. [00-start](00-start/README.md) - środowisko, kompilator, Git, CMake.
2. [01-podstawy](01-podstawy/README.md) - pierwszy program, wejście/wyjście, typy, zmienne, proste obliczenia.
3. [02-sterowanie-i-petle](02-sterowanie-i-petle/README.md) - instrukcje warunkowe, pętle, proste algorytmy.
4. [03-funkcje-tablice-napisy](03-funkcje-tablice-napisy/README.md) - funkcje, tablice, napisy, rozbijanie programu na części.
5. [04-wskazniki-referencje-pamiec](04-wskazniki-referencje-pamiec/README.md) - adresy, wskaźniki, referencje, podstawy pamięci.
6. [05-pliki-wyjatki](05-pliki-wyjatki/README.md) - pliki tekstowe, obsługa błędów, wyjątki.
7. [06-oop](06-oop/README.md) - klasy, obiekty, konstruktory, dziedziczenie, przeciążanie operatorów.
8. [07-stl-struktury-danych](07-stl-struktury-danych/README.md) - kontenery STL i podstawowe struktury danych.
9. [08-projekt-build-testy](08-projekt-build-testy/README.md) - organizacja projektu, preprocesor, build, testy, CI/CD.
10. [09-modern-cpp](09-modern-cpp/README.md) - elementy modern C++, wielowątkowość, moduły.
11. [10-projekty](10-projekty/README.md) - zadania projektowe i tematy zaliczeniowe.

## Konwencja segmentu

W każdym segmencie materiały są uporządkowane według schematu:

- `README.md` - cel segmentu i sugerowana kolejność.
- pliki lekcyjne - cel lekcji, wymagania wstępne, teoria, przykłady, zadania i kryteria zaliczenia.
- plik zadań segmentu - zestaw ćwiczeń od podstawowych do projektowych.
- `examples/` - kompilowalne przykłady `.cpp`, jeśli segment ich używa.
- `archive/` - pierwotne wersje materiałów zachowane do wglądu.

## Materiały pomocnicze

- [docs/prowadzacy.md](docs/prowadzacy.md) - przewodnik organizacyjny dla prowadzącego.
- [docs/plan-semestru.md](docs/plan-semestru.md) - przykładowy 15-tygodniowy rozkład zajęć.
- [docs/student.md](docs/student.md) - instrukcja pracy z repozytorium dla studenta.
- [_assets](./_assets) - media i pliki pomocnicze.
- [_archive](./_archive) - luźne notatki, linki i stare materiały, które nie są częścią głównej ścieżki.

## Sprawdzanie przykładów

Przykłady z głównej ścieżki można skompilować zbiorczo:

```sh
sh tools/check-examples.sh
```

Skrypt używa domyślnie `c++`, standardu C++17 i katalogu `/tmp/cpp-examples-build`. Można to zmienić zmiennymi środowiskowymi `CXX`, `STD` i `BUILD_DIR`.

Ten sam skrypt jest uruchamiany w GitHub Actions po `push` i `pull_request`.

## Status porządkowania

Główna ścieżka `00`-`10` została ujednolicona do wspólnego formatu. Materiały przygotowywane są po polsku. Kolejne prace powinny dotyczyć już jakości merytorycznej: rozbudowy przykładów, dodawania testów do większych zadań i przenoszenia wybranych materiałów z archiwów do lekcji.
