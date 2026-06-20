# English Version Plan

## Goal

The English edition should become a downloadable version of the C++ course for
students who want to learn from the same material as the Polish course.

The current English edition covers the full learning path from `00-start` to
`10-projects`. Further work should focus on review, examples, consistency, and
future polishing rather than creating the first structure.

## Learning Path

1. `00-start` - development environment, compiler, editor, Git, and CMake.
2. `01-basics` - first program, input/output, types, variables, and operators.
3. `02-control-flow-loops` - conditions, `switch`, loops, `break`, `continue`.
4. `03-functions-arrays-strings` - functions, arrays, matrices, and strings.
5. `04-pointers-references-memory` - addresses, pointers, references, and safe memory habits.
6. `05-files-exceptions` - text files, validation, and exceptions.
7. `06-oop` - classes, objects, constructors, encapsulation, inheritance, and operators.
8. `07-stl-data-structures` - STL containers, algorithms, maps, stacks, queues, and lists.
9. `08-project-build-tests` - multi-file projects, build scripts, tests, and CI.
10. `09-modern-cpp` - selected modern C++ features, lambdas, move semantics, namespaces, and threads.
11. `10-projects` - final project topics, grading checklists, and project planning.

## Translation Batches

### Batch 1

- Main repository introduction - draft added.
- Ebook front matter - draft added.
- `00-start` - first English chapter added.
- `01-basics` - first English chapter added.

### Batch 2

- `02-control-flow-loops` - first English chapter added.
- Bridge exercise: minimum, maximum, and average - included in the chapter.

### Batch 3

- `03-functions-arrays-strings` - first English chapter added.
- Bridge exercise: GADERYPOLUKI cipher - included in the chapter.

### Batch 4

- `04-pointers-references-memory` - first English chapter added.
- `05-files-exceptions` - first English chapter added.
- `06-oop` - first English chapter added.
- Bridge exercise: figures and polymorphism - included in the chapter.

### Batch 5

- `07-stl-data-structures` - first English chapter added.
- `08-project-build-tests` - first English chapter added.
- Bridge exercise: RPN calculator - included in the chapter.

### Batch 6

- `09-modern-cpp` - first English chapter added.
- `10-projects` - first English chapter added.
- Project checklist and grading card - included in the project chapter.

## Editorial Rules

- Keep the English text simple and practical.
- Do not translate code identifiers unless the example itself is rewritten.
- Prefer short paragraphs and clear section titles.
- Keep exercises close to the Polish version, but adjust wording for an English-speaking student.
- Do not include archive materials in the ebook.
- Keep the Polish and English ebook versions buildable by the same script.

## YouTube Support

The first bilingual video format should be short quizzes:

- Polish question first.
- English question second.
- One C++ concept per video.
- Link to the repository and both ebook downloads in the description.

Example:

```text
C++ Quiz #1
What will this program print?

int x = 5;
std::cout << x++ << " " << x;

A) 5 5
B) 5 6
C) 6 6
```

Answer: `B) 5 6`, because postfix `x++` returns the current value first and
increments the variable afterwards.

## Current Downloadable English Edition

The current downloadable English edition is:

- title: `C++ Course`
- version: `0.7.1-en`
- scope: full learning path `00`-`10`
- output files:
  - `ebook/download/cpp-course-en.pdf`
  - `ebook/download/cpp-course-en.epub`
