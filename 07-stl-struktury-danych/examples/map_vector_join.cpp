#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Employee {
    int id;
    std::string name;
    int departmentId;
    double salary;
};

int main() {
    const std::map<int, std::string> departments{
        {10, "IT"},
        {20, "Sprzedaz"},
        {30, "Administracja"}
    };

    const std::vector<Employee> employees{
        {1, "Anna", 10, 7200.0},
        {2, "Piotr", 20, 6100.0},
        {3, "Maria", 10, 8300.0},
        {4, "Tomasz", 40, 5500.0}
    };

    std::map<int, double> salaryByDepartment;

    std::cout << "Pracownicy z nazwa dzialu:\n";
    for (const Employee& employee : employees) {
        const auto department = departments.find(employee.departmentId);
        const std::string departmentName = department == departments.end() ? "Nieznany dzial" : department->second;

        std::cout << employee.id << ". " << employee.name << " | " << departmentName << " | " << employee.salary << '\n';
        salaryByDepartment[employee.departmentId] += employee.salary;
    }

    std::cout << "\nSuma wynagrodzen wedlug dzialu:\n";
    for (const auto& item : salaryByDepartment) {
        const auto department = departments.find(item.first);
        const std::string departmentName = department == departments.end() ? "Nieznany dzial" : department->second;
        std::cout << departmentName << ": " << item.second << '\n';
    }
}
