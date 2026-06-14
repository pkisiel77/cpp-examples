# Projekt 12 - Symulator bankomatu

## Cel projektu

Celem projektu jest przygotowanie aplikacji konsolowej symulującej działanie
bankomatu. Projekt ma pokazać modelowanie prostego systemu użytkowego,
walidację danych, obsługę menu, klasy, operacje na stanie konta oraz
podstawową historię operacji.

Projekt jest dobrym wyborem dla osób, które chcą połączyć programowanie
obiektowe, pracę ze stanem programu, proste uwierzytelnianie i scenariusze
błędnych danych.

## Zakres funkcjonalny

Program powinien umożliwiać:

- uruchomienie bankomatu w terminalu,
- zalogowanie użytkownika numerem karty albo identyfikatorem konta,
- sprawdzenie kodu PIN,
- wyświetlenie salda,
- wypłatę środków,
- wpłatę środków,
- zmianę PIN-u,
- wyświetlenie historii operacji,
- zakończenie sesji użytkownika,
- obsługę błędnych danych wejściowych.

Przykładowe menu:

```text
1. Sprawdz saldo
2. Wplac srodki
3. Wyplac srodki
4. Historia operacji
5. Zmien PIN
6. Wyloguj
```

## Wymagania techniczne

Projekt powinien:

- być napisany w C++17,
- używać klasy `Account` do reprezentowania konta,
- używać klasy `Atm` albo `AtmSession` do obsługi sesji użytkownika,
- ukrywać saldo i PIN w polach prywatnych,
- walidować kwoty wpłaty i wypłaty,
- nie pozwalać wypłacić więcej niż wynosi saldo,
- ograniczać liczbę nieudanych prób podania PIN-u,
- używać `std::vector` do historii operacji,
- rozdzielać deklaracje i implementacje na pliki `.h` i `.cpp`,
- kompilować się z flagami `-Wall -Wextra -pedantic`.

## Proponowana struktura plików

```text
atm/
  include/atm/
    account.h
    atm.h
    transaction.h
    menu.h
  src/
    account.cpp
    atm.cpp
    transaction.cpp
    menu.cpp
    main.cpp
  tests/
    account_tests.cpp
  data/
    accounts.csv
  build/
```

Znaczenie elementów:

- `Account` - dane konta, saldo, PIN i operacje na środkach,
- `Atm` - logika logowania oraz obsługa sesji,
- `Transaction` - pojedyncza operacja w historii,
- `Menu` - komunikacja z użytkownikiem w terminalu.

Kompilowalny punkt startowy dla modelu konta znajduje się w pliku
[examples/atm_account.cpp](examples/atm_account.cpp). Przykład pokazuje klasę
`Account`, historię operacji oraz podstawową walidację wpłaty, wypłaty i zmiany
PIN-u.

## Model danych

Konto powinno mieć co najmniej:

- identyfikator konta,
- PIN,
- saldo,
- informację, czy konto jest zablokowane,
- historię operacji.

Przykład:

```cpp
enum class TransactionType {
    Deposit,
    Withdrawal,
    PinChange
};

struct Transaction {
    TransactionType type;
    double amount;
    std::string description;
};

class Account {
public:
    Account(std::string id, std::string pin, double balance);

    bool verifyPin(const std::string& pin) const;
    double balance() const;
    bool deposit(double amount);
    bool withdraw(double amount);
    bool changePin(const std::string& oldPin, const std::string& newPin);

private:
    std::string id_;
    std::string pin_;
    double balance_;
    std::vector<Transaction> history_;
};
```

## Minimalny wariant zaliczeniowy

Minimalna wersja projektu powinna zawierać:

1. Menu startowe z logowaniem.
2. Jedno przykładowe konto zapisane w kodzie albo w pliku.
3. Sprawdzenie PIN-u.
4. Blokadę po trzech błędnych próbach PIN-u.
5. Wyświetlenie salda.
6. Wpłatę dodatniej kwoty.
7. Wypłatę dodatniej kwoty.
8. Odmowę wypłaty przy braku środków.
9. Historię operacji w trakcie działania programu.
10. Zakończenie sesji użytkownika.
11. Instrukcję kompilacji i uruchomienia.

## Rozszerzenia dla chętnych

Możliwe rozszerzenia:

- wiele kont,
- zapis kont do pliku CSV,
- odczyt kont z pliku przy starcie programu,
- przelewy między kontami,
- limit dziennej wypłaty,
- data i godzina operacji,
- eksport historii operacji do pliku,
- testy automatyczne klasy `Account`,
- osobna rola administratora,
- prosta walidacja formatu PIN-u.

## Kryteria oceny

Projekt jest zaliczony, jeśli:

- kompiluje się bez błędów i ostrzeżeń,
- poprawnie loguje użytkownika poprawnym PIN-em,
- odrzuca błędny PIN,
- blokuje konto albo sesję po zbyt wielu błędnych próbach,
- poprawnie pokazuje saldo,
- poprawnie obsługuje wpłatę,
- poprawnie obsługuje wypłatę,
- nie pozwala wypłacić więcej niż wynosi saldo,
- zapisuje operacje w historii,
- ma czytelne menu konsolowe,
- kod jest podzielony na klasy i moduły,
- zawiera instrukcję uruchomienia,
- zawiera testy albo opis ręcznych scenariuszy sprawdzenia.

## Scenariusze sprawdzenia

1. Zaloguj się poprawnym PIN-em i sprawdź saldo.
2. Podaj trzy razy błędny PIN i sprawdź blokadę.
3. Wpłać `100` i sprawdź, czy saldo wzrosło.
4. Wypłać `50` i sprawdź, czy saldo spadło.
5. Spróbuj wypłacić kwotę większą niż saldo.
6. Spróbuj wpłacić albo wypłacić kwotę ujemną.
7. Wykonaj kilka operacji i wyświetl historię.
8. Zmień PIN i sprawdź logowanie nowym PIN-em.

## Źródło

Projekt powstał na podstawie starszego zadania z
[zadań pomocniczych TNT](tnt-tasks/atm.md).
