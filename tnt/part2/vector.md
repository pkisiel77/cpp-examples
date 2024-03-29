## Zadanie 1

Pewien serwis internetowy chce przechowywać swoje hasła w sposób bezpieczny. Wymyślił więc system, który zamienia hasła na serie liczb, które następnie są przechowywane w strukturze std::vector.

Proces kodowania hasła jest następujący:

- Każda litera małych liter (a-z) jest zamieniana na odpowiadającą jej liczbę w zakresie 1-26.
- Każda litera dużych liter (A-Z) jest zamieniana na odpowiadającą jej liczbę w zakresie 27-52.
- Każda cyfra (0-9) jest zamieniana na odpowiadającą jej liczbę w zakresie 53-62.

Twoje zadanie polega na napisaniu funkcji w C++, która przyjmuje string reprezentujący hasło, a następnie zwraca std::vector<int> reprezentujący zakodowane hasło. 
  
  Następnie napisz funkcję, która potrafi odkodować takie hasło na podstawie std::vector<int> z powrotem na string. 
  
  Pamiętaj o obsłudze potencjalnych błędów, takich jak niewłaściwe znaki w haśle.

## Zadanie 2*
Napisz program, który będzie wykonywał następujące kroki:

- Pobiera od użytkownika liczbę n - ilość liczb, które zostaną wprowadzone.
- Pobiera n liczb od użytkownika i zapisuje je w wektorze.
- Wypisuje wszystkie liczby z wektora.
- Wypisuje średnią wartość liczb w wektorze.
- Wypisuje wszystkie liczby większe od tej średniej.

<details>
  <summary>Kod</summary>

```cpp
#include <iostream>
#include <vector>

int main() {
    int n;
    std::vector<int> liczby;

    // 1. Pobranie ilości liczb
    std::cout << "Podaj ilosc liczb: ";
    std::cin >> n;

    // 2. Pobranie liczb od użytkownika
    std::cout << "Podaj " << n << " liczb:" << std::endl;
    for (int i = 0; i < n; ++i) {
        int liczba;
        std::cin >> liczba;
        liczby.push_back(liczba);
    }

    // 3. Wypisanie liczb z wektora
    std::cout << "Wprowadzone liczby: ";
    for (int liczba : liczby) {
        std::cout << liczba << " ";
    }
    std::cout << std::endl;

    // 4. Obliczenie i wypisanie średniej wartości
    double suma = 0.0;
    for (int liczba : liczby) {
        suma += liczba;
    }
    double srednia = suma / n;
    std::cout << "Srednia wartosc: " << srednia << std::endl;

    // 5. Wypisanie liczb większych od średniej
    std::cout << "Liczby wieksze od sredniej: ";
    for (int liczba : liczby) {
        if (liczba > srednia) {
            std::cout << liczba << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}

```
</details>

## Zadanie 3*
Napisz program, który:

- Pobiera od użytkownika liczbę n - ilość liczb, które zostaną wprowadzone.
- Pobiera n liczb od użytkownika i zapisuje je w wektorze.
- Sortuje liczby w wektorze w porządku rosnącym.
- Wypisuje medianę (wartość środkową) liczb w wektorze.
- Usuwa z wektora wszystkie liczby większe od mediany.
- Wypisuje liczby, które pozostały w wektorze.

<details>
  <summary>Kod</summary>
  
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::vector<int> liczby;

    // 1. Pobranie ilości liczb
    std::cout << "Podaj ilosc liczb: ";
    std::cin >> n;

    // 2. Pobranie liczb od użytkownika
    std::cout << "Podaj " << n << " liczb:" << std::endl;
    for (int i = 0; i < n; ++i) {
        int liczba;
        std::cin >> liczba;
        liczby.push_back(liczba);
    }

    // 3. Sortowanie wektora w porządku rosnącym
    std::sort(liczby.begin(), liczby.end());

    // 4. Obliczenie i wypisanie mediany
    double mediana;
    if (n % 2 == 0) {
        mediana = (liczby[n / 2 - 1] + liczby[n / 2]) / 2.0;
    } else {
        mediana = liczby[n / 2];
    }
    std::cout << "Mediana: " << mediana << std::endl;

    // 5. Usunięcie liczb większych od mediany
    liczby.erase(std::remove_if(liczby.begin(), liczby.end(), [mediana](int x) { return x > mediana; }), liczby.end());

    // 6. Wypisanie pozostałych liczb w wektorze
    std::cout << "Liczby w wektorze po usunieciu: ";
    for (int liczba : liczby) {
        std::cout << liczba << " ";
    }
    std::cout << std::endl;

    return 0;
}

```
</details>


  
