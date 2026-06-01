#include <iostream>

class Punkt
{
public:
    int x;
    int y;
};

int main()
{
    Punkt pierwszy;
    pierwszy.x = 10;
    pierwszy.y = 20;

    Punkt drugi;
    drugi.x = -5;
    drugi.y = 7;

    std::cout << "Pierwszy punkt: " << pierwszy.x << ", " << pierwszy.y << std::endl;
    std::cout << "Drugi punkt: " << drugi.x << ", " << drugi.y << std::endl;

    return 0;
}
