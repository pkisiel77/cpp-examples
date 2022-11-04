# Teoria

## Linki
- https://www.youtube.com/watch?v=hXLbgSh1Wo0&list=PLOYHgt8dIdoxx0Y5wzs7CFpmBzb40PaDo&index=3&ab_channel=Pasjainformatyki
- https://www.youtube.com/watch?v=hXLbgSh1Wo0&ab_channel=Pasjainformatyki
- https://en.cppreference.com/w/cpp/language/if
- https://www.w3schools.com/cpp/cpp_conditions.asp

# Zadania

## Zadanie 1
Napisz program który obliczy:
- $\sqrt{3x-1}+(1+x)^2$
- $(sqrt{2} + 3)^2$
- <img width="157" alt="image" src="https://user-images.githubusercontent.com/26519123/195828669-2fa6679b-fe2b-4e12-88bd-4189995866cd.png">
- <img width="212" alt="image" src="https://user-images.githubusercontent.com/26519123/195828752-330ed368-cf79-49da-bece-7fa8268273fc.png">
- <img width="243" alt="image" src="https://user-images.githubusercontent.com/26519123/195828829-2a9b75af-0dba-4f87-82d2-f692cd56d96b.png">

Przykład użycia funkcji SQRT()
```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  cout << "Square root of 25 = ";
   
  // print the square root of 25
  cout << sqrt(25);

  return 0;
}

// Output: Square root of 25 = 5
```

## Zadanie 2*
Napisz program który rozwiąże poniższe równanie:
<img width="320" alt="image" src="https://user-images.githubusercontent.com/26519123/195822629-df3bfbc1-d157-4f03-96c6-eee148ee350d.png">

## Zadanie 3
Napisz program który obliczy wartość liczbową dla x = 1/7 i y = 0.5
<img width="315" alt="image" src="https://user-images.githubusercontent.com/26519123/195825547-a6be93c6-bf3b-445b-a585-c5b267b379a3.png">

## Zadanie 4
Napisz program informujący czy liczba podana przez użytkownika jest większa, mniejsza czy równa zero. 
Wykorzystaj tylko dwie instrukcje warunkowe.

## Zadanie 5
Napisz program informujący czy liczba podana przez użytkownika jest liczbą pierwszą.

## Zadanie 6
Napisz program informujący czy liczba podana przez użytkownika jest parzysta czy nieparzysta.

## Zadanie 7
Napisz program wyznaczający najmniejszą z 10 liczb podanych przez użytkownika.

## Zadanie 8
Napisz program, który odpowiada na pytanie, czy wśród 10 liczb występują pary liczb.

## Zadanie 9
Napisz program, który odpowiada na pytanie, czy trzy podawane liczby całkowite są ustawione w porządku rosnącym.

## Zadanie 10
Napisz program sprawdzający czy liczba podana przez użytkownika jest z przedziału <-10,13> lub <25,35>

## Zadanie 11
Napisz kalkulator wyliczający wskaźnik BMI (Body Mass Index)

Wzór dla wskaźnika BMI

```cpp
BMI = (masa_ciala)/(wzrost * wzrost) // masa_ciala [kg], wzrost [m]
```


```
Zakresy wartości BMI:
mniej niż 16 - wygłodzenie
16 - 16.99 - wychudzenie
17 - 18.49 - niedowaga
18.5 - 24.99 - wartość prawidłowa
25 - 29.99 - nadwaga
30 - 34.99 - I stopień otyłości
35 - 39.99 - II stopień otyłości
powyżej 40 - otyłość skrajna
```

## Zadanie 12
Napisz program sprawdzający czy dwie różne liczby całkowite są liczbami skojarzonymi.

Dwie różne liczby całkowite a i b większe od 1 nazwiemy skojarzonymi, 
jeśli suma wszystkich różnych dodatnich dzielników a mniejszych od a jest równa b+1, 
a suma wszystkich różnych dodatnich dzielników b mniejszych od b jest równa a+1.

Skojarzone są np. liczby 140 i 195, ponieważ:
a) dzielnikami 140 są 1, 2, 4, 5, 7, 10, 14, 20, 28, 35, 70, a ich suma wynosi 196 = 195+1.
b) dzielnikami 195 są 1, 3, 5, 13, 15, 39, 65, a suma tych liczb równa jest 141 = 140+1. 
