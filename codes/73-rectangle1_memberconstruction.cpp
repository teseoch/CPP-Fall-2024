#include <iostream>
#include <stdexcept>
#include <string>

class Rectangle
{
public:
    Rectangle()
    {
        std::cout << "Rectangle Default Constructor" << std::endl;

        //Question: Are the lines below _initializing_ the members width and height?
        width = 0;
        height = 0;
    }

    Rectangle(double w, double h)
    {
        std::cout << "Rectangle Parameterized Constructor" << std::endl;
        if (w < 0 || h < 0)
        {
            throw std::runtime_error{"Invalid dimensions"};
        }
        width = w;
        height = h;
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

    Rectangle S{Rectangle::create_unit_square()};
    std::cout << "S has width " << S.get_width() << std::endl;
    std::cout << "S has height " << S.get_height() << std::endl;
    std::cout << "S has area " << S.get_area() << std::endl;

    return 0;
}
