# Ebook - Kurs C++

Ten katalog zawiera źródła i konfigurację ebooka budowanego z materiałów
repozytorium.

## Cel

Ebook ma być wersją czytelniczą kursu C++:

- po polsku,
- dla studentów uczących się od podstaw,
- z zachowaniem segmentów `00`-`10`,
- z ćwiczeniami pomostowymi i projektami,
- bez materiałów archiwalnych.

## Pliki

- [metadata.yaml](metadata.yaml) - metadane dla `pandoc`.
- [front-matter.md](front-matter.md) - strona wstępna ebooka.
- [manifest.txt](manifest.txt) - kolejność plików źródłowych.
- [download/cpp-kurs.pdf](download/cpp-kurs.pdf) - aktualny PDF do pobrania.
- [download/cpp-kurs.epub](download/cpp-kurs.epub) - aktualny EPUB do pobrania.
- `build/` - katalog wynikowy tworzony przez skrypt, ignorowany przez Git.

## Pobieranie

Gotowe pliki:

- [Pobierz PDF PL](download/cpp-kurs.pdf),
- [Pobierz EPUB PL](download/cpp-kurs.epub),
- [Download PDF EN](download/cpp-course-en.pdf),
- [Download EPUB EN](download/cpp-course-en.epub).

Wersja angielska jest przygotowywana w katalogu [en](en/README.md). Obecnie jest
to draft planu i struktury tłumaczenia, a nie pełny przekład całego kursu.

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
- utrzymywać polski język materiałów.
