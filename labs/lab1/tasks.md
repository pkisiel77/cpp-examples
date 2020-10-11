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

Wzór dla wskaźnika BMI

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

#### setprecision

```cpp
#include <iostream>     
#include <iomanip>      

using namespace std;

int main()
{
    double double_value = 3.14159;

    cout << setprecision(4) << double_value << endl;
    cout << setprecision(9) << double_value << endl;
    cout << fixed;
    cout << setprecision(5) << double_value << endl;
    cout << setprecision(10) << double_value << endl;;

    return 0;
}
```

#### setw

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "The number printed with width 10" << endl;
    cout << setw(10);
    cout << 77 << endl;

    cout << "The number printed with width 2" << endl;
    cout << setw(2);
    cout << 10 << endl;

    cout << "The number printed with width 5" << endl;
    cout << setw(5);
    cout << 25 << endl;
    return 0;
}
```

#### setfill

```cpp
#include <iostream>     
#include <iomanip> 

using namespace std;

int main () 
{
    cout << setfill('*') << setw(10);
    cout << 15 << endl;
    cout << setfill('#') << setw(5);
    cout << 5 << endl;
    cout << setfill('#') << setw(5);
    cout << 1 << endl;
    cout << setfill('*') << setw(10);
    cout << 25 << endl;

    return 0;
}
```


### Referencja 




