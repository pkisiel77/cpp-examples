## Online C/C++
https://www.onlinegdb.com/online_c++_compiler

## Dodawanie 

```cpp
#include<iostream>

int main()
{
    int v1,v2,sum;
    std::cout << "Hello" << std::endl;
    std::cin >> v1;
    std::cin >> v2;
    sum = v1 + v2;
    std::cout << "Sum from v1=" << v1 << " v2=" << v2 << "is = " << sum << std::endl;
    return 0;
}
```

## Dodaj możliwość odejmowania

```cpp
#include<iostream>

using namespace std;

int main()
{
    int v1;
    int x ;
    double v2;
    double result;
    
    cout << "Podaj pierwsza liczbe" << endl;
    cin >> v1;
    cout << "Podaj druga liczbe" << endl;
    cin >> v2;
    cout << "Wybierz odejmowanie lub dodawanie" << endl;
    cout << "odejmowanie (1 + " << endl;
    cout << "dodawanie (2 -" << endl;
    cout << "* (3 -" << endl;
    cout << "/ (4 -" << endl;
    
    cin >> x;

    if(x == 1)
    {
        result = v1 + v2;
    }
    else if(x == 2)
    {
        result = v1 - v2;
    }
    else if(x == 3)
    {
        result = v1*v2;
    }
    else if(x == 4)
    {
        if (v2 != 0)
        {
            cout << v1/(v2*1.0) << endl;
            result = v1/v2;
        }
    }
    cout << " v1=" << v1 << " v2=" << v2 << " is = " << result << std::endl;
    
    return 0;
}
```

## Tablica
```cpp
#include<iostream>

using namespace std;

int main()
{
    int tab[5] = {1,20,3,-4,5};
    // [1][20][3][-4][5]
    //  0  1   2  3   4
    
    for(int i=0; i<5; i++)
    {
        cout << "index=" << i << endl;
        cout << tab[i] << endl;
    }

    
    return 0;
}
```

