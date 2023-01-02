## Zadanie 1

Napisz program w C++ który zarelizuje poniższą hierarhię

![image](https://user-images.githubusercontent.com/26519123/210280871-47e61ac1-785c-4401-97fd-58101d675e36.png)
Source: http://hoth.amu.edu.pl/~fishbomb/wyklady/wyklad_11.html


## Zadanie 2

Opisz co się dzieje w poniższykodzie linika kodu po linijce

```cpp
#include <iostream>
#include <string>

using namespace std;

// Base class for all employees
class Employee {
protected:
  string name;
  double salary;
  string jobTitle;

public:
  Employee(string name, double salary, string jobTitle) :
    name(name), salary(salary), jobTitle(jobTitle) {}

  double getSalary() {
    return salary;
  }

  string getJobDescription() {
    return "I am a " + jobTitle + " and I earn $" + to_string(salary) + " per year.";
  }
};

// Derived class for managers
class Manager : public Employee {
private:
  int numDirectReports;

public:
  Manager(string name, double salary, int numDirectReports) :
    Employee(name, salary, "Manager"), numDirectReports(numDirectReports) {}

  int getNumDirectReports() {
    return numDirectReports;
  }
};

// Derived class for engineers
class Engineer : public Employee {
private:
  string engineeringField;

public:
  Engineer(string name, double salary, string engineeringField) :
    Employee(name, salary, "Engineer"), engineeringField(engineeringField) {}

  string getEngineeringField() {
    return engineeringField;
  }
};

int main() {
  // Create an employee, a manager, and an engineer
  Employee e("John Smith", 50000, "Employee");
  Manager m("Jane Doe", 80000, 3);
  Engineer eng("Bob Johnson", 60000, "Computer Science");

  // Print information about each employee
  cout << e.getJobDescription() << endl;
  cout << m.getJobDescription() << " I manage " << m.getNumDirectReports() << " people." << endl;
  cout << eng.getJobDescription() << " I work in the field of " << eng.getEngineeringField() << "." << endl;

  return 0;
}
```


