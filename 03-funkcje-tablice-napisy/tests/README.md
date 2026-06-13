# Testy segmentu 03

Ten katalog pokazuje prosty sposób testowania funkcji bez zewnętrznego frameworka.
Test jest zwykłym programem C++, który zwraca:

- `0`, jeśli wszystkie przypadki przechodzą,
- `1`, jeśli co najmniej jeden przypadek kończy się błędem.

## Uruchomienie

```sh
c++ -std=c++17 -Wall -Wextra -pedantic tests/test_podstawowe_funkcje.cpp -o /tmp/test_podstawowe_funkcje
/tmp/test_podstawowe_funkcje
```

Ten test jest też uruchamiany przez główny skrypt:

```sh
sh ../../tools/check-examples.sh
```

## Co testować

Najłatwiej testować funkcje, które:

- przyjmują argumenty,
- zwracają wynik,
- nie pytają użytkownika o dane w środku funkcji,
- nie wypisują wyniku jako jedynego efektu działania.
