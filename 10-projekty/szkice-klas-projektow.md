# Szkice klas w projektach

Ten dokument jest przeglądem projektów pod kątem przykładowych modeli danych,
struktur i klas. Pomaga zdecydować, gdzie warto dodać następny szkic
kompilowalny w katalogu [examples](examples).

## Status projektów

| Projekt | Status szkicu | Co jest w opisie | Następny krok |
| --- | --- | --- | --- |
| [Gra kółko i krzyżyk](gra-kolko-krzyzyk.md) | wystarczający | `Cell`, `GameState`, `Board` | brak pilnych zmian |
| [Projekt 01 - Logger](project-01-logger.md) | dobry | lista klas i przykład [logger_skeleton.cpp](examples/logger_skeleton.cpp) | utrzymywać przykład jako punkt startowy |
| [Projekt 02 - Kolejkowanie zamówień](project-02-kolejkowanie-zamowien.md) | wystarczający | `OrderStatus`, `Order` | rozważyć przykład dopiero po projektach bez szkicu |
| [Projekt 04 - Tetris](project-04-tetris.md) | wystarczający | `TetrominoType`, `Position`, `Board` | brak pilnych zmian |
| [Projekt 05 - Snake](project-05-snake.md) | wystarczający | `Direction`, `Position`, `Snake` | brak pilnych zmian |
| [Projekt 06 - Pac-Man](project-06-pacman.md) | wystarczający | `Tile`, `Position`, `Maze` | brak pilnych zmian |
| [Projekt 07 - Baza pojazdów](project-07-baza-pojazdow.md) | wystarczający | `VehicleType`, `Vehicle` | można później dodać przykład filtrowania |
| [Projekt 08 - Kalkulator](project-08-kalkulator.md) | niewymagany | projekt może być funkcyjny | szkic klasy nie jest konieczny w wariancie minimum |
| [Projekt 09 - Kalkulator macierzy](project-09-kalkulator-macierzy.md) | wystarczający | `Matrix` | brak pilnych zmian |
| [Projekt 10 - System zarządzania zadaniami](project-10-system-zadan.md) | dobry | `TaskPriority`, `TaskStatus`, `Task` i przykład [task_manager_skeleton.cpp](examples/task_manager_skeleton.cpp) | utrzymywać przykład jako punkt startowy |
| [Projekt 11 - Parser plików CSV](project-11-parser-csv.md) | wystarczający | `CsvRecord`, `CsvTable` | dodać przykład parsera, jeśli pojawią się trudności studentów |
| [Projekt 12 - Symulator bankomatu](project-12-symulator-bankomatu.md) | dobry | `TransactionType`, `Transaction`, `Account` | utrzymywać przykład [atm_account.cpp](examples/atm_account.cpp) |

## Projekty bez kodowego szkicu klasy

Nie ma już pilnych braków w kodowych szkicach klas. Kolejne przykłady warto
dodawać wtedy, gdy pomagają pokazać jedną technikę, np. zapis CSV albo
filtrowanie danych.

Projekt `project-08-kalkulator.md` nie wymaga szkicu klasy, bo wariant minimum
może być czytelnie zrealizowany funkcjami. Jeśli student wybierze wersję
obiektową, może samodzielnie wydzielić klasę `Calculator`.

## Rekomendowany porządek dalszych uzupełnień

1. Rozważyć `10-projekty/examples/csv_parser_skeleton.cpp`.
2. Dopiero potem dodawać przykłady do projektów, które mają już wystarczający
   model w opisie.
