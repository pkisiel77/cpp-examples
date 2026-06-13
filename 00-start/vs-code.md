# Visual Studio Code dla C++

## Cel lekcji

Celem lekcji jest przygotowanie edytora Visual Studio Code do pracy z kodem
C++. Po tej lekcji student powinien umieć otworzyć katalog projektu, edytować
plik `.cpp`, uruchomić terminal w edytorze i skompilować program.

## Wymagania wstępne

Przed lekcją student powinien:

- mieć zainstalowany kompilator C++,
- umieć otworzyć terminal,
- znać podstawowe polecenie kompilacji z lekcji
  [kompilator.md](kompilator.md).

## Krótka teoria

Visual Studio Code jest edytorem kodu. Sam edytor nie jest kompilatorem.
Do pracy z C++ potrzebne są dwa elementy:

- edytor, w którym piszemy kod,
- kompilator, który tłumaczy kod na program wykonywalny.

VS Code może ułatwiać pracę przez:

- podświetlanie składni,
- podpowiedzi kodu,
- wbudowany terminal,
- szybkie wyszukiwanie w projekcie,
- integrację z Git,
- konfigurację zadań kompilacji.

## Zalecane rozszerzenia

Na start wystarczy:

- `C/C++` od Microsoft,
- opcjonalnie `CMake Tools`, jeśli projekt używa CMake.

Rozszerzenia pomagają w edycji kodu, ale nie zastępują kompilatora.
Jeśli `g++ --version` albo `clang++ --version` nie działa w terminalu,
VS Code również nie skompiluje programu.

## Przykład praktyczny

1. Otwórz VS Code.
2. Wybierz `File -> Open Folder`.
3. Otwórz katalog z ćwiczeniem.
4. Utwórz plik `main.cpp`.
5. Wklej kod:

```cpp
#include <iostream>

int main()
{
    std::cout << "Program uruchomiony z VS Code\n";
    return 0;
}
```

6. Otwórz terminal w VS Code:

```text
Terminal -> New Terminal
```

7. Skompiluj program:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o app
```

8. Uruchom program:

```bash
./app
```

Na Windows z MinGW:

```bash
app.exe
```

## Typowe problemy

### Terminal otwiera się w złym katalogu

Sprawdź aktualny katalog:

```bash
pwd
```

Na Windows w `cmd`:

```bat
cd
```

Jeśli terminal nie jest w katalogu z plikiem `main.cpp`, przejdź do właściwego
katalogu poleceniem `cd`.

### VS Code nie widzi kompilatora

Sprawdź w terminalu VS Code:

```bash
g++ --version
```

Jeśli polecenie nie działa, problem dotyczy instalacji kompilatora albo
zmiennej `PATH`, a nie samego kodu C++.

### Podkreślenia w edytorze nie zawsze są błędem kompilacji

Najważniejszy jest wynik kompilacji w terminalu. Podpowiedzi edytora mogą być
pomocne, ale ostatecznie kod musi przejść przez kompilator.

## Zadania do wykonania

1. Otwórz katalog ćwiczenia w VS Code.
2. Utwórz plik `main.cpp`.
3. Wpisz prosty program wypisujący tekst.
4. Otwórz terminal w VS Code.
5. Sprawdź wersję kompilatora.
6. Skompiluj i uruchom program.
7. Zmień wypisywany tekst i uruchom program ponownie.

## Kryteria zaliczenia

Lekcja jest zaliczona, jeśli student potrafi:

- otworzyć katalog projektu w VS Code,
- utworzyć i zapisać plik `.cpp`,
- uruchomić terminal w VS Code,
- sprawdzić dostępność kompilatora,
- skompilować program z terminala,
- uruchomić program wynikowy.

## Źródła

- Dokumentacja VS Code: `Using GCC with MinGW`.
