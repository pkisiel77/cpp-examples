# 04 - Zadanie: menu plikowe

## Cel lekcji

Celem lekcji jest połączenie obsługi plików, walidacji wejścia i funkcji w jednym małym programie użytkowym.

## Wymagania wstępne

Student powinien znać:

- podstawy plików tekstowych z lekcji [01-pliki-tekstowe.md](01-pliki-tekstowe.md),
- walidację odczytu z lekcji [02-odczyt-i-walidacja.md](02-odczyt-i-walidacja.md),
- funkcje z segmentu [03-funkcje-tablice-napisy](../03-funkcje-tablice-napisy/README.md).

## Krótka teoria

Napisz program, który zarządza prostym plikiem tekstowym `dane.txt`.

Program powinien wyświetlać menu:

```text
1. Dodaj wpis
2. Wyswietl wpisy
3. Usun wszystkie wpisy
0. Wyjdz
```

Użytkownik wybiera opcję, a program wykonuje odpowiednią operację na pliku.

### Wymagane funkcje programu

Program powinien być podzielony na funkcje:

- `pokazMenu()` - wypisuje dostępne opcje,
- `dodajWpis()` - dopisuje linię tekstu do pliku,
- `wyswietlWpisy()` - odczytuje i wypisuje cały plik,
- `usunWpisy()` - czyści zawartość pliku,
- `wczytajWybor()` - pobiera i sprawdza wybór użytkownika.

Podział na funkcje jest ważny, bo dzięki temu `main` pozostaje czytelny.

## Przykład kodu: dopisywanie wpisu

Dopisywanie wpisu wymaga otwarcia pliku w trybie `std::ios::app`.

```cpp
std::ofstream plik("dane.txt", std::ios::app);
plik << wpis << std::endl;
```

Jeśli plik nie istnieje, zostanie utworzony.

## Przykład kodu: wyświetlanie wpisów

Odczyt wykonujemy linia po linii.

```cpp
std::ifstream plik("dane.txt");
std::string linia;

while (std::getline(plik, linia))
{
    std::cout << linia << std::endl;
}
```

Warto numerować wpisy, bo wtedy wynik jest czytelniejszy.

## Przykład kodu: czyszczenie pliku

Najprostszy sposób wyczyszczenia pliku to otwarcie go zwykłym `std::ofstream`.

```cpp
std::ofstream plik("dane.txt");
```

Taki zapis nadpisuje poprzednią zawartość pustą treścią.

### Walidacja wyboru

Nie można zakładać, że użytkownik zawsze wpisze liczbę.

```cpp
int wybor = -1;

if (!(std::cin >> wybor))
{
    std::cout << "Niepoprawny wybor" << std::endl;
}
```

Po nieudanym odczycie trzeba wyczyścić stan `std::cin` i usunąć błędne dane z bufora. W przykładzie referencyjnym użyta jest do tego funkcja `ignorujReszteLinii()`.

## Przykład referencyjny

Pełny przykład znajduje się w pliku [examples/file_menu.cpp](examples/file_menu.cpp).

Przykład pokazuje:

- pętlę menu,
- dopisywanie wpisów,
- odczyt pliku,
- czyszczenie pliku,
- prostą walidację wyboru.

## Zadania do wykonania

1. Uruchom przykład referencyjny i sprawdź wszystkie opcje menu.
2. Zmień nazwę pliku z `dane.txt` na `notatki.txt`.
3. Dodaj opcję `4. Policz wpisy`, która wypisuje liczbę linii w pliku.
4. Dodaj komunikat `Brak wpisow`, jeśli plik jest pusty.
5. Rozbuduj wpis tak, aby przed tekstem zapisywany był numer wpisu.

## Ćwiczenia dodatkowe

1. Dodaj opcję liczenia wpisów w pliku.
2. Dodaj walidację pustego wpisu.
3. Zmień program tak, aby nazwa pliku była stałą na początku programu.

## Kryteria zaliczenia

Program powinien:

- wyświetlać menu w pętli,
- obsługiwać wybór `0` jako zakończenie programu,
- dopisywać wpisy do pliku,
- wyświetlać wszystkie wpisy z pliku,
- czyścić zawartość pliku,
- sprawdzać błędny wybór użytkownika,
- być podzielony na funkcje,
- kompilować się bez błędów.

## Pytania kontrolne

1. Dlaczego dopisywanie wymaga `std::ios::app`?
2. Dlaczego `main` nie powinien zawierać całej logiki programu?
3. Co robi zwykłe otwarcie pliku przez `std::ofstream`?
4. Dlaczego trzeba obsłużyć niepoprawny wybór z menu?
5. Jak sprawdzić, czy plik jest pusty?
