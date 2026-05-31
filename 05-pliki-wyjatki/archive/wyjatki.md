# Wyjątki (Exceptions)

_Stosujemy w sytuacjach, gdy jedna z części programu zleca innej wykoanie ryzykownego zadania. Ryzykownego, czyli takiego , które może się nie udać._

## Opis

### Obsługa błędów i wyjątków

- błąd => przyczyna, która powoduje niewłaściwe działanie programu. 
  - error => różnica między spodziewanym a faktycznym działaniem programu. 
  - fault, bug => defekt, przyczyna, która powoduje niewłaściwe działanie programu. 
  - failure => stan w którym program nie działa właściwe.  
  - mistake => działanie człowieka, które powoduje niewłaściwe działanie programu. 
- wyjątek (exception) – przewidywalne przez  programistę niewłaściwe zachowanie programu wykonywalnego.   
- wyjątek (IEEE 610, Standard Computer Dictionary) - zdarzenie które powoduje niewłaściwe działanie programu. Rozróżnia się następujące typy wyjątków:
  − niewłaściwe adresowanie,
  − niewłaściwe dane,
  − niewłaściwie wykonana operacja,
  − przepełnienie (overflow exception),
  − niedopełnienie (underflow exception),
  − niewłaściwa ochrona (protection exception).
- wyjątek – jest to obiekt, który przekazuje informację o niewłaściwym działaniu programu do innego obszaru  programu.
- debugging - proces wykrywania i usuwania błędów w programie. 
- obsługa wyjątków – proces  analizy zdarzeń które mogą powodować niewłaściwe zachowanie programu i  definiowanie procedur alternatywnych zachowań programu

[src](https://docplayer.pl/57445059-11-1-obsluga-bledow-i-wyjatkow-polecenia-try-throw-catch-cli-c-klasa-exception-9.html)

```cpp
try 
{
    // "Wyrzucenie" wyjątku:
    if(coś poszło nie tak)
        throw wyjątek;
    // KOD
}
catch (typ nazwa) 
{
    // Obsługa wyjątku
}
```
```cpp
try 
{
    // Code
}
catch (int ex) 
{
    cout << "exception for type int";
}
catch (double ex) 
{
    cout << "exception for type double";
}
catch (...) 
{
    cout << "default exception";
}
```

- [Wyjątki standardowe](https://en.cppreference.com/w/cpp/error/exception)
- [Wyjątki opis MS](https://docs.microsoft.com/pl-pl/cpp/cpp/errors-and-exception-handling-modern-cpp?view=msvc-160)

## Własne wyjątki

```cpp
#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception
{
    virtual const char *what() const throw()
    {
        return "My exception :)";
    }
};
int main()
{
    MyException myEx;
    try
    {
        throw myEx;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
```

## noexcept

```cpp
// specyfikator noexcept
void method0(); // metoda może rzucić wyjątki
void method1() noexcept(true); // metoda nie rzuca wyjątki
void method2() noexcept(false); // metoda może rzucić wyjątki
void method3() noexcept; // noexcept(true)
```

```cpp
// operator noexcept
void method(double) noexcept;
void method(int);

constexpr bool m1 = noexcept(method(2.5)); // true
constexpr bool m2 = noexcept(method(2)); // false
```

```bash
g++ file.cpp -std=c++11
```

```cpp
#include <iostream>
using namespace std;
void foo() noexcept     // see the noexcept specifier
{
    throw 42;
}
int main()
{
    try
    {
        foo();
    }
    catch(...)
    {
        cerr<<"exception caught\n";
    }
    return 0;
}
```

```cpp
#include <iostream>
using namespace std;
void foo()    // noexcept is eliminated
{
    throw 42;
}
int main()
{
    try
    {
        foo();
    }
    catch(...)
    {
        cerr<<"exception caught\n";
    }
    return 0;
}
```

## Przykłady

Ex1
```cpp
#include <iostream>
using namespace std;

int main()
{
	try
	{
		int n;
		cout << "Number(1-10):";
		cin >> n;
		if (n < 0)
			throw 1;
		if (n == 0)
			throw 2;
		if (n > 10)
			throw 3;
		cout << "n*n = " << n * n << endl;
	}
	catch (int x)
	{
		cout << "Exception nb " << x << endl;
	}

	return 0;
}
```

Ex2
```cpp
#include <iostream>
#include <vector>
 
int main() {
    try {
        std::cout << "Throwing an integer exception...\n";
        throw 42;
    } catch (int i) {
        std::cout << " the integer exception was caught, with value: " << i << '\n';
    }
 
    try {
        std::cout << "Creating a vector of size 5... \n";
        std::vector<int> v(5);
        std::cout << "Accessing the 11th element of the vector...\n";
        std::cout << v.at(10); // vector::at() throws std::out_of_range
    } catch (const std::exception& e) { // caught by reference to base
        std::cout << " a standard exception was caught, with message '"
                  << e.what() << "'\n";
    }
 
}
```

Ex3
```cpp
#include <iostream>
using namespace std;
void main()
{
    try
    {
        int x = 7;
        throw x;
    }
    // polecenie catch() wyłapuje wyrzuconą zmienną typu int gdy:
    // catch (const int ci), catch (int i), catch (int & r)
    /*    catch (int i)       {             cout << "Blad, x=  " << i << endl;        } */
    /*    catch (const int ci)       {             cout << "Blad, x=  " << ci << endl;        } */
    catch (int &r)
    {
        cout << "Blad, x=  " << r << endl;
    }
}
```
example for [link](https://docplayer.pl/57445059-11-1-obsluga-bledow-i-wyjatkow-polecenia-try-throw-catch-cli-c-klasa-exception-9.html)


[Ex4](https://docs.microsoft.com/pl-pl/cpp/cpp/exceptions-and-stack-unwinding-in-cpp?view=msvc-160)



