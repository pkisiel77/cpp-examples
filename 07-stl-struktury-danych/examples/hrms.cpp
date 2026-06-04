#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

class Employee {
public:
    Employee(std::string id, std::string name, std::string surname,
             std::string departmentId, std::string position)
        : id(std::move(id)),
          name(std::move(name)),
          surname(std::move(surname)),
          departmentId(std::move(departmentId)),
          position(std::move(position)) {}

    const std::string& getId() const {
        return id;
    }

    const std::string& getDepartmentId() const {
        return departmentId;
    }

    std::string getFullName() const {
        return name + " " + surname;
    }

    const std::string& getPosition() const {
        return position;
    }

private:
    std::string id;
    std::string name;
    std::string surname;
    std::string departmentId;
    std::string position;
};

class HRMS {
public:
    bool add(const Employee& employee, double salary) {
        if (findEmployee(employee.getId()) != nullptr || salary < 0.0) {
            return false;
        }

        employees.push_back(employee);
        departmentEmployees[employee.getDepartmentId()].push_back(employee.getId());
        salaries[employee.getId()] = salary;
        return true;
    }

    bool changeSalary(const std::string& employeeId, double newSalary) {
        auto salaryIt = salaries.find(employeeId);

        if (salaryIt == salaries.end() || newSalary < 0.0) {
            return false;
        }

        salaryIt->second = newSalary;
        return true;
    }

    void printDepartment(const std::string& departmentId) const {
        auto departmentIt = departmentEmployees.find(departmentId);

        std::cout << "Department " << departmentId << ":\n";
        if (departmentIt == departmentEmployees.end()) {
            std::cout << "  No employees\n";
            return;
        }

        for (const std::string& employeeId : departmentIt->second) {
            const Employee* employee = findEmployee(employeeId);
            if (employee != nullptr) {
                std::cout << "  " << employee->getFullName()
                          << " - " << employee->getPosition() << '\n';
            }
        }
    }

    void printSalaries() const {
        std::cout << "Salaries by employee ID:\n";
        for (const auto& [employeeId, salary] : salaries) {
            std::cout << "  " << employeeId << ": " << salary << '\n';
        }
    }

    void printSalariesSorted() const {
        std::vector<std::pair<std::string, double>> sortedSalaries(
            salaries.begin(), salaries.end());

        std::sort(sortedSalaries.begin(), sortedSalaries.end(),
                  [](const auto& left, const auto& right) {
                      return left.second > right.second;
                  });

        std::cout << "Salaries from highest to lowest:\n";
        for (const auto& [employeeId, salary] : sortedSalaries) {
            const Employee* employee = findEmployee(employeeId);
            if (employee != nullptr) {
                std::cout << "  " << employee->getFullName()
                          << ": " << salary << '\n';
            }
        }
    }

private:
    const Employee* findEmployee(const std::string& employeeId) const {
        auto employeeIt = std::find_if(
            employees.begin(), employees.end(),
            [&employeeId](const Employee& employee) {
                return employee.getId() == employeeId;
            });

        if (employeeIt == employees.end()) {
            return nullptr;
        }

        return &*employeeIt;
    }

    std::vector<Employee> employees;
    std::map<std::string, std::vector<std::string>> departmentEmployees;
    std::map<std::string, double> salaries;
};

int main() {
    HRMS hrms;

    hrms.add(Employee("E001", "Anna", "Nowak", "IT", "Developer"), 9200.0);
    hrms.add(Employee("E002", "Jan", "Kowalski", "IT", "Tester"), 7600.0);
    hrms.add(Employee("E003", "Maria", "Wisniewska", "HR", "Recruiter"), 7100.0);
    hrms.add(Employee("E004", "Piotr", "Zielinski", "SALES", "Sales Manager"), 10500.0);
    hrms.add(Employee("E005", "Ewa", "Wojcik", "SALES", "Sales Specialist"), 6800.0);

    hrms.changeSalary("E002", 8000.0);

    hrms.printDepartment("IT");
    std::cout << '\n';
    hrms.printSalaries();
    std::cout << '\n';
    hrms.printSalariesSorted();
}
