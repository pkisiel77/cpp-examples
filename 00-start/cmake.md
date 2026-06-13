# CMake - pierwsze wprowadzenie

## Cel lekcji

Celem lekcji jest zrozumienie, po co używa się CMake i jak wygląda minimalny
plik `CMakeLists.txt` dla prostego programu C++. Po tej lekcji student powinien
umieć odróżnić ręczną kompilację pojedynczego pliku od budowania projektu.

## Wymagania wstępne

Przed lekcją student powinien:

- umieć skompilować pojedynczy plik `.cpp`,
- znać podstawowe pojęcie katalogu projektu,
- umieć uruchomić polecenie w terminalu.

## Krótka teoria

CMake nie jest kompilatorem. CMake jest narzędziem, które generuje konfigurację
budowania projektu dla właściwego kompilatora i systemu build.

Ręczna kompilacja jest wygodna dla jednego pliku:

```bash
g++ main.cpp -o app
```

Przy większym projekcie pojawiają się dodatkowe problemy:

- wiele plików `.cpp`,
- katalogi z nagłówkami,
- biblioteki,
- testy,
- różne systemy operacyjne,
- różne kompilatory.

CMake pomaga opisać projekt w jednym miejscu.

## Minimalny projekt

Przykładowa struktura:

```text
hello-cmake/
  CMakeLists.txt
  main.cpp
```

Plik `main.cpp`:

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello from CMake\n";
    return 0;
}
```

Plik `CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.16)

project(hello_cmake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hello main.cpp)
```

## Budowanie projektu

W katalogu projektu uruchom:

```bash
cmake -S . -B build
```

Następnie:

```bash
cmake --build build
```

Uruchomienie programu zależy od systemu i generatora. Na Linuxie albo macOS
często będzie to:

```bash
./build/hello
```

Na Windows plik wykonywalny może znaleźć się głębiej w katalogu `build`,
zależnie od użytego generatora.

## Znaczenie poleceń

```bash
cmake -S . -B build
```

oznacza:

- `-S .` - katalog ze źródłami znajduje się tutaj,
- `-B build` - pliki budowania mają powstać w katalogu `build`.

```bash
cmake --build build
```

oznacza:

- zbuduj projekt używając konfiguracji zapisanej w katalogu `build`.

## Typowe problemy

### CMake nie jest kompilatorem

Jeśli kompilator nie jest zainstalowany, CMake nie rozwiąże tego problemu.
Najpierw sprawdź:

```bash
g++ --version
```

albo:

```bash
clang++ --version
```

### Literówka w nazwie pliku

Jeśli w `CMakeLists.txt` wpiszesz `main.cpp`, a plik nazywa się inaczej,
budowanie zakończy się błędem.

### Mieszanie plików źródłowych i build

Katalog `build/` powinien zawierać pliki generowane. Nie należy ręcznie
edytować większości plików w tym katalogu.

## Zadania do wykonania

1. Sprawdź wersję CMake:

```bash
cmake --version
```

2. Utwórz katalog `hello-cmake`.
3. Dodaj pliki `main.cpp` i `CMakeLists.txt`.
4. Wygeneruj katalog budowania poleceniem `cmake -S . -B build`.
5. Zbuduj projekt poleceniem `cmake --build build`.
6. Uruchom powstały program.
7. Zmień tekst wypisywany przez program i zbuduj projekt ponownie.

## Checklist dla studenta

Przed zaliczeniem lekcji sprawdź, czy potrafisz:

- wskazać rolę pliku `CMakeLists.txt`,
- utworzyć katalog build poza kodem źródłowym,
- uruchomić `cmake -S . -B build`,
- zbudować projekt komendą `cmake --build build`,
- odróżnić pliki źródłowe od wygenerowanych artefaktów.

## Kryteria zaliczenia

Lekcja jest zaliczona, jeśli student potrafi:

- wyjaśnić, że CMake nie jest kompilatorem,
- napisać minimalny `CMakeLists.txt`,
- wygenerować katalog `build`,
- zbudować projekt poleceniem `cmake --build`,
- uruchomić powstały program,
- wskazać, po co oddziela się katalog źródeł od katalogu `build`.
