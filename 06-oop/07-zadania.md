# 07 - Zadania

## Cel zestawu zadań

Ten plik zbiera zadania do segmentu [06 - Programowanie obiektowe](README.md). Zadania sprawdzają klasy, obiekty, konstruktory, enkapsulację, metody `const`, kopiowanie, dziedziczenie oraz przeciążanie operatorów.

## Zasady wykonania

Każde zadanie powinno być zapisane w osobnym pliku `.cpp`. Program powinien
kompilować się bez błędów i wypisywać wynik w czytelnej formie.

Przykład kompilacji:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic nazwa_pliku.cpp -o program
./program
```

Klasy powinny mieć czytelne nazwy, a pola powinny być prywatne, jeśli zadanie nie mówi inaczej.

## Wymagania jakościowe

W zadaniach z tego segmentu zwracaj uwagę na:

- kompilację z flagami `-std=c++17 -Wall -Wextra -pedantic`,
- prywatne pola i publiczne metody tylko tam, gdzie są potrzebne,
- metody `const` dla operacji, które nie zmieniają obiektu,
- konstruktory ustawiające obiekt od razu w poprawnym stanie,
- krótkie funkcje i czytelne nazwy klas, metod oraz pól.
- rozdzielenie logiki klasy od demonstracji w `main`.

## Poziom 1 - Klasy i obiekty

### Zadanie 1. Punkt

Utwórz klasę `Punkt` z polami `x` i `y`. Utwórz dwa obiekty tej klasy i wypisz ich współrzędne.

Wymagania:

- użyj nazwy klasy zapisanej wielką literą,
- przygotuj metodę `wypisz`,
- w `main` utwórz dwa punkty o różnych współrzędnych.

### Zadanie 2. Prostokąt

Utwórz klasę `Prostokat` z polami `szerokosc` i `wysokosc`.

Dodaj metody:

- `pole`,
- `obwod`,
- `wypiszInformacje`.

Scenariusz sprawdzenia:

```text
Szerokosc: 4
Wysokosc: 3
Pole: 12
Obwod: 14
```

### Zadanie 3. Osoba

Utwórz klasę `Osoba` z polami `imie` i `wiek`. Utwórz kilka obiektów i wypisz ich dane.

Wymagania:

- wiek nie powinien być ujemny,
- przygotuj metodę wypisującą dane osoby.

### Zadanie 4. Produkt

Utwórz klasę `Produkt` z polami:

- `nazwa`,
- `cena`,
- `ilosc`.

Dodaj metodę `wartosc`, która zwraca `cena * ilosc`.

Wymagania:

- `wartosc` powinna zwracać `double`,
- nie wypisuj wyniku bezpośrednio w metodzie `wartosc`.

### Zadanie 5. Konto

Utwórz klasę `Konto` z polami:

- `wlasciciel`,
- `numer`,
- `saldo`.

Dodaj metodę wypisującą dane konta.

Nie dodawaj jeszcze wpłat i wypłat. To pojawi się w kolejnych zadaniach.

## Poziom 2 - Konstruktory i enkapsulacja

### Zadanie 6. Konto z konstruktorem

Przepisz klasę `Konto` tak, aby pola były prywatne. Dodaj konstruktor ustawiający właściciela, numer i saldo początkowe.

Wymagania:

- saldo początkowe nie może być ujemne,
- jeśli konstruktor dostaje ujemne saldo, ustaw saldo na `0`,
- dodaj getter do salda.

### Zadanie 7. Wpłata i wypłata

Dodaj do klasy `Konto` metody:

- `wplac`,
- `wyplac`,
- `pobierzSaldo`.

Program powinien odrzucać wpłaty ujemne oraz wypłatę większą niż saldo.

Scenariusz sprawdzenia:

```text
Saldo poczatkowe: 100
Po wplacie 50: 150
Po wyplacie 30: 120
Wyplata 200 odrzucona
Wplata -10 odrzucona
Saldo koncowe: 120
```

### Zadanie 8. Samochód

Utwórz klasę `Samochod` z prywatnymi polami:

- `marka`,
- `model`,
- `rokProdukcji`,
- `przebieg`.

Dodaj konstruktor, gettery i metodę `jedz`, która zwiększa przebieg tylko dla dodatniej liczby kilometrów.

Wymagania:

- gettery oznacz jako `const`,
- `jedz(0)` i `jedz(-10)` nie powinny zmieniać przebiegu.

### Zadanie 9. Walidacja settera

Dodaj setter `ustawPrzebieg`, który nie pozwala ustawić przebiegu na wartość ujemną.

Setter powinien zwracać `true`, jeśli zmiana się udała, i `false`, jeśli została
odrzucona.

### Zadanie 10. Klasa `Uczen`

Utwórz klasę `Uczen` z prywatnymi polami `imie`, `nazwisko` i `ocena`.

Ocena powinna być w zakresie od `1` do `6`.

Wymagania:

- pole `ocena` ma być prywatne,
- konstruktor albo setter ma odrzucać ocenę spoza zakresu,
- dodaj metodę `czyZaliczyl`, która zwraca `true` dla ocen od `2` do `6`.

## Poziom 3 - `const`, `this` i kopiowanie

### Zadanie 11. Gettery `const`

W klasie `Produkt` dodaj gettery oznaczone jako `const`.

Sprawdź, czy możesz wywołać gettery na obiekcie zadeklarowanym jako `const Produkt`.

### Zadanie 12. Wartość produktu

Dodaj metodę `wartosc() const`, która nie zmienia obiektu.

Scenariusz sprawdzenia:

```text
Produkt: Zeszyt
Cena: 4.50
Ilosc: 3
Wartosc: 13.50
```

### Zadanie 13. Konstruktor z `this`

Napisz konstruktor klasy `Produkt`, w którym parametry mają takie same nazwy jak pola. Użyj `this`, aby odróżnić pola od parametrów.

### Zadanie 14. Konstruktor kopiujący

Dodaj konstruktor kopiujący do klasy `Konto`. W konstruktorze wypisz komunikat `Kopiowanie konta`.

W `main` utwórz kopię konta i pokaż, że oba obiekty mają te same dane, ale są
osobnymi obiektami.

### Zadanie 15. Przekazywanie obiektu do funkcji

Napisz dwie funkcje wypisujące konto:

- pierwsza przyjmuje konto przez wartość,
- druga przyjmuje konto przez `const` referencję.

Zaobserwuj, kiedy powstaje kopia.

Wymagania:

- wykorzystaj komunikat z konstruktora kopiującego,
- w komentarzu zapisz, która wersja funkcji jest lepsza do samego odczytu i dlaczego.

## Poziom 4 - Dziedziczenie

### Zadanie 16. Pracownik i menedżer

Utwórz klasę `Pracownik` z polami `imie` i `pensja`.

Utwórz klasę `Menedzer`, która dziedziczy po `Pracownik` i dodaje pole `liczbaOsob`.

Wymagania:

- pola klasy bazowej powinny być prywatne albo chronione zgodnie z wybranym projektem,
- dodaj metodę wypisującą dane pracownika i menedżera,
- pokaż utworzenie obu typów obiektów.

### Zadanie 17. Samochód sportowy

Utwórz klasę `SportowySamochod`, która dziedziczy po `Samochod` i dodaje pole `maksymalnaPredkosc`.

Dodaj metodę `turbo`, która zwiększa maksymalną prędkość tylko dla dodatniej wartości.

Scenariusz sprawdzenia:

```text
Predkosc poczatkowa: 220
Po turbo 30: 250
Po turbo -10: 250
```

### Zadanie 18. Konto oszczędnościowe

Utwórz klasę `KontoOszczednosciowe`, która dziedziczy po `Konto`.

Dodaj pole `oprocentowanie` oraz metodę `doliczOdsetki`.

Wymagania:

- oprocentowanie nie może być ujemne,
- odsetki powinny zwiększać saldo,
- wykorzystaj publiczne metody klasy bazowej zamiast bezpośredniego dostępu do pól prywatnych.

### Zadanie 19. Relacja „jest” czy „ma”

Dla poniższych par zdecyduj, czy lepsze jest dziedziczenie, czy pole w klasie:

- samochód i silnik,
- menedżer i pracownik,
- zamówienie i produkt,
- sportowy samochód i samochód.

Zapisz krótkie uzasadnienie w komentarzu.

Wymagania:

- dla każdej pary napisz jednozdaniowe uzasadnienie,
- nie implementuj pełnych klas, jeśli zadanie ma być tylko analizą.

### Zadanie 20. Opis hierarchii

Napisz program z klasami `Pracownik`, `Menedzer` i `Inzynier`.

Każda klasa powinna mieć metodę wypisującą opis obiektu.

Wymagania:

- pokaż wspólne elementy w klasie bazowej,
- pokaż różnice w klasach pochodnych,
- nie powielaj tych samych pól bez potrzeby.

Większe ćwiczenie z klasą abstrakcyjną i polimorfizmem znajduje się w pliku
[08-cwiczenie-figury-polimorfizm.md](08-cwiczenie-figury-polimorfizm.md).

## Poziom 5 - Przeciążanie operatorów

### Zadanie 21. Punkt i operator `+`

Dodaj do klasy `Punkt` operator `+`, który dodaje współrzędne dwóch punktów.

Scenariusz sprawdzenia:

```text
(2, 3) + (4, -1) = (6, 2)
```

### Zadanie 22. Punkt i operator `==`

Dodaj operator `==`, który zwraca `true`, jeśli dwa punkty mają takie same współrzędne.

W `main` sprawdź parę równych i parę różnych punktów.

### Zadanie 23. Punkt i operator `<<`

Dodaj operator `<<`, który wypisuje punkt w formacie:

```text
(x, y)
```

Operator powinien zwracać referencję do strumienia, aby można było łączyć
wypisywanie kilku wartości.

### Zadanie 24. Kwota

Utwórz klasę `Kwota` z polami `zlote` i `grosze`. Dodaj operator `+`, który poprawnie sumuje grosze.

Scenariusz sprawdzenia:

```text
12 zl 80 gr + 3 zl 50 gr = 16 zl 30 gr
```

Wymagania:

- po dodawaniu `grosze` powinny być w zakresie `0..99`,
- pola powinny być prywatne.

### Zadanie 25. Macierz

Utwórz klasę `Macierz` reprezentującą macierz liczb `double`.

Dodaj:

- konstruktor z liczbą wierszy i kolumn,
- metody `set` i `get`,
- operator `+`,
- operator `==`,
- operator `<<`.

Wymagania:

- sprawdzaj zgodność wymiarów przy dodawaniu,
- `get` i `set` powinny obsługiwać błędny indeks,
- dla pierwszej wersji możesz ograniczyć macierz do stałego rozmiaru `2 x 2`, jeśli pełna wersja jest zbyt trudna.

## Zadania dodatkowe

### Zadanie 26. Klasa do obsługi pliku

Utwórz klasę `PlikTekstowy`, która przechowuje nazwę pliku i ma metody:

- `zapisz`,
- `dopisz`,
- `odczytaj`.

Wykorzystaj wiedzę z segmentu [05-pliki-wyjatki](../05-pliki-wyjatki/README.md).

Wymagania:

- metody powinny zgłaszać błąd, jeśli operacja na pliku się nie uda,
- nazwa pliku powinna być ustawiana w konstruktorze.

### Zadanie 27. Prosty katalog produktów

Utwórz klasy `Produkt` i `KatalogProduktow`.

Katalog powinien pozwalać:

- dodać produkt,
- wypisać produkty,
- policzyć łączną wartość magazynu.

Wymagania:

- `KatalogProduktow` powinien przechowywać kolekcję produktów,
- nie pozwól dodać produktu z ujemną ceną albo ilością,
- metoda licząca wartość magazynu powinna być `const`.

### Zadanie 28. Mini-projekt: konto bankowe

Przygotuj program z klasami:

- `Konto`,
- `KontoOszczednosciowe`,
- `HistoriaOperacji`.

Program powinien pozwalać wykonać wpłatę, wypłatę i wypisać historię operacji.

## Wariant minimum

Do zaliczenia segmentu wykonaj co najmniej:

1. Zadanie 1 albo 2.
2. Zadanie 6 albo 7.
3. Zadanie 8 albo 10.
4. Zadanie 11 albo 12.
5. Zadanie 14 albo 15.
6. Zadanie 16 albo 18.
7. Zadanie 21 albo 22.

Zadania 25-28 są dodatkowe albo projektowe. Możesz je robić po wykonaniu
wariantu minimum.

## Mini-sprawdzian segmentu

Napisz program z klasą `Konto`, który:

- ma prywatne pola `wlasciciel`, `numer`, `saldo`,
- ustawia poprawny stan w konstruktorze,
- odrzuca ujemne saldo początkowe,
- pozwala wykonać wpłatę i wypłatę z walidacją,
- ma metodę `pobierzSaldo() const`,
- ma operator `==` porównujący numer konta,
- kompiluje się z `-Wall -Wextra -pedantic`.

Scenariusz sprawdzenia:

```text
Saldo poczatkowe: 100
Wplata 50: zaakceptowana
Wyplata 30: zaakceptowana
Wyplata 500: odrzucona
Saldo koncowe: 120
Konta o tym samym numerze: rowne
```

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

## Checklista oddania

Przed oddaniem rozwiązań sprawdź:

- [ ] Każde zadanie jest w osobnym pliku `.cpp`.
- [ ] Programy kompilują się z `-Wall -Wextra -pedantic`.
- [ ] Pola klas są prywatne, jeśli nie ma dobrego powodu, aby były publiczne.
- [ ] Konstruktory ustawiają obiekty w poprawnym stanie.
- [ ] Metody odczytujące są oznaczone jako `const`.
- [ ] Settery i metody modyfikujące walidują dane.
- [ ] `main` pokazuje użycie klasy, ale nie zawiera logiki należącej do klasy.
- [ ] Przeciążone operatory mają intuicyjne znaczenie.

## Archiwum

Oryginalne materiały źródłowe tego segmentu są zachowane w katalogu [archive](archive).
