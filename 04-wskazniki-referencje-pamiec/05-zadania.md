# 05 - Zadania

## Cel zestawu zadań

Ten plik zbiera zadania do segmentu [04 - Wskaźniki, referencje, pamięć](README.md). Zadania sprawdzają rozumienie adresów, wskaźników, referencji, przekazywania argumentów do funkcji oraz podstawowych zasad bezpieczeństwa pamięci.

## Zasady wykonania

Każde zadanie powinno być zapisane w osobnym pliku `.cpp`. Program powinien
kompilować się bez błędów i wypisywać wynik w czytelnej formie.

Przykład kompilacji:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic nazwa_pliku.cpp -o program
./program
```

W zadaniach ze wskaźnikami pamiętaj o sprawdzaniu `nullptr`, jeśli funkcja dopuszcza brak wartości.

Przed oddaniem zadania sprawdź:

- czy każdy wskaźnik jest sprawdzony przed dereferencją, jeśli może być pusty,
- czy funkcje nie zwracają adresów zmiennych lokalnych,
- czy tablice są przekazywane razem z rozmiarem,
- czy indeksy tablic są sprawdzane przed użyciem,
- czy w komentarzach nie ma nieprawdziwych założeń o czasie życia zmiennych.

## Poziom 1 - Adresy i wskaźniki

### Zadanie 1. Adres zmiennej

Utwórz zmienną typu `int`, przypisz jej wartość i wypisz:

- wartość zmiennej,
- adres zmiennej,
- wartość odczytaną przez wskaźnik.

Wymagania:

- użyj operatora `&` do pobrania adresu,
- użyj operatora `*` do dereferencji,
- w komentarzu opisz różnicę między wartością zmiennej a jej adresem.

### Zadanie 2. Zmiana przez wskaźnik

Utwórz zmienną `liczba` i wskaźnik wskazujący na tę zmienną. Zmień wartość zmiennej przez wskaźnik i wypisz wynik przed oraz po zmianie.

Scenariusz sprawdzenia:

```text
Przed: 10
Po: 25
```

### Zadanie 3. `nullptr`

Napisz funkcję `wypiszWartosc`, która przyjmuje wskaźnik do `int`.

Funkcja powinna:

- wypisać wartość, jeśli wskaźnik nie jest pusty,
- wypisać komunikat `Brak wartosci`, jeśli wskaźnik ma wartość `nullptr`.

W `main` wywołaj funkcję dwa razy: raz z adresem poprawnej zmiennej i raz z
`nullptr`.

### Zadanie 4. Wskaźnik do elementu tablicy

Utwórz tablicę pięciu liczb całkowitych. Ustaw wskaźnik na pierwszy element tablicy i wypisz wszystkie elementy, używając wskaźnika oraz indeksu.

Wymagania:

- użyj zapisu `*(wskaznik + i)`,
- nie wychodź poza zakres pięciu elementów,
- wypisz indeks i wartość elementu.

### Zadanie 5. Największa wartość przez wskaźnik

Napisz funkcję `wskaznikNaWieksza`, która przyjmuje dwa wskaźniki do `int` i zwraca wskaźnik do większej wartości.

Załóż, że oba wskaźniki muszą wskazywać poprawne zmienne. W funkcji `main` pokaż użycie funkcji.

Rozszerzenie: obsłuż sytuację, w której jeden ze wskaźników jest `nullptr`.

## Poziom 2 - Referencje

### Zadanie 6. Zmiana przez referencję

Napisz funkcję `zwieksz`, która przyjmuje referencję do `int` i zwiększa wartość zmiennej o `1`.

W `main` pokaż wartość przed i po wywołaniu funkcji.

### Zadanie 7. Zamiana wartości

Napisz funkcję `zamien`, która przyjmuje dwie referencje do `int` i zamienia wartości zmiennych.

Nie używaj `std::swap`.

Scenariusz sprawdzenia:

```text
Przed: a = 7, b = 12
Po:    a = 12, b = 7
```

### Zadanie 8. Minimum i maksimum

Napisz funkcję `minimumMaksimum`, która przyjmuje tablicę, jej rozmiar oraz dwie referencje wyjściowe:

- `minimum`,
- `maksimum`.

Funkcja powinna zapisać w referencjach najmniejszą i największą wartość z tablicy.

Wymagania:

- jeśli rozmiar tablicy jest mniejszy lub równy `0`, wypisz komunikat o błędzie,
- nie próbuj odczytywać pierwszego elementu pustej tablicy,
- sprawdź tablicę z liczbami dodatnimi i ujemnymi.

### Zadanie 9. Poprawianie wyniku

Napisz funkcję `ograniczDoZakresu`, która przyjmuje referencję do liczby oraz dwie granice: `min` i `max`.

Jeśli liczba jest mniejsza niż `min`, funkcja powinna ustawić ją na `min`. Jeśli jest większa niż `max`, powinna ustawić ją na `max`.

Scenariusze sprawdzenia:

- `-5` przy zakresie `0..100` daje `0`,
- `120` przy zakresie `0..100` daje `100`,
- `60` przy zakresie `0..100` zostaje `60`.

### Zadanie 10. Referencja czy wskaźnik

Napisz dwie wersje funkcji zwiększającej liczbę o podaną wartość:

- wersję przyjmującą wskaźnik,
- wersję przyjmującą referencję.

W komentarzu w kodzie napisz, kiedy wybrałbyś wskaźnik, a kiedy referencję.

Wymagania:

- wersja wskaźnikowa ma obsługiwać `nullptr`,
- wersja referencyjna zakłada, że obiekt zawsze istnieje,
- w `main` pokaż oba wywołania.

## Poziom 3 - Przekazywanie argumentów do funkcji

### Zadanie 11. Przekazanie przez wartość

Napisz funkcję, która próbuje zmienić wartość argumentu przekazanego przez wartość. Pokaż w `main`, że oryginalna zmienna się nie zmieniła.

Wynik programu powinien jasno pokazać dwie wartości: wewnątrz funkcji i po
powrocie do `main`.

### Zadanie 12. Przekazanie przez wskaźnik

Napisz funkcję `ustawZero`, która przyjmuje wskaźnik do `int` i ustawia wartość zmiennej na `0`, jeśli wskaźnik nie jest pusty.

W `main` wywołaj funkcję dla poprawnego wskaźnika i dla `nullptr`.

### Zadanie 13. Przekazanie przez referencję

Napisz funkcję `podwoj`, która przyjmuje referencję do `int` i podwaja wartość zmiennej.

### Zadanie 14. Dwa wyniki z funkcji

Napisz funkcję `sumaIloczyn`, która przyjmuje dwie liczby i zwraca dwa wyniki:

- sumę,
- iloczyn.

Jeden wynik zwróć przez `return`, a drugi przez parametr wskaźnikowy albo referencję.

Przykład:

```text
Dane: 4 i 5
Suma: 9
Iloczyn: 20
```

### Zadanie 15. Warunkowa zamiana

Napisz funkcję przyjmującą wskaźniki do dwóch zmiennych typu `int`. Funkcja powinna zamienić wartości tylko wtedy, gdy druga wartość jest mniejsza od pierwszej.

Przykład:

```text
przed: a = 10, b = 3
po:    a = 3, b = 10
```

Wymagania:

- sprawdź oba wskaźniki przed użyciem,
- jeśli któryś wskaźnik jest pusty, nie zmieniaj danych,
- jeśli wartości są już w kolejności rosnącej, nie zamieniaj ich.

## Poziom 4 - Bezpieczeństwo pamięci

### Zadanie 16. Bezpieczne wypisywanie tablicy

Napisz funkcję `wypiszTablice`, która przyjmuje wskaźnik do pierwszego elementu tablicy oraz jej rozmiar.

Funkcja powinna:

- sprawdzić, czy wskaźnik nie jest pusty,
- sprawdzić, czy rozmiar jest większy od `0`,
- wypisać elementy tylko wtedy, gdy dane wejściowe są poprawne.

Scenariusze sprawdzenia:

- poprawna tablica i rozmiar `5` - wypisuje elementy,
- `nullptr` i rozmiar `5` - wypisuje komunikat o błędzie,
- poprawna tablica i rozmiar `0` - wypisuje komunikat o błędzie.

### Zadanie 17. Bezpieczna suma tablicy

Napisz funkcję `sumaTablicy`, która przyjmuje wskaźnik do tablicy oraz rozmiar.

Jeśli wskaźnik jest pusty albo rozmiar jest niepoprawny, funkcja powinna zwrócić `0`.

Scenariusz sprawdzenia:

```text
Tablica: 2 4 6
Suma: 12
nullptr: 0
rozmiar 0: 0
```

### Zadanie 18. Nie wychodź poza tablicę

Napisz program, który wczytuje indeks elementu tablicy pięcioelementowej.

Program powinien:

- sprawdzić, czy indeks jest w zakresie,
- wypisać element tylko dla poprawnego indeksu,
- wypisać komunikat o błędzie dla indeksu spoza zakresu.

Sprawdź indeksy `0`, `4`, `-1` i `5`.

### Zadanie 19. Brak wskaźnika do zmiennej lokalnej

Napisz przykład funkcji, która zwraca wynik przez wartość zamiast zwracać wskaźnik do zmiennej lokalnej.

W komentarzu wyjaśnij, dlaczego zwracanie adresu zmiennej lokalnej byłoby błędem.

Wymagania:

- nie pisz funkcji, która faktycznie zwraca błędny wskaźnik,
- opisz błąd w komentarzu,
- pokaż poprawną funkcję zwracającą wynik przez wartość.

### Zadanie 20. Wskaźnik opcjonalny

Napisz funkcję `ustawJesliPodano`, która przyjmuje wskaźnik do `int` oraz nową wartość.

Funkcja powinna zmienić zmienną tylko wtedy, gdy wskaźnik nie jest pusty.

W `main` pokaż wywołanie z adresem zmiennej i z `nullptr`.

## Zadania dodatkowe

### Zadanie 21. Statystyki tablicy

Napisz funkcję `statystyki`, która przyjmuje tablicę i jej rozmiar, a następnie zwraca przez parametry wyjściowe:

- minimum,
- maksimum,
- sumę,
- średnią.

Dobierz wskaźniki albo referencje tak, aby kod był czytelny i bezpieczny.

Wymagania:

- funkcja powinna zwracać informację, czy obliczenia się udały,
- dla pustej tablicy albo `nullptr` nie zapisuj nieprawdziwych wyników,
- średnią zwróć jako `double`.

### Zadanie 22. Sortowanie dwóch liczb

Napisz funkcję, która przyjmuje dwie referencje i ustawia wartości w kolejności rosnącej.

Przykład:

```text
przed: a = 8, b = 2
po:    a = 2, b = 8
```

### Zadanie 23. Proste menu z funkcjami

Napisz program z menu:

- `1` - pokaż wartość,
- `2` - zwiększ przez referencję,
- `3` - ustaw przez wskaźnik,
- `0` - zakończ.

Program powinien przechowywać jedną zmienną typu `int` i przekazywać ją do funkcji różnymi sposobami.

## Wariant minimum

Do zaliczenia segmentu wykonaj co najmniej:

1. Zadanie 1 albo 2.
2. Zadanie 3.
3. Zadanie 6 albo 7.
4. Zadanie 8 albo 9.
5. Zadanie 12 albo 14.
6. Zadanie 16 albo 17.
7. Mini-sprawdzian segmentu z końca pliku.

Zadania 21-23 są dodatkowe. Możesz je robić po wykonaniu wariantu minimum.

## Kryteria zaliczenia segmentu

Student zalicza segment, jeśli potrafi samodzielnie:

- wypisać adres zmiennej,
- utworzyć wskaźnik i odczytać wartość przez dereferencję,
- sprawdzić wskaźnik przed dereferencją,
- użyć `nullptr`,
- zmienić wartość zmiennej przez wskaźnik,
- zmienić wartość zmiennej przez referencję,
- dobrać wskaźnik albo referencję do prostego przypadku,
- przekazać wynik z funkcji przez parametr wyjściowy,
- nie wychodzić poza zakres tablicy,
- wyjaśnić, dlaczego nie wolno zwracać adresu zmiennej lokalnej.

## Mini-sprawdzian segmentu

Napisz program z trzema funkcjami, który:

- zamienia dwie wartości przez referencje,
- próbuje ustawić wartość przez wskaźnik po sprawdzeniu `nullptr`,
- zwraca dwa wyniki przez parametry wyjściowe,
- wypisuje adresy i wartości przed oraz po zmianie,
- kompiluje się z `-Wall -Wextra -pedantic`.

Wymagania szczegółowe:

- funkcja zamiany ma używać referencji,
- funkcja ustawiania przez wskaźnik ma obsługiwać `nullptr`,
- funkcja z dwoma wynikami ma zwracać jeden wynik przez referencję, a drugi przez wskaźnik albo drugą referencję,
- program ma pokazać przypadek poprawnego wskaźnika i `nullptr`.

Scenariusz sprawdzenia:

```text
Przed zamiana: a = 4, b = 9
Po zamianie:   a = 9, b = 4
Ustawiono przez wskaznik: 100
Brak wskaznika - bez zmiany
Suma: 13
Iloczyn: 36
```

## Checklista oddania

Przed oddaniem rozwiązań sprawdź:

- [ ] Każde zadanie jest w osobnym pliku `.cpp`.
- [ ] Programy kompilują się z `-Wall -Wextra -pedantic`.
- [ ] Wskaźniki są sprawdzane przed dereferencją, jeśli mogą być `nullptr`.
- [ ] Funkcje nie zwracają adresów zmiennych lokalnych.
- [ ] Tablice są przekazywane razem z rozmiarem.
- [ ] Program nie odczytuje tablicy poza zakresem.
- [ ] W kodzie jest jasne, kiedy użyto wskaźnika, a kiedy referencji.

## Archiwum

Oryginalne materiały źródłowe tego segmentu są zachowane w katalogu [archive](archive).
