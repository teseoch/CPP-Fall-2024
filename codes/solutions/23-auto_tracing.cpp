#include <iostream>

int f(int x, int y)
{
    x = 10;
    y = 6;
    return x + y;
}

float g(int a, int b)
{
    return a + b;
}

int h(float a, float b)
{
    return a / b;
}

int main()
{
    int x{111};
    int y{116};
    auto z{f(x, y)}; //z is an integer

    std::cout << "Begin: " << x << " " << y << " " << z << std::endl;

    z = g(2.5, 2.5);

    if (z == 4)
    {
        int x{0};
        x = 200;
        y = 1000;
        float z = h(x, y);
    }

    std::cout << "End: " << x << " " << y << " " << z << std::endl;

    return 0;
}
