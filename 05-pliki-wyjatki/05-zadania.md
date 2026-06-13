# 05 - Zadania

## Cel zestawu zadań

Ten plik zbiera zadania do segmentu [05 - Pliki i wyjątki](README.md). Zadania sprawdzają zapis i odczyt plików tekstowych, walidację danych, obsługę błędów oraz podstawy wyjątków.

## Zasady wykonania

Każde zadanie powinno być zapisane w osobnym pliku `.cpp`. Program powinien
kompilować się bez błędów i wypisywać wynik w czytelnej formie.

Przykład kompilacji:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic nazwa_pliku.cpp -o program
./program
```

Jeśli program tworzy pliki pomocnicze, używaj prostych nazw, np. `dane.txt`, `liczby.txt`, `raport.txt`.
Nie dodawaj plików wynikowych ani lokalnych danych testowych do commita, jeśli
prowadzący nie poprosił o to wprost.

Przed oddaniem zadania sprawdź:

- czy program reaguje czytelnie na brak pliku,
- czy błędne dane nie kończą programu awaryjnie,
- czy pliki są zamykane automatycznie przez obiekty strumieni,
- czy funkcje odczytu i walidacji są wydzielone z `main`,
- czy przykładowe pliki wejściowe są małe i opisane.

## Poziom 1 - Zapis i odczyt pliku

### Zadanie 1. Pierwszy zapis

Napisz program, który tworzy plik `dane.txt` i zapisuje do niego trzy linie tekstu.

Wymagania:

- sprawdź, czy plik udało się otworzyć do zapisu,
- wypisz komunikat po poprawnym zapisie,
- po uruchomieniu sprawdź zawartość pliku w edytorze albo przez `cat dane.txt`.

### Zadanie 2. Odczyt liniami

Napisz program, który odczytuje plik `dane.txt` linia po linii i wypisuje jego zawartość.

Scenariusz sprawdzenia:

```text
Zawartosc dane.txt:
Ala
ma
kota

