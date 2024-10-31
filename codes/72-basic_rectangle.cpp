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

    //Task: Add get_width and get_height functions which return the width
    //      and height of this rectangle

    //Task: Add a get_area function which returns the area of this rectangle

    //Task: Add a static member function create_unit_square which creates
    //      and returns a rectangle with width and height equal to 1

    double width{0};
    double height{0};
};

int main()
{
    Rectangle R{}; //This uses the default constructor

    Rectangle R2{6, 10}; //This uses the parameterized constructor

    std::cout << "R has width " << R.get_width() << std::endl;
    std::cout << "R has height " << R.get_height() << std::endl;
    std::cout << "R has area " << R.get_area() << std::endl;

    std::cout << "R2 has width " << R2.get_width() << std::endl;
    std::cout << "R2 has height " << R2.get_height() << std::endl;
    std::cout << "R2 has area " << R2.get_area() << std::endl;

    return 0;
}
