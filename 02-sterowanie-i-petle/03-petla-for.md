# 03 - Pętla `for`

## Cel lekcji

Celem lekcji jest nauczenie klasycznej pętli `for`, czyli konstrukcji używanej wtedy, gdy z góry wiemy, ile razy chcemy powtórzyć instrukcje.

## Wymagania wstępne

Student powinien znać:

- [01-instrukcje-warunkowe.md](01-instrukcje-warunkowe.md),
- [02-switch-i-operator-warunkowy.md](02-switch-i-operator-warunkowy.md),
- podstawowe operatory arytmetyczne z segmentu [01-podstawy](../01-podstawy/README.md).

## Krótka teoria

### Składnia pętli `for`

```cpp
for (inicjalizacja; warunek; zmiana)
{
    // instrukcje wykonywane w pętli
}
```

Najczęstszy przykład:

```cpp
for (int i = 0; i < 10; i++)
{
    std::cout << i << std::endl;
}
```

Znaczenie elementów:

- `int i = 0` - utworzenie licznika pętli,
- `i < 10` - warunek kontynuowania pętli,
- `i++` - zwiększenie licznika po każdym obiegu.

### Kolejność działania

Dla pętli:

```cpp
for (int i = 1; i <= 3; i++)
{
    std::cout << i << std::endl;
}
```

Program działa tak:

1. Tworzy zmienną `i` i nadaje jej wartość `1`.
2. Sprawdza warunek `i <= 3`.
3. Wykonuje ciało pętli.
4. Wykonuje `i++`.
5. Wraca do sprawdzenia warunku.

Wynik:

```text
1
2
3
```

Ten przykład znajduje się w pliku [examples/for_count.cpp](examples/for_count.cpp).

### Pętla z innym krokiem

Licznik nie musi zwiększać się o `1`.

```cpp
for (int i = 0; i <= 20; i += 2)
{
    std::cout << i << std::endl;
}
```

Ta pętla wypisuje liczby parzyste od `0` do `20`.

### Pętla malejąca

Pętla może też odliczać w dół.

```cpp
for (int i = 10; i >= 1; i--)
{
    std::cout << i << std::endl;
}
```

## Przykład kodu: suma liczb

Pętla `for` często służy do obliczania sumy.

```cpp
int suma = 0;

for (int i = 1; i <= 100; i++)
{
    suma += i;
}

std::cout << "Suma: " << suma << std::endl;
```

Pełny przykład znajduje się w pliku [examples/for_sum.cpp](examples/for_sum.cpp).

## Przykład kodu: pętla i warunek

Wewnątrz pętli można używać instrukcji `if`.

```cpp
for (int i = 1; i <= 20; i++)
{
    if (i % 2 == 0)
    {
        std::cout << i << std::endl;
    }
}
```

Ten kod wypisuje liczby parzyste od `1` do `20`.

Pełny przykład znajduje się w pliku [examples/for_even_numbers.cpp](examples/for_even_numbers.cpp).

## Typowe błędy

### Zły warunek końca

```cpp
for (int i = 0; i <= 10; i++)
```

Ta pętla wykona się `11` razy, bo obejmuje wartości od `0` do `10`.

### Brak zmiany licznika

```cpp
for (int i = 0; i < 10;)
{
    std::cout << i << std::endl;
}
```

Jeżeli licznik się nie zmienia, pętla może nigdy się nie skończyć.

### Użycie licznika poza zakresem

```cpp
for (int i = 0; i < 10; i++)
{
    std::cout << i << std::endl;
}

// tutaj i nie jest już dostępne
```

Zmienna `i` zadeklarowana w pętli istnieje tylko w tej pętli.

## Zadania do wykonania

1. Napisz program, który za pomocą pętli `for` wypisuje liczby od `1` do `110`.
2. Napisz program, który za pomocą pętli `for` wypisuje liczby od `100` do `1`.
3. Napisz program, który wypisuje liczby parzyste od `0` do `20`.
4. Napisz program, który wypisuje liczby podzielne przez `3` z przedziału od `1` do `100`.
5. Napisz program, który sumuje liczby całkowite od `1` do `110`.
6. Napisz program, który sumuje liczby parzyste od `1` do `110`.
7. Napisz program, który oblicza silnię liczby `n` podanej przez użytkownika.
8. Napisz program, który wypisuje litery alfabetu od `a` do `z`.

## Kryteria zaliczenia

Program powinien:

- poprawnie używać składni `for (inicjalizacja; warunek; zmiana)`,
- kończyć pętlę po oczekiwanej liczbie obiegów,
- stosować czytelne nazwy zmiennych pomocniczych,
- kompilować się bez błędów,
- wypisywać wynik w czytelnej formie.

## Pytania kontrolne

1. Z jakich trzech części składa się nagłówek pętli `for`?
2. Kiedy najczęściej wybieramy pętlę `for`?
3. Ile razy wykona się pętla `for (int i = 0; i < 10; i++)`?
4. Czym różni się `i++` od `i += 2` w nagłówku pętli?
5. Co może się stać, jeśli licznik pętli nigdy nie zmieni wartości?
