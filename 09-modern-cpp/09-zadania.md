# 09 - Zadania

## Cel zestawu zadań

Ten plik zbiera zadania do segmentu [09 - Modern C++](README.md). Zadania
sprawdzają konstrukcje C++11 i C++17, lambdy, silniejsze typy, semantykę
przenoszenia, przestrzenie nazw, organizację kodu oraz podstawy
wielowątkowości.

## Zasady wykonania

Każde zadanie powinno być zapisane w osobnym pliku `.cpp` albo osobnym katalogu,
jeśli wymaga kilku plików. Program powinien kompilować się bez błędów i
ostrzeżeń.

Przykład kompilacji:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic nazwa_pliku.cpp -o program
./program
```

Dla zadań z wątkami użyj dodatkowo `-pthread`, jeśli wymaga tego system.

## Wymagania jakościowe

W zadaniach z tego segmentu zwracaj uwagę na:

- kompilację z flagami `-std=c++17 -Wall -Wextra -pedantic`,
- używanie `auto` tylko wtedy, gdy nie ukrywa znaczenia kodu,
- `enum class` zamiast luźnych liczb lub napisów opisujących stan,
- lambdy krótkie i czytelne, a dłuższą logikę przeniesioną do funkcji,
- wywołanie `join` dla każdego uruchomionego wątku.
- brak współdzielonych danych bez ochrony, jeśli używasz kilku wątków.

## Poziom 1 - Podstawy modern C++

### Zadanie 1. Inicjalizacja klamrowa

Utwórz zmienne typu `int`, `double`, `std::string` oraz `std::vector<int>` z
użyciem inicjalizacji klamrowej. Wypisz ich wartości.

Wymagania:

- dołącz potrzebne nagłówki,
- pokaż inicjalizację pustego i niepustego wektora,
- w komentarzu zapisz, dlaczego inicjalizacja klamrowa jest czytelna.

### Zadanie 2. `auto` w praktyce

Utwórz wektor napisów i przejdź po nim pętlą zakresową z `const auto&`.
Następnie zapisz iterator z `begin()` do zmiennej z `auto`.

Wymagania:

- użyj `const auto&` przy wypisywaniu napisów,
- nie używaj `auto`, jeśli typ prosty jest bardziej czytelny, np. przy `int licznik`.

### Zadanie 3. `nullptr`

Utwórz strukturę `Student` oraz funkcję zwracającą wskaźnik do najlepszego
studenta albo `nullptr`, jeśli lista jest pusta.

Scenariusze sprawdzenia:

- pusta lista zwraca `nullptr`,
- lista z kilkoma studentami zwraca studenta z najwyższą liczbą punktów.

### Zadanie 4. Pętla zakresowa

Przepisz program z klasyczną pętlą indeksową na pętlę zakresową. Zapisz w
komentarzu, która wersja jest czytelniejsza i dlaczego.

Nie używaj pętli zakresowej, jeśli potrzebujesz modyfikować indeks. W komentarzu
opisz tę różnicę.

### Zadanie 5. Structured bindings

Utwórz `std::pair<std::string, int>` z nazwą i wynikiem. Rozpakuj parę przez
structured bindings i wypisz wynik.

Przykład wyniku:

```text
Anna: 82
```

## Poziom 2 - Lambdy i algorytmy

### Zadanie 6. Sortowanie przez lambdę

Utwórz wektor struktur `Product` z polami `name` i `price`. Posortuj produkty
rosnąco według ceny za pomocą `std::sort` i lambdy.

Wymagania:

- lambda powinna przyjmować argumenty przez `const Product&`,
- po sortowaniu wypisz produkty, aby pokazać kolejność.

### Zadanie 7. Filtrowanie z progiem

Utwórz zmienną `minimumPrice` i skopiuj do nowego wektora tylko produkty droższe
lub równe tej wartości. Użyj `std::copy_if` i przechwycenia przez wartość.

Scenariusz sprawdzenia:

```text
minimumPrice = 100
Produkty: 80, 100, 150
Wynik: 100, 150
```

### Zadanie 8. Liczenie elementów

Policz produkty tańsze niż `100` za pomocą `std::count_if`.

Wynik wypisz jako pełne zdanie, np. `Produkty tansze niz 100: 2`.

### Zadanie 9. `find_if`

Znajdź pierwszy produkt o podanej nazwie. Pamiętaj o sprawdzeniu wyniku przed
dereferencją iteratora.

Sprawdź przypadek znaleziony i nieznaleziony.

### Zadanie 10. Lambda czy funkcja

Przepisz jeden warunek z lambdy na osobną funkcję. Porównaj czytelność obu wersji
w komentarzu.

Jeśli warunek ma więcej niż jedną instrukcję albo jest używany w kilku miejscach,
preferuj osobną funkcję.

## Poziom 3 - Silniejsze typy i API

### Zadanie 11. `enum class`

Utwórz `enum class OrderStatus` z wartościami:

- `New`,
- `Paid`,
- `Sent`,
- `Cancelled`.

Dodaj funkcję `statusToText`.

Wymagania:

- w `switch` obsłuż wszystkie wartości `OrderStatus`,
- nie używaj gołych liczb do reprezentowania statusu.

### Zadanie 12. Aliasy typów

Dodaj aliasy:

```cpp
using OrderId = std::string;
using Money = double;
```

Użyj ich w strukturze `Order`.

W komentarzu zapisz, czy alias zwiększył czytelność pól struktury.

### Zadanie 13. `override`

Utwórz klasę bazową `Printer` z metodą wirtualną `print`. Następnie utwórz
klasy `ConsolePrinter` i `SilentPrinter`, które nadpisują tę metodę z użyciem
`override`.

Wymagania:

- destruktor klasy bazowej powinien być wirtualny,
- pokaż wywołanie przez referencję albo wskaźnik do klasy bazowej.

### Zadanie 14. `= delete`

Utwórz klasę `Logger`, której nie da się kopiować. Użyj `= delete` dla
konstruktora kopiującego i operatora przypisania.

W komentarzu pokaż przykład linii, która nie powinna się kompilować, ale nie
zostawiaj jej aktywnej w kodzie.

### Zadanie 15. `= default`

Dodaj do klasy `Config` jawny konstruktor domyślny przez `= default`. Zapisz w
komentarzu, po co taki zapis może być czytelny.

Dodaj co najmniej jedno pole z wartością domyślną.

## Poziom 4 - Przenoszenie i organizacja kodu

### Zadanie 16. Kopiowanie i przenoszenie

Utwórz klasę `Buffer`, która przechowuje `std::vector<int>`. Dodaj konstruktor
kopiujący i przenoszący, które wypisują odpowiedni komunikat.

Wymagania:

- konstruktor przenoszący powinien używać `std::move`,
- dołącz `<utility>`.

### Zadanie 17. `std::move`

Utwórz obiekt `Buffer`, skopiuj go do drugiego obiektu, a następnie przenieś do
trzeciego przez `std::move`.

Wynik programu powinien pokazać komunikat dla kopiowania i komunikat dla
przenoszenia.

### Zadanie 18. Stan po przeniesieniu

Po przeniesieniu wypisz rozmiar obiektu źródłowego i docelowego. Zapisz w
komentarzu, dlaczego nie należy zakładać konkretnej zawartości obiektu po
przeniesieniu.

Wymaganie: obiekt po przeniesieniu może być użyty tylko w poprawnym, ale
nieokreślonym stanie. Nie pisz kodu zależnego od konkretnej zawartości.

### Zadanie 19. Przestrzeń nazw

Utwórz przestrzeń nazw `app::reports` i funkcję `printSummary`. Wywołaj ją przez
operator `::`.

Dodaj drugą funkcję o tej samej nazwie w innej przestrzeni nazw, aby pokazać,
po co używa się kwalifikacji nazw.

### Zadanie 20. Podział na pliki

Utwórz mały moduł logiczny `messages` z plikami:

- `message.h`,
- `message.cpp`,
- `main.cpp`.

W komentarzu wyjaśnij różnicę między takim modułem logicznym a modułem C++20.

Wymagania:

- `message.h` ma zawierać deklaracje,
- `message.cpp` ma zawierać implementację,
- `main.cpp` ma korzystać z interfejsu z nagłówka.

## Poziom 5 - Wątki i mini-projekty

### Zadanie 21. Pierwszy wątek

Utwórz funkcję `work`, która wypisuje komunikat. Uruchom ją w `std::thread` i
zakończ program przez `join`.

Wymagania:

- dołącz `<thread>`,
- wywołaj `join` dokładnie raz dla uruchomionego wątku.

### Zadanie 22. Dwa wątki

Uruchom dwa wątki, które wykonują tę samą funkcję z różnymi nazwami zadań.
Zaobserwuj, że kolejność komunikatów może się zmieniać.

W komentarzu zapisz, dlaczego nie należy zakładać stałej kolejności wypisywania.

### Zadanie 23. Bezpieczny licznik

Utwórz klasę `SafeCounter` z `std::mutex`, metodą `add` i metodą `getTotal`.
Uruchom kilka wątków zwiększających licznik.

Wymagania:

- użyj `std::lock_guard<std::mutex>`,
- wszystkie wątki muszą zostać zakończone przez `join`,
- wynik końcowy powinien być zgodny z liczbą wykonanych inkrementacji.

### Zadanie 24. Mini-projekt: monitor zadań

Przygotuj mini-projekt `task-monitor`, który:

- przechowuje listę zadań,
- używa `enum class` dla statusu zadania,
- sortuje zadania lambdą,
- ma przestrzeń nazw `app::tasks`,
- uruchamia dwa wątki zwiększające licznik wykonanych operacji,
- kompiluje się przez prostą komendę albo skrypt `build.sh`.

## Wariant minimum

Do zaliczenia segmentu wykonaj co najmniej:

1. Zadanie 1 albo 2.
2. Zadanie 3 albo 5.
3. Zadanie 6 albo 7.
4. Zadanie 11 albo 13.
5. Zadanie 16 albo 17.
6. Zadanie 19 albo 20.
7. Zadanie 21 albo 23.

Zadanie 24 jest mini-projektem rozszerzonym. Możesz je robić po wykonaniu
wariantu minimum.

## Mini-sprawdzian segmentu

Napisz program `order-monitor`, który:

- używa `enum class OrderStatus`,
- przechowuje zamówienia w `std::vector`,
- filtruje zamówienia lambdą przez `std::copy_if`,
- sortuje zamówienia po wartości przez `std::sort`,
- używa aliasów `OrderId` i `Money`,
- ma przestrzeń nazw `app::orders`,
- uruchamia dwa wątki zwiększające bezpieczny licznik przetworzonych operacji.

Scenariusz sprawdzenia:

```text
Zamowienia o statusie Paid: 2
Najdrozsze zamowienie: ORD-3
Przetworzone operacje: 2000
```

## Kryteria zaliczenia segmentu

Student zalicza segment, jeśli potrafi samodzielnie:

- użyć `auto`, `nullptr` i inicjalizacji klamrowej,
- napisać lambdę i użyć jej z algorytmem STL,
- przechwycić zmienną w lambdzie,
- zdefiniować `enum class`,
- użyć aliasu typu przez `using`,
- zastosować `override`, `= default` i `= delete`,
- wyjaśnić różnicę między kopiowaniem i przenoszeniem,
- użyć `std::move`,
- zorganizować kod w przestrzeni nazw,
- rozdzielić mały moduł logiczny na `.h` i `.cpp`,
- utworzyć `std::thread`, wywołać `join` i ochronić wspólne dane przez `std::mutex`.

## Checklista oddania

Przed oddaniem rozwiązań sprawdź:

- [ ] Każde zadanie jest w osobnym pliku `.cpp` albo osobnym katalogu projektu.
- [ ] Programy kompilują się z `-Wall -Wextra -pedantic`.
- [ ] `auto` poprawia czytelność zamiast ją ukrywać.
- [ ] Lambdy są krótkie, a dłuższa logika jest w funkcjach.
- [ ] `enum class` zastępuje luźne liczby albo napisy statusów.
- [ ] Po `std::move` kod nie zakłada konkretnej zawartości obiektu źródłowego.
- [ ] Każdy uruchomiony wątek ma `join`.
- [ ] Wspólne dane używane przez wątki są chronione przez `std::mutex`.

## Archiwum

Oryginalne materiały źródłowe tego segmentu są zachowane w katalogu [archive](archive).
