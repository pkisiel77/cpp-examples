#include <iostream>
#include <string>

int main()
{
    std::string tekst = "program";

    for (int i = 0; i < static_cast<int>(tekst.length()); i++)
    {
        std::cout << i << ": " << tekst[i] << std::endl;
    }

    return 0;
}
