# 07 - Zadania

## Cel zestawu zadań

Ten plik zbiera zadania do segmentu [06 - Programowanie obiektowe](README.md). Zadania sprawdzają klasy, obiekty, konstruktory, enkapsulację, metody `const`, kopiowanie, dziedziczenie oraz przeciążanie operatorów.

## Zasady wykonania

Każde zadanie powinno być zapisane w osobnym pliku `.cpp`. Program powinien kompilować się bez błędów i wypisywać wynik w czytelnej formie.

Przykład kompilacji:

```sh
c++ nazwa_pliku.cpp -o program
./program
```

Klasy powinny mieć czytelne nazwy, a pola powinny być prywatne, jeśli zadanie nie mówi inaczej.

## Poziom 1 - Klasy i obiekty

### Zadanie 1. Punkt

Utwórz klasę `Punkt` z polami `x` i `y`. Utwórz dwa obiekty tej klasy i wypisz ich współrzędne.

### Zadanie 2. Prostokąt

Utwórz klasę `Prostokat` z polami `szerokosc` i `wysokosc`.

Dodaj metody:

- `pole`,
- `obwod`,
- `wypiszInformacje`.

### Zadanie 3. Osoba

Utwórz klasę `Osoba` z polami `imie` i `wiek`. Utwórz kilka obiektów i wypisz ich dane.

### Zadanie 4. Produkt

Utwórz klasę `Produkt` z polami:

- `nazwa`,
- `cena`,
- `ilosc`.

Dodaj metodę `wartosc`, która zwraca `cena * ilosc`.

### Zadanie 5. Konto

Utwórz klasę `Konto` z polami:

- `wlasciciel`,
- `numer`,
- `saldo`.

Dodaj metodę wypisującą dane konta.

## Poziom 2 - Konstruktory i enkapsulacja

### Zadanie 6. Konto z konstruktorem

Przepisz klasę `Konto` tak, aby pola były prywatne. Dodaj konstruktor ustawiający właściciela, numer i saldo początkowe.

### Zadanie 7. Wpłata i wypłata

Dodaj do klasy `Konto` metody:

- `wplac`,
- `wyplac`,
- `pobierzSaldo`.

Program powinien odrzucać wpłaty ujemne oraz wypłatę większą niż saldo.

### Zadanie 8. Samochód

Utwórz klasę `Samochod` z prywatnymi polami:

- `marka`,
- `model`,
- `rokProdukcji`,
- `przebieg`.

Dodaj konstruktor, gettery i metodę `jedz`, która zwiększa przebieg tylko dla dodatniej liczby kilometrów.

### Zadanie 9. Walidacja settera

Dodaj setter `ustawPrzebieg`, który nie pozwala ustawić przebiegu na wartość ujemną.

### Zadanie 10. Klasa `Uczen`

Utwórz klasę `Uczen` z prywatnymi polami `imie`, `nazwisko` i `ocena`.

Ocena powinna być w zakresie od `1` do `6`.

## Poziom 3 - `const`, `this` i kopiowanie

### Zadanie 11. Gettery `const`

W klasie `Produkt` dodaj gettery oznaczone jako `const`.

### Zadanie 12. Wartość produktu

Dodaj metodę `wartosc() const`, która nie zmienia obiektu.

### Zadanie 13. Konstruktor z `this`

Napisz konstruktor klasy `Produkt`, w którym parametry mają takie same nazwy jak pola. Użyj `this`, aby odróżnić pola od parametrów.

### Zadanie 14. Konstruktor kopiujący

Dodaj konstruktor kopiujący do klasy `Konto`. W konstruktorze wypisz komunikat `Kopiowanie konta`.

### Zadanie 15. Przekazywanie obiektu do funkcji

Napisz dwie funkcje wypisujące konto:

- pierwsza przyjmuje konto przez wartość,
- druga przyjmuje konto przez `const` referencję.

Zaobserwuj, kiedy powstaje kopia.

## Poziom 4 - Dziedziczenie

