## Deklaracja i definicja funkcji


```cpp
#include <iostream>

// function declaration
int addTwoIntNumbers(int a, int b);

int main() 
{
    int ret = addTwoIntNumbers(1,2);
    std::cout << ret << "\n";
    return 0;
}

// function definition
int addTwoIntNumbers(int a, int b)
{
    return a + b;
}
```
