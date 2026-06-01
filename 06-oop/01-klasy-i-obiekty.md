# 01 - Klasy i obiekty

## Cel lekcji

Celem lekcji jest zrozumienie, czym jest klasa, czym jest obiekt oraz jak w C++ zapisać pola i metody klasy.

## Wymagania wstępne

Student powinien znać:

- zmienne i typy danych z segmentu [01-podstawy](../01-podstawy/README.md),
- funkcje z segmentu [03-funkcje-tablice-napisy](../03-funkcje-tablice-napisy/README.md),
- podstawy pracy z plikami `.cpp`.

## Klasa

Klasa to opis typu obiektu. Określa, jakie dane obiekt przechowuje i jakie operacje można na nim wykonać.

Przykład:

```cpp
class Punkt
{
public:
    int x;
    int y;
};
```

Klasa `Punkt` opisuje obiekty, które mają dwa pola: `x` i `y`.

## Obiekt

Obiekt to konkretna zmienna utworzona na podstawie klasy.

```cpp
Punkt p;
p.x = 10;
p.y = 20;
```

`Punkt` jest typem, a `p` jest obiektem tego typu.

Pełny przykład znajduje się w pliku [examples/simple_point.cpp](examples/simple_point.cpp).

## Pola

Pola to dane przechowywane w obiekcie.

```cpp
class Osoba
{
public:
    std::string imie;
    int wiek;
};
```

Każdy obiekt klasy `Osoba` ma własne pole `imie` i własne pole `wiek`.

```cpp
Osoba adam;
adam.imie = "Adam";
adam.wiek = 20;

Osoba ewa;
ewa.imie = "Ewa";
ewa.wiek = 21;
```

Zmiana pola w obiekcie `adam` nie zmienia pola w obiekcie `ewa`.

## Metody

Metoda to funkcja należąca do klasy. Metoda może korzystać z pól obiektu.

```cpp
class Prostokat
{
public:
    double szerokosc;
    double wysokosc;

    double pole()
    {
        return szerokosc * wysokosc;
    }
};
```

Wywołanie metody:

```cpp
Prostokat p;
p.szerokosc = 5;
p.wysokosc = 3;

std::cout << p.pole() << std::endl;
```

Pełny przykład znajduje się w pliku [examples/rectangle_methods.cpp](examples/rectangle_methods.cpp).

## `public`

Słowo `public` oznacza, że pola i metody są dostępne z zewnątrz klasy.

```cpp
class Punkt
{
public:
    int x;
    int y;
};
```

W pierwszej lekcji używamy `public`, żeby skupić się na samej idei klasy i obiektu. W kolejnej lekcji pojawi się `private`, czyli ukrywanie danych przed bezpośrednią zmianą z zewnątrz.

## Nazwy klas

Nazwy klas powinny być rzeczownikami albo krótkimi frazami rzeczownikowymi.

Dobre przykłady:

- `Punkt`,
- `Osoba`,
- `KontoBankowe`,
- `Rezerwacja`,
- `Produkt`.

W tym kursie nazwy klas zapisujemy stylem `PascalCase`, czyli każde słowo zaczyna się wielką literą.

```cpp
class KontoBankowe
{
public:
    double saldo;
};
```

## Częste błędy

### Brak średnika po klasie

Niepoprawnie:

```cpp
class Punkt
{
public:
    int x;
    int y;
}
```

Poprawnie:

```cpp
class Punkt
{
public:
    int x;
    int y;
};
```

Definicja klasy kończy się średnikiem.

### Mylenie klasy z obiektem

Niepoprawnie:

```cpp
Punkt.x = 10;
```

Poprawnie:

```cpp
Punkt p;
p.x = 10;
```

Najpierw trzeba utworzyć obiekt, potem można korzystać z jego pól.

### Zbyt techniczna nazwa klasy

Mniej czytelnie:

```cpp
class DaneTablica
{
};
```

Czytelniej:

```cpp
class ListaZakupow
{
};
```

Nazwa klasy powinna opisywać pojęcie z problemu, a nie szczegół implementacji.

## Zadania

1. Utwórz klasę `Punkt` z polami `x` i `y`. Utwórz dwa obiekty tej klasy i wypisz ich wartości.
2. Utwórz klasę `Osoba` z polami `imie` i `wiek`. Wypisz dane dwóch osób.
3. Utwórz klasę `Prostokat` z polami `szerokosc` i `wysokosc` oraz metodą `pole`.
4. Rozbuduj klasę `Prostokat` o metodę `obwod`.
5. Utwórz klasę `Produkt` z polami `nazwa`, `cena` i `ilosc`. Dodaj metodę `wartosc`, która zwraca `cena * ilosc`.

## Kryteria zaliczenia

Program powinien:

- poprawnie definiować klasę,
- kończyć definicję klasy średnikiem,
- tworzyć obiekty klasy,
- odczytywać i zmieniać pola obiektu,
- wywoływać metody obiektu,
- używać czytelnych nazw klas,
- kompilować się bez błędów.

## Pytania kontrolne

1. Czym różni się klasa od obiektu?
2. Czym są pola klasy?
3. Czym jest metoda?
4. Do czego służy `public`?
5. Dlaczego definicja klasy kończy się średnikiem?
