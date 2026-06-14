# 07 - Zadania

## Cel zestawu zadań

Ten plik zbiera zadania do segmentu [07 - STL i struktury danych](README.md).
Zadania sprawdzają użycie kontenerów, algorytmów STL, iteratorów, predykatów
oraz łączenie struktur danych z klasami.

## Zasady wykonania

Każde zadanie powinno być zapisane w osobnym pliku `.cpp`. Program powinien
kompilować się bez błędów i wypisywać wynik w czytelnej formie.

Przykład kompilacji:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic nazwa_pliku.cpp -o program
./program
```

Jeśli zadanie wymaga wyszukiwania lub sortowania, użyj odpowiedniego algorytmu
STL zamiast pisać własną pętlę realizującą ten sam algorytm.

## Wymagania jakościowe

W zadaniach z tego segmentu zwracaj uwagę na:

- kompilację z flagami `-std=c++17 -Wall -Wextra -pedantic`,
- dobór kontenera do sposobu użycia danych,
- pętle zakresowe i `const auto&` tam, gdzie poprawiają czytelność,
- algorytmy STL zamiast ręcznego sortowania lub wyszukiwania,
- sprawdzanie wyniku `find` przed użyciem znalezionego elementu.
- unikanie `operator[]` w `std::map`, jeśli samo wyszukiwanie nie powinno tworzyć wpisu.

## Poziom 1 - `std::vector`

### Zadanie 1. Liczby od 1 do 10

Utwórz `std::vector<int>` i wypełnij go liczbami od `1` do `10`. Wyświetl
wszystkie elementy za pomocą pętli zakresowej.

Wymagania:

- użyj `push_back` albo inicjalizacji listą,
- do wypisywania użyj pętli zakresowej,
- nie wypisuj elementów ręcznie po indeksach.

### Zadanie 2. Suma i średnia

Wczytaj od użytkownika pięć liczb rzeczywistych i zapisz je w wektorze.
Wyświetl ich sumę oraz średnią.

Scenariusz sprawdzenia:

```text
Dane:
2 4 6 8 10

Suma: 30
Srednia: 6
```

### Zadanie 3. Dodawanie i usuwanie

Utwórz wektor liczb od `1` do `10`. Usuń z niego liczbę `5`, a następnie dodaj
liczbę `0` na początku wektora.

Wymagania:

- usuń wartość `5` bez założenia, że znasz jej indeks,
- sprawdź, czy wartość została znaleziona przed usunięciem,
- po operacjach wypisz cały wektor.

### Zadanie 4. Lista słów

Utwórz wektor zawierający co najmniej pięć słów. Wyświetl:

- liczbę zapisanych słów,
- pierwsze słowo,
- ostatnie słowo,
- wszystkie słowa dłuższe niż pięć znaków.

Wymagania:

- przed odczytem pierwszego i ostatniego elementu upewnij się, że wektor nie jest pusty,
- do filtrowania dłuższych słów możesz użyć pętli zakresowej.

### Zadanie 5. Wektor obiektów

Utwórz klasę `Produkt` z polami `nazwa` i `cena`. Zapisz kilka produktów w
wektorze i wyświetl ich dane.

Wymagania:

- pola powinny być prywatne,
- dodaj konstruktor i gettery,
- cena nie może być ujemna.

## Poziom 2 - Algorytmy STL

### Zadanie 6. Sortowanie liczb

Posortuj wektor liczb całkowitych rosnąco, a następnie malejąco. Użyj
`std::sort`.

Wymagania:

- sortowanie rosnące wykonaj domyślnym `std::sort`,
- sortowanie malejące wykonaj z lambdą albo `std::greater<int>`,
- wypisz wynik po każdym sortowaniu.

### Zadanie 7. Wyszukiwanie wartości

Wyszukaj wskazaną przez użytkownika liczbę w wektorze za pomocą `std::find`.
Wyświetl informację, czy liczba została znaleziona.

Sprawdź przypadek, w którym liczba istnieje, oraz przypadek, w którym jej nie ma.

### Zadanie 8. Pierwsza liczba parzysta

Znajdź pierwszą liczbę parzystą w wektorze za pomocą `std::find_if` i wyrażenia
lambda.

Jeśli liczby parzystej nie ma, wypisz komunikat `Brak liczby parzystej`.

### Zadanie 9. Zliczanie ocen

W wektorze ocen zlicz wartości większe lub równe `3` za pomocą
`std::count_if`.

Scenariusz sprawdzenia:

```text
Oceny: 2 3 5 1 4
Zaliczone: 3
```

### Zadanie 10. Usuwanie wartości

Usuń z wektora wszystkie liczby ujemne. Użyj `std::remove_if` oraz metody
`erase`.

Wymagania:

- użyj idiomu erase-remove,
- po usunięciu wypisz pozostałe liczby,
- sprawdź przypadek, w którym wektor nie zawiera liczb ujemnych.

### Zadanie 11. Sortowanie produktów

Rozbuduj klasę `Produkt` z zadania 5. Posortuj produkty:

- rosnąco według ceny,
- alfabetycznie według nazwy.

Do każdego sortowania użyj osobnego wyrażenia lambda.

Wymagania:

- sortowanie po cenie ma zachować ceny rosnąco,
- sortowanie po nazwie ma zachować kolejność alfabetyczną,
- nie duplikuj kodu wypisującego produkty.

## Poziom 3 - `std::map`

### Zadanie 12. Numery telefonów

Utwórz mapę, w której kluczem jest imię, a wartością numer telefonu. Dodaj kilka
wpisów i wyświetl całą książkę telefoniczną.

Wymagania:

- użyj `std::map<std::string, std::string>`,
- pokaż, że klucze są wypisywane w kolejności uporządkowanej przez mapę.

### Zadanie 13. Bezpieczne wyszukiwanie

Rozbuduj książkę telefoniczną o wyszukiwanie osoby. Użyj metody `find`, aby
program nie tworzył nowego wpisu dla nieznanego imienia.

Sprawdź wyszukiwanie istniejącego i nieistniejącego imienia.

### Zadanie 14. Licznik słów

Wczytaj zdanie i policz wystąpienia każdego słowa. Wyniki zapisz w
`std::map<std::string, int>`.

Przykład:

```text
Dane:
ala ma kota ala

