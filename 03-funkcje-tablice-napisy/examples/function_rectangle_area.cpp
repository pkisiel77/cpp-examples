#include <iostream>

double poleProstokata(double szerokosc, double wysokosc)
{
    return szerokosc * wysokosc;
}

int main()
{
    double pole = poleProstokata(4.0, 2.5);
    std::cout << "Pole prostokata: " << pole << std::endl;
    return 0;
}
