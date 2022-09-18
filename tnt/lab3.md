# Pętle 

## for 

- [cppreference-link](https://en.cppreference.com/w/cpp/language/for)
- [microsoft-link](https://docs.microsoft.com/pl-pl/cpp/cpp/for-statement-cpp?view=vs-2019)

Składnia
```cpp
for ( init-expression ; cond-expression ; loop-expression )
    statement
```
### Przykłady i zadania
- http://drzewniak.slupsk.pl/~ks/c/c_013.html



### Range-based for
- [cppreference-link](https://en.cppreference.com/w/cpp/language/range-for)
- [microsoft-link](https://docs.microsoft.com/pl-pl/cpp/cpp/range-based-for-statement-cpp?view=vs-2019)

Składnia
```cpp
for (***Deklaracja* : dla zakresu *wyrażenie***)
    instrukcja
```

```cpp

// FASLE 0
// TRUE != 0

// pre, post inkrementacja i dekrementacja

for(int i=0;i<10;i++)
{
    std::cout << i << endl;
}

// Basic 10-element integer array.
int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

// Range-based for loop to iterate through the array.
for( int y : x ) 
{ 
    // Access by value using a copy declared as a specific type.
    // Not preferred.
    cout << y << " ";
}
cout << endl;

// example for: key, value ... 
```

## while

- (while)[https://en.cppreference.com/w/cpp/language/while]
- (while)[https://docs.microsoft.com/pl-pl/cpp/cpp/while-statement-cpp?view=vs-2019]

Składnia
```cpp
```

## do{}while

- (do-while)[https://en.cppreference.com/w/cpp/language/do]
- (do-while)[https://docs.microsoft.com/pl-pl/cpp/cpp/do-while-statement-cpp?view=vs-2019]

```cpp
do
   statement
while ( expression ) ;
```

## goto

```cpp
    int i=1;

    if(i=0) // err? ==
    {
        goto AAA;
    }
    else 
    {
        goto BBB;
    }

AAA:
    {
        cout << "AAA" << endl;    
    }

BBB:
    {
        cout << "BBB" << endl;    
    }
```

## Instrukcje warunkowe

### if

- (if)[https://en.cppreference.com/w/cpp/language/if]
- (if)[https://docs.microsoft.com/pl-pl/cpp/cpp/if-else-statement-cpp?view=vs-2019]

#### Zadanie 1
Jaki będzie wyniki działania poniższego kodu i dlaczego.

```cpp
#include <iostream>

int main()
{
    int a = 1;
    
    if (a == 0); 
    {
        std::cout << "a1=" << a << std::endl;
        a = 2;
    }
    std::cout << "a2=" << a << std::endl;
}
```

### switch

- (switch)[https://en.cppreference.com/w/cpp/language/switch]
- (switch)[https://docs.microsoft.com/pl-pl/cpp/cpp/switch-statement-cpp?view=vs-2019]

### ? :

- Operator warunkowy / trójargumentowy 
- Conditional Operator

```cpp
int a=0, b=1;
return a>b ? 1 : 0;
```
