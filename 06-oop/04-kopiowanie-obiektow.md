# 04 - Kopiowanie obiektów

## Cel lekcji

Celem lekcji jest zrozumienie, kiedy w C++ powstaje kopia obiektu, czym jest konstruktor kopiujący oraz dlaczego obiekty często przekazujemy do funkcji przez referencję.

## Wymagania wstępne

Student powinien znać:

- klasy, obiekty i metody z lekcji [01-klasy-i-obiekty.md](01-klasy-i-obiekty.md),
- konstruktory i enkapsulację z lekcji [02-konstruktory-i-enkapsulacja.md](02-konstruktory-i-enkapsulacja.md),
- referencje z segmentu [04-wskazniki-referencje-pamiec](../04-wskazniki-referencje-pamiec/README.md).

## Krótka teoria

### Kiedy powstaje kopia

Kopia obiektu może powstać między innymi wtedy, gdy:

- tworzymy nowy obiekt na podstawie istniejącego,
- przekazujemy obiekt do funkcji przez wartość,
- funkcja zwraca obiekt przez wartość.

Przykład:

```cpp
Konto konto1("Anna", 100);
Konto konto2 = konto1;
```

`konto2` jest osobnym obiektem. Ma takie same wartości pól jak `konto1`, ale jest niezależną kopią.

## Przykład kodu: konstruktor kopiujący

Konstruktor kopiujący tworzy nowy obiekt na podstawie istniejącego obiektu tej samej klasy.

```cpp
class Konto
{
public:
    Konto(const Konto& inne)
    {
        wlasciciel = inne.wlasciciel;
        saldo = inne.saldo;
    }

private:
    std::string wlasciciel;
    double saldo;
};
```

Parametr konstruktora kopiującego zwykle ma typ:

```cpp
const Konto& inne
```

Używamy referencji, żeby nie tworzyć kolejnej kopii. Używamy `const`, bo konstruktor kopiujący nie powinien zmieniać obiektu źródłowego.

Pełny przykład znajduje się w pliku [examples/copy_constructor.cpp](examples/copy_constructor.cpp).

### Domyślne kopiowanie

Jeśli klasa ma proste pola, C++ potrafi wygenerować konstruktor kopiujący automatycznie.

```cpp
class Punkt
{
public:
    int x;
    int y;
};
```

Dla takiej klasy kopiowanie działa bez pisania własnego konstruktora kopiującego.

```cpp
Punkt a;
a.x = 1;
a.y = 2;

Punkt b = a;
```

Własny konstruktor kopiujący piszemy wtedy, gdy chcemy mieć specjalne zachowanie podczas kopiowania albo gdy klasa zarządza zasobem.

Na tym etapie najważniejsze jest rozumienie, kiedy kopia powstaje.

## Przykład kodu: przekazywanie przez wartość

Gdy funkcja przyjmuje obiekt przez wartość, powstaje kopia.

```cpp
void wypisz(Konto konto)
{
    std::cout << konto.pobierzSaldo() << std::endl;
}
```

Dla małych klas to może nie mieć znaczenia. Dla większych obiektów kopiowanie może być kosztowne.

Pełny przykład znajduje się w pliku [examples/pass_object.cpp](examples/pass_object.cpp).

### Przekazywanie przez referencję `const`

Jeśli funkcja ma tylko odczytać obiekt, zwykle lepiej przekazać go przez referencję `const`.

```cpp
void wypisz(const Konto& konto)
{
    std::cout << konto.pobierzSaldo() << std::endl;
}
```

Taki zapis:

- nie tworzy kopii,
- nie pozwala funkcji zmienić obiektu,
- jest czytelny dla osoby czytającej kod.

### Przekazywanie przez referencję bez `const`

Jeśli funkcja ma zmienić obiekt, można przekazać go przez zwykłą referencję.

```cpp
void dopiszOdsetki(Konto& konto)
{
    konto.wplac(10);
}
```

Taki zapis oznacza, że funkcja może zmienić oryginalny obiekt.

### Zwracanie obiektów z funkcji

Funkcja może zwrócić obiekt przez wartość.

```cpp
Konto utworzKonto()
{
    Konto konto("Anna", 100);
    return konto;
}
```

W nowoczesnym C++ kompilator często optymalizuje takie przypadki. Na tym etapie warto jednak pamiętać, że zwracanie obiektu oznacza przekazanie gotowego wyniku do miejsca wywołania.

## Typowe błędy

### Niepotrzebne kopiowanie dużych obiektów

Mniej korzystnie:

```cpp
void wypisz(Raport raport)
{
}
```

Lepiej:

```cpp
void wypisz(const Raport& raport)
{
}
```

### Brak `const` przy referencji tylko do odczytu

Mniej precyzyjnie:

```cpp
void wypisz(Konto& konto)
{
}
```

Lepiej:

```cpp
void wypisz(const Konto& konto)
{
}
```

Jeśli funkcja nie zmienia obiektu, powinna to pokazać w typie parametru.

### Mylenie kopii z tym samym obiektem

```cpp
Konto a("Anna", 100);
Konto b = a;
```

`a` i `b` to dwa osobne obiekty. Zmiana `b` nie zmienia `a`.

## Zadania do wykonania

1. Utwórz klasę `Konto` z polami prywatnymi `wlasciciel` i `saldo`.
2. Dodaj konstruktor z parametrami oraz konstruktor kopiujący.
3. W konstruktorze kopiującym wypisz komunikat `Kopiowanie konta`.
4. Napisz funkcję, która przyjmuje `Konto` przez wartość i zaobserwuj, że powstaje kopia.
5. Napisz drugą funkcję, która przyjmuje `const Konto&` i porównaj działanie obu funkcji.

## Kryteria zaliczenia

Program powinien:

- poprawnie definiować konstruktor kopiujący,
- przekazywać obiekt źródłowy jako `const` referencję,
- pokazać sytuację, w której powstaje kopia,
- używać `const` referencji dla parametrów tylko do odczytu,
- odróżniać kopię obiektu od oryginału,
- kompilować się bez błędów.

## Pytania kontrolne

1. Kiedy powstaje kopia obiektu?
2. Jak wygląda typowy parametr konstruktora kopiującego?
3. Dlaczego konstruktor kopiujący przyjmuje `const Konto&`, a nie `Konto`?
4. Kiedy funkcja powinna przyjmować obiekt przez `const` referencję?
5. Czy zmiana kopii obiektu zmienia oryginał?
