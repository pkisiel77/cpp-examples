#include <iostream>

void zwieksz(int& liczba)
{
    liczba++;
}

int main()
{
    int x = 5;

    zwieksz(x);

    std::cout << "x: " << x << std::endl;
    return 0;
}
