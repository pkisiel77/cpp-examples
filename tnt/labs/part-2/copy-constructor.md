## Napisz konstruktor kopiujący dla klasy "MyClass"

Klasa "MyClass" posiada dwa składowe: "name" typu string oraz "value" typu int.
Konstruktor kopiujący powinien skopiować wartości składowych "name" i "value" z obiektu podanego jako argument konstruktora do nowo utworzonego obiektu.
Przetestuj działanie konstruktora kopiującego przy użyciu przykładów kodu.
Przykład:

```cpp
class MyClass {
public:
    MyClass(string name, int value); //konstruktor
    MyClass(const MyClass &other); //konstruktor kopiujący
    string getName() const;
    int getValue() const;
private:
    string name;
    int value;
};

MyClass::MyClass(string n, int v) : name(n), value(v) {}
MyClass::MyClass(const MyClass &other) : name(other.name), value(other.value) {}
string MyClass::getName() const { return name; }
int MyClass::getValue() const { return value; }

int main() {
    MyClass obj1("object1", 10);
    MyClass obj2 = obj1; //kopiujący konstruktor
    cout << obj2.getName() << " " << obj2.getValue() << endl;
    return 0;
}
```

Uwaga: W powyższym przykładzie użyty został konstruktor kopiujący domyślny, który skopiuje wszystkie pola z obiektu źródłowego do nowego obiektu. W przypadku gdy klasa posiada składowe dynamicznie alokowane, trzeba przepisać konstruktor kopiujący, by skopiować te składowe za pomocą operatora new.
