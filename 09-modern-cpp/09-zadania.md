# 09 - Zadania

## Cel

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

## Poziom 1 - Podstawy modern C++

### Zadanie 1. Inicjalizacja klamrowa

Utwórz zmienne typu `int`, `double`, `std::string` oraz `std::vector<int>` z
użyciem inicjalizacji klamrowej. Wypisz ich wartości.

### Zadanie 2. `auto` w praktyce

Utwórz wektor napisów i przejdź po nim pętlą zakresową z `const auto&`.
Następnie zapisz iterator z `begin()` do zmiennej z `auto`.

### Zadanie 3. `nullptr`

Utwórz strukturę `Student` oraz funkcję zwracającą wskaźnik do najlepszego
studenta albo `nullptr`, jeśli lista jest pusta.

### Zadanie 4. Pętla zakresowa

Przepisz program z klasyczną pętlą indeksową na pętlę zakresową. Zapisz w
komentarzu, która wersja jest czytelniejsza i dlaczego.

### Zadanie 5. Structured bindings

Utwórz `std::pair<std::string, int>` z nazwą i wynikiem. Rozpakuj parę przez
structured bindings i wypisz wynik.

## Poziom 2 - Lambdy i algorytmy

### Zadanie 6. Sortowanie przez lambdę

Utwórz wektor struktur `Product` z polami `name` i `price`. Posortuj produkty
rosnąco według ceny za pomocą `std::sort` i lambdy.

### Zadanie 7. Filtrowanie z progiem

Utwórz zmienną `minimumPrice` i skopiuj do nowego wektora tylko produkty droższe
lub równe tej wartości. Użyj `std::copy_if` i przechwycenia przez wartość.

### Zadanie 8. Liczenie elementów

Policz produkty tańsze niż `100` za pomocą `std::count_if`.

### Zadanie 9. `find_if`

Znajdź pierwszy produkt o podanej nazwie. Pamiętaj o sprawdzeniu wyniku przed
dereferencją iteratora.

### Zadanie 10. Lambda czy funkcja

Przepisz jeden warunek z lambdy na osobną funkcję. Porównaj czytelność obu wersji
w komentarzu.

## Poziom 3 - Silniejsze typy i API

### Zadanie 11. `enum class`

Utwórz `enum class OrderStatus` z wartościami:

- `New`,
- `Paid`,
- `Sent`,
- `Cancelled`.

Dodaj funkcję `statusToText`.

### Zadanie 12. Aliasy typów

Dodaj aliasy:

```cpp
using OrderId = std::string;
using Money = double;
```

Użyj ich w strukturze `Order`.

### Zadanie 13. `override`

Utwórz klasę bazową `Printer` z metodą wirtualną `print`. Następnie utwórz
klasy `ConsolePrinter` i `SilentPrinter`, które nadpisują tę metodę z użyciem
`override`.

### Zadanie 14. `= delete`

Utwórz klasę `Logger`, której nie da się kopiować. Użyj `= delete` dla
konstruktora kopiującego i operatora przypisania.

### Zadanie 15. `= default`

Dodaj do klasy `Config` jawny konstruktor domyślny przez `= default`. Zapisz w
komentarzu, po co taki zapis może być czytelny.

## Poziom 4 - Przenoszenie i organizacja kodu

### Zadanie 16. Kopiowanie i przenoszenie

Utwórz klasę `Buffer`, która przechowuje `std::vector<int>`. Dodaj konstruktor
kopiujący i przenoszący, które wypisują odpowiedni komunikat.

### Zadanie 17. `std::move`

Utwórz obiekt `Buffer`, skopiuj go do drugiego obiektu, a następnie przenieś do
trzeciego przez `std::move`.

### Zadanie 18. Stan po przeniesieniu

Po przeniesieniu wypisz rozmiar obiektu źródłowego i docelowego. Zapisz w
komentarzu, dlaczego nie należy zakładać konkretnej zawartości obiektu po
przeniesieniu.

### Zadanie 19. Przestrzeń nazw

Utwórz przestrzeń nazw `app::reports` i funkcję `printSummary`. Wywołaj ją przez
operator `::`.

### Zadanie 20. Podział na pliki

Utwórz mały moduł logiczny `messages` z plikami:

- `message.h`,
- `message.cpp`,
- `main.cpp`.

W komentarzu wyjaśnij różnicę między takim modułem logicznym a modułem C++20.

## Poziom 5 - Wątki i mini-projekty

### Zadanie 21. Pierwszy wątek

Utwórz funkcję `work`, która wypisuje komunikat. Uruchom ją w `std::thread` i
zakończ program przez `join`.

### Zadanie 22. Dwa wątki

Uruchom dwa wątki, które wykonują tę samą funkcję z różnymi nazwami zadań.
Zaobserwuj, że kolejność komunikatów może się zmieniać.

### Zadanie 23. Bezpieczny licznik

Utwórz klasę `SafeCounter` z `std::mutex`, metodą `add` i metodą `getTotal`.
Uruchom kilka wątków zwiększających licznik.

### Zadanie 24. Mini-projekt: monitor zadań

Przygotuj mini-projekt `task-monitor`, który:

- przechowuje listę zadań,
- używa `enum class` dla statusu zadania,
- sortuje zadania lambdą,
- ma przestrzeń nazw `app::tasks`,
- uruchamia dwa wątki zwiększające licznik wykonanych operacji,
- kompiluje się przez prostą komendę albo skrypt `build.sh`.

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

## Archiwum

Oryginalne materiały źródłowe tego segmentu będą zachowane w katalogu
[archive](archive) po zakończeniu porządkowania.
