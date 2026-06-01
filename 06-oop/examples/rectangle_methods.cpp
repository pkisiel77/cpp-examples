#include <iostream>

class Prostokat
{
public:
    double szerokosc;
    double wysokosc;

    double pole()
    {
        return szerokosc * wysokosc;
    }

    double obwod()
    {
        return 2 * szerokosc + 2 * wysokosc;
    }
};

int main()
{
    Prostokat prostokat;
    prostokat.szerokosc = 5;
    prostokat.wysokosc = 3;

    std::cout << "Pole: " << prostokat.pole() << std::endl;
    std::cout << "Obwod: " << prostokat.obwod() << std::endl;

    return 0;
}
