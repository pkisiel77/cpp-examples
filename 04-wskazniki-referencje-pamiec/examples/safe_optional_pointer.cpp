#include <iostream>

void zwiekszJesliIstnieje(int* liczba)
{
    if (liczba != nullptr)
    {
        (*liczba)++;
    }
}

void zwieksz(int& liczba)
{
    liczba++;
}

int main()
{
    int a = 10;
    int b = 20;
    int* pusty = nullptr;

    zwiekszJesliIstnieje(&a);
    zwiekszJesliIstnieje(pusty);
    zwieksz(b);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    return 0;
}
