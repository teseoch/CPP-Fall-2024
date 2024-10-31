#include <iostream>
#include <stdexcept>
#include <string>

class Rectangle
{
private:
    //The default constructor is private, so code outside the class
    //is not permitted to create Rectangle objects with the default
    //constructor
    Rectangle()
    {
        std::cout << "Default constructor" << std::endl;
        width = 0;
        height = 0;
    }

public:
    Rectangle(double initial_width, double initial_height)
    {
        std::cout << "Parameterized constructor 1" << std::endl;
        if (initial_width <= 0 || initial_height <= 0)
        {
            throw std::runtime_error("Rectangles must have non-zero width and height.");
        }
        width = initial_width;
        height = initial_height;
    }

    //Contrived constructor which takes a string argument (and then ignores it)
    Rectangle(std::string s)
    {
        std::cout << "Parameterized constructor 2" << std::endl;
        width = 10;
        height = 17;
    }

    //Destructor (executed when the object is about to be deallocated)
    ~Rectangle()
    {
        std::cout << "Destructor: ";
        print();
    }

    void print()
    {
        std::cout << "Width = " << width;
        std::cout << " Height = " << height;
        std::cout << std::endl;
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
        Rectangle R{};
        R.width = 1;
        R.height = 1;
        return R;
    }

private:
    double width;
    double height;
};

int main()
{
    std::cout << "Starting main" << std::endl;

    Rectangle R1{6, 10};

    Rectangle R2{"Hi"}; //This will call the contrived constructor which takes a string

    std::cout << "R1: ";
    R1.print();

    std::cout << "R2: ";
    R2.print();
    std::cout << "Area of R2: " << R2.get_area() << std::endl;

    std::cout << "Done main" << std::endl;

    return 0;
}
