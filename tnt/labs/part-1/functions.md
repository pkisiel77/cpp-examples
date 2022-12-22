# Funkcja

- Funkcja ma swoją nazwę, która ją identyfikuje.
- Funkcja jest blokiem kodu, który wykonuje jakąś operację.
```cpp
{ // block begin

} // block end
```
- Funkcja może opcjonalnie definiować parametry wejściowe, które umożliwiają obiektom wywołującym przekazywanie argumentów do funkcji. 
- Funkcja może opcjonalnie zwrócić wartość jako dane wyjściowe. 
- Funkcje są przydatne w przypadku hermetyzacji typowych operacji w jednym bloku wielokrotnego użytku, najlepiej z nazwą, 
  która wyraźnie opisuje działanie funkcji.

https://learn.microsoft.com/pl-pl/cpp/cpp/functions-cpp?view=msvc-170

```cpp
typ_wartości nazwa_funkcji(lista_parametrów){
   deklaracje_zmiennych;  
   ciąg instrukcji;
   deklaracje_zmiennych;
   ciąg instrukcji;
   ...
}
```

# Deklaracja i definicja

Funkcja C++ składa się z dwóch części:
- Deklaracja: zwracany typ, nazwa funkcji i parametry (jeśli występują)
- Definicja: ciało funkcji (kod do wykonania)

## Deklaracja

- Deklaracja 
```cpp 
int f( );

// oznacza 

int f(void);
```

- Deklaracja funkcji kończy się średnikiem

Przykłady deklaracji funkcji:
```cpp
double kwadrat(int bok);
```
kwadrat jest funkcji (wywoływaną z jednym argumentem typu **int**), która w rezultacie zwraca wartość typu **double**

### Opisz poniższe deklaracje.
```cpp
void fun(int stopien, char znaczek, int nachylenie); 
int przypadek(void);
char znak_x();
void pin(...);
```

### Nazwa argumentów funkcji w deklaracji

Nazwy argumentów umieszczone w nawiasach deklaracji funkcji są nieistotne dla kompilatora i można je pominąć. 

> Uwaga: nazwy, a nie typy argumentów.

Dlatego deklarację funkcji:
```cpp
void fun(int stopien, char znaczek, int nachylenie);
```
można napisać także jako:
```cpp
void fun(int, char, int);
```
To dlatego, że w deklaracji powiadamiamy kompilator o liczbie i typie argumentów. 
Ich nazwy nie są w tym momencie istotne. 
To będzie ważne w definicji.

### C++ 11

C++11 dopuszcza nowy, alternatywny zapis w takiej postaci:

```cpp
auto funkcja(typ_arg1 , typ_arg2 ) -> typ_rezultatu ;
```

## Definicja

```cpp
double kwadrat(int bok)
{
  retrun bok * bok;
}
```

# Linki
- https://www.w3schools.com/cpp/cpp_functions.asp
- https://www.youtube.com/watch?v=NKTqUVq6NN0&ab_channel=Kana%C5%82oWszystkim
- https://www.youtube.com/watch?v=b1HxT1QATvo&ab_channel=Kana%C5%82oWszystkim
- https://www.youtube.com/watch?v=HHplT1A4_A4&t=1s&ab_channel=Pasjainformatyki

## Zadania
Napisz program w C++ obliczający pole prostokąta (utwórz funkcję rectangleArea). 
Program powinien on zawierać jedną funkcję (podprogram) => bezparametrową funkcję pole_prostokata(), w której zawarty będzie algorytm obliczania pola.

Wartości boków a i b wprowadzamy z klawiatury. w programie należy założyć, że zmienne a, b oraz pole są typu float (rzeczywistego) i są one zmiennymi globalnymi. Należy dla nich przyjąć format wyświetlania ich z dwoma miejscami po kropce.

## Z2
Conversion
Napisz program (utwórz funkcję conversion) do konwersji temperatury ze stopni Celsjusza na stopnie Fahrenheita:
Fahrenheit = Celsjusz * (212 - 32)/100 + 32







