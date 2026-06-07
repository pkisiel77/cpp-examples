# 04 - Kompilacja i prosty build

## Cel lekcji

Celem lekcji jest zrozumienie, jak kompilować projekt złożony z kilku plików
oraz czym różni się kompilacja od linkowania. Student powinien umieć zbudować
aplikację jedną komendą, przygotować pliki obiektowe i użyć prostego skryptu
build.

## Wymagania wstępne

Przed rozpoczęciem lekcji warto znać:

- podział programu na pliki `.h` i `.cpp`,
- strukturę projektu z katalogami `include`, `src`, `tests` i `build`,
- podstawową komendę kompilacji `c++`.

## Kompilacja wielu plików jedną komendą

Najprostszy sposób budowania małego projektu to podanie kompilatorowi wszystkich
plików `.cpp`:

```sh
c++ -std=c++17 \
  -I examples/project-layout/include \
  examples/project-layout/src/main.cpp \
  examples/project-layout/src/counter.cpp \
  -o examples/project-layout/build/task_counter_app
```

Znaczenie elementów komendy:

- `-std=c++17` - wybiera standard języka,
- `-I .../include` - wskazuje katalog z własnymi nagłówkami,
- pliki `.cpp` - kod źródłowy do skompilowania,
- `-o ...` - nazwa programu wynikowego.

## Ostrzeżenia kompilatora

Podczas nauki warto kompilować z ostrzeżeniami:

```sh
-Wall -Wextra -pedantic
```

Pełna komenda:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic \
  -I examples/project-layout/include \
  examples/project-layout/src/main.cpp \
  examples/project-layout/src/counter.cpp \
  -o examples/project-layout/build/task_counter_app
```

Ostrzeżenia nie zawsze zatrzymują kompilację, ale często pokazują błąd, który
później będzie trudny do znalezienia.

## Kompilacja i linkowanie

Budowanie programu można rozbić na dwa kroki.

Pierwszy krok tworzy pliki obiektowe `.o`:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic \
  -I examples/project-layout/include \
  -c examples/project-layout/src/counter.cpp \
  -o examples/project-layout/build/counter.o
```

```sh
c++ -std=c++17 -Wall -Wextra -pedantic \
  -I examples/project-layout/include \
  -c examples/project-layout/src/main.cpp \
  -o examples/project-layout/build/main.o
```

Drugi krok linkuje pliki obiektowe w program:

```sh
c++ examples/project-layout/build/main.o \
  examples/project-layout/build/counter.o \
  -o examples/project-layout/build/task_counter_app
```

Kompilacja sprawdza pojedyncze pliki źródłowe. Linkowanie łączy gotowe fragmenty
w program wykonywalny.

## Typowe błędy

### Brak katalogu z nagłówkami

Jeśli zabraknie flagi `-I`, kompilator może zgłosić:

```text
fatal error: 'task_counter/counter.h' file not found
```

### Brak pliku implementacji

Jeśli podczas linkowania pominiemy `counter.cpp` albo `counter.o`, linker może
zgłosić błąd podobny do:

```text
undefined reference to `Counter::addTask()'
```

### Artefakty w repozytorium

Programy wynikowe, pliki `.o` i tymczasowe katalogi build nie powinny trafiać do
commita. Kod źródłowy powinien wystarczyć do odtworzenia tych plików.

## Prosty skrypt build

Dłuższe komendy warto zapisać w skrypcie:

```sh
sh examples/project-layout/build.sh
```

Skrypt w przykładzie:

- tworzy katalog `build`,
- kompiluje aplikację,
- kompiluje testy,
- uruchamia testy.

Domyślnie zapisuje wyniki w `examples/project-layout/build`. Dla czystej
weryfikacji można wskazać inny katalog:

```sh
BUILD_DIR=/tmp/task-counter-build sh examples/project-layout/build.sh
```

## Kompletny przykład

Przykład znajduje się w katalogu
[`examples/project-layout`](examples/project-layout).

Uruchomienie pełnego buildu:

```sh
BUILD_DIR=/tmp/task-counter-build sh examples/project-layout/build.sh
```

Uruchomienie aplikacji po buildzie:

```sh
/tmp/task-counter-build/task_counter_app
```

## Zadania do wykonania

1. Zbuduj aplikację jedną komendą `c++`.
2. Zbuduj aplikację w dwóch krokach: pliki `.o`, a potem linkowanie.
3. Uruchom `build.sh` z domyślnym katalogiem `build`.
4. Uruchom `build.sh` z katalogiem ustawionym przez `BUILD_DIR`.
5. Celowo usuń z komendy plik `counter.cpp` i przeczytaj komunikat linkera.

## Kryteria zaliczenia

Student zalicza lekcję, jeśli potrafi:

- skompilować projekt z wieloma plikami `.cpp`,
- użyć flag `-std`, `-Wall`, `-Wextra`, `-pedantic` i `-I`,
- odróżnić kompilację od linkowania,
- utworzyć plik obiektowy `.o`,
- zlinkować pliki obiektowe w program,
- uruchomić prosty skrypt build,
- nie commitować plików wynikowych.
