#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> uczestnicy = {"Anna", "Jan", "Ewa"};
    std::map<std::string, int> punkty = {{"Anna", 12}, {"Jan", 9}, {"Ewa", 15}};
    std::queue<std::string> kolejkaZgloszen;

    kolejkaZgloszen.push("Zgloszenie 1");
    kolejkaZgloszen.push("Zgloszenie 2");

    std::cout << "Uczestnicy:" << std::endl;
    for (const auto& uczestnik : uczestnicy)
    {
        std::cout << uczestnik << " ma punktow: " << punkty[uczestnik] << std::endl;
    }

    std::cout << "Pierwsze do obslugi: " << kolejkaZgloszen.front() << std::endl;

    return 0;
}
