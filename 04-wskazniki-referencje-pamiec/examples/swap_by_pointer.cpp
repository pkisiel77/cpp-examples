#include <iostream>

void zamien(int* a, int* b)
{
    if (a == nullptr || b == nullptr)
    {
        return;
    }

    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x = 10;
    int y = 20;

    zamien(&x, &y);

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;

    return 0;
}
