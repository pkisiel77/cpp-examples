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
- `tests/` - proste testy automatyczne bez zewnętrznego frameworka, jeśli segment ich używa.
- `archive/` - pierwotne wersje materiałów zachowane do wglądu.

## Materiały pomocnicze

- [docs/prowadzacy.md](docs/prowadzacy.md) - przewodnik organizacyjny dla prowadzącego.
- [docs/plan-semestru.md](docs/plan-semestru.md) - przykładowy 15-tygodniowy rozkład zajęć.
- [docs/postepy-i-ocenianie.md](docs/postepy-i-ocenianie.md) - punkty kontrolne, poziomy osiągnięć i model oceniania.
- [docs/student.md](docs/student.md) - instrukcja pracy z repozytorium dla studenta.
- [docs/checklista-oddania.md](docs/checklista-oddania.md) - lista kontrolna przed oddaniem i odbiorem pracy.
- [docs/walidacja-repo.md](docs/walidacja-repo.md) - lokalne sprawdzanie przykładów, testów i CI.
- [docs/przyklady-do-uzupelnienia.md](docs/przyklady-do-uzupelnienia.md) - audyt przykładów `.cpp` i priorytety uzupełnień.
- [10-projekty/checklista-projektu.md](10-projekty/checklista-projektu.md) - lista kontroli projektu zaliczeniowego.
- [templates](templates) - szablony oddawania krótkich zadań i projektów.
- [_assets](./_assets) - media i pliki pomocnicze.
- [_archive](./_archive) - luźne notatki, linki i stare materiały, które nie są częścią głównej ścieżki.

## Ćwiczenia pomostowe

Po wybranych segmentach dostępne są większe ćwiczenia, które łączą kilka lekcji
i przygotowują do pracy projektowej:

- [minimum, maksimum i średnia](02-sterowanie-i-petle/07-cwiczenie-min-max-srednia.md) - pętle, walidacja i wynik częściowy,
- [szyfr GADERYPOLUKI](03-funkcje-tablice-napisy/07-cwiczenie-szyfr-gaderypoluki.md) - funkcje i przetwarzanie napisów,
- [figury i polimorfizm](06-oop/08-cwiczenie-figury-polimorfizm.md) - dziedziczenie, klasa abstrakcyjna i polimorfizm,
- [kalkulator RPN](08-projekt-build-testy/09-cwiczenie-kalkulator-rpn.md) - projekt wieloplikowy, build i testy.

## Sprawdzanie przykładów

Przykłady z głównej ścieżki można skompilować zbiorczo:

```sh
sh tools/check-examples.sh
```

Skrypt używa domyślnie `c++`, standardu C++17 i katalogu `/tmp/cpp-examples-build`. Można to zmienić zmiennymi środowiskowymi `CXX`, `STD` i `BUILD_DIR`.

Ten sam skrypt jest uruchamiany w GitHub Actions po `push` i `pull_request`.
Szczegóły użycia i interpretacji wyników są opisane w
[docs/walidacja-repo.md](docs/walidacja-repo.md).

## Status porządkowania

Główna ścieżka `00`-`10` została ujednolicona do wspólnego formatu. Materiały
przygotowywane są po polsku. Zadania TNT mają już mapę docelowego użycia:
część została przeniesiona do ćwiczeń pomostowych, a symulator bankomatu trafił
do głównej listy projektów.
