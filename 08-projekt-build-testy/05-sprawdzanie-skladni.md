# 05 - Sprawdzanie składni

## Cel lekcji

Celem lekcji jest nauczenie się szybkiego sprawdzania kodu C++ bez tworzenia
programu wynikowego. Student powinien umieć użyć kompilatora do kontroli
składni, włączyć ostrzeżenia i odróżnić błąd kompilacji od błędu linkowania.

## Wymagania wstępne

Przed rozpoczęciem lekcji warto znać:

- kompilację pojedynczego pliku `.cpp`,
- kompilację projektu z kilkoma plikami,
- podstawowe flagi `-std`, `-Wall`, `-Wextra` i `-I`.

## Po co sprawdzać składnię osobno

Pełna kompilacja tworzy program wykonywalny. Czasem chcemy szybciej sprawdzić,
czy plik jest poprawny składniowo, ale jeszcze nie potrzebujemy programu.

Do tego służy flaga:

```sh
-fsyntax-only
```

Kompilator analizuje plik i zgłasza błędy, ale nie tworzy pliku `.o` ani
programu wynikowego.

## Podstawowa komenda

Dla pojedynczego pliku:

```sh
c++ -std=c++17 -fsyntax-only examples/syntax-check/student_report.cpp
```

Warto od razu dodać ostrzeżenia:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic -fsyntax-only \
  examples/syntax-check/student_report.cpp
```

Jeśli komenda nie wypisuje błędów, składnia pliku jest poprawna.

## Ostrzeżenia

Ostrzeżenie nie zawsze zatrzymuje kompilację, ale często wskazuje problem:

- nieużywana zmienna,
- brak wartości zwracanej z funkcji,
- porównanie różnych typów,
- podejrzana konwersja.

Podstawowy zestaw flag:

```sh
-Wall -Wextra -pedantic
```

Na późniejszym etapie można potraktować ostrzeżenia jak błędy:

```sh
-Werror
```

Przykład:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic -Werror -fsyntax-only \
  examples/syntax-check/student_report.cpp
```

## Błąd kompilacji a błąd linkowania

Sprawdzanie składni wykrywa błędy w pojedynczym pliku:

- brak średnika,
- literówkę w nazwie typu,
- niepoprawną składnię instrukcji,
- brakujący nagłówek.

Nie wykrywa wszystkich problemów linkowania. Jeśli funkcja jest tylko
zadeklarowana, ale nie ma implementacji, `-fsyntax-only` może przejść poprawnie,
a pełne linkowanie zakończy się błędem.

## Sprawdzanie projektu z katalogami

Dla projektu z własnymi nagłówkami nadal trzeba podać ścieżkę `-I`:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic -fsyntax-only \
  -I examples/project-layout/include \
  examples/project-layout/src/main.cpp
```

Sprawdzenie składni nie zastępuje pełnego buildu. Jest dodatkowym, szybkim
krokiem kontroli.

## Kompletny przykład

Przykład znajduje się w pliku
[`examples/syntax-check/student_report.cpp`](examples/syntax-check/student_report.cpp).

Sprawdzenie składni:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic -fsyntax-only \
  examples/syntax-check/student_report.cpp
```

Pełna kompilacja:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic \
  examples/syntax-check/student_report.cpp \
  -o student_report
```

Uruchomienie:

```sh
./student_report
```

## Zadania do wykonania

1. Sprawdź składnię przykładu za pomocą `-fsyntax-only`.
2. Skompiluj przykład pełną komendą i uruchom program.
3. Usuń średnik po jednej instrukcji i sprawdź komunikat kompilatora.
4. Dodaj nieużywaną zmienną i sprawdź, czy pojawi się ostrzeżenie.
5. Dodaj flagę `-Werror` i zaobserwuj, jak ostrzeżenie staje się błędem.

## Kryteria zaliczenia

Student zalicza lekcję, jeśli potrafi:

- użyć `-fsyntax-only`,
- włączyć ostrzeżenia kompilatora,
- wyjaśnić sens flagi `-Werror`,
- odróżnić błąd składni od błędu linkowania,
- sprawdzić składnię pliku korzystającego z własnych nagłówków,
- wykonać pełną kompilację po sprawdzeniu składni.
