# Pętle 

## for 

- [for](https://en.cppreference.com/w/cpp/language/for)
- [for](https://docs.microsoft.com/pl-pl/cpp/cpp/for-statement-cpp?view=vs-2019)

Składnia
```cpp
for ( init-expression ; cond-expression ; loop-expression )
    statement
```
- (Range-based for)[https://en.cppreference.com/w/cpp/language/range-for]
- (Range-based for)[https://docs.microsoft.com/pl-pl/cpp/cpp/range-based-for-statement-cpp?view=vs-2019]

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

# Wskaźniki i referencje

## Inicjacja i deklaracja wskaźnika z NULL

(NULL)[https://en.cppreference.com/w/cpp/types/NULL]

```cpp
int * ptrInt1 = 0;
int * ptrInt2 = NULL;
int * ptrInt3 = nullptr; // C++11
```

```cpp
int * ptr = 0;                    // Zadeklaruj wskaźnik typu int, inicjacja wskaźnika tak, aby wskazywał na NULL
std::cout << *ptr << std::endl;   // STATUS_ACCESS_VIOLATION EXCEPTION
int * ptr = NULL;                
```
Wartość NULL podczas deklaracji jest dobrą praktyką inżynierii oprogramowania.

## Wskaźniki
```cpp
int * ptr, v1;
int * ptr1, * ptr2;

// p jest wskaźnikiem na int:
int *p;
// s jest wskaźnikiem na char:
char *s;

// Tutaj i jest normalną zmienną, nie wskaźnikiem(!):
int *q, i;
// Równoważnie:
int i, *q;
```

## Operator &
Aby zainicjalizować wskaźnik potrzebujemy operatora pobrania adresu – &. 
Operator ten, jak nazwa wskazuje, zwraca adres podanego obiektu.

```cpp
int i;
int *p = &i;
```
## Operator *
Mechanizm ten to tzw. operator dereferencji, oznaczany znowu gwiazdką przed wskaźnikiem. 
Pozwala on zarówno na pobranie wartości zmiennej na którą wskaźnik wskazuje, jak i na jej modyfikację:

```cpp
int i = 1;
int p = &i;

cout <<  p; // adres 0x1798010
cout << *p; // 1

*p = 2;
cout << *p; // 2
cout << i;  // 2
```

```cpp
int v1 = 123;
int * ptr= & v1;
int arr[ 2 ] = { 10, 20 };

std::cout << "Wartosc: " << v1 << ", Adres: " << ptr << ", Adres wskaznika: " << & ptr << std::endl;
std::cout << & arr[ 0 ] << '\n' << & arr[ 1 ] << std::endl;
```

```cpp
int v1 = 123;
int * ptr = & v1;

std::cout << v1 << std::endl;
std::cout << ptr << std::endl;
std::cout << * ptr << std::endl;
```

```cpp
std::cout << v1 << " = " << * ptr << std::endl;
v1 = 42;
std::cout << v1 << " = " << * ptr << std::endl;
* ptr = 357;
std::cout << v1 << " = " << * ptr << std::endl;
```

### Zadanie 1
Napisz funkcję otrzymującą jako argumenty wskaźniki do dwóch zmiennych typu int, która zamienia ze sobą wartości wskazywanych zmiennych tylko wtedy, gdy wskazywana przez drugi argument zmienna jest mniejsza od zmiennej wskazywanej przez pierwszy argument.

### Zadanie 2
Napisz funkcję otrzymującą jako argumenty referencje
do dwóch zmiennych typu int, która zamienia ze sobą wartości zmiennych, do których referencje dostaliśmy w argumentach.

### Zdanie 3
Napisz funkcję otrzymującą dwa argumenty referencję a
oraz wskaźnik b do zmiennych typu int, która zamienia ze sobą wartości zmiennych, do których wskaźnik i referencję dostała w argumentach.

### Zadanie 4
Napisz funkcję, która pobiera dwa argumenty i zwraca dwa odrębne wyniki.
Jednym z wyników powinien być iloczyn obu argumentów, a drugim ich suma. Ponieważ funkcja może bezpośrednio zwracać tylko jedną wartość, druga
powinna być zwracana poprzez parametr wskaźnikowy albo referencję.

## swap()

Opis
Przypisuje wartość obiektu a obiektowi b i wartość obiektu b obiektowi a

Składnia
```cpp
#include <algorithm>
namespace std
{
    template < typename T >
    void swap( T & a, T & b );
}
```

(Przykład)[http://www.cplusplus.com/reference/algorithm/swap/]

### Zadanie 5
Napisz funkcję, która zamienia miejscami wartości swoich dwóch argumentów.
Przekaż do funkcji argumenty przy użyciu wskaźników albo referencji.
Przygotuj odpowiednie testy dla zaproponowanego rozwiązania.

### Zadanie 6
(Source)[http://cpp0x.pl/dokumentacja/standard-C++/swap/461]
Należy wziąć pod uwagę, że ta funkcja powoduje skopiowanie obiektu do zmiennej tymczasowej i dwa razy wywołuje operator przypisania, 
więc może nie być efektywna dla typów, dla których wspomniane operacje są kosztowne. 
W takie sytuacji rekomendowane jest przeciążenie tej funkcji tak, by wykonywała zamianę w wydajniejszy sposób.

