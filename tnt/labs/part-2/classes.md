## Zadanie

Utwórz klasę "Konto" z polami: 
- nazwa, 
- numer 
- i saldo.

Dodaj konstruktor domyślny oraz konstruktor z parametrami (konstruktor przeciążony), który ustawia pola klasy na podane wartości.

Dodaj destruktor, który wyświetla informację o usunięciu obiektu.

Utwórz kilka obiektów klasy "Konto" i przetestuj działanie konstruktorów i destruktora.

```cpp
#include <iostream>

class Konto {
    public:
        Konto();
        Konto(std::string n, int num, double s);
        ~Konto();

        std::string nazwa;
        int numer;
        double saldo;
};

Konto::Konto() {
    nazwa = "";
    numer = 0;
    saldo = 0.0;
}

Konto::Konto(std::string n, int num, double s) {
    nazwa = n;
    numer = num;
    saldo = s;
}

Konto::~Konto() {
    std::cout << "Usunięto obiekt klasy Konto o numerze " << numer << "\n";
}

int main() {
    Konto k1("Jan Kowalski", 123, 1000.0);
    Konto k2;
    k2.nazwa = "Anna Nowak";
    k2.numer = 456;
    k2.saldo = 2000.0;

    // ...
    return 0;
}
```

## Zadanie

Utwórz klasę "Konto" z polami: 
- nazwa, 
- numer 
- i saldo.

Dodaj konstruktor domyślny, konstruktor kopiujący oraz konstruktor z parametrami, który ustawia pola klasy na podane wartości.

Dodaj destruktor, który wyświetla informację o usunięciu obiektu.

Stwórz kilka obiektów klasy "Konto" i przetestuj działanie konstruktorów i destruktora.

```cpp
#include <iostream>

class Konto
{
public:
    Konto();
    Konto(const Konto &k);
    Konto(std::string n, int num, double s);
    ~Konto();

    std::string nazwa;
    int numer;
    double saldo;
};

Konto::Konto()
{
    nazwa = "";
    numer = 0;
    saldo = 0.0;
}

Konto::Konto(const Konto &k)
{
    nazwa = k.nazwa;
    numer = k.numer;
    saldo = k.saldo;
}

Konto::Konto(std::string n, int num, double s)
{
    nazwa = n;
    numer = num;
    saldo = s;
}

Konto::~Konto()
{
    std::cout << "Usunięto obiekt klasy Konto o numerze " << numer << "\n";
}

int main()
{
    Konto k1("Jan Kowalski", 123, 1000.0);
    Konto k2(k1);
    Konto k3 = k1;
    Konto k4;
    // ...
    return 0;
}

```
