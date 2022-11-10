## Zadanie
Naisz program który za pomocą **pętli for** sumuje liczby całkowite od 1 do 110

## Zadanie
Naisz program który za pomocą **pętli do{}while** sumuje liczby całkowite od 1 do 110

## Zadanie
Naisz program który za pomocą **pętli while** sumuje liczby całkowite od 1 do 110

## Zadanie
Naisz program który za pomocą **pętli for** sumuje liczby **parzyste** od 1 do 110

## Zadanie
Naisz program który za pomocą **pętli do{}while** sumuje liczby **nieparzyste** od 1 do 110

## Zadanie
Naisz program który za pomocą **pętli while** sumuje liczby **pierwsze** od 1 do 110

## Zadanie *

Napisz program który wyświetli tabliczkę mnożenia od 1 do 100

Wynik działania programu:

![image](https://user-images.githubusercontent.com/26519123/201101425-a3b3c2cc-d7db-4f17-8410-8857df1b5218.png)

src: https://www.bajkidoczytania.pl/img/tabliczka-mnozenia-do-100.pdf

## Zadanie *
Napisz program, który znajdzie największą i najmniejszą liczbę ze zbioru n **(int n;)** liczb losowych z przedziału od 1 do 100 oraz obliczy ich średnią arytmatyczną

```cpp
#include<iostream>
#include<cstdlib>

int main(){

	srand((unsigned) time(NULL));

	// Loop to get 5 random numbers
	for(int i=1; i<=5; i++){
		
		// Retrieve a random number between 1 and 100
		// Offset = 1
		// Range = 101
		int random = 1 + (rand() % 101);

		// Print the random number
		std::cout<<random<<"\n";
	}

	return 0;
}
```

