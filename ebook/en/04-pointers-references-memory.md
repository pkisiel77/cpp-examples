# 04 - Pointers, References, and Memory

This chapter introduces addresses, pointers, references, and basic memory
safety habits. These topics are powerful, but they require discipline because
small mistakes can produce hard-to-diagnose bugs.

## Learning Goals

After this chapter you should be able to:

- distinguish a variable value from its address,
- use the address-of operator `&`,
- declare and initialize pointers,
- understand `nullptr`,
- dereference a pointer with `*`,
- use references,
- pass data to functions by value, pointer, and reference,
- recognize common memory safety problems.

## Value and Address

A variable has a value and an address in memory:

```cpp
#include <iostream>

int main() {
    int number = 42;

    std::cout << "Value: " << number << std::endl;
    std::cout << "Address: " << &number << std::endl;
}
```

`number` reads the value. `&number` reads the address.

## Pointers

A pointer stores an address:

```cpp
#include <iostream>

int main() {
    int number = 42;
    int* pointer = &number;

    std::cout << pointer << std::endl;
    std::cout << *pointer << std::endl;
}
```

`pointer` stores the address. `*pointer` reads the value stored at that address.
This is called dereferencing.

## `nullptr`

If a pointer does not point to a valid object, initialize it with `nullptr`:

```cpp
int* pointer = nullptr;
```

Before dereferencing a pointer, check whether it is not empty:

```cpp
if (pointer != nullptr) {
    std::cout << *pointer << std::endl;
}
```

This habit prevents many beginner-level pointer mistakes.

## References

A reference is another name for an existing object:

```cpp
#include <iostream>

int main() {
    int value = 10;
    int& ref = value;

    ref = 20;

    std::cout << value << std::endl;
}
```

The program prints `20` because `ref` refers to `value`.

## Pointer or Reference

Use a reference when the argument must exist:

```cpp
void increment(int& value) {
    ++value;
}
```

Use a pointer when the argument may be missing:

```cpp
void incrementIfPresent(int* value) {
    if (value != nullptr) {
        ++(*value);
    }
}
```

This is a practical rule for beginner code. It makes the intent visible in the
function signature.

## Passing to Functions

Passing by value copies the argument:

```cpp
void changeCopy(int value) {
    value = 100;
}
```

Passing by reference can modify the original value:

```cpp
void changeOriginal(int& value) {
    value = 100;
}
```

Passing by pointer can also modify the original value, but the function should
handle `nullptr`:

```cpp
void changeIfPresent(int* value) {
    if (value != nullptr) {
        *value = 100;
    }
}
```

## `const` References

Use `const` references when a function should read a larger object without
copying it:

```cpp
#include <iostream>
#include <string>

void printName(const std::string& name) {
    std::cout << name << std::endl;
}
```

The function cannot modify `name`, and it avoids copying the string.

## Arrays and Pointers

An array name can be used as a pointer to the first element:

```cpp
#include <iostream>

int main() {
    int numbers[3] = {10, 20, 30};
    int* p = numbers;

    for (int i = 0; i < 3; ++i) {
        std::cout << p[i] << std::endl;
    }
}
```

Valid indexes for this array are `0`, `1`, and `2`. Accessing `p[3]` is outside
the array and is an error.

## Memory Safety Rules

Use these rules consistently:

- initialize pointers,
- prefer `nullptr` for an empty pointer,
- check a pointer before dereferencing it,
- do not return the address of a local variable,
- do not access an array outside its valid range,
- prefer references when a value is required,
- prefer `const` references for read-only larger objects,
- keep variables close to the place where they are used.

Do not write code like this:

```cpp
int* invalid() {
    int local = 10;
    return &local;
}
```

`local` stops existing when the function ends. The returned pointer does not
point to a valid object.

## Practice Tasks

1. Write `printIfPresent`, which takes `int*` and prints the value only when the
   pointer is not `nullptr`.
2. Write `incrementIfPresent`, which takes `int*` and increments the value only
   when the pointer is not `nullptr`.
3. Write `increment`, which takes `int&`, and compare it with the pointer
   version.
4. Write a function that reads an array through a pointer and a size.
5. Find one previous function where `const std::string&` would be better than
   passing a string by value.

## Checklist

Before moving on, make sure that your code:

- initializes every pointer,
- checks optional pointers before dereferencing,
- does not return addresses of local variables,
- does not read past the end of an array,
- uses references when a value is required,
- compiles without warnings.
