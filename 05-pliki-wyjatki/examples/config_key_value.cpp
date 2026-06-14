#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

std::string trim(const std::string& text) {
    const std::size_t first = text.find_first_not_of(" \t");
    if (first == std::string::npos) {
        return "";
    }

    const std::size_t last = text.find_last_not_of(" \t");
    return text.substr(first, last - first + 1);
}

std::map<std::string, std::string> parseConfig(const std::vector<std::string>& lines) {
    std::map<std::string, std::string> config;

    for (std::size_t lineNumber = 0; lineNumber < lines.size(); ++lineNumber) {
        const std::string line = trim(lines[lineNumber]);
        if (line.empty() || line[0] == '#') {
            continue;
        }

        const std::size_t separator = line.find('=');
        if (separator == std::string::npos) {
            throw std::runtime_error("linia bez znaku =: " + std::to_string(lineNumber + 1));
        }

        const std::string key = trim(line.substr(0, separator));
        const std::string value = trim(line.substr(separator + 1));

        if (key.empty()) {
            throw std::runtime_error("pusty klucz w linii: " + std::to_string(lineNumber + 1));
        }

        config[key] = value;
    }

    return config;
}

int main() {
    const std::vector<std::string> lines{
        "# konfiguracja aplikacji",
        "host = localhost",
        "port = 8080",
        "debug = true",
        "",
        "log_file = app.log"
    };

    try {
        const std::map<std::string, std::string> config = parseConfig(lines);

        std::cout << "Wczytana konfiguracja:\n";
        for (const auto& item : config) {
            std::cout << item.first << " = " << item.second << '\n';
        }

        std::cout << "\nPort: " << config.at("port") << '\n';
    } catch (const std::exception& ex) {
        std::cout << "Blad konfiguracji: " << ex.what() << '\n';
    }
}
