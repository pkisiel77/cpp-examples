Zadanie 2
Cześć A: Implementacja klas.
## Zadanie 1
Napisać program umożliwiający tworzenie oraz dalsze wykorzystanie obiektów dwóch klas: COsoba oraz CPracownik.
Klasą bazową jest klasa COsoba. W klasie tej przewidziane są chronione dane składowe: nazwisko (typu string) oraz wiek (typu int;
wiek osoby powinien być z zakresu od 0 do 120). W klasie powinien zostać zdefiniowany konstruktor domyślny, który umożliwia
również nadanie pewnych domyślnych wartości danym składowym klasy (nazwisko = "", wiek = 0). Wykorzystuje on odpowiednie
funkcje dostępowe Set zdefiniowane w obiekcie (funkcje te nadają wartości danym składowym w klasie oraz sprawdzają
poprawność zaproponowanych przez użytkownika danych). Ponadto w klasie powinny zostać zdefiniowane funkcje dostępowe Get
(określone jako funkcje stałe), funkcja stała Drukuj wyświetlająca informacje o osobie na ekranie oraz działający w podobny sposób
przeciążony operator wstawiania do strumienia <<.
Drugą klasą jest klasa CPracownik, która dziedziczy dane i funkcje składowe klasy COsoba. Co więcej w klasie tej przewidziana
jest prywatna dana składowa: zarobek_mies (typu int; zarobek pracownika podany w walucie PLN powinien być z zakresu od 0 do
5000). W klasie CPracownik powinien się znaleźć również odpowiednio: konstruktor domyślny, który umożliwia również nadanie
pewnych domyślne wartości danym składowym klasy (nazwisko = "", wiek = 0, zarobek_mies = 0), funkcje Set, stałe funkcje Get,
stała funkcja Drukuj wyświetlająca informacje o pracowniku na ekranie oraz działający w podobny sposób przeciążony operator
wstawiania do strumienia <<. Dodatkowo w klasie powinna zostać zdefiniowana funkcja składowa Dochod_Roczny. Zadaniem
funkcji jest przekazywanie do programu (przez return) rocznego dochodu uzyskanego przez pracownika (12 x zarobek_mies).
Cześć B: Zadania testowe w programie.
1) Zadeklaruj w programie obiekt osobaA typu COsoba (przyjmujemy, że dane o osobie będą określone w dalszej części programu)
oraz obiekt pracA typu CPracownik (dane o pracowniku nadane zostaną przy tworzeniu obiektu).
2) Nadaj wartości danym obiektu osobaA wykorzystując do tego funkcje dostępowe Set.
3) Wypisz na ekranie dane o osobie osobaA wykorzystując do tego funkcję Drukuj oraz dane o pracowniku pracA wykorzystując do
tego przeciążony operator <<.
4) Zadeklaruj wskaźnik ptrOsoba do typu COsoba oraz ptrPracownik do typu CPracownik.
5) Przypisz adres obiektu osobaA dla wskaźnika ptrOsoba oraz adres obiektu pracA dla wskaźnika ptrPracownik.
6) Wypisz na ekranie dane o osobie osobaA oraz pracowniku pracA wykorzystując do tego funkcję Drukuj oraz wskaźniki ptrOsoba
i ptrPracownik.
7) Zadeklaruj wskaźnik ptr1 do typu COsoba i zainicjuj go adresem obiektu pracA.
8) Wypisz na ekranie informacje o pracowniku pracA wykorzystując do tego przeciążony operator << oraz zdereferowany wskaźnik
ptr1.
9) Zadeklaruj wskaźnik ptr2 do typu COsoba i zainicjuj go adresem obiektu pracA.
10) Zadeklaruj wskaźnik ptr3 do typu CPracownik.
11) Wykonaj operację rzutowania wskaźnika ptr2 do klasy COsoba na wskaźnik ptr3 klasy CPracownik.
12) Wykorzystując operator << oraz zdereferowany wskaźnik ptr3 wypisz na ekranie informacje o pracowniku pracA.
13) Przypisz adres ptrOsoba dla wskaźnika ptr2.
14) Wykonaj operację rzutowania wskaźnika ptr2 na wskaźnik ptrPracownik.
15) Wykorzystując operator << oraz wskaźnik ptrPracownik wypisz na ekranie informacje o pracowniku.

## Zadanie 2


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


