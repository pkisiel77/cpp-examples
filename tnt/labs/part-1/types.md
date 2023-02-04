Napisz program w języku C++, który będzie przechowywał dwa typy danych: liczbę całkowitą i liczbę zmiennoprzecinkową.  
Następnie program powinien wykonać kilka operacji na tych liczbach, wykorzystując różne typy danych.

- Przypisz do zmiennej całkowitej 'a' wartość 5, a do zmiennej zmiennoprzecinkowej 'b' wartość 3.14
- Oblicz i wyświetl sumę tych dwóch zmiennych
- Oblicz i wyświetl iloczyn tych dwóch zmiennych
- Oblicz i wyświetl resztę z dzielenia liczby całkowitej przez liczbę zmiennoprzecinkową
- Oblicz i wyświetl różnicę pomiędzy liczbą całkowitą a liczbą zmiennoprzecinkową
- Wypisz na ekranie wartość zmiennej całkowitej oraz zmiennej zmiennoprzecinkowej
- Uwaga: Pamiętaj o odpowiednim konwertowaniu typów danych przed wykonaniem operacji matematycznych.


```cpp
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  // Typy liczbowe stałoprzecinkowe
  float a = 3.14;
  double b = -2.718;

  cout << "Wartość zmiennej 'a': " << a << endl;
  cout << "Wartość zmiennej 'b': " << b << endl;

  // Typy liczbowe zmiennoprzecinkowe
  long double c = 1.0;
  long double d = -0.5;

  cout << "Wartość zmiennej 'c': " << c << endl;
  cout << "Wartość zmiennej 'd': " << d << endl;

  // Operacje matematyczne na typach liczbowych
  long double result = sin(a) + cos(b);

  cout << "Wynik operacji matematycznej: " << result << endl;

  return 0;
}
```
