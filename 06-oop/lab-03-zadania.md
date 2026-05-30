```cpp
#include <iostream>

class Matrix
{
    public:
    // dodatkowy konstruktor jako argument przyjmujący ścieżkę do pliku o podanym wcześniej formacie i na jego podstawie tworzący nową macierz na podstawie przekazanego pliku
    Matrix(std::string path);
    // przyjmujący dwa argumenty typu int tworzący macierz o podanych wymiarach zainicjalizowaną zerami    
    Matrix(int n, int m);
    // przyjmujący jeden argument typu int tworzący macierz kwadratową o podanym rozmiarze zainicjalizowaną zerami
    Matrix(int n);

    ~Matrix();

    // set(n, m, val) - metoda ustawiająca wartość elementu (n, m) na val
    void set(int n, int m, double val);

    // get(n, m) - metoda pobierająca element (n, m)
    double get(int n, int m);

    // add(Matrix m2) - metoda przyjmująca jako argument inną macierz i zwracająca jako wynik nową macierz będącą sumą bieżącej macierzy oraz macierzy przekazanej jako argument
    Matrix add(Matrix& m2);

    // subtract(Matrix m2) - metoda przyjmująca jako argument inną macierz i zwracająca jako wynik nową macierz będącą różnicą bieżącej macierzy oraz macierzy przekazanej jako argument
    Matrix subtract(Matrix& m2);

    // multiply(Matrix m2) - metoda przyjmująca jako argument inną macierz i zwracająca jako wynik nową macierz będącą iloczynem bieżącej macierzy oraz macierzy przekazanej jako argument
    Matrix multiply(Matrix& m2);

    // cols() - metoda zwracająca liczbę kolumn macierzy
    int cols();

    // rows() - metoda zwracająca liczbę wierszy macierzy
    int rows();

    // print() - metoda wyświetlająca macierz na ekranie
    // https://invisible-island.net/ncurses/announce.html
    void print(); 

    // store(std::string filename, std::string path) - metoda zapisująca macierz w pliku; w pliku powinny być zapisane wymiary macierzy (liczba kolumn i liczba wierszy w pierwszym wierszu pliku) oraz jej zawartość (każdy wiersz macierzy w osobnym wierszu pliku)
    bool store(std::string filename, std::string path);

};

int main()
{
    // należy dodać metodę main (chodzi o funkcję int main(){}) pokazującą działanie wszystkich powyższych metod na przykładzie macierzy o rozmiarze co najmniej 4 (należy zademonstrować działanie wszystkich konstruktorów).

}
```
