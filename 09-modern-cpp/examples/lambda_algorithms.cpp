#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Order {
    std::string customer;
    double total;
    bool paid;
};

void printOrders(const std::vector<Order>& orders) {
    for (const auto& order : orders) {
        std::cout << "  " << order.customer
                  << ": " << order.total
                  << ", paid: " << (order.paid ? "yes" : "no") << '\n';
    }
}

int main() {
    std::vector<Order> orders{
        {"Anna", 240.0, true},
        {"Jan", 75.5, false},
        {"Maria", 310.0, true},
        {"Piotr", 120.0, false},
    };

    std::sort(orders.begin(), orders.end(),
              [](const Order& left, const Order& right) {
                  return left.total > right.total;
              });

    std::cout << "Orders sorted by total:\n";
    printOrders(orders);

    const double minimumTotal{150.0};
    std::vector<Order> largeOrders;

    std::copy_if(orders.begin(), orders.end(), std::back_inserter(largeOrders),
                 [minimumTotal](const Order& order) {
                     return order.total >= minimumTotal;
                 });

    std::cout << "\nLarge orders:\n";
    printOrders(largeOrders);

    const auto unpaidIt = std::find_if(orders.begin(), orders.end(),
                                       [](const Order& order) {
                                           return !order.paid;
                                       });

    if (unpaidIt != orders.end()) {
        std::cout << "\nFirst unpaid order: " << unpaidIt->customer << '\n';
    }

    const auto paidCount = std::count_if(orders.begin(), orders.end(),
                                         [](const Order& order) {
                                             return order.paid;
                                         });

    std::cout << "Paid orders: " << paidCount << '\n';
    return 0;
}
