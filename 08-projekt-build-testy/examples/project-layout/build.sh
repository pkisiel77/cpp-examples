#!/bin/sh

set -eu

PROJECT_DIR=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
BUILD_DIR=${BUILD_DIR:-"$PROJECT_DIR/build"}
CXX=${CXX:-c++}
CXXFLAGS=${CXXFLAGS:-"-std=c++17 -Wall -Wextra -pedantic"}

mkdir -p "$BUILD_DIR"

"$CXX" $CXXFLAGS \
  -I "$PROJECT_DIR/include" \
  "$PROJECT_DIR/src/main.cpp" \
  "$PROJECT_DIR/src/counter.cpp" \
  -o "$BUILD_DIR/task_counter_app"

"$CXX" $CXXFLAGS \
  -I "$PROJECT_DIR/include" \
  "$PROJECT_DIR/tests/counter_tests.cpp" \
  "$PROJECT_DIR/src/counter.cpp" \
  -o "$BUILD_DIR/counter_tests"

"$BUILD_DIR/counter_tests"

echo "Build finished: $BUILD_DIR"
