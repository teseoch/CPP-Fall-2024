#include <iostream>
#include <stdexcept>
#include <string>

class Point
{
public:
    Point()
    {
        std::cout << "Point: Default Constructor" << std::endl;
        x = 0;
        y = 0;
    }
    Point(double val)
    {
        std::cout << "Point: (x,x) Constructor" << std::endl;
        x = val;
        y = val;
    }

    Point(double x_val, double y_val)
    {
        std::cout << "Point: (x,y) Constructor" << std::endl;
        x = x_val;
        y = y_val;
    }
    ~Point()
    {
        std::cout << "Point Destructor" << std::endl;
    }
    //Note that x and y are public (so there is no way of controlling
    //modifications or encapsulating them)

    double get_x() const { return x; }
    double get_y() const { return y; }

private:
    double x, y;
    //Question: Why would a compile error occur if we make x and y private,
    //          and how could we remedy the error?
};

class Rectangle
{
private:
    Rectangle()
        : Rectangle(0, 0)
    {
        std::cout << "Rectangle: Default constructor" << std::endl;

        //Task: Initialize the lower left and upper right points to (0,0).
        // lower_left.x = 0;
        // lower_left.y = 0;

        // upper_right.x = 0;
        // upper_right.y = 0;
    }

public:
    Rectangle(double ll_x, double ll_y, double ur_x, double ur_y)
        : lower_left{ll_x, ll_y}, upper_right{ur_x, ur_y}
    {
        std::cout << "Rectangle: Bounding Box Constructor" << std::endl;

        //Task: Initialize the component points as given. Throw a runtime_error if the
        //      width or height is negative or zero.

        // lower_left.x = ll_x;
        // lower_left.y = ll_y;

        // upper_right.x = ur_x;
        // upper_right.y = ur_y;

        if (get_width() <= 0 || get_height() <= 0)
            throw std::runtime_error("invalid");
    }
    Rectangle(double initial_width, double initial_height)
        : Rectangle(0, 0, initial_width, initial_height)
    {
        std::cout << "Rectangle: Width/Height Constructor" << std::endl;

        //Task: Initialize the lower left point to (0,0) and the upper right point
        //      to (initial_width, initial_height). Throw a runtime_error if the
        //      width or height is negative or zero.
        // lower_left.x = 0;
        // lower_left.y = 0;

        // upper_right.x = initial_width;
        // upper_right.y = initial_height;

        // if (get_width() <= 0 || get_height() <= 0)
        //     throw std::runtime_error("invalid");
    }

    ~Rectangle()
    {
        //Other than the unique way that it is called, a destructor is an ordinary member function
        //and can access any of the members of this object.
        //Question: What does this imply about the way that the members
        //          (like lower_left and upper_right) are destructed?
        std::cout << "Rectangle Destructor: ";
        print();
    }

    void print()
    {
        std::cout << "Lower left: (" << lower_left.get_x() << ", " << lower_left.get_y() << ") ";
        std::cout << "Upper right: (" << upper_right.get_x() << ", " << upper_right.get_y() << ") ";
        std::cout << std::endl;
    }

    double get_width()
    {
        //Task: Implement this
        return upper_right.get_x() - lower_left.get_x();
    }
    double get_height()
    {
        //Task: Implement this
        return upper_right.get_y() - lower_left.get_y();
    }
    double get_area()
    {
        return get_width() * get_height();
    }

    static Rectangle create_unit_square()
    {
        Rectangle R{0, 0, 1, 1};
        return R;
    }

private:
    Point lower_left;
    Point upper_right;
};

int main()
{
    Rectangle R1{2, 2};
    Rectangle R2{0, 0, 6, 10};

    std::cout << "R1 has width " << R1.get_width() << std::endl;
    std::cout << "R1 has height " << R1.get_height() << std::endl;
    std::cout << "R1 has area " << R1.get_area() << std::endl;

    std::cout << "R2 has width " << R2.get_width() << std::endl;
    std::cout << "R2 has height " << R2.get_height() << std::endl;
    std::cout << "R2 has area " << R2.get_area() << std::endl;

    Rectangle R3{Rectangle::create_unit_square()};

    std::cout << "R3 has width " << R3.get_width() << std::endl;
    std::cout << "R3 has height " << R3.get_height() << std::endl;
    std::cout << "R3 has area " << R3.get_area() << std::endl;

    return 0;
}
