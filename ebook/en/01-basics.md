# 01 - C++ Basics

This chapter is the first programming block of the course. It introduces the
structure of a C++ program, input and output, basic data types, variables,
operators, and simple console tasks.

## Learning Goals

After this chapter you should be able to:

- describe the role of an algorithm, a program, and the `main` function,
- write, compile, and run a simple C++ program,
- use `std::cout`, `std::cin`, and `std::getline`,
- choose basic data types for a simple problem,
- declare and initialize variables,
- perform simple calculations,
- format basic text output,
- solve small console exercises.

## Minimal Program Structure

Most beginner programs in this course start like this:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello" << std::endl;
    return 0;
}
```

Important parts:

- `#include <iostream>` makes console input/output available,
- `int main()` is the starting point of the program,
- statements inside `{ }` are executed in order,
- `return 0;` means the program finished successfully.

## Output

Use `std::cout` to print text:

```cpp
#include <iostream>

int main() {
    std::cout << "C++ basics" << std::endl;
    std::cout << "Second line" << std::endl;
}
```

`std::endl` ends the current line.

## Input

Use `std::cin` to read a value:

```cpp
#include <iostream>
#include <string>

int main() {
    std::string name;

    std::cout << "Your name: ";
    std::cin >> name;

    std::cout << "Hello, " << name << "!" << std::endl;
}
```

Use `std::getline` when you want to read a full line with spaces:

```cpp
#include <iostream>
#include <string>

int main() {
    std::string fullName;

    std::cout << "Full name: ";
    std::getline(std::cin, fullName);

    std::cout << "Hello, " << fullName << "!" << std::endl;
}
```

## Basic Types

Common beginner types:

| Type | Example use |
| --- | --- |
| `int` | whole numbers |
| `double` | decimal numbers |
| `char` | one character |
| `bool` | true or false |
| `std::string` | text |

Example:

```cpp
int age = 20;
double price = 19.99;
bool active = true;
std::string city = "Krakow";
```

## Simple Calculation

```cpp
#include <iostream>

int main() {
    double a = 0.0;
    double b = 0.0;

    std::cout << "First number: ";
    std::cin >> a;

    std::cout << "Second number: ";
    std::cin >> b;

    std::cout << "Sum: " << a + b << std::endl;
    std::cout << "Product: " << a * b << std::endl;
}
```

## Formatting Output

For decimal precision, use `<iomanip>`:

```cpp
#include <iomanip>
#include <iostream>

int main() {
    double value = 10.0 / 3.0;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << value << std::endl;
}
```

Expected output:

```text
3.33
```

## Common Mistakes

- forgetting `#include <iostream>`,
- missing semicolon at the end of a statement,
- using `int` when the result should contain decimals,
- mixing `std::cin >> value` and `std::getline` without understanding how input is buffered,
- ignoring compiler warnings.

## Practice Tasks

1. Print your name, city, and favorite programming topic.
2. Read two integers and print their sum, difference, and product.
3. Read a rectangle width and height, then print its area.
4. Read a temperature in Celsius and print the value in Fahrenheit.
5. Read a full name with spaces and print a greeting.

## Student Checklist

Before moving to control flow and loops, make sure you can:

- write a minimal C++ program,
- compile it with `-std=c++17 -Wall -Wextra -pedantic`,
- read one value from the user,
- read one full line from the user,
- choose between `int`, `double`, `bool`, and `std::string`,
- format a decimal number with two digits after the decimal point.

## Next Step

The next topic is control flow: `if`, `else`, `switch`, and loops.
