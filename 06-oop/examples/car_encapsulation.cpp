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
        przebieg = 0;
    }

    void jedz(int kilometry)
    {
        if (kilometry > 0)
        {
            przebieg += kilometry;
        }
    }

    void wypiszInformacje()
    {
        std::cout << marka << " " << model << ", rok: " << rokProdukcji
                  << ", przebieg: " << przebieg << " km" << std::endl;
    }

private:
    std::string marka;
    std::string model;
    int rokProdukcji;
    int przebieg;
};

int main()
{
    Samochod auto1("Toyota", "Corolla", 2020);

    auto1.jedz(120);
    auto1.jedz(-50);
    auto1.wypiszInformacje();

    return 0;
}
