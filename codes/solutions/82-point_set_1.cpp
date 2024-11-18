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
    /* Add an operator here */
    bool operator<(const Point &other) const
    {
        if (get_x() == other.get_x())
        {
            return get_y() < other.get_y();
        }
        else
        {
            return get_x() < other.get_x();
        }
    }

    double operator[](int index) const
    {
        if (index == 0)
            return get_x();
        else if (index == 1)
            return get_y();
        else
            throw std::invalid_argument{"Index out of range"};
    }

    Point operator-(const Point &other)
    {
        return Point{x - other.x, y - other.get_y()};
    }

    Point operator-()
    {
        return Point{-x, -y};
    }

private:
    double x, y;
};

// Point operator-(const Point &p1, const Point &p2)
// {
//     return Point{p1.get_x() - p2.get_x(), p1.get_y() - p2.get_y()};
// }

// Point operator-(const Point &p)
// {
//     return Point{-p.get_x(), -p.get_y()};
// }

int main()
{

    Point P{6, 17};
    Point Q{6, 10};
    Point R{1, 3};
    Point S{-3, -5};

    double px = P[0];

    Point diff{P - Q};
    Point Pm = -P;

    int x{5};
    int y = -x;

    std::set<Point>
        point_set;

    //In order for .insert to work, there must be a < operator
    //defined for the element type.
    point_set.insert(P);
    point_set.insert(Q);
    point_set.insert(R);
    point_set.insert(S);

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
