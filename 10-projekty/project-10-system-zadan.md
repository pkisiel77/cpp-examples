# Projekt 10 - System zarządzania zadaniami

## Cel projektu

Celem projektu jest przygotowanie konsolowego systemu do zarządzania zadaniami.
Projekt ma pokazać modelowanie danych, priorytety, statusy, sortowanie,
filtrowanie, zapis do pliku oraz podział programu na klasy.

Punktem wyjścia są zadania opisane polami:

- `UID` albo `PID`,
- `Name`,
- `Priority`,
- `StartTime`,
- `Function`.

W projekcie warto doprecyzować te pola i nadać im jasne znaczenie.

## Zakres funkcjonalny

System powinien umożliwiać:

- dodanie nowego zadania,
- edycję zadania,
- usunięcie zadania,
- wyświetlenie listy zadań,
- wyszukanie zadania po identyfikatorze,
- zmianę statusu zadania,
- sortowanie po priorytecie albo czasie startu,
- filtrowanie po statusie,
- zapis zadań do pliku,
- odczyt zadań z pliku przy starcie programu.

Przykładowe statusy:

- `New`,
- `InProgress`,
- `Done`,
- `Cancelled`.

Przykładowe priorytety:

- `Low`,
- `Normal`,
- `High`,
- `Critical`.

## Wymagania techniczne

Projekt powinien:

- być napisany w C++17,
- używać klas do modelowania zadania i systemu zadań,
- używać `enum class` dla statusu i priorytetu,
- używać `std::vector` do przechowywania zadań,
- używać `std::map` albo `std::unordered_map` do wyszukiwania po ID,
- używać algorytmów STL do sortowania i filtrowania,
- zapisywać dane do pliku tekstowego, np. CSV,
- rozdzielać deklaracje i implementacje na pliki `.h` i `.cpp`,
- kompilować się z flagami `-Wall -Wextra -pedantic`.

Pole `Function` można potraktować jako tekstowy opis akcji, np.
`send_email`, `generate_report`, `backup_data`.

## Proponowana struktura plików

```text
task-system/
  include/task_system/
    task.h
    task_priority.h
    task_status.h
    task_manager.h
    task_storage.h
  src/
    task.cpp
    task_manager.cpp
    task_storage.cpp
    main.cpp
  tests/
    task_manager_tests.cpp
  data/
    tasks.csv
  build/
```

Znaczenie elementów:

- `Task` - dane pojedynczego zadania,
- `TaskPriority` - priorytet zadania,
- `TaskStatus` - status zadania,
- `TaskManager` - logika dodawania, usuwania, edycji i wyszukiwania,
- `TaskStorage` - zapis i odczyt zadań z pliku.

## Model danych

Zadanie powinno mieć co najmniej:

- `id`,
- `name`,
- `priority`,
- `status`,
- `startTime`,
- `functionName`.

Przykład:

```cpp
enum class TaskPriority {
    Low,
    Normal,
    High,
    Critical
};

enum class TaskStatus {
    New,
    InProgress,
    Done,
    Cancelled
};

struct Task {
    std::string id;
    std::string name;
    TaskPriority priority;
    TaskStatus status;
    std::string startTime;
    std::string functionName;
};
```

## Minimalny wariant zaliczeniowy

Minimalna wersja projektu powinna zawierać:

1. Menu konsolowe z opcjami:
   - dodaj zadanie,
   - edytuj zadanie,
   - usuń zadanie,
   - wyświetl zadania,
   - wyszukaj zadanie,
   - zmień status,
   - zapisz dane,
   - wczytaj dane,
   - zakończ.
2. Walidację unikalnego ID.
3. Sortowanie zadań po priorytecie.
4. Filtrowanie zadań po statusie.
5. Zapis i odczyt danych z pliku CSV.
6. Instrukcję kompilacji i uruchomienia w `README.md` projektu.

## Rozszerzenia dla chętnych

Możliwe rozszerzenia:

- historia zmian statusu,
- data zakończenia zadania,
- przypisanie zadania do użytkownika,
- cykliczne zadania,
- eksport raportu do pliku tekstowego,
- testy automatyczne dla `TaskManager`,
- tryb demonstracyjny z przykładowymi zadaniami,
- zapis do SQLite.

## Kryteria oceny

Projekt jest zaliczony, jeśli:

- kompiluje się bez błędów i ostrzeżeń,
- poprawnie dodaje zadania,
- odrzuca duplikaty ID,
- umożliwia edycję i usuwanie zadań,
- wyszukuje zadanie po ID,
- sortuje i filtruje zadania,
- zapisuje i odczytuje dane z pliku,
- używa klas, `enum class` i kontenerów STL,
- ma czytelne menu konsolowe,
- zawiera instrukcję uruchomienia,
- zawiera testy albo opis ręcznych scenariuszy sprawdzenia.

## Scenariusze sprawdzenia

1. Dodaj trzy zadania z różnymi priorytetami i wyświetl listę.
2. Posortuj zadania po priorytecie.
3. Zmień status wybranego zadania na `Done` i przefiltruj zadania zakończone.
4. Spróbuj dodać drugie zadanie z tym samym ID.
5. Zapisz zadania do pliku, uruchom program ponownie i wczytaj dane.
