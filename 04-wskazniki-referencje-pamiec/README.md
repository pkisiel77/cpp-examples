# 04 - Wskaźniki, referencje, pamięć

Ten segment wprowadza pojęcia adresu, wskaźnika i referencji. Materiał powinien być prowadzony ostrożnie, ponieważ błędy w tej części często prowadzą do trudnych do diagnozowania problemów.

## Cele segmentu

Po zakończeniu segmentu student powinien umieć:

- odróżnić wartość zmiennej od jej adresu,
- używać operatora pobrania adresu `&`,
- deklarować wskaźniki,
- rozumieć znaczenie `nullptr`,
- używać operatora dereferencji `*`,
- rozumieć podstawy referencji,
- przekazywać dane do funkcji przez wskaźnik i przez referencję,
- wskazać podstawowe ryzyka pracy z pamięcią.

## Docelowa kolejność lekcji

1. [01-adresy-i-wskazniki.md](01-adresy-i-wskazniki.md) - adres zmiennej, wskaźnik, `nullptr`, dereferencja.
2. `02-referencje.md` - referencje i różnice względem wskaźników.
3. `03-przekazywanie-do-funkcji.md` - przekazywanie przez wartość, wskaźnik i referencję.
4. `04-bezpieczenstwo-pamieci.md` - typowe błędy i dobre praktyki.
5. `05-zadania.md` - zadania podstawowe i dodatkowe.

## Obecne materiały źródłowe

Materiały w tym katalogu są w trakcie porządkowania. Aktualnie źródłem treści są:

- [wskazniki-i-referencje.md](wskazniki-i-referencje.md)
- [lab-02-petle-wskazniki.md](lab-02-petle-wskazniki.md)
- [memory-safe.md](memory-safe.md)

## Format lekcji

Każda docelowa lekcja powinna mieć taki układ:

1. Cel lekcji.
2. Wymagania wstępne.
3. Krótka teoria.
4. Przykład kodu.
5. Zadania do wykonania.
6. Kryteria zaliczenia.

## Katalogi pomocnicze

- `examples/` - kompilowalne przykłady `.cpp` dla tego segmentu.
- `archive/` - stare wersje plików po wchłonięciu ich treści do nowych lekcji.
