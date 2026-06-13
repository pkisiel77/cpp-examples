# 02 - Konstruktory i enkapsulacja

## Cel lekcji

Celem lekcji jest zrozumienie, po co stosujemy konstruktory, pola `private` oraz metody dostępowe, czyli gettery i settery.

## Wymagania wstępne

Student powinien znać:

- klasy i obiekty z lekcji [01-klasy-i-obiekty.md](01-klasy-i-obiekty.md),
- funkcje z segmentu [03-funkcje-tablice-napisy](../03-funkcje-tablice-napisy/README.md),
- instrukcje warunkowe z segmentu [02-sterowanie-i-petle](../02-sterowanie-i-petle/README.md).

## Krótka teoria

### Problem z polami publicznymi

W pierwszej lekcji pola były publiczne:

```cpp
class Konto
{
public:
    double saldo;
};
```

Taki zapis pozwala zmienić pole z dowolnego miejsca programu.

```cpp
Konto konto;
konto.saldo = -1000;
```

Dla konta bankowego ujemne saldo może być niedozwolone. Klasa powinna chronić swoje dane przed niepoprawną zmianą.

### `private`

Słowo `private` oznacza, że pola są dostępne tylko wewnątrz klasy.

```cpp
class Konto
{
private:
    double saldo;
};
```

Teraz kod poza klasą nie może bezpośrednio zmienić pola `saldo`.

```cpp
Konto konto;
// konto.saldo = 100; // blad kompilacji
```

To jest początek enkapsulacji: dane obiektu są ukryte, a dostęp do nich odbywa się przez metody.

## Przykład kodu: konstruktor

Konstruktor to specjalna metoda wywoływana podczas tworzenia obiektu. Ma taką samą nazwę jak klasa i nie ma typu zwracanego.

```cpp
class Konto
{
public:
    Konto(double saldoPoczatkowe)
    {
        saldo = saldoPoczatkowe;
    }

private:
    double saldo;
};
```

Użycie:

```cpp
Konto konto(100);
```

Konstruktor pozwala utworzyć obiekt od razu w poprawnym stanie.

Pełny przykład znajduje się w pliku [examples/account_constructor.cpp](examples/account_constructor.cpp).

### Getter

Getter to metoda, która zwraca wartość pola.

```cpp
double pobierzSaldo()
{
    return saldo;
}
```

Getter pozwala odczytać wartość bez bezpośredniego dostępu do pola.

```cpp
std::cout << konto.pobierzSaldo() << std::endl;
```

### Setter

Setter to metoda, która zmienia wartość pola. Setter może sprawdzić, czy nowa wartość jest poprawna.

```cpp
void ustawSaldo(double noweSaldo)
{
    if (noweSaldo >= 0)
    {
        saldo = noweSaldo;
    }
}
```

Dzięki temu klasa może odrzucić niepoprawne dane.

## Przykład kodu: enkapsulacja

Enkapsulacja oznacza ukrywanie szczegółów działania klasy i udostępnianie tylko potrzebnych operacji.

Dobra klasa:

- ukrywa pola jako `private`,
- udostępnia metody, które mają sens dla użytkownika klasy,
- pilnuje poprawności swoich danych,
- nie pozwala ominąć reguł obiektu.

Przykład:

```cpp
class Samochod
{
public:
    Samochod(std::string marka, int rokProdukcji)
    {
        this->marka = marka;
        this->rokProdukcji = rokProdukcji;
        przebieg = 0;
    }

    void jedz(int kilometry)
    {
        if (kilometry > 0)
        {
            przebieg += kilometry;
        }
    }

private:
    std::string marka;
    int rokProdukcji;
    int przebieg;
};
```

Pełny przykład znajduje się w pliku [examples/car_encapsulation.cpp](examples/car_encapsulation.cpp).

### Konstruktor domyślny i konstruktor z parametrami

Konstruktor domyślny nie przyjmuje argumentów.

```cpp
Konto()
{
    saldo = 0;
}
```

Konstruktor z parametrami przyjmuje dane potrzebne do utworzenia obiektu.

```cpp
Konto(double saldoPoczatkowe)
{
    saldo = saldoPoczatkowe;
}
```

Klasa może mieć więcej niż jeden konstruktor, jeśli różnią się listą parametrów.

## Typowe błędy

### Publiczne pola bez kontroli

Niepoprawnie:

```cpp
class Samochod
{
public:
    int przebieg;
};
```

Taki kod pozwala ustawić `przebieg` na wartość ujemną.

Poprawniej:

```cpp
class Samochod
{
public:
    void jedz(int kilometry)
    {
        if (kilometry > 0)
        {
            przebieg += kilometry;
        }
    }

private:
    int przebieg = 0;
};
```

### Getter, który zmienia stan

Getter powinien tylko odczytywać dane. Zmiana stanu w getterze jest myląca.

### Setter bez walidacji

Jeśli setter tylko przypisuje wartość bez żadnych zasad, to często nie daje przewagi nad polem publicznym.

## Zadania do wykonania

1. Utwórz klasę `Konto` z prywatnym polem `saldo` i konstruktorem ustawiającym saldo początkowe.
2. Dodaj getter `pobierzSaldo`.
3. Dodaj metodę `wplac`, która zwiększa saldo tylko dla kwoty większej od `0`.
4. Dodaj metodę `wyplac`, która zmniejsza saldo tylko wtedy, gdy kwota jest większa od `0` i nie przekracza salda.
5. Utwórz klasę `Samochod` z prywatnymi polami `marka`, `model`, `rokProdukcji` i `przebieg`. Dodaj konstruktor oraz metodę `jedz`.

## Kryteria zaliczenia

Program powinien:

- używać pól `private`,
- tworzyć obiekty przez konstruktor,
- udostępniać dane przez gettery,
- zmieniać dane przez metody z walidacją,
- nie pozwalać ustawić niepoprawnego stanu obiektu,
- kompilować się bez błędów.

## Pytania kontrolne

1. Po co stosujemy `private`?
2. Czym jest konstruktor?
3. Czym getter różni się od settera?
4. Co oznacza enkapsulacja?
5. Dlaczego obiekt powinien pilnować poprawności własnych danych?
