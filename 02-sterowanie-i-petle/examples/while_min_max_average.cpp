#include <iostream>
#include <sstream>
#include <string>

bool tryParseDouble(const std::string& text, double& value) {
    std::istringstream input(text);
    input >> value;
    return input && input.eof();
}

int main() {
    double minimum = 0.0;
    double maximum = 0.0;
    double sum = 0.0;
    int count = 0;

    while (true) {
        std::cout << "Podaj liczbe albo q, aby zakonczyc: ";

        std::string line;
        std::getline(std::cin, line);

        if (line.empty() || line == "q" || line == "koniec") {
            break;
        }

        double value = 0.0;
        if (!tryParseDouble(line, value)) {
            std::cout << "To nie jest poprawna liczba.\n";
            continue;
        }

        if (count == 0) {
            minimum = value;
            maximum = value;
        } else {
            if (value < minimum) {
                minimum = value;
            }
            if (value > maximum) {
                maximum = value;
            }
        }

        sum += value;
        ++count;
    }

    if (count == 0) {
        std::cout << "Nie podano zadnej liczby.\n";
        return 0;
    }

    std::cout << "Liczba wartosci: " << count << '\n';
    std::cout << "Minimum: " << minimum << '\n';
    std::cout << "Maksimum: " << maximum << '\n';
    std::cout << "Srednia: " << (sum / count) << '\n';
    return 0;
}
