# Narzędzia repozytorium

Ten katalog zawiera proste skrypty do lokalnej walidacji materiałów, przykładów
i ebooków. Wszystkie komendy uruchamiaj z katalogu głównego repozytorium.

## Walidacja przykładów

```sh
sh tools/check-examples.sh
```

Skrypt sprawdza linki Markdown, kompiluje przykłady z głównej ścieżki,
uruchamia testy segmentów oraz wybrane smoke checki. Domyślnie zapisuje pliki
wynikowe w `/tmp/cpp-examples-build`.

Przydatne zmienne:

- `CXX` - kompilator, domyślnie `c++`,
- `STD` - standard C++, domyślnie `-std=c++17`,
- `BUILD_DIR` - katalog wynikowy.

## Walidacja linków

```sh
python3 tools/check-links.py
```

Skrypt sprawdza lokalne linki Markdown poza katalogiem `ebook/build/`.

## Budowanie ebooka

Wersja polska:

```sh
sh tools/build-ebook.sh
```

Wersja angielska:

```sh
EBOOK_LANG=en sh tools/build-ebook.sh
```

Wyniki trafiają domyślnie do `ebook/build/`.

## Walidacja ebooków

```sh
sh tools/check-ebooks.sh
```

Skrypt sprawdza metadane ebooków PL/EN, buduje PDF/EPUB i weryfikuje, czy
gotowe pliki do pobrania istnieją w `ebook/download/`.

Samo sprawdzenie metadanych:

```sh
python3 tools/check-ebook-metadata.py
```

Ten check jest lekki i działa również w GitHub Actions.
