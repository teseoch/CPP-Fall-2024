#include <iostream>
#include <stdexcept>
#include <string>

// Declarations of the classes, functions and operators below.
class Point;
class Rectangle;
void print_point(Point const &P);
std::ostream &operator<<(std::ostream &stream, Point const &P);

class Point
{
public:
    Point() : x{0}, y{0}
    {
        std::cout << "Point: Default Constructor" << std::endl;
        x = 0;
        y = 0;
    }
    Point(double x_val, double y_val)
    {
        std::cout << "Point: (x,y) Constructor" << std::endl;
        x = x_val;
        y = y_val;
    }
    ~Point()
    {
        std::cout << "Point Destructor: (" << x << ", " << y << ")" << std::endl;
    }

private:
    double x, y;

    friend class Rectangle;
    friend void print_point(Point const &P);
    friend std::ostream &operator<<(std::ostream &stream, Point const &P);
};

void print_point(Point const &P)
{
    std::cout << "(" << P.x << "," << P.y << ")";
}

std::ostream &operator<<(std::ostream &stream, Point const &P)
{
    stream << "(" << P.x << "," << P.y << ")";
    return stream;
}

class Rectangle
{
private:
    Rectangle() : lower_left{0, 0}, upper_right{0, 0}
    {
        std::cout << "Rectangle: Default constructor" << std::endl;
    }

public:
    Rectangle(double ll_x, double ll_y, double ur_x, double ur_y) : lower_left{ll_x, ll_y}, upper_right{ur_x, ur_y}
    {
        std::cout << "Rectangle: Bounding Box Constructor" << std::endl;

        if (get_width() <= 0 || get_height() <= 0)
        {
            throw std::runtime_error{"Invalid dimensions"};
        }
    }
    Rectangle(double initial_width, double initial_height) : lower_left{0, 0}, upper_right{initial_width, initial_height}
    {
        std::cout << "Rectangle: Width/Height Constructor" << std::endl;

        if (get_width() <= 0 || get_height() <= 0)
        {
            throw std::runtime_error{"Invalid dimensions"};
        }
    }

    double get_width()
    {
        return upper_right.x - lower_left.x;
    }
    double get_height()
    {
        return upper_right.y - lower_left.y;
    }
    double get_area()
    {
        return get_width() * get_height();
    }

private:
    Point lower_left{};
    Point upper_right{};
};

int main()
{

    Rectangle R1{6, 10};

    std::cout << "R1 has width " << R1.get_width() << std::endl;
    std::cout << "R1 has height " << R1.get_height() << std::endl;
    std::cout << "R1 has area " << R1.get_area() << std::endl;

    Point P{111, 116};
    std::cout << "Printing P with print_point: ";
    print_point(P);
    std::cout << std::endl;

    std::cout << "Printing P with << operator: ";
    std::cout << P << std::endl;

    return 0;
}