Oczekiwany wynik:
Ala
ma
kota
```

### Zadanie 3. Numerowanie linii

Rozbuduj program z zadania 2 tak, aby przed każdą linią wypisywał jej numer.

Przykład:

```text
1. Pierwsza linia
2. Druga linia
```

Wymagania:

- numerowanie zacznij od `1`,
- pustą linię też licz jako linię.

### Zadanie 4. Dopisywanie do pliku

Napisz program, który dopisuje nową linię na końcu pliku `dane.txt`, nie usuwając wcześniejszej zawartości.

Wymagania:

- użyj trybu dopisywania,
- po dopisaniu odczytaj plik i pokaż całą zawartość.

### Zadanie 5. Liczba linii

Napisz program, który zlicza, ile linii znajduje się w pliku tekstowym.

Sprawdź program dla pliku pustego, pliku z jedną linią i pliku z kilkoma liniami.

## Poziom 2 - Walidacja danych

### Zadanie 6. Brak pliku

Napisz program, który próbuje otworzyć plik `liczby.txt`.

Jeśli plik nie istnieje, program powinien wypisać czytelny komunikat i zakończyć działanie.

Oczekiwany komunikat powinien zawierać nazwę pliku, którego nie udało się
otworzyć.

### Zadanie 7. Suma liczb z pliku

Napisz program, który odczytuje liczby całkowite z pliku `liczby.txt` i wypisuje ich sumę.

Przykładowy plik:

```text
2
4
-1
10
```

Oczekiwany wynik:

```text
Suma: 15
```

### Zadanie 8. Błędne dane w pliku

Rozbuduj program z zadania 7 tak, aby wykrywał sytuację, w której plik zawiera tekst zamiast liczby.

Program powinien wypisać komunikat o błędnych danych.

Przykładowy plik:

```text
10
abc
5
```

Program powinien zgłosić błąd dla `abc`. Może przerwać działanie albo pominąć
błędną linię, ale to zachowanie powinno być jasno opisane w komunikacie.

### Zadanie 9. Odczyt i zakres

Napisz program, który odczytuje z pliku wiek użytkownika.

Program powinien sprawdzić:

- czy odczyt się udał,
- czy wiek jest w zakresie od `0` do `130`.

Sprawdź dane: `20`, `-1`, `131`, `abc`.

### Zadanie 10. Pomijanie błędnych linii

Napisz program, który czyta plik `linie.txt` linia po linii.

Program powinien wypisywać tylko te linie, które zawierają poprawną liczbę całkowitą. Dla błędnych linii powinien wypisać komunikat `Pominieto bledna linie`.

Przykładowy plik:

```text
10
kot
-3
4.5
0
```

Oczekiwane poprawne wartości: `10`, `-3`, `0`.

## Poziom 3 - Wyjątki

### Zadanie 11. Dzielenie przez zero

Napisz funkcję `podziel`, która przyjmuje dwie liczby typu `double`.

Jeśli drugi argument jest równy `0`, funkcja powinna rzucić `std::invalid_argument`.

Wymagania:

- dołącz `<stdexcept>`,
- w treści wyjątku podaj informację o dzieleniu przez zero,
- dla poprawnych danych funkcja powinna zwracać wynik dzielenia.

### Zadanie 12. Obsługa wyjątku

Rozbuduj program z zadania 11 tak, aby funkcja `main` obsługiwała wyjątek i wypisywała czytelny komunikat.

Wymagania:

- łap wyjątek przez `const std::exception&`,
- po obsłudze wyjątku program powinien zakończyć się kontrolowanie.

### Zadanie 13. Sprawdzanie wieku

Napisz funkcję `sprawdzWiek`, która rzuca wyjątek, jeśli wiek jest mniejszy od `0` albo większy od `130`.

Scenariusze sprawdzenia:

- `0` - poprawny,
- `130` - poprawny,
- `-1` - wyjątek,
- `131` - wyjątek.

### Zadanie 14. Indeks poza zakresem

Utwórz `std::vector<int>` z kilkoma wartościami. Użyj metody `at()` i obsłuż wyjątek `std::out_of_range` dla indeksu spoza zakresu.

Sprawdź indeks poprawny oraz indeks równy rozmiarowi wektora.

### Zadanie 15. Plik jako wyjątek

Napisz funkcję `otworzPlik`, która próbuje otworzyć plik do odczytu.

Jeśli pliku nie da się otworzyć, funkcja powinna rzucić `std::runtime_error`.

W `main` obsłuż wyjątek i wypisz komunikat z `what()`.

## Poziom 4 - Menu plikowe

### Zadanie 16. Proste menu

Napisz program z menu:

- `1` - dodaj wpis,
- `2` - wyświetl wpisy,
- `0` - zakończ.

Wpisy zapisuj w pliku `dane.txt`.

Wymagania:

- menu ma działać w pętli,
- dodawanie wpisu ma dopisywać do pliku,
- wyświetlanie ma obsługiwać brak pliku albo pusty plik.

### Zadanie 17. Czyszczenie pliku

Rozbuduj program z zadania 16 o opcję:

- `3` - usuń wszystkie wpisy.

Czyszczenie powinno otworzyć plik w trybie zapisu, tak aby poprzednia zawartość
została zastąpiona pustą zawartością.

### Zadanie 18. Liczenie wpisów

Dodaj opcję:

- `4` - policz wpisy.

Program powinien wypisać liczbę linii zapisanych w pliku.

Sprawdź wynik po dodaniu dwóch wpisów i po wyczyszczeniu pliku.

### Zadanie 19. Walidacja wyboru menu

Rozbuduj menu tak, aby program poprawnie reagował na wpisanie tekstu zamiast liczby.

Program nie powinien wpadać w pętlę nieskończoną.

Wskazówka: po błędnym odczycie z `std::cin` trzeba wyczyścić stan strumienia i
usunąć błędne dane z bufora.

### Zadanie 20. Pusty wpis

Rozbuduj dodawanie wpisu tak, aby pusty wpis nie był zapisywany do pliku.

Program powinien wypisać komunikat, że pusty wpis został odrzucony.

## Zadania dodatkowe

### Zadanie 21. Lista zadań w pliku

Napisz program, który zapisuje listę zadań do pliku `todo.txt`.

Program powinien umożliwiać:

- dodanie zadania,
- wypisanie wszystkich zadań,
- oznaczenie zadania jako wykonane przez dopisanie `[x]`.

Wymagania:

- zadania numeruj od `1`,
- obsłuż próbę oznaczenia nieistniejącego zadania,
- po zmianie zapisz aktualną listę zadań do pliku.

### Zadanie 22. Prosty dziennik

Napisz program, który dopisuje wpis do pliku `dziennik.txt`.

Każdy wpis powinien zawierać:

- numer wpisu,
- temat,
- treść.

Wymagania:

- nowy wpis dopisuj na końcu pliku,
- numer wpisu wylicz na podstawie istniejącej liczby wpisów,
- oddziel wpisy pustą linią.

### Zadanie 23. Raport z liczb

Napisz program, który odczytuje liczby z pliku `liczby.txt` i zapisuje do pliku `raport.txt`:

- liczbę poprawnych wartości,
- sumę,
- średnią,
- najmniejszą wartość,
- największą wartość.

Program powinien obsługiwać błędne linie.

## Wariant minimum

Do zaliczenia segmentu wykonaj co najmniej:

1. Zadanie 1 albo 2.
2. Zadanie 4 albo 5.
3. Zadanie 6.
4. Zadanie 7 albo 10.
5. Zadanie 11 albo 12.
6. Zadanie 16 albo 18.
7. Mini-sprawdzian segmentu z końca pliku.

Zadania 21-23 są dodatkowe. Możesz je robić po wykonaniu wariantu minimum.

## Kryteria zaliczenia segmentu

Student zalicza segment, jeśli potrafi samodzielnie:

- zapisać dane do pliku tekstowego,
- odczytać plik linia po linii,
- dopisać dane na końcu pliku,
- sprawdzić, czy plik został otwarty,
- sprawdzić wynik operacji odczytu,
- odróżnić błąd typu danych od wartości spoza zakresu,
- użyć `try`, `throw` i `catch`,
- złapać wyjątek standardowy przez `const` referencję,
- podzielić program plikowy na funkcje,
- zbudować proste menu działające w pętli.

## Mini-sprawdzian segmentu

Napisz program tworzący raport z pliku tekstowego, który:

- odczytuje dane linia po linii,
- pomija błędne linie z komunikatem,
- liczy poprawne wartości i ich sumę,
- zapisuje wynik do osobnego pliku,
- obsługuje brak pliku przez wyjątek albo czytelny komunikat błędu.

Wymagania szczegółowe:

- plik wejściowy powinien mieć nazwę `liczby.txt`,
- plik wynikowy powinien mieć nazwę `raport.txt`,
- błędne linie powinny być policzone osobno,
- raport powinien zawierać liczbę poprawnych wartości, liczbę błędnych linii i sumę,
- brak pliku wejściowego nie może zakończyć programu awaryjnie.

Scenariusz sprawdzenia:

```text
Zawartosc liczby.txt:
10
abc
-2
5

Oczekiwany raport:
Poprawne wartosci: 3
Bledne linie: 1
Suma: 13
```

## Checklista oddania

Przed oddaniem rozwiązań sprawdź:

- [ ] Każde zadanie jest w osobnym pliku `.cpp`.
- [ ] Programy kompilują się z `-Wall -Wextra -pedantic`.
- [ ] Program sprawdza, czy plik udało się otworzyć.
- [ ] Brak pliku ma czytelny komunikat.
- [ ] Błędne dane wejściowe nie powodują awaryjnego zakończenia.
- [ ] Program nie zostawia w repozytorium lokalnych plików wynikowych.
- [ ] Wyjątki są łapane przez `const` referencję.

## Archiwum

Oryginalne materiały źródłowe tego segmentu są zachowane w katalogu [archive](archive).
