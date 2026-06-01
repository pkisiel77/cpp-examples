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

void wypiszKonto(const Konto& konto)
{
    std::cout << konto.pobierzWlasciciela() << ": "
              << konto.pobierzSaldo() << std::endl;
}

int main()
{
    Konto konto("Anna", 200);
    konto.wplac(50);

    wypiszKonto(konto);

    return 0;
}
