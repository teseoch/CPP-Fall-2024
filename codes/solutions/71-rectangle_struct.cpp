#include <iostream>
#include <stdexcept>
#include <string>

//Issue 1: The width and height members are not protected
//         against invalid data.
struct Rectangle
{
    double width{0};
    double height{0};
};

//Issue 2: This function is conceptually "part of" the rectangle
//         but since it exists in the global scope we have to use
//         a naming gimmick (like putting "rectangle" in the name)
//         to make it clear that it's related.
double get_rectangle_area(const Rectangle &rec)
{
    //Issue 3: What if we want to store the area of the rectangle
    //         as one of its members instead of computing it every
    //         time? How can we ensure that the area is always
    //         kept synchronized with the current width and height?
    return rec.width * rec.height;
}

int main()
{

    Rectangle R{1, 1};

    Rectangle R2{-6, 10};

    std::cout << "R has width " << R.width << std::endl;
    std::cout << "R has height " << R.height << std::endl;
    std::cout << "R has area " << get_rectangle_area(R) << std::endl;

    std::cout << "R2 has width " << R2.width << std::endl;
    std::cout << "R2 has height " << R2.height << std::endl;
    std::cout << "R2 has area " << get_rectangle_area(R2) << std::endl;

    return 0;
}
