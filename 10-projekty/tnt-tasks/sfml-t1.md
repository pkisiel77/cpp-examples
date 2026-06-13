# Ćwiczenie - Figury, dziedziczenie i polimorfizm

## Cel ćwiczenia

Celem ćwiczenia jest napisanie programu, który pokazuje działanie klasy
abstrakcyjnej, dziedziczenia i polimorfizmu na przykładzie figur
geometrycznych.

Ćwiczenie utrwala:

- klasy abstrakcyjne,
- metody wirtualne,
- dziedziczenie,
- enkapsulację,
- wskaźniki albo referencje do klasy bazowej,
- wywoływanie metod przez interfejs klasy bazowej.

Wizualizacja w SFML może być dodatkiem, ale nie jest wymagana w minimalnej
wersji ćwiczenia.

## Zakres funkcjonalny

Program powinien:

- zdefiniować abstrakcyjną klasę bazową `Figura`,
- zdefiniować klasy pochodne `Kwadrat` i `Kolo`,
- obliczać pole każdej figury,
- zwracać opis każdej figury,
- przechowywać różne figury przez wskaźniki albo referencje do klasy bazowej,
- iterować po kolekcji figur i wywoływać metody polimorficznie.

## Wymagania techniczne

Program powinien:

- być napisany w C++17,
- używać metod czysto wirtualnych,
- używać destruktora wirtualnego w klasie bazowej,
- ukrywać dane figur w sekcji `private`,
- oznaczać metody niezmieniające obiektu jako `const`,
- używać `override` w klasach pochodnych,
- używać `std::vector` do przechowywania figur,
- kompilować się z flagami `-Wall -Wextra -pedantic`.

## Proponowany model klas

Klasa bazowa:

```cpp
class Figura {
public:
    virtual ~Figura() = default;

    virtual double pole() const = 0;
    virtual std::string opis() const = 0;
};
```

Klasy pochodne:

```cpp
class Kwadrat : public Figura {
public:
    explicit Kwadrat(double bok);

    double pole() const override;
    std::string opis() const override;

private:
    double bok_;
};

class Kolo : public Figura {
public:
    explicit Kolo(double promien);

    double pole() const override;
    std::string opis() const override;

private:
    double promien_;
};
```

W funkcji `main` można użyć `std::unique_ptr<Figura>`, aby bezpiecznie
przechowywać obiekty różnych klas w jednej kolekcji:

```cpp
std::vector<std::unique_ptr<Figura>> figury;
```

## Minimalny wariant zaliczeniowy

Minimalna wersja ćwiczenia powinna zawierać:

1. Klasę abstrakcyjną `Figura`.
2. Metodę czysto wirtualną `pole`.
3. Metodę czysto wirtualną `opis`.
4. Wirtualny destruktor w klasie bazowej.
5. Klasę `Kwadrat` z prywatnym polem `bok`.
6. Klasę `Kolo` z prywatnym polem `promien`.
7. Implementację metod `pole` i `opis` w obu klasach pochodnych.
8. Kolekcję przechowującą co najmniej jeden kwadrat i jedno koło.
9. Pętlę, która wyświetla opis i pole każdej figury.
10. Krótką instrukcję kompilacji i uruchomienia.

## Rozszerzenia dla chętnych

Możliwe rozszerzenia:

- dodanie klasy `Prostokat`,
- dodanie klasy `Trojkat`,
- walidacja wymiarów figur,
- metoda `obwod`,
- sortowanie figur po polu,
- suma pól wszystkich figur,
- testy automatyczne metod `pole`,
- wizualizacja figur w SFML,
- zapis listy figur do pliku.

## Rozszerzenie SFML

Jeśli student chce użyć SFML, powinien potraktować to jako osobny etap po
działającej wersji konsolowej.

Wariant z SFML może zawierać:

- okno aplikacji,
- narysowanie kwadratu i koła,
- podpisy figur,
- skalowanie figur do rozmiaru okna,
- zamknięcie programu po naciśnięciu przycisku zamknięcia okna.

Kod OOP powinien pozostać oddzielony od kodu odpowiedzialnego za rysowanie.
Klasy `Figura`, `Kwadrat` i `Kolo` nie powinny zależeć bezpośrednio od SFML
w minimalnej wersji.

## Kryteria oceny

Ćwiczenie jest zaliczone, jeśli:

- program kompiluje się bez błędów i ostrzeżeń,
- klasa `Figura` jest abstrakcyjna,
- `pole` i `opis` są metodami wirtualnymi,
- klasy `Kwadrat` i `Kolo` dziedziczą po `Figura`,
- metody w klasach pochodnych używają `override`,
- dane figur są prywatne,
- program przechowuje figury przez wskaźnik albo referencję do klasy bazowej,
- wywołanie metod działa polimorficznie,
- wyniki pól są poprawne,
- kod jest czytelnie sformatowany.

## Scenariusze sprawdzenia

1. Utwórz kwadrat o boku `4` i sprawdź, czy pole wynosi `16`.
2. Utwórz koło o promieniu `2` i sprawdź, czy pole jest bliskie `12.566`.
3. Umieść kwadrat i koło w jednej kolekcji typu bazowego.
4. Przejdź pętlą po kolekcji i wyświetl wynik `opis()` oraz `pole()`.
5. Sprawdź, czy usunięcie obiektów przez wskaźnik do klasy bazowej jest
   bezpieczne dzięki wirtualnemu destruktorowi.

## Źródło pierwotne

Zadanie pochodziło ze starszego materiału o OOP i opcjonalnej wizualizacji
w SFML. Zostało uporządkowane do formatu ćwiczenia repozytorium.
