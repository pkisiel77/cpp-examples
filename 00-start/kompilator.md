# Kompilator C++

## Cel lekcji

Celem lekcji jest zrozumienie, czym jest kompilator i jak użyć go do
uruchomienia pierwszego programu C++. Po tej lekcji student powinien potrafić
sprawdzić, czy kompilator jest zainstalowany, skompilować prosty plik `.cpp`
i uruchomić powstały program.

## Wymagania wstępne

Przed lekcją student powinien umieć:

- otworzyć terminal,
- przejść do katalogu z plikami,
- utworzyć prosty plik tekstowy,
- rozpoznać rozszerzenie pliku, np. `.cpp`.

## Krótka teoria

Język programowania jest sposobem zapisu obliczeń w formie zrozumiałej dla
ludzi i możliwej do przetworzenia przez maszynę. Kompilator tłumaczy kod
źródłowy C++ na program wykonywalny.

Typowy przepływ pracy wygląda tak:

1. Programista pisze kod w pliku, np. `main.cpp`.
2. Kompilator sprawdza składnię i typy.
3. Jeśli kod jest poprawny, powstaje program wykonywalny.
4. Program można uruchomić w terminalu.

Najczęściej używane kompilatory C++:

- `g++` - część GCC, często używany na Linuxie i w MinGW,
- `clang++` - często dostępny na macOS i Linuxie,
- `cl` - kompilator Microsoft Visual C++ na Windows.

W tym repozytorium przykłady zakładają standard C++17.

## Sprawdzenie kompilatora

W terminalu uruchom jedno z poleceń:

```bash
g++ --version
```

albo:

```bash
clang++ --version
```

Jeśli terminal wypisze wersję kompilatora, środowisko jest gotowe do prostych
ćwiczeń. Jeśli pojawi się komunikat typu `command not found`, kompilator nie
jest zainstalowany albo nie jest dostępny w zmiennej `PATH`.

## Przykład praktyczny

Utwórz plik `main.cpp`:

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, C++!\n";
    return 0;
}
```

Skompiluj program:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o hello
```

Uruchom program na Linuxie albo macOS:

```bash
./hello
```

Na Windows, jeśli używasz MinGW:

```bash
hello.exe
```

Oczekiwany wynik:

```text
Hello, C++!
```

## Znaczenie flag kompilacji

W poleceniu:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o hello
```

poszczególne elementy oznaczają:

- `g++` - uruchomienie kompilatora,
- `-std=c++17` - użycie standardu C++17,
- `-Wall` - włączenie podstawowych ostrzeżeń,
- `-Wextra` - włączenie dodatkowych ostrzeżeń,
- `-pedantic` - dokładniejsze sprawdzanie zgodności ze standardem,
- `main.cpp` - plik źródłowy,
- `-o hello` - nazwa programu wynikowego.

Ostrzeżenia nie zawsze zatrzymują kompilację, ale warto je traktować poważnie.
Na kursie kod powinien kompilować się bez błędów i bez ostrzeżeń.

## Typowe problemy

### Brak kompilatora

Objaw:

```text
g++: command not found
```

Co sprawdzić:

- czy kompilator jest zainstalowany,
- czy terminal został uruchomiony ponownie po instalacji,
- czy katalog z kompilatorem jest dodany do `PATH`.

### Błąd składni

Przykład:

```cpp
std::cout << "Hello"
```

Brakuje średnika. Kompilator wskaże linię, w której znalazł problem albo jego
skutek.

### Niepoprawna nazwa pliku

Jeśli kompilujesz `main.cpp`, a plik nazywa się inaczej, kompilator zgłosi, że
nie może znaleźć pliku. Przed kompilacją warto sprawdzić zawartość katalogu:

```bash
ls
```

Na Windows w klasycznym `cmd`:

```bat
dir
```

## Zadania do wykonania

1. Sprawdź wersję kompilatora poleceniem `g++ --version` albo
   `clang++ --version`.
2. Utwórz plik `main.cpp` z programem wypisującym `Hello, C++!`.
3. Skompiluj program z flagami `-std=c++17 -Wall -Wextra -pedantic`.
4. Uruchom program w terminalu.
5. Celowo usuń średnik z programu, skompiluj ponownie i przeczytaj komunikat
   błędu.
6. Przywróć poprawny kod i upewnij się, że program kompiluje się bez ostrzeżeń.

## Kryteria zaliczenia

Lekcja jest zaliczona, jeśli student potrafi:

- sprawdzić wersję kompilatora,
- wyjaśnić różnicę między plikiem źródłowym a programem wykonywalnym,
- skompilować prosty program C++,
- uruchomić program z terminala,
- rozpoznać podstawowy błąd składni,
- skompilować kod z flagami `-Wall -Wextra -pedantic`.

## Źródła

- Aho, A. V.; Lam, M. S.; Sethi, R.; Ullman, J., `Kompilatory`, s. 1.
