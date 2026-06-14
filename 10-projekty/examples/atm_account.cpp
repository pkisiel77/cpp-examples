#include <iostream>
#include <string>
#include <utility>
#include <vector>

enum class TransactionType {
    Deposit,
    Withdrawal,
    PinChange
};

struct Transaction {
    TransactionType type;
    double amount;
    std::string description;
};

class Account {
public:
    Account(std::string id, std::string pin, double balance)
        : id_(std::move(id)), pin_(std::move(pin)), balance_(balance) {}

    const std::string& id() const {
        return id_;
    }

    bool verifyPin(const std::string& pin) const {
        return pin == pin_;
    }

    double balance() const {
        return balance_;
    }

    bool deposit(double amount) {
        if (amount <= 0.0) {
            return false;
        }

        balance_ += amount;
        history_.push_back(Transaction{TransactionType::Deposit, amount, "wplata"});
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0.0 || amount > balance_) {
            return false;
        }

        balance_ -= amount;
        history_.push_back(Transaction{TransactionType::Withdrawal, amount, "wyplata"});
        return true;
    }

    bool changePin(const std::string& oldPin, const std::string& newPin) {
        if (!verifyPin(oldPin) || newPin.size() != 4) {
            return false;
        }

        pin_ = newPin;
        history_.push_back(Transaction{TransactionType::PinChange, 0.0, "zmiana PIN"});
        return true;
    }

    const std::vector<Transaction>& history() const {
        return history_;
    }

private:
    std::string id_;
    std::string pin_;
    double balance_;
    std::vector<Transaction> history_;
};

int main() {
    Account account{"ACC-001", "1234", 500.0};

    std::cout << "Konto: " << account.id() << '\n';
    std::cout << "PIN 1111 poprawny? " << std::boolalpha << account.verifyPin("1111") << '\n';
    std::cout << "PIN 1234 poprawny? " << account.verifyPin("1234") << '\n';

    account.deposit(150.0);
    account.withdraw(80.0);

    if (!account.withdraw(1000.0)) {
        std::cout << "Odmowa wyplaty: za malo srodkow albo bledna kwota\n";
    }

    if (account.changePin("1234", "4321")) {
        std::cout << "PIN zostal zmieniony\n";
    }

    std::cout << "Saldo: " << account.balance() << '\n';
    std::cout << "Liczba operacji w historii: " << account.history().size() << '\n';
}
