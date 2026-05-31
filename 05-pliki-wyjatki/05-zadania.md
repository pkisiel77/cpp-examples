# 05 - Zadania

## Cel

Ten plik zbiera zadania do segmentu [05 - Pliki i wyjątki](README.md). Zadania sprawdzają zapis i odczyt plików tekstowych, walidację danych, obsługę błędów oraz podstawy wyjątków.

## Zasady wykonania

Każde zadanie powinno być zapisane w osobnym pliku `.cpp`. Program powinien kompilować się bez błędów i wypisywać wynik w czytelnej formie.

Przykład kompilacji:

```sh
c++ nazwa_pliku.cpp -o program
./program
```

Jeśli program tworzy pliki pomocnicze, używaj prostych nazw, np. `dane.txt`, `liczby.txt`, `raport.txt`.

## Poziom 1 - Zapis i odczyt pliku

### Zadanie 1. Pierwszy zapis

Napisz program, który tworzy plik `dane.txt` i zapisuje do niego trzy linie tekstu.

### Zadanie 2. Odczyt liniami

Napisz program, który odczytuje plik `dane.txt` linia po linii i wypisuje jego zawartość.

### Zadanie 3. Numerowanie linii

Rozbuduj program z zadania 2 tak, aby przed każdą linią wypisywał jej numer.

Przykład:

```text
1. Pierwsza linia
2. Druga linia
```

### Zadanie 4. Dopisywanie do pliku

Napisz program, który dopisuje nową linię na końcu pliku `dane.txt`, nie usuwając wcześniejszej zawartości.

### Zadanie 5. Liczba linii

Napisz program, który zlicza, ile linii znajduje się w pliku tekstowym.

## Poziom 2 - Walidacja danych

### Zadanie 6. Brak pliku

Napisz program, który próbuje otworzyć plik `liczby.txt`.

Jeśli plik nie istnieje, program powinien wypisać czytelny komunikat i zakończyć działanie.

### Zadanie 7. Suma liczb z pliku

Napisz program, który odczytuje liczby całkowite z pliku `liczby.txt` i wypisuje ich sumę.

### Zadanie 8. Błędne dane w pliku

Rozbuduj program z zadania 7 tak, aby wykrywał sytuację, w której plik zawiera tekst zamiast liczby.

Program powinien wypisać komunikat o błędnych danych.

### Zadanie 9. Odczyt i zakres

Napisz program, który odczytuje z pliku wiek użytkownika.

Program powinien sprawdzić:

- czy odczyt się udał,
- czy wiek jest w zakresie od `0` do `130`.

### Zadanie 10. Pomijanie błędnych linii

Napisz program, który czyta plik `linie.txt` linia po linii.

Program powinien wypisywać tylko te linie, które zawierają poprawną liczbę całkowitą. Dla błędnych linii powinien wypisać komunikat `Pominieto bledna linie`.

## Poziom 3 - Wyjątki

### Zadanie 11. Dzielenie przez zero

Napisz funkcję `podziel`, która przyjmuje dwie liczby typu `double`.

Jeśli drugi argument jest równy `0`, funkcja powinna rzucić `std::invalid_argument`.

### Zadanie 12. Obsługa wyjątku

Rozbuduj program z zadania 11 tak, aby funkcja `main` obsługiwała wyjątek i wypisywała czytelny komunikat.

### Zadanie 13. Sprawdzanie wieku

Napisz funkcję `sprawdzWiek`, która rzuca wyjątek, jeśli wiek jest mniejszy od `0` albo większy od `130`.

### Zadanie 14. Indeks poza zakresem

Utwórz `std::vector<int>` z kilkoma wartościami. Użyj metody `at()` i obsłuż wyjątek `std::out_of_range` dla indeksu spoza zakresu.

### Zadanie 15. Plik jako wyjątek

Napisz funkcję `otworzPlik`, która próbuje otworzyć plik do odczytu.

Jeśli pliku nie da się otworzyć, funkcja powinna rzucić `std::runtime_error`.

## Poziom 4 - Menu plikowe

### Zadanie 16. Proste menu

Napisz program z menu:

- `1` - dodaj wpis,
- `2` - wyświetl wpisy,
- `0` - zakończ.

Wpisy zapisuj w pliku `dane.txt`.

### Zadanie 17. Czyszczenie pliku

Rozbuduj program z zadania 16 o opcję:

- `3` - usuń wszystkie wpisy.

### Zadanie 18. Liczenie wpisów

Dodaj opcję:

- `4` - policz wpisy.

Program powinien wypisać liczbę linii zapisanych w pliku.

### Zadanie 19. Walidacja wyboru menu

Rozbuduj menu tak, aby program poprawnie reagował na wpisanie tekstu zamiast liczby.

Program nie powinien wpadać w pętlę nieskończoną.

### Zadanie 20. Pusty wpis

Rozbuduj dodawanie wpisu tak, aby pusty wpis nie był zapisywany do pliku.

## Zadania dodatkowe

### Zadanie 21. Lista zadań w pliku

Napisz program, który zapisuje listę zadań do pliku `todo.txt`.

Program powinien umożliwiać:

- dodanie zadania,
- wypisanie wszystkich zadań,
- oznaczenie zadania jako wykonane przez dopisanie `[x]`.

### Zadanie 22. Prosty dziennik

Napisz program, który dopisuje wpis do pliku `dziennik.txt`.

Każdy wpis powinien zawierać:

- numer wpisu,
- temat,
- treść.

### Zadanie 23. Raport z liczb

Napisz program, który odczytuje liczby z pliku `liczby.txt` i zapisuje do pliku `raport.txt`:

- liczbę poprawnych wartości,
- sumę,
- średnią,
- najmniejszą wartość,
- największą wartość.

Program powinien obsługiwać błędne linie.

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

## Archiwum

Oryginalne materiały źródłowe tego segmentu będą zachowane w katalogu [archive](archive) po zakończeniu porządkowania.
