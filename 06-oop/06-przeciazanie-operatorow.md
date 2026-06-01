# 06 - Przeciążanie operatorów

## Cel lekcji

Celem lekcji jest zrozumienie, czym jest przeciążanie operatorów i jak użyć go w prostych klasach, aby kod był czytelniejszy.

## Wymagania wstępne

Student powinien znać:

- klasy i obiekty z lekcji [01-klasy-i-obiekty.md](01-klasy-i-obiekty.md),
- enkapsulację z lekcji [02-konstruktory-i-enkapsulacja.md](02-konstruktory-i-enkapsulacja.md),
- metody `const` z lekcji [03-metody-const-i-this.md](03-metody-const-i-this.md),
- kopiowanie obiektów z lekcji [04-kopiowanie-obiektow.md](04-kopiowanie-obiektow.md).

## Czym jest przeciążanie operatorów

Przeciążanie operatorów pozwala zdefiniować, co oznacza operator dla obiektów własnej klasy.

Przykład:

```cpp
Punkt a(1, 2);
Punkt b(3, 4);
Punkt c = a + b;
```

Dla klasy `Punkt` możemy ustalić, że `+` oznacza dodanie współrzędnych.

```cpp
Punkt operator+(const Punkt& inny) const
{
    return Punkt(x + inny.x, y + inny.y);
}
```

Pełny przykład znajduje się w pliku [examples/point_operators.cpp](examples/point_operators.cpp).

## Operator jako metoda

Operator można zapisać jako metodę klasy.

```cpp
class Punkt
{
public:
    Punkt operator+(const Punkt& inny) const
    {
        return Punkt(x + inny.x, y + inny.y);
    }

private:
    int x;
    int y;
};
```

Słowo `operator+` oznacza przeciążenie operatora `+`.

Parametr `const Punkt& inny` oznacza drugi obiekt po prawej stronie operatora.

Metoda jest `const`, bo dodawanie nie powinno zmieniać istniejących punktów.

## Operator `==`

Operator `==` powinien zwracać `bool`.

```cpp
bool operator==(const Punkt& inny) const
{
    return x == inny.x && y == inny.y;
}
```

Dzięki temu można pisać:

```cpp
if (a == b)
{
    std::cout << "Punkty sa takie same" << std::endl;
}
```

## Operator `<<`

Operator `<<` pozwala wypisywać obiekt do strumienia.

```cpp
std::cout << punkt << std::endl;
```

Często zapisuje się go jako funkcję poza klasą.

```cpp
std::ostream& operator<<(std::ostream& out, const Punkt& punkt)
{
    out << "(" << punkt.pobierzX() << ", " << punkt.pobierzY() << ")";
    return out;
}
```

Funkcja zwraca `std::ostream&`, żeby można było łączyć wypisywanie.

```cpp
std::cout << punkt << std::endl;
```

## Operator jako funkcja zaprzyjaźniona

Jeśli operator zewnętrzny potrzebuje dostępu do prywatnych pól, można użyć `friend`.

```cpp
friend std::ostream& operator<<(std::ostream& out, const Punkt& punkt);
```

W tym kursie na początku preferujemy gettery, bo są prostsze do zrozumienia i nie otwierają prywatnych pól dla dodatkowej funkcji.

Pełny przykład operatora `<<` znajduje się w pliku [examples/money_output_operator.cpp](examples/money_output_operator.cpp).

## Kiedy przeciążanie operatorów ma sens

Przeciążanie operatorów ma sens, gdy operator jest naturalny dla danej klasy.

Dobre przykłady:

- `Punkt + Punkt`,
- `Kwota + Kwota`,
- `Macierz + Macierz`,
- `Macierz == Macierz`.

Podejrzane przykłady:

- `Student + Student`,
- `Plik * Plik`,
- `Samochod == Kierowca`.

Operator powinien zachowywać się intuicyjnie.

## Częste błędy

### Operator robi coś zaskakującego

Jeśli `+` usuwa dane albo zapisuje plik, kod będzie trudny do zrozumienia. Operator powinien robić coś zgodnego z oczekiwaniem.

### Brak `const`

Mniej precyzyjnie:

```cpp
Punkt operator+(Punkt& inny)
{
}
```

Lepiej:

```cpp
Punkt operator+(const Punkt& inny) const
{
}
```

Dodawanie nie powinno zmieniać ani lewego, ani prawego argumentu.

### Zwracanie referencji do obiektu lokalnego

Nie wolno zwracać referencji do zmiennej utworzonej wewnątrz operatora.

```cpp
// Niepoprawny pomysl
Punkt& operator+(const Punkt& inny)
{
    Punkt wynik(0, 0);
    return wynik;
}
```

Wynik dodawania zwracamy przez wartość.

## Zadania

1. Utwórz klasę `Punkt` z polami `x` i `y`. Dodaj operator `+`.
2. Dodaj operator `==` dla klasy `Punkt`.
3. Dodaj operator `<<`, który wypisuje punkt w formacie `(x, y)`.
4. Utwórz klasę `Kwota` z polami `zlote` i `grosze`. Dodaj operator `+`.
5. Rozbuduj klasę macierzy z wcześniejszych zadań o operator `+` i operator `==`.

## Kryteria zaliczenia

Program powinien:

- poprawnie przeciążać operator jako metodę klasy,
- używać `const` dla operatorów, które nie zmieniają obiektu,
- przekazywać drugi operand przez `const` referencję,
- zwracać wynik operatora przez wartość, jeśli powstaje nowy obiekt,
- implementować operator `<<` jako funkcję zwracającą `std::ostream&`,
- kompilować się bez błędów.

## Pytania kontrolne

1. Co oznacza `operator+`?
2. Dlaczego operator `==` zwraca `bool`?
3. Dlaczego operator `+` zwykle zwraca nowy obiekt?
4. Po co operator `<<` zwraca `std::ostream&`?
5. Kiedy przeciążanie operatora jest dobrym pomysłem?
