#include <iomanip>
#include <iostream>

double obliczBmi(double masa, double wzrost)
{
    return masa / (wzrost * wzrost);
}

int main()
{
    double masa = 72.0;
    double wzrost = 1.80;
    double bmi = obliczBmi(masa, wzrost);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "BMI: " << bmi << std::endl;
    return 0;
}
