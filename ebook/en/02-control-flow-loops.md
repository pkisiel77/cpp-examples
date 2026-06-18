# 02 - Control Flow and Loops

This chapter teaches how a program makes decisions and repeats instructions.
These tools are necessary for almost every non-trivial console program.

## Learning Goals

After this chapter you should be able to:

- use `if`, `else if`, and `else`,
- use comparison and logical operators,
- use `switch` for simple menu-like choices,
- use the conditional operator `?:` in simple expressions,
- write loops with `for`, `while`, and `do while`,
- choose the right loop type for a problem,
- use `break` and `continue` in simple cases,
- solve tasks that require decisions and repetition.

## Conditions

Use `if` when the program should execute code only in some situations:

```cpp
#include <iostream>

int main() {
    int age = 0;

    std::cout << "Age: ";
    std::cin >> age;

    if (age >= 18) {
        std::cout << "Adult" << std::endl;
    } else {
        std::cout << "Minor" << std::endl;
    }
}
```

Common comparison operators:

| Operator | Meaning |
| --- | --- |
| `==` | equal |
| `!=` | not equal |
| `<` | less than |
| `<=` | less than or equal |
| `>` | greater than |
| `>=` | greater than or equal |

Logical operators:

| Operator | Meaning |
| --- | --- |
| `&&` | and |
| `||` | or |
| `!` | not |

## Multiple Conditions

Use `else if` when there are several possible ranges or categories:

```cpp
#include <iostream>

int main() {
    int points = 0;

    std::cout << "Points: ";
    std::cin >> points;

    if (points >= 90) {
        std::cout << "Very good" << std::endl;
    } else if (points >= 60) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
    }
}
```

## `switch`

Use `switch` for simple choices based on one value:

```cpp
#include <iostream>

int main() {
    int option = 0;

    std::cout << "1. Add\n";
    std::cout << "2. Remove\n";
    std::cout << "Option: ";
    std::cin >> option;

    switch (option) {
        case 1:
            std::cout << "Add selected" << std::endl;
            break;
        case 2:
            std::cout << "Remove selected" << std::endl;
            break;
        default:
            std::cout << "Unknown option" << std::endl;
            break;
    }
}
```

Remember `break`. Without it, execution continues into the next case.

## `for` Loop

Use `for` when you know how many times the loop should run:

```cpp
#include <iostream>

int main() {
    for (int i = 1; i <= 5; ++i) {
        std::cout << i << std::endl;
    }
}
```

Typical uses:

- counting from `1` to `n`,
- summing numbers,
- printing a table,
- iterating over an index range.

## `while` Loop

Use `while` when the loop depends on a condition that may change during input:

```cpp
#include <iostream>

int main() {
    int number = 0;

    while (number != 5) {
        std::cout << "Enter 5 to stop: ";
        std::cin >> number;
    }
}
```

This loop may execute zero times if the condition is false at the beginning.

## `do while` Loop

Use `do while` when the body should run at least once:

```cpp
#include <iostream>

int main() {
    int option = 0;

    do {
        std::cout << "1. Continue\n";
        std::cout << "0. Exit\n";
        std::cout << "Option: ";
        std::cin >> option;
    } while (option != 0);
}
```

This is useful for simple console menus.

## `break` and `continue`

`break` exits a loop:

```cpp
for (int i = 1; i <= 10; ++i) {
    if (i == 5) {
        break;
    }
    std::cout << i << std::endl;
}
```

`continue` skips the rest of the current iteration:

```cpp
for (int i = 1; i <= 10; ++i) {
    if (i % 2 == 0) {
        continue;
    }
    std::cout << i << std::endl;
}
```

## Common Mistakes

- writing `=` instead of `==` in a condition,
- adding an accidental semicolon after `if` or `while`,
- forgetting `break` in `switch`,
- creating an infinite loop because the loop variable never changes,
- dividing by zero when no valid input was provided,
- using `for` for input that should end based on user command.

## Bridge Exercise: Minimum, Maximum, and Average

Write a console program that reads real numbers from the user and calculates:

- minimum value,
- maximum value,
- arithmetic average,
- number of valid values.

The user should be able to finish input with a portable text command, for
example `q`, `end`, or an empty line.

Example session:

```text
Enter a number or q to finish: 10
Enter a number or q to finish: -2.5
Enter a number or q to finish: 4.5
Enter a number or q to finish: q

Count: 3
Minimum: -2.5
Maximum: 10
Average: 4
```

### Requirements

The program should:

- use C++17,
- use a `while` or `do while` loop,
- store the sum in a `double`,
- count valid values,
- update minimum and maximum after each valid value,
- detect invalid input,
- avoid division by zero when no numbers were entered,
- compile with `-Wall -Wextra -pedantic`.

### Suggested Work Plan

1. Write a loop that reads text until the user enters `q`.
2. Add a counter for valid numbers.
3. Add sum and average calculation.
4. Add minimum and maximum.
5. Add a message for the empty data case.
6. Add invalid input handling, for example for `abc`.

### Check Scenarios

1. Enter `10`, `-2.5`, `4.5`, then `q`.
2. Enter only one number and check that minimum, maximum, and average are the same.
3. Finish without entering any number and check the message.
4. Enter invalid text such as `abc` and check that the program asks again.
5. Enter several negative numbers and verify minimum and maximum.

## Practice Tasks

1. Read a number and print whether it is positive, negative, or zero.
2. Read a menu option and handle it with `switch`.
3. Print numbers from `1` to `100` with a `for` loop.
4. Sum numbers from `1` to `n`.
5. Read numbers until the user enters `0`.
6. Print a multiplication table.
7. Skip even numbers using `continue`.
8. Stop searching when a target value is found using `break`.

## Student Checklist

Before moving to functions, arrays, and strings, make sure you can:

- write an `if/else` condition,
- use comparison and logical operators,
- use a `switch` with `break`,
- choose between `for`, `while`, and `do while`,
- write a loop that depends on user input,
- explain when `break` and `continue` are useful,
- solve the minimum, maximum, and average bridge exercise.
