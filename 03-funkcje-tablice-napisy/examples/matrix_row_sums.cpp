#include <iostream>

int main()
{
    const int rows = 3;
    const int cols = 3;

    int macierz[rows][cols] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (int row = 0; row < rows; row++)
    {
        int sumaWiersza = 0;

        for (int col = 0; col < cols; col++)
        {
            sumaWiersza += macierz[row][col];
        }

        std::cout << "Suma wiersza " << row << ": " << sumaWiersza << std::endl;
    }

    return 0;
}
