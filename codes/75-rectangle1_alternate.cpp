#include <iostream>
#include <stdexcept>
#include <string>

class Rectangle
{
public:
    Rectangle() : width{0}, area{0}
    {
        std::cout << "Rectangle Default Constructor" << std::endl;
    }

    Rectangle(double initial_width, double initial_height)
    {
        std::cout << "Rectangle Parameterized Constructor" << std::endl;
        if (initial_width < 0 || initial_height < 0)
        {
            throw std::runtime_error{"Invalid dimensions"};
        }
        width = initial_width;
        area = initial_width * initial_height;
    }
    double get_width()
    {
        return width;
    }
    double get_height()
    {
        if (area == 0)
        {
            //Hmm...
            return 0;
        }
        return get_area() / get_width();
    }

    double get_area()
    {
        return area;
    }

    static Rectangle create_unit_square()
    {
        Rectangle result{1, 1};
        return result;
    }

private:
    double width{0};
    double area{0};
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
