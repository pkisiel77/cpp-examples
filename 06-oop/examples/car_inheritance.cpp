#include <iostream>
#include <string>

class Samochod
{
public:
    Samochod(std::string marka, std::string model, int rokProdukcji)
    {
        this->marka = marka;
        this->model = model;
        this->rokProdukcji = rokProdukcji;
    }

    std::string opis() const
    {
        return marka + " " + model + ", rok: " + std::to_string(rokProdukcji);
    }

private:
    std::string marka;
    std::string model;
    int rokProdukcji;
};

class SportowySamochod : public Samochod
{
public:
    SportowySamochod(std::string marka, std::string model, int rokProdukcji, int maksymalnaPredkosc)
        : Samochod(marka, model, rokProdukcji)
    {
        if (maksymalnaPredkosc > 0)
        {
            this->maksymalnaPredkosc = maksymalnaPredkosc;
        }
        else
        {
            this->maksymalnaPredkosc = 0;
        }
    }

    void turbo(int wzrost)
    {
        if (wzrost > 0)
        {
            maksymalnaPredkosc += wzrost;
        }
    }

    int pobierzMaksymalnaPredkosc() const
    {
        return maksymalnaPredkosc;
    }

private:
    int maksymalnaPredkosc;
};

int main()
{
    SportowySamochod auto1("Porsche", "911", 2022, 310);

    auto1.turbo(20);
    auto1.turbo(-100);

    std::cout << auto1.opis() << std::endl;
    std::cout << "Maksymalna predkosc: " << auto1.pobierzMaksymalnaPredkosc() << " km/h" << std::endl;

    return 0;
}
