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
c++ -std=c++17 nazwa_pliku.cpp -o program
./program
```

Jeśli zadanie wymaga wyszukiwania lub sortowania, użyj odpowiedniego algorytmu
STL zamiast pisać własną pętlę realizującą ten sam algorytm.

## Poziom 1 - `std::vector`

### Zadanie 1. Liczby od 1 do 10

Utwórz `std::vector<int>` i wypełnij go liczbami od `1` do `10`. Wyświetl
wszystkie elementy za pomocą pętli zakresowej.

### Zadanie 2. Suma i średnia

Wczytaj od użytkownika pięć liczb rzeczywistych i zapisz je w wektorze.
Wyświetl ich sumę oraz średnią.

### Zadanie 3. Dodawanie i usuwanie

Utwórz wektor liczb od `1` do `10`. Usuń z niego liczbę `5`, a następnie dodaj
liczbę `0` na początku wektora.

### Zadanie 4. Lista słów

Utwórz wektor zawierający co najmniej pięć słów. Wyświetl:

- liczbę zapisanych słów,
- pierwsze słowo,
- ostatnie słowo,
- wszystkie słowa dłuższe niż pięć znaków.

### Zadanie 5. Wektor obiektów

Utwórz klasę `Produkt` z polami `nazwa` i `cena`. Zapisz kilka produktów w
wektorze i wyświetl ich dane.

## Poziom 2 - Algorytmy STL

### Zadanie 6. Sortowanie liczb

Posortuj wektor liczb całkowitych rosnąco, a następnie malejąco. Użyj
`std::sort`.

### Zadanie 7. Wyszukiwanie wartości

Wyszukaj wskazaną przez użytkownika liczbę w wektorze za pomocą `std::find`.
Wyświetl informację, czy liczba została znaleziona.

### Zadanie 8. Pierwsza liczba parzysta

Znajdź pierwszą liczbę parzystą w wektorze za pomocą `std::find_if` i wyrażenia
lambda.

### Zadanie 9. Zliczanie ocen

W wektorze ocen zlicz wartości większe lub równe `3` za pomocą
`std::count_if`.

### Zadanie 10. Usuwanie wartości

Usuń z wektora wszystkie liczby ujemne. Użyj `std::remove_if` oraz metody
`erase`.

### Zadanie 11. Sortowanie produktów

Rozbuduj klasę `Produkt` z zadania 5. Posortuj produkty:

- rosnąco według ceny,
- alfabetycznie według nazwy.

Do każdego sortowania użyj osobnego wyrażenia lambda.

## Poziom 3 - `std::map`

### Zadanie 12. Numery telefonów

Utwórz mapę, w której kluczem jest imię, a wartością numer telefonu. Dodaj kilka
wpisów i wyświetl całą książkę telefoniczną.

### Zadanie 13. Bezpieczne wyszukiwanie

Rozbuduj książkę telefoniczną o wyszukiwanie osoby. Użyj metody `find`, aby
program nie tworzył nowego wpisu dla nieznanego imienia.

### Zadanie 14. Licznik słów

Wczytaj zdanie i policz wystąpienia każdego słowa. Wyniki zapisz w
`std::map<std::string, int>`.

### Zadanie 15. Magazyn

Utwórz mapę przechowującą nazwę produktu i liczbę sztuk w magazynie. Program
powinien pozwalać:

- dodać nowy produkt,
- zwiększyć stan produktu,
- zmniejszyć stan produktu,
- odrzucić operację prowadzącą do ujemnego stanu.

### Zadanie 16. Biblioteka filmów

Utwórz klasę `MovieLibrary`, która przechowuje oceny filmów w
`std::map<std::string, double>`.

Klasa powinna pozwalać:

- dodać i usunąć film,
- odczytać ocenę filmu,
- obliczyć średnią ocenę,
- znaleźć najlepiej oceniony film.

## Poziom 4 - Stos, kolejka i lista

### Zadanie 17. Odwracanie kolejności

Umieść kilka słów w `std::stack<std::string>`, a następnie zdejmuj je ze stosu
i wyświetlaj. Zaobserwuj kolejność elementów.

### Zadanie 18. Kolejka klientów

Utwórz kolejkę klientów oczekujących na obsługę. Program powinien pozwalać
dodać klienta oraz obsłużyć pierwszą osobę z kolejki.

### Zadanie 19. Nawiasy

Napisz funkcję, która za pomocą stosu sprawdza, czy w podanym napisie nawiasy
okrągłe są poprawnie zamknięte.

Przykłady:

```text
(a + b)       -> poprawne
((a + b) * c) -> poprawne
(a + b))      -> niepoprawne
```

### Zadanie 20. Lista uczestników

Utwórz `std::list<std::string>` z nazwiskami uczestników. Dodaj i usuń osoby z
początku oraz końca listy. Następnie posortuj listę alfabetycznie.

### Zadanie 21. Dobór kontenera

Dla każdego przypadku wybierz właściwy kontener: `std::vector`, `std::map`,
`std::stack`, `std::queue` albo `std::list`. Zapisz krótkie uzasadnienie w
komentarzu.

- historia cofania operacji w edytorze,
- klienci oczekujący na połączenie z konsultantem,
- oceny przypisane do numeru indeksu studenta,
- lista wyników przeznaczona do częstego sortowania i odczytu,
- elementy często dodawane i usuwane w środku kolekcji.

## Poziom 5 - Zadania projektowe

### Zadanie 22. Ranking graczy

Utwórz klasę `Player` z nazwą i liczbą punktów. Przechowuj graczy w wektorze.
Program powinien:

- odrzucać powtarzające się nazwy,
- pozwalać zmienić wynik gracza,
- wyświetlać ranking malejąco według punktów,
- znaleźć gracza o podanej nazwie.

### Zadanie 23. System zamówień

Utwórz klasy `Order` i `OrderSystem`. System powinien przechowywać zamówienia,
umożliwiać wyszukiwanie po identyfikatorze oraz obsługiwać je w kolejności
dodania.

Dobierz kontenery do każdej odpowiedzialności i uzasadnij wybór w komentarzu.

### Zadanie 24. Rozbudowa HRMS

Rozbuduj projekt z lekcji [06-projekt-hrms.md](06-projekt-hrms.md).

Dodaj:

- usuwanie pracownika ze wszystkich kontenerów,
- przenoszenie pracownika do innego działu,
- średnie wynagrodzenie w dziale,
- listę pracowników posortowaną alfabetycznie,
- informację o błędnej operacji bez przerywania programu.

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

## Archiwum

Oryginalne materiały źródłowe tego segmentu są zachowane w katalogu [archive](archive).
