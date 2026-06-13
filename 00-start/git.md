# Git - podstawy pracy z repozytorium

## Cel lekcji

Celem lekcji jest poznanie podstawowych poleceń Git potrzebnych do pracy
z materiałami kursu. Po tej lekcji student powinien umieć sprawdzić stan
repozytorium, dodać zmiany do commita i zapisać je lokalnie.

## Wymagania wstępne

Przed lekcją student powinien:

- umieć otworzyć terminal,
- umieć przejść do katalogu projektu,
- mieć zainstalowany Git,
- rozumieć, że repozytorium przechowuje historię zmian.

## Krótka teoria

Git zapisuje historię zmian w plikach projektu. Najważniejsze pojęcia:

- repozytorium - katalog śledzony przez Git,
- working tree - bieżące pliki na dysku,
- staging area - lista zmian przygotowanych do commita,
- commit - zapisany punkt historii,
- remote - zdalne repozytorium, np. na GitHubie.

Typowy cykl pracy:

1. Zmieniasz pliki.
2. Sprawdzasz stan repozytorium.
3. Dodajesz wybrane pliki do indeksu.
4. Tworzysz commit.
5. Wysyłasz commit do zdalnego repozytorium.

## Podstawowe polecenia

Sprawdzenie stanu repozytorium:

```bash
git status
```

Krótki status:

```bash
git status --short
```

Podgląd zmian:

```bash
git diff
```

Dodanie pliku do indeksu:

```bash
git add main.cpp
```

Commit:

```bash
git commit -m "Add first C++ program"
```

Wysłanie zmian:

```bash
git push origin main
```

## Praca z branchami

Pobranie informacji o zdalnych branchach:

```bash
git fetch origin
```

Przełączenie na istniejący branch:

```bash
git checkout nazwa-brancha
```

Utworzenie nowego brancha:

```bash
git checkout -b moja-zmiana
```

W nowszych wersjach Git można używać także:

```bash
git switch -c moja-zmiana
```

## Typowe problemy

### Plik nie trafił do commita

Sprawdź:

```bash
git status --short
```

Jeśli plik nadal jest oznaczony jako zmodyfikowany, prawdopodobnie nie został
dodany poleceniem `git add`.

### Przypadkowo dodany plik

Jeśli plik został dodany do indeksu, ale nie chcesz go commitować:

```bash
git restore --staged nazwa-pliku
```

### Zmiana adresu zdalnego repozytorium

Przykład zmiany adresu na SSH:

```bash
git remote set-url origin git@github.com:USERNAME/REPOSITORY.git
```

## Zadania do wykonania

1. Sprawdź wersję Git:

```bash
git --version
```

2. Sprawdź status repozytorium:

```bash
git status --short
```

3. Utwórz albo zmień mały plik ćwiczeniowy.
4. Sprawdź różnice poleceniem `git diff`.
5. Dodaj plik do indeksu poleceniem `git add`.
6. Sprawdź status ponownie.
7. Utwórz commit z krótkim opisem.

## Checklist dla studenta

Przed zaliczeniem lekcji sprawdź, czy potrafisz:

- wyjaśnić różnicę między katalogiem roboczym, indeksem i commitem,
- użyć `git status` przed commitem,
- dodać wybrane pliki przez `git add`,
- utworzyć czytelny commit,
- utworzyć i przełączyć branch.

## Kryteria zaliczenia

Lekcja jest zaliczona, jeśli student potrafi:

- sprawdzić status repozytorium,
- odróżnić pliki zmienione od dodanych do indeksu,
- podejrzeć diff,
- dodać plik poleceniem `git add`,
- utworzyć commit,
- wyjaśnić, po co używa się commita.
