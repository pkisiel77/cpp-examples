#!/bin/sh

set -eu

CXX=${CXX:-c++}
BUILD_DIR=${BUILD_DIR:-build}

mkdir -p "$BUILD_DIR"

"$CXX" -std=c++17 -Wall -Wextra -pedantic src/main.cpp -o "$BUILD_DIR/projekt"

echo "Build finished: $BUILD_DIR/projekt"
