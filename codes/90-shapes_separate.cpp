#include <iostream>
#include <string>
#include <cmath>
#include <numbers>

class Point
{
public:
    Point() : x{0}, y{0}
    {
    }
    ~Point()
    {
    }
    Point(double x_coord, double y_coord) : x{x_coord}, y{y_coord}
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

class Rectangle
{
private:
    Rectangle() : lower_left{0, 0}, upper_right{1, 1}
    {
        std::cout << "Rectangle constructor 1" << std::endl;
    }

public:
    Rectangle(double x0, double y0, double x1, double y1) : lower_left{x0, y0}, upper_right{x1, y1}
    {
        std::cout << "Rectangle constructor 2" << std::endl;
    }
    ~Rectangle()
    {
        std::cout << "Rectangle destructor" << std::endl;
    }
    std::string get_name() const
    {
        return "Rectangle";
    }
    double get_width() const
    {
        return upper_right.get_x() - lower_left.get_x();
    }
    double get_height() const
    {
        return upper_right.get_y() - lower_left.get_y();
    }
    double get_area() const
    {
        return get_width() * get_height();
    }

private:
    Point lower_left;
    Point upper_right;
};

class Square
{
public:
    Square(double x0, double y0, double side_length) : lower_left{x0, y0},
                                                       upper_right{x0 + side_length, y0 + side_length}
    {
        std::cout << "Square constructor" << std::endl;
    }
    ~Square()
    {
        std::cout << "Square destructor" << std::endl;
    }
    std::string get_name() const
    {
        return "Square";
    }

    double get_width() const
    {
        return upper_right.get_x() - lower_left.get_x();
    }
    double get_height() const
    {
        return upper_right.get_y() - lower_left.get_y();
    }
    double get_area() const
    {
        return get_width() * get_height();
    }

private:
    Point lower_left;
    Point upper_right;
};

class Circle
{
private:
    Circle() : radius{0}, center{0, 0}
    {
        std::cout << "Circle constructor 1" << std::endl;
    }

public:
    Circle(double cx, double cy, double r) : radius{r}, center{cx, cy}
    {
        std::cout << "Circle constructor 2" << std::endl;
    }
    ~Circle()
    {
        std::cout << "Circle destructor" << std::endl;
    }

    std::string get_name() const
    {
        return "Circle";
    }

    double get_width() const
    {
        return 2 * radius;
    }
    double get_height() const
    {
        return 2 * radius;
    }
    double get_area() const
    {
        return (std::numbers::pi)*radius * radius;
    }

private:
    double radius;
    Point center;
};

/* Define several (identical) print_shape functions, one for each
   type of shape. Since each shape is a separate class, there's
   no easy way to combine the common behavior.
*/
void print_shape(Circle const &s)
{
    std::cout << "Shape (" << s.get_name() << "):";
    std::cout << " width = " << s.get_width();
    std::cout << " height = " << s.get_height();
    std::cout << " area = " << s.get_area();
    std::cout << std::endl;
}

void print_shape(Rectangle const &s)
{
    std::cout << "Shape (" << s.get_name() << "):";
    std::cout << " width = " << s.get_width();
    std::cout << " height = " << s.get_height();
    std::cout << " area = " << s.get_area();
    std::cout << std::endl;
}
void print_shape(Square const &s)
{
    std::cout << "Shape (" << s.get_name() << "):";
    std::cout << " width = " << s.get_width();
    std::cout << " height = " << s.get_height();
    std::cout << " area = " << s.get_area();
    std::cout << std::endl;
}

int main()
{

    std::cout << "Constructing a Rectangle" << std::endl;
    Rectangle R{0, 0, 2, 3};

    std::cout << "Constructing a Square" << std::endl;
    Square Sq{0, 0, 6};

    std::cout << "Constructing a Circle" << std::endl;
    Circle C{0, 0, 1};

    print_shape(R);
    print_shape(Sq);
    print_shape(C);

    return 0;
}
