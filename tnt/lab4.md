# Wskaźniki i referencje

## Inicjacja i deklaracja wskaźnika z NULL

[NULL in C](https://en.cppreference.com/w/c/types/NULL)

[NULL in C++](https://en.cppreference.com/w/cpp/types/NULL)

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
