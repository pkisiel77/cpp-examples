# 07 - Moduły i podział kodu

## Cel lekcji

Celem lekcji jest rozróżnienie dwóch pojęć: klasycznego podziału programu na
pliki `.h` i `.cpp` oraz modułów C++20. Student powinien rozumieć, że w tym
kursie stabilną podstawą pozostaje podział na nagłówki i pliki źródłowe, a
moduły C++20 są tematem rozszerzającym.

## Wymagania wstępne

Przed rozpoczęciem lekcji warto znać:

- pliki nagłówkowe,
- implementacje w plikach `.cpp`,
- guardy,
- kompilację wielu plików,
- przestrzenie nazw.

## Klasyczny podział na pliki

W typowym projekcie C++ interfejs umieszczamy w pliku `.h`, a implementację w
pliku `.cpp`.

```text
message.h
message.cpp
main.cpp
```

Plik nagłówkowy mówi, co można wywołać:

```cpp
std::string formatMessage(const Message& message);
```

Plik `.cpp` mówi, jak to działa:

```cpp
std::string formatMessage(const Message& message) {
    return message.author + ": " + message.text;
}
```

To jest podstawowy i nadal bardzo powszechny sposób organizacji kodu C++.

## „Moduł” jako część programu

W rozmowach o projekcie słowo „moduł” często oznacza logiczną część programu,
np. moduł wiadomości, moduł użytkowników albo moduł raportów.

Taki moduł może być zwykłą parą plików:

```text
message.h
message.cpp
```

Nie jest to jeszcze moduł C++20. To tylko organizacja kodu.

## Moduły C++20

C++20 wprowadził językową funkcję `module`.

Przykładowy szkic:

```cpp
export module messages;

export std::string formatMessage(const Message& message);
```

Moduły C++20 mają rozwiązywać część problemów nagłówków, np. wielokrotne
dołączanie i koszt preprocesora. W praktyce ich obsługa zależy od kompilatora,
wersji narzędzi i systemu build.

Dlatego w tym repozytorium przykłady kompilowalne trzymamy przy klasycznym
podziale na `.h` i `.cpp`.

## Co wybrać w tym kursie

Na tym etapie wybieraj:

- `.h` dla deklaracji i interfejsu,
- `.cpp` dla implementacji,
- `namespace` dla uporządkowania nazw,
- `examples/` dla małych programów demonstracyjnych.

Moduły C++20 warto znać jako kierunek rozwoju języka, ale nie są wymagane do
zrozumienia większości projektów C++.

## Kompletny przykład

Przykład znajduje się w katalogu
[`examples/code-organization`](examples/code-organization).

Kompilacja:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic \
  examples/code-organization/main.cpp \
  examples/code-organization/message.cpp \
  -o code_organization
./code_organization
```

## Zadania do wykonania

1. Skompiluj i uruchom przykład.
2. Dodaj do `Message` pole `priority`.
3. Rozszerz `formatMessage`, aby wypisywała priorytet.
4. Dodaj drugi logiczny moduł `users.h` i `users.cpp`.
5. Napisz w komentarzu, czym różni się taki moduł logiczny od modułu C++20.

## Kryteria zaliczenia

Student zalicza lekcję, jeśli potrafi:

- rozdzielić interfejs od implementacji,
- wskazać rolę pliku `.h` i `.cpp`,
- skompilować program złożony z kilku plików,
- wyjaśnić, że „moduł” może oznaczać logiczną część programu,
- odróżnić klasyczny podział kodu od modułów C++20,
- wskazać, dlaczego moduły C++20 zależą od narzędzi build i kompilatora.
