#include <iostream>

float f(int a, int b)
{
    std::cout << "f: " << a << " " << b << std::endl;
    float x = a / b;
    return x;
}
int main()
{
    int x{6};
    int y{10};
    std::cout << "main (1): " << x << " " << y << std::endl;

    y = f(x + 1, y);

    std::cout << "main (2): " << x << " " << y << std::endl;
    if (0 < 1)
    {
        int x{-111};
        y = x - 5;
        std::cout << "main (3): " << x << " " << y << std::endl;
    }
    std::cout << "main (4): " << x << " " << y << std::endl;

    return 0;
}
