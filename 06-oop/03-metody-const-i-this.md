# 03 - Metody `const` i `this`

## Cel lekcji

Celem lekcji jest zrozumienie, kiedy metoda klasy powinna być oznaczona jako `const`, czym jest wskaźnik `this` oraz jak nazywać klasy, pola i metody w czytelny sposób.

## Wymagania wstępne

Student powinien znać:

- klasy i obiekty z lekcji [01-klasy-i-obiekty.md](01-klasy-i-obiekty.md),
- konstruktory i enkapsulację z lekcji [02-konstruktory-i-enkapsulacja.md](02-konstruktory-i-enkapsulacja.md).

## Metoda `const`

Metoda oznaczona jako `const` obiecuje, że nie zmieni stanu obiektu.

```cpp
class Konto
{
public:
    double pobierzSaldo() const
    {
        return saldo;
    }

private:
    double saldo = 0;
};
```

Słowo `const` zapisujemy po liście parametrów metody.

```cpp
double pobierzSaldo() const
```

Getter zwykle powinien być metodą `const`, ponieważ tylko odczytuje dane.

Pełny przykład znajduje się w pliku [examples/const_methods.cpp](examples/const_methods.cpp).

## Dlaczego `const` jest przydatne

Jeśli obiekt jest stały, można na nim wywołać tylko metody `const`.

```cpp
const Konto konto(100);
std::cout << konto.pobierzSaldo() << std::endl;
```

To chroni obiekt przed przypadkową zmianą.

Metoda `const` nie może zmienić pola obiektu.

```cpp
double pobierzSaldo() const
{
    // saldo = 0; // blad kompilacji
    return saldo;
}
```

## Metody odczytujące i modyfikujące

Warto rozdzielać metody na dwie grupy.

Metody odczytujące:

- zwracają stan obiektu,
- nie zmieniają pól,
- zwykle powinny być `const`.

Przykłady:

```cpp
double pobierzSaldo() const;
std::string pobierzNazwe() const;
int pobierzPrzebieg() const;
```

Metody modyfikujące:

- zmieniają stan obiektu,
- nie są oznaczane jako `const`.

Przykłady:

```cpp
void wplac(double kwota);
void jedz(int kilometry);
void ustawNazwe(std::string nowaNazwa);
```

## Wskaźnik `this`

Każda metoda obiektu ma dostęp do specjalnego wskaźnika `this`.

`this` wskazuje na obiekt, na którym została wywołana metoda.

```cpp
class Produkt
{
public:
    Produkt(std::string nazwa)
    {
        this->nazwa = nazwa;
    }

private:
    std::string nazwa;
};
```

W przykładzie parametr konstruktora i pole klasy mają tę samą nazwę. Zapis `this->nazwa` oznacza pole obiektu.

Pełny przykład znajduje się w pliku [examples/this_pointer.cpp](examples/this_pointer.cpp).

## Kiedy używać `this`

`this` jest przydatne, gdy:

- parametr ma taką samą nazwę jak pole,
- chcemy jasno pokazać, że chodzi o pole obiektu,
- metoda zwraca bieżący obiekt albo wskaźnik do niego.

Na tym etapie najczęstsze użycie to rozróżnienie pola i parametru.

```cpp
void ustawNazwe(std::string nazwa)
{
    this->nazwa = nazwa;
}
```

Można też unikać konfliktu nazw przez inne nazwy parametrów:

```cpp
void ustawNazwe(std::string nowaNazwa)
{
    nazwa = nowaNazwa;
}
```

Oba style są poprawne. Najważniejsza jest spójność.

## Dobre nazwy w klasach

Nazwy klas powinny być rzeczownikami.

Dobrze:

- `Samochod`,
- `KontoBankowe`,
- `Produkt`,
- `Rezerwacja`.

Nazwy metod powinny mówić, co metoda robi.

Dobrze:

- `pobierzSaldo`,
- `ustawNazwe`,
- `wplac`,
- `wyplac`,
- `wypiszInformacje`.

Mniej czytelnie:

- `doIt`,
- `data`,
- `manager`,
- `process`.

## Konwencja w tym kursie

W materiałach stosujemy:

- klasy: `PascalCase`, np. `KontoBankowe`,
- zmienne i metody: `camelCase` albo polskie nazwy bez znaków diakrytycznych, np. `pobierzSaldo`,
- stałe: wielkie litery tylko wtedy, gdy są naprawdę stałymi globalnymi,
- nazwy opisujące pojęcie z zadania, a nie szczegół techniczny.

W istniejących przykładach mogą pojawiać się starsze style. Nowe materiały powinny być spójne i czytelne.

## Częste błędy

### Brak `const` przy getterze

Mniej precyzyjnie:

```cpp
double pobierzSaldo()
{
    return saldo;
}
```

Lepiej:

```cpp
double pobierzSaldo() const
{
    return saldo;
}
```

### Próba zmiany pola w metodzie `const`

Niepoprawnie:

```cpp
double pobierzSaldo() const
{
    saldo = 0;
    return saldo;
}
```

Metoda `const` nie może zmieniać zwykłych pól obiektu.

### Niejasne nazwy

Niepoprawnie:

```cpp
class Data
{
};
```

`Data` może oznaczać datę albo dane. Lepiej użyć nazwy bardziej jednoznacznej, np. `DaneKlienta` albo `DataUrodzenia`.

## Zadania

1. Dodaj `const` do getterów w klasie `Konto`.
2. Utwórz klasę `Produkt` z polami `nazwa`, `cena` i `ilosc`. Gettery powinny być metodami `const`.
3. Dodaj metodę `wartosc() const`, która zwraca `cena * ilosc`.
4. Napisz konstruktor klasy `Produkt`, w którym użyjesz `this`, aby odróżnić pola od parametrów.
5. Przejrzyj własny kod z poprzednich zadań i popraw nazwy klas oraz metod tak, aby były bardziej opisowe.

## Kryteria zaliczenia

Program powinien:

- oznaczać metody odczytujące jako `const`,
- nie zmieniać pól w metodach `const`,
- poprawnie używać `this` do odróżniania pól od parametrów,
- stosować czytelne nazwy klas i metod,
- kompilować się bez błędów.

## Pytania kontrolne

1. Co oznacza `const` po liście parametrów metody?
2. Dlaczego getter zwykle powinien być metodą `const`?
3. Czym jest `this`?
4. Kiedy `this->nazwa` jest bardziej czytelne niż samo `nazwa`?
5. Jakie nazwy są dobre dla klas, a jakie dla metod?
