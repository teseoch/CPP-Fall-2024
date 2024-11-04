#include <iostream>
#include <stdexcept>
#include <string>

class Rectangle
{
public:
    //Task: Add a default constructor (which initializes the rectangle
    //      to have width = height = 0) and a parameterized constructor
    //      which takes a width and height (and verifies that they are
    //      valid).
    Rectangle()
    {
        std::cout << "Default no-arg constructor" << std::endl;

        width = 0;
        height = 0;
    }

    Rectangle(double side)
    {
        std::cout << "Constructor for a square" << std::endl;

        if (side < 0)
        {
            throw std::runtime_error{"Invalid square"};
        }

        width = height = side;
    }

    Rectangle(double w, double h)
    {
        std::cout << "Constructor with w and h" << std::endl;

        if (w < 0 || h < 0)
        {
            throw std::runtime_error{"Invalid rect w or h"};
        }

        width = w;
        height = h;
    }

    //Task: Add get_width and get_height functions which return the width
    //      and height of this rectangle
    double get_width()
    {
        return width;
    }
    double get_height()
    {
        return height;
    }

    void set_width(double w)
    {
        if (w < 0)
        {
            throw std::runtime_error{"Invalid width"};
        }
        width = w;
    }

    void set_height(double h)
    {
        if (h < 0)
        {
            throw std::runtime_error{"Invalid height"};
        }
        height = h;
    }

    // double get_area()
    // {
    //     return width * height;
    // }
    double get_area()
    {
        return get_width() * get_height();
    }

    //Task: Add a get_area function which returns the area of this rectangle

    //Task: Add a static member function create_unit_square which creates
    //      and returns a rectangle with width and height equal to 1
    static Rectangle create_unit_square()
    {
        // Rectangle res{1, 1};
        // Rectangle res{1};

        Rectangle res{};
        res.width = res.height = 1;

        return res;
    }

private:
    double width;
    double height;
};

int main()
{
    Rectangle R{}; //This uses the default constructor

    Rectangle square{10}; //This uses the default constructor

    Rectangle R2{6, 10}; //This uses the parameterized constructor

    R.set_width(4);
    R.set_height(30);

    std::cout << "R has width " << R.get_width() << std::endl;
    std::cout << "R has height " << R.get_height() << std::endl;
    std::cout << "R has area " << R.get_area() << std::endl;

    std::cout << "R2 has width " << R2.get_width() << std::endl;
    std::cout << "R2 has height " << R2.get_height() << std::endl;
    std::cout << "R2 has area " << R2.get_area() << std::endl;

    std::cout << "square has width " << square.get_width() << std::endl;
    std::cout << "square has height " << square.get_height() << std::endl;
    std::cout << "square has area " << square.get_area() << std::endl;

    Rectangle usquare{Rectangle::create_unit_square()};
    // Rectangle usquare{R2.create_unit_square()};
    std::cout << "usquare has width " << usquare.get_width() << std::endl;
    std::cout << "usquare has height " << usquare.get_height() << std::endl;
    std::cout << "usquare has area " << usquare.get_area() << std::endl;

    return 0;
}
