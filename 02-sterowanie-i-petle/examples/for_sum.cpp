#include <iostream>

int main()
{
    int suma = 0;

    for (int i = 1; i <= 100; i++)
    {
        suma += i;
    }

    std::cout << "Suma liczb od 1 do 100: " << suma << std::endl;
    return 0;
}
