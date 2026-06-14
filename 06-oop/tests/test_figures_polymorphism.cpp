#include <cmath>
#include <cstdlib>
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

bool expectTrue(const std::string& nazwa, bool warunek) {
    if (warunek) {
        return true;
    }

    std::cout << "FAIL " << nazwa << std::endl;
    return false;
}

bool expectNear(const std::string& nazwa, double wynik, double oczekiwane) {
    if (std::fabs(wynik - oczekiwane) < 0.0001) {
        return true;
    }

    std::cout << "FAIL " << nazwa << ": oczekiwano " << oczekiwane
              << ", otrzymano " << wynik << std::endl;
    return false;
}

int main() {
    bool ok = true;

    Kwadrat kwadrat{4.0};
    ok = expectNear("pole kwadratu", kwadrat.pole(), 16.0) && ok;
    ok = expectTrue("opis kwadratu", kwadrat.opis() == "Kwadrat") && ok;

    Kolo kolo{2.0};
    ok = expectNear("pole kola", kolo.pole(), 12.566370614359172) && ok;
    ok = expectTrue("opis kola", kolo.opis() == "Kolo") && ok;

    std::vector<std::unique_ptr<Figura>> figury;
    figury.push_back(std::make_unique<Kwadrat>(4.0));
    figury.push_back(std::make_unique<Kolo>(2.0));

    ok = expectNear("suma pol", sumaPol(figury), 28.566370614359172) && ok;
    ok = expectTrue("wywolanie polimorficzne opisu", figury[0]->opis() == "Kwadrat") && ok;

    bool invalidSquareRejected = false;
    try {
        Kwadrat invalid{0.0};
    } catch (const std::invalid_argument&) {
        invalidSquareRejected = true;
    }
    ok = expectTrue("odrzucenie blednego kwadratu", invalidSquareRejected) && ok;

    bool invalidCircleRejected = false;
    try {
        Kolo invalid{-1.0};
    } catch (const std::invalid_argument&) {
        invalidCircleRejected = true;
    }
    ok = expectTrue("odrzucenie blednego kola", invalidCircleRejected) && ok;

    if (!ok) {
        return 1;
    }

    std::cout << "Wszystkie testy figur i polimorfizmu przeszly" << std::endl;
    return 0;
}
