# Zadanie 1

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
## sln
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
