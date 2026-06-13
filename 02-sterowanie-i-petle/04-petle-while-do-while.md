# 04 - Pętle `while` i `do while`

## Cel lekcji

Celem lekcji jest nauczenie pętli zależnych od warunku: `while` i `do while`.

## Wymagania wstępne

Student powinien znać:

- [01-instrukcje-warunkowe.md](01-instrukcje-warunkowe.md),
- [03-petla-for.md](03-petla-for.md),
- podstawowe operatory porównania i logiczne.

## Krótka teoria

### Pętla `while`

Pętla `while` wykonuje instrukcje tak długo, jak długo warunek jest prawdziwy.

Składnia:

```cpp
while (warunek)
{
    // instrukcje
}
```

Przykład:

```cpp
int i = 1;

while (i <= 10)
{
    std::cout << i << std::endl;
    i++;
}
```

Pętla `while` najpierw sprawdza warunek, a dopiero potem wykonuje ciało pętli. Jeżeli warunek od początku jest fałszywy, pętla nie wykona się ani razu.

Pełny przykład znajduje się w pliku [examples/while_count.cpp](examples/while_count.cpp).

### Kiedy używać `while`

Pętla `while` jest dobrym wyborem, gdy nie wiemy z góry, ile razy pętla ma się wykonać.

Przykłady:

- program czeka, aż użytkownik poda poprawną wartość,
- program wykonuje menu do momentu wyboru opcji wyjścia,
- program przetwarza dane, dopóki spełniony jest warunek.

## Przykład kodu: suma do zera

```cpp
int liczba;
int suma = 0;

std::cout << "Podaj liczbe, 0 konczy program: ";
std::cin >> liczba;

while (liczba != 0)
{
    suma += liczba;

    std::cout << "Podaj liczbe, 0 konczy program: ";
    std::cin >> liczba;
}

std::cout << "Suma: " << suma << std::endl;
```

Pełny przykład znajduje się w pliku [examples/while_sum_until_zero.cpp](examples/while_sum_until_zero.cpp).

### Pętla `do while`

Pętla `do while` najpierw wykonuje ciało pętli, a dopiero potem sprawdza warunek.

Składnia:

```cpp
do
{
    // instrukcje
}
while (warunek);
```

Uwaga: po `while (warunek)` na końcu pętli `do while` stawiamy średnik.

Przykład:

```cpp
int wybor;

do
{
    std::cout << "1. Start\n";
    std::cout << "0. Wyjscie\n";
    std::cout << "Wybor: ";
    std::cin >> wybor;
}
while (wybor != 0);
```

Pełny przykład znajduje się w pliku [examples/do_while_menu.cpp](examples/do_while_menu.cpp).

### Różnica między `while` i `do while`

`while` może nie wykonać się ani razu:

```cpp
int i = 10;

while (i < 5)
{
    std::cout << i << std::endl;
}
```

`do while` wykona się co najmniej raz:

```cpp
int i = 10;

do
{
    std::cout << i << std::endl;
}
while (i < 5);
```

### Pętla nieskończona

Pętla nieskończona powstaje wtedy, gdy warunek nigdy nie staje się fałszywy.

```cpp
int i = 1;

while (i <= 10)
{
    std::cout << i << std::endl;
    // brak i++
}
```

W tym przykładzie `i` nigdy się nie zmienia, więc warunek `i <= 10` pozostaje prawdziwy.

## Zadania do wykonania

1. Napisz program, który za pomocą `while` wypisuje liczby od `1` do `110`.
2. Napisz program, który za pomocą `while` wypisuje liczby od `100` do `1`.
3. Napisz program, który za pomocą `while` sumuje liczby od `1` do `10`.
4. Napisz program, który za pomocą `do while` wypisuje liczby parzyste od `0` do `20`.
5. Napisz program, który za pomocą `do while` oblicza iloczyn liczb od `1` do `5`.
6. Napisz program, który wczytuje liczby od użytkownika aż do podania `0`, a następnie wypisuje ich sumę.
7. Napisz program z menu działającym w pętli `do while`, gdzie opcja `0` kończy program.

## Kryteria zaliczenia

Program powinien:

- poprawnie używać pętli `while` lub `do while`,
- mieć warunek kończący pętlę,
- aktualizować zmienne używane w warunku,
- kompilować się bez błędów,
- wypisywać wynik w czytelnej formie.

## Pytania kontrolne

1. Czym różni się `while` od `do while`?
2. Kiedy pętla `while` może nie wykonać się ani razu?
3. Dlaczego `do while` dobrze pasuje do menu programu?
4. Co powoduje pętlę nieskończoną?
5. Dlaczego po `while (warunek)` w pętli `do while` stawiamy średnik?
