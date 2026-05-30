#include <iostream>

int main()
{
    const int rows = 2;
    const int cols = 3;

    int macierz[rows][cols] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int suma = 0;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            suma += macierz[row][col];
        }
    }

    std::cout << "Suma: " << suma << std::endl;
    return 0;
}
