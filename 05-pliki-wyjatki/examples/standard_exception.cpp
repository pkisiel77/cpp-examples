#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>

int main()
{
    std::vector<int> liczby = {10, 20, 30};

    try
    {
        std::cout << liczby.at(10) << std::endl;
    }
    catch (const std::out_of_range& blad)
    {
        std::cout << "Indeks poza zakresem: " << blad.what() << std::endl;
    }
    catch (const std::exception& blad)
    {
        std::cout << "Inny blad standardowy: " << blad.what() << std::endl;
    }

    return 0;
}
