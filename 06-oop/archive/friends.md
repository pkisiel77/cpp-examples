Poniżej znajduje się przykład wykorzystania klasy zaprzyjaźnionej. W tym przykładzie klasa Printer jest zaprzyjaźniona z klasą SecretData, dzięki czemu może uzyskać dostęp do jej prywatnych danych.

```cpp
#include<iostream>

class SecretData {
private:
    int secretNumber;
public:
    SecretData() : secretNumber(42) {}

    // Zadeklarowanie klasy Printer jako zaprzyjaźnionej
    friend class Printer;
};

class Printer {
public:
    void printSecret(const SecretData& data) {
        std::cout << "Sekretne dane: " << data.secretNumber << std::endl;
    }
};

int main() {
    SecretData data;
    Printer printer;
    printer.printSecret(data);

    return 0;
}

```
W tym kodzie, Printer jest w stanie uzyskać dostęp do prywatnego pola secretNumber z klasy SecretData, pomimo tego, że jest ono prywatne. Bez deklaracji klasy Printer jako klasy zaprzyjaźnionej, taki dostęp byłby niemożliwy.
