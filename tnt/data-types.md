# C++ Data Types

- https://www.w3schools.com/cpp/cpp_data_types.asp
- https://www.geeksforgeeks.org/c-data-types/
- https://www.w3schools.com/cpp/cpp_variables.asp

## Description
W C++ mamy różne typy danych, które możemy podzielić na kilka kategorii:

- Podstawowe typy danych
    - Liczby całkowite
int: Przechowuje całkowite liczby od -2147483648 do 2147483647
short int lub short: Przechowuje całkowite liczby od -32768 do 32767
long int lub long: Przechowuje całkowite liczby od -2147483648 do 2147483647
long long int: Przechowuje całkowite liczby od -9223372036854775808 do 9223372036854775807
unsigned int: Przechowuje całkowite liczby od 0 do 4294967295
unsigned short int: Przechowuje całkowite liczby od 0 do 65535
unsigned long int: Przechowuje całkowite liczby od 0 do 4294967295
unsigned long long int: Przechowuje całkowite liczby od 0 do 18446744073709551615
    - Znaki
char: Przechowuje pojedynczy znak
wchar_t: Przechowuje pojedynczy znak szeroki, używany do obsługi zestawów znaków używanych w niektórych językach, takich jak japoński, chiński i koreański
Liczby rzeczywiste
float: Przechowuje liczby zmiennoprzecinkowe
double: Przechowuje liczby zmiennoprzecinkowe o podwójnej precyzji
long double: Przechowuje liczby zmiennoprzecinkowe o podwójnej precyzji z większym zakresem i precyzją
Bool
bool: Przechowuje wartość prawda/fałsz
- Wskazane typy danych
Wskaźniki
type*: Wskaźnik do zmiennej typu type
Referencje
type&: Referencja do zmiennej typu type
Złożone typy danych
Tablice
type[]: Tablica zmiennych typu type
Struktury
struct: Struktura to zbiór zmiennych różnych typów, grupowanych razem
Unie
union: Unia to zbiór zmiennych różnych typów, które współdzielą ten sam obszar pamięci
Wyliczenia
enum: Typ wyliczeniowy to zbiór predefiniowanych wartości
- Typy danych definiowane przez użytkownika
Klasy
class: Klasa to zbiór zmiennych i funkcji, które są zgrupowane razem
Typedef
typedef: Definicja typu pozwala na utworzenie nowego nazwy dla istniejącego typu danych
Powyższe zakresy liczbowe mogą się różnić w zależności od architektury systemu (32-bitowy vs 64-bitowy).

## Code

```cpp
// C++ program to sizes of data types
// https://www.geeksforgeeks.org/c-data-types/
#include<iostream>
using namespace std;
 
int main()
{
    cout << "Size of char : " << sizeof(char)
      << " byte" << endl;
    cout << "Size of int : " << sizeof(int)
      << " bytes" << endl;
    cout << "Size of short int : " << sizeof(short int)
      << " bytes" << endl;
    cout << "Size of long int : " << sizeof(long int)
       << " bytes" << endl;
    cout << "Size of signed long int : " << sizeof(signed long int)
       << " bytes" << endl;
    cout << "Size of unsigned long int : " << sizeof(unsigned long int)
       << " bytes" << endl;
    cout << "Size of float : " << sizeof(float)
       << " bytes" <<endl;
    cout << "Size of double : " << sizeof(double)
       << " bytes" << endl;
    cout << "Size of wchar_t : " << sizeof(wchar_t)
       << " bytes" <<endl;
     
    return 0;
}
```

