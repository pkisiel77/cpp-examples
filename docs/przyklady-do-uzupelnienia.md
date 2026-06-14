# Przykłady do uzupełnienia

Ten dokument porządkuje przegląd przykładów `.cpp` w segmentach `01`-`10`.
Nie każdy temat wymaga osobnego przykładu. Priorytet mają miejsca, w których
krótki program demonstracyjny pomaga studentowi zacząć większe zadanie.

## Stan obecny

| Segment | Liczba przykładów `.cpp` | Ocena pokrycia |
| --- | ---: | --- |
| `01-podstawy` | 9 | dobre |
| `02-sterowanie-i-petle` | 14 | bardzo dobre po dodaniu przykładu min/max/średnia |
| `03-funkcje-tablice-napisy` | 15 | bardzo dobre po dodaniu przykładu GADERYPOLUKI |
| `04-wskazniki-referencje-pamiec` | 13 | dobre |
| `05-pliki-wyjatki` | 10 | dobre |
| `06-oop` | 13 | bardzo dobre po dodaniu przykładu polimorfizmu |
| `07-stl-struktury-danych` | 11 | dobre |
| `08-projekt-build-testy` | 10 | bardzo dobre po dodaniu przykładu RPN |
| `09-modern-cpp` | 9 | wystarczające |
| `10-projekty` | 1 | startowe po dodaniu szkicu konta bankomatu |

## Priorytety uzupełnień

### Wysoki priorytet

- `08-projekt-build-testy` - utrzymywać przykład
  [rpn-calculator](../08-projekt-build-testy/examples/rpn-calculator/README.md)
  jako wzorzec projektu wieloplikowego z testami.
- `06-oop` - utrzymywać przykład
  [figures_polymorphism.cpp](../06-oop/examples/figures_polymorphism.cpp) jako
  punkt startowy do ćwiczenia z klasą abstrakcyjną i polimorfizmem.

### Średni priorytet

- `02-sterowanie-i-petle` - utrzymywać przykład
  [while_min_max_average.cpp](../02-sterowanie-i-petle/examples/while_min_max_average.cpp)
  jako demonstrację pętli, walidacji i wyniku częściowego.
- `03-funkcje-tablice-napisy` - utrzymywać przykład
  [string_gaderypoluki.cpp](../03-funkcje-tablice-napisy/examples/string_gaderypoluki.cpp)
  jako demonstrację funkcji pracujących na znakach i napisach.

### Niski priorytet

- `01-podstawy` - przykłady pokrywają główne potrzeby startowe.
- `04-wskazniki-referencje-pamiec` - przykłady są wystarczająco drobne i
  dobrze oddzielone.
- `05-pliki-wyjatki` - przykłady obejmują odczyt, zapis, dopisywanie,
  walidację i wyjątki.
- `07-stl-struktury-danych` - przykłady obejmują najważniejsze kontenery i
  algorytmy.
- `09-modern-cpp` - przykłady są wystarczające dla materiału pokazowego.

## Następne przykłady do napisania

| Priorytet | Miejsce | Proponowany przykład | Cel dydaktyczny |
| --- | --- | --- | --- |
| 1 | `10-projekty/examples/` | [logger_skeleton.cpp](../10-projekty/examples/logger_skeleton.cpp) | pokazać prosty model wpisu dziennika, poziomy logowania i zapis do pliku |
| 2 | `10-projekty/examples/` | szkic `Task` i `TaskManager` dla projektu 10 | pokazać klasę zarządzającą kolekcją obiektów i filtrowanie statusów |
| 3 | `10-projekty/examples/` | szkic parsera CSV dla projektu 11 | połączyć odczyt pliku, podział linii i walidację kolumn |
| 4 | `07-stl-struktury-danych/examples/` | `map_vector_join.cpp` | pokazać praktyczne użycie `std::map` z wektorem rekordów |
| 5 | `05-pliki-wyjatki/examples/` | `config_key_value.cpp` | pokazać prosty parser konfiguracji `klucz=wartosc` z obsługą błędów |

Te przykłady powinny być krótkimi punktami startowymi. Nie powinny rozwiązywać
całego projektu zaliczeniowego, tylko pokazywać model danych albo jedną
technikę, którą student rozwinie samodzielnie.

## Przykłady pomostowe dodane

| Ćwiczenie | Przykład |
| --- | --- |
| Minimum, maksimum i średnia | [while_min_max_average.cpp](../02-sterowanie-i-petle/examples/while_min_max_average.cpp) |
| Szyfr GADERYPOLUKI | [string_gaderypoluki.cpp](../03-funkcje-tablice-napisy/examples/string_gaderypoluki.cpp) |
| Figury i polimorfizm | [figures_polymorphism.cpp](../06-oop/examples/figures_polymorphism.cpp) |
| Kalkulator RPN | [rpn-calculator](../08-projekt-build-testy/examples/rpn-calculator/README.md) |
| Model konta bankomatu | [atm_account.cpp](../10-projekty/examples/atm_account.cpp) |
| Szkic loggera | [logger_skeleton.cpp](../10-projekty/examples/logger_skeleton.cpp) |

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
