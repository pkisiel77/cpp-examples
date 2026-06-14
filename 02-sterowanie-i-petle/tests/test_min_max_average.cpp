#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Statistics {
    bool hasValues;
    double minimum;
    double maximum;
    double average;
    int count;
};

bool tryParseDouble(const std::string& text, double& value) {
    std::istringstream input(text);
    input >> value;
    return input && input.eof();
}

Statistics calculateStatistics(const std::vector<double>& values) {
    if (values.empty()) {
        return Statistics{false, 0.0, 0.0, 0.0, 0};
    }

    double minimum = values[0];
    double maximum = values[0];
    double sum = 0.0;

    for (double value : values) {
        if (value < minimum) {
            minimum = value;
        }
        if (value > maximum) {
            maximum = value;
        }
        sum += value;
    }

    return Statistics{true, minimum, maximum, sum / static_cast<int>(values.size()), static_cast<int>(values.size())};
}

void sprawdz(bool warunek, const std::string& opis) {
    if (!warunek) {
        std::cerr << "Blad testu: " << opis << '\n';
        std::exit(1);
    }
}

int main() {
    double value = 0.0;

    sprawdz(tryParseDouble("10", value) && value == 10.0, "parsowanie liczby calkowitej");
    sprawdz(tryParseDouble("-2.5", value) && value == -2.5, "parsowanie liczby ujemnej");
    sprawdz(!tryParseDouble("abc", value), "odrzucenie tekstu");
    sprawdz(!tryParseDouble("10abc", value), "odrzucenie czesciowego dopasowania");

    const Statistics many = calculateStatistics({10.0, -2.5, 4.5});
    sprawdz(many.hasValues, "statystyki maja dane");
    sprawdz(many.count == 3, "licznik wartosci");
    sprawdz(many.minimum == -2.5, "minimum");
    sprawdz(many.maximum == 10.0, "maksimum");
    sprawdz(many.average == 4.0, "srednia");

    const Statistics one = calculateStatistics({7.0});
    sprawdz(one.hasValues, "jedna wartosc istnieje");
    sprawdz(one.minimum == 7.0, "minimum dla jednej wartosci");
    sprawdz(one.maximum == 7.0, "maksimum dla jednej wartosci");
    sprawdz(one.average == 7.0, "srednia dla jednej wartosci");

    const Statistics empty = calculateStatistics({});
    sprawdz(!empty.hasValues, "pusty zbior nie ma statystyk");
    sprawdz(empty.count == 0, "pusty licznik");

    std::cout << "Wszystkie testy min/max/srednia przeszly\n";
    return 0;
}
