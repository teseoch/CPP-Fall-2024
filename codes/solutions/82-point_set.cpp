#include <iostream>
#include <stdexcept>
#include <set>

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

private:
    double x, y;
};

/* Add an operator here */

//p1 < p2?
bool operator<(const Point &p1, const Point &p2)
{
    // std::string p1s{std::to_string(p1.get_x()) + std::to_string(p1.get_y())};
    // std::string p2s{std::to_string(p2.get_x()) + std::to_string(p2.get_y())};

    // return p1s < p2s;

    // return p1.get_x() + p1.get_y() < p2.get_x() + p2.get_y();

    // if (p1.get_x() < p2.get_x())
    //     return true;
    // else if (p1.get_x() > p2.get_x())
    //     return false;

    // else if (p1.get_y() < p2.get_y())
    //     return true;
    // else //if (p1.get_y() > p2.get_y())
    //     return false;

    if (p1.get_x() == p2.get_x())
    {
        return p1.get_y() < p2.get_y();
    }
    else
    {
        return p1.get_x() < p2.get_x();
    }
}

int main()
{

    Point P{6, 17};
    Point Q{6, 10};
    Point T{10, 10};
    Point R{1, 3};
    Point S{-3, -5};

    std::cout << (P < Q) << std::endl;

    std::set<Point> point_set;

    //In order for .insert to work, there must be a < operator
    //defined for the element type.
    point_set.insert(P);
    point_set.insert(Q);
    point_set.insert(R);
    point_set.insert(S);
    point_set.insert(T);

    for (auto pt : point_set)
    {
        std::cout << "(" << pt.get_x() << ", " << pt.get_y() << ") ";
    }
    std::cout << std::endl;

    Point search_point1{6, 10};
    Point search_point2{111, 116};
    if (point_set.contains(search_point1))
    {
        std::cout << "Found (6,10) in the set." << std::endl;
    }
    else
    {
        std::cout << "Did not find (6,10) in the set." << std::endl;
    }

    if (point_set.contains(search_point2))
    {
        std::cout << "Found (111,116) in the set." << std::endl;
    }
    else
    {
        std::cout << "Did not find (111,116) in the set." << std::endl;
    }
    return 0;
}
