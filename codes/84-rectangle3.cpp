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
    double x, y;
    //Question: Why would a compile error occur if we make x and y private,
    //          and how could we remedy the error?
};

class Rectangle
{
private:
    Rectangle()
    {
        std::cout << "Rectangle: Default constructor" << std::endl;

        //Task: Initialize the lower left and upper right points to (0,0).
    }

public:
    Rectangle(double ll_x, double ll_y, double ur_x, double ur_y)
    {
        std::cout << "Rectangle: Bounding Box Constructor" << std::endl;

        //Task: Initialize the component points as given. Throw a runtime_error if the
        //      width or height is negative or zero.
    }
    Rectangle(double initial_width, double initial_height)
    {
        std::cout << "Rectangle: Width/Height Constructor" << std::endl;

        //Task: Initialize the lower left point to (0,0) and the upper right point
        //      to (initial_width, initial_height). Throw a runtime_error if the
        //      width or height is negative or zero.
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
        std::cout << "Lower left: (" << lower_left.x << ", " << lower_left.y << ") ";
        std::cout << "Upper right: (" << upper_right.x << ", " << upper_right.y << ") ";
        std::cout << std::endl;
    }

    double get_width()
    {
        //Task: Implement this
        return 0;
    }
    double get_height()
    {
        //Task: Implement this
        return 0;
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

    Rectangle R2{6, 10};

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
