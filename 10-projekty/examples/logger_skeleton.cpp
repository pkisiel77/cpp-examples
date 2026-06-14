#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

enum class LogLevel {
    Info,
    Warning,
    Error
};

std::string toString(LogLevel level) {
    switch (level) {
        case LogLevel::Info:
            return "INFO";
        case LogLevel::Warning:
            return "WARNING";
        case LogLevel::Error:
            return "ERROR";
    }

    return "UNKNOWN";
}

class LogSink {
public:
    virtual ~LogSink() = default;
    virtual void write(const std::string& entry) = 0;
};

class MemorySink : public LogSink {
public:
    void write(const std::string& entry) override {
        entries_.push_back(entry);
    }

    const std::vector<std::string>& entries() const {
        return entries_;
    }

private:
    std::vector<std::string> entries_;
};

class FileSink : public LogSink {
public:
    explicit FileSink(std::string path) : path_(std::move(path)) {}

    void write(const std::string& entry) override {
        std::ofstream file(path_, std::ios::app);
        if (!file) {
            throw std::runtime_error("nie mozna otworzyc pliku logu");
        }

        file << entry << '\n';
    }

private:
    std::string path_;
};

class Logger {
public:
    explicit Logger(LogSink& sink) : sink_(sink) {}

    void log(LogLevel level, const std::string& message) {
        sink_.write("[" + toString(level) + "] " + message);
    }

private:
    LogSink& sink_;
};

int main() {
    MemorySink memorySink;
    Logger memoryLogger(memorySink);

    memoryLogger.log(LogLevel::Info, "Start programu");
    memoryLogger.log(LogLevel::Warning, "Brak opcjonalnej konfiguracji");
    memoryLogger.log(LogLevel::Error, "Przyklad bledu");

    for (const std::string& entry : memorySink.entries()) {
        std::cout << entry << '\n';
    }

    FileSink fileSink{"/tmp/cpp-examples-logger-demo.log"};
    Logger fileLogger(fileSink);
    fileLogger.log(LogLevel::Info, "Ten wpis trafi do pliku");
}
