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

class Shape
{
public:
    Shape()
    {
        std::cout << "Generic Shape constructor 1" << std::endl;
        name = "Generic shape";
    }
    Shape(const std::string &shape_name)
    {
        std::cout << "Generic Shape constructor 2" << std::endl;
        name = shape_name;
    }
    virtual ~Shape()
    {
        std::cout << "Shape destructor" << std::endl;
    }
    std::string get_name()
    {
        return name;
    }

    virtual double get_area() const
    {
        return 0;
    }
    virtual double get_height() const
    {
        return 0;
    }
    virtual double get_width() const
    {
        return 0;
    }

protected:
    std::string name;
};

class Rectangle : public Shape
{
private:
    Rectangle() : lower_left{0, 0}, upper_right{1, 1}
    {
        std::cout << "Rectangle constructor 1" << std::endl;
    }

public:
    Rectangle(double x0, double y0, double x1, double y1)
        : Shape{"Rectangle"}, lower_left{x0, y0}, upper_right{x1, y1}
    //, name{"Rectangle"}
    {
        std::cout << "Rectangle constructor 2" << std::endl;
        // name = "Rectangle";
    }

    ~Rectangle()
    {
        std::cout << "Rectangle destructor " << name << std::endl;
    }

    double get_width() const override
    {
        return upper_right.get_x() - lower_left.get_x();
    }
    double get_height() const override
    {
        return upper_right.get_y() - lower_left.get_y();
    }
    double get_area() const override
    {
        return get_width() * get_height();
    }

private:
    Point lower_left;
    Point upper_right;
};

class Square : public Rectangle
{
public:
    Square(double x0, double y0, double side_length)
        : Rectangle{x0, y0, x0 + side_length, y0 + side_length}
    {
        std::cout << "Square constructor" << std::endl;
        name = "Square";
    }
    ~Square()
    {
        std::cout << "Square destructor" << std::endl;
    }
};

class Circle : public Shape
{
private:
    Circle()
    {
        std::cout << "Circle constructor 1" << std::endl;
        name = "Circle";
    }

public:
    Circle(double cx, double cy, double r)
        : radius{r}, center{cx, cy}
    {
        std::cout << "Circle constructor 2" << std::endl;
        name = "Circle";
    }
    ~Circle()
    {
        std::cout << "Circle destructor" << std::endl;
    }

    double get_width() const override
    {
        return 2 * radius;
    }
    double get_height() const override
    {
        return 2 * radius;
    }
    double get_area() const override
    {
        return (std::numbers::pi)*radius * radius;
    }

private:
    double radius;
    Point center;
};

void print_shape(Shape &s)
{
    std::cout << "Shape (" << s.get_name() << "):";
    std::cout << " width = " << s.get_width();
    std::cout << " height = " << s.get_height();
    std::cout << " area = " << s.get_area();
    std::cout << std::endl;
}

int main()
{

    // std::cout << "(main) Constructing a Rectangle" << std::endl;
    // Rectangle R{0, 0, 2, 3};

    // std::cout << "(main) Constructing a Square" << std::endl;
    // Square Sq{0, 0, 6};

    // std::cout << "(main) Constructing a Circle" << std::endl;
    Circle C{0, 0, 1};

    // print_shape(R);
    // print_shape(Sq);
    print_shape(C);

    //Question: Is it possible to construct a generic Shape object?
    //          Should it be?
    {
        Shape s{};
    }
    std::cout << "end of main" << std::endl;

    return 0;
}
