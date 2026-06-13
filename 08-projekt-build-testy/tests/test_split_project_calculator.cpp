#include <cstdlib>
#include <iostream>
#include <string>

#include "../examples/split-project/calculator.h"

void sprawdzRownosc(const std::string& opis, int aktualna, int oczekiwana) {
    if (aktualna != oczekiwana) {
        std::cerr << "Blad testu: " << opis
                  << ", oczekiwano " << oczekiwana
                  << ", otrzymano " << aktualna << '\n';
        std::exit(1);
    }
}

int main() {
    sprawdzRownosc("dodawanie liczb dodatnich", add(2, 3), 5);
    sprawdzRownosc("dodawanie liczby ujemnej", add(-4, 9), 5);
    sprawdzRownosc("dodawanie zer", add(0, 0), 0);

    sprawdzRownosc("odejmowanie liczb dodatnich", subtract(10, 4), 6);
    sprawdzRownosc("odejmowanie z wynikiem ujemnym", subtract(3, 8), -5);
    sprawdzRownosc("odejmowanie liczby ujemnej", subtract(3, -2), 5);

    sprawdzRownosc("mnozenie liczb dodatnich", multiply(6, 7), 42);
    sprawdzRownosc("mnozenie przez zero", multiply(9, 0), 0);
    sprawdzRownosc("mnozenie liczby ujemnej", multiply(-3, 5), -15);

    std::cout << "Wszystkie testy split-project calculator przeszly\n";
    return 0;
}
