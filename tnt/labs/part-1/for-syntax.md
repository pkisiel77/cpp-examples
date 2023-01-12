```cpp
#include <iostream>

int main() {
    // Poprawna składnia pętli for
    for (int i = 0; i < 10; i++) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    // Poprawna składnia pętli for z deklaracją zmiennej wewnątrz
    for (int i = 0; i < 5; i++) {
        std::cout << i*i << " ";
    }

    std::cout << std::endl;

    // Błędna składnia pętli for - brak inicjalizacji zmiennej
    for (; i < 5; i++) {
        std::cout << i*i << " ";
    }

    std::cout << std::endl;

    // Błędna składnia pętli for - brak warunku
    for (int i = 0; ; i++) {
        std::cout << i*i << " ";
    }

    return 0;
}
```
