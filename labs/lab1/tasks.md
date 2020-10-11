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
```sh
sort.exe 100 2 30 5 8 34 56 78 90
out = 2 5 8 30 34 56 78 90 100

chmod +x sort
./sort 100 2 30 5 8 34 56 78 90
out = 2 5 8 30 34 56 78 90 100
```

#### Zadanie 2
Napisz kalkulator wyliczający wskaźnik BMI (Body Mass Index)

Wzór dla BMI

```cpp
BMI = (masa_ciala)/(wzrost * wzrost) // masa_ciala [kg], wzrost [m]
```

```
Zakresy wartości BMI:
mniej niż 16 - wygłodzenie
16 - 16.99 - wychudzenie
17 - 18.49 - niedowaga
18.5 - 24.99 - wartość prawidłowa
25 - 29.99 - nadwaga
30 - 34.99 - I stopień otyłości
35 - 39.99 - II stopień otyłości
powyżej 40 - otyłość skrajna
```

### Formatownie wyjścia - iomanip

### Referencja 




