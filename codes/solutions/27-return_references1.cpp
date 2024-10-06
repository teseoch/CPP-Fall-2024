#include <iostream>

int &get_a_reference(int &x, int &y, int &z)
{
    // Question: What happens if the below code is used instead?
    // int result{y};
    // return result;

    return y;
}

int main()
{
    int a{6}, b{10}, c{17};

    std::cout << "Part 1: a = " << a << " b = " << b << " c = " << c << std::endl;
    // int z{get_a_reference(a, b, c)};
    // == int z { b };

    // int &z{get_a_reference(a, b, c)};
    //==int &z{b};

    // z = 1000;

    get_a_reference(a, b, c) = 300;

    // std::cout << "Part 2: a = " << a << " b = " << b << " c = " << c << " z = " << z << std::endl;
    std::cout << "Part 2: a = " << a << " b = " << b << " c = " << c << std::endl;

    return 0;
}