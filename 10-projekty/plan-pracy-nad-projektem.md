# Plan pracy nad projektem

Ten dokument pomaga prowadzić projekt etapami. Celem nie jest napisanie całego
programu naraz, tylko regularne dostarczanie małych, działających wersji.

## 1. Etap startowy

Na początku projektu przygotuj:

- wybrany temat i krótki opis celu,
- wariant minimum zapisany w kilku punktach,
- katalog projektu,
- pierwszy `README.md`,
- komendę kompilacji,
- najprostszy program, który się kompiluje i uruchamia.

Po tym etapie projekt nie musi jeszcze rozwiązywać problemu. Musi jednak mieć
strukturę, którą da się dalej rozwijać.

## 2. Etap modelu danych

W drugim kroku ustal, jakie dane przechowuje program:

- jakie obiekty występują w problemie,
- jakie pola mają te obiekty,
- które dane są wpisywane przez użytkownika,
- które dane są liczone przez program,
- które dane trzeba zapisać do pliku.

Przykłady:

- system zadań przechowuje tytuł, opis, status i termin zadania,
- baza pojazdów przechowuje markę, model, rocznik i numer rejestracyjny,
- parser CSV przechowuje wiersze, kolumny i wynik walidacji.

## 3. Etap pierwszej funkcji

Pierwsza funkcja powinna być mała i widoczna dla użytkownika. Dobre przykłady:

- dodanie jednego zadania,
- wczytanie jednego rekordu z pliku,
- wykonanie jednego działania w kalkulatorze,
- wyświetlenie pustej planszy gry,
- zapis jednego wpisu do logu.

Po tym etapie program powinien mieć pierwszy scenariusz sprawdzenia.

## 4. Etap wariantu minimum

Wariant minimum jest gotowy, gdy program:

- realizuje wszystkie podstawowe wymagania z opisu projektu,
- obsługuje podstawowy przypadek użycia od początku do końca,
- obsługuje co najmniej jeden błąd użytkownika,
- nie wymaga ręcznego poprawiania plików po uruchomieniu,
- ma instrukcję kompilacji i uruchomienia.

Na tym etapie nie dodawaj jeszcze rozszerzeń, jeśli podstawowy przepływ działania
nie jest stabilny.

## 5. Etap testów i scenariuszy

Przygotuj krótką listę sprawdzeń:

- przypadek poprawny,
- przypadek błędnych danych,
- przypadek pustych danych,
- przypadek graniczny,
- ponowne uruchomienie programu po zapisie danych.

Jeśli projekt ma testy automatyczne, opisz komendę ich uruchomienia. Jeśli ma
testy ręczne, zapisz dokładne kroki i oczekiwany wynik.

## 6. Etap dokumentacji

`README.md` projektu powinien odpowiedzieć na pytania:

- co robi program,
- jak go skompilować,
- jak go uruchomić,
- jakie funkcje zawiera wariant minimum,
- jakie rozszerzenia zostały dodane,
- jakie są znane ograniczenia,
- jakie pliki są najważniejsze.

Dokumentacja nie musi być długa. Musi pozwolić innej osobie uruchomić projekt
bez zgadywania.

## 7. Etap pokazu

Przed pokazem przygotuj kolejność demonstracji:

1. Uruchomienie programu.
2. Pokaz podstawowego przypadku użycia.
3. Pokaz obsługi błędnych danych.
4. Krótkie omówienie struktury plików.
5. Wskazanie najważniejszych funkcji albo klas.
6. Pokaz testów albo ręcznych scenariuszy.
7. Omówienie ograniczeń i możliwych rozszerzeń.

Pokaz powinien zaczynać się od wariantu minimum. Rozszerzenia pokazuj dopiero
po udowodnieniu, że podstawowy program działa.

## 8. Proponowany harmonogram

| Moment pracy | Co powinno być gotowe |
| --- | --- |
| Start | Temat, wariant minimum, katalog, pierwsze `README.md` |
| Po pierwszej iteracji | Program kompiluje się i wykonuje jedną prostą akcję |
| Po drugiej iteracji | Istnieje model danych i część funkcji minimum |
| Po trzeciej iteracji | Wariant minimum działa od początku do końca |
| Przed oddaniem | Dokumentacja, scenariusze sprawdzenia, obsługa błędów |
| Pokaz | Projekt uruchamia się na czystym stanowisku |

## 9. Sygnały ostrzegawcze

Zatrzymaj się i uprość zakres, jeśli:

- program długo się nie kompiluje,
- nie da się pokazać żadnego działającego scenariusza,
- większość czasu zajmują rozszerzenia zamiast wariantu minimum,
- struktura plików jest niezrozumiała dla autora projektu,
- dane są przechowywane w wielu miejscach bez jasnej odpowiedzialności.

W takiej sytuacji lepiej zmniejszyć zakres i doprowadzić prostszą wersję do
końca niż zostawić rozbudowany, ale niedziałający projekt.
