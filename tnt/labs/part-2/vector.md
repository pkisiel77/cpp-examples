## Opis

- https://www.algorytm.edu.pl/stl/vector
- https://edu.pjwstk.edu.pl/wyklady/pro/scb/PRG2CPP_files/node142.html
- https://cpp0x.pl/kursy/Kurs-STL-C++/Wstep-podstawowe-informacje-o-STL-u/115
- https://www.youtube.com/watch?v=M8EDrK4joTc&ab_channel=CppCon


## vector

### Example std::vector
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector;

    // Add elements to the vector
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);

    // Print the elements of the vector
    for (int i = 0; i < myVector.size(); i++) {
        std::cout << myVector[i] << " ";
    }
    std::cout << std::endl;

    // Remove the last element of the vector
    myVector.pop_back();

    // Print the elements of the vector again
    for (int i = 0; i < myVector.size(); i++) {
        std::cout << myVector[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```
C++11
```cpp
for(auto& elem:myVector)
    std::cout<<elem<<" ";
```
C++17
```cpp
std::size() 
myVector.size()
```
### Example std::vector

Program tworzy wektor struktur o nazwie Kandydat. 
Struktura zawiera: 
- imię,
- nazwisko,
- wiek 
- i nazwy umiejętności. 

Wektor jest uzupełniany poprzez dodanie kilku kandydatów do listy.

Następnie wyszukiwane są umiejętności.

```cpp
#include <iostream>
#include <vector>
#include <string>

struct Candidate {
    std::string name;
    int age;
    std::string skills;
};

int main() {
    std::vector<Candidate> candidates;

    // Add candidates to the list
    candidates.push_back({"Alice", 25, "C++, Python, JavaScript"});
    candidates.push_back({"Bob", 30, "Java, C#, SQL"});
    candidates.push_back({"Charlie", 35, "C++, Java, Python"});

    // Ask the user for a skill to search for
    std::cout << "Enter a skill to search for: ";
    std::string searchSkill;
    std::cin >> searchSkill;

    // Search for candidates with the specified skill
    std::cout << "Candidates with " << searchSkill << " skill:" << std::endl;
    for (const auto& candidate : candidates) {
        if (candidate.skills.find(searchSkill) != std::string::npos) {
            std::cout << candidate.name << ", " << candidate.age << std::endl;
        }
    }
    return 0;
}
```

### Example - resize
```cpp
#include <iostream>
#include <vector>
 
int main()
{
    std::vector<int> c = {1, 2, 3};
    std::cout << "The vector holds: ";
    for (const auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
 
    c.resize(5);
    std::cout << "After resize up to 5: ";
    for (const auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
 
    c.resize(2);
    std::cout << "After resize down to 2: ";
    for (const auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
 
    c.resize(6, 4);
    std::cout << "After resize up to 6 (initializer = 4): ";
    for (const auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
}
```

### Example - sort
```cpp
// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

bool myfunction (int i,int j) { return (i<j); }

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

int main () {
  int myints[] = {32,71,12,45,26,80,53,33};
  std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33

  // using default comparison (operator <):
  std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33

  // using function as comp
  std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

  // using object as comp
  std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
```
https://cplusplus.com/reference/algorithm/sort/

### Example
Proszę napisać program w języku C++, który utworzy wektor liczb całkowitych o rozmiarze 10 elementów i wypełni go wartościami od 1 do 10. Następnie program powinien wypisać zawartość wektora na ekranie.

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector(10);
    for (int i = 0; i < 10; i++) {
        myVector[i] = i + 1;
    }
    for (int i = 0; i < 10; i++) {
        std::cout << myVector[i] << " ";
    }
    return 0;
}

```
### Example
Proszę napisać program w języku C++, który utworzy wektor obiektów klasy "Person" zawierającej pola name (string) i age (int), a następnie zaimplementuje funkcję, która przyjmuje wektor i dwie liczby całkowite a i b jako argumenty i zwraca wektor składający się tylko z obiektów o polu age z przedziału <a,b>, posortowanych alfabetycznie według pola name.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
class Person {
    public:
        std::string name;
        int age;
};
std::vector<Person> filterAndSort(std::vector<Person> people, int a, int b) {
    std::vector<Person> result;
    std::copy_if(people.begin(), people.end(), std::back_inserter(result), [a, b](const Person& p) {
        return a <= p.age && p.age <= b;
    });
    std::sort(result.begin(), result.end(), [](const Person& a, const Person& b) {
        return a.name < b.name;
    });
    return result;
}
int main() {
    std::vector<Person> people = {{"John", 30}, {"Mike", 25}, {"Bob", 35}};
    auto result = filterAndSort(people, 25, 35);
    for (const auto& person : result) {
        std::cout << person.name << " " << person.age << std::endl;
    }
    return 0;
}
```


