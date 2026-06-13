#include <iostream>
#include <string>

class Konto
{
public:
    Konto(std::string wlasciciel, double saldo)
        : wlasciciel_(wlasciciel), saldo_(saldo)
    {
        if (saldo_ < 0.0)
        {
            saldo_ = 0.0;
        }
    }

    const std::string& wlasciciel() const
    {
        return wlasciciel_;
    }

    double saldo() const
    {
        return saldo_;
    }

    bool wplac(double kwota)
    {
        if (kwota <= 0.0)
        {
            return false;
        }

        saldo_ += kwota;
        return true;
    }

    bool wyplac(double kwota)
    {
        if (kwota <= 0.0 || kwota > saldo_)
        {
            return false;
        }

        saldo_ -= kwota;
        return true;
    }

    bool operator==(const Konto& inne) const
    {
        return wlasciciel_ == inne.wlasciciel_ && saldo_ == inne.saldo_;
    }

private:
    std::string wlasciciel_;
    double saldo_;
};

bool expectTrue(const std::string& nazwa, bool warunek)
{
    if (warunek)
    {
        return true;
    }

    std::cout << "FAIL " << nazwa << std::endl;
    return false;
}

bool expectDouble(const std::string& nazwa, double wynik, double oczekiwane)
{
    if (wynik == oczekiwane)
    {
        return true;
    }

    std::cout << "FAIL " << nazwa << ": oczekiwano " << oczekiwane
              << ", otrzymano " << wynik << std::endl;
    return false;
}

bool expectString(const std::string& nazwa, const std::string& wynik, const std::string& oczekiwane)
{
    if (wynik == oczekiwane)
    {
        return true;
    }

    std::cout << "FAIL " << nazwa << ": oczekiwano " << oczekiwane
              << ", otrzymano " << wynik << std::endl;
    return false;
}

int main()
{
    bool ok = true;

    Konto konto{"Anna", 100.0};
    ok = expectString("wlasciciel po konstrukcji", konto.wlasciciel(), "Anna") && ok;
    ok = expectDouble("saldo po konstrukcji", konto.saldo(), 100.0) && ok;

    ok = expectTrue("wplata poprawna", konto.wplac(50.0)) && ok;
    ok = expectDouble("saldo po wplacie", konto.saldo(), 150.0) && ok;

    ok = expectTrue("odrzucona wplata ujemna", !konto.wplac(-10.0)) && ok;
    ok = expectDouble("saldo po blednej wplacie", konto.saldo(), 150.0) && ok;

    ok = expectTrue("wyplata poprawna", konto.wyplac(70.0)) && ok;
    ok = expectDouble("saldo po wyplacie", konto.saldo(), 80.0) && ok;

    ok = expectTrue("odrzucona za duza wyplata", !konto.wyplac(100.0)) && ok;
    ok = expectDouble("saldo po blednej wyplacie", konto.saldo(), 80.0) && ok;

    Konto kontoZNiedozwolonymSaldem{"Jan", -20.0};
    ok = expectDouble("ujemne saldo startowe zamienione na zero", kontoZNiedozwolonymSaldem.saldo(), 0.0) && ok;

    Konto kontoPorownawcze{"Anna", 80.0};
    ok = expectTrue("operator porownania", konto == kontoPorownawcze) && ok;

    if (!ok)
    {
        return 1;
    }

    std::cout << "Wszystkie testy OOP przeszly" << std::endl;
    return 0;
}
