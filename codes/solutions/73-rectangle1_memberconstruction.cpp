#include <iostream>
#include <stdexcept>
#include <string>

class Rectangle
{
public:
    Rectangle() : width{0}, height{0}
    {
        std::cout << "Rectangle Default Constructor" << std::endl;
        std::cout << width << std::endl;
        std::cout << height << std::endl;

        //Question: Are the lines below _initializing_ the members width and height?
        // width = 0;
        // height = 0;
    }

    Rectangle(double w, double h) : width{w}, height{h}
    {
        std::cout << "Rectangle Parameterized Constructor" << std::endl;
        if (w < 0 || h < 0)
        {
            throw std::runtime_error{"Invalid dimensions"};
        }
    }

    double get_width()
    {
        return width;
    }
    double get_height()
    {
        return height;
    }

    double get_area()
    {
        return get_width() * get_height();
    }

    static Rectangle create_unit_square()
    {
        Rectangle res{};
        res.width = 1;
        res.height = 1;
        return res;
    }

private:
    double width{};
    double height{};
};

int main()
{
    // int a{};
    // a = 6;

    // int a{6};

    Rectangle R{}; //This uses the default constructor

    // double area = Rectangle{2, 2}.get_area();

    Rectangle R2{6, 10}; //This uses the parameterized constructor

    std::cout << "R has width " << R.get_width() << std::endl;
    std::cout << "R has height " << R.get_height() << std::endl;
    std::cout << "R has area " << R.get_area() << std::endl;

    std::cout << "R2 has width " << R2.get_width() << std::endl;
    std::cout << "R2 has height " << R2.get_height() << std::endl;
    std::cout << "R2 has area " << R2.get_area() << std::endl;

    Rectangle S{Rectangle::create_unit_square()};
    std::cout << "S has width " << S.get_width() << std::endl;
    std::cout << "S has height " << S.get_height() << std::endl;
    std::cout << "S has area " << S.get_area() << std::endl;

    return 0;
}
