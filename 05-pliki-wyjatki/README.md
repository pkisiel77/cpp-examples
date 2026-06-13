# 05 - Pliki i wyjątki

Ten segment pokazuje, jak program może zapisywać dane poza pamięcią operacyjną oraz jak reagować na sytuacje błędne. Materiał łączy obsługę plików tekstowych z podstawami walidacji, kontroli błędów i wyjątków.

## Cele segmentu

Po zakończeniu segmentu student powinien umieć:

- otworzyć plik tekstowy do odczytu,
- otworzyć plik tekstowy do zapisu,
- dopisać dane na końcu pliku,
- odczytać plik linia po linii,
- sprawdzić, czy operacja na pliku się udała,
- rozumieć różnicę między błędem możliwym do obsłużenia a błędem programistycznym,
- użyć podstawowego bloku `try`, `throw`, `catch`,
- dobrać prostą strategię obsługi błędów do zadania.

## Kolejność lekcji

1. [01-pliki-tekstowe.md](01-pliki-tekstowe.md) - zapis, odczyt i dopisywanie danych.
2. [02-odczyt-i-walidacja.md](02-odczyt-i-walidacja.md) - sprawdzanie błędów wejścia i stanu pliku.
3. [03-wyjatki.md](03-wyjatki.md) - podstawy `try`, `throw`, `catch`.
4. [04-zadanie-menu-plikowe.md](04-zadanie-menu-plikowe.md) - mały program z menu do zarządzania plikiem.
5. [05-zadania.md](05-zadania.md) - zadania podstawowe i dodatkowe.

## Status porządkowania

Lekcje i zadania zostały uporządkowane do wspólnego formatu segmentów. Pierwotne wersje materiałów są zachowane w katalogu [archive](archive):

- [archive/pliki-tekstowe.md](archive/pliki-tekstowe.md)
- [archive/pliki-tekstowe-zadanie.md](archive/pliki-tekstowe-zadanie.md)
- [archive/zadanie-io-plik.md](archive/zadanie-io-plik.md)
- [archive/wyjatki.md](archive/wyjatki.md)

## Przykłady kodu

Przykłady w katalogu [examples](examples) można kompilować osobno:

- [examples/write_text_file.cpp](examples/write_text_file.cpp) - zapis do pliku.
- [examples/append_text_file.cpp](examples/append_text_file.cpp) - dopisywanie danych.
- [examples/read_text_file.cpp](examples/read_text_file.cpp) - odczyt liniami.
- [examples/missing_file_check.cpp](examples/missing_file_check.cpp) - sprawdzanie braku pliku.
- [examples/read_numbers_with_validation.cpp](examples/read_numbers_with_validation.cpp) - odczyt liczb z walidacją.
- [examples/validate_lines.cpp](examples/validate_lines.cpp) - walidacja danych w liniach.
- [examples/basic_exception.cpp](examples/basic_exception.cpp) - podstawowy wyjątek.
- [examples/function_exception.cpp](examples/function_exception.cpp) - rzucanie wyjątku z funkcji.
- [examples/standard_exception.cpp](examples/standard_exception.cpp) - obsługa wyjątku standardowego.
- [examples/file_menu.cpp](examples/file_menu.cpp) - program z menu plikowym.

## Format lekcji

Każda docelowa lekcja powinna mieć taki układ:

1. Cel lekcji.
2. Wymagania wstępne.
3. Krótka teoria.
4. Przykład kodu.
5. Zadania do wykonania.
6. Kryteria zaliczenia.

## Katalogi pomocnicze

- `examples/` - kompilowalne przykłady `.cpp` dla tego segmentu.
- `archive/` - pierwotne wersje materiałów zachowane do wglądu.
