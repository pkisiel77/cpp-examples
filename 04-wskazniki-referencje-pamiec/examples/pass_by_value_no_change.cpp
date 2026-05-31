#include <iostream>

void ustawNaZero(int liczba)
{
    liczba = 0;
}

int main()
{
    int x = 5;

    ustawNaZero(x);

    std::cout << "x: " << x << std::endl;
    return 0;
}
