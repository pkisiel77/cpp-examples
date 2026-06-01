#include <iostream>

class Punkt
{
public:
    Punkt(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    int pobierzX() const
    {
        return x;
    }

    int pobierzY() const
    {
        return y;
    }

    Punkt operator+(const Punkt& inny) const
    {
        return Punkt(x + inny.x, y + inny.y);
    }

    bool operator==(const Punkt& inny) const
    {
        return x == inny.x && y == inny.y;
    }

private:
    int x;
    int y;
};

std::ostream& operator<<(std::ostream& out, const Punkt& punkt)
{
    out << "(" << punkt.pobierzX() << ", " << punkt.pobierzY() << ")";
    return out;
}

int main()
{
    Punkt a(1, 2);
    Punkt b(3, 4);
    Punkt c = a + b;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;

    if (c == Punkt(4, 6))
    {
        std::cout << "Dodawanie dziala" << std::endl;
    }

    return 0;
}
