# Testy segmentu 06

Ten katalog pokazuje prosty sposób testowania klas bez zewnętrznego frameworka.
Test jest zwykłym programem C++, który tworzy obiekty, wywołuje metody i zwraca:

- `0`, jeśli wszystkie przypadki przechodzą,
- `1`, jeśli co najmniej jeden przypadek kończy się błędem.

## Uruchomienie

```sh
c++ -std=c++17 -Wall -Wextra -pedantic tests/test_konto.cpp -o /tmp/test_konto
/tmp/test_konto
```

Ten test jest też uruchamiany przez główny skrypt:

```sh
sh ../tools/check-examples.sh
```

## Co testować w klasach

W klasach warto sprawdzać:

- konstruktor i stan początkowy obiektu,
- metody zmieniające stan,
- metody `const`, które tylko odczytują dane,
- reakcję na błędne dane,
- operatory, jeśli klasa je definiuje.
