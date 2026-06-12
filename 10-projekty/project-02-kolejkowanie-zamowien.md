# Projekt 02 - Kolejkowanie zamówień w sklepie

## Cel projektu

Celem projektu jest przygotowanie konsolowego systemu do obsługi kolejki
zamówień w sklepie. Projekt ma pokazać praktyczne użycie kontenerów STL, klas,
plików, walidacji danych oraz prostego zapisu stanu programu.

System powinien umożliwiać dodawanie zamówień, pobieranie ich w kolejności
przyjęcia oraz zapis i odczyt kolejki między uruchomieniami programu.

## Zakres funkcjonalny

System powinien umożliwiać:

- dodanie nowego zamówienia,
- pobranie najstarszego zamówienia z kolejki,
- wyświetlenie wszystkich oczekujących zamówień,
- wyszukanie zamówienia po identyfikatorze,
- zmianę statusu zamówienia,
- zapis kolejki do pliku,
- odczyt kolejki z pliku przy starcie programu,
- obsługę pustej kolejki i błędnych danych wejściowych.

Przykładowe statusy:

- `New`,
- `InProgress`,
- `Completed`,
- `Cancelled`.

## Wymagania techniczne

Projekt powinien:

- być napisany w C++17,
- używać klas do modelowania zamówienia i systemu kolejkowania,
- używać `std::queue` albo `std::deque` do obsługi kolejności FIFO,
- używać `std::map` albo `std::unordered_map` do szybkiego wyszukiwania po ID,
- używać `enum class` dla statusu zamówienia,
- zapisywać dane do pliku tekstowego, np. CSV,
- rozdzielać deklaracje i implementacje na pliki `.h` i `.cpp`,
- kompilować się z flagami `-Wall -Wextra -pedantic`.

Baza danych SQL albo NoSQL może być rozszerzeniem, ale minimalny wariant
powinien działać bez zewnętrznych zależności.

## Proponowana struktura plików

```text
order-queue/
  include/order_queue/
    order.h
    order_status.h
    order_queue.h
    order_storage.h
  src/
    order.cpp
    order_queue.cpp
    order_storage.cpp
    main.cpp
  tests/
    order_queue_tests.cpp
  data/
    orders.csv
  build/
```

Znaczenie elementów:

- `Order` - pojedyncze zamówienie,
- `OrderStatus` - status zamówienia,
- `OrderQueue` - logika dodawania i pobierania zamówień,
- `OrderStorage` - zapis i odczyt zamówień z pliku.

## Model danych

Zamówienie powinno mieć co najmniej:

- `id`,
- `customerName`,
- `createdAt`,
- `totalAmount`,
- `status`.

Przykład:

```cpp
struct Order {
    std::string id;
    std::string customerName;
    double totalAmount;
    OrderStatus status;
};
```

## Minimalny wariant zaliczeniowy

Minimalna wersja projektu powinna zawierać:

1. Menu konsolowe z opcjami:
   - dodaj zamówienie,
   - pobierz następne zamówienie,
   - wyświetl kolejkę,
   - zapisz dane,
   - wczytaj dane,
   - zakończ.
2. Klasę `OrderQueue`, która pilnuje kolejności FIFO.
3. Walidację pustej kolejki.
4. Zapis i odczyt danych z pliku CSV.
5. Przykładowy plik z danymi.
6. Instrukcję kompilacji i uruchomienia w `README.md` projektu.

## Rozszerzenia dla chętnych

Możliwe rozszerzenia:

- filtrowanie zamówień po statusie,
- priorytety zamówień,
- historia zrealizowanych zamówień,
- zapis do SQLite,
- eksport raportu dziennego,
- testy automatyczne dla `OrderQueue`,
- osobny tryb demonstracyjny z przykładowymi zamówieniami,
- obsługa anulowania zamówienia po ID.

## Kryteria oceny

Projekt jest zaliczony, jeśli:

- kompiluje się bez błędów i ostrzeżeń,
- poprawnie dodaje zamówienia,
- pobiera zamówienia w kolejności FIFO,
- obsługuje pustą kolejkę,
- zapisuje i odczytuje dane z pliku,
- używa klas i kontenerów STL,
- ma czytelne menu konsolowe,
- zawiera instrukcję uruchomienia,
- zawiera testy albo opis ręcznych scenariuszy sprawdzenia.

## Scenariusze sprawdzenia

1. Dodaj trzy zamówienia i sprawdź, czy są pobierane w tej samej kolejności.
2. Spróbuj pobrać zamówienie z pustej kolejki i sprawdź komunikat błędu.
3. Zapisz kolejkę do pliku, uruchom program ponownie i wczytaj dane.
4. Wyszukaj zamówienie po poprawnym i niepoprawnym ID.
5. Zmień status zamówienia i sprawdź, czy zmiana jest widoczna po zapisie i
   odczycie.
