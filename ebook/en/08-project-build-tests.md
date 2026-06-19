# 08 - Project Structure, Build, and Tests

This chapter shows how to move from one `.cpp` file to a small C++ project with
headers, source files, build commands, syntax checks, tests, and basic
automation.

## Learning Goals

After this chapter you should be able to:

- split a program into header and source files,
- explain the role of the preprocessor and `#include`,
- protect headers against multiple inclusion,
- create a minimal project structure,
- compile a project made of several files,
- check syntax without building a full program,
- write simple tests without an external framework,
- explain the basic idea of CI/CD.

## From One File to Several Files

A one-file program is fine at the beginning. As the code grows, split it into:

- headers with declarations,
- source files with definitions,
- tests that check selected functions,
- a build directory for generated files.

A small structure can look like this:

```text
calculator/
  include/calculator.h
  src/calculator.cpp
  src/main.cpp
  tests/calculator_tests.cpp
  build/
  build.sh
```

The exact layout can vary. The important rule is that source code and generated
files are not mixed.

## Headers and Source Files

A header declares what exists:

```cpp
// include/calculator.h
#ifndef CALCULATOR_H
#define CALCULATOR_H

int add(int a, int b);

#endif
```

A source file defines how it works:

```cpp
// src/calculator.cpp
#include "calculator.h"

int add(int a, int b) {
    return a + b;
}
```

`main.cpp` can use the function through the header:

```cpp
#include <iostream>
#include "calculator.h"

int main() {
    std::cout << add(2, 3) << std::endl;
}
```

## Include Guards

Include guards prevent the same header from being included more than once in a
single translation unit:

```cpp
#ifndef CALCULATOR_H
#define CALCULATOR_H

// declarations

#endif
```

You may also see `#pragma once` in real projects. Include guards are explicit
and portable, so they are a good teaching default.

## Compiling Multiple Files

A simple manual compile command can look like this:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic \
    -Iinclude \
    src/main.cpp src/calculator.cpp \
    -o build/calculator
```

Important parts:

- `-std=c++17` selects the language version,
- `-Wall -Wextra -pedantic` enables useful warnings,
- `-Iinclude` tells the compiler where to find project headers,
- several `.cpp` files are compiled and linked into one program.

## Build Script

A small `build.sh` keeps commands repeatable:

```sh
#!/bin/sh
set -eu

mkdir -p build

c++ -std=c++17 -Wall -Wextra -pedantic \
    -Iinclude \
    src/main.cpp src/calculator.cpp \
    -o build/calculator

c++ -std=c++17 -Wall -Wextra -pedantic \
    -Iinclude \
    tests/calculator_tests.cpp src/calculator.cpp \
    -o build/calculator_tests

./build/calculator_tests
```

Generated files should stay in `build/` and should not be committed.

## Syntax Checks

Use `-fsyntax-only` when you want the compiler to check code without producing
an executable:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic -fsyntax-only src/main.cpp
```

This is useful for quick feedback and for checking starter files.

## Simple Tests Without a Framework

A minimal test program can return `0` for success and non-zero for failure:

```cpp
#include "calculator.h"

int main() {
    if (add(2, 3) != 5) {
        return 1;
    }

    if (add(-2, 2) != 0) {
        return 1;
    }

    return 0;
}
```

The build script can run the test executable. If the test returns `1`, the
script fails.

## Basic CI/CD Idea

CI means that checks are run automatically after a change is pushed to the
repository. For this course, a useful first CI setup would:

- install a compiler,
- compile examples,
- run simple tests,
- fail when a command returns an error.

CD is about automatic delivery or deployment. For this repository, CI is the
more important concept for students.

## Bridge Exercise: RPN Calculator

Build a small multi-file project that calculates arithmetic expressions by
converting them to Reverse Polish Notation.

The program should:

- read one text expression,
- support real numbers,
- support `+`, `-`, `*`, `/`,
- respect multiplication and division precedence,
- support parentheses,
- convert the expression to Reverse Polish Notation,
- evaluate the result with a stack,
- report clear errors for invalid expressions.

Examples:

```text
2 + 2 * 2 = 6
(2 + 2) * 2 = 8
10 / 2 + 3 = 8
```

Suggested structure:

```text
rpn-calculator/
  include/rpn/
    token.h
    tokenizer.h
    rpn.h
    evaluator.h
  src/
    tokenizer.cpp
    rpn.cpp
    evaluator.cpp
    main.cpp
  tests/
    rpn_tests.cpp
  build/
    .gitignore
  build.sh
  README.md
```

Suggested functions:

```cpp
std::vector<Token> tokenize(const std::string& expression);
std::vector<Token> toReversePolishNotation(const std::vector<Token>& tokens);
double evaluateReversePolishNotation(const std::vector<Token>& tokens);
```

Minimum requirements:

- C++17,
- separate tokenization from evaluation,
- use `std::vector<Token>`,
- use `std::vector` or `std::stack` as the evaluation stack,
- handle division by zero,
- detect invalid parentheses,
- include tests for at least three valid expressions,
- include a `build.sh` script that builds the app and tests,
- compile with `-Wall -Wextra -pedantic`.

Suggested work order:

1. Create the project directory structure.
2. Add `build.sh` that compiles an empty program.
3. Define `Token`.
4. Implement tokenization for numbers and operators.
5. Convert tokens to Reverse Polish Notation.
6. Evaluate the RPN expression with a stack.
7. Add tests for valid expressions.
8. Add error handling and tests for invalid expressions.

Extra tasks:

- negative numbers,
- exponentiation,
- constants `pi` and `e`,
- repeated calculations in a loop,
- calculation history,
- comparison with a recursive parser.

## Practice Tasks

1. Split a one-file calculator into `calculator.h`, `calculator.cpp`, and
   `main.cpp`.
2. Add a `build.sh` script for the calculator.
3. Add a test program that checks three functions.
4. Add a syntax-only command for one starter file.
5. Add a `README.md` section that explains how to build and test the project.
6. Start the RPN calculator with only tokenization and tests.

## Checklist

Before moving on, make sure that your project:

- has headers and source files in clear directories,
- keeps generated files in `build/`,
- has a repeatable build command or script,
- compiles with warnings enabled,
- has tests that return non-zero on failure,
- separates parsing, calculation, and user interaction,
- documents build and test commands.
