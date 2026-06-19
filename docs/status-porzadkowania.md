# Status porządkowania materiałów

Ten dokument zamyka bieżący etap porządkowania repozytorium z materiałami do
nauki C++. Główne materiały źródłowe pozostają po polsku, a ebook ma już
również pierwszą pełną edycję angielską.

## Zakres zakończony

Zakończone są:

- główna ścieżka segmentów `00`-`10`,
- wspólny format segmentów i lekcji,
- ćwiczenia pomostowe po wybranych segmentach,
- tematy projektów zaliczeniowych w `10-projekty`,
- przeniesienie najważniejszych zadań TNT do aktualnej struktury,
- przykłady startowe dla trudniejszych miejsc projektowych,
- ebook PL do pobrania jako PDF i EPUB,
- ebook EN do pobrania jako PDF i EPUB,
- lokalna walidacja przykładów, testów, linków i smoke checków.

## Najważniejsze punkty startowe

Dla studenta:

- [README główne](../README.md),
- [instrukcja dla studenta](student.md),
- [ebook PL/EN](../ebook/README.md),
- [co po segmencie](co-po-segmencie.md),
- [checklista oddania](checklista-oddania.md).

Dla prowadzącego:

- [przewodnik dla prowadzącego](prowadzacy.md),
- [plan semestru](plan-semestru.md),
- [postępy i ocenianie](postepy-i-ocenianie.md),
- [ebook i pliki do pobrania](../ebook/README.md),
- [walidacja repozytorium](walidacja-repo.md).

Dla projektów:

- [10-projekty](../10-projekty/README.md),
- [checklista projektu](../10-projekty/checklista-projektu.md),
- [karta oceny projektu](../10-projekty/karta-oceny-projektu.md),
- [szkice klas projektów](../10-projekty/szkice-klas-projektow.md).

## Walidacja

Przed większą zmianą i przed zajęciami uruchom:

```sh
sh tools/check-examples.sh
```

Skrypt sprawdza linki Markdown, kompiluje przykłady, uruchamia testy segmentów
oraz wykonuje smoke check wybranych przykładów startowych.

## Dalsze zmiany

Nie ma obecnie pilnego backlogu porządkowego. Kolejne zmiany warto robić wtedy,
gdy:

- pojawi się nowy temat zajęć,
- konkretne zadanie wymaga doprecyzowania,
- studenci powtarzalnie blokują się na jednym fragmencie,
- przykład albo test będzie krótki i możliwy do sprawdzenia automatycznie.

Nowe materiały w głównej ścieżce powinny zachować polski język, format
segmentów oraz możliwość walidacji przez `tools/check-examples.sh`, jeśli
zawierają kod. Zmiany w ebooku angielskim powinny być spójne z wersją EN i
odnotowane w `ebook/CHANGELOG.md`.
