# Testy segmentu 07

Ten katalog pokazuje prosty sposób testowania kodu używającego kontenerów STL
i algorytmów biblioteki standardowej.

## Uruchomienie

```sh
c++ -std=c++17 -Wall -Wextra -pedantic tests/test_stl_algorytmy.cpp -o /tmp/test_stl_algorytmy
/tmp/test_stl_algorytmy
```

Ten test jest też uruchamiany przez główny skrypt:

```sh
sh ../tools/check-examples.sh
```

## Co testować

W zadaniach z STL warto sprawdzać:

- wynik sortowania,
- filtrowanie danych,
- wyszukiwanie elementów,
- zachowanie mapy dla istniejącego i brakującego klucza,
- kolejność działania stosu albo kolejki.
