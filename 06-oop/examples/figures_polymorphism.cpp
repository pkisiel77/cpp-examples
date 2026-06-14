#include <iomanip>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class Figura {
public:
    virtual ~Figura() = default;

    virtual double pole() const = 0;
    virtual std::string opis() const = 0;
};

class Kwadrat : public Figura {
public:
    explicit Kwadrat(double bok) : bok_(bok) {
        if (bok <= 0.0) {
            throw std::invalid_argument("bok kwadratu musi byc dodatni");
        }
    }

    double pole() const override {
        return bok_ * bok_;
    }

    std::string opis() const override {
        return "Kwadrat";
    }

private:
    double bok_;
};

class Kolo : public Figura {
public:
    explicit Kolo(double promien) : promien_(promien) {
        if (promien <= 0.0) {
            throw std::invalid_argument("promien kola musi byc dodatni");
        }
    }

    double pole() const override {
        return pi * promien_ * promien_;
    }

    std::string opis() const override {
        return "Kolo";
    }

private:
    static constexpr double pi = 3.141592653589793;
    double promien_;
};

double sumaPol(const std::vector<std::unique_ptr<Figura>>& figury) {
    double suma = 0.0;

    for (const auto& figura : figury) {
        suma += figura->pole();
    }

    return suma;
}

int main() {
    std::vector<std::unique_ptr<Figura>> figury;
    figury.push_back(std::make_unique<Kwadrat>(4.0));
    figury.push_back(std::make_unique<Kolo>(2.0));

    std::cout << std::fixed << std::setprecision(3);

    for (const auto& figura : figury) {
        std::cout << figura->opis() << " pole: " << figura->pole() << '\n';
    }

    std::cout << "Suma pol: " << sumaPol(figury) << '\n';
    return 0;
}
