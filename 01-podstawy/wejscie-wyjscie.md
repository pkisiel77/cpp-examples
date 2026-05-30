
[cout part 1](https://youtu.be/yoj8nKbPFVE)

[add two integers](https://user-images.githubusercontent.com/26519123/234231187-fb067042-475d-4519-a728-26aa0af68cf9.mp4)

### std::endl

`std::endl` to manipulator strumienia w C++, który wstawia znak nowej linii (`'\n'`) do strumienia wyjściowego, a następnie opróżnia ten strumien (wymusza operację flush). Jest to często używane podczas pracy z operacjami wejścia/wyjścia.

Na przykład, możemy użyć `std::endl` w następujący sposób:

```cpp
#include <iostream>

int main() {
    std::cout << "Witaj, świecie!" << std::endl;
    return 0;
}
```

W tym kodzie, "Witaj, świecie!" jest wyświetlane na konsoli, a potem następuje nowa linia dzięki `std::endl`. Warto jednak zauważyć, że używanie `std::endl` może być nieco mniej wydajne niż użycie zwykłego znaku nowej linii (`'\n'`), ponieważ wymusza opróżnienie bufora. W zależności od kontekstu, może to być niepotrzebne.

