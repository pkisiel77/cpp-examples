# Wstęp
- https://en.cppreference.com/w/cpp/language/for
- https://www.youtube.com/watch?v=y6GOYVTVvqo&ab_channel=Pasjainformatyki
- https://cpp0x.pl/kursy/Kurs-C++/Poziom-2/Petla-for/294

# Zadanie 1
Na podstawie poniższego diagramu napisz program w C++

<img width="486" alt="image" src="https://user-images.githubusercontent.com/26519123/198257884-6f0b525a-6f4e-4180-8ef9-1be61b7ffc6e.png">

# Zadanie 2

```cpp
#include <iostream>

int main()
{
    int array[] = {1,3,6,3,4,7,8,4,3};
    // Wyświetl elementy tabulicy array[] używając:
    // for 
    // while 
    // do{}while
    std::cout << sizeof(array)/sizeof(int) << "\n";

    return 0;
}
```
Do zadania 1 dodaj schemat blokowy.

# Zadanie 3

```cpp
#include <iostream>

int main()
{
    int array[] = {1,3,6,3,4,7,8,4,3};
    // Oblicz średnią artymetyczną 
    // Use: for or while loop
    std::cout << sizeof(array)/sizeof(int) << "\n";

    return 0;
}
```
## Proponowane rozwiązanie
```cpp
#include <iostream>

int main()
{
    // Oblicz średnią artymetyczną
    int array[] = {1,3,6,3,4,7,8,4,3};
    // array size
    int n = sizeof(array)/sizeof(int);
    std::cout << "Array size = " << n << "\n";
    
    int sum = 0;
    for(int i=0; i < n; i++) {
        sum += array[i];
    }
    
    double avg = sum / (n*1.0);
    
    std::cout << "AVG = " << avg << "\n";
    
    return 0;
}
```

<img width="736" alt="image" src="https://user-images.githubusercontent.com/26519123/197942274-6a712b1b-f1d0-4df5-b187-fd73b9e68e9e.png">

