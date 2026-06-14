# Instrukcja dla studenta

Ten dokument pokazuje, jak korzystać z repozytorium podczas nauki C++.

## Jak zacząć

1. Zacznij od [00-start](../00-start/README.md).
2. Przejdź po kolei przez segmenty z głównego [README](../README.md).
3. W każdym segmencie czytaj najpierw `README.md`, potem lekcje w podanej kolejności.
4. Uruchamiaj przykłady z katalogu `examples`, jeśli segment je zawiera.
5. Po lekcji wykonaj zadania i sprawdź checklistę.

## Jak kompilować przykłady

Większość pojedynczych plików można kompilować tak:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic plik.cpp -o program
./program
```

Jeśli przykład ma kilka plików, przeczytaj instrukcję w lekcji albo w `README.md`
danego segmentu.

## Jak sprawdzić całe repo

Możesz uruchomić zbiorcze sprawdzenie przykładów:

```sh
sh tools/check-examples.sh
```

Skrypt zapisuje pliki wynikowe w `/tmp/cpp-examples-build`, więc nie zaśmieca
katalogów z materiałami.

W segmentach z katalogiem `tests` znajdziesz też małe testy bez zewnętrznego
frameworka. Możesz uruchamiać je osobno, jeśli chcesz przećwiczyć sprawdzanie
funkcji bez pełnego skryptu repozytorium.

Więcej informacji o lokalnej walidacji repozytorium znajdziesz w dokumencie
[walidacja repozytorium](walidacja-repo.md).

## Ćwiczenia pomostowe

Po zadaniach z segmentu warto wykonać większe ćwiczenie pomostowe, jeśli chcesz
połączyć kilka tematów przed projektem:

- [minimum, maksimum i średnia](../02-sterowanie-i-petle/07-cwiczenie-min-max-srednia.md),
- [szyfr GADERYPOLUKI](../03-funkcje-tablice-napisy/07-cwiczenie-szyfr-gaderypoluki.md),
- [figury i polimorfizm](../06-oop/08-cwiczenie-figury-polimorfizm.md),
- [kalkulator RPN](../08-projekt-build-testy/09-cwiczenie-kalkulator-rpn.md).

## Jak oddawać zadania

Dla każdego zadania przygotuj:

- plik `.cpp` albo mały katalog projektu,
- kod, który kompiluje się bez błędów,
- czytelne nazwy zmiennych i funkcji,
- krótki opis, jeśli zadanie jest większe,
- przykładowe dane wejściowe, jeśli program ich wymaga.

Przed oddaniem uruchom program dla danych poprawnych, granicznych i błędnych.
Przejdź też przez [checklistę oddania](checklista-oddania.md).

Możesz zacząć od szablonu [templates/zadanie](../templates/zadanie) albo
[templates/projekt](../templates/projekt), jeśli prowadzący nie podał innego
formatu.

## Czego unikać

Unikaj:

- oddawania kodu, który się nie kompiluje,
- zostawiania plików wynikowych w repozytorium,
- kopiowania rozwiązania bez rozumienia,
- bardzo długiej funkcji `main`,
- nazw typu `a`, `b`, `x`, jeśli nie wiadomo, co oznaczają,
- ignorowania ostrzeżeń kompilatora.

## Projekty

Przy projektach z [10-projekty](../10-projekty/README.md) najpierw zrób wariant
minimum. Dopiero gdy działa stabilnie, dodawaj rozszerzenia.

Jeśli nie wiesz, który temat wybrać, zacznij od
[przewodnika wyboru projektu](../10-projekty/jak-wybrac-projekt.md). Jednym z
tematów systemowych jest
[symulator bankomatu](../10-projekty/project-12-symulator-bankomatu.md).

Przed oddaniem projektu przejdź przez
[checklistę projektu](../10-projekty/checklista-projektu.md). Jest bardziej
szczegółowa niż ogólna checklista oddania i pomaga przygotować pokaz projektu.

Każdy projekt powinien mieć `README.md` z informacją:

- co robi program,
- jak go skompilować,
- jak go uruchomić,
- jakie są podstawowe scenariusze sprawdzenia,
- czego jeszcze brakuje albo co można dodać później.
