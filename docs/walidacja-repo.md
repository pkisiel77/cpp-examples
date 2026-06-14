# Walidacja repozytorium

Ten dokument opisuje, jak lokalnie sprawdzić przykłady i testy z głównej
ścieżki kursu. Używaj go przed zajęciami, po większych zmianach w materiałach
albo przed przygotowaniem pull requesta.

## Szybkie uruchomienie

Z katalogu głównego repozytorium:

```sh
sh tools/check-examples.sh
```

Skrypt kompiluje przykłady z katalogów `examples`, uruchamia testy z katalogów
`tests` oraz sprawdza przykłady wieloplikowe z segmentów `08` i `09`.

## Co sprawdza skrypt

`tools/check-examples.sh` wykonuje:

- kompilację pojedynczych przykładów `.cpp` z głównej ścieżki,
- smoke check wybranych przykładów startowych, które nie wymagają danych z terminala,
- sprawdzenie składni wybranego przykładu przez `-fsyntax-only`,
- kompilację przykładu `08-projekt-build-testy/examples/split-project`,
- build i testy przykładu `08-projekt-build-testy/examples/project-layout`,
- testy automatyczne segmentów `01`-`09`,
- kompilację przykładu organizacji kodu z segmentu `09`.

Skrypt pomija katalogi `archive`, ponieważ zawierają materiały historyczne,
które nie muszą być częścią bieżącej ścieżki zajęć.

## Konfiguracja

Domyślne wartości:

```text
CXX=c++
STD=-std=c++17
BUILD_DIR=/tmp/cpp-examples-build
```

Możesz je nadpisać przy uruchomieniu:

```sh
CXX=clang++ STD=-std=c++20 BUILD_DIR=/tmp/cpp-check sh tools/check-examples.sh
```

Pliki wynikowe trafiają do `BUILD_DIR`, więc skrypt nie powinien zostawiać
artefaktów w katalogach z materiałami.

## Jak czytać wynik

Typowy poprawny koniec działania:

```text
All example checks passed
```

Jeśli kompilacja albo test się nie powiedzie, skrypt zatrzyma się na pierwszym
błędzie. W takim przypadku sprawdź:

- nazwę pliku wypisaną tuż przed błędem,
- komunikat kompilatora,
- czy przykład wymaga dodatkowego pliku `.cpp`,
- czy test zwraca kod zakończenia różny od `0`.

## CI

Ten sam skrypt działa w GitHub Actions po `push` i `pull_request`.
Konfiguracja znajduje się w:

```text
.github/workflows/check-examples.yml
```

Dzięki temu lokalne uruchomienie `sh tools/check-examples.sh` daje podobny
wynik do sprawdzenia w repozytorium zdalnym.

## Kiedy uruchamiać

Uruchom pełną walidację:

- po dodaniu albo zmianie przykładu `.cpp`,
- po dodaniu testu w katalogu `tests`,
- po zmianie skryptu build,
- przed commitem obejmującym większą zmianę w materiałach,
- przed zajęciami, jeśli chcesz upewnić się, że przykłady nadal się kompilują.
