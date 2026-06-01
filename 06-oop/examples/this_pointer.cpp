#include <iostream>
#include <string>

class Produkt
{
public:
    Produkt(std::string nazwa, double cena, int ilosc)
    {
        this->nazwa = nazwa;
        this->cena = cena;
        this->ilosc = ilosc;
    }

    std::string pobierzNazwe() const
    {
        return nazwa;
    }

    double wartosc() const
    {
        return cena * ilosc;
    }

    void ustawIlosc(int ilosc)
    {
        if (ilosc >= 0)
        {
            this->ilosc = ilosc;
        }
    }

private:
    std::string nazwa;
    double cena;
    int ilosc;
};

int main()
{
    Produkt produkt("Monitor", 899.99, 2);

    std::cout << produkt.pobierzNazwe() << ": " << produkt.wartosc() << std::endl;

    produkt.ustawIlosc(3);
    std::cout << produkt.pobierzNazwe() << ": " << produkt.wartosc() << std::endl;

    return 0;
}
