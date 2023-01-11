## Opis

- https://edu.pjwstk.edu.pl/wyklady/pro/scb/PRG2CPP_files/node142.html
- https://cpp0x.pl/kursy/Kurs-STL-C++/Wstep-podstawowe-informacje-o-STL-u/115
- https://www.youtube.com/watch?v=M8EDrK4joTc&ab_channel=CppCon


## vector

### Resize
```cpp
#include <iostream>
#include <vector>
 
int main()
{
    std::vector<int> c = {1, 2, 3};
    std::cout << "The vector holds: ";
    for (const auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
 
    c.resize(5);
    std::cout << "After resize up to 5: ";
    for (const auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
 
    c.resize(2);
    std::cout << "After resize down to 2: ";
    for (const auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
 
    c.resize(6, 4);
    std::cout << "After resize up to 6 (initializer = 4): ";
    for (const auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
}
```



