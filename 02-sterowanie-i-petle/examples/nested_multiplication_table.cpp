#include <iostream>

int main()
{
    for (int row = 1; row <= 10; row++)
    {
        for (int col = 1; col <= 10; col++)
        {
            std::cout << row * col << '\t';
        }

        std::cout << std::endl;
    }

    return 0;
}
