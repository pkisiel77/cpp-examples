# Projekt 01 - Logger C++

## Cel projektu

Celem projektu jest przygotowanie prostego loggera w C++, który zastępuje
proceduralny logger zapisujący dane przez funkcje z C. Projekt ma pokazać
podział odpowiedzialności na klasy, obsługę plików, formatowanie wpisów oraz
testowanie podstawowych scenariuszy.

Punktem wyjścia jest stary styl zapisu:

```c
int ZapiszDoLog(char *sciezka, char *tryb)
{
    FILE *fp = fopen(sciezka, "a");
    if (fp == NULL)
    {
        return -1;
    }

    fprintf(fp, "LOG: %s", tryb);
    fclose(fp);
    return 0;
}
```

Nowa wersja powinna używać idiomów C++: klas, `std::string`, strumieni,
enkapsulacji i czytelnej obsługi błędów.

## Zakres funkcjonalny

Logger powinien umożliwiać:

- zapis wpisu tekstowego do pliku,
- zapis wpisu tekstowego do pamięci,
- dodanie poziomu logowania, np. `Info`, `Warning`, `Error`,
- automatyczne dodanie daty i czasu do wpisu,
- odczyt wpisów zapisanych w pamięci,
- obsługę błędu otwarcia pliku,
- czytelne formatowanie wpisu.

Przykład formatu:

```text
[2026-06-12 14:30:05] [INFO] System started
```

## Wymagania techniczne

Projekt powinien:

- być napisany w C++17,
- używać `std::ofstream` zamiast `FILE*`,
- używać `std::string` zamiast `char*`,
- mieć interfejs wspólny dla różnych miejsc zapisu,
- rozdzielać deklaracje i implementacje na pliki `.h` i `.cpp`,
- kompilować się z flagami `-Wall -Wextra -pedantic`.

Do formatowania czasu można użyć biblioteki standardowej:

- `<chrono>`,
- `<ctime>`,
- `<iomanip>`,
- `<sstream>`.

## Proponowana struktura plików

```text
logger/
  include/logger/
    log_level.h
    log_sink.h
    file_sink.h
    memory_sink.h
    logger.h
  src/
    file_sink.cpp
    memory_sink.cpp
    logger.cpp
    main.cpp
  tests/
    logger_tests.cpp
  build/
```

Znaczenie elementów:

- `LogLevel` - poziom wpisu,
- `LogSink` - abstrakcyjny interfejs miejsca zapisu,
- `FileSink` - zapis do pliku,
- `MemorySink` - zapis do wektora w pamięci,
- `Logger` - klasa przyjmująca wiadomość i przekazująca ją do wybranego sinka.

Kompilowalny szkic klas znajduje się w pliku
[examples/logger_skeleton.cpp](examples/logger_skeleton.cpp). Przykład pokazuje
wspólny interfejs `LogSink`, zapis do pamięci, zapis do pliku i klasę `Logger`.

## Minimalny wariant zaliczeniowy

Minimalna wersja projektu powinna zawierać:

1. `enum class LogLevel` z wartościami `Info`, `Warning`, `Error`.
2. Klasę `Logger` z metodą:

```cpp
void log(LogLevel level, const std::string& message);
```

3. Klasę `FileSink`, która dopisuje wpisy do pliku.
4. Klasę `MemorySink`, która przechowuje wpisy w `std::vector<std::string>`.
5. Program demonstracyjny zapisujący co najmniej trzy wpisy.
6. Instrukcję kompilacji i uruchomienia w `README.md` projektu.

## Rozszerzenia dla chętnych

Możliwe rozszerzenia:

- filtrowanie wpisów poniżej minimalnego poziomu,
- osobne pliki dla różnych poziomów logowania,
- rotacja pliku logu po przekroczeniu rozmiaru,
- zapis do formatu CSV,
- zapis do bazy danych jako dodatkowy sink,
- testy automatyczne dla `MemorySink`,
- konfiguracja loggera z pliku tekstowego.

## Kryteria oceny

Projekt jest zaliczony, jeśli:

- kompiluje się bez błędów i ostrzeżeń,
- zapisuje wpisy do pliku,
- zapisuje wpisy do pamięci,
- używa `enum class` dla poziomu logowania,
- ma wspólny interfejs dla różnych miejsc zapisu,
- obsługuje błąd otwarcia pliku,
- ma kod podzielony na pliki,
- zawiera instrukcję uruchomienia,
- zawiera testy albo opis ręcznych scenariuszy sprawdzenia.

## Scenariusze sprawdzenia

1. Uruchom program z poprawną ścieżką pliku i sprawdź, czy plik zawiera wpisy.
2. Uruchom program ze ścieżką, której nie da się utworzyć, i sprawdź obsługę
   błędu.
3. Zapisz trzy wpisy do `MemorySink` i wypisz je na ekranie.
4. Sprawdź, czy poziomy `Info`, `Warning` i `Error` są widoczne w wyniku.
5. Sprawdź, czy każdy wpis ma datę i czas.
