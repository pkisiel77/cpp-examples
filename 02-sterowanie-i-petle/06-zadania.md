# 06 - Zadania

## Cel zestawu zadań

Ten plik zbiera zadania do segmentu [02 - Sterowanie i pętle](README.md). Zadania sprawdzają instrukcje warunkowe, `switch`, operator `?:`, pętle oraz sterowanie wykonaniem pętli.

## Zasady wykonania

Każde zadanie powinno być zapisane w osobnym pliku `.cpp`. Program powinien kompilować się bez błędów i wypisywać wynik w czytelnej formie.

Przykład kompilacji:

```sh
c++ nazwa_pliku.cpp -o program
./program
```

## Poziom 1 - Instrukcje warunkowe

### Zadanie 1. Znak liczby

Napisz program, który wczytuje liczbę całkowitą i wypisuje, czy jest:

- dodatnia,
- ujemna,
- równa zero.

### Zadanie 2. Parzystość

Napisz program, który sprawdza, czy liczba podana przez użytkownika jest parzysta czy nieparzysta.

### Zadanie 3. Kolejność rosnąca

Napisz program, który wczytuje trzy liczby całkowite i sprawdza, czy są podane w kolejności rosnącej.

### Zadanie 4. Przedziały

Napisz program, który sprawdza, czy liczba należy do jednego z przedziałów:

- `<-10, 13>`,
- `<25, 35>`.

### Zadanie 5. Klasyfikacja BMI

Rozbuduj kalkulator BMI z segmentu `01-podstawy`. Program powinien obliczyć BMI i wypisać kategorię, np. niedowaga, wartość prawidłowa, nadwaga.

## Poziom 2 - `switch` i operator `?:`

### Zadanie 6. Dzień tygodnia

Napisz program, który dla numeru od `1` do `7` wypisuje nazwę dnia tygodnia. Użyj `switch`.

### Zadanie 7. Ocena opisowa

Napisz program, który dla oceny od `1` do `6` wypisuje opis, np. `niedostateczny`, `dobry`, `bardzo dobry`.

### Zadanie 8. Prosty kalkulator

Napisz program z menu:

- `1` - dodawanie,
- `2` - odejmowanie,
- `3` - mnożenie,
- `4` - dzielenie.

Użytkownik wybiera operację i podaje dwie liczby.

### Zadanie 9. Większa liczba

Napisz program, który wczytuje dwie liczby i przy pomocy operatora `?:` wybiera większą.

### Zadanie 10. Pełnoletniość

Napisz program, który wczytuje wiek i przy pomocy operatora `?:` wypisuje `pelnoletni` albo `niepelnoletni`.

## Poziom 3 - Pętla `for`

### Zadanie 11. Liczby od 1 do 110

Napisz program, który za pomocą pętli `for` wypisuje liczby całkowite od `1` do `110`.

### Zadanie 12. Liczby podzielne przez 3

Napisz program, który za pomocą pętli `for` wypisuje liczby podzielne przez `3` z przedziału od `1` do `100`.

### Zadanie 13. Suma liczb

Napisz program, który za pomocą pętli `for` sumuje liczby całkowite od `1` do `110`.

### Zadanie 14. Suma liczb parzystych

Napisz program, który za pomocą pętli `for` sumuje liczby parzyste od `1` do `110`.

### Zadanie 15. Silnia

Napisz program, który wczytuje liczbę `n` i oblicza `n!` przy pomocy pętli `for`.

## Poziom 4 - `while` i `do while`

### Zadanie 16. Odliczanie w dół

Napisz program, który za pomocą pętli `while` wypisuje liczby od `100` do `1`.

### Zadanie 17. Suma do zera

Napisz program, który wczytuje liczby od użytkownika aż do podania `0`, a następnie wypisuje ich sumę.

### Zadanie 18. Iloczyn liczb

Napisz program, który za pomocą pętli `do while` oblicza iloczyn liczb od `1` do `5`.

### Zadanie 19. Menu w pętli

Napisz program z menu działającym w pętli `do while`. Program kończy działanie po wybraniu opcji `0`.

### Zadanie 20. Potęgi dwójki

Napisz program, który za pomocą pętli `while` wypisuje kolejne potęgi liczby `2`, aż do osiągnięcia wartości `m` podanej przez użytkownika.

## Poziom 5 - `break`, `continue` i zagnieżdżenia

### Zadanie 21. Pierwsza liczba podzielna przez 17

Napisz program, który sprawdza liczby od `1` do `100` i kończy pętlę, gdy znajdzie pierwszą liczbę podzielną przez `17`.

### Zadanie 22. Pomijanie liczb

Napisz program, który wypisuje liczby od `1` do `50`, pomijając liczby podzielne przez `5`. Użyj `continue`.

### Zadanie 23. Tabliczka mnożenia

Napisz program, który za pomocą pętli zagnieżdżonych wypisuje tabliczkę mnożenia od `1` do `10`.

### Zadanie 24. Prostokąt z gwiazdek

Napisz program, który wczytuje szerokość i wysokość, a następnie wypisuje prostokąt z gwiazdek.

Przykład dla szerokości `5` i wysokości `3`:

```text
*****
*****
*****
```

### Zadanie 25. Trójkąt z gwiazdek

Napisz program, który wczytuje wysokość, a następnie wypisuje trójkąt z gwiazdek.

Przykład dla wysokości `4`:

```text
*
**
***
****
```

## Zadania dodatkowe

### Zadanie 26. Liczba pierwsza

Napisz program, który sprawdza, czy liczba podana przez użytkownika jest liczbą pierwszą.

### Zadanie 27. Minimum, maksimum i średnia

Napisz program, który wczytuje `n` liczb, a następnie wypisuje:

- najmniejszą liczbę,
- największą liczbę,
- średnią arytmetyczną.

### Zadanie 28. Liczby trójkątne

Napisz program, który wypisuje wszystkie liczby trójkątne z przedziału od `1` do `20`.

## Zadania przeniesione na później

Oryginalne materiały zawierały także zadania, które lepiej pasują do późniejszych segmentów:

- tablice,
- struktury,
- większe zadania algorytmiczne,
- zadania z losowaniem danych.

Ich pierwotne wersje są zachowane w katalogu [archive](archive).

## Kryteria zaliczenia segmentu

Student zalicza segment, jeśli potrafi samodzielnie:

- zapisać decyzję przy pomocy `if`, `else if`, `else`,
- użyć `switch` dla menu lub wyboru jednej z wielu stałych wartości,
- zastosować operator `?:` w prostym przypadku,
- napisać pętlę `for`, `while` i `do while`,
- uniknąć pętli nieskończonej,
- użyć `break` i `continue` w uzasadnionych sytuacjach,
- zastosować pętlę zagnieżdżoną do problemu dwuwymiarowego.

## Mini-sprawdzian segmentu

Napisz program z menu, który pozwala:

- wczytywać liczby do momentu wyboru opcji zakończenia,
- zliczać liczby dodatnie, ujemne i zera,
- pominąć liczby spoza zakresu od `-100` do `100`,
- wypisać podsumowanie po zakończeniu,
- skompilować program z `-Wall -Wextra -pedantic`.
