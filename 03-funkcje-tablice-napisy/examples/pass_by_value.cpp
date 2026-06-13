#include <iostream>

void zmien(int liczba)
{
    liczba = 100;
    std::cout << "wartosc lokalna w funkcji: " << liczba << std::endl;
}

int main()
{
    int x = 5;

    zmien(x);

    std::cout << "x po wywolaniu funkcji: " << x << std::endl;
    return 0;
}
