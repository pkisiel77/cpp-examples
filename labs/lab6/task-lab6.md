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

```cpp
#include <iostream>
#include <stack>

int main()
{
    std::stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    std::cout << "Top of the stack = " << intStack.top();
    std::cout << std::endl;
    return 0;
}
```

```cpp
#include <iostream>
#include <stack>

int main()
{
    std::stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    std::cout << "Size of stack using stack.size() method " << intStack.size();
    std::cout << std::endl;
    return 0;
}
```

```cpp
#include <iostream>
#include <stack>

int main()
{
    std::stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    std::cout << "Is stack empty? " << intStack.empty() << std::endl;
    std::cout << "Pop three times" << std::endl;
    intStack.pop();
    intStack.pop();
    intStack.pop();

    std::cout << "Is stack empty? " << intStack.empty() << std::endl;
    std::cout << std::endl;
    return 0;
}
```

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

```cpp
#include <iostream>
#include <queue>
using namespace std;
int main()
{
  queue<int> queue1;
  queue1.emplace(1);
  queue1.emplace(2);
  queue1.emplace(3);

  if (queue1.empty())
  {
    cout << "The queue is empty";
  }
  else
  {
    cout << "The queue is not empty";
  }
  return 0;
}
```

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main()
{
  queue<int> queue2;
  queue2.push(0);
  queue2.push(1);
  queue2.push(2);
  queue2.push(3);
  queue2.push(4);
  // queue has element 0,1,2,3,4

  queue2.pop();

  // after poping one element queue becomes 0,1,2,3

  // Printing queue elements
  cout << "Elements of the queue are:";
  while (!queue2.empty())
  {
    cout << ' ' << queue2.front();
    queue2.pop();
  }
}
```

```cpp
#include <iostream> 
#include <queue> 
using namespace std; 
  
int main() 
{ 
    queue<int> queue3; 
    queue3.push(0); 
    queue3.push(1); 
    queue3.push(2);
    queue3.push(3);
    queue3.push(4);
    
    cout<<"Size of the queue is: "<<queue3.size()<<endl;
    cout<<"The element at the front is:"<<queue3.front()<<endl;
    cout<<"The element at the back is:"<<queue3.back()<<endl;	
    return(0);
}
```

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main()
{
  queue<int> queue2;
  queue<int> queue1;
  queue1.push(0);
  queue1.push(1);
  queue1.push(2);
  queue1.push(3);
  queue1.push(4);

  queue2.push(5);
  queue2.push(6);
  queue2.push(7);
  queue2.push(8);
  queue2.push(9);

  queue1.swap(queue2); //Swapping

  cout << "Elements of queue1 after swapping are:";
  while (!queue1.empty())
  {
    cout << queue1.front() << " ";
    queue1.pop();
  }

  // Print the second set
  cout << endl
       << "Elements of queue2 after swapping are:";
  while (!queue2.empty())
  {
    cout << queue2.front() << " ";
    queue2.pop();
  }

  return 0;
}
```

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

std::map (mapa, inaczej słownik) jest kontenerem asocjacyjnym, pozwalającym na przechowywanie posortowanej listy unikalnych par postaci klucz-wartość. Elementy są sortowane na podstawie funkcji porównującej Compare, aplikowanej do kluczy. Operacje znajdowania, wstawiania i usuwania elementów mają złożoność logarytmiczną. Słowniki są zazwyczaj implementowane jako [drzewa czerwono-czarne](https://eduinf.waw.pl/inf/alg/001_search/0121.php)

Wszędzie, gdzie w bibliotece standardowej wykorzystywany jest koncept Compare, unikalność jest sprawdzana korzystając z relacji równoważności. Dwa obiekty a i b są uważane za równoważne, jeśli żaden z nich nie jest mniejszy od drugiego: !comp(a, b) && !comp(b, a).

std::map spełnia wymogi Container, AllocatorAwareContainer, AssociativeContainer i ReversibleContainer.

więcej na stronie [cppreference](https://pl.cppreference.com/w/cpp/container/map)

```cpp
// Create
map<string, int> myMap;
//Insert
myMap.insert(make_pair("earth", 1));
myMap.insert(make_pair("moon", 2));

myMap["sun"] = 3;

map<char, int>::iterator it;
for(it=first.begin(); it!=first.end(); ++it){
  cout << it->first << " => " << it->second << '\n';
}
```

```cpp
#include <iostream>
#include <map>

using namespace std;

int main (){
  map<char,int> first;
  
  //initializing
  first['a']=10;
  first['b']=20;
  first['c']=30;
  first['d']=40;
  
   map<char, int>::iterator it;
   for(it=first.begin(); it!=first.end(); ++it){
      cout << it->first << " => " << it->second << '\n';
   }
   
  return 0;
}
```

Microsoft [Map](https://docs.microsoft.com/pl-pl/cpp/standard-library/map-class?view=msvc-160)

```cpp
// map_begin.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   map <int, int> m1;

   map <int, int> :: iterator m1_Iter;
   map <int, int> :: const_iterator m1_cIter;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 0, 0 ) );
   m1.insert ( Int_Pair ( 1, 1 ) );
   m1.insert ( Int_Pair ( 2, 4 ) );

   m1_cIter = m1.begin ( );
   cout << "The first element of m1 is " << m1_cIter -> first << endl;

   m1_Iter = m1.begin ( );
   m1.erase ( m1_Iter );

   // The following 2 lines would err because the iterator is const
   // m1_cIter = m1.begin ( );
   // m1.erase ( m1_cIter );

   m1_cIter = m1.begin( );
   cout << "The first element of m1 is now " << m1_cIter -> first << endl;
}
```



