#include <iostream>

int main()
{
    int liczba = 10;
    int& ref = liczba;

    ref = 20;

    std::cout << "liczba: " << liczba << std::endl;
    std::cout << "ref: " << ref << std::endl;

    return 0;
}
