#include <iostream>

class Konto
{
public:
    Konto(double saldoPoczatkowe)
    {
        if (saldoPoczatkowe >= 0)
        {
            saldo = saldoPoczatkowe;
        }
        else
        {
            saldo = 0;
        }
    }

    double pobierzSaldo()
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

    void wyplac(double kwota)
    {
        if (kwota > 0 && kwota <= saldo)
        {
            saldo -= kwota;
        }
    }

private:
    double saldo;
};

int main()
{
    Konto konto(100);

    konto.wplac(50);
    konto.wyplac(30);
    konto.wyplac(500);

    std::cout << "Saldo: " << konto.pobierzSaldo() << std::endl;

    return 0;
}
