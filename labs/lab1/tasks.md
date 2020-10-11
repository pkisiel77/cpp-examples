# Początek C++

### Komentarze w kodzie C++
[Comments in C++](https://en.cppreference.com/w/cpp/comment)

### Argumenty funkcji main

```cpp
int main () {}
int main (int argc, char *argv[]) {}
int main (int argc, char **argv) {}
// another implementation-defined form, with int as return type	
```
#### Przykład 1
```cpp
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    cout << "Number of arguments " << argc << endl;

    for (int i = 0; i < argc; ++i)
        cout << argv[i] << endl;

    return 0;
}
```
#### Przykład 2

[WinMain](https://docs.microsoft.com/en-us/windows/win32/learnwin32/winmain--the-application-entry-point)

```cpp
// another implementation-defined form, with int as return type
INT WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR lpCmdLine, INT nCmdShow)
{
    return 0;
}
```
### Operacje na strumieniach cin, cout

#### Zadanie 1
Napisz program sortujący rosnąco ciąg liczb podanch jako arguemnt programu.

Przykład dla zadania nr 1

- sort.exe 100 2 30 5 8 34 56 78 90
- out = 2 5 8 30 34 56 78 90 100

- ./sort 100 2 30 5 8 34 56 78 90
- out = 2 5 8 30 34 56 78 90 100

#### Zadanie 2
Napisz kalkulator BMI


### Formatownie wyjścia - iomanip

### Referencja 




