#include <iomanip>
#include <iostream>

int main()
{
    double pi = 3.1415926535;

    std::cout << "Precyzja bez fixed:" << std::endl;
    std::cout << std::setprecision(4) << pi << std::endl;
    std::cout << std::setprecision(8) << pi << std::endl;

    std::cout << "Precyzja z fixed:" << std::endl;
    std::cout << std::fixed << std::setprecision(2) << pi << std::endl;
    std::cout << std::fixed << std::setprecision(5) << pi << std::endl;

    return 0;
}
