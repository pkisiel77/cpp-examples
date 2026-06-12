Here's a simple example of a modular system in C++ using header files:

```cpp
// module1.h
#ifndef MODULE1_H
#define MODULE1_H

void printMessage();

#endif

// module1.cpp
#include "module1.h"
#include <iostream>

void printMessage() {
  std::cout << "This is a message from module 1." << std::endl;
}

// main.cpp
#include "module1.h"

int main() {
  printMessage();
  return 0;
}

```
In this example, the function printMessage is declared in the header file module1.h and defined in the module1.cpp file. The header file acts as an interface to the implementation in the module1.cpp file, allowing the implementation to change without affecting the code in main.cpp.

The header file is included in main.cpp so that the function printMessage can be used in main. When the program is compiled and run, it will print "This is a message from module 1." to the console.
