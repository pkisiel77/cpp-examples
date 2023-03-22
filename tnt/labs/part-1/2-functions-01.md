## 

https://app.prezo.ai/decks/d567dee5-d87a-497f-b43f-5453cdca2a66

## Deklaracja i definicja funkcji



https://user-images.githubusercontent.com/26519123/226863231-5be7342f-a7ce-4b9c-930b-773cf240ced2.mp4



```cpp
#include <iostream>

// function declaration
int addTwoIntNumbers(int a, int b);

// or 
// int addTwoIntNumbers(int, int);

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
