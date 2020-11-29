# Wyjątki (Exceptions)

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


- [Wyjątki standardowe](https://en.cppreference.com/w/cpp/error/exception)
- [Wyjątki opis MS](https://docs.microsoft.com/pl-pl/cpp/cpp/errors-and-exception-handling-modern-cpp?view=msvc-160)
- [Wyjątki własne]

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
```



