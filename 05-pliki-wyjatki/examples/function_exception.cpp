#include <iostream>
#include <stdexcept>

double podziel(double a, double b)
{
    if (b == 0)
    {
        throw std::invalid_argument("Nie wolno dzielic przez zero");
    }

    return a / b;
}

int main()
{
    try
    {
        std::cout << podziel(10, 2) << std::endl;
        std::cout << podziel(10, 0) << std::endl;
    }
    catch (const std::invalid_argument& blad)
    {
        std::cout << "Niepoprawny argument: " << blad.what() << std::endl;
    }

    return 0;
}
