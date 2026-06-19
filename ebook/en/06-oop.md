# 06 - Object-Oriented Programming

This chapter introduces classes, objects, constructors, encapsulation,
inheritance, and polymorphism. The goal is not to make every program
object-oriented. The goal is to understand when objects help organize data and
behavior.

## Learning Goals

After this chapter you should be able to:

- define a class,
- create objects,
- use private fields,
- write constructors,
- write `const` methods,
- understand `this`,
- explain basic inheritance,
- use virtual methods,
- use `override`,
- overload a simple operator,
- build a small polymorphic program.

## Classes and Objects

A class defines a type. An object is a value of that type:

```cpp
#include <iostream>
#include <string>

class Student {
public:
    Student(const std::string& name, int points)
        : name_(name), points_(points) {
    }

    void print() const {
        std::cout << name_ << ": " << points_ << std::endl;
    }

private:
    std::string name_;
    int points_;
};

int main() {
    Student student("Alice", 42);
    student.print();
}
```

The public part is the interface. The private part is implementation detail.

## Encapsulation

Encapsulation means that the class protects its own data. Instead of making
fields public, provide methods that keep the object valid:

```cpp
class Counter {
public:
    void increment() {
        ++value_;
    }

    int value() const {
        return value_;
    }

private:
    int value_ = 0;
};
```

Code outside the class cannot accidentally assign an invalid internal state.

## Constructors

A constructor prepares an object for use:

```cpp
class Rectangle {
public:
    Rectangle(double width, double height)
        : width_(width), height_(height) {
    }

    double area() const {
        return width_ * height_;
    }

private:
    double width_;
    double height_;
};
```

Prefer initializing fields in the initializer list.

## `const` Methods and `this`

A method marked with `const` promises not to modify the object:

```cpp
double area() const {
    return width_ * height_;
}
```

Inside a method, `this` points to the current object. You rarely need to write
`this` explicitly in beginner code, but it helps explain what method calls do.

## Inheritance

Inheritance lets one class reuse or specialize another class:

```cpp
#include <iostream>
#include <string>

class Person {
public:
    explicit Person(const std::string& name) : name_(name) {
    }

    void printName() const {
        std::cout << name_ << std::endl;
    }

private:
    std::string name_;
};

class Teacher : public Person {
public:
    Teacher(const std::string& name, const std::string& subject)
        : Person(name), subject_(subject) {
    }

private:
    std::string subject_;
};
```

Use inheritance carefully. If one class is not a real specialized version of
another class, composition is often clearer.

## Virtual Methods and Polymorphism

Polymorphism means that code can call the same method through a base interface,
while the actual implementation depends on the object type:

```cpp
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
    virtual std::string description() const = 0;
};

class Square : public Shape {
public:
    explicit Square(double side) : side_(side) {
    }

    double area() const override {
        return side_ * side_;
    }

    std::string description() const override {
        return "square";
    }

private:
    double side_;
};

class Circle : public Shape {
public:
    explicit Circle(double radius) : radius_(radius) {
    }

    double area() const override {
        return 3.14159 * radius_ * radius_;
    }

    std::string description() const override {
        return "circle";
    }

private:
    double radius_;
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Square>(4.0));
    shapes.push_back(std::make_unique<Circle>(2.0));

    for (const auto& shape : shapes) {
        std::cout << shape->description()
                  << ": " << shape->area() << std::endl;
    }
}
```

`Shape` is abstract because it has pure virtual methods. `Square` and `Circle`
provide concrete implementations.

## Why the Virtual Destructor Matters

When a derived object is deleted through a base pointer, the base class should
have a virtual destructor:

```cpp
virtual ~Shape() = default;
```

This is a standard safety rule for base classes used polymorphically.

## Operator Overloading

Operator overloading lets a class define how an operator works for its objects:

```cpp
class Point {
public:
    Point(int x, int y) : x_(x), y_(y) {
    }

    Point operator+(const Point& other) const {
        return Point(x_ + other.x_, y_ + other.y_);
    }

private:
    int x_;
    int y_;
};
```

Use operator overloading only when the operator has a natural meaning for the
type.

## Bridge Exercise: Shapes and Polymorphism

Write a console program that:

- defines an abstract base class `Shape`,
- defines derived classes `Square` and `Circle`,
- calculates the area of each shape,
- returns a description of each shape,
- stores different shapes through base-class pointers,
- iterates over the collection and calls methods polymorphically.

Minimum technical requirements:

- C++17,
- pure virtual methods,
- virtual destructor in the base class,
- private fields in derived classes,
- `const` methods for read-only operations,
- `override` in derived classes,
- `std::vector` for the collection,
- `std::unique_ptr<Shape>` for ownership,
- compilation with `-Wall -Wextra -pedantic`.

Suggested steps:

1. Write the abstract class `Shape`.
2. Add `Square` and test area calculation.
3. Add `Circle` and a constant for pi.
4. Add `description` to every derived class.
5. Store shapes in one collection through base-class pointers.
6. Print every description and area in a loop.
7. Add validation for dimensions.

Extra tasks:

- add `Rectangle`,
- add `Triangle`,
- add perimeter calculation,
- sort shapes by area,
- calculate total area,
- save the shape list to a file.

## Checklist

Before moving on, make sure that your code:

- keeps fields private,
- initializes objects through constructors,
- marks read-only methods as `const`,
- uses `override` for overridden virtual methods,
- uses a virtual destructor in polymorphic base classes,
- separates object logic from input/output when possible,
- compiles without warnings.
