#include <iostream>

int main()
{
    int x{6};
    int y{10};

    auto z{x + y};

    std::cout << "x is " << x << std::endl;
    std::cout << "y is " << y << std::endl;
    std::cout << "z is " << z << std::endl;
}
