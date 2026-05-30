#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Liczba argumentow: " << argc << std::endl;

    for (int i = 0; i < argc; ++i)
    {
        std::cout << i << ": " << argv[i] << std::endl;
    }

    return 0;
}
