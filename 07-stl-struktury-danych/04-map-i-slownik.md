# 04 - `std::map` i słownik

## Cel lekcji

Celem lekcji jest nauczenie się pracy z `std::map`, czyli kontenerem przechowującym pary klucz-wartość.

## Wymagania wstępne

Student powinien znać:

- podstawy STL z lekcji [01-wprowadzenie-do-stl.md](01-wprowadzenie-do-stl.md),
- `std::vector` z lekcji [02-vector.md](02-vector.md),
- klasy z segmentu [06-oop](../06-oop/README.md).

## Krótka teoria

### Czym jest `std::map`

`std::map` przechowuje dane jako pary:

```text
klucz -> wartość
```

Przykłady:

- tytuł filmu -> ocena,
- identyfikator pracownika -> pensja,
- nazwa produktu -> liczba sztuk,
- słowo -> liczba wystąpień.

Do użycia `std::map` potrzebny jest nagłówek:

```cpp
#include <map>
```

## Przykład kodu: tworzenie mapy

Mapa z kluczem typu `std::string` i wartością typu `double`:

```cpp
std::map<std::string, double> ocenyFilmow;
```

Dodawanie wartości:

```cpp
ocenyFilmow["Matrix"] = 5.0;
ocenyFilmow["Incepcja"] = 4.8;
```

Pełny przykład znajduje się w pliku [examples/map_basics.cpp](examples/map_basics.cpp).

### Klucz musi być unikalny

W `std::map` każdy klucz występuje tylko raz.

```cpp
ocenyFilmow["Matrix"] = 5.0;
ocenyFilmow["Matrix"] = 4.5;
```

Po drugim przypisaniu wartość dla klucza `"Matrix"` zostanie zmieniona na `4.5`.

### Odczyt przez `operator[]`

Można odczytać wartość tak:

```cpp
std::cout << ocenyFilmow["Matrix"] << std::endl;
```

Trzeba jednak uważać: jeśli klucza nie ma, `operator[]` utworzy nowy wpis z wartością domyślną.

```cpp
std::cout << ocenyFilmow["Nieznany film"] << std::endl;
```

Ten kod doda do mapy nowy film z oceną `0.0`.

## Przykład kodu: bezpieczne wyszukiwanie przez `find`

Do sprawdzania, czy klucz istnieje, używamy `find`.

```cpp
auto wynik = ocenyFilmow.find("Matrix");

if (wynik != ocenyFilmow.end())
{
    std::cout << wynik->second << std::endl;
}
```

`wynik->first` to klucz, a `wynik->second` to wartość.

### Przechodzenie po mapie

Po mapie można przechodzić pętlą zakresową.

```cpp
for (const auto& para : ocenyFilmow)
{
    std::cout << para.first << ": " << para.second << std::endl;
}
```

Elementy w `std::map` są uporządkowane według klucza.

### Usuwanie elementu

Element można usunąć metodą `erase`.

```cpp
ocenyFilmow.erase("Matrix");
```

Jeśli klucza nie ma, metoda nie usuwa niczego.

Przed usunięciem można sprawdzić, czy element istnieje.

```cpp
if (ocenyFilmow.find("Matrix") != ocenyFilmow.end())
{
    ocenyFilmow.erase("Matrix");
}
```

## Przykład kodu: biblioteka filmów

`std::map` dobrze pasuje do biblioteki filmów, w której tytuł jest kluczem, a ocena jest wartością.

```cpp
std::map<std::string, double> filmy;
```

Pełny przykład klasy `MovieLibrary` znajduje się w pliku [examples/movie_library.cpp](examples/movie_library.cpp).

Przykład pokazuje:

- dodawanie filmu,
- sprawdzanie duplikatu,
- usuwanie filmu,
- pobieranie oceny,
- obliczanie średniej,
- szukanie najwyżej ocenionego filmu.

## Typowe błędy

### Użycie `[]` do sprawdzania istnienia klucza

Niepoprawnie:

```cpp
if (ocenyFilmow["Matrix"] > 0)
{
}
```

Jeśli filmu nie ma, taki kod doda go do mapy.

Poprawnie:

```cpp
auto wynik = ocenyFilmow.find("Matrix");
if (wynik != ocenyFilmow.end())
{
}
```

### Brak sprawdzenia wyniku `find`

Niepoprawnie:

```cpp
auto wynik = ocenyFilmow.find("Matrix");
std::cout << wynik->second << std::endl;
```

Poprawnie:

```cpp
if (wynik != ocenyFilmow.end())
{
    std::cout << wynik->second << std::endl;
}
```

### Zły wybór klucza

Klucz powinien jednoznacznie identyfikować wpis. Jeśli tytuły filmów mogą się powtarzać, sam tytuł może nie wystarczyć.

## Zadania do wykonania

1. Utwórz `std::map<std::string, int>` przechowującą liczbę sztuk produktów w magazynie.
2. Dodaj kilka produktów i wypisz całą mapę.
3. Sprawdź przez `find`, czy produkt istnieje.
4. Usuń produkt z mapy.
5. Utwórz klasę `MovieLibrary` z mapą `std::map<std::string, double>` i metodami `addMovie`, `removeMovie`, `getRating`.

## Kryteria zaliczenia

Program powinien:

- dołączać nagłówek `<map>`,
- tworzyć mapę z odpowiednim typem klucza i wartości,
- dodawać i aktualizować wartości,
- sprawdzać istnienie klucza przez `find`,
- przechodzić po mapie pętlą zakresową,
- usuwać elementy przez `erase`,
- kompilować się bez błędów.

## Pytania kontrolne

1. Co przechowuje `std::map`?
2. Dlaczego klucz w mapie musi być unikalny?
3. Jaka jest różnica między `mapa["klucz"]` a `mapa.find("klucz")`?
4. Co oznaczają `first` i `second` w elemencie mapy?
5. Kiedy `std::map` jest lepszym wyborem niż `std::vector`?
