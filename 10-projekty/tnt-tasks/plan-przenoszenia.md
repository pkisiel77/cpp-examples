# Plan przenoszenia zadań TNT

Ten dokument określa, co zrobić ze starszymi zadaniami z katalogu `tnt-tasks`.
Nie każde zadanie musi trafić do głównej listy projektów. Część z nich lepiej
działa jako krótkie ćwiczenia w segmentach wcześniejszych.

## Zasady decyzji

Zadanie przenosimy do głównych materiałów, jeśli:

- pasuje do konkretnego segmentu kursu,
- ma jasny wariant minimum,
- można je sprawdzić w czasie jednej lub dwóch lekcji,
- nie wymaga dodatkowych bibliotek w wersji podstawowej,
- uzupełnia lukę w istniejących ćwiczeniach.

Zadanie zostaje w `tnt-tasks`, jeśli:

- jest wariantem już istniejącego projektu,
- wymaga większego doprecyzowania,
- jest przydatne jako inspiracja, ale nie jako obowiązkowy materiał,
- wymaga biblioteki zewnętrznej tylko w wersji rozszerzonej.

## Mapa przeniesienia

| Plik | Docelowe użycie | Priorytet | Decyzja |
| --- | --- | --- | --- |
| `min-max-avg.md` | `02-sterowanie-i-petle` | wykonane | wersja docelowa: `07-cwiczenie-min-max-srednia.md` |
| `encryption-1.md` | `03-funkcje-tablice-napisy` | wykonane | wersja docelowa: `07-cwiczenie-szyfr-gaderypoluki.md` |
| `sfml-t1.md` | `06-oop` | wykonane | wersja docelowa: `08-cwiczenie-figury-polimorfizm.md` |
| `calculator.md` | `08-projekt-build-testy` | wykonane | wersja docelowa: `09-cwiczenie-kalkulator-rpn.md` |
| `atm.md` | `10-projekty` | wykonane | wersja docelowa: `project-12-symulator-bankomatu.md` |

## Kolejność pracy

Wszystkie zadania z bieżącej listy TNT mają już decyzję docelową.

## Format po przeniesieniu ćwiczenia

Ćwiczenie po przeniesieniu powinno mieć:

- cel ćwiczenia,
- wymagania wstępne,
- opis zadania,
- wymagania techniczne,
- wariant podstawowy,
- zadania dodatkowe,
- pytania kontrolne,
- scenariusze sprawdzenia.

Jeśli zadanie trafia do segmentu wcześniejszego, nie musi mieć pełnej rubryki
projektowej. Wystarczy format zgodny z ćwiczeniami danego segmentu.

## Format po awansie do projektu

Jeśli zadanie zostaje projektem w `10-projekty`, powinno mieć pełny układ:

1. Cel projektu.
2. Zakres funkcjonalny.
3. Wymagania techniczne.
4. Proponowana struktura plików.
5. Model danych albo model domeny.
6. Minimalny wariant zaliczeniowy.
7. Rozszerzenia dla chętnych.
8. Kryteria oceny.
9. Scenariusze sprawdzenia.

## Notatki do konkretnych zadań

### `min-max-avg.md`

Wersja docelowa znajduje się w
`02-sterowanie-i-petle/07-cwiczenie-min-max-srednia.md`. Ćwiczenie trafiło do
segmentu pętli, walidacji wejścia i obliczania wyniku częściowego.

### `encryption-1.md`

Wersja docelowa znajduje się w
`03-funkcje-tablice-napisy/07-cwiczenie-szyfr-gaderypoluki.md`. Ćwiczenie trafiło
do segmentu napisów i funkcji. Dobrze sprawdza rozdzielenie logiki szyfrowania
od wejścia i wyjścia.

### `sfml-t1.md`

Wersja docelowa znajduje się w
`06-oop/08-cwiczenie-figury-polimorfizm.md`. Minimalny wariant działa bez SFML,
a wizualizacja została opisana jako rozszerzenie dla studentów, którzy mają
przygotowane środowisko graficzne.

### `calculator.md`

Wersja docelowa znajduje się w
`08-projekt-build-testy/09-cwiczenie-kalkulator-rpn.md`. To pomost między
ćwiczeniem a projektem: obejmuje RPN, podział na pliki, build i testy, ale nie
dubluje pełnego projektu kalkulatora z `10-projekty`.

### `atm.md`

Wersja docelowa znajduje się w
`10-projekty/project-12-symulator-bankomatu.md`. Temat został awansowany do
projektu głównego. Wariant minimum obejmuje jedno konto testowe, logowanie
PIN-em, saldo, wpłatę, wypłatę i historię operacji.
