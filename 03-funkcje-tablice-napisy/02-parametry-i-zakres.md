# 02 - Parametry i zakres zmiennych

## Cel lekcji

Celem lekcji jest zrozumienie, jak funkcje otrzymują dane przez parametry, czym różnią się parametry od argumentów oraz gdzie są dostępne zmienne lokalne.

## Wymagania wstępne

Student powinien znać materiał z lekcji [01-funkcje-podstawy.md](01-funkcje-podstawy.md): definicję funkcji, deklarację funkcji, wywołanie funkcji i `return`.

## Krótka teoria

### Parametr i argument

**Parametr** to zmienna zapisana w definicji funkcji.

```cpp
int dodaj(int a, int b)
{
    return a + b;
}
```

W tym przykładzie `a` i `b` są parametrami.

**Argument** to konkretna wartość przekazana podczas wywołania funkcji.

```cpp
int wynik = dodaj(2, 3);
```

Wartości `2` i `3` są argumentami.

## Przykład kodu: przekazywanie przez wartość

Na tym etapie używamy przekazywania przez wartość. Oznacza to, że funkcja dostaje kopię przekazanej wartości.

```cpp
void zmien(int liczba)
{
    liczba = 100;
}

int main()
{
    int x = 5;
    zmien(x);
    std::cout << x << std::endl; // nadal 5
}
```

Zmiana parametru `liczba` wewnątrz funkcji nie zmienia zmiennej `x` w `main`.

Pełny przykład znajduje się w pliku [examples/pass_by_value.cpp](examples/pass_by_value.cpp).

### Zmienne lokalne

Zmienna zadeklarowana wewnątrz funkcji jest zmienną lokalną. Jest dostępna tylko w tej funkcji.

```cpp
int obliczKwadrat(int liczba)
{
    int wynik = liczba * liczba;
    return wynik;
}
```

Zmienna `wynik` istnieje tylko w funkcji `obliczKwadrat`.

### Zakres zmiennej

Zakres zmiennej określa, w której części programu można użyć tej zmiennej.

```cpp
int main()
{
    int x = 10;

    if (x > 0)
    {
        int y = 5;
        std::cout << y << std::endl;
    }

    // tutaj y nie jest dostępne
    return 0;
}
```

Zmienna `y` istnieje tylko wewnątrz bloku `if`.

### Nazwy parametrów w deklaracji

W deklaracji funkcji nazwy parametrów można podać, ale nie trzeba.

```cpp
double poleProstokata(double szerokosc, double wysokosc);
```

To samo można zapisać tak:

```cpp
double poleProstokata(double, double);
```

Typy i kolejność parametrów są ważne. Nazwy w deklaracji służą głównie czytelności.

W definicji funkcji nazwy parametrów są potrzebne, ponieważ używamy ich w kodzie.

```cpp
double poleProstokata(double szerokosc, double wysokosc)
{
    return szerokosc * wysokosc;
}
```

## Przykład kodu: pole prostokąta

```cpp
#include <iostream>

double poleProstokata(double szerokosc, double wysokosc)
{
    return szerokosc * wysokosc;
}

int main()
{
    std::cout << poleProstokata(4.0, 2.5) << std::endl;
    return 0;
}
```

Pełny przykład znajduje się w pliku [examples/function_rectangle_area.cpp](examples/function_rectangle_area.cpp).

## Przykład kodu: BMI

```cpp
double obliczBmi(double masa, double wzrost)
{
    return masa / (wzrost * wzrost);
}
```

Taka funkcja ukrywa wzór w jednym miejscu. Program główny może skupić się na wczytywaniu danych i wypisywaniu wyniku.

Pełny przykład znajduje się w pliku [examples/function_bmi.cpp](examples/function_bmi.cpp).

## Zadania do wykonania

1. Napisz funkcję `poleProstokata`, która przyjmuje dwa argumenty typu `double` i zwraca pole prostokąta.
2. Napisz funkcję `obwodProstokata`, która przyjmuje dwa argumenty typu `double` i zwraca obwód prostokąta.
3. Napisz funkcję `czyParzysta`, która przyjmuje liczbę całkowitą i zwraca `true` albo `false`.
4. Napisz funkcję `maksimum`, która przyjmuje dwie liczby całkowite i zwraca większą z nich.
5. Napisz funkcję `obliczBmi`, która przyjmuje masę i wzrost, a następnie zwraca wartość BMI.
6. Napisz program pokazujący, że zmiana parametru przekazanego przez wartość nie zmienia zmiennej w funkcji `main`.

## Ćwiczenia dodatkowe

1. Dodaj przykład funkcji z parametrem przekazywanym przez `const` referencję.
2. Zmień nazwę zmiennej lokalnej tak, aby nie myliła się z parametrem.
3. Dodaj funkcję, która zwraca wynik zamiast wypisywać go w środku funkcji.

## Kryteria zaliczenia

Program powinien:

- stosować parametry funkcji o odpowiednich typach,
- rozróżniać argumenty od parametrów,
- używać zmiennych lokalnych w ograniczonym zakresie,
- nie korzystać z niepotrzebnych zmiennych globalnych,
- kompilować się bez błędów.

## Pytania kontrolne

1. Czym różni się parametr od argumentu?
2. Co oznacza przekazywanie przez wartość?
3. Czy zmienna lokalna z jednej funkcji jest dostępna w innej funkcji?
4. Czy nazwy parametrów w deklaracji funkcji są obowiązkowe?
5. Dlaczego warto ograniczać zakres zmiennych?
