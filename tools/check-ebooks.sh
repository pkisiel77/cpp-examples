#!/bin/sh

set -eu

build_dir=${BUILD_DIR:-ebook/build}

echo "build PL ebook"
OUT_DIR="$build_dir" EBOOK_LANG=pl sh tools/build-ebook.sh

echo "build EN ebook"
OUT_DIR="$build_dir" EBOOK_LANG=en sh tools/build-ebook.sh

check_file() {
    file=$1
    if [ ! -s "$file" ]; then
        echo "Missing or empty ebook artifact: $file" >&2
        exit 1
    fi
}

check_file "$build_dir/cpp-kurs.pdf"
check_file "$build_dir/cpp-kurs.epub"
check_file "$build_dir/cpp-course-en.pdf"
check_file "$build_dir/cpp-course-en.epub"

check_file ebook/download/cpp-kurs.pdf
check_file ebook/download/cpp-kurs.epub
check_file ebook/download/cpp-course-en.pdf
check_file ebook/download/cpp-course-en.epub

echo "All ebook checks passed"
