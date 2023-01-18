## Zadanie

Utwórz klasę "Konto" z polami: 
- nazwa, 
- numer 
- i saldo.

Dodaj konstruktor domyślny oraz konstruktor z parametrami, który ustawia pola klasy na podane wartości.

Dodaj destruktor, który wyświetla informację o usunięciu obiektu.

Utwórz kilka obiektów klasy "Konto" i przetestuj działanie konstruktorów i destruktora.

```cpp
class Konto {
    public:
        Konto();
        Konto(string n, int num, double s);
        ~Konto();

        string nazwa;
        int numer;
        double saldo;
};

Konto::Konto() {
    nazwa = "";
    numer = 0;
    saldo = 0.0;
}

Konto::Konto(string n, int num, double s) {
    nazwa = n;
    numer = num;
    saldo = s;
}

Konto::~Konto() {
    cout << "Usunięto obiekt klasy Konto o numerze " << numer << endl;
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
