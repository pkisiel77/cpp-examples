## Apps
- https://diagrams.net
- https://online.visual-paradigm.com/diagrams/templates/?category=flowchart


## Links
- https://home.agh.edu.pl/~estrzalk/PI/cw/zapis_algorytmow.pdf
- http://informatyka2.orawskie.pl/?pl_schematy-blokowe,90

## Zadanie 1
Napisz program w C++ realizujący poniższy algorytm

<img width="301" alt="image" src="https://user-images.githubusercontent.com/26519123/197586723-9dc26817-d42e-4132-b680-9b97d7d52eb1.png">

```cpp
#include <iostream>

int main() {
    int a, b, c;

    std::cout << "Podaj a ";
    std::cin >> a;
    std::cout << "Podaj b ";
    std::cin >> b;

    c = a + b;

    std::cout << "a + b = " << c << "\n";

    return 0;
}
```

## Zadanie 2
Napisz program w C++ realizujący poniższy algorytm

<img width="359" alt="image" src="https://user-images.githubusercontent.com/26519123/197586880-a01c7f7f-cadb-443e-9064-880fe6a69c4d.png">

```cpp
#include <iostream>

int main() {
    int a, b;

    std::cout << "Podaj a ";
    std::cin >> a;
    std::cout << "Podaj b ";
    std::cin >> b;

    if (a >= b) {
        std::cout << "max a =  " << a << "\n";
    } else {
        std::cout << "max b = " << b << "\n";
    }

    return 0;
}
```

## Zadanie 3
Napisz program w C++ realizujący poniższy algorytm

<img width="316" alt="image" src="https://user-images.githubusercontent.com/26519123/197586992-f78b155f-ba25-4bb7-a3b7-f20965c9f836.png">
