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
        std::cout << "Powstaje kopia konta: " << inne.wlasciciel << std::endl;
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

private:
    std::string wlasciciel;
    double saldo;
};

void wypiszPrzezWartosc(Konto konto)
{
    std::cout << "Przez wartosc: " << konto.pobierzWlasciciela()
              << ", saldo: " << konto.pobierzSaldo() << std::endl;
}

void wypiszPrzezReferencje(const Konto& konto)
{
    std::cout << "Przez referencje const: " << konto.pobierzWlasciciela()
              << ", saldo: " << konto.pobierzSaldo() << std::endl;
}

int main()
{
    Konto konto("Jan", 250);

    wypiszPrzezWartosc(konto);
    wypiszPrzezReferencje(konto);

    return 0;
}
