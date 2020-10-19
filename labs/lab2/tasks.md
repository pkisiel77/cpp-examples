# Pętle 

## for 

(for)[https://en.cppreference.com/w/cpp/language/for]
(for)[https://docs.microsoft.com/pl-pl/cpp/cpp/for-statement-cpp?view=vs-2019]

Składnia
'''cpp
for ( init-expression ; cond-expression ; loop-expression )
    statement
'''
(Range-based for)[https://en.cppreference.com/w/cpp/language/range-for]
(Range-based for)[https://docs.microsoft.com/pl-pl/cpp/cpp/range-based-for-statement-cpp?view=vs-2019]

Składnia
'''cpp
for (***Deklaracja* : dla zakresu *wyrażenie***)
    instrukcja
'''

## while

(while)[https://en.cppreference.com/w/cpp/language/while]
(while)[https://docs.microsoft.com/pl-pl/cpp/cpp/while-statement-cpp?view=vs-2019]

Składnia
'''cpp
for (***Deklaracja* : dla zakresu *wyrażenie***)
    instrukcja
'''

## do{}while

(do-while)[https://en.cppreference.com/w/cpp/language/do]
(do-while)[https://docs.microsoft.com/pl-pl/cpp/cpp/do-while-statement-cpp?view=vs-2019]
'''cpp
do
   statement
while ( expression ) ;
'''

## Instrukcje warunkowe

### if

(if)[https://en.cppreference.com/w/cpp/language/if]
(if)[https://docs.microsoft.com/pl-pl/cpp/cpp/if-else-statement-cpp?view=vs-2019]

### switch

(switch)[https://en.cppreference.com/w/cpp/language/switch]
(switch)[https://docs.microsoft.com/pl-pl/cpp/cpp/switch-statement-cpp?view=vs-2019]

### ? :

Operator warunkowy
Conditional Operator

# Wskaźniki i referencje

'''cpp
int * wskaznikInt1 = 0;
int * wskaznikInt2 = NULL;
int * wskaznikInt3 = nullptr; // C++11
'''

'''cpp
int * wskaznik, zmienna;
int * wskaznik1, * wskaznik2;
'''

'''cpp
int zmienna = 123;
int * wskaznik = & zmienna;
int tablica[ 2 ] = { 10, 20 };

std::cout << "Wartosc: " << zmienna << ", Adres: " << wskaznik << ", Adres wskaznika: " << & wskaznik << std::endl;
std::cout << & tablica[ 0 ] << '\n' << & tablica[ 1 ] << std::endl;
'''

'''cpp
int zmienna = 123;
int * wskaznik = & zmienna;

std::cout << zmienna << std::endl;
std::cout << wskaznik << std::endl;
std::cout << * wskaznik << std::endl;
'''

'''cpp
std::cout << zmienna << " = " << * wskaznik << std::endl;
zmienna = 42;
std::cout << zmienna << " = " << * wskaznik << std::endl;
* wskaznik = 357;
std::cout << zmienna << " = " << * wskaznik << std::endl;
'''

Zadanie 1
Napisz funkcję otrzymującą jako argumenty wskaźniki do dwóch zmiennych typu int, która zamienia ze sobą wartości wskazywanych zmiennych tylko wtedy, gdy wskazywana przez drugi argument zmienna jest
mniejsza od zmiennej wskazywanej przez pierwszy argument.

Zadanie 2
Napisz funkcję otrzymującą jako argumenty referencje
do dwóch zmiennych typu int, która zamienia ze sobą wartości zmiennych, do których referencje dostaliśmy w argumentach.

Zdanie 3
Napisz funkcję otrzymującą dwa argumenty referencję a
oraz wskaźnik b do zmiennych typu int, która zamienia ze sobą wartości zmiennych, do których wskaźnik i referencję dostała w argumentach.

Zadanie 4
Napisz funkcję, która pobiera dwa argumenty i zwraca dwa odrębne wyniki.
Jednym z wyników powinien być iloczyn obu argumentów, a drugim ich suma. Ponieważ funkcja może bezpośrednio zwracać tylko jedną wartość, druga
powinna być zwracana poprzez parametr wskaźnikowy albo referencję.

### swap()

Opis
Przypisuje wartość obiektu a obiektowi b i wartość obiektu b obiektowi a

Składnia
'''cpp
#include <algorithm>
namespace std
{
    template < typename T >
    void swap( T & a, T & b );
}
'''

(Przykład)[http://www.cplusplus.com/reference/algorithm/swap/]

Zadanie 5
Napisz funkcję, która zamienia miejscami wartości swoich dwóch argumentów.
Przekaż do funkcji argumenty przy użyciu wskaźników albo referencji.

Zadanie 6
(Source)[http://cpp0x.pl/dokumentacja/standard-C++/swap/461]
Należy wziąć pod uwagę, że ta funkcja powoduje skopiowanie obiektu do zmiennej tymczasowej i dwa razy wywołuje operator przypisania, 
więc może nie być efektywna dla typów, dla których wspomniane operacje są kosztowne. 
W takie sytuacji rekomendowane jest przeciążenie tej funkcji tak, by wykonywała zamianę w wydajniejszy sposób.



# Zalety






