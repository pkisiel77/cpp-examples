#include <iostream>
#include <stdexcept>

int main()
{
    try
    {
        throw std::runtime_error("Operacja nie powiodla sie");
    }
    catch (const std::runtime_error& blad)
    {
        std::cout << "Blad: " << blad.what() << std::endl;
    }

    return 0;
}
