# Przykłady do uzupełnienia

Ten dokument porządkuje przegląd przykładów `.cpp` w segmentach `01`-`09`.
Nie każdy temat wymaga osobnego przykładu. Priorytet mają miejsca, w których
krótki program demonstracyjny pomaga studentowi zacząć większe zadanie.

## Stan obecny

| Segment | Liczba przykładów `.cpp` | Ocena pokrycia |
| --- | ---: | --- |
| `01-podstawy` | 9 | dobre |
| `02-sterowanie-i-petle` | 13 | dobre |
| `03-funkcje-tablice-napisy` | 14 | dobre |
| `04-wskazniki-referencje-pamiec` | 13 | dobre |
| `05-pliki-wyjatki` | 10 | dobre |
| `06-oop` | 12 | dobre |
| `07-stl-struktury-danych` | 11 | dobre |
| `08-projekt-build-testy` | 10 | bardzo dobre po dodaniu przykładu RPN |
| `09-modern-cpp` | 9 | wystarczające |

## Priorytety uzupełnień

### Wysoki priorytet

- `08-projekt-build-testy` - utrzymywać przykład
  [rpn-calculator](../08-projekt-build-testy/examples/rpn-calculator/README.md)
  jako wzorzec projektu wieloplikowego z testami.
- `06-oop` - w przyszłości można dodać kompilowalny przykład do ćwiczenia
  [figury i polimorfizm](../06-oop/08-cwiczenie-figury-polimorfizm.md), jeśli
  grupa potrzebuje więcej wsparcia przy `virtual`, `override` i `unique_ptr`.

### Średni priorytet

- `02-sterowanie-i-petle` - można dodać przykład częściowy do ćwiczenia
  [minimum, maksimum i średnia](../02-sterowanie-i-petle/07-cwiczenie-min-max-srednia.md),
  np. samą pętlę wczytywania i walidacji bez pełnego rozwiązania.
- `03-funkcje-tablice-napisy` - można dodać przykład częściowy do ćwiczenia
  [szyfr GADERYPOLUKI](../03-funkcje-tablice-napisy/07-cwiczenie-szyfr-gaderypoluki.md),
  np. funkcję zamieniającą pojedynczy znak.

### Niski priorytet

- `01-podstawy` - przykłady pokrywają główne potrzeby startowe.
- `04-wskazniki-referencje-pamiec` - przykłady są wystarczająco drobne i
  dobrze oddzielone.
- `05-pliki-wyjatki` - przykłady obejmują odczyt, zapis, dopisywanie,
  walidację i wyjątki.
- `07-stl-struktury-danych` - przykłady obejmują najważniejsze kontenery i
  algorytmy.
- `09-modern-cpp` - przykłady są wystarczające dla materiału pokazowego.

## Zasada dodawania nowych przykładów

Nowy przykład `.cpp` warto dodać, jeśli spełnia co najmniej dwa warunki:

- pokazuje technikę używaną w kilku zadaniach,
- można go skompilować jednym poleceniem albo istniejącym skryptem,
- jest krótszy niż pełne rozwiązanie zadania,
- zawiera jeden wyraźny temat,
- może być automatycznie sprawdzony przez `tools/check-examples.sh`.

Nie warto dodawać przykładu, jeśli byłby pełnym rozwiązaniem zadania
zaliczeniowego albo projektu. W takim przypadku lepszy jest szkielet, testy albo
scenariusz sprawdzenia.
