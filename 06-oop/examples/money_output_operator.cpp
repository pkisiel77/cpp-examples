#include <iomanip>
#include <iostream>

class Kwota
{
public:
    Kwota(int zlote, int grosze)
    {
        int razemGrosze = zlote * 100 + grosze;

        this->zlote = razemGrosze / 100;
        this->grosze = razemGrosze % 100;
    }

    int pobierzZlote() const
    {
        return zlote;
    }

    int pobierzGrosze() const
    {
        return grosze;
    }

    Kwota operator+(const Kwota& inna) const
    {
        return Kwota(zlote + inna.zlote, grosze + inna.grosze);
    }

private:
    int zlote;
    int grosze;
};

std::ostream& operator<<(std::ostream& out, const Kwota& kwota)
{
    out << kwota.pobierzZlote() << ","
        << std::setw(2) << std::setfill('0') << kwota.pobierzGrosze()
        << " zl";
    return out;
}

int main()
{
    Kwota pierwsza(10, 75);
    Kwota druga(5, 80);
    Kwota suma = pierwsza + druga;

    std::cout << pierwsza << " + " << druga << " = " << suma << std::endl;

    return 0;
}
