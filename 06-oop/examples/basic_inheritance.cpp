#include <iostream>
#include <string>

class Pracownik
{
public:
    Pracownik(std::string imie, int pensja)
    {
        this->imie = imie;
        this->pensja = pensja;
    }

    std::string opis() const
    {
        return imie + ", pensja: " + std::to_string(pensja);
    }

private:
    std::string imie;
    int pensja;
};

class Menedzer : public Pracownik
{
public:
    Menedzer(std::string imie, int pensja, int liczbaOsob)
        : Pracownik(imie, pensja)
    {
        this->liczbaOsob = liczbaOsob;
    }

    std::string opisZespolu() const
    {
        return "Liczba osob w zespole: " + std::to_string(liczbaOsob);
    }

private:
    int liczbaOsob;
};

int main()
{
    Pracownik pracownik("Anna", 6000);
    Menedzer menedzer("Jan", 9000, 5);

    std::cout << pracownik.opis() << std::endl;
    std::cout << menedzer.opis() << std::endl;
    std::cout << menedzer.opisZespolu() << std::endl;

    return 0;
}
