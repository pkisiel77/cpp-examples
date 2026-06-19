# 05 - Files and Exceptions

This chapter shows how a program can store data outside memory and how it can
react to error situations. You will work with text files, input validation, and
basic exceptions.

## Learning Goals

After this chapter you should be able to:

- open a text file for writing,
- append data to a text file,
- open a text file for reading,
- read a file line by line,
- check whether a file operation succeeded,
- validate simple input data,
- use `try`, `throw`, and `catch`,
- choose a simple error-handling strategy for a small program.

## Writing a Text File

Use `std::ofstream` to write to a file:

```cpp
#include <fstream>
#include <iostream>

int main() {
    std::ofstream file("notes.txt");

    if (!file) {
        std::cout << "Cannot open file for writing." << std::endl;
        return 1;
    }

    file << "First line" << std::endl;
    file << "Second line" << std::endl;
}
```

Opening a file this way replaces the previous content.

## Appending Data

Use `std::ios::app` to append data at the end:

```cpp
#include <fstream>

int main() {
    std::ofstream file("notes.txt", std::ios::app);
    file << "Another line" << std::endl;
}
```

This is useful for logs, notes, and simple history files.

## Reading a Text File

Use `std::ifstream` and `std::getline`:

```cpp
#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream file("notes.txt");

    if (!file) {
        std::cout << "Cannot open file for reading." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
}
```

Always check whether the file was opened correctly before reading from it.

## Reading Numbers with Validation

Input from a file can be invalid. Keep parsing and validation separate from the
rest of the program:

```cpp
#include <iostream>
#include <sstream>
#include <string>

bool parseInt(const std::string& text, int& result) {
    std::istringstream input(text);
    input >> result;
    return input && input.eof();
}

int main() {
    int value = 0;

    if (parseInt("123", value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "Invalid number" << std::endl;
    }
}
```

This design is easy to test because `parseInt` does not depend on a real file.

## Simple Configuration Format

A practical beginner exercise is a small `key=value` file:

```text
name=Alice
level=3
active=true
```

Read the file line by line, split each line at `=`, and validate the result.
Empty lines and malformed lines should be handled deliberately.

## Exceptions

An exception reports an error that cannot be handled at the current place in
the code:

```cpp
#include <iostream>
#include <stdexcept>

int divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("division by zero");
    }

    return a / b;
}

int main() {
    try {
        std::cout << divide(10, 0) << std::endl;
    } catch (const std::runtime_error& error) {
        std::cout << "Error: " << error.what() << std::endl;
    }
}
```

Use exceptions for situations where normal execution cannot continue in the
current function. Do not use them as a replacement for simple `if` statements.

## Error-Handling Strategy

For small student programs, use this order:

1. Check expected problems with `if`, for example missing input or an empty
   value.
2. Return a status value when a function can fail in a normal way.
3. Throw an exception when the current function cannot sensibly continue.
4. Catch exceptions near the program boundary, for example in `main`.

The goal is not to use advanced error handling. The goal is to make failures
visible and predictable.

## Bridge Exercise: File Menu

Write a console program with a simple menu:

```text
1. Add note
2. Show notes
3. Clear notes
0. Exit
```

Requirements:

- store notes in a text file,
- append new notes instead of replacing the whole file,
- read and print all notes,
- handle a missing file,
- validate the menu choice,
- keep file operations in separate functions.

## Practice Tasks

1. Write a program that saves three lines to a file.
2. Modify it so that new lines are appended instead of overwriting the file.
3. Write a program that reads a file line by line and counts non-empty lines.
4. Write a function that parses one integer from a string.
5. Write a function that throws an exception for division by zero.

## Checklist

Before moving on, make sure that your code:

- checks whether files open successfully,
- separates parsing from file reading,
- handles invalid input,
- catches exceptions by `const` reference,
- keeps user-facing error messages clear,
- compiles without warnings.
