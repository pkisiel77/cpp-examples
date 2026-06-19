# 07 - STL and Data Structures

This chapter introduces the Standard Template Library containers and a few
common algorithms. You will learn how to choose a container, store records,
search data, sort values, and combine containers in a small program.

## Learning Goals

After this chapter you should be able to:

- choose a container for a simple task,
- use `std::vector` for lists of values,
- iterate over containers with a range-based `for` loop,
- add, remove, and search elements,
- use `std::map` for key-value data,
- use `std::stack` and `std::queue`,
- use basic STL algorithms such as `std::sort` and `std::find_if`,
- combine containers with classes or structs.

## Why STL Matters

The STL gives you tested building blocks. Instead of writing your own dynamic
array, map, stack, or queue, use the standard container that matches the task.

For beginner projects, this usually means:

- `std::vector` for a list,
- `std::map` for lookup by key,
- `std::queue` for first-in-first-out processing,
- `std::stack` for last-in-first-out processing,
- algorithms from `<algorithm>` for searching, sorting, and filtering.

## `std::vector`

`std::vector` stores a sequence of values:

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    for (int value : numbers) {
        std::cout << value << std::endl;
    }
}
```

Use `push_back` to add an element at the end. Use `size` to check how many
elements are stored.

## Vector of Records

Containers become more useful when they store structured data:

```cpp
#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int points;
};

int main() {
    std::vector<Student> students = {
        {"Alice", 42},
        {"Bob", 35},
        {"Carol", 50}
    };

    for (const Student& student : students) {
        std::cout << student.name << ": "
                  << student.points << std::endl;
    }
}
```

Use `const Student&` in the loop when you only read the element and do not want
to copy it.

## Sorting

Use `std::sort` from `<algorithm>`:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {5, 2, 9, 1};

    std::sort(numbers.begin(), numbers.end());

    for (int value : numbers) {
        std::cout << value << std::endl;
    }
}
```

For records, pass a comparison function or a lambda:

```cpp
std::sort(students.begin(), students.end(),
          [](const Student& a, const Student& b) {
              return a.points > b.points;
          });
```

This sorts students by points from highest to lowest.

## Searching with `std::find_if`

Use `std::find_if` when the search condition is more complex than equality:

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int points;
};

int main() {
    std::vector<Student> students = {
        {"Alice", 42},
        {"Bob", 35}
    };

    auto found = std::find_if(students.begin(), students.end(),
                              [](const Student& student) {
                                  return student.name == "Bob";
                              });

    if (found != students.end()) {
        std::cout << found->points << std::endl;
    }
}
```

The result is an iterator. Compare it with `end()` before using it.

## `std::map`

`std::map` stores key-value pairs:

```cpp
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> points;

    points["Alice"] = 42;
    points["Bob"] = 35;

    std::cout << points["Alice"] << std::endl;
}
```

Use `find` when you want to check whether a key exists:

```cpp
auto it = points.find("Carol");
if (it != points.end()) {
    std::cout << it->second << std::endl;
}
```

This avoids accidentally creating a new entry.

## Stack, Queue, and List

Use `std::stack` when the last value added should be processed first:

```cpp
#include <iostream>
#include <stack>

int main() {
    std::stack<int> values;
    values.push(1);
    values.push(2);

    std::cout << values.top() << std::endl;
    values.pop();
}
```

Use `std::queue` when the first value added should be processed first:

```cpp
#include <iostream>
#include <queue>

int main() {
    std::queue<std::string> tasks;
    tasks.push("compile");
    tasks.push("test");

    std::cout << tasks.front() << std::endl;
    tasks.pop();
}
```

Use `std::list` only when you really need frequent insertions and removals in
the middle. For many beginner tasks, `std::vector` is the better default.

## Choosing a Container

Use these practical rules:

- choose `std::vector` for ordered data and simple iteration,
- choose `std::map` when lookup by key is important,
- choose `std::queue` for tasks processed in arrival order,
- choose `std::stack` for reverse-order processing,
- choose `std::list` only when its insertion and removal behavior matters.

Start with the simplest container that matches the problem.

## Mini Project: HRMS

Build a small human resources management program.

Minimum version:

- store employees in `std::vector`,
- each employee has an id, name, department, and salary,
- print all employees,
- find an employee by id,
- sort employees by salary,
- group or count employees by department with `std::map`.

Suggested structure:

```cpp
struct Employee {
    int id;
    std::string name;
    std::string department;
    double salary;
};
```

Keep operations in separate functions. This prepares the code for the next
chapter, where projects are split into multiple files and tested.

## Practice Tasks

1. Store five numbers in a vector and print them in sorted order.
2. Store students in a vector and find the student with the highest score.
3. Build a `std::map<std::string, int>` that counts words.
4. Simulate a queue of tasks with `std::queue`.
5. Use `std::stack` to reverse a sequence of values.
6. Extend the HRMS mini project with a department filter.

## Checklist

Before moving on, make sure that your code:

- uses standard containers instead of manual arrays when appropriate,
- checks iterators before dereferencing,
- uses `const` references for read-only records,
- keeps container choice simple and justified,
- separates data operations into functions,
- compiles without warnings.
