#include <iostream>
#include <queue>
#include <stack>
#include <string>

int main()
{
    std::stack<std::string> historia;
    historia.push("Dodano rekord");
    historia.push("Zmieniono rekord");
    historia.push("Usunieto rekord");

    std::cout << "Cofanie operacji:" << std::endl;
    while (!historia.empty())
    {
        std::cout << historia.top() << std::endl;
        historia.pop();
    }

    std::queue<std::string> zgloszenia;
    zgloszenia.push("Zgloszenie 1");
    zgloszenia.push("Zgloszenie 2");
    zgloszenia.push("Zgloszenie 3");

    std::cout << "Obsluga zgloszen:" << std::endl;
    while (!zgloszenia.empty())
    {
        std::cout << zgloszenia.front() << std::endl;
        zgloszenia.pop();
    }

    return 0;
}
