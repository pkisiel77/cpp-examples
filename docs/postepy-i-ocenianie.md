# Postępy i ocenianie

Ten dokument pomaga prowadzić kurs w sposób mierzalny. Nie zastępuje wymagań
szkoły ani zasad przedmiotowych, ale daje spójny model oceniania zadań,
mini-sprawdzianów i projektu.

## Punkty kontrolne

| Moment | Zakres | Co sprawdzić |
| --- | --- | --- |
| Po `01-podstawy` | kompilacja, wejście/wyjście, typy, formatowanie | Student pisze prosty program obliczeniowy i formatuje wynik. |
| Po `02-sterowanie-i-petle` | warunki, menu, pętle | Student rozwiązuje zadanie z wyborem opcji i powtarzaniem działań. |
| Po `03-funkcje-tablice-napisy` | funkcje, tablice, napisy | Student dzieli program na funkcje i przetwarza kolekcję danych. |
| Po `04-wskazniki-referencje-pamiec` | adresy, wskaźniki, referencje | Student wyjaśnia różnicę między wskaźnikiem i referencją oraz sprawdza `nullptr`. |
| Po `05-pliki-wyjatki` | pliki, walidacja, wyjątki | Student zapisuje i odczytuje dane oraz obsługuje błędy wejścia. |
| Po `07-stl-struktury-danych` | klasy, STL, algorytmy | Student dobiera kontener i używa algorytmów biblioteki standardowej. |
| Po `08-projekt-build-testy` | projekt, build, testy | Student buduje projekt wieloplikowy i potrafi uruchomić testy lub scenariusze sprawdzenia. |
| Po `10-projekty` | projekt zaliczeniowy | Student prezentuje działający wariant minimum i dokumentację. |

## Ćwiczenia pomostowe

Ćwiczenia pomostowe można oceniać jako większe zadania praktyczne między
mini-sprawdzianem a projektem. Dobrze nadają się do sprawdzenia, czy student
łączy kilka tematów w jednym programie.

| Ćwiczenie | Co sprawdza | Kiedy użyć |
| --- | --- | --- |
| [minimum, maksimum i średnia](../02-sterowanie-i-petle/07-cwiczenie-min-max-srednia.md) | pętle, walidację, przypadek pustych danych | po `02-sterowanie-i-petle` |
| [szyfr GADERYPOLUKI](../03-funkcje-tablice-napisy/07-cwiczenie-szyfr-gaderypoluki.md) | funkcje, napisy, rozdzielenie logiki od wejścia/wyjścia | po `03-funkcje-tablice-napisy` |
| [figury i polimorfizm](../06-oop/08-cwiczenie-figury-polimorfizm.md) | klasę abstrakcyjną, dziedziczenie, polimorfizm | po dziedziczeniu w `06-oop` |
| [kalkulator RPN](../08-projekt-build-testy/09-cwiczenie-kalkulator-rpn.md) | projekt wieloplikowy, build, testy, tokenizację | po `08-projekt-build-testy` |

Przy ocenie ćwiczenia pomostowego wymagaj kompilacji, scenariuszy sprawdzenia
i krótkiego wyjaśnienia decyzji projektowych. Nie musi mieć pełnej rubryki
projektu zaliczeniowego.

## Poziomy osiągnięć

### Poziom podstawowy

Student:

- kompiluje program z instrukcji,
- wykonuje zadania podstawowe,
- rozumie własny kod na poziomie składni,
- potrafi poprawić proste błędy kompilacji,
- oddaje rozwiązanie bez plików wynikowych.

### Poziom dobry

Student:

- samodzielnie dobiera instrukcje, pętle, funkcje i kontenery,
- obsługuje dane błędne i przypadki graniczne,
- dzieli większy program na mniejsze funkcje albo klasy,
- używa czytelnych nazw,
- potrafi uzasadnić podstawowe decyzje projektowe.

### Poziom bardzo dobry

Student:

- projektuje stabilne rozwiązanie przed kodowaniem,
- używa testów albo dokładnych scenariuszy sprawdzenia,
- porządkuje projekt wieloplikowy,
- potrafi refaktoryzować kod bez zmiany działania programu,
- realizuje rozszerzenia bez psucia wariantu minimum.

## Proponowane wagi ocen

| Element | Waga | Uwagi |
| --- | ---: | --- |
| Zadania bieżące | 35% | Krótkie zadania z lekcji i segmentów. |
| Mini-sprawdziany lub ćwiczenia pomostowe | 20% | Samodzielne programy kontrolne po segmentach albo większe ćwiczenia praktyczne. |
| Aktywność techniczna | 10% | Kompilacja, czytanie błędów, praca z Git, poprawki. |
| Projekt zaliczeniowy | 35% | Wariant minimum, jakość kodu, dokumentacja i prezentacja. |

Wagi można zmienić, jeśli projekt ma być głównym elementem zaliczenia. Wtedy
warto zwiększyć wagę projektu do `50%` i zmniejszyć wagę zadań bieżących.

## Poprawki

Poprawka powinna wymagać od studenta konkretnej zmiany, a nie tylko ponownego
wysłania pliku. Dobrze działa taki schemat:

1. Prowadzący wskazuje problem: kompilacja, błąd działania, brak walidacji albo brak dokumentacji.
2. Student poprawia kod i opisuje, co zmienił.
3. Student ponownie uruchamia scenariusze sprawdzenia.
4. Prowadzący sprawdza tylko poprawiany zakres oraz ewentualne regresje.

Nie warto akceptować poprawki, jeśli student nie potrafi wyjaśnić, co zostało
zmienione.

## Samodzielność

Przy ocenie samodzielności zwracaj uwagę, czy student:

- potrafi opowiedzieć, jak działa jego kod,
- umie wskazać miejsce, w którym program wczytuje dane,
- umie wskazać miejsce, w którym program podejmuje decyzję,
- rozumie błędy kompilatora po wprowadzeniu drobnej zmiany,
- potrafi samodzielnie dodać małą funkcję albo warunek.

Jeśli rozwiązanie wygląda dobrze, ale student nie potrafi go wyjaśnić, traktuj
je jako materiał do rozmowy i poprawki, a nie jako pełne zaliczenie.

## Dokumenty pomocnicze

- [Plan semestru](plan-semestru.md) - kiedy robić punkty kontrolne.
- [Checklista oddania](checklista-oddania.md) - co sprawdzić przed przyjęciem pracy.
- [Rubryka projektów](../10-projekty/README.md) - jak oceniać projekty zaliczeniowe.
- [Karta oceny projektu](../10-projekty/karta-oceny-projektu.md) - gotowy arkusz do odbioru projektu.
