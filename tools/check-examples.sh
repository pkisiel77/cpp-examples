#!/bin/sh

set -eu

CXX=${CXX:-c++}
STD=${STD:--std=c++17}
BUILD_DIR=${BUILD_DIR:-/tmp/cpp-examples-build}

mkdir -p "$BUILD_DIR"

compile_one() {
    src=$1
    name=$(printf '%s' "$src" | sed 's#^\./##; s#[/.]#_#g')
    out="$BUILD_DIR/$name"
    extra_flags=""

    case "$src" in
        *thread_basics.cpp)
            extra_flags="-pthread"
            ;;
    esac

    echo "compile $src"
    # shellcheck disable=SC2086
    "$CXX" "$STD" -Wall -Wextra -pedantic $extra_flags "$src" -o "$out"
}

find . \
    -path './.git' -prune -o \
    -path './*/archive/*' -prune -o \
    -path './08-projekt-build-testy/examples/project-layout/*' -prune -o \
    -path './08-projekt-build-testy/examples/split-project/*' -prune -o \
    -path './09-modern-cpp/examples/code-organization/*' -prune -o \
    -type f -path './*/examples/*.cpp' -print |
while IFS= read -r src; do
    case "$src" in
        ./08-projekt-build-testy/examples/syntax-check/student_report.cpp)
            echo "syntax $src"
            "$CXX" "$STD" -Wall -Wextra -pedantic -fsyntax-only "$src"
            ;;
        *)
            compile_one "$src"
            ;;
    esac
done

echo "compile 08 split-project"
"$CXX" "$STD" -Wall -Wextra -pedantic \
    08-projekt-build-testy/examples/split-project/main.cpp \
    08-projekt-build-testy/examples/split-project/calculator.cpp \
    -o "$BUILD_DIR/08_split_project"

echo "build 08 project-layout"
BUILD_DIR="$BUILD_DIR/08_project_layout" sh 08-projekt-build-testy/examples/project-layout/build.sh

echo "compile 09 code-organization"
"$CXX" "$STD" -Wall -Wextra -pedantic \
    09-modern-cpp/examples/code-organization/main.cpp \
    09-modern-cpp/examples/code-organization/message.cpp \
    -o "$BUILD_DIR/09_code_organization"

echo "All example checks passed"
