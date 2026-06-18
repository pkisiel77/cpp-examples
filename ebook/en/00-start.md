# 00 - Start

This chapter prepares the technical environment for learning C++. It is meant
for students who are starting with a compiler, code editor, terminal, Git, and
simple project structure.

## Learning Goals

After this chapter you should be able to:

- explain what a C++ compiler does,
- compile and run a simple `.cpp` file,
- use a terminal for basic commands,
- open and edit source files in Visual Studio Code or another editor,
- understand why Git is useful during programming exercises,
- understand the role of `CMakeLists.txt` in larger projects,
- move safely to the first C++ programming chapter.

## What You Need

You need:

- a C++ compiler with C++17 support,
- a text editor or IDE,
- a terminal,
- Git,
- access to this repository.

On macOS and Linux, the compiler is often available as `c++`, `clang++`, or
`g++`. On Windows, students usually use MSYS2, Visual Studio Build Tools, or an
IDE configured by the teacher.

## First Compiler Check

Open a terminal and run:

```sh
c++ --version
```

If the command prints compiler information, you can continue. If it says that
the command is missing, install a compiler before moving forward.

## First Program

Create a file named `hello.cpp`:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, C++!" << std::endl;
    return 0;
}
```

Compile it:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic hello.cpp -o hello
```

Run it:

```sh
./hello
```

Expected output:

```text
Hello, C++!
```

## Editor

Use an editor that lets you:

- open folders,
- edit `.cpp` files,
- open an integrated terminal,
- see compiler errors clearly.

Visual Studio Code is a practical default for beginners, but the course does
not depend on one specific editor.

## Git Basics

Git helps you save progress and review changes. For this course, the most
important commands are:

```sh
git status
git add file.cpp
git commit -m "Describe the change"
```

At the beginning, treat Git as a history of your learning steps. Commit small,
working changes.

## CMake in One Sentence

CMake is a build configuration tool. In small exercises you can compile one
file manually. In larger projects, CMake or a build script describes how many
source files should be compiled together.

## Student Checklist

Before going to the next chapter, make sure you can:

- open a terminal,
- check the compiler version,
- compile `hello.cpp`,
- run the generated program,
- explain what source file and executable mean,
- check Git status in a repository.

## Next Step

Go to chapter `01 - Basics` and write your first simple console programs.
