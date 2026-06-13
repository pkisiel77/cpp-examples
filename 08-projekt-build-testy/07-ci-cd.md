# 07 - CI/CD

## Cel lekcji

Celem lekcji jest zrozumienie, po co automatyzować kompilację i testy. Student
powinien umieć opisać podstawową ideę CI/CD oraz przygotować prosty workflow,
który po zmianie kodu uruchamia build i testy.

## Wymagania wstępne

Przed rozpoczęciem lekcji warto znać:

- strukturę projektu C++,
- kompilację wielu plików,
- prosty skrypt build,
- testy uruchamiane jako osobny program.

## Krótka teoria

### Co oznacza CI

CI, czyli Continuous Integration, oznacza regularne sprawdzanie zmian w kodzie.
W praktyce dla małego projektu C++ oznacza to najczęściej:

1. pobranie kodu z repozytorium,
2. przygotowanie środowiska,
3. kompilację programu,
4. uruchomienie testów,
5. zgłoszenie błędu, jeśli któryś krok się nie powiedzie.

CI nie zastępuje myślenia programisty, ale szybko wykrywa część problemów.

### Co oznacza CD

CD może oznaczać Continuous Delivery albo Continuous Deployment. W tym kursie
wystarczy rozumieć ogólną ideę: po przejściu testów projekt może być
automatycznie przygotowany do wydania.

Dla repozytorium edukacyjnego zwykle wystarczy CI. Automatyczne wdrażanie nie
jest potrzebne na tym etapie.

### Dlaczego testy muszą zwracać kod błędu

Skrypt CI sprawdza kod zakończenia komendy:

- `0` oznacza sukces,
- wartość różna od `0` oznacza błąd.

Dlatego testy z lekcji [06-testy.md](06-testy.md) zwracają `1`, jeśli któryś
przypadek testowy nie przechodzi. Dzięki temu CI może zatrzymać proces.

## Przykład komendy: lokalny odpowiednik CI

Zanim uruchomimy automatyzację na serwerze, warto mieć lokalną komendę, która
robi to samo:

```sh
BUILD_DIR=/tmp/task-counter-build sh examples/project-layout/build.sh
```

Taki skrypt:

- kompiluje aplikację,
- kompiluje testy,
- uruchamia testy,
- kończy się błędem, jeśli testy się nie powiodą.

To jest najważniejsza część CI. Platforma, np. GitHub Actions, tylko uruchamia
tę komendę automatycznie.

## Przykład konfiguracji: GitHub Actions

Przykładowy workflow znajduje się w pliku
[`examples/ci-cd/github-actions-cpp.yml`](examples/ci-cd/github-actions-cpp.yml).

Aby go użyć w prawdziwym repozytorium, należy skopiować go do:

```text
.github/workflows/cpp.yml
```

Workflow uruchamia się dla `push` i `pull_request`, a następnie wykonuje skrypt
build z przykładu.

### Minimalny workflow

Najważniejsza część workflow to kroki:

```yaml
- name: Checkout
  uses: actions/checkout@v4

- name: Build and test
  run: BUILD_DIR=/tmp/task-counter-build sh 08-projekt-build-testy/examples/project-layout/build.sh
```

Pierwszy krok pobiera kod. Drugi uruchamia build i testy.

### Co powinno trafić do CI

Na tym etapie warto automatyzować:

- kompilację przykładów,
- uruchomienie testów,
- sprawdzanie składni najważniejszych plików,
- uruchomienie jednego skryptu, który zwraca poprawny kod zakończenia.

Nie warto zaczynać od zbyt złożonej konfiguracji. Najpierw trzeba mieć lokalny
skrypt build, który działa przewidywalnie.

## Typowe błędy

### Workflow robi coś innego niż lokalny build

Jeśli CI używa innych komend niż programista lokalnie, trudniej odtworzyć błąd.
Najlepiej, gdy CI uruchamia ten sam skrypt.

### Testy wypisują błąd, ale zwracają `0`

CI uzna taki wynik za sukces. Test powinien zwrócić wartość różną od zera, jeśli
wykrył problem.

### Build zapisuje artefakty w repozytorium

Pliki wynikowe powinny trafiać do katalogu tymczasowego albo do ignorowanego
`build/`.

## Zadania do wykonania

1. Uruchom lokalnie skrypt `examples/project-layout/build.sh`.
2. Sprawdź, jaki kod zakończenia zwraca skrypt po poprawnym buildzie.
3. Celowo zepsuj jeden test i sprawdź, czy skrypt kończy się błędem.
4. Przeczytaj plik `examples/ci-cd/github-actions-cpp.yml`.
5. Wyjaśnij, dlaczego workflow uruchamia ten sam skrypt, którego używamy
   lokalnie.

## Kryteria zaliczenia

Student zalicza lekcję, jeśli potrafi:

- wyjaśnić podstawową ideę CI,
- odróżnić CI od CD,
- przygotować lokalny skrypt uruchamiany przez CI,
- wyjaśnić znaczenie kodu zakończenia programu,
- wskazać, gdzie w repozytorium umieszcza się workflow GitHub Actions,
- opisać, dlaczego CI powinno uruchamiać te same kroki co lokalny build.
