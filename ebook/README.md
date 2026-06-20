# Ebook - Kurs C++

Ten katalog zawiera źródła i konfigurację ebooka budowanego z materiałów
repozytorium.

## Cel

Ebook ma być wersją czytelniczą kursu C++:

- po polsku i po angielsku,
- dla studentów uczących się od podstaw,
- z zachowaniem segmentów `00`-`10`,
- z ćwiczeniami pomostowymi i projektami,
- bez materiałów archiwalnych.

## Pliki

- [metadata.yaml](metadata.yaml) - metadane dla `pandoc`.
- [front-matter.md](front-matter.md) - strona wstępna ebooka.
- [manifest.txt](manifest.txt) - kolejność plików źródłowych.
- [CHANGELOG.md](CHANGELOG.md) - historia wersji ebooka.
- [download/cpp-kurs.pdf](download/cpp-kurs.pdf) - aktualny PDF do pobrania.
- [download/cpp-kurs.epub](download/cpp-kurs.epub) - aktualny EPUB do pobrania.
- [en](en/README.md) - źródła i opis angielskiej wersji ebooka.
- `build/` - katalog wynikowy tworzony przez skrypt, ignorowany przez Git.

## Aktualne wersje

- PL: `0.1.1`.
- EN: `0.7.1-en`.

## Pobieranie

Gotowe pliki:

- [Pobierz PDF PL](download/cpp-kurs.pdf),
- [Pobierz EPUB PL](download/cpp-kurs.epub),
- [Download PDF EN](download/cpp-course-en.pdf),
- [Download EPUB EN](download/cpp-course-en.epub).

Wersja angielska jest utrzymywana w katalogu [en](en/README.md). Obejmuje pełną
ścieżkę `00`-`10` w formie pierwszej angielskiej edycji rozdziałów.

## Budowanie

Z katalogu głównego repozytorium:

```sh
sh tools/build-ebook.sh
```

Domyślnie skrypt tworzy:

- `ebook/build/cpp-kurs.md`,
- `ebook/build/cpp-kurs.pdf`,
- `ebook/build/cpp-kurs.epub`.

Wersję angielską można zbudować poleceniem:

```sh
EBOOK_LANG=en sh tools/build-ebook.sh
```

Po zatwierdzonej redakcji można skopiować aktualne pliki PDF i EPUB do
`ebook/download/`, żeby były dostępne bezpośrednio z repozytorium.

Jeśli środowisko nie ma pełnego LaTeX-a, nadal można używać wygenerowanego
pliku Markdown jako źródła do dalszej redakcji.

## Zasady redakcji

Ebook nie powinien być prostą kopią repozytorium bez selekcji. Kolejne etapy
redakcji powinny:

- usuwać powtórzenia między `README.md` segmentów i lekcjami,
- dodawać krótkie przejścia między rozdziałami,
- zostawiać kod w blokach Markdown,
- pomijać katalogi `archive`,
- utrzymywać spójny język danej wersji,
- aktualizować pliki w `ebook/download/` po zatwierdzonej zmianie treści.
