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

## Jak oddawać zadania

Dla każdego zadania przygotuj:

- plik `.cpp` albo mały katalog projektu,
- kod, który kompiluje się bez błędów,
- czytelne nazwy zmiennych i funkcji,
- krótki opis, jeśli zadanie jest większe,
- przykładowe dane wejściowe, jeśli program ich wymaga.

Przed oddaniem uruchom program dla danych poprawnych, granicznych i błędnych.

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

Każdy projekt powinien mieć `README.md` z informacją:

- co robi program,
- jak go skompilować,
- jak go uruchomić,
- jakie są podstawowe scenariusze sprawdzenia,
- czego jeszcze brakuje albo co można dodać później.
