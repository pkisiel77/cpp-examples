# 06 - Zadania

## Cel zestawu zadań

Ten plik zbiera zadania do segmentu [02 - Sterowanie i pętle](README.md). Zadania sprawdzają instrukcje warunkowe, `switch`, operator `?:`, pętle oraz sterowanie wykonaniem pętli.

## Zasady wykonania

Każde zadanie powinno być zapisane w osobnym pliku `.cpp`. Program powinien
kompilować się bez błędów i wypisywać wynik w czytelnej formie.

Przykład kompilacji:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic nazwa_pliku.cpp -o program
./program
```

Przed oddaniem zadania sprawdź:

- czy program kończy się dla wszystkich typowych danych wejściowych,
- czy warunki obejmują przypadki graniczne,
- czy pętle mają poprawny warunek zakończenia,
- czy wynik jest opisany, a nie wypisany jako sama liczba,
- czy program był uruchomiony dla danych poprawnych i błędnych.

## Poziom 1 - Instrukcje warunkowe

### Zadanie 1. Znak liczby

Napisz program, który wczytuje liczbę całkowitą i wypisuje, czy jest:

- dodatnia,
- ujemna,
- równa zero.

Scenariusze sprawdzenia:

```text
Dane: 12
Wynik: dodatnia

Dane: -3
Wynik: ujemna

Dane: 0
Wynik: zero
```

### Zadanie 2. Parzystość

Napisz program, który sprawdza, czy liczba podana przez użytkownika jest parzysta czy nieparzysta.

Wymagania:

- użyj operatora `%`,
- sprawdź program dla liczby dodatniej, ujemnej i zera.

### Zadanie 3. Kolejność rosnąca

Napisz program, który wczytuje trzy liczby całkowite i sprawdza, czy są podane w kolejności rosnącej.

Przykłady:

- `1 2 3` - kolejność rosnąca,
- `1 1 2` - nie jest ściśle rosnąca,
- `3 2 1` - nie jest rosnąca.

### Zadanie 4. Przedziały

Napisz program, który sprawdza, czy liczba należy do jednego z przedziałów:

- `<-10, 13>`,
- `<25, 35>`.

Sprawdź przypadki graniczne: `-10`, `13`, `14`, `25`, `35`, `36`.

### Zadanie 5. Klasyfikacja BMI

Rozbuduj kalkulator BMI z segmentu `01-podstawy`. Program powinien obliczyć BMI i wypisać kategorię, np. niedowaga, wartość prawidłowa, nadwaga.

Przyjmij proste progi:

- poniżej `18.5` - niedowaga,
- od `18.5` do poniżej `25.0` - wartość prawidłowa,
- od `25.0` do poniżej `30.0` - nadwaga,
- od `30.0` - otyłość.

## Poziom 2 - `switch` i operator `?:`

### Zadanie 6. Dzień tygodnia

Napisz program, który dla numeru od `1` do `7` wypisuje nazwę dnia tygodnia. Użyj `switch`.

Wymagania:

- dla wartości spoza zakresu wypisz komunikat `Nieznany dzien`,
- użyj gałęzi `default`.

### Zadanie 7. Ocena opisowa

Napisz program, który dla oceny od `1` do `6` wypisuje opis, np. `niedostateczny`, `dobry`, `bardzo dobry`.

### Zadanie 8. Prosty kalkulator

Napisz program z menu:

- `1` - dodawanie,
- `2` - odejmowanie,
- `3` - mnożenie,
- `4` - dzielenie.

Użytkownik wybiera operację i podaje dwie liczby.

Wymagania:

- użyj `switch`,
- obsłuż nieznaną opcję,
- przy dzieleniu sprawdź dzielenie przez zero.

Scenariusz sprawdzenia:

```text
Dane:
4
10
0

Oczekiwany wynik:
Nie mozna dzielic przez zero.
```

### Zadanie 9. Większa liczba

Napisz program, który wczytuje dwie liczby i przy pomocy operatora `?:` wybiera większą.

Jeśli liczby są równe, program może wypisać dowolną z nich jako większą albo
osobny komunikat o równości. Opisz to zachowanie w wyniku programu.

### Zadanie 10. Pełnoletniość

Napisz program, który wczytuje wiek i przy pomocy operatora `?:` wypisuje `pelnoletni` albo `niepelnoletni`.

## Poziom 3 - Pętla `for`

### Zadanie 11. Liczby od 1 do 110

Napisz program, który za pomocą pętli `for` wypisuje liczby całkowite od `1` do `110`.

Wymagania:

- każdą liczbę wypisz w osobnej linii albo oddziel spacją,
- nie wpisuj liczb ręcznie.

### Zadanie 12. Liczby podzielne przez 3

Napisz program, który za pomocą pętli `for` wypisuje liczby podzielne przez `3` z przedziału od `1` do `100`.

### Zadanie 13. Suma liczb

Napisz program, który za pomocą pętli `for` sumuje liczby całkowite od `1` do `110`.

Oczekiwany wynik:

```text
Suma: 6105
```

### Zadanie 14. Suma liczb parzystych

Napisz program, który za pomocą pętli `for` sumuje liczby parzyste od `1` do `110`.

### Zadanie 15. Silnia

Napisz program, który wczytuje liczbę `n` i oblicza `n!` przy pomocy pętli `for`.

Założenia:

- dla tego zadania przyjmij `0 <= n <= 12`,
- dla `0` wynik powinien wynosić `1`,
- jeśli użytkownik poda liczbę spoza zakresu, wypisz komunikat o błędzie.

## Poziom 4 - `while` i `do while`

### Zadanie 16. Odliczanie w dół

Napisz program, który za pomocą pętli `while` wypisuje liczby od `100` do `1`.

### Zadanie 17. Suma do zera

Napisz program, który wczytuje liczby od użytkownika aż do podania `0`, a następnie wypisuje ich sumę.

Scenariusz sprawdzenia:

```text
Dane:
5
-2
10
0

