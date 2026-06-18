# English Ebook Draft

This directory contains the first English ebook draft and build configuration.
It is intentionally smaller than the Polish source material. The goal is to
prepare the English structure before translating the full course.

## Files

- [metadata.yaml](metadata.yaml) - metadata for `pandoc`.
- [front-matter.md](front-matter.md) - English title and introduction.
- [course-plan.md](course-plan.md) - English course plan and translation roadmap.
- [manifest.txt](manifest.txt) - source file order.
- [../CHANGELOG.md](../CHANGELOG.md) - ebook version history.

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
