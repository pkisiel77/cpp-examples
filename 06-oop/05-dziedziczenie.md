# 05 - Dziedziczenie

## Cel lekcji

Celem lekcji jest zrozumienie podstaw dziedziczenia: czym jest klasa bazowa, czym jest klasa pochodna i jak klasa pochodna może ponownie wykorzystać kod klasy bazowej.

## Wymagania wstępne

Student powinien znać:

- klasy i obiekty z lekcji [01-klasy-i-obiekty.md](01-klasy-i-obiekty.md),
- konstruktory i enkapsulację z lekcji [02-konstruktory-i-enkapsulacja.md](02-konstruktory-i-enkapsulacja.md),
- metody `const` z lekcji [03-metody-const-i-this.md](03-metody-const-i-this.md).

## Krótka teoria

### Klasa bazowa i klasa pochodna

Dziedziczenie pozwala opisać relację typu „jest rodzajem”.

Przykłady:

- `Menedzer` jest rodzajem `Pracownika`,
- `SportowySamochod` jest rodzajem `Samochodu`,
- `KontoOszczednosciowe` jest rodzajem `Konta`.

Klasa bazowa zawiera wspólne pola i metody.

```cpp
class Pracownik
{
public:
    Pracownik(std::string imie, int pensja)
    {
        this->imie = imie;
        this->pensja = pensja;
    }

private:
    std::string imie;
    int pensja;
};
```

Klasa pochodna rozszerza klasę bazową.

```cpp
class Menedzer : public Pracownik
{
public:
    Menedzer(std::string imie, int pensja, int liczbaOsob)
        : Pracownik(imie, pensja)
    {
        this->liczbaOsob = liczbaOsob;
    }

private:
    int liczbaOsob;
};
```

Pełny przykład znajduje się w pliku [examples/basic_inheritance.cpp](examples/basic_inheritance.cpp).

### Dziedziczenie `public`

Najczęściej na początku używamy dziedziczenia publicznego:

```cpp
class Menedzer : public Pracownik
{
};
```

Oznacza to, że publiczne metody klasy bazowej pozostają publiczne w klasie pochodnej.

Jeśli `Pracownik` ma publiczną metodę `opis()`, to obiekt klasy `Menedzer` też może jej użyć.

## Przykład kodu: konstruktor klasy bazowej

Klasa pochodna musi zbudować część bazową obiektu.

Robimy to na liście inicjalizacyjnej konstruktora:

```cpp
Menedzer(std::string imie, int pensja, int liczbaOsob)
    : Pracownik(imie, pensja)
{
    this->liczbaOsob = liczbaOsob;
}
```

Fragment:

```cpp
: Pracownik(imie, pensja)
```

wywołuje konstruktor klasy bazowej.

### `protected`

Pola `private` klasy bazowej nie są dostępne bezpośrednio w klasie pochodnej.

```cpp
class Pracownik
{
private:
    int pensja;
};
```

Klasa `Menedzer` nie może bezpośrednio użyć pola `pensja`, jeśli jest ono `private`.

Można użyć `protected`, aby pole było dostępne w klasie bazowej i pochodnych.

```cpp
class Pracownik
{
protected:
    int pensja;
};
```

Na początku warto jednak nadal preferować `private` i publiczne metody dostępowe. `protected` jest przydatne, ale łatwo przez nie osłabić enkapsulację.

## Przykład kodu: rozszerzanie zachowania

Klasa pochodna może dodać własne pola i metody.

```cpp
class SportowySamochod : public Samochod
{
public:
    void turbo()
    {
        maksymalnaPredkosc += 20;
    }

private:
    int maksymalnaPredkosc;
};
```

Pełny przykład znajduje się w pliku [examples/car_inheritance.cpp](examples/car_inheritance.cpp).

### Kiedy dziedziczenie ma sens

Dziedziczenie ma sens, gdy relacja naprawdę oznacza „jest rodzajem”.

Dobrze:

- `Menedzer` jest rodzajem `Pracownika`,
- `SportowySamochod` jest rodzajem `Samochodu`.

Podejrzane:

- `Samochod` dziedziczy po `Silnik`,
- `Zamowienie` dziedziczy po `Produkt`.

W takich przypadkach lepiej użyć pola w klasie.

```cpp
class Samochod
{
private:
    Silnik silnik;
};
```

To oznacza relację „ma”.

## Typowe błędy

### Dziedziczenie zamiast pola

Jeśli obiekt coś posiada, nie powinien po tym dziedziczyć.

Samochód ma silnik, ale nie jest silnikiem.

### Bezpośredni dostęp do zbyt wielu pól

Nadużywanie `protected` może sprawić, że klasy pochodne zbyt mocno zależą od szczegółów klasy bazowej.

### Brak wywołania konstruktora bazowego

Jeśli klasa bazowa nie ma konstruktora domyślnego, klasa pochodna musi jawnie wywołać konstruktor bazowy na liście inicjalizacyjnej.

## Zadania do wykonania

1. Utwórz klasę `Pracownik` z polami `imie` i `pensja` oraz metodą `opis`.
2. Utwórz klasę `Menedzer`, która dziedziczy publicznie po `Pracownik` i dodaje pole `liczbaOsob`.
3. Dodaj do klasy `Menedzer` metodę `opisZespolu`.
4. Utwórz klasę `Samochod` oraz klasę `SportowySamochod`, która po niej dziedziczy.
5. W klasie `SportowySamochod` dodaj metodę `turbo`, która zwiększa maksymalną prędkość tylko dla dodatniej wartości.

## Kryteria zaliczenia

Program powinien:

- poprawnie definiować klasę bazową,
- poprawnie definiować klasę pochodną,
- używać dziedziczenia `public`,
- wywoływać konstruktor klasy bazowej,
- odróżniać relację „jest” od relacji „ma”,
- kompilować się bez błędów.

## Pytania kontrolne

1. Czym jest klasa bazowa?
2. Czym jest klasa pochodna?
3. Co oznacza zapis `class Menedzer : public Pracownik`?
4. Po co klasa pochodna wywołuje konstruktor klasy bazowej?
5. Kiedy lepiej użyć pola zamiast dziedziczenia?
