#include <iostream>
#include <string>

char encryptGaderypolukiChar(char znak)
{
    const std::string klucz = "GADERYPOLUKI";

    for (std::size_t i = 0; i + 1 < klucz.size(); i += 2)
    {
        if (znak == klucz[i])
        {
            return klucz[i + 1];
        }
        if (znak == klucz[i + 1])
        {
            return klucz[i];
        }
    }

    return znak;
}

std::string encryptGaderypoluki(const std::string& text)
{
    std::string result;

    for (char znak : text)
    {
        result += encryptGaderypolukiChar(znak);
    }

    return result;
}

bool expectEqual(const std::string& nazwa, const std::string& wynik, const std::string& oczekiwane)
{
    if (wynik == oczekiwane)
    {
        return true;
    }

    std::cout << "FAIL " << nazwa << ": oczekiwano '" << oczekiwane
              << "', otrzymano '" << wynik << "'" << std::endl;
    return false;
}

int main()
{
    bool ok = true;

    ok = expectEqual("PROGRAM", encryptGaderypoluki("PROGRAM"), "OYPAYGM") && ok;
    ok = expectEqual("pary klucza", encryptGaderypoluki("GADERYPOLUKI"), "AGEDYROPULIK") && ok;
    ok = expectEqual("znaki spoza klucza", encryptGaderypoluki("ALA 123"), "GUG 123") && ok;
    ok = expectEqual("pusty tekst", encryptGaderypoluki(""), "") && ok;

    if (!ok)
    {
        return 1;
    }

    std::cout << "Wszystkie testy szyfru GADERYPOLUKI przeszly" << std::endl;
    return 0;
}
