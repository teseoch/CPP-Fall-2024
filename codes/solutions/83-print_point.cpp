#include <iostream>
#include <stdexcept>
#include <fstream>

class Point
{
public:
    Point() : x{0}, y{0}
    {
    }
    Point(double x_val, double y_val) : x{x_val}, y{y_val}
    {
    }
    double get_x() const
    {
        return x;
    }
    double get_y() const
    {
        return y;
    }
    void print()
    {
        std::cout << "(" << get_x() << "," << get_y() << ")";
    }

private:
    double x, y;
};

std::ostream &operator<<(std::ostream &stream, const Point &p)
{
    stream << "(" << p.get_x() << "," << p.get_y() << ")";

    return stream;
}

std::ostream &foo(std::ostream &stream, const Point &p)
{
    stream << "(" << p.get_x() << "," << p.get_y() << ")";

    return stream;
}

int main()
{
    Point P{6, 17};
    Point Q{111, 116};

    std::cout << "Point P: ";
    // P.print();
    //Task 1: Add code to allow the following more natural notation to be used instead.
    //        (Note that std::cout is an object of type std::ostream).
    // "std::cout + P";
    //(((1+4)+5)+7)
    std::cout << P << std::endl;

    std::ofstream file{"bla.txt"};
    file << P << std::endl;

    std::cout << "Points P and Q: ";
    //Task 2: Refine the implementation from Task 1 to also work with the expression
    //        below (where multiple stream insertions are chained together).
    std::cout << P << Q << std::endl;
    foo(foo(std::cout, P), Q) << std::endl;

    return 0;
}
