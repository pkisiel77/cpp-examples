# Przewodnik dla prowadzącego

Ten dokument opisuje, jak używać repozytorium jako materiału do zajęć z C++.
Zakłada pracę etapową: najpierw podstawy języka, potem organizacja kodu,
a na końcu projekty zaliczeniowe.

Gotowy rozkład 15-tygodniowy znajduje się w [planie semestru](plan-semestru.md).
Zasady punktów kontrolnych i oceniania opisuje dokument [postępy i ocenianie](postepy-i-ocenianie.md).

## Proponowany układ pracy

| Etap | Segmenty | Cel |
| --- | --- | --- |
| Start techniczny | `00-start` | Przygotowanie środowiska, kompilatora, edytora i Git. |
| Podstawy składni | `01-podstawy`, `02-sterowanie-i-petle` | Pierwsze programy, wejście/wyjście, warunki i pętle. |
| Funkcje i dane | `03-funkcje-tablice-napisy`, `04-wskazniki-referencje-pamiec` | Podział programu, tablice, napisy, referencje i wskaźniki. |
| Programy użytkowe | `05-pliki-wyjatki`, `06-oop` | Pliki, walidacja, wyjątki, klasy i podstawy OOP. |
| Biblioteka standardowa | `07-stl-struktury-danych`, `09-modern-cpp` | Kontenery, algorytmy, lambdy i wybrane elementy modern C++. |
| Projekt i jakość | `08-projekt-build-testy`, `10-projekty` | Build, testy, CI i projekt zaliczeniowy. |

## Praca z lekcją

Na pojedynczych zajęciach warto trzymać stały rytm:

1. Omów cel lekcji i wymagania wstępne.
2. Przejdź przez krótki przykład kodu.
3. Uruchom przykład lokalnie i pokaż kompilację z ostrzeżeniami.
4. Daj studentom zadania do wykonania.
5. Na koniec użyj checklisty, pytań kontrolnych albo mini-sprawdzianu.

Jeśli grupa jest początkująca, lepiej zrobić mniej zadań, ale każde zakończyć
kompilacją i krótkim omówieniem błędów.

## Zadania obowiązkowe i dodatkowe

Zadania z poziomów podstawowych traktuj jako obowiązkowe. Zadania dodatkowe,
rozszerzenia i projekty wariantu rozszerzonego powinny być używane dla osób,
które kończą pracę wcześniej albo potrzebują większego wyzwania.

Praktyczna zasada:

- minimum - student wykonuje zadania podstawowe i umie wyjaśnić własny kod,
- dobrze - student wykonuje też zadania z walidacją i przypadkami brzegowymi,
- bardzo dobrze - student rozbudowuje program, dzieli kod na funkcje lub klasy i dokumentuje decyzje.

## Sprawdzanie prac

Przy sprawdzaniu krótkich zadań wymagaj:

- kompilacji bez błędów,
- czytelnych nazw zmiennych i funkcji,
- braku niepotrzebnego kodu,
- obsługi podstawowych błędnych danych,
- krótkiego wyjaśnienia rozwiązania przez studenta.

Dla większych zadań i projektów używaj rubryki z [10-projekty](../10-projekty/README.md).
Najpierw sprawdzaj wariant minimum, dopiero później rozszerzenia.
Przy odbiorze możesz przejść przez [checklistę oddania](checklista-oddania.md).

## Walidacja techniczna repozytorium

Przed zajęciami albo po większych zmianach uruchom:

```sh
sh tools/check-examples.sh
```

Skrypt kompiluje przykłady z głównej ścieżki i uruchamia testowy build z segmentu
`08-projekt-build-testy`. Ten sam skrypt działa w GitHub Actions.

## Praca z projektami

Przy projektach zaliczeniowych poproś studentów o:

- wybór tematu z `10-projekty`,
- wskazanie wariantu minimum,
- krótki plan plików i klas,
- regularne commity,
- opis kompilacji w `README.md`,
- scenariusze sprawdzenia albo proste testy.

Nie oceniaj rozszerzeń, jeśli wersja minimalna nie jest stabilna.
