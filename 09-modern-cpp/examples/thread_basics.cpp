#include <iostream>
#include <functional>
#include <mutex>
#include <string>
#include <thread>

class SafeCounter {
public:
    void add(int value) {
        std::lock_guard<std::mutex> lock{mutex};
        total += value;
    }

    int getTotal() const {
        std::lock_guard<std::mutex> lock{mutex};
        return total;
    }

private:
    mutable std::mutex mutex;
    int total = 0;
};

void addMany(SafeCounter& counter, const std::string& name, int times) {
    for (int i = 0; i < times; ++i) {
        counter.add(1);
    }

    std::cout << name << " finished\n";
}

int main() {
    SafeCounter counter;

    std::thread first{addMany, std::ref(counter), "first thread", 1000};
    std::thread second{addMany, std::ref(counter), "second thread", 1000};

    first.join();
    second.join();

    std::cout << "Total: " << counter.getTotal() << '\n';
    return 0;
}
