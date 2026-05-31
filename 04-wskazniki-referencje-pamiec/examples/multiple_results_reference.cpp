#include <iostream>

void sumaIIloczyn(int a, int b, int& suma, int& iloczyn)
{
    suma = a + b;
    iloczyn = a * b;
}

int main()
{
    int suma = 0;
    int iloczyn = 0;

    sumaIIloczyn(3, 4, suma, iloczyn);

    std::cout << "Suma: " << suma << std::endl;
    std::cout << "Iloczyn: " << iloczyn << std::endl;

    return 0;
}
