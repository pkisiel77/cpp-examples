#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

struct CsvRecord {
    std::vector<std::string> fields;
};

std::vector<std::string> parseCsvLine(const std::string& line) {
    std::vector<std::string> fields;
    std::string current;
    bool inQuotes = false;

    for (std::size_t i = 0; i < line.size(); ++i) {
        const char ch = line[i];

        if (ch == '"') {
            if (inQuotes && i + 1 < line.size() && line[i + 1] == '"') {
                current.push_back('"');
                ++i;
            } else {
                inQuotes = !inQuotes;
            }
            continue;
        }

        if (ch == ',' && !inQuotes) {
            fields.push_back(current);
            current.clear();
            continue;
        }

        current.push_back(ch);
    }

    if (inQuotes) {
        throw std::runtime_error("brak zamykajacego cudzyslowu");
    }

    fields.push_back(current);
    return fields;
}

class CsvTable {
public:
    explicit CsvTable(std::vector<std::string> headers) : headers_(std::move(headers)) {}

    bool addRecord(CsvRecord record) {
        if (record.fields.size() != headers_.size()) {
            return false;
        }

        records_.push_back(std::move(record));
        return true;
    }

    std::optional<std::size_t> columnIndex(const std::string& name) const {
        for (std::size_t i = 0; i < headers_.size(); ++i) {
            if (headers_[i] == name) {
                return i;
            }
        }

        return std::nullopt;
    }

    std::vector<CsvRecord> filterEquals(const std::string& columnName, const std::string& value) const {
        const std::optional<std::size_t> index = columnIndex(columnName);
        if (!index.has_value()) {
            return {};
        }

        std::vector<CsvRecord> result;
        for (const CsvRecord& record : records_) {
            if (record.fields[*index] == value) {
                result.push_back(record);
            }
        }
        return result;
    }

    const std::vector<std::string>& headers() const {
        return headers_;
    }

    const std::vector<CsvRecord>& records() const {
        return records_;
    }

private:
    std::vector<std::string> headers_;
    std::vector<CsvRecord> records_;
};

void printRecords(const CsvTable& table, const std::vector<CsvRecord>& records) {
    for (const std::string& header : table.headers()) {
        std::cout << header << '\t';
    }
    std::cout << '\n';

    for (const CsvRecord& record : records) {
        for (const std::string& field : record.fields) {
            std::cout << field << '\t';
        }
        std::cout << '\n';
    }
}

int main() {
    CsvTable table{parseCsvLine("name,city,grade")};

    table.addRecord(CsvRecord{parseCsvLine("\"Kowalski, Jan\",Warsaw,4.5")});
    table.addRecord(CsvRecord{parseCsvLine("Anna,,5.0")});
    table.addRecord(CsvRecord{parseCsvLine("Piotr,Krakow,3.5")});

    std::cout << "Wszystkie rekordy:\n";
    printRecords(table, table.records());

    std::cout << "\nRekordy z city == Warsaw:\n";
    printRecords(table, table.filterEquals("city", "Warsaw"));
}
