# 09 - Modern C++

This chapter collects selected features from modern C++, mainly C++11 and
newer. The goal is not to cover every language feature. The goal is to
recognize useful tools that make beginner projects safer and easier to read.

## Learning Goals

After this chapter you should be able to:

- recognize selected modern C++ features,
- use `auto`, `nullptr`, brace initialization, and range-based loops,
- use `enum class`, type aliases, and `override`,
- write simple lambda expressions,
- understand the basic idea of move semantics,
- organize names with namespaces,
- explain the difference between classic file splitting and C++20 modules,
- run a simple `std::thread` example.

## `auto`

`auto` lets the compiler deduce the type from the initializer:

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3};

    for (auto value : numbers) {
        std::cout << value << std::endl;
    }
}
```

Use `auto` when the type is obvious from the right side or when the exact type
is long, for example an iterator. Do not use it to hide important information.

## `nullptr`

Use `nullptr` instead of `0` or `NULL` for empty pointers:

```cpp
int* pointer = nullptr;

if (pointer == nullptr) {
    // no object is available
}
```

`nullptr` has a clear pointer meaning and avoids old C-style ambiguities.

## Brace Initialization

Brace initialization gives a consistent way to initialize values:

```cpp
int count{10};
double price{19.99};
std::vector<int> numbers{1, 2, 3};
```

It is especially useful when initializing containers and objects.

## Range-Based `for`

Use a range-based loop when you want to process every element:

```cpp
for (const auto& name : names) {
    std::cout << name << std::endl;
}
```

Use `const auto&` when you only read larger objects and want to avoid copying.

## `enum class`

`enum class` creates a scoped enumeration:

```cpp
enum class Status {
    New,
    InProgress,
    Done
};

Status status = Status::New;
```

This is safer than an old unscoped `enum` because names do not leak into the
surrounding scope.

## Type Aliases

Use `using` to give a meaningful name to a type:

```cpp
using StudentId = int;
using Points = int;
```

Aliases do not create new types, but they can make interfaces easier to read.

## `override`

Use `override` when a derived class overrides a virtual method:

```cpp
class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
};

class Square : public Shape {
public:
    double area() const override {
        return 16.0;
    }
};
```

If the method signature is wrong, the compiler will report an error. This is a
useful safety net.

## Lambdas

A lambda is a small function object written inline:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {5, 1, 9, 2};

    std::sort(numbers.begin(), numbers.end(),
              [](int a, int b) {
                  return a > b;
              });

    for (int value : numbers) {
        std::cout << value << std::endl;
    }
}
```

Lambdas are often used with STL algorithms.

## Basic Move Semantics Idea

Some objects own resources, for example memory inside a `std::vector` or
`std::string`. Moving can transfer resources instead of copying them:

```cpp
#include <string>
#include <utility>
#include <vector>

int main() {
    std::vector<std::string> source = {"alpha", "beta"};
    std::vector<std::string> target = std::move(source);
}
```

After moving, the source object is still valid, but its value should not be
assumed. For beginner projects, the most important rule is simple: do not use
`std::move` unless you know why ownership should be transferred.

## Namespaces

Namespaces group related names and avoid conflicts:

```cpp
namespace math {
    int add(int a, int b) {
        return a + b;
    }
}

int main() {
    return math::add(2, 3);
}
```

In small exercises, namespaces are optional. In larger projects, they help keep
modules organized.

## Classic Files and C++20 Modules

This course mainly uses classic `.h` and `.cpp` files because they are widely
supported and easy to build with simple commands.

C++20 modules are a newer language feature that can replace parts of the header
model in modern toolchains. Treat modules as a topic for further study after
you are comfortable with headers, source files, and build scripts.

## Basic Threads

`std::thread` starts work in a separate thread:

```cpp
#include <iostream>
#include <thread>

void work() {
    std::cout << "Work in another thread" << std::endl;
}

int main() {
    std::thread worker(work);
    worker.join();
}
```

`join` waits for the thread to finish. Multithreading quickly introduces data
races and synchronization problems, so keep first examples small.

## Practice Tasks

1. Rewrite a loop over a vector using a range-based `for`.
2. Replace a nullable pointer example with `nullptr`.
3. Create an `enum class` for task status.
4. Sort a vector of records with a lambda.
5. Add `override` to a polymorphic example.
6. Put two utility functions into a namespace.
7. Run a simple `std::thread` example and explain why `join` is needed.

## Checklist

Before moving on, make sure that your code:

- uses modern features to improve clarity, not to look advanced,
- avoids unnecessary `std::move`,
- uses `override` on overridden methods,
- keeps lambdas short and readable,
- still compiles with `-Wall -Wextra -pedantic`,
- stays understandable to another student.
