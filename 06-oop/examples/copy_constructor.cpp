#include <iostream>
#include <string>

class Konto
{
public:
    Konto(std::string wlasciciel, double saldo)
    {
        this->wlasciciel = wlasciciel;
        this->saldo = saldo;
    }

    Konto(const Konto& inne)
    {
        std::cout << "Kopiowanie konta: " << inne.wlasciciel << std::endl;
        wlasciciel = inne.wlasciciel;
        saldo = inne.saldo;
    }

    std::string pobierzWlasciciela() const
    {
        return wlasciciel;
    }

    double pobierzSaldo() const
    {
        return saldo;
    }

    void wplac(double kwota)
    {
        if (kwota > 0)
        {
            saldo += kwota;
        }
    }

private:
    std::string wlasciciel;
    double saldo;
};

int main()
{
    Konto pierwsze("Anna", 100);
    Konto drugie = pierwsze;

    drugie.wplac(50);

    std::cout << pierwsze.pobierzWlasciciela() << ": " << pierwsze.pobierzSaldo() << std::endl;
    std::cout << drugie.pobierzWlasciciela() << ": " << drugie.pobierzSaldo() << std::endl;

    return 0;
}
