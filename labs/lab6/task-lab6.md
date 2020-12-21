# Kontenery w C++

### (Termin oddania dla wszystkich grup 31.12.2020)

Należy zaimplementować system dla działu HR w firmie.
1. Gdy w poniższych wymaganiach mowa jest o kontenerze należy zastosować
jeden z poniższych kontenerów (właściwy dla danego wymagania):
- std::stack
- std::vector
- std::queue
- std::list
- std::map
2. Należy zaimplementować klasę Employee z następującymi polami:
- id: string - identyfikator pracownika
- name: string
- surname: string
- departmentId: string - identyfikator działu w którym pracuje dane osoba
- position: string - stanowisko na którym pracuje dana osoba
3. Należy zaimplementować klasę HRMS służącą do zarządzania pracownikami.
Klasa ma mieć następujące składowe:
- kontener w którym będą przechowywani wszyscy pracownicy
- kontener w którym będzie przechowywane mapowanie pomiędzy identyfikatorami departamentów a identyfikatorami wszystkich pracowników danego departamentu
- kontener przechowywujący informacje o zarobkach pracowników
- metoda add(Employee employee, std::string departmentId, double salary) dodająca użytkownika do systemu, do danego departamentu, mającego dane wynagrodzenie
- metoda printDepartment(std::string departmentId) wypisująca wszystkich pracowników danego departamentu
- metoda changeSalary(std::string employeeId, double salary) - metoda zmieniająca wynagrodzenie danego pracownika
- metoda printSalaries() wypisująca wynagrodzenia wszystkich pracowników, wraz z informacjami o tych pracownikach
- metoda printSalariesSorted() wypisująca wynagrodzenia wszystkich pracowników, wraz z informacjami o tych pracownikach, w kolejności malejącego wynagrodzenia (sortowanie ma być wykonana z użyciem std::algorithm)
4. Należy zaimplementować metodę main demonstrującą działanie powyższego kodu dla co najmniej 10 pracowników pracujących co najmniej w 3 departamentach

## std::stack

std::stack (stos) jest adapterem kontenera, zapewniająca programiście funkcjonalność stosu - struktury danych FILO (first-in, last-out; pierwszy na wejściu, ostatni na wyjściu).

Szablon tej klasy funkcjonuje jak opakowanie do kontenera - umożliwia tylko pewien konkretny zbiór operacji. Stos operuje tylko na końcu opakowywanego kontenera, nazywanym wierzchołkiem stosu (top()). Możliwymi działaniami jest dodanie elementu na koniec (wrzucenie na stos) i usunięcie elementu z końca (zdjęcie ze stosu).

więcej na stronie [cppreference](https://pl.cppreference.com/w/cpp/container/stack)

## std::vector

std::vector jest kontenerem sekwencyjnym, który enkapsuluje tablice zmiennej wielkości.

Elementy są przechowywane w ciągłej pamięci, co oznacza, że można do nich uzyskać dostęp nie tylko przez iteratory, ale również przesuwając zwykłe wskaźniki na elementy. Dzięki temu wskaźnik na element wektora można przekazać do funkcji oczekującej wskaźnika na element tablicy.	(od C++03)
Pojemność wektora jest zarządzana automatycznie, zwiększana bądź zmniejszana w razie potrzeby. Wektory zużywają zwykle więcej pamięci niż tablice, ponieważ "na zapas" alokują więcej pamięci, która jest później używana w przypadku zwiększenia liczby elementów. W ten sposób wektor nie musi realokować całej swojej pamięci za każdym razem, gdy dodawany jest do niego element, ale dopiero gdy zapasowa pamięć się wyczerpie. Całkowitą ilość zarezerwowanej pamięci można odczytać poprzez funkcję capacity(). Nadmiarowa pamięć może zostać zwrócona do systemu poprzez wywołanie shrink_to_fit(). (od C++11)

Realokacje są kosztownymi operacjami pod względem wydajności. Jeśli liczba elementów jest znana zawczasu, można wykorzystać funkcję reserve(), aby wyeliminować realokacje i od razu zarezerwować wymaganą ilość pamięci.

Złożoność obliczeniowa (wydajność) standardowych operacji na wektorze jest następująca:

Dostęp bezpośredni do elementu - stała O(1)
Wstawienie lub usunięcie elementu na końcu - amortyzowana stała O(1)
Wstawienie lub usunięcie elementu - liniowa względem odległości do końca wektora O(n)
std::vector spełnia wymagania Container, AllocatorAwareContainer, SequenceContainer i ReversibleContainer.

```cpp
#include <iostream>
#include <vector>
 
int main()
{
    // Tworzy wektor zawierający liczby całkowite
    std::vector<int> v = {7, 5, 16, 8};
 
    // Dodaje dwie liczby do wektora
    v.push_back(25);
    v.push_back(13);
 
    // Iteruje po wartościach w wektorze i wypisuje je
    for(int n : v) {
        std::cout << n << '\n';
    }
}
```

## std::queue

td::queue - kolejka jest adapterem kontenera, zapewniającym programiście funkcjonalność kolejki - struktury danych FIFO (first-in, first-out; pierwszy na wejściu, pierwszy na wyjściu).

Szablon tej klasy funkcjonuje jak opakowanie do kontenera - umożliwia tylko pewien konkretny zbiór operacji. Kolejka dodaje elementy na koniec opakowywanego kontenera i usuwa elementy z jego początku.

więcej na stronie [cppreference](https://pl.cppreference.com/w/cpp/container/queue)


## std::list

std::list jest kontenerem pozwalającym na wstawianie i usuwanie elementów w dowolnym miejscu w kontenerze, w czasie stałym. Szybki dostęp bezpośredni do elementów nie jest wspierany. Zazwyczaj jest implementowana jako lista dwukierunkowa. W porównaniu do std::forward_list ten kontener pozwala na iterowanie w obu kierunkach. Zużywa z tego powodu więcej pamięci.

Dodawanie, usuwanie ani przenoszenie elementów wewnątrz listy / pomiędzy listami nie unieważnia iteratorów ani referencji. Iterator jest unieważniany tylko wtedy, gdy odpowiadający mu element jest usuwany.

```cpp
#include <algorithm>
#include <iostream>
#include <list>
 
int main()
{
    // Tworzy listę zawierającą liczby całkowite
    std::list<int> l = { 7, 5, 16, 8 };
 
    // Dodaje element na początku listy
    l.push_front(25);
    // Dodaje element na końcu listy
    l.push_back(13);
 
    // Wstawia element przed 16-ką, poprzez wyszukanie jej
    auto it = std::find(l.begin(), l.end(), 16);
    if (it != l.end()) {
        l.insert(it, 42);
    }
 
    // Iteruje po wartościach w liście i wypisuje je
    for (int n : l) {
        std::cout << n << '\n';
    }
}
```

## std::map

