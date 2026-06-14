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
| `min-max-avg.md` | `02-sterowanie-i-petle/tasks` | wysoki | przenieść jako ćwiczenie z pętli i walidacji |
| `encryption-1.md` | `03-funkcje-tablice-napisy/tasks` | wysoki | przenieść jako ćwiczenie z napisów i funkcji |
| `sfml-t1.md` | `06-oop/tasks` | średni | przenieść część bez SFML jako ćwiczenie OOP |
| `calculator.md` | `08-projekt-build-testy` albo `10-projekty` | średni | zostawić jako pomost do projektu kalkulatora |
| `atm.md` | `10-projekty` | niski | rozważyć jako nowy projekt główny po doprecyzowaniu |

## Kolejność pracy

1. Przenieś `min-max-avg.md` do segmentu sterowania i pętli.
2. Przenieś `encryption-1.md` do segmentu funkcji i napisów.
3. Wydziel z `sfml-t1.md` wersję bez biblioteki SFML i przenieś ją do OOP.
4. Porównaj `calculator.md` z głównym projektem kalkulatora.
5. Zdecyduj, czy `atm.md` ma zostać projektem pomocniczym, czy projektem głównym.

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

Najlepiej pasuje do pętli, walidacji wejścia i obliczania wyniku częściowego.
Po przeniesieniu warto dodać pytania o pusty zestaw danych i błędny tekst
wpisany zamiast liczby.

### `encryption-1.md`

Najlepiej pasuje do napisów i funkcji. Dobrze sprawdza rozdzielenie logiki
szyfrowania od wejścia i wyjścia.

### `sfml-t1.md`

Minimalny wariant powinien działać bez SFML. Wizualizacja może zostać tylko jako
rozszerzenie dla studentów, którzy mają przygotowane środowisko graficzne.

### `calculator.md`

To dobry pomost między ćwiczeniem a projektem. Nie trzeba tworzyć drugiego
pełnego projektu kalkulatora, jeśli główny projekt już obejmuje ten temat.

### `atm.md`

Temat nadaje się na projekt główny, ale wymaga pilnowania zakresu. Wariant
minimum powinien obejmować jedno konto testowe, logowanie PIN-em, saldo, wpłatę,
wypłatę i historię operacji.
