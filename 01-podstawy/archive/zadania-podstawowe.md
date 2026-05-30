## Zadanie 1
Napisz program w języku C++, który pobiera od użytkownika 5 liczb całkowitych i zapisuje je do tablicy. 
Następnie program wywołuje funkcję, która znajduje największą i najmniejszą liczbę w tablicy oraz oblicza ich średnią arytmetyczną. 
Funkcja powinna przyjmować tablicę jako argument i zwracać strukturę zawierającą wartości maksymalnej, minimalnej i średniej arytmetycznej. 
Na końcu program powinien wypisać wyniki na ekranie.

Przykładowe wykonanie programu:

```
Podaj 5 liczb całkowitych:
1
2
3
4
5

Wyniki:
Największa liczba: 5
Najmniejsza liczba: 1
Średnia arytmetyczna: 3
```

## Zadanie 2
Napisz program w języku C++, który będzie działał jako parser dla zapisu wyrażeń arytmetycznych w notacji ONP (Odwrócona Notacja Polska). Program powinien umożliwiać wprowadzenie wyrażenia w postaci ONP przez użytkownika i obliczenie jego wartości.

Kroki programu:

Utwórz stos na liczbach całkowitych, na którym będziesz przechowywał wartości wynikowe.
Pobierz od użytkownika wyrażenie w postaci ONP.
Przejdź przez wyrażenie od lewej do prawej i wykonaj następujące czynności:
- Jeśli napotkasz liczbę, umieść ją na stosie.
- Jeśli napotkasz operator, pobierz dwie wartości ze szczytu stosu, wykonaj działanie określone przez operator i umieść wynik na stosie.
- Po przejściu całego wyrażenia, wynik powinien znajdować się na szczycie stosu. 
- Zdejmij go ze stosu i wypisz na ekranie.

```
Podaj 5 liczb całkowitych:
1
2
3
4
5

Wyniki:
Największa liczba: 5
Najmniejsza liczba: 1
Średnia arytmetyczna: 3
```
