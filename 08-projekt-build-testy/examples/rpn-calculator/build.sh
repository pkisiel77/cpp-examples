#!/bin/sh
set -eu

cd "$(dirname "$0")"

CXX=${CXX:-c++}
STD=${STD:--std=c++17}
BUILD_DIR=${BUILD_DIR:-build}

mkdir -p "$BUILD_DIR"

"$CXX" "$STD" -Wall -Wextra -pedantic \
    -I include \
    src/main.cpp src/calculator.cpp \
    -o "$BUILD_DIR/rpn-calculator"

"$CXX" "$STD" -Wall -Wextra -pedantic \
    -I include \
    tests/rpn_tests.cpp src/calculator.cpp \
    -o "$BUILD_DIR/rpn-tests"

"$BUILD_DIR/rpn-tests"

echo "RPN calculator build passed"
