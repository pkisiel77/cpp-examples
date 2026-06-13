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

echo "test 01 basics"
"$CXX" "$STD" -Wall -Wextra -pedantic \
    01-podstawy/tests/test_podstawy.cpp \
    -o "$BUILD_DIR/01_test_podstawy"
"$BUILD_DIR/01_test_podstawy"

echo "test 02 control-flow"
"$CXX" "$STD" -Wall -Wextra -pedantic \
    02-sterowanie-i-petle/tests/test_sterowanie_petle.cpp \
    -o "$BUILD_DIR/02_test_sterowanie_petle"
"$BUILD_DIR/02_test_sterowanie_petle"

echo "test 03 functions"
"$CXX" "$STD" -Wall -Wextra -pedantic \
    03-funkcje-tablice-napisy/tests/test_podstawowe_funkcje.cpp \
    -o "$BUILD_DIR/03_test_podstawowe_funkcje"
"$BUILD_DIR/03_test_podstawowe_funkcje"

echo "test 04 pointers-references"
"$CXX" "$STD" -Wall -Wextra -pedantic \
    04-wskazniki-referencje-pamiec/tests/test_wskazniki_referencje.cpp \
    -o "$BUILD_DIR/04_test_wskazniki_referencje"
"$BUILD_DIR/04_test_wskazniki_referencje"

echo "test 05 validation"
"$CXX" "$STD" -Wall -Wextra -pedantic \
    05-pliki-wyjatki/tests/test_walidacja.cpp \
    -o "$BUILD_DIR/05_test_walidacja"
"$BUILD_DIR/05_test_walidacja"

echo "test 06 oop"
"$CXX" "$STD" -Wall -Wextra -pedantic \
    06-oop/tests/test_konto.cpp \
    -o "$BUILD_DIR/06_test_konto"
"$BUILD_DIR/06_test_konto"

echo "test 07 stl"
"$CXX" "$STD" -Wall -Wextra -pedantic \
    07-stl-struktury-danych/tests/test_stl_algorytmy.cpp \
    -o "$BUILD_DIR/07_test_stl_algorytmy"
"$BUILD_DIR/07_test_stl_algorytmy"

echo "test 09 modern-cpp"
"$CXX" "$STD" -Wall -Wextra -pedantic \
    09-modern-cpp/tests/test_modern_cpp.cpp \
    -o "$BUILD_DIR/09_test_modern_cpp"
"$BUILD_DIR/09_test_modern_cpp"

echo "compile 09 code-organization"
"$CXX" "$STD" -Wall -Wextra -pedantic \
    09-modern-cpp/examples/code-organization/main.cpp \
    09-modern-cpp/examples/code-organization/message.cpp \
    -o "$BUILD_DIR/09_code_organization"

echo "All example checks passed"