Oczekiwany wynik:
Suma: 13
```

### Zadanie 18. Iloczyn liczb

Napisz program, który za pomocą pętli `do while` oblicza iloczyn liczb od `1` do `5`.

### Zadanie 19. Menu w pętli

Napisz program z menu działającym w pętli `do while`. Program kończy działanie po wybraniu opcji `0`.

Minimalne menu:

```text
1. Wypisz powitanie
2. Wypisz aktualny licznik wyborow
0. Zakoncz
```

Program powinien obsłużyć nieznaną opcję bez zakończenia działania.

### Zadanie 20. Potęgi dwójki

Napisz program, który za pomocą pętli `while` wypisuje kolejne potęgi liczby `2`, aż do osiągnięcia wartości `m` podanej przez użytkownika.

Przykład dla `m = 20`:

```text
1
2
4
8
16
```

## Poziom 5 - `break`, `continue` i zagnieżdżenia

### Zadanie 21. Pierwsza liczba podzielna przez 17

Napisz program, który sprawdza liczby od `1` do `100` i kończy pętlę, gdy znajdzie pierwszą liczbę podzielną przez `17`.

Wymagania:

- użyj `break`,
- wypisz znalezioną liczbę,
- nie kontynuuj sprawdzania po znalezieniu wyniku.

### Zadanie 22. Pomijanie liczb

Napisz program, który wypisuje liczby od `1` do `50`, pomijając liczby podzielne przez `5`. Użyj `continue`.

Sprawdź, czy w wyniku nie pojawiają się liczby `5`, `10`, `15`, `20`, `25`,
`30`, `35`, `40`, `45`, `50`.

### Zadanie 23. Tabliczka mnożenia

Napisz program, który za pomocą pętli zagnieżdżonych wypisuje tabliczkę mnożenia od `1` do `10`.

Wymagania:

- użyj dwóch pętli,
- wyrównaj kolumny przez `std::setw`,
- pierwszy wiersz powinien zawierać wyniki mnożenia przez `1`.

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

Scenariusze sprawdzenia:

- `1` - nie jest liczbą pierwszą,
- `2` - jest liczbą pierwszą,
- `9` - nie jest liczbą pierwszą,
- `17` - jest liczbą pierwszą.

### Zadanie 27. Minimum, maksimum i średnia

Napisz program, który wczytuje `n` liczb, a następnie wypisuje:

- najmniejszą liczbę,
- największą liczbę,
- średnią arytmetyczną.

Wymagania:

- najpierw wczytaj `n`,
- jeśli `n <= 0`, wypisz komunikat o błędzie,
- nie używaj tablic.

Rozszerzony wariant tego zadania, z wczytywaniem do momentu wpisania komendy
kończącej, znajduje się w osobnym ćwiczeniu
[07-cwiczenie-min-max-srednia.md](07-cwiczenie-min-max-srednia.md).

### Zadanie 28. Liczby trójkątne

Napisz program, który wypisuje wszystkie liczby trójkątne z przedziału od `1` do `20`.

Liczby trójkątne obliczaj jako kolejne sumy:

```text
1
1 + 2 = 3
1 + 2 + 3 = 6
```

## Wariant minimum

Do zaliczenia segmentu wykonaj co najmniej:

1. Zadanie 1 albo 2.
2. Zadanie 4 albo 5.
3. Zadanie 6 albo 8.
4. Zadanie 13 albo 15.
5. Zadanie 17 albo 19.
6. Zadanie 21 albo 22.
7. Mini-sprawdzian segmentu z końca pliku.

Zadania 26-28 są dodatkowe. Możesz je robić po wykonaniu wariantu minimum.

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

Wymagania szczegółowe:

- użyj menu w pętli `do while`,
- użyj `continue` do pomijania liczb spoza zakresu,
- użyj warunków do klasyfikacji liczby,
- zakończ program dopiero po wybraniu opcji zakończenia.

Scenariusz sprawdzenia:

```text
Dane:
1
10
1
-5
1
0
1
150
0

Oczekiwane podsumowanie:
Dodatnie: 1
Ujemne: 1
Zera: 1
Pominiete: 1
```

## Checklista oddania

Przed oddaniem rozwiązań sprawdź:

- [ ] Każde zadanie jest w osobnym pliku `.cpp`.
- [ ] Programy kompilują się z `-Wall -Wextra -pedantic`.
- [ ] Każda pętla ma jasny warunek zakończenia.
- [ ] Programy obsługują wartości graniczne z treści zadania.
- [ ] Menu obsługuje nieznaną opcję.
- [ ] Dzielenie przez zero jest obsłużone tam, gdzie może wystąpić.
- [ ] Wyniki są opisane tekstem zrozumiałym dla użytkownika.
