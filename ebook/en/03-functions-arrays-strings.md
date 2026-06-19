# 03 - Functions, Arrays, and Strings

This chapter teaches how to split a program into smaller parts and how to work
with simple collections of data. You will use functions, one-dimensional arrays,
two-dimensional arrays, and `std::string`.

## Learning Goals

After this chapter you should be able to:

- declare and define your own functions,
- pass arguments to functions,
- return values from functions,
- understand the difference between a declaration and a definition,
- use one-dimensional arrays,
- use simple two-dimensional arrays,
- iterate over array elements,
- perform basic operations on `std::string`,
- split a larger task into smaller functions.

## Why Functions Matter

A function gives a name to a piece of logic. Instead of writing everything in
`main`, you can move a calculation into a separate function:

```cpp
#include <iostream>

int add(int a, int b) {
    return a + b;
}

int main() {
    std::cout << add(2, 3) << std::endl;
}
```

This makes code easier to read, test, and reuse.

## Declaration and Definition

A declaration tells the compiler that a function exists:

```cpp
int add(int a, int b);
```

A definition contains the function body:

```cpp
int add(int a, int b) {
    return a + b;
}
```

In small programs, both can be in one file. In larger projects, declarations
often go into header files and definitions go into `.cpp` files.

## Parameters and Return Values

Parameters are input values for a function. `return` sends a result back:

```cpp
double rectangleArea(double width, double height) {
    return width * height;
}
```

Use clear names. A function named `rectangleArea` is easier to understand than
one named `calc`.

## Local Variables and Scope

Variables declared inside a function are local to that function:

```cpp
int square(int value) {
    int result = value * value;
    return result;
}
```

`result` cannot be used outside `square`. This is useful because it prevents
unrelated parts of the program from accidentally changing each other.

## One-Dimensional Arrays

An array stores several values of the same type:

```cpp
#include <iostream>

int main() {
    int numbers[5] = {4, 2, 9, 1, 7};

    for (int i = 0; i < 5; ++i) {
        std::cout << numbers[i] << std::endl;
    }
}
```

Array indexes start at `0`. For an array of size `5`, valid indexes are
`0`, `1`, `2`, `3`, and `4`.

## Array Minimum and Maximum

```cpp
#include <iostream>

int main() {
    int numbers[5] = {4, 2, 9, 1, 7};
    int minimum = numbers[0];
    int maximum = numbers[0];

    for (int i = 1; i < 5; ++i) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
        if (numbers[i] > maximum) {
            maximum = numbers[i];
        }
    }

    std::cout << "Minimum: " << minimum << std::endl;
    std::cout << "Maximum: " << maximum << std::endl;
}
```

The first element is a practical initial value when the array is not empty.

## Two-Dimensional Arrays

A two-dimensional array can represent a table or a small matrix:

```cpp
#include <iostream>

int main() {
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    for (int row = 0; row < 2; ++row) {
        for (int col = 0; col < 3; ++col) {
            std::cout << matrix[row][col] << " ";
        }
        std::cout << std::endl;
    }
}
```

Nested loops are the usual way to process rows and columns.

## Strings

`std::string` stores text:

```cpp
#include <iostream>
#include <string>

int main() {
    std::string text = "C++";

    std::cout << text << std::endl;
    std::cout << "Length: " << text.size() << std::endl;
}
```

You can iterate over characters:

```cpp
for (char ch : text) {
    std::cout << ch << std::endl;
}
```

## Reading a Full Line

Use `std::getline` when the text may contain spaces:

```cpp
#include <iostream>
#include <string>

int main() {
    std::string sentence;

    std::cout << "Enter text: ";
    std::getline(std::cin, sentence);

    std::cout << "You entered: " << sentence << std::endl;
}
```

## Bridge Exercise: GADERYPOLUKI Cipher

Write a console program that encrypts text with the GADERYPOLUKI substitution
cipher.

The cipher uses replacement pairs:

```text
GA DE RY PO LU KI
```

Rules:

- `G` becomes `A`,
- `A` becomes `G`,
- `D` becomes `E`,
- `E` becomes `D`,
- the same rule applies to every pair,
- characters not present in the key stay unchanged.

Example:

```text
PROGRAM -> OYPAYGM
```

## Required Function

The program should contain a function:

```cpp
std::string encryptGaderypoluki(const std::string& text);
```

The function should:

- take the input text as `std::string`,
- return a new encrypted `std::string`,
- not modify the input text directly,
- keep characters outside the key unchanged.

## Suggested Work Plan

1. Write a helper function that replaces one character.
2. Test the pair `G` and `A`.
3. Add all remaining key pairs.
4. Write a function that loops over the whole string.
5. Read input with `std::getline`.
6. Test text containing spaces, digits, and punctuation.

## Check Scenarios

1. Input `PROGRAM`; expected result: `OYPAYGM`.
2. Input `GADERYPOLUKI`; every letter should be replaced by its pair.
3. Input `ALA 123`; digits and spaces should stay unchanged.
4. Input an empty string; the program should not crash.

## Extra Tasks

After the basic version works, add:

- lowercase support,
- preserving letter case,
- automatic decryption with the same function,
- tests for the encryption function,
- reading text from a file,
- writing encrypted text to a file,
- a custom substitution key.

## Common Mistakes

- printing from the encryption function instead of returning a value,
- changing only one pair and forgetting the rest of the key,
- using `std::cin >> text` when the text may contain spaces,
- modifying the original string when a returned result would be clearer,
- mixing input/output code with encryption logic.

## Practice Tasks

1. Write a function `isEven`.
2. Write a function `maxOfTwo`.
3. Calculate the average of an array.
4. Find the minimum and maximum in an array.
5. Print a two-dimensional array as a table.
6. Count letters in a string.
7. Check whether a string is a palindrome.
8. Implement the GADERYPOLUKI cipher.

## Student Checklist

Before moving to pointers, references, and memory, make sure you can:

- write a function with parameters and a return value,
- explain local variable scope,
- iterate over an array by index,
- process a two-dimensional array with nested loops,
- read a full line with `std::getline`,
- iterate over characters in `std::string`,
- split a string-processing task into small functions.
