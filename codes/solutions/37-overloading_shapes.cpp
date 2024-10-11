#include <iostream>

struct Rectangle
{
    double width{0};
    double height{0};
};

struct Triangle
{
    double base{0};
    double height{0};
};

struct Circle
{
    double radius{0};
};

double get_area(const Rectangle &R)
{
    return R.width * R.height;
}

double get_area(const Triangle &T)
{
    return T.base * T.height / 2.0;
}

double get_area(const Circle &C)
{
    return C.radius * C.radius * 3.14;
}

int main()
{
    Rectangle R{6, 10};
    std::cout << "Area of R: " << get_area(R) << std::endl;

    Triangle T{17, 2};
    std::cout << "Area of T: " << get_area(T) << std::endl;

    Circle C{1};
    std::cout << "Area of C: " << get_area(C) << std::endl;

    return 0;
}
