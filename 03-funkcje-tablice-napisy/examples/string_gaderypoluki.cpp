#include <iostream>
#include <string>

char encryptGaderypolukiChar(char znak) {
    const std::string klucz = "GADERYPOLUKI";

    for (std::size_t i = 0; i + 1 < klucz.size(); i += 2) {
        if (znak == klucz[i]) {
            return klucz[i + 1];
        }
        if (znak == klucz[i + 1]) {
            return klucz[i];
        }
    }

    return znak;
}

std::string encryptGaderypoluki(const std::string& text) {
    std::string result;

    for (char znak : text) {
        result += encryptGaderypolukiChar(znak);
    }

    return result;
}

int main() {
    const std::string text = "PROGRAM 123";
    const std::string encrypted = encryptGaderypoluki(text);

    std::cout << "Tekst: " << text << '\n';
    std::cout << "Szyfr: " << encrypted << '\n';
    return 0;
}
