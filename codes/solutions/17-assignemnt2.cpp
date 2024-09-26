#include <iostream>

int main()
{
    int x{6};
    int y{10};
    int z{00};

    // Second law of assignemnt statements
    // An ordinary (not initialization) assignment statement is ALWAYS a copy

    z = x;
    x = 100;

    std::cout << "x is " << x << std::endl;
    std::cout << "y is " << y << std::endl;
    std::cout << "z is " << z << std::endl;
}
