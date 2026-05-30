#include <iostream>

int dodaj(int a, int b);

int main()
{
    int wynik = dodaj(2, 3);
    std::cout << "Wynik: " << wynik << std::endl;
    return 0;
}

int dodaj(int a, int b)
{
    return a + b;
}