Wynik:
ala: 2
ma: 1
kota: 1
```

### Zadanie 15. Magazyn

Utwórz mapę przechowującą nazwę produktu i liczbę sztuk w magazynie. Program
powinien pozwalać:

- dodać nowy produkt,
- zwiększyć stan produktu,
- zmniejszyć stan produktu,
- odrzucić operację prowadzącą do ujemnego stanu.

Wymagania:

- wyszukuj produkty przez `find`,
- nie pozwól na ujemny stan magazynu,
- wypisz czytelny komunikat dla nieznanego produktu.

### Zadanie 16. Biblioteka filmów

Utwórz klasę `MovieLibrary`, która przechowuje oceny filmów w
`std::map<std::string, double>`.

Klasa powinna pozwalać:

- dodać i usunąć film,
- odczytać ocenę filmu,
- obliczyć średnią ocenę,
- znaleźć najlepiej oceniony film.

Wymagania:

- odczyt oceny nie powinien tworzyć nowego wpisu,
- średnia pustej biblioteki powinna być obsłużona czytelnym komunikatem,
- usunięcie nieznanego filmu powinno zwrócić informację o niepowodzeniu.

## Poziom 4 - Stos, kolejka i lista

### Zadanie 17. Odwracanie kolejności

Umieść kilka słów w `std::stack<std::string>`, a następnie zdejmuj je ze stosu
i wyświetlaj. Zaobserwuj kolejność elementów.

Wynik powinien pokazać zasadę LIFO: ostatni dodany element wychodzi pierwszy.

### Zadanie 18. Kolejka klientów

Utwórz kolejkę klientów oczekujących na obsługę. Program powinien pozwalać
dodać klienta oraz obsłużyć pierwszą osobę z kolejki.

Wymagania:

- jeśli kolejka jest pusta, obsługa klienta ma wypisać komunikat,
- pokaż zasadę FIFO: pierwszy dodany klient jest obsługiwany jako pierwszy.

### Zadanie 19. Nawiasy

Napisz funkcję, która za pomocą stosu sprawdza, czy w podanym napisie nawiasy
okrągłe są poprawnie zamknięte.

Przykłady:

```text
(a + b)       -> poprawne
((a + b) * c) -> poprawne
(a + b))      -> niepoprawne
```

Dodaj też test dla napisu `((a)` oraz dla pustego napisu.

### Zadanie 20. Lista uczestników

Utwórz `std::list<std::string>` z nazwiskami uczestników. Dodaj i usuń osoby z
początku oraz końca listy. Następnie posortuj listę alfabetycznie.

Wymagania:

- użyj metod `push_front`, `push_back`, `pop_front`, `pop_back`,
- przed usuwaniem sprawdź, czy lista nie jest pusta,
- do sortowania użyj metody `sort` listy.

### Zadanie 21. Dobór kontenera

Dla każdego przypadku wybierz właściwy kontener: `std::vector`, `std::map`,
`std::stack`, `std::queue` albo `std::list`. Zapisz krótkie uzasadnienie w
komentarzu.

- historia cofania operacji w edytorze,
- klienci oczekujący na połączenie z konsultantem,
- oceny przypisane do numeru indeksu studenta,
- lista wyników przeznaczona do częstego sortowania i odczytu,
- elementy często dodawane i usuwane w środku kolekcji.

Wymagania:

- dla każdego przypadku wskaż jeden kontener,
- uzasadnienie ma odnosić się do sposobu użycia danych, nie tylko do nazwy kontenera.

## Poziom 5 - Zadania projektowe

### Zadanie 22. Ranking graczy

Utwórz klasę `Player` z nazwą i liczbą punktów. Przechowuj graczy w wektorze.
Program powinien:

- odrzucać powtarzające się nazwy,
- pozwalać zmienić wynik gracza,
- wyświetlać ranking malejąco według punktów,
- znaleźć gracza o podanej nazwie.

Wymagania:

- do sprawdzania powtarzających się nazw użyj `std::find_if` albo dodatkowej mapy,
- ranking sortuj przez `std::sort`,
- aktualizacja nieznanego gracza powinna zwrócić komunikat o błędzie.

### Zadanie 23. System zamówień

Utwórz klasy `Order` i `OrderSystem`. System powinien przechowywać zamówienia,
umożliwiać wyszukiwanie po identyfikatorze oraz obsługiwać je w kolejności
dodania.

Dobierz kontenery do każdej odpowiedzialności i uzasadnij wybór w komentarzu.

Wymagania:

- wyszukiwanie po identyfikatorze powinno być szybkie i bezpieczne,
- obsługa zamówień ma zachować kolejność dodania,
- system nie powinien pozwolić dodać dwóch zamówień o tym samym identyfikatorze.

### Zadanie 24. Rozbudowa HRMS

Rozbuduj projekt z lekcji [06-projekt-hrms.md](06-projekt-hrms.md).

Dodaj:

- usuwanie pracownika ze wszystkich kontenerów,
- przenoszenie pracownika do innego działu,
- średnie wynagrodzenie w dziale,
- listę pracowników posortowaną alfabetycznie,
- informację o błędnej operacji bez przerywania programu.

## Wariant minimum

Do zaliczenia segmentu wykonaj co najmniej:

1. Zadanie 1 albo 2.
2. Zadanie 6 albo 7.
3. Zadanie 8 albo 10.
4. Zadanie 12 albo 13.
5. Zadanie 17 albo 18.
6. Zadanie 19 albo 21.
7. Mini-sprawdzian segmentu z końca pliku.

Zadania 22-24 są projektowe. Możesz je robić po wykonaniu wariantu minimum.

## Mini-sprawdzian segmentu

Napisz program `Biblioteka ocen filmów`, który:

- przechowuje filmy i oceny w `std::map<std::string, double>`,
- pozwala dodać film, zmienić ocenę i usunąć film,
- wyszukuje film bez tworzenia nowego wpisu,
- wypisuje filmy posortowane alfabetycznie po tytule,
- tworzy ranking filmów malejąco po ocenie z użyciem `std::vector` i `std::sort`,
- obsługuje pustą bibliotekę bez błędu.

Scenariusz sprawdzenia:

```text
Dodaj: Matrix 9.0
Dodaj: Alien 8.5
Zmien: Matrix 9.5
Szukaj: Matrix -> 9.5
Szukaj: Brak -> nie znaleziono
Ranking:
Matrix 9.5
Alien 8.5
```

## Kryteria zaliczenia segmentu

Student zalicza segment, jeśli potrafi samodzielnie:

- utworzyć i modyfikować `std::vector`,
- bezpiecznie przechodzić po elementach kontenera,
- użyć `std::sort`, `std::find`, `std::find_if` i `std::count_if`,
- zastosować idiom `erase-remove`,
- napisać prosty predykat jako wyrażenie lambda,
- użyć `std::map` i bezpiecznie wyszukać klucz metodą `find`,
- wyjaśnić różnicę między stosem a kolejką,
- dobrać kontener do prostego problemu,
- połączyć klasę z kilkoma kontenerami STL,
- zachować spójność danych przechowywanych w kilku kontenerach.

## Checklista oddania

Przed oddaniem rozwiązań sprawdź:

- [ ] Każde zadanie jest w osobnym pliku `.cpp`.
- [ ] Programy kompilują się z `-Wall -Wextra -pedantic`.
- [ ] Kontener jest dobrany do sposobu użycia danych.
- [ ] Sortowanie, wyszukiwanie i filtrowanie używa algorytmów STL tam, gdzie ma to sens.
- [ ] Wynik `find` albo `find_if` jest sprawdzony przed dereferencją.
- [ ] `std::map::find` jest używany tam, gdzie wyszukiwanie nie powinno tworzyć wpisu.
- [ ] Operacje na pustym kontenerze są obsłużone czytelnym komunikatem.

## Archiwum

Oryginalne materiały źródłowe tego segmentu są zachowane w katalogu [archive](archive).
