#include <iostream>
#include <string>

bool czyPalindrom(std::string tekst)
{
    int left = 0;
    int right = static_cast<int>(tekst.length()) - 1;

    while (left < right)
    {
        if (tekst[left] != tekst[right])
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main()
{
    std::string tekst;

    std::cout << "Podaj tekst: ";
    std::cin >> tekst;

    if (czyPalindrom(tekst))
    {
        std::cout << "To jest palindrom" << std::endl;
    }
    else
    {
        std::cout << "To nie jest palindrom" << std::endl;
    }

    return 0;
}
