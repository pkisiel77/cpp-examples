# English Ebook

This directory contains the English ebook source files and build configuration.
The English edition covers the full learning path from environment setup to
final projects. It is written as a practical student-facing version, not as a
literal line-by-line translation of the Polish materials.

Current version: `0.7.1-en`.

## Files

- [metadata.yaml](metadata.yaml) - metadata for `pandoc`.
- [front-matter.md](front-matter.md) - English title and introduction.
- [course-plan.md](course-plan.md) - English course plan and translation roadmap.
- [manifest.txt](manifest.txt) - source file order.
- [../CHANGELOG.md](../CHANGELOG.md) - ebook version history.

## Chapters

The manifest currently includes:

1. `00-start` - development environment, compiler, editor, Git, and CMake.
2. `01-basics` - first program, input/output, types, variables, and operators.
3. `02-control-flow-loops` - conditions, `switch`, loops, `break`, `continue`.
4. `03-functions-arrays-strings` - functions, arrays, matrices, and strings.
5. `04-pointers-references-memory` - addresses, pointers, references, and memory safety.
6. `05-files-exceptions` - text files, validation, and exceptions.
7. `06-oop` - classes, objects, constructors, inheritance, and polymorphism.
8. `07-stl-data-structures` - STL containers, algorithms, maps, stacks, queues, and lists.
9. `08-project-build-tests` - multi-file projects, build scripts, tests, and CI.
10. `09-modern-cpp` - selected modern C++ features.
11. `10-projects` - final projects, checklist, and grading rubric.

## Download

Ready-to-use files are available in the shared download directory:

- [PDF EN](../download/cpp-course-en.pdf),
- [EPUB EN](../download/cpp-course-en.epub).

## Build

From the repository root:

```sh
EBOOK_LANG=en sh tools/build-ebook.sh
```

The command creates:

- `ebook/build/cpp-course-en.md`,
- `ebook/build/cpp-course-en.pdf`,
- `ebook/build/cpp-course-en.epub`.

After review, the generated PDF and EPUB can be copied to `ebook/download/`.

## Editorial Notes

- Keep English explanations simple and practical.
- Keep code examples compatible with C++17 unless a chapter explicitly explains
  a newer feature.
- Do not include archive materials in the ebook.
- Update `metadata.yaml`, `front-matter.md`, `manifest.txt`, and
  `../CHANGELOG.md` when changing the released ebook structure.
