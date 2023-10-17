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


  