### Zadanie 16. Pracownik i menedżer

Utwórz klasę `Pracownik` z polami `imie` i `pensja`.

Utwórz klasę `Menedzer`, która dziedziczy po `Pracownik` i dodaje pole `liczbaOsob`.

### Zadanie 17. Samochód sportowy

Utwórz klasę `SportowySamochod`, która dziedziczy po `Samochod` i dodaje pole `maksymalnaPredkosc`.

Dodaj metodę `turbo`, która zwiększa maksymalną prędkość tylko dla dodatniej wartości.

### Zadanie 18. Konto oszczędnościowe

Utwórz klasę `KontoOszczednosciowe`, która dziedziczy po `Konto`.

Dodaj pole `oprocentowanie` oraz metodę `doliczOdsetki`.

### Zadanie 19. Relacja „jest” czy „ma”

Dla poniższych par zdecyduj, czy lepsze jest dziedziczenie, czy pole w klasie:

- samochód i silnik,
- menedżer i pracownik,
- zamówienie i produkt,
- sportowy samochód i samochód.

Zapisz krótkie uzasadnienie w komentarzu.

### Zadanie 20. Opis hierarchii

Napisz program z klasami `Pracownik`, `Menedzer` i `Inzynier`.

Każda klasa powinna mieć metodę wypisującą opis obiektu.

## Poziom 5 - Przeciążanie operatorów

### Zadanie 21. Punkt i operator `+`

Dodaj do klasy `Punkt` operator `+`, który dodaje współrzędne dwóch punktów.

### Zadanie 22. Punkt i operator `==`

Dodaj operator `==`, który zwraca `true`, jeśli dwa punkty mają takie same współrzędne.

### Zadanie 23. Punkt i operator `<<`

Dodaj operator `<<`, który wypisuje punkt w formacie:

```text
(x, y)
```

### Zadanie 24. Kwota

Utwórz klasę `Kwota` z polami `zlote` i `grosze`. Dodaj operator `+`, który poprawnie sumuje grosze.

### Zadanie 25. Macierz

Utwórz klasę `Macierz` reprezentującą macierz liczb `double`.

Dodaj:

- konstruktor z liczbą wierszy i kolumn,
- metody `set` i `get`,
- operator `+`,
- operator `==`,
- operator `<<`.

## Zadania dodatkowe

### Zadanie 26. Klasa do obsługi pliku

Utwórz klasę `PlikTekstowy`, która przechowuje nazwę pliku i ma metody:

- `zapisz`,
- `dopisz`,
- `odczytaj`.

Wykorzystaj wiedzę z segmentu [05-pliki-wyjatki](../05-pliki-wyjatki/README.md).

### Zadanie 27. Prosty katalog produktów

Utwórz klasy `Produkt` i `KatalogProduktow`.

Katalog powinien pozwalać:

- dodać produkt,
- wypisać produkty,
- policzyć łączną wartość magazynu.

### Zadanie 28. Mini-projekt: konto bankowe

Przygotuj program z klasami:

- `Konto`,
- `KontoOszczednosciowe`,
- `HistoriaOperacji`.

Program powinien pozwalać wykonać wpłatę, wypłatę i wypisać historię operacji.

## Kryteria zaliczenia segmentu

Student zalicza segment, jeśli potrafi samodzielnie:

- zdefiniować klasę i utworzyć obiekty,
- dobrać pola i metody do prostego problemu,
- ukryć pola jako `private`,
- napisać konstruktor,
- dodać gettery i metody modyfikujące z walidacją,
- oznaczyć metody odczytujące jako `const`,
- użyć `this` w konstruktorze lub setterze,
- rozpoznać moment kopiowania obiektu,
- przekazać obiekt przez `const` referencję,
- zbudować prostą hierarchię dziedziczenia,
- przeciążyć podstawowy operator w czytelny sposób.

## Archiwum

Oryginalne materiały źródłowe tego segmentu są zachowane w katalogu [archive](archive).
