#include <iostream>

struct Rectangle
{
    double width{0};
    double height{0};
};

double get_area(Rectangle R)
{
    return R.width * R.height;
}

int main()
{

    Rectangle R{6, 10};

    std::cout << "Area of R: " << get_area(R) << std::endl;

    return 0;
}
