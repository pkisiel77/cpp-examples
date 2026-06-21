# Walidacja repozytorium

Ten dokument opisuje, jak lokalnie sprawdzić linki, przykłady, testy i ebooki
z głównej ścieżki kursu. Używaj go przed zajęciami, po większych zmianach w
materiałach albo przed przygotowaniem pull requesta.

## Szybkie uruchomienie

Z katalogu głównego repozytorium:

```sh
sh tools/check-examples.sh
```

Skrypt kompiluje przykłady z katalogów `examples`, uruchamia testy z katalogów
`tests` oraz sprawdza przykłady wieloplikowe z segmentów `08` i `09`.

Jeśli zmieniasz ebook, uruchom dodatkowo:

```sh
sh tools/check-ebooks.sh
```

## Co sprawdza skrypt

`tools/check-examples.sh` wykonuje:

- sprawdzenie linków Markdown,
- kompilację pojedynczych przykładów `.cpp` z głównej ścieżki,
- smoke check wybranych przykładów startowych, które nie wymagają danych z terminala,
- sprawdzenie składni wybranego przykładu przez `-fsyntax-only`,
- kompilację przykładu `08-projekt-build-testy/examples/split-project`,
- build i testy przykładu `08-projekt-build-testy/examples/project-layout`,
- testy automatyczne segmentów `01`-`09`,
- kompilację przykładu organizacji kodu z segmentu `09`.

Skrypt pomija katalogi `archive`, ponieważ zawierają materiały historyczne,
które nie muszą być częścią bieżącej ścieżki zajęć.

## Walidacja ebooków

`tools/check-ebooks.sh` buduje obie wersje ebooka:

- sprawdza spójność metadanych wersji PL i EN,
- PL: `ebook/build/cpp-kurs.pdf` i `ebook/build/cpp-kurs.epub`,
- EN: `ebook/build/cpp-course-en.pdf` i `ebook/build/cpp-course-en.epub`.

Skrypt sprawdza też, czy istnieją gotowe pliki do pobrania w `ebook/download/`.
Uruchamiaj go po zmianach w:

- `ebook/manifest.txt`,
- `ebook/metadata.yaml`,
- `ebook/front-matter.md`,
- `ebook/en/manifest.txt`,
- `ebook/en/metadata.yaml`,
- `ebook/en/front-matter.md`,
- `ebook/README.md`,
- `ebook/en/README.md`,
- rozdziałach ebooka PL albo EN,
- `ebook/CHANGELOG.md`,
- skryptach `tools/build-ebook.sh` i `tools/check-ebooks.sh`.

Jeśli zmiana treści ebooka jest zatwierdzona, przebuduj odpowiednią wersję i
skopiuj nowe PDF/EPUB do `ebook/download/`.

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

Ten sam skrypt przykładów działa w GitHub Actions po `push` i `pull_request`.
CI uruchamia też lekki check metadanych ebooka:
`python3 tools/check-ebook-metadata.py`.

Konfiguracja znajduje się w:

```text
.github/workflows/check-examples.yml
```

Dzięki temu lokalne uruchomienie `sh tools/check-examples.sh` oraz
`python3 tools/check-ebook-metadata.py` daje podobny wynik do sprawdzenia w
repozytorium zdalnym.

PDF i EPUB nie są obecnie budowane w GitHub Actions. Sprawdzaj je lokalnie
komendą `sh tools/check-ebooks.sh`, szczególnie przed commitem zmieniającym
katalog `ebook/`.

## Kiedy uruchamiać

Uruchom pełną walidację:

- po dodaniu albo zmianie przykładu `.cpp`,
- po dodaniu testu w katalogu `tests`,
- po zmianie skryptu build,
- po zmianie źródeł ebooka albo plików do pobrania,
- przed commitem obejmującym większą zmianę w materiałach,
- przed zajęciami, jeśli chcesz upewnić się, że przykłady nadal się kompilują.
