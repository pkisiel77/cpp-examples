# 06 - Programowanie obiektowe

Ten segment wprowadza programowanie obiektowe jako sposób modelowania większych programów. Materiał przechodzi od prostych klas i obiektów do konstruktorów, enkapsulacji, kopiowania, dziedziczenia oraz przeciążania operatorów.

## Cele segmentu

Po zakończeniu segmentu student powinien umieć:

- zdefiniować prostą klasę,
- utworzyć obiekt klasy,
- odróżnić pola od metod,
- stosować `public` i `private`,
- napisać konstruktor,
- rozumieć podstawy enkapsulacji,
- użyć metod `const`,
- rozumieć, kiedy powstaje kopia obiektu,
- wyjaśnić podstawy dziedziczenia,
- przeciążyć prosty operator,
- zaprojektować małą klasę do zadania praktycznego.

## Kolejność lekcji

1. [01-klasy-i-obiekty.md](01-klasy-i-obiekty.md) - klasa, obiekt, pola i metody.
2. [02-konstruktory-i-enkapsulacja.md](02-konstruktory-i-enkapsulacja.md) - konstruktory, `private`, gettery i settery.
3. [03-metody-const-i-this.md](03-metody-const-i-this.md) - metody `const`, wskaźnik `this`, dobre nazwy.
4. [04-kopiowanie-obiektow.md](04-kopiowanie-obiektow.md) - konstruktor kopiujący i przekazywanie obiektów.
5. [05-dziedziczenie.md](05-dziedziczenie.md) - klasy bazowe i pochodne.
6. [06-przeciazanie-operatorow.md](06-przeciazanie-operatorow.md) - podstawy przeciążania operatorów.
7. [07-zadania.md](07-zadania.md) - zadania podstawowe i projektowe.
8. [08-cwiczenie-figury-polimorfizm.md](08-cwiczenie-figury-polimorfizm.md) - większe ćwiczenie z dziedziczenia, klasy abstrakcyjnej i polimorfizmu.

## Status porządkowania

Lekcje i zadania zostały uporządkowane do wspólnego formatu segmentów. Pierwotne wersje materiałów są zachowane w katalogu [archive](archive):

- [archive/klasa-obiekt.md](archive/klasa-obiekt.md)
- [archive/nazwy-klas.md](archive/nazwy-klas.md)
- [archive/klasy-zadania.md](archive/klasy-zadania.md)
- [archive/zadania-oop-1.md](archive/zadania-oop-1.md)
- [archive/zadania-oop-t1.md](archive/zadania-oop-t1.md)
- [archive/lab-03-klasa-macierz.md](archive/lab-03-klasa-macierz.md)
- [archive/lab-03-zadania.md](archive/lab-03-zadania.md)
- [archive/konstruktor-kopiujacy.md](archive/konstruktor-kopiujacy.md)
- [archive/friends.md](archive/friends.md)
- [archive/dziedziczenie-zadania.md](archive/dziedziczenie-zadania.md)
- [archive/przeciazanie-operatorow.md](archive/przeciazanie-operatorow.md)
- [archive/drzewo-binarne.md](archive/drzewo-binarne.md)
- [archive/composite.md](archive/composite.md)
- [archive/uml-composite.md](archive/uml-composite.md)
- [archive/linki-oop.md](archive/linki-oop.md)

## Przykłady kodu

Przykłady w katalogu [examples](examples) można kompilować osobno:

- [examples/simple_point.cpp](examples/simple_point.cpp) - prosta klasa i obiekt.
- [examples/rectangle_methods.cpp](examples/rectangle_methods.cpp) - pola i metody klasy.
- [examples/car_encapsulation.cpp](examples/car_encapsulation.cpp) - enkapsulacja pól.
- [examples/account_constructor.cpp](examples/account_constructor.cpp) - konstruktor i walidacja.
- [examples/const_methods.cpp](examples/const_methods.cpp) - metody `const`.
- [examples/this_pointer.cpp](examples/this_pointer.cpp) - wskaźnik `this`.
- [examples/copy_constructor.cpp](examples/copy_constructor.cpp) - konstruktor kopiujący.
- [examples/pass_object.cpp](examples/pass_object.cpp) - przekazywanie obiektów.
- [examples/basic_inheritance.cpp](examples/basic_inheritance.cpp) - podstawowe dziedziczenie.
- [examples/car_inheritance.cpp](examples/car_inheritance.cpp) - rozszerzanie klasy.
- [examples/point_operators.cpp](examples/point_operators.cpp) - przeciążanie operatorów.
- [examples/money_output_operator.cpp](examples/money_output_operator.cpp) - operator wyjścia `<<`.

Większe ćwiczenie integrujące dziedziczenie i polimorfizm znajduje się w pliku
[08-cwiczenie-figury-polimorfizm.md](08-cwiczenie-figury-polimorfizm.md).

## Testy

Katalog [tests](tests) zawiera prosty test klasy bez zewnętrznego frameworka.
Test pokazuje, jak sprawdzać konstruktor, metody zmieniające stan, metody
`const` oraz operator porównania.

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
- `tests/` - proste testy automatyczne dla klas.
- `archive/` - pierwotne wersje materiałów zachowane do wglądu.
