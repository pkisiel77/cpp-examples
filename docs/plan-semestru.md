# Plan semestru

Propozycja zakłada 15 spotkań. Jedno spotkanie może oznaczać jedne dłuższe
zajęcia albo blok dwóch krótszych lekcji. Plan można skracać przez pominięcie
części rozszerzeń albo wydłużać przez dodanie czasu na projekty.

## Założenia

- Materiał jest prowadzony po kolei od `00-start` do `10-projekty`.
- Na każdych zajęciach student powinien skompilować co najmniej jeden program.
- Mini-sprawdziany służą do szybkiej kontroli samodzielności, nie do zastępowania projektu.
- Projekt zaliczeniowy startuje przed końcem semestru, żeby był czas na poprawki.

## Rozkład 15-tygodniowy

| Tydzień | Temat | Materiały | Zadanie domowe | Punkt kontrolny |
| ---: | --- | --- | --- | --- |
| 1 | Środowisko pracy | `00-start` | Skonfigurować edytor, kompilator i Git. | Student kompiluje pierwszy plik `.cpp`. |
| 2 | Pierwszy program i wejście/wyjście | `01-podstawy/01-02` | Zadania z wejścia i wyjścia. | Student używa `std::cin`, `std::cout`, `std::getline`. |
| 3 | Typy, operatory i formatowanie | `01-podstawy/03-05` | Mini-sprawdzian segmentu `01`. | Program oblicza i formatuje wynik liczbowy. |
| 4 | Warunki i menu | `02-sterowanie-i-petle/01-02` | Program z menu i walidacją wyboru. | Student stosuje `if`, `else if`, `switch`. |
| 5 | Pętle | `02-sterowanie-i-petle/03-06` | Mini-sprawdzian segmentu `02`. | Student pisze pętlę bez ryzyka pętli nieskończonej. |
| 6 | Funkcje | `03-funkcje-tablice-napisy/01-02` | Przepisać wcześniejsze zadanie na funkcje. | Program ma krótkie funkcje z jasnymi nazwami. |
| 7 | Tablice i napisy | `03-funkcje-tablice-napisy/03-06` | Mini-sprawdzian segmentu `03`. | Student przetwarza tablicę i napis w pętli. |
| 8 | Referencje, wskaźniki i bezpieczeństwo | `04-wskazniki-referencje-pamiec` | Mini-sprawdzian segmentu `04`. | Student sprawdza `nullptr` i odróżnia wskaźnik od referencji. |
| 9 | Pliki i wyjątki | `05-pliki-wyjatki` | Mini-sprawdzian segmentu `05`. | Program zapisuje, odczytuje i waliduje dane z pliku. |
| 10 | Klasy i obiekty | `06-oop/01-04` | Mała klasa z konstruktorem i metodami `const`. | Student ukrywa pola i tworzy obiekt w poprawnym stanie. |
| 11 | Dziedziczenie, operatory i STL | `06-oop/05-07`, `07-stl-struktury-danych/01-03` | Zadanie z wektorem obiektów i sortowaniem. | Student używa `std::vector` oraz `std::sort`. |
| 12 | Mapy, kolejki i projekt HRMS | `07-stl-struktury-danych/04-07` | Zadanie łączące `std::map` z klasą. | Student dobiera kontener do problemu. |
| 13 | Organizacja projektu, build i testy | `08-projekt-build-testy` | Przygotować szkielet projektu z `include`, `src`, `tests`. | Projekt buduje się skryptem lub jedną opisaną komendą. |
| 14 | Modern C++ i start projektu | `09-modern-cpp`, `10-projekty` | Wybrać temat projektu i opisać wariant minimum. | Student pokazuje plan plików, klas i scenariuszy sprawdzenia. |
| 15 | Prezentacje i odbiór projektów | `10-projekty` | Poprawki po przeglądzie. | Projekt spełnia wariant minimum i ma instrukcję uruchomienia. |

## Moment rozpoczęcia projektu

Projekt warto ogłosić najpóźniej w tygodniu 13. W tygodniu 14 każdy student
powinien mieć:

- wybrany temat z `10-projekty`,
- zaznaczony wariant minimum,
- prosty szkic struktury plików,
- listę przypadków testowych albo scenariuszy ręcznego sprawdzenia,
- pierwszy commit z pustym szkieletem projektu.

## Kontrole w trakcie semestru

Zalecane punkty kontrolne:

- po tygodniu 3 - podstawy kompilacji, wejścia, wyjścia i formatowania,
- po tygodniu 5 - warunki, pętle i menu,
- po tygodniu 7 - funkcje, tablice i napisy,
- po tygodniu 9 - pliki, walidacja i wyjątki,
- po tygodniu 12 - klasy, STL i dobór kontenerów,
- po tygodniu 15 - projekt zaliczeniowy.

## Dostosowanie tempa

Jeśli grupa potrzebuje więcej czasu, skróć zakres modern C++ i potraktuj
`09-modern-cpp` jako materiał pokazowy. Jeśli grupa pracuje szybciej, rozszerz
projekt o testy, GitHub Actions i dodatkowe funkcje z sekcji `Rozszerzenia dla chętnych`.
